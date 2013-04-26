<?php
/**
 * @file
 * Blue State Digital Voting Service.
 */

/**
 * Include the core service class.
 */
include_once dirname(__FILE__) . '/bsd.core.service.inc';

/**
 * This service also makes use of the group API.
 */
include_once dirname(__FILE__) . '/bsd.group.api.inc';


class BlueStateDigitalVoting extends BlueStateDigitalService {

  /**
   * Limit votes to once per day.
   *
   * Allow users to vote once per calendar day for the configured time zone.
   */
  const NO_LIMIT = 0;
  const ONCE_PER_CALENDAR_DAY = 1;
  const ONCE_PER_LIFETIME = 2;

  const TEMPLATE_NAME = "Ballot";

  protected $consGroupApi;

  protected $calendarTimeZone;

  public function __construct($api_id, $api_secret, $rest_method, $request_base,
    $request_timeout = 10) {

    parent::__construct($api_id, $api_secret, $rest_method, $request_base,
      $request_timeout);

    // This service also makes use of the constituent group API.
    $this->consGroupApi = new BlueStateDigitalConstituentGroupApi($api_id,
      $api_secret, $rest_method, $request_base, $request_timeout);

    // Set the default timezone for the vote limit calendar.
    $this->setCalendarTimeZone("America/Los_Angeles");
  }

  public function setCalendarTimeZone($tz) {
    $this->calendarTimeZone = $tz;
  }

  public function listBallots() {
    return $this->listInstances(self::TEMPLATE_NAME);
  }

  public function getBallotByTitle($title) {
    return $this->getInstanceByTitle(self::TEMPLATE_NAME, $title);
  }

  public function getBallotByExtId($ext_id) {
    return $this->getInstanceByExtId(self::TEMPLATE_NAME, $ext_id);
  }

  public function createBallot($title, $ext_id, $create_group = FALSE) {
    $ballot_id = $this->cloneSignupFromTemplate(self::TEMPLATE_NAME, $title, $ext_id);
    if ($create_group) {
      $group_name = $this->createName(self::TEMPLATE_NAME, $title);
      $new_groups = $this->consGroupApi->addConstituentGroups(array($group_name));
      $group = reset($new_groups);
      if ($group !== FALSE) {
        $this->signupApi->setFormConsGroup($ballot_id, $group['id']);
      }
    }
    return $ballot_id;
  }

  public function setBallotGroup($ballot_id, $group_id) {
    $this->signupApi->setFormConsGroup($ballot_id, $group_id);
  }

  public function setOptInGroup($ballot_id, $index, $group_id) {
    $fields = $this->getFieldIds($ballot_id, TRUE);
    $field_id = $fields->{"opt_in_{$index}"};
    $this->signupApi->setFieldConsGroup($field_id, $group_id);
  }

  protected function getFieldIds($ballot_id, $reset = FALSE) {

    $key = $this->createSlug(self::TEMPLATE_NAME, $ballot_id);

    $mapping = NULL;
    if ($reset || !$this->cacheGet($key, $mapping)) {

      $fields = $this->signupApi->listFormFields($ballot_id);

      $mapping = new StdClass();
      $mapping->opt_in = array();
      foreach ($fields as $id => $field) {

        if ($field['label'] === 'Email') {
          $mapping->email = $id;
        }
        elseif ($field['label'] === 'vote') {
          $mapping->vote = $id;
        }
        elseif ($field['label'] === 'referrer-code') {
          $mapping->referrer_code = $id;
        }
        elseif ($field['label'] === 'referrer-opt-in') {
          $mapping->referrer_opt_in = $id;
        }
        else {
          $pattern = '/^opt-in-(?P<index>\d+)$/';
          $matches = array();
          if (preg_match($pattern, $field['label'], $matches)) {
            $index = $matches['index'];
            $mapping->opt_in[$index] = $id;
          }
        }
      }

      $this->cacheSet($key, $mapping);
    }

    return $mapping;
  }

  public function castVote($ballot_id, $email, $vote, $opt_ins = array(),
    $referrer_code = NULL, $referrer_opt_in = NULL) {

    // Get the field ids for the ballot.
    $mapping = $this->getFieldIds($ballot_id);

      // Email and vote are required fields.
      if (isset($mapping->email) && isset($mapping->vote)) {

      // Populate the fields of the signup.
      $fields = array(
        $mapping->email => BlueStateDigitalSignupApi::signupValue($email),
        $mapping->vote => BlueStateDigitalSignupApi::signupValue($vote),
      );

      // Add in the option referrer code and opt-in.
      if (isset($referrer_code)) {
        $fields[$mapping->referrer_code]
          = BlueStateDigitalSignupApi::signupValue($referrer_code);
        if (isset($referrer_opt_in)) {
          $fields[$mapping->referrer_opt_in]
            = BlueStateDigitalSignupApi::signupValue($referrer_opt_in);
        }
      }

      // Populate the emails opt-ins from the form definition to allow additional
      // opt-ins to be added or removed from the template without effecting
      // existing ballots.
      foreach ($mapping->opt_in as $index => $id) {
        if (isset($opt_ins[$index])) {
          $checked = $opt_ins[$index] ? 1 : 0;
          $fields[$id] = BlueStateDigitalSignupApi::signupValue($checked);
        }
      }
      $signup = array($ballot_id => $fields);

      // Send the signup.
      $this->signupApi->processSignup($signup);

      return TRUE;
    }

    return FALSE;
  }

  public function getMostRecentVote($ballot_id, $email) {

    $signups = $this->signupApi->getSignupsByEmail($email);

    $latest = NULL;
    foreach ($signups as $signup) {
      if ($signup['signup_form_id'] == $ballot_id) {
        if (!isset($latest) || $signup['create_dt'] > $latest['create_dt']) {
          $latest = $signup;
        }
      }
    }

    if (isset($latest)) {
      // Get the field ids for the ballot.
      $mapping = $this->getFieldIds($ballot_id);
      // Return the vote token value if there is one.
      if (isset($latest['extra_fields'][$mapping->vote])) {
        return array(
          'token' => $latest['extra_fields'][$mapping->vote]['varchar'],
          'timestamp' => $latest['create_dt'],
        );
      }
    }

    return FALSE;
  }

  public function checkEligibility($most_recent_vote, $frequency = self::NO_LIMIT) {

    // Check if there is even a most recent vote to start with.
    if ($most_recent_vote === FALSE) {
      return TRUE;
    }

    if ($frequency === self::ONCE_PER_CALENDAR_DAY) {

      // Date comparisons are done in a specific timezone.
      $tz = new DateTimeZone($this->calendarTimeZone);
      $now = new DateTime();
      $now->setTimezone($tz);

      $timestamp = (string) $most_recent_vote['timestamp'];
      $created = new DateTime();
      $created->setTimestamp($timestamp);
      $created->setTimezone($tz);

      // Check if the vote is on the same day of the year.
      if ($now->format('Yz') == $created->format('Yz')) {
        return FALSE;
      }
    }
    elseif ($frequency === self::ONCE_PER_LIFETIME) {
      // One vote for all time.
      return FALSE;
    }

    return TRUE;
  }
}

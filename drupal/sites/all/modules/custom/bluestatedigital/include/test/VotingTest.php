<?php

include_once dirname(__FILE__) . '/../bsdapi/bsd.voting.inc';

class VotingTest extends PHPUnit_Framework_TestCase {
/*
  const API_ID = "takepart-com";
  const API_SECRET = "ae2cbc9a230ba4c36a9972fb7eeef41e2f2c62f8";
  const REST_METHOD = BlueStateDigitalApi::REST_METHOD_CURL;
  const REQUEST_BASE = "http://action.takepart.com/page/api/";
*/
  const API_ID = "takepart-qa";
  const API_SECRET = "4a5ecec2568a4ab7a74e26032b8f886c9f8d3057";
  const REST_METHOD = BlueStateDigitalApi::REST_METHOD_CURL;
  const REQUEST_BASE = "http://tkprtdemo.bsdtoolsdemo.com/page/api/";

  const EXISTING_BALLOT_COUNT = 1;

  protected static $timestamp;

  /**
   * Create a test email for all tests.
   */
  public static function setUpBeforeClass()
  {
    self::$timestamp = time();
  }

  public static function getEmail() {
    return "vote." . (string) self::$timestamp . ".test@takepart.com";
  }

  public static function getTitle() {
    return "Test " . (string) self::$timestamp;
  }

  public static function getExtId() {
    return "test-" . (string) self::$timestamp;
  }

  public static function getToken($index) {
    return "token-" . (string) $index . "-" . (string) self::$timestamp;
  }

  /**
   * Instantiate the voting service.
   */
  public function testConstruction() {
    $service = new BlueStateDigitalVoting(self::API_ID, self::API_SECRET,
      self::REST_METHOD, self::REQUEST_BASE);
    return $service;
  }

  /**
   * Check that there are not ballots left over from the last test run.
   *
   * @depends testConstruction
   */
  public function testExistingBallots($service) {
    $ballots = $service->listBallots();
    $this->assertTrue(is_array($ballots));
    $this->assertFalse(empty($ballots));
    $this->assertEquals(self::EXISTING_BALLOT_COUNT, count($ballots));
    return $service;
  }

  /**
   * Create a new ballot from the template.
   *
   * @depends testExistingBallots
   */
  public function testCreateBallot($service) {
    $ballot_id = $service->createBallot(self::getTitle(), self::getExtId(), TRUE);
    return $service;
  }

  /**
   * Confirm that new ballot is available in the list of ballots
   *
   * @depends testCreateBallot
   */
  public function testOneBallotCreated($service) {
    $ballots = $service->listBallots();
    $this->assertEquals(self::EXISTING_BALLOT_COUNT + 1, count($ballots));
    return $service;
  }

  /**
   * @depends testOneBallotCreated
   */
  public function testGetBallot($service) {

    $ballot = $service->getBallotByExtId(self::getExtId());

    $this->assertNotEquals(FALSE, $ballot);
    $this->assertTrue(is_array($ballot));
    $this->assertArrayHasKey('id', $ballot);
    $this->assertArrayHasKey('signup_form_name', $ballot);
    $this->assertArrayHasKey('signup_form_slug', $ballot);
    $this->assertArrayHasKey('form_public_title', $ballot);
    $this->assertArrayHasKey('create_dt', $ballot);

    $name = "Ballot - " . self::getTitle();
    $this->assertEquals($name, $ballot['signup_form_name']);

    $slug = "ballot-" . self::getExtId();
    $this->assertEquals($slug, $ballot['signup_form_slug']);

    return $service;
  }

  /**
   * @depends testGetBallot
   */
  public function testAllowOncePerDayVote($service) {

    $ballot = $service->getBallotByExtId('manually-created');

    $vote = $service->getMostRecentVote($ballot['id'], self::getEmail());
    $this->assertFalse($vote);

    $allowed = $service->checkEligibility($vote,
      BlueStateDigitalVoting::ONCE_PER_CALENDAR_DAY);
    $this->assertTrue($allowed);

    return $service;
  }

  /**
   * @depends testAllowOncePerDayVote
   */
  public function testCastFirstVote($service) {

    $ballot = $service->getBallotByExtId('manually-created');

    $opt_ins = array(
      1 => TRUE,
      2 => FALSE,
      3 => TRUE,
      4 => FALSE,
      5 => FALSE,
    );

    $service->castVote($ballot['id'], self::getEmail(), self::getToken(1),
      $opt_ins, 'referrer_code', TRUE);

    return $service;
  }

  /**
   * @depends testCastFirstVote
   */
  public function testDenyOncePerDayVote($service) {

    // Wait for the vote to propagate on the BSD side.
    sleep(2);

    $ballot = $service->getBallotByExtId('manually-created');

    $vote = $service->getMostRecentVote($ballot['id'], self::getEmail());
    $this->assertTrue(is_array($vote));
    $this->assertArrayHasKey('token', $vote);
    $this->assertArrayHasKey('timestamp', $vote);
    $this->assertEquals(self::getToken(1), $vote['token']);

    $allowed = $service->checkEligibility($vote,
      BlueStateDigitalVoting::ONCE_PER_CALENDAR_DAY);
    $this->assertFalse($allowed);

    return $service;
  }

  /**
   * @depends testDenyOncePerDayVote
   */
  public function testCastSecondVote($service) {

    $ballot = $service->getBallotByExtId('manually-created');
    $service->castVote($ballot['id'], self::getEmail(), self::getToken(2));

    return $service;
  }

  /**
   * @depends testCastSecondVote
   */
  public function testGetMostRecentVote($service) {

    // Wait for the vote to propagate on the BSD side.
    sleep(2);

    $ballot = $service->getBallotByExtId('manually-created');

    $vote = $service->getMostRecentVote($ballot['id'], self::getEmail());
    $this->assertTrue(is_array($vote));
    $this->assertArrayHasKey('token', $vote);
    $this->assertArrayHasKey('timestamp', $vote);
    $this->assertEquals(self::getToken(2), $vote['token']);

    return $service;
  }
}

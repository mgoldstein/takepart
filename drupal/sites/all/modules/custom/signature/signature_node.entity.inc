<?php
/**
 * @file
 * Signature node settings entity.
 */

/**
 * SignatureNode Entity.
 */
class SignatureNode extends Entity {

  /**
   * Overrides Entity::__construct().
   */
  public function __construct($values = array(),
    $entity_type = 'signature_node') {
    parent::__construct($values, $entity_type);
  }

  /**
   * Overrides Entity::defaultUri().
   */
  protected function defaultUri() {
    if (!empty($this->nid)) {
      return array(
        'path' => 'node/' . $this->nid,
      );
    }
    return NULL;
  }
}

class SignatureNodeController extends EntityAPIController {

  /**
   * Implements EntityApiControllerInterface.
   */
  public function create(array $values = array()) {
    $values += array(
      'nid' => '',
      'type' => '',
      'goal' => 100000,
      'bsd_form' => 0,
      'limit_to_dates' => FALSE,
      'start_date' => time(),
      'end_date' => time() + 365 * 24 * 60 * 60,
      'heading' => '',
      'sign_label' => '',
      'newsletter_opt_ins' => array(),
      'restrictions' => '',
      'terms_of_use' => "By signing, you accept TakePart's "
      . '<a href="/terms-of-use" target="_blank">Terms of Use</a>.',
      'display_disclaimer' => implode(' ', array(
        'You may choose not to display your name on this website,',
        'but TakePart will include your name,',
        'e-mail address and zip code in the petition,',
        'which may be made public and presented to lawmakers.',
      )),
    );
    return parent::create($values);
  }

  /**
   * Implements EntityApiControllerInterface.
   */
  protected function buildQuery($ids, $conditions = array(),
    $revision_id = FALSE) {
    global $user;
    $email = empty($user->mail) ? '' : $user->mail;
    $count_query = db_select('signature', 'sc');
    $count_query->addField('sc', 'nid', 'nid');
    $count_query->addExpression('COUNT(sc.nid)', 'count');
    $count_query->groupBy('sc.nid');
    $signed_query = db_select('signature', 'ss');
    $signed_query->addField('ss', 'nid', 'nid');
    $signed_query->addExpression('COUNT(ss.nid)', 'signed');
    $signed_query->condition('ss.email', $email, '=');
    $signed_query->groupBy('ss.nid');
    $query = parent::buildQuery($ids, $conditions, $revision_id);
    $query->leftJoin('node', 'n', 'base.nid = n.nid');
    $query->addField('n', 'title', 'title');
    $query->addField('n', 'type', 'node_type');
    $query->leftJoin($count_query, 'c', 'base.nid = c.nid');
    $query->addField('c', 'count', 'count');
    $query->leftJoin($signed_query, 's', 'base.nid = s.nid');
    $query->addField('s', 'signed', 'signed');
    return $query;
  }

  /**
   * Implements EntityApiControllerInterface.
   */
  protected function attachLoad(&$queried_entities, $revision_id = FALSE) {
    foreach ($queried_entities as $key => $entity) {
      if (!isset($entity->count)) {
        $entity->count = 0;
      }
      if (!isset($entity->signed)) {
        $entity->signed = 0;
      }
      if (!isset($entity->title)) {
        $entity->title = t('Settings for node @nid', array(
          '@nid' => $entity->nid,
        ));
      }
      if (!isset($entity->node_type)) {
        $entity->node_type = '';
      }
      $queried_entities[$key] = $entity;
    }
    parent::attachLoad($queried_entities, $revision_id);
  }

  /**
   * Calculates the progress towards goal of the signature collecting node.
   */
  public function progressVariables($entity) {

    // Calculate the progress percentage.
    if ($entity->goal > 0) {
      $percent = ((float) $entity->count / (float) ($entity->goal)) * 100.0;
    }
    else {
      $percent = 0.0;
    }

    // Calculate the progress classes.
    $percent_as_unit = floor($percent);
    $percent_as_tenth = floor($percent / 10.0);
    $percent_as_twentieth = floor($percent / 5.0);
    $percent_as_half = $percent < 50.0 ? 'first-half' : 'second-half';
    $complete_classes = array(
      "signature-progress-complete-{$percent_as_unit}",
      "signature-progress-complete-tenth-{$percent_as_tenth}",
      "signature-progress-complete-twentieth-{$percent_as_twentieth}",
      "signature-progress-complete-{$percent_as_half}",
    );
    if ($entity->count >= $entity->goal) {
      $complete_classes[] = 'signature-progress-complete-goal';
    }

    // Calculate the count classes.
    $count_classes = array(
      "signature-progress-count-{$entity->count}",
    );
    if ($entity->count >= $entity->goal) {
      $count_classes[] = 'signature-progress-count-goal';
    }

    // Calculate the number of signaturs needed.
    $needed = ($entity->goal >= $entity->count)
      ? $entity->goal - $entity->count : 0;

    // Calculate the number of days left.
    $days_left = 0;
    $now = getdate();
    $now_seconds = mktime(0, 0, 0, $now['mon'], $now['mday'], $now['year']);
    $seconds_left = $entity->end_date - $now_seconds;
    if ($seconds_left >= 0) {
      $days_left = floor((float) $seconds_left / (float) (24 * 60 * 60)) + 1;
    }

    // The signature collection state is determined by wether the user is logged
    // in and has an existing signature, unless signature collection is closed.
    $state = empty($entity->signed) ? 'unsigned' : 'signed';
    if ($days_left == 0 && $entity->limit_to_dates != 0) {
      $state = 'closed';
    }

    $decimals = variable_get('signature_progress_decimals', 0);
    if ($decimals == -1) {
      $decimals = $percent < 10.0 ? 1 : 0;
    }

    return array(
      'percent' => $percent,
      'decimals' => $decimals,
      'complete_classes' => $complete_classes,
      'count_classes' => $count_classes,
      'count' => $entity->count,
      'goal' => $entity->goal,
      'needed' => $needed,
      'days_left' => $days_left,
      'state' => $state,
    );
  }
}

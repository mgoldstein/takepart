<?php
/**
 * @file
 * Contest Entity.
 */

class TakePartContest extends Entity {

  const DURATION_NONE  = 'none';
  const DURATION_SLOT  = 'slot';
  const DURATION_SPAN  = 'span';
  const DURATION_PHASE = 'phase';

  const UNITS_MINUTES  = 'minutes';
  const UNITS_HOURS    = 'hours';
  const UNITS_DAYS     = 'days';
  const UNITS_WEEKS    = 'weeks';
  const UNITS_MONTHS   = 'months';
  const UNITS_YEARS    = 'years';
  const UNITS_LIFETIME = 'lifetime';

  public function __construct($values = array(),
    $entity_type = 'takepart_contests_contest') {
    parent::__construct($values, $entity_type);
  }

  protected function defaultUri() {
    $info = $this->entityInfo();
    if (isset($info['admin ui']) && isset($info['admin ui']['path'])) {
      $base = $info['admin ui']['path'];
      return array('path' => $base . '/manage/' . (string) $this->identifier());
    }
    return NULL;
  }

  public function createEntry(array $values = array()) {
    $values += array(
      'contest_id' => $this->contest_id,
      'type' => $this->type . '_entry',
      'name' => $this->name . ' Entry',  
    );
    return entity_create('takepart_contests_contest_entry', $values);
  }
}

class TakePartContestController extends EntityAPIController {

  public function create(array $values = array()) {
    $values += array(
      'contest_id' => '',
      'type' => '',
      'language' => '',
      'is_new' => TRUE,
      'name' => '', 
      'created' => 0,
      'changed' => 0,
      'entry_period' => array(
        'duration' => array(
          'type' => TakePartContest::DURATION_SLOT,
          'count' => 1,
          'units' => TakePartContest::UNITS_DAYS,
          'start' => strftime('%H:%M %m/%d/%Y'),
        )
      ),
    );
    return parent::create($values);
  }

  public function save($entity, DatabaseTransaction $transaction = NULL) {
    // Set/update the created and changed timestamps
    $entity->is_new = isset($entity->is_new) ? $entity->is_new : FALSE;
    if ($entity->is_new) {
      $entity->created = time();
    }
    $entity->changed = time();
    return parent::save($entity, $transaction);
  }
}

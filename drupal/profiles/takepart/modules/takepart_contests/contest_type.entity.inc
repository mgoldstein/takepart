<?php
/**
 * @file
 * Contest Type Entity.
 */

class TakePartContestType extends Entity {

  public function __construct($values = array(),
    $entity_type = 'takepart_contests_contest_type') {
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

  public function entryType() {
    return $this->identifier() . '_entry';
  }
}

class TakePartContestTypeController extends EntityAPIControllerExportable {

  public function create(array $values = array()) {
    $values += array(
      'id' => '',
      'type' => '',
      'label' => '',
      'default_entry_period' => '',
      'weight' => 0,
      'status' => ENTITY_CUSTOM,
      'module' => 'takepart_contests',
    );
    return parent::create($values);
  }
}

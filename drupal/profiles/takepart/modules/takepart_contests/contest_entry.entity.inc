<?php
/**
 * @file
 * Contest Entry Entity.
 */

class TakePartContestEntry extends Entity {

  public function __construct($values = array(),
    $entity_type = 'takepart_contests_contest_entry') {
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
}

class TakePartContestEntryController extends EntityAPIController {

  public function create(array $values = array()) {
    $values += array(
        'entry_id' => '',
        'contest_id' => '',
        'language' => LANGUAGE_NONE,
        'uid' => 0,
        'status' => TRUE,
        'created' => 0,
        'changed' => 0,
    );
    return parent::create($values);
  }

  protected function buildQuery($ids, $conditions = array(), $revision_id = FALSE) {
    $query = parent::buildQuery($ids, $conditions, $revision_id);
    $query->innerJoin('takepart_contests_contest', 'c',
      'base.contest_id = c.contest_id');
    $query->addField('c', 'type', 'type');
    $query->addField('c', 'name', 'name');
    return $query;
  }

  protected function attachLoad(&$queried_entities, $revision_id = FALSE) {
    foreach ($queried_entities as $key => $entity) {
      $entity->type = $entity->type . '_entry';
      $entity->name = $entity->name . ' Entry';
      $queried_entities[$key] = $entity;
    }
    parent::attachLoad($queried_entities, $revision_id);
  }

  public function save($entity, DatabaseTransaction $transaction = NULL) {
    global $user;
    // set/update the created and changed timestamps
    $entity->is_new = isset($entity->is_new) ? $entity->is_new : 0;
    if ($entity->is_new) {
      $entity->uid = $user->uid;
      $entity->created = time();
    }
    $entity->changed = time();
    return parent::save($entity, $transaction);
  }
}

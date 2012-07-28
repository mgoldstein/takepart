<?php
/**
 * @file
 * Ideas for Good Voting Group Entity.
 */

class IdeasForGoodVotingGroup extends Entity {

  public function __construct($values = array(),
    $entity_type = 'ideasforgood_voting_group') {
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

class IdeasForGoodVotingGroupController extends EntityAPIController {

  public function create(array $values = array()) {
    $values += array(
      'id' => '',
      'name' => '',
      'contest' => '',
      'voting_form_id' => 0,
      'email_field_id' => 0,
      'vote_field_id' => 0,
      'opt_in_field_id' => 0,
      'created' => 0,
      'changed' => 0,
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

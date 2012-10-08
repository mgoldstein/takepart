<?php
/**
 * @file
 * Follow up entity and controller classes.
 */

class FollowUp extends Entity {

  /**
   * Overrides Entity::__construct().
   *
   * Provides a default value for the entity type.
   */
  public function __construct($values = array(), $entity_type = 'followup') {
    parent::__construct($values, $entity_type);
  }

  /**
   * Overrides Entity::defaultUri().
   */
  protected function defaultUri() {
    if (!empty($this->nid)) {
      return array('path' => 'node/' . $this->nid);
    }
    return NULL;
  }
}

class FollowUpController extends EntityAPIController {

  /**
   * Overrides EntityAPIController::create().
   */
  public function create(array $values = array()) {
    $values += array(
      'id' => '',
      'title' => '',
      'type' => '',
      'nid' => '',
      'uid' => 0,
      'status' => TRUE,
      'created' => 0,
      'changed' => 0,
    );
    return parent::create($values);
  }

  /**
   * Overrides EntityAPIController::save().
   *
   * Sets the uid, created and changed fields.
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    global $user;
    // Set/update the created and changed timestamps.
    $entity->is_new = isset($entity->is_new) ? $entity->is_new : 0;
    if ($entity->is_new) {
      $entity->uid = $user->uid;
      $entity->created = time();
    }
    $entity->changed = time();
    return parent::save($entity, $transaction);
  }
}

<?php
/**
 * @file
 * Follow up type entity and controller classes.
 */

class FollowUpType extends Entity {

  /**
   * Overrides Entity::__construct().
   *
   * Provides a default value for the entity type.
   */
  public function __construct($values = array(),
    $entity_type = 'followup_type') {
    parent::__construct($values, $entity_type);
  }

  /**
   * Overrides Entity::defaultUri().
   */
  protected function defaultUri() {
    $info = $this->entityInfo();
    if (isset($info['admin ui']) && isset($info['admin ui']['path'])) {
      $base = $info['admin ui']['path'];
      return array('path' => $base . '/manage/' . (string) $this->identifier());
    }
    return NULL;
  }
}

class FollowUpTypeController extends EntityAPIControllerExportable {

  /**
   * Overrides EntityAPIController::create().
   */
  public function create(array $values = array()) {
    $values += array(
      'id' => '',
      'type' => '',
      'label' => '',
      'description' => '',
      'status' => ENTITY_CUSTOM,
      'module' => 'followup',
    );
    return parent::create($values);
  }
}

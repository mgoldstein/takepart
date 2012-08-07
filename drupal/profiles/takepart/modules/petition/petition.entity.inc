<?php
/**
 * @file
 * Petition Entity.
 */

class Petition extends Entity {

  public function __construct($values = array(), $entity_type = 'petition') {
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

  public function createSignature(array $values = array()) {
    $values += array(
      'petition_id' => $this->petition_id,
      'type' => $this->type . '_signature',
      'name' => $this->name . ' Signature',  
    );
    return entity_create('petition_signature', $values);
  }
}

class PetitionController extends EntityAPIController {

  public function create(array $values = array()) {
    $values += array(
      'petition_id' => '',
      'type' => '',
      'name' => '',
      'goal' => 100000,
      'language' => LANGUAGE_NONE,
      'status' => TRUE,
      'created' => 0,
      'changed' => 0,
    );
    return parent::create($values);
  }

  protected function attachLoad(&$queried_entities, $revision_id = FALSE) {
    parent::attachLoad($queried_entities, $revision_id);
    foreach ($queried_entities as $key => $entity) {
      $base = "petition:{$entity->type}:{$entity->petition_id}:";
      $entity->thank_you_page = variable_get($base . "thank_you_page", '');
      $entity->updates_page = variable_get($base . "updates_page", '');
      $entity->share_url = variable_get($base . "share_url", '');
      $entity->email_share_msg = variable_get($base . "email_share_msg", '');
      $entity->twitter_share_msg = variable_get($base . "twitter_share_msg", '');
      $queried_entities[$key] = $entity;
    }
  }

  public function save($entity, DatabaseTransaction $transaction = NULL) {
    // Set/update the created and changed timestamps
    $entity->is_new = isset($entity->is_new) ? $entity->is_new : FALSE;
    if ($entity->is_new) {
      $entity->created = time();
    }
    $entity->changed = time();
    $saved = parent::save($entity, $transaction);
    if ($saved !== FALSE) {
      $base = "petition:{$entity->type}:{$entity->petition_id}:";
      variable_set($base . "thank_you_page", $entity->thank_you_page);
      variable_set($base . "updates_page", $entity->updates_page);
      variable_set($base . "share_url", $entity->share_url);
      variable_set($base . "email_share_msg", $entity->email_share_msg);
      variable_set($base . "twitter_share_msg", $entity->twitter_share_msg);
    }
    return $saved;
  }
}

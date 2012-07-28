<?php
/**
 * @file
 * Petition Signature Entity.
 */

class PetitionSignature extends Entity {

  public function __construct($values = array(),
    $entity_type = 'petition_signature') {
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

class PetitionSignatureController extends EntityAPIController {

  public function create(array $values = array()) {
    $values += array(
      'signature_id' => '',
      'petition_id' => '',
      'language' => LANGUAGE_NONE,
      'uid' => 0,
      'hostname' => '',
      'status' => TRUE,
      'created' => 0,
      'changed' => 0,
    );
    return parent::create($values);
  }

  protected function buildQuery($ids, $conditions = array(), $revision_id = FALSE) {
    $query = parent::buildQuery($ids, $conditions, $revision_id);
    $query->innerJoin('petition', 'p', 'base.petition_id = p.petition_id');
    $query->addField('p', 'type', 'type');
    $query->addField('p', 'name', 'name');
    return $query;
  }

  protected function attachLoad(&$queried_entities, $revision_id = FALSE) {
    foreach ($queried_entities as $key => $entity) {
      $entity->type = $entity->type . '_signature';
      $entity->name = $entity->name . ' Signature';
      $queried_entities[$key] = $entity;
    }
    parent::attachLoad($queried_entities, $revision_id);
  }

  public function save($entity, DatabaseTransaction $transaction = NULL) {
    global $user;
    // Set/update the created and changed timestamps
    $entity->is_new = isset($entity->is_new) ? $entity->is_new : FALSE;
    if ($entity->is_new) {
      $entity->uid = $user->uid;
      $entity->hostname = ip_address();
      $entity->created = time();
    }
    $entity->changed = time();
    return parent::save($entity, $transaction);
  }
}

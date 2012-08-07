<?php
/**
 * @file
 * Petition Type Entity.
 */

class PetitionType extends Entity {

  public function __construct($values = array(),
    $entity_type = 'petition_type') {
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

  public function signatureType() {
    return $this->identifier() . '_signature';
  }
}

class PetitionTypeController extends EntityAPIControllerExportable {

  public function create(array $values = array()) {
    $values += array(
      'id' => '',
      'type' => '',
      'label' => '',
      'restrictions_note' => '',
      'terms_of_use_note' => '',
      'signature_display_disclaimer' => '',
      'weight' => 0,
      'status' => ENTITY_CUSTOM, 
      'module' => 'petition',
    );
    return parent::create($values);
  }

  protected function attachLoad(&$queried_entities, $revision_id = FALSE) {
    parent::attachLoad($queried_entities, $revision_id);
    foreach ($queried_entities as $key => $entity) {
      $entity->restrictions_note = variable_get(
        "petition:{$entity->type}:restrictions_note", '');
      $entity->terms_of_use_note = variable_get(
        "petition:{$entity->type}:terms_of_use_note", '');
      $entity->signature_display_disclaimer = variable_get(
        "petition:{$entity->type}:signature_display_disclaimer", '');
      $queried_entities[$key] = $entity;
    } 
  }

  public function save($entity, DatabaseTransaction $transaction = NULL) {
    $saved = parent::save($entity, $transaction);
    if ($saved !== FALSE) {
      variable_set("petition:{$entity->type}:restrictions_note",
        $entity->restrictions_note);
      variable_set("petition:{$entity->type}:terms_of_use_note",
        $entity->terms_of_use_note);
      variable_set("petition:{$entity->type}:signature_display_disclaimer",
        $entity->signature_display_disclaimer);
    }
    return $saved;
  }
}

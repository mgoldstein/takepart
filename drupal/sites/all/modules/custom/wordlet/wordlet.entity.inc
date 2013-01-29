<?php

class Wordlet extends Entity {

  public function __construct($values = array(),
    $entity_type = 'wordlet') {
    parent::__construct($values, $entity_type);
  }
  
  protected function defaultUri() {
    $path = implode('/', array(
      'admin',
      'wordlet',
      'page',
      $this->page,
      'manage',
      $this->id,
    ));
    return array('path' => $path);
  }
}

class WordletController extends EntityAPIControllerExportable {

  public function create(array $values = array()) {
    $values += array(
      'id' => '',
      'page' => '',
      'title' => '',
      'name' => '',
      'description' => '',
      'type' => '',
      'allow_markup' => 0,
      'enabled' => 1,
      'integer_value' => 0,
      'string_value' => '',
      'text_value' => '',
      'markup' => 0,
      'created' => 0,
      'changed' => 0,
      'status' => ENTITY_CUSTOM,
      'module' => 'wordlet',
    );
    return parent::create($values);
  }

  public function save($entity, DatabaseTransaction $transaction = NULL) {
    // set/update the created and changed timestamps
    $entity->is_new = isset($entity->is_new) ? $entity->is_new : 0;
    if ($entity->is_new) {
      $entity->created = time();
    }
    $entity->changed = time();
    return parent::save($entity, $transaction);
  }
}

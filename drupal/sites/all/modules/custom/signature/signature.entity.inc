<?php

class Signature extends Entity {

  public function __construct($values = array(), $entity_type = 'signature') {
    parent::__construct($values, $entity_type);
  }
}

class SignatureController extends EntityAPIController {

  public function create(array $values = array()) {
    global $user;
    $email = !empty($user->uid) ? $user->mail : '';
    $values += array(
      'id' => '',
      'type' => '',
      'nid' => '',
      'email' => $email,
      'display' => 1,
      'newsletter' => 0x1f,
      'language' => LANGUAGE_NONE,
      'uid' => 0,
      'hostname' => '',
      'status' => TRUE,
      'created' => 0,
      'changed' => 0,
    );
    return parent::create($values);
  }

  public function save($entity, DatabaseTransaction $transaction = NULL) {
    global $user;
    // set/update the created and changed timestamps
    $entity->is_new = isset($entity->is_new) ? $entity->is_new : 0;
    if ($entity->is_new) {
      $entity->uid = $user->uid;
      $entity->hostname = ip_address();
      $entity->created = time();
    }
    $entity->changed = time();
    return parent::save($entity, $transaction);
  }
}

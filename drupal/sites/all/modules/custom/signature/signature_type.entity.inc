<?php

class SignatureType extends Entity {

  public function __construct($values = array(),
    $entity_type = 'signature_type') {
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

class SignatureTypeController extends EntityAPIControllerExportable {

  public function create(array $values = array()) {
    $values += array(
      'id' => '',
      'type' => '',
      'label' => '',
      'status' => ENTITY_CUSTOM,
      'module' => 'signature',
    );
    return parent::create($values);
  }
}

<?php

class TakePartVideoPlayerNodeReferenceFieldBuilder {

  protected $entity_type;
  protected $entity;
  protected $langcode;
  protected $items;

  public function __construct($entity_type, $entity, $langcode, $items) {
    $this->entity_type = $entity_type;
    $this->entity = $entity;
    $this->langcode = $langcode;
    $this->items = $items;
  }

  public function settings($global_default) {
    return array();
  }

  public function allowedRegions() {
    return array();
  }
}

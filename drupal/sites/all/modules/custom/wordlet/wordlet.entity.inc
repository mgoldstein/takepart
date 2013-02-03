<?php

class Wordlet extends Entity {

  public $items;

  public function __construct($values = array(), $entity_type = 'wordlet') {
    $this->items = array();
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

  protected function defaultLabel() {
    return empty($this->title) ? $this->name : $this->title;
  }
}

class WordletController extends EntityAPIControllerExportable {

  public function create(array $values = array()) {
    $values += array(
      'id' => '',
      'page' => '',
      'name' => '',
      'title' => '',
      'description' => '',
      'type' => '',
      'format' => 0,
      'enabled' => 1,
      'cardinality' => 1,
      'weight' => 0,
      'items_data' => '',
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

    // serialize the field item values
    $entity->items_data = serialize($entity->items);

    return parent::save($entity, $transaction);
  }

  protected function attachLoad(&$queried_entities, $revision_id = FALSE) {

    // Unserialize the field item values
    foreach ($queried_entities as $key => $entity) {
      $items = unserialize($entity->items_data);
      if (!empty($items) && is_array($items)) {
        $entity->items = $items;
      }
      $queried_entities[$key] = $entity;
    }

    parent::attachLoad($queried_entities, $revision_id);
  }

  private function createViewItem($entity, $item) {

    // Determine the access level for the wordlet.
    $editable = FALSE;
    $configurable = FALSE;
    if (!empty($_COOKIE['show_wordlets'])) {
      if (wordlet_access('administer', $entity)) {
        $editable = TRUE;
        $configurable = TRUE;
      }
      elseif (wordlet_access('administer', $entity)) {
        $editable = TRUE;
        $configurable = FALSE;
      }
    }

    $args = array(
      'id' => $entity->id,
      'page' => $entity->page,
      'name' => $entity->name,
      'type' => $entity->type,
      'format' => $entity->format,
      'editable' => $editable,
      'configurable' => $configurable,
    );
    $args += $item;

    if ($entity->type === 'single-line') {
      return new SingleLineWordlet($args);
    }
    elseif ($entity->type === 'multiple-lines') {
      return new MultipleLineWordlet($args);
    }
    elseif ($entity->type === 'node-reference') {
      return new NodeReferenceWordlet($args);
    }
    elseif ($entity->type === 'simple-link') {
      return new SimpleLinkWordlet($args);
    }
    else {
      return new WordletItem($args);
    }
  }

  public function viewOne($entity) {
    //if ($entity->cardinality != 1) {
    //  // The list object has a __toString method and can be printed directly
    //  return $this->viewList($entity);
    //}
    $first = reset($entity->items);
    $item = $first !== FALSE ? $first : array();
    return $this->createViewItem($entity, $item);
  }

  public function viewList($entity) {
    $wordlets = array();
    foreach ($entity->items as $item) {
      $wordlets[] = $this->createViewItem($entity, $item);
    }
    return new WordletList($wordlets);
  }
}

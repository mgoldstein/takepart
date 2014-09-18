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

  private function getVideoNode() {
    $items = field_get_items($this->entity_type, $this->entity, 'field_ic_video', $this->langcode);
    if ($items !== FALSE && count($items) > 0) {
      $item = reset($items);
      return node_load($item['nid']);
    }
    return NULL;
  }

  public function settings($global_default) {

    $controller = new TakePartVideoPlayerOverrideController();

    // Load the global defaults for the entity view mode.
    $defaults = $controller->loadByName($global_default);

    $configurations = array($defaults);

    $node = $this->getVideoNode();
    if (!is_null($node)) {
      $node_configuration = $controller->loadOverrideForEntity('node',
        $node->nid, 'full_page');
      if (!is_null($node_configuration)) {
        $configurations[] = $node_configuration;
      }
    }

    // Get the configuration overrides for full page nodes.
    $override = $controller->loadOverrideForEntity($this->entity_type,
      entity_id($this->entity_type, $this->entity), 'inline_content');
    if (!is_null($override)) {
      $configurations[] = $override;
    }

    // Merge the defaults with the overrides.
    $configuration = $controller->merge($configurations);

    // The configuration can contain tokens, wrap it in a token resolver object.
    $resolved_configuration =  new TakePartTokenizedObject($configuration,
      array($this->entity_type => $this->entity),
      array('language' => $this->langcode));

    $items = field_get_items('node', $node, 'field_video');
    if ($items !== FALSE && count($items) > 0) {
      $settings_builder = new TakePartVideoPlayerSettingsBuilder($resolved_configuration);
      return $settings_builder->build(reset($items));
    }
    return array();
  }

  public function allowedRegions() {
    $regions = array();
    $node = $this->getVideoNode();
    if (!empty($node)) {
      $items = field_get_items('node', $node, 'field_allowed_regions');
      if ($items !== FALSE && count($items) > 0) {
        foreach ($items as $item) {
          $value = str_replace(array(','), ' ', $item['value']);
          $chunks = explode(' ', $value);
          $trimmed = array_map('trim', $chunks);
          $list = array_filter($trimmed, 'strlen');
          $regions += array_map('strtolower', $list);
        }
      }
    }
    return $regions;
  }
}

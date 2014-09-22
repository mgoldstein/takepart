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

    $configurations = array();

    // Start with the default configuration.
    $defaults = tp_video_player_load_default_configuration($global_default);
    if (!is_null($defaults)) {
      $configurations[] = $defaults;
    }

    $node = $this->getVideoNode();
    if (!is_null($node)) {
      // Add any specific entity overrides.
      $override = tp_video_player_load_entity_configuration('node', $node->nid);
      if (!is_null($override)) {
        $configurations[] = $override;
      }
    }

    // Merge the configurations into a single active configuration.
    $active = tp_video_player_merge_configurations($configurations);

    // The configuration can contain tokens, wrap it in a token resolver object.
    $resolved_configuration =  new TakePartTokenizedObject($active,
      array($this->entity_type => $this->entity),
      array('language' => $this->langcode));

    $items = field_get_items('node', $node, 'field_video');
    if ($items !== FALSE && count($items) > 0) {
      return tp_video_player_build_settings($resolved_configuration, $items);
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

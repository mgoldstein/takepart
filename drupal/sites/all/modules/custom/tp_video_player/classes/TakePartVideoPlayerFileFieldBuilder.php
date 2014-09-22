<?php

class TakePartVideoPlayerFileFieldBuilder {

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

    $configurations = array();

    // Start with the default configuration.
    $defaults = tp_video_player_load_default_configuration($global_default);
    if (!is_null($defaults)) {
      $configurations[] = $defaults;
    }

    // Add any specific entity overrides.
    $override = tp_video_player_load_entity_configuration($this->entity_type,
      entity_id($this->entity_type, $this->entity));
    if (!is_null($override)) {
      $configurations[] = $override;
    }

    // Merge the configurations into a single active configuration.
    $active = tp_video_player_merge_configurations($configurations);

    // The configuration can contain tokens, wrap it in a token resolver object.
    $resolved_configuration =  new TakePartTokenizedObject($active,
      array($this->entity_type => $this->entity),
      array('language' => $this->langcode));

    $settings_builder = new TakePartVideoPlayerSettingsBuilder($resolved_configuration);
    return $settings_builder->build(reset($this->items));
  }

  public function allowedRegions() {
    // Get the allowed regions from the allowed_regions field on the same entity.
    $regions = array();
    $items = field_get_items($this->entity_type, $this->entity,
      'field_allowed_regions');
    if ($items !== FALSE && count($items) > 0) {
      foreach ($items as $item) {
        $value = str_replace(array(','), ' ', $item['value']);
        $chunks = explode(' ', $value);
        $trimmed = array_map('trim', $chunks);
        $list = array_filter($trimmed, 'strlen');
        $regions += array_map('strtolower', $list);
      }
    }
    return $regions;
  }
}

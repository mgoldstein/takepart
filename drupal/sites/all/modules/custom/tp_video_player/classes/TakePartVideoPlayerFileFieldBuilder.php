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

    $controller = new TakePartVideoPlayerOverrideController();

    // Load the global defaults for the entity view mode.
    $configuration = $controller->loadByName($global_default);

    // Get the configuration overrides for full page nodes.
    if ($global_default === 'full_page') {
      $override = $controller->loadOverrideForEntity($this->entity_type,
        $this->entity, 'full_page');
      if (!is_null($override)) {
        // Merge the defaults with the overrides.
        $configuration = $controller->merge(array($configuration, $override));
      }
    }

    // The configuration can contain tokens, wrap it in a token resolver object.
    $resolved_configuration =  new TakePartTokenizedObject($configuration,
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

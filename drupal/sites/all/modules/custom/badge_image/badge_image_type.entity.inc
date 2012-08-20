<?php
/**
 * @file
 * Media Badge Type entity classes.
 */

class BadgeImageType extends Entity {

  public function __construct($values = array(),
    $entity_type = 'badge_image_type') {
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

class BadgeImageTypeController extends EntityAPIControllerExportable {

  public function create(array $values = array()) {
    $values += array(
      'id' => '',
      'type' => '',
      'label' => '',
      'heading' => '',
      'instructions_text' => '',
      'instructions_format' => 'full_html',
      'blank_fid' => 0,
      'font_fid' => 0,
      'font_size' => 51,
      'font_angle' => 0,
      'offset_y' => 300,
      'max_length' => 15,
      'redirect_url' => '',
      'status' => ENTITY_CUSTOM,
      'module' => 'badge_image',
    );
    return parent::create($values);
  }
}

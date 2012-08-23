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
      'max_length' => 15,
      'redirect_url' => '',
      'share_url' => '',
      'blank_fid' => 0,
      'image_font_size' => 51,
      'image_font_angle' => 0,
      'image_offset_y' => 300,
      'preview_fid' => 0,
      'preview_font_size' => 51,
      'preview_font_angle' => 0,
      'preview_offset_y' => 300,
      'twitter_message' => '',
      'email_message' => '',
      'status' => ENTITY_CUSTOM,
      'module' => 'badge_image',
    );
    return parent::create($values);
  }
}

<?php
/**
 * @file
 * Badge Image entity classes.
 */

class BadgeImage extends Entity {

  public function __construct($values = array(), $entity_type = 'badge_image') {
    parent::__construct($values, $entity_type);
  }

  protected function defaultUri() {
    if (!empty($this->fid)) {
      $path = badge_image_create_alias($this, 'return');
    }
    else {
      $info = $this->entityInfo();
      $base = $info['admin ui']['path'];
      $path = $base . '/manage/' . (string) $this->identifier();
    }
    return array('path' => $path);
  }
}

class BadgeImageController extends EntityAPIController {

  public function create(array $values = array()) {
    $values += array(
      'id' => '',
      'type' => '',
      'text' => '',
      'fid' => '',
      'uid' => 0,
      'hostname' => '',
      'created' => 0,
      'changed' => 0,
    );
    return parent::create($values);
  }

  public function save($entity, DatabaseTransaction $transaction = NULL) {
    global $user;
    // Set/update the created and changed timestamps.
    $entity->is_new = isset($entity->is_new) ? $entity->is_new : 0;
    if ($entity->is_new) {
      $entity->uid = $user->uid;
      $entity->hostname = ip_address();
      $entity->created = time();
    }
    $entity->changed = time();
    return parent::save($entity, $transaction);
  }

  public function generateImage($entity) {

    // Make a note of the current image file id.
    $prev_fid = $entity->fid;

    // Get the blank badge.
    $type = badge_image_type_load($entity->type);
    $blank = file_load($type->fid);

    // Create the new badge as a copy.
    $directory = "public://badge_image/badges/" . $type->type;
    drupal_mkdir($directory, NULL, TRUE);
    $destination = $directory . "/badge_{$entity->id}.jpeg";
    $file = file_copy($blank, $destination, FILE_EXISTS_REPLACE);
    file_usage_add($file, 'badge_image', 'badge_image_type', $entity->id);

    // Tie the image to the badge entity.
    $entity->fid = $file->fid;
    entity_save('badge_image', $entity);

    // Update the media page url alias.
    if ($entity->fid != $prev_fid) {
      badge_image_create_alias($entity, 'insert');
    }
    else {
      badge_image_create_alias($entity, 'update');
    }

    // Add the text to the badge.
    $badge = image_load($file->uri);
    if (image_gd_load($badge)) {

      $font_file = drupal_get_path('module', 'badge_image')
      . '/fonts/ITC__Avant__Garde_Bold.ttf';

      $text = strtoupper(check_plain($entity->text));

      $textbox = imagettfbbox($type->font_size, $type->font_angle, $font_file,
        $text);
      $width = abs($textbox[2] - $textbox[0]);

      $x = ($badge->info['width'] - $width) / 2;
      $y = $type->offset_y;

      $black = imagecolorallocate($badge->resource, 0, 0, 0);
      imagettftext($badge->resource, $type->font_size, $type->font_angle, $x,
        $y, $black, $font_file, $text);

      return image_gd_save($badge, $destination);
    }

    return FALSE;
  }
}

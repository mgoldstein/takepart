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
    if (!empty($this->image_fid)) {
      $path = badge_image_create_image_alias($this, 'return');
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
      'image_fid' => 0,
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

  /**
   * Badge Image creation function.
   */
  public function generateImage($entity) {

    // Make a note of the original image file id.
    $original_fid = $entity->image_fid;

    // Get the blank badge.
    $type = badge_image_type_load($entity->type);
    $blank = file_load($type->blank_fid);

    // Create the new badge as a copy.
    $directory = "public://badge_image/badges/" . $type->type;
    drupal_mkdir($directory, NULL, TRUE);
    $destination = $directory . "/badge_{$entity->id}.jpeg";
    $file = file_copy($blank, $destination, FILE_EXISTS_REPLACE);
    file_usage_add($file, 'badge_image', 'badge_image_type', $entity->id);

    // Tie the image to the badge entity.
    $entity->image_fid = $file->fid;
    entity_save('badge_image', $entity);

    // Update the media page url alias.
    if (empty($original_fid)) {
      badge_image_create_image_alias($entity, 'insert');
      $share_url = badge_image_create_speakup_alias($entity, 'insert');
    }
    else {
      badge_image_create_image_alias($entity, 'update');
      $share_url = badge_image_create_speakup_alias($entity, 'update');
    }

    $query = db_merge('badge_image_share')
      ->key(array('id' => $entity->id))
      ->fields(array(
        'share_url' => $share_url['alias'],
      ));
      $query->execute();

    // Add the text to the badge.
    $badge = image_load($file->uri);
    if (image_gd_load($badge)) {

      $font_file = drupal_get_path('module', 'badge_image')
      . '/fonts/ITC__Avant__Garde_Bold.ttf';

      $text = strtoupper(check_plain($entity->text));

      // Calculate the position of the text.
      $textbox = imagettfbbox($type->image_font_size, $type->image_font_angle,
        $font_file, $text);
      $width = abs($textbox[2] - $textbox[0]);
      $x = ($badge->info['width'] - $width) / 2;
      $y = $type->image_offset_y;

      // Draw the text on the blank.
      $black = imagecolorallocate($badge->resource, 0, 0, 0);
      imagettftext($badge->resource, $type->image_font_size,
        $type->image_font_angle, $x, $y, $black, $font_file, $text);

      // Save the updated image.
      return image_gd_save($badge, $destination);
    }
    return FALSE;
  }
}

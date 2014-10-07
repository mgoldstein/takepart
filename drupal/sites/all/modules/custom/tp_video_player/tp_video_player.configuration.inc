<?php
/**
 * @file
 * TakePart custom video player configuration object.
 */

define ('TP_VIDEO_PLAYER_NO_SCHEDULE', 0);
define ('TP_VIDEO_PLAYER_VIDEO_SCHEDULE', 1);
define ('TP_VIDEO_PLAYER_PLAYLIST_SCHEDULE', 2);

function tp_video_player_defaults($name = NULL) {
  $info = array(
    'video_full_page' => array(
      'type' => 'video',
      'title' => 'Video Full Page',
      'description' => 'Full page video nodes.',
    ),
    'video_block' => array(
      'type' => 'video',
      'title' => 'Video Block (Right Rail)',
      'description' => 'Videos featured in a block.',
    ),
    'video_iframe' => array(
      'type' => 'video',
      'title' => 'Video iFrame Embed',
      'description' => 'Videos embedded on other sites using an iframe.',
    ),
    'video_inline_content' => array(
      'type' => 'video',
      'title' => 'Video Inline Content',
      'description' => 'Videos embedded in other content as an inline replacement.',
    ),
    'video_feature_main' => array(
      'type' => 'video',
      'title' => 'Video Front Page Feature',
      'description' => 'Videos featured on the front page.',
    ),
    'video_feature_main_tpl' => array(
      'type' => 'video',
      'title' => 'Video Front Page Feature (TPL)',
      'description' => 'Videos featured in the TPL section of the front page.',
    ),
    'video_feature_topic' => array(
      'type' => 'video',
      'title' => 'Video Topic Page Feature',
      'description' => 'Videos featured on topic pages.',
    ),
    'playlist_full_page' => array(
      'type' => 'playlist',
      'title' => 'Playlist Full Page',
      'description' => 'Full page playlist nodes.',
    ),
    'playlist_block' => array(
      'type' => 'playlist',
      'title' => 'Playlist Block (Right Rail)',
      'description' => 'Playlists featured in a block.',
    ),
    'playlist_iframe' => array(
      'type' => 'playlist',
      'title' => 'Playlist iFrame Embed',
      'description' => 'Playlists embedded on other sites using an iframe.',
    ),
    'playlist_inline_content' => array(
      'type' => 'playlist',
      'title' => 'Playlist Inline Content',
      'description' => 'Playlists embedded in other content as an inline replacement.',
    ),
    'playlist_feature_main' => array(
      'type' => 'playlist',
      'title' => 'Playlist Front Page Feature',
      'description' => 'Playlists featured on the front page.',
    ),
    'playlist_feature_main_tpl' => array(
      'type' => 'playlist',
      'title' => 'Playlist Front Page Feature (TPL)',
      'description' => 'Playlists featured in the TPL section of the front page.',
    ),
    'playlist_feature_topic' => array(
      'type' => 'playlist',
      'title' => 'Playlist Topic Page Feature',
      'description' => 'Playlists featured on topic pages.',
    ),
  );

  if (is_null($name)) { return $info; }
  if (isset($info[$name])) { return $info[$name]; }
  return NULL;
}

function tp_video_player_create_configuration($values = array()) {
  $object = new StdClass();
  $values += array(

    /* Keys */
    'id' => NULL,
    'name' => NULL,

    /* Promo */
    'show_promo_title' => NULL,
    'promo_image' => NULL,
    'promo_title' => NULL,

    /* Layout */
    'show_controls' => NULL,
    'responsive' => NULL,
    'width' => NULL,
    'height' => NULL,
    'skin' => NULL,
    'stretching' => NULL,

    /* Playback */
    'auto_start' => NULL,
    'fallback' => NULL,
    'mute_playback' => NULL,
    'repeat_playback' => NULL,
    'primary_player' => NULL,

    /* Playlist */
    'playlist_position' => NULL,
    'playlist_size' => NULL,
    'playlist_layout' => NULL,

    /* Sharing */
    'enable_share' => NULL,
    'share_heading' => NULL,
    'share_url' => NULL,
    'embed_code' => NULL,

    /* Analytics */
    'enable_jwplayer_analytics' => NULL,
    'google_analytics_object' => NULL,
    'google_analytics_title' => NULL,
    'site_catalyst_media_name' => NULL,
    'site_catalyst_player_name' => NULL,

    /* Advertising */
    'ad_schedule' => NULL,
    'ad_frequency' => NULL,
    'ad_client' => NULL,
    'ad_tag' => NULL,
    'ad_message' => NULL,

    /* Timestamps */
    'created_at' => NULL,
    'updated_at' => NULL,
  );
  foreach ($values as $name => $value) {
    $object->{$name} = $value;
  }
  return $object;
}

function tp_video_player_load_default_configuration($name) {
  $object = db_select('tp_video_player_configuration', 'c')
    ->fields('c')
    ->condition('name', $name, '=')
    ->isNotNull('name')
    ->range(0, 1)
    ->execute()
    ->fetchObject();
  // Use NULL for not found instead of FALSE.
  return $object !== FALSE ? $object : NULL;
}

function tp_video_player_clone_default_configuration($name) {
  $configuration = tp_video_player_load_default_configuration($name);
  $values = is_null($configuration) ? array() : (array) $configuration;
  unset($values['name']);
  unset($values['id']);
  unset($values['created_at']);
  unset($values['updated_at']);
  return tp_video_player_create_configuration($values);
}

function tp_video_player_load_entity_configuration($entity_type, $entity_id, $view_mode) {
  $query = db_select('tp_video_player_configuration', 'c')
    ->fields('c');
  $query->join('tp_video_player_entity_configuration', 'e', 'e.configuration_id = c.id');
  $object = $query->condition('e.entity_type', $entity_type, '=')
    ->condition('e.entity_id', $entity_id, '=')
    ->condition('e.view_mode', $view_mode, '=')
    ->range(0, 1)
    ->execute()
    ->fetchObject();
  // Use NULL for not found instead of FALSE.
  return $object !== FALSE ? $object : NULL;
}

function tp_video_player_resolve_entity_configuration($entity_type, $entity, $langcode, $configuration) {
  foreach ((array) $configuration as $name => $value) {
    $configuration->{$name} = token_replace($value,
      array($entity_type => $entity), array('language' => $langcode));
  }
  return $configuration;
}

function tp_video_player_attach_entity_configuration($entity_type, $entity_id, $view_mode, $configuration) {
  $fields = array(
    'configuration_id' => $configuration->id,
    'entity_type' => $entity_type,
    'entity_id' => $entity_id,
    'view_mode' => $view_mode,
  );
  db_merge('tp_video_player_entity_configuration')
    ->key(array('configuration_id' => $configuration->id))
    ->fields($fields)
    ->execute();
}

function tp_video_player_delete_entity_configuration($entity_type, $entity_id) {
  $ids = db_select('tp_video_player_entity_configuration', 'e')
    ->fields('e', array('configuration_id'))
    ->condition('e.entity_type', $entity_type, '=')
    ->condition('e.entity_id', $entity_id, '=')
    ->execute()
    ->fetchCol();
  db_delete('tp_video_player_entity_configuration')
    ->condition('entity_type', $entity_type, '=')
    ->condition('entity_id', $entity_id, '=')
    ->execute();

  if (!empty($ids)) {
    db_delete('tp_video_player_configuration')
      ->condition('id', $ids, 'IN')
      ->execute();
  }
}

function tp_video_player_save_configuration($configuration) {
  $values = (array) $configuration;
  if (isset($values['id'])) {
    $configuration->updated_at = $values['updated_at'] = REQUEST_TIME;
    db_update('tp_video_player_configuration')
      ->fields($values)
      ->condition('id', $values['id'], '=')
      ->execute();
  }
  else {
    $configuration->created_at = $values['created_at'] = REQUEST_TIME;
    $configuration->updated_at = $values['updated_at'] = REQUEST_TIME;
    db_insert('tp_video_player_configuration')
      ->fields($values)
      ->execute();
    $configuration->id = Database::getConnection()->lastInsertId();
  }
}

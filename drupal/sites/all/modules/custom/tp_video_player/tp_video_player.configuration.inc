<?php
/**
 * @file
 * TakePart custom video player configuration object.
 */

function tp_video_player_defaults_info() {
  return array(
    'full_page' => array(
      'title' => 'Full Page',
      'description' => 'Full page video and playlist nodes.',
    ),
    'block' => array(
      'title' => 'Block (Right Rail)',
      'description' => 'Videos and playlists featured in a block.',
    ),
    'iframe' => array(
      'title' => 'iFrame Embed',
      'description' => 'Videos and playlists embedded on other sites using an iframe.',
    ),
    'inline_content' => array(
      'title' => 'Inline Content',
      'description' => 'Videos and playlists embedded in other content as an inline replacement.',
    ),
    'feature_main' => array(
      'title' => 'Front Page Feature',
      'description' => 'Videos and playlists featured on the front page.',
    ),
    'feature_main_tpl' => array(
      'title' => 'Front Page Feature (TPL)',
      'description' => 'Videos and playlists featured in the TPL section of the front page.',
    ),
    'feature_topic' => array(
      'title' => 'Topic Page Feature',
      'description' => 'Videos and playlists featured on topic pages.',
    ),
  );
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

function tp_video_player_create_default_configuration($name) {
  return tp_video_player_create_configuration(array(

    /* Allow access by name */
    'name' => $name,

    /* Promo */
    'show_promo_title' => 1,
    'promo_image' => NULL,
    'promo_title' => '[node:title]',

    /* Layout */
    'show_controls' => 1,
    'responsive' => 1,
    'width' => 16,
    'height' => 9,
    'skin' => 'glow',
    'stretching' => 'uniform',

    /* Playback */
    'auto_start' => 1,
    'fallback' => 0,
    'mute_playback' => 0,
    'repeat_playback' => 0,
    'primary_player' => 'html5',

    /* Playlist */
    'playlist_position' => 'none',
    'playlist_size' => 270,
    'playlist_layout' => 'extended',

    /* Sharing */
    'enable_share' => 1,
    'share_heading' => 'Share This Video',
    'share_url' => '[f:bool:{node:field_share_url}:{node:field_share_url}:{node:url:absolute}]?cmpid=longtailshare',
    'embed_code' => '[node:iframe-embed-markup]',

    /* Analytics */
    'enable_jwplayer_analytics' => 1,
    'google_analytics_object' => '_gaq',
    'google_analytics_title' => 'title',
    'site_catalyst_media_name' => '[node:title]',
    'site_catalyst_player_name' => NULL,

    /* Advertising */
    'ad_frequency' => 1,
    'ad_client' => 'googima',
    'ad_tag' => 'http://pubads.g.doubleclick.net/gampad/ads?sz=640x360&iu=/4355895/TP3_Video_640x360&ciu_szs&impl=s&gdfp_req=1&ev=vp&output=xml_vast2&unviewed_position_start=1&url=[referrer_url]&correlator=[timestamp]',
    'ad_message' => 'Your video will play after this brief advertisement',
  ));
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

function tp_video_player_load_entity_configuration($entity_type, $entity_id) {
  $query = db_select('tp_video_player_configuration', 'c')
    ->fields('c');
  $query->join('tp_video_player_entity_configuration', 'e', 'e.configuration_id = c.id');
  $object = $query->condition('e.entity_type', $entity_type, '=')
    ->condition('e.entity_id', $entity_id, '=')
    ->range(0, 1)
    ->execute()
    ->fetchObject();
  // Use NULL for not found instead of FALSE.
  return $object !== FALSE ? $object : NULL;
}

function tp_video_player_attach_entity_configuration($entity_type, $entity_id, $configuration) {
  $fields = array(
    'configuration_id' => $configuration->id,
    'entity_type' => $entity_type,
    'entity_id' => $entity_id,
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
  db_delete('tp_video_player_configuration')
    ->condition('id', $ids, 'IN')
    ->execute();
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

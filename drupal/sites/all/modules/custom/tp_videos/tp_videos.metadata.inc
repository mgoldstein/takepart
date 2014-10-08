<?php
/**
 * @file
 * TakePart custom video metadata object.
 */

function tp_videos_create_metadata($values = array()) {
  $object = new StdClass();
  $values += array(

    /* Keys */
    'fid' => NULL,

    /* Metadata */
    'width' => NULL,
    'height' => NULL,
    'length' => NULL,
    'thumbnail_image' => NULL,
    'embed_code' => NULL,

    /* Timestamps */
    'created_at' => NULL,
    'updated_at' => NULL,
  );
  foreach ($values as $name => $value) {
    $object->{$name} = $value;
  }
  return $object;
}

function tp_videos_load_metadata($fid) {
  $object = db_select('tp_videos_metadata', 'm')
    ->fields('m')
    ->condition('m.fid', $fid, '=')
    ->range(0, 1)
    ->execute()
    ->fetchObject();
  // Use NULL for not found instead of FALSE.
  return $object !== FALSE ? $object : NULL;
}

function tp_videos_load_multiple_metadata($fids) {
  $records = db_select('tp_videos_metadata', 'm')
    ->fields('m')
    ->condition('m.fid', $fids, 'IN')
    ->execute()
    ->fetchAllAssoc('fid');
  $values = array();
  foreach ($records as $fid => $record) {
    $values[$fid] = tp_videos_create_metadata((array) $record);
  }
  return $values;
}

function tp_videos_delete_metadata($fid) {
  db_delete('tp_videos_metadata')
    ->condition('fid', $fid, '=')
    ->execute();
}

function tp_videos_save_metadata($metadata) {
  db_merge('tp_videos_metadata')
    ->key(array('fid' => $metadata->fid))
    ->insertFields(array(
      'fid' => $metadata->fid,
      'width' => $metadata->width,
      'height' => $metadata->height,
      'length' => $metadata->length,
      'thumbnail_image' => $metadata->thumbnail_image,
      'embed_code' => $metadata->embed_code,
      'created_at' => REQUEST_TIME,
      'updated_at' => REQUEST_TIME,
    ))
    ->updateFields(array(
      'fid' => $metadata->fid,
      'width' => $metadata->width,
      'height' => $metadata->height,
      'length' => $metadata->length,
      'thumbnail_image' => $metadata->thumbnail_image,
      'embed_code' => $metadata->embed_code,
      'updated_at' => REQUEST_TIME,
    ))
    ->execute();
}

/**
 * Parse a media stream wapper URI
 */
function tp_videos_parse_wrapper_uri($uri) {
  $path = explode('://', $uri);
  $parts = explode('/', $path[1]);
  $params = array();
  $count = 0;
  $total = count($parts);
  if (!$total || ($total % 2)) {
    // If we have no parts, or an odd number of parts, it's malformed.
    return FALSE;
  }
  while ($count < $total) {
    // We iterate count for each step of the assignment to keep us honest.
    $params[$parts[$count++]] = $parts[$count++];
  }
  return $params;
}

function tp_videos_fetch_youtube_video_length($token) {

  $url = "http://gdata.youtube.com/feeds/api/videos/{$token}";
  $response = drupal_http_request($url);
  if ($response->code == 200) {

    $dom = new SimpleXMLElement($response->data);
    $dom->registerXPathNamespace('media', 'http://search.yahoo.com/mrss/');
    $dom->registerXPathNamespace('yt', 'http://gdata.youtube.com/schemas/2007');

    $elements = $dom->xpath('//media:group/yt:duration[@seconds]');
    if ($elements !== FALSE) {
      $element = reset($elements);
      return intval($element['seconds'] . '');
    }
  }
  return 0;
}

function tp_videos_fetch_youtube_metadata($file) {

  $params = tp_videos_parse_wrapper_uri($file->uri);
  $token = $params['v'];

  $video_url = rawurlencode("http://www.youtube.com/watch?v={$token}");
  $oembed_url = "http://www.youtube.com/oembed?url={$video_url}&format=json";
  $response = drupal_http_request($oembed_url);
  if ($response->code == 200) {

    $data = json_decode($response->data, TRUE);
    $length = tp_videos_fetch_youtube_video_length($token);

    return tp_videos_create_metadata(array(
      'fid' => $file->fid,
      'width' => intval($data['width']),
      'height' => intval($data['height']),
      'length' => $length,
      'thumbnail_image' => $data['thumbnail_url'],
      'embed_code' => $data['html'],
    ));
  }
  return NULL;
}

function tp_videos_fetch_vimeo_metadata($file) {

  $params = tp_videos_parse_wrapper_uri($file->uri);
  $token = $params['v'];

  $video_url = rawurlencode("http://vimeo.com/{$token}");
  $oembed_url = "http://vimeo.com/api/oembed.json?url={$video_url}";
  $response = drupal_http_request($oembed_url);
  if ($response->code == 200) {

    $data = json_decode($response->data, TRUE);

    return tp_videos_create_metadata(array(
      'fid' => $file->fid,
      'width' => intval($data['width']),
      'height' => intval($data['height']),
      'length' => intval($data['duration']),
      'thumbnail_image' => $data['thumbnail_url'],
      'embed_code' => $data['html'],
    ));
  }
  return NULL;
}

function tp_videos_fetch_jwplatform_video_data($token) {
  $api = pm_jwplatform_get_api();
  $response = $api->call('/videos/show', array('video_key' => $token));
  if ($response['status'] === 'ok' && isset($response['video'])) {
    return $response['video'];
  }
  return NULL;
}

function tp_videos_fetch_jwplatform_channel_data($token) {
  $api = pm_jwplatform_get_api();
  $response = $api->call('/channels/show', array('channel_key' => $token));
  if ($response['status'] === 'ok' && isset($response['channel'])) {
    return tp_videos_fetch_jwplatform_first_video_in_channel_data($token);
  }
  return NULL;
}

function tp_videos_fetch_jwplatform_first_video_in_channel_data($token) {
  $api = pm_jwplatform_get_api();
  $response = $api->call('/channels/videos/list', array(
    'channel_key' => $token,
    'result_limit' => 1,
  ));
  if ($response['status'] === 'ok' && count($response['videos']) > 0) {
    $video = reset($response['videos']);
    return tp_videos_fetch_jwplatform_video_data($video['key']);
  }
  return NULL;
}

function tp_videos_fetch_jwplatform_video_original_conversion_data($token) {
  $api = pm_jwplatform_get_api();
  $response = $api->call('/videos/conversions/list', array('video_key' => $token));
  if ($response['status'] === 'ok' && isset($response['conversions'])) {
    $conversions = $response['conversions'];
    foreach ($conversions as $conversion) {
      if (isset($conversion['template']['format']['key'])
        && $conversion['template']['format']['key'] === 'original') {
        return $conversion;
      }
    }
  }
  return NULL;
}

function tp_videos_fetch_jwplatform_video_dimensions($token) {
  $width = 0;
  $height = 0;
  $original = tp_videos_fetch_jwplatform_video_original_conversion_data($token);
  if (!is_null($original)) {
    $width = intval($original['width']);
    $height = intval($original['height']);
  }
  return array($width, $height);
}

function tp_videos_fetch_jwplatform_metadata($file) {

  $params = tp_videos_parse_wrapper_uri($file->uri);
  $token = $params['key'];

  $scheme = file_uri_scheme($file->uri);
  if ($scheme === 'jwplatform-video') {
    $data = tp_videos_fetch_jwplatform_video_data($token);
  }
  else {
    $data = tp_videos_fetch_jwplatform_channel_data($token);
  }

  if (!is_null($data)) {

    list($width, $height) = tp_videos_fetch_jwplatform_video_dimensions($data['key']);

    $js_src = '//content.jwplatform.com/players/' . $token . '.js';
    $embed_code = '<script type="text/javascript" src="' . $js_src . '"></script>';

    $thumb_src = '//content.jwplatform.com/thumbs/' . $data['key'] . '-720.jpg';

    return tp_videos_create_metadata(array(
      'fid' => $file->fid,
      'width' => $width,
      'height' => $height,
      'length' => intval($data['duration']),
      'thumbnail_image' => $thumb_src,
      'embed_code' => $embed_code,
    ));
  }

  return NULL;
}

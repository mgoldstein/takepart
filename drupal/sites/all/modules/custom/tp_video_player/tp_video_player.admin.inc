<?php
/**
 * @file
 * TakePart custom video player admin.
 */

function tp_video_player_defaults_page($usage) {
  $configuration = tp_video_player_load_configuration_by_name($usage);
  if (empty($configuration)) {
    $configuration = tp_video_player_create_default_configuration($usage);
  }
  return drupal_get_form('tp_video_player_global_defaults_form', $configuration);
}

function tp_video_player_create_default_configuration($name = NULL) {

  $configuration = new StdClass();

  $configuration->name = $name;
  $configuration->created_at = REQUEST_TIME;
  $configuration->updated_at = REQUEST_TIME;

  /* Promo */
  $configuration->show_promo_title = TRUE;
  $configuration->promo_image = NULL;
  $configuration->promo_title = NULL;

  /* Layout */
  $configuration->show_controls = TRUE;
  $configuration->responsive = TRUE;
  $configuration->width = 16;
  $configuration->height = 9;
  $configuration->skin = 'glow';
  $configuration->stretching = 'uniform';

  /* Playback */
  $configuration->auto_start = FALSE;
  $configuration->fallback = FALSE;
  $configuration->mute_playback = FALSE;
  $configuration->repeat_playback = FALSE;
  $configuration->primary_player = 'html5';

  /* Playlist */
  $configuration->playlist_position = 'none';
  $configuration->playlist_size = 180;
  $configuration->playlist_layout = 'extended';

  /* Sharing */
  $configuration->enable_share = TRUE;
  $configuration->share_heading = NULL;
  $configuration->share_url = NULL;
  $configuration->embed_code = NULL;

  /* Analytics */
  $configuration->enable_jwplayer_analytics = TRUE;
  $configuration->google_analytics_object = '_gaq';
  $configuration->google_analytics_title = 'title';
  $configuration->site_catalyst_media_name = NULL;
  $configuration->site_catalyst_player_name = NULL;

  /* Advertising */
  $configuration->ad_frequency = 1;
  $configuration->ad_client = 'vast';
  $configuration->ad_tag = NULL;
  $configuration->ad_message = NULL;

  return $configuration;
}

function tp_video_player_global_defaults_form($form, &$form_state, $configuration) {

  $form['promo'] = tp_video_player_promo_defaults_fields($configuration);
  $form['layout'] = tp_video_player_layout_default_fields($configuration);
  $form['playback'] = tp_video_player_playback_default_fields($configuration);
  $form['playlist'] = tp_video_player_playlist_default_fields($configuration);
  $form['sharing'] = tp_video_player_sharing_default_fields($configuration);
  $form['analytics'] = tp_video_player_analytics_default_fields($configuration);
  $form['advertising'] = tp_video_player_advertising_default_fields($configuration);

  $form['actions'] = array(
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Save Defaults'),
    ),
  );

  $form_state['tp_video_player_configuration'] = $configuration;

  return $form;
}

function tp_video_player_global_defaults_form_submit($form, $form_state) {

  $values = $form_state['values'];

  $configuration = $form_state['tp_video_player_configuration'];

  $boolean_fields = array(
    'show_promo_title',
    'show_controls',
    'responsive',
    'auto_start',
    'fallback',
    'mute_playback',
    'repeat_playback',
    'enable_share',
    'enable_jwplayer_analytics',
  );
  foreach ($boolean_fields as $name) {
    $configuration->{$name} = !empty($values[$name]) ? 1 : 0;
  }

  $scalar_fields = array(
    'promo_image',
    'promo_title',
    'width',
    'height',
    'skin',
    'stretching',
    'primary_player',
    'playlist_position',
    'playlist_size',
    'playlist_layout',
    'share_heading',
    'share_url',
    'embed_code',
    'google_analytics_object',
    'google_analytics_title',
    'site_catalyst_media_name',
    'site_catalyst_player_name',
    'ad_frequency',
    'ad_client',
    'ad_tag',
    'ad_message',
  );
  foreach ($scalar_fields as $name) {
    $configuration->{$name} = empty($values[$name]) ? NULL : $values[$name];
  }

  if (isset($configuration->id)) {
    tp_video_player_update_configuration($configuration);
  }
  else {
    tp_video_player_insert_configuration($configuration);
  }

  drupal_set_message('Defaults saved.');
}

function tp_video_player_promo_defaults_fields($configuration) {

  $fields = array(
    '#type' => 'fieldset',
    '#title' => t('Promo'),
    '#collapsible' => TRUE,
    '#tree' => FALSE,
  );

  $fields['show_promo_title'] = array(
    '#type' => 'checkbox',
    '#title' => 'Show Title',
    '#description' => t('Display the title of the video file inside the play icon in the middle of the display'),
    '#default_value' => $configuration->show_promo_title,
  );

  $fields['promo_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => $configuration->promo_title,
  );

  $fields['promo_image'] = array(
    '#type' => 'textfield',
    '#title' => t('Image'),
    '#description' => t('URL to a poster image to display before playback starts'),
    '#default_value' => $configuration->promo_image,
  );

  return $fields;
}

function tp_video_player_layout_default_fields($configuration) {

  $fields = array(
    '#type' => 'fieldset',
    '#title' => t('Layout'),
    '#collapsible' => TRUE,
    '#tree' => FALSE,
  );

  $fields['show_controls'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Controls'),
    '#description' => t('Display the video controls (controlbar, display icons and dock buttons)'),
    '#default_value' => $configuration->show_controls,
  );

  $fields['responsive'] = array(
    '#type' => 'checkbox',
    '#title' => t('Responsive'),
    '#description' => t('Setup JW Player for responsive design'),
    '#default_value' => $configuration->responsive,
  );

  $fields['width'] = array(
    '#type' => 'textfield',
    '#title' => t('Width'),
    '#description' => t('Width of the player for non-responsive players, width component of the aspect ratio for responsive players'),
    '#default_value' => $configuration->width,
    '#required' => TRUE,
    '#element_validate' => array('element_validate_integer_positive')
  );

  $fields['height'] = array(
    '#type' => 'textfield',
    '#title' => t('Height'),
    '#description' => t('Height of the player for non-responsive players, height component of the aspect ratio for responsive players'),
    '#default_value' => $configuration->height,
    '#required' => TRUE,
    '#element_validate' => array('element_validate_integer_positive')
  );

  $fields['skin'] = array(
    '#type' => 'select',
    '#title' => t('Skin'),
    '#description' => t('Which skin to use for styling the player'),
    '#options' => array(
      'beelden' => t('Beelden'),
      'bekle' => t('Bekle'),
      'five' => t('Five'),
      'glow' => t('Glow'),
      'roundster' => t('Roundster'),
      'six' => t('Six'),
      'stormtrooper' => t('Stormtrooper'),
      'vapor' => t('Vapor'),
    ),
    '#required' => TRUE,
    '#default_value' => $configuration->skin,
  );

  $fields['stretching'] = array(
    '#type' => 'select',
    '#title' => t('Strecthing'),
    '#description' => t('How to resize images and video to fit the display'),
    '#options' => array(
      'uniform' => t('Uniform'),
      'exactfit' => t('Exact Fit'),
      'fill' => t('Fill'),
      'none' => t('None'),
    ),
    '#required' => TRUE,
    '#default_value' => $configuration->stretching,
  );

  return $fields;
}

function tp_video_player_playback_default_fields($configuration) {

  $fields = array(
    '#type' => 'fieldset',
    '#title' => t('Playback'),
    '#collapsible' => TRUE,
    '#tree' => FALSE,
  );

  $fields['auto_start'] = array(
    '#type' => 'checkbox',
    '#title' => t('Auto start'),
    '#description' => t('Automatically start playing the video on page load. <em>Autostart does not work on mobile devices</em>'),
    '#default_value' => $configuration->auto_start,
  );

  $fields['fallback'] = array(
    '#type' => 'checkbox',
    '#title' => t('Fallback'),
    '#description' => t('Render a nice download link to the video if HTML5/Flash are not supported'),
    '#default_value' => $configuration->fallback,
  );

  $fields['mute_playback'] = array(
    '#type' => 'checkbox',
    '#title' => t('Mute playback'),
    '#description' => t('Whether to have the sound muted on startup or not. <em>Mute does not work on mobile devices</em>'),
    '#default_value' => $configuration->mute_playback,
  );

  $fields['repeat_playback'] = array(
    '#type' => 'checkbox',
    '#title' => t('Repeat'),
    '#description' => t('Whether to loop playback of the playlist or not'),
    '#default_value' => $configuration->repeat_playback,
  );

  $fields['primary_player'] = array(
    '#type' => 'select',
    '#title' => t('Primary Player'),
    '#description' => t('Which rendering mode to use for rendering the player if both are available'),
    '#options' => array(
      'html5' => t('HTML5'),
      'flash' => t('Flash'),
    ),
    '#required' => TRUE,
    '#default_value' => $configuration->primary_player,
  );

  return $fields;
}

function tp_video_player_playlist_default_fields($configuration) {

  $fields = array(
    '#type' => 'fieldset',
    '#title' => t('JWPlayer Playlist'),
    '#collapsible' => TRUE,
    '#tree' => FALSE,
  );

  $fields['playlist_position'] = array(
    '#type' => 'select',
    '#title' => t('Position'),
    '#description' => t('Position of the listbar relative to the video display'),
    '#options' => array(
      'bottom' => t('Bottom'),
      'none' => t('None'),
      'right' => t('Right'),
    ),
    '#required' => TRUE,
    '#default_value' => $configuration->playlist_position,
  );

  $fields['playlist_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Size'),
    '#description' => t('Width (if position is right) or height (if position is bottom) of the listbar. This is basically the amount of pixels the bar "steals" from the video window.'),
    '#default_value' => $configuration->playlist_size,
    '#required' => TRUE,
    '#element_validate' => array('element_validate_integer_positive')
  );

  $fields['playlist_layout'] = array(
    '#type' => 'select',
    '#title' => t('Layout'),
    '#description' => t('Layout of the playlist items in the listbar. Can be basic (only title) or extended (image, title and description)'),
    '#options' => array(
      'basic' => t('Basic'),
      'extended' => t('Extended'),
    ),
    '#required' => TRUE,
    '#default_value' => $configuration->playlist_layout,
  );

  return $fields;
}

function tp_video_player_sharing_default_fields($configuration) {

  $fields = array(
    '#type' => 'fieldset',
    '#title' => t('Sharing'),
    '#collapsible' => TRUE,
    '#tree' => FALSE,
  );

  $fields['enable_share'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enabled'),
    '#description' => t('Whether to allow social sharing through the video player or not.'),
    '#default_value' => $configuration->enable_share,
  );

  $fields['share_heading'] = array(
    '#type' => 'textfield',
    '#title' => t('Share Heading'),
    '#description' => t('Short, instructive text to display at the top of the sharing screen.'),
    '#default_value' => $configuration->share_heading,
  );

  $fields['share_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Share URL'),
    '#description' => t('URL to display in the video link field.'),
    '#default_value' => $configuration->share_url,
  );

  $fields['embed_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Embed Code'),
    '#description' => t('Embed code to display in the embed code field. If no code is set, the field is not shown'),
    '#default_value' => $configuration->embed_code,
  );

  return $fields;
}

function tp_video_player_analytics_default_fields($configuration) {

  $fields = array(
    '#type' => 'fieldset',
    '#title' => t('Analytics'),
    '#collapsible' => TRUE,
    '#tree' => FALSE,
  );

  $fields['enable_jwplayer_analytics'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable JWPlayer Analytics'),
    '#description' => t('Whether to enable JWPlayer analytics or not.'),
    '#default_value' => $configuration->enable_jwplayer_analytics,
  );

  $fields['google_analytics_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Analytics Title'),
    '#default_value' => $configuration->google_analytics_title,
  );

  $fields['google_analytics_object'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Analytics Object'),
    '#default_value' => $configuration->google_analytics_object,
  );

  $fields['site_catalyst_media_name'] = array(
    '#type' => 'textfield',
    '#title' => t('SiteCatalyst Media Name'),
    '#default_value' => $configuration->site_catalyst_media_name,
  );

  $fields['site_catalyst_player_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Site Catalyst Player Name'),
    '#default_value' => $configuration->site_catalyst_player_name,
  );

  return $fields;
}

function tp_video_player_advertising_default_fields($configuration) {

  $fields = array(
    '#type' => 'fieldset',
    '#title' => t('Advertising'),
    '#collapsible' => TRUE,
    '#tree' => FALSE,
  );

  $fields['ad_client'] = array(
    '#type' => 'select',
    '#title' => t('Client'),
    '#description' => t('Which advertising system you are using.'),
    '#options' => array(
      'none' => t('None'),
      'googima' => t('IMA'),
      'vast' => t('VAST'),
    ),
    '#default_value' => $configuration->ad_client,
  );

  $fields['ad_frequency'] = array(
    '#type' => 'select',
    '#title' => t('Frequency'),
    '#description' => t('Frequency at which ads should be played when playing through a playlist.'),
    '#options' => array(
      1 => '1',
      2 => '2',
      3 => '3',
      4 => '4',
      5 => '5',
      6 => '6',
      7 => '7',
      8 => '8',
      9 => '9',
      10 => '10',
    ),
    '#default_value' => $configuration->ad_frequency,
  );

  $fields['ad_tag'] = array(
    '#type' => 'textfield',
    '#title' => t('Tag'),
    '#description' => t('URL of the VAST or IMA ad tag to play.'),
    '#default_value' => $configuration->ad_tag,
  );

  $fields['ad_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Message'),
    '#description' => t('Message to show during linear ad playback. <em>The value <strong>XX</strong> will be replaced with the number of seconds remaining for the ad.</em>'),
    '#default_value' => $configuration->ad_message,
  );

  return $fields;
}

<?php
/**
 * @file
 * TakePart custom video player global defaults admin.
 */

function tp_video_player_defaults_page($name) {
  $configuration = tp_video_player_load_default_configuration($name);
  if (is_null($configuration)) {
    $configuration = tp_video_player_create_default_configuration($name);
  }
  return drupal_get_form('tp_video_player_defaults_form', $configuration);
}

function tp_video_player_form_promo_fields($values, $is_default = FALSE) {

  $fields = array();

  $fields['show_promo_title'] = array(
    '#type' => 'checkbox',
    '#title' => 'Show Title',
    '#description' => t('Display the title of the video file inside the play icon in the middle of the display'),
    '#default_value' => $values['show_promo_title'],
    '#access' => $is_default,
  );

  $fields['promo_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => $values['promo_title'],
    '#access' => $is_default,
  );

  $fields['promo_image'] = array(
    '#type' => 'textfield',
    '#title' => t('Image'),
    '#description' => t('URL to a poster image to display before playback starts'),
    '#default_value' => $values['promo_image'],
    '#access' => $is_default,
  );

  return $fields;
}

function tp_video_player_form_layout_fields($values, $is_default = FALSE) {

  $fields = array();

  $fields['show_controls'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Controls'),
    '#description' => t('Display the video controls (controlbar, display icons and dock buttons)'),
    '#default_value' => $values['show_controls'],
    '#access' => $is_default,
  );

  $fields['responsive'] = array(
    '#type' => 'checkbox',
    '#title' => t('Responsive'),
    '#description' => t('Setup JW Player for responsive design'),
    '#default_value' => $values['responsive'],
  );

  $fields['width'] = array(
    '#type' => 'textfield',
    '#title' => t('Width'),
    '#description' => t('Width of the player for non-responsive players, width component of the aspect ratio for responsive players'),
    '#default_value' => $values['width'],
    '#required' => TRUE,
    '#element_validate' => array('element_validate_integer_positive')
  );

  $fields['height'] = array(
    '#type' => 'textfield',
    '#title' => t('Height'),
    '#description' => t('Height of the player for non-responsive players, height component of the aspect ratio for responsive players'),
    '#default_value' => $values['height'],
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
    '#default_value' => $values['skin'],
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
    '#default_value' => $values['stretching'],
    '#access' => $is_default,
  );

  return $fields;
}

function tp_video_player_form_playback_fields($values, $is_default = FALSE) {

  $fields = array();

  $fields['auto_start'] = array(
    '#type' => 'checkbox',
    '#title' => t('Auto start'),
    '#description' => t('Automatically start playing the video on page load. <em>Autostart does not work on mobile devices</em>'),
    '#default_value' => $values['auto_start'],
  );

  $fields['fallback'] = array(
    '#type' => 'checkbox',
    '#title' => t('Fallback'),
    '#description' => t('Render a nice download link to the video if HTML5/Flash are not supported'),
    '#default_value' => $values['fallback'],
    '#access' => $is_default,
  );

  $fields['mute_playback'] = array(
    '#type' => 'checkbox',
    '#title' => t('Mute playback'),
    '#description' => t('Whether to have the sound muted on startup or not. <em>Mute does not work on mobile devices</em>'),
    '#default_value' => $values['mute_playback'],
  );

  $fields['repeat_playback'] = array(
    '#type' => 'checkbox',
    '#title' => t('Repeat'),
    '#description' => t('Whether to loop playback of the playlist or not'),
    '#default_value' => $values['repeat_playback'],
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
    '#default_value' => $values['primary_player'],
    '#access' => $is_default,
  );

  return $fields;
}

function tp_video_player_form_playlist_fields($values, $is_default = FALSE) {

  $fields = array();

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
    '#default_value' => $values['playlist_position'],
    '#access' => $is_default,
  );

  $fields['playlist_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Size'),
    '#description' => t('Width (if position is right) or height (if position is bottom) of the listbar. This is basically the amount of pixels the bar "steals" from the video window.'),
    '#default_value' => $values['playlist_size'],
    '#required' => TRUE,
    '#element_validate' => array('element_validate_integer_positive'),
    '#access' => $is_default,
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
    '#default_value' => $values['playlist_layout'],
    '#access' => $is_default,
  );

  return $fields;
}

function tp_video_player_form_sharing_fields($values, $is_default = FALSE) {

  $fields = array();

  $fields['enable_share'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enabled'),
    '#description' => t('Whether to allow social sharing through the video player or not.'),
    '#default_value' => $values['enable_share'],
  );

  $fields['share_heading'] = array(
    '#type' => 'textfield',
    '#title' => t('Share Heading'),
    '#description' => t('Short, instructive text to display at the top of the sharing screen.'),
    '#default_value' => $values['share_heading'],
  );

  $fields['share_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Share URL'),
    '#description' => t('URL to display in the video link field.'),
    '#default_value' => $values['share_url'],
  );

  $fields['embed_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Embed Code'),
    '#description' => t('Embed code to display in the embed code field. If no code is set, the field is not shown'),
    '#default_value' => $values['embed_code'],
  );

  return $fields;
}

function tp_video_player_form_analytics_fields($values, $is_default = FALSE) {

  $fields = array();

  $fields['enable_jwplayer_analytics'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable JWPlayer Analytics'),
    '#description' => t('Whether to enable JWPlayer analytics or not.'),
    '#default_value' => $values['enable_jwplayer_analytics'],
    '#access' => $is_default,
  );

  $fields['google_analytics_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Analytics Title'),
    '#default_value' => $values['google_analytics_title'],
    '#access' => $is_default,
  );

  $fields['google_analytics_object'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Analytics Object'),
    '#default_value' => $values['google_analytics_object'],
    '#access' => $is_default,
  );

  $fields['site_catalyst_media_name'] = array(
    '#type' => 'textfield',
    '#title' => t('SiteCatalyst Media Name'),
    '#default_value' => $values['site_catalyst_media_name'],
    '#access' => $is_default,
  );

  $fields['site_catalyst_player_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Site Catalyst Player Name'),
    '#default_value' => $values['site_catalyst_player_name'],
    '#access' => $is_default,
  );

  return $fields;
}

function tp_video_player_form_advertising_fields($values, $is_default = FALSE) {

  $fields = array();

  $fields['ad_client'] = array(
    '#type' => 'select',
    '#title' => t('Client'),
    '#description' => t('Which advertising system you are using.'),
    '#options' => array(
      'none' => t('None'),
      'googima' => t('IMA'),
      'vast' => t('VAST'),
    ),
    '#default_value' => $values['ad_client'],
    '#access' => $is_default,
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
    '#default_value' => $values['ad_frequency'],
  );

  $fields['ad_tag'] = array(
    '#type' => 'textfield',
    '#title' => t('Tag'),
    '#description' => t('URL of the VAST or IMA ad tag to play.'),
    '#default_value' => $configuration->ad_tag,
    '#maxlength' => 255,
  );

  $fields['ad_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Message'),
    '#description' => t('Message to show during linear ad playback. <em>The value <strong>XX</strong> will be replaced with the number of seconds remaining for the ad.</em>'),
    '#default_value' => $values['ad_message'],
  );

  return $fields;
}

function tp_video_player_defaults_form($form, &$form_state, $configuration) {

  $form_state['storage']['tp_video_player_configuration'] = $configuration;

  $is_default = isset($configuration->name);

  $values = (array) $configuration;

  $form['promo'] = array(
    '#type' => 'fieldset',
    '#title' => t('Promo'),
    '#collapsible' => TRUE,
    '#access' => $is_default,
  ) + tp_video_player_form_promo_fields($values, $is_default);

  $form['layout'] = array(
    '#type' => 'fieldset',
    '#title' => t('Layout'),
    '#collapsible' => TRUE,
  ) + tp_video_player_form_layout_fields($values, $is_default);

  $form['playback'] = array(
    '#type' => 'fieldset',
    '#title' => t('Playback'),
    '#collapsible' => TRUE,
  ) + tp_video_player_form_playback_fields($values, $is_default);

  $form['playlist'] = array(
    '#type' => 'fieldset',
    '#title' => t('Playlist'),
    '#collapsible' => TRUE,
    '#access' => $is_default,
  ) + tp_video_player_form_playlist_fields($values, $is_default);

  $form['sharing'] = array(
    '#type' => 'fieldset',
    '#title' => t('Sharing'),
    '#collapsible' => TRUE,
  ) + tp_video_player_form_sharing_fields($values, $is_default);

  $form['analytics'] = array(
    '#type' => 'fieldset',
    '#title' => t('Analytics'),
    '#collapsible' => TRUE,
    '#access' => $is_default,
  ) + tp_video_player_form_analytics_fields($values, $is_default);

  $form['advertising'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advertising'),
    '#collapsible' => TRUE,
  ) + tp_video_player_form_advertising_fields($values, $is_default);

  $form['actions'] = array(
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Save defaults'),
    ),
    '#access' => $is_default,
  );

  return $form;
}

function tp_video_player_defaults_form_submit($form, $form_state) {

  $configuration = $form_state['storage']['tp_video_player_configuration'];

  $values = $form_state['values'];

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

  tp_video_player_save_configuration($configuration);

  drupal_set_message('Defaults saved.');
}

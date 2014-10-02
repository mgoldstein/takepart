<?php
/**
 * @file
 * TakePart custom video player global defaults admin.
 */

function tp_video_player_defaults_page($name) {

  $configuration = tp_video_player_load_default_configuration($name);
  if (is_null($configuration)) {
    $configuration = tp_video_player_create_configuration(array('name' => $name));
  }

  $info = tp_video_player_defaults($name);
  return drupal_get_form('tp_video_player_configuration_form', $configuration, $info['type']);
}

function tp_video_player_form_promo_fields($values, $is_default = FALSE) {

  $fields = array();

  if ($is_default) {

    $fields['show_promo_title'] = array(
      '#type' => 'checkbox',
      '#title' => 'Show Title',
      '#description' => t('Display the title of the video file inside the play icon in the middle of the display'),
      '#default_value' => $values['show_promo_title'],
    );

    $fields['promo_title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#default_value' => $values['promo_title'],
    );

    $fields['promo_image'] = array(
      '#type' => 'textfield',
      '#title' => t('Image'),
      '#description' => t('URL to a poster image to display before playback starts'),
      '#default_value' => $values['promo_image'],
    );
  }
  else {

    $fields['show_promo_title'] = array(
      '#type' => 'value',
      '#value' => $values['show_promo_title'],
    );

    $fields['promo_title'] = array(
      '#type' => 'value',
      '#value' => $values['promo_title'],
    );

    $fields['promo_image'] = array(
      '#type' => 'value',
      '#value' => $values['promo_image'],
    );
  }

  return $fields;
}

function tp_video_player_form_layout_fields($values, $is_default = FALSE) {

  $fields = array();

  if ($is_default) {
    $fields['show_controls'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show Controls'),
      '#description' => t('Display the video controls (controlbar, display icons and dock buttons)'),
      '#default_value' => $values['show_controls'],
    );
  }
  else {
    $fields['show_controls'] = array(
      '#type' => 'value',
      '#value' => $values['show_controls'],
    );
  }

  //override for legacy videos
  if (empty($values['responsive']) && empty($values['width']) && empty($values['height'])) {
    $values['responsive'] = 1;
    $values['width'] = 16;
    $values['height'] = 9;
  }
  
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

  if ($is_default) {
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
    );
  }
  else {
    $fields['stretching'] = array(
      '#type' => 'value',
      '#value' => $values['stretching'],
    );
  }

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

  if ($is_default) {
    $fields['fallback'] = array(
      '#type' => 'checkbox',
      '#title' => t('Fallback'),
      '#description' => t('Render a nice download link to the video if HTML5/Flash are not supported'),
      '#default_value' => $values['fallback'],
    );
  }
  else {
    $fields['fallback'] = array(
      '#type' => 'value',
      '#value' => $values['fallback'],
    );
  }

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

  if ($is_default) {
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
    );
  }
  else {
    $fields['primary_player'] = array(
      '#type' => 'value',
      '#value' => $values['primary_player'],
    );
  }

  return $fields;
}

function tp_video_player_form_playlist_fields($values, $is_default = FALSE) {

  $fields = array();

  if ($is_default) {

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
    );

    $fields['playlist_size'] = array(
      '#type' => 'textfield',
      '#title' => t('Size'),
      '#description' => t('Width (if position is right) or height (if position is bottom) of the listbar. This is basically the amount of pixels the bar "steals" from the video window.'),
      '#default_value' => $values['playlist_size'],
      '#required' => TRUE,
      '#element_validate' => array('element_validate_integer_positive'),
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
    );
  }
  else {

    $fields['playlist_position'] = array(
      '#type' => 'value',
      '#value' => $values['playlist_position'],
    );

    $fields['playlist_size'] = array(
      '#type' => 'value',
      '#value' => $values['playlist_size'],
    );

    $fields['playlist_layout'] = array(
      '#type' => 'value',
      '#value' => $values['playlist_layout'],
    );
  }

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

  if ($is_default) {

    $fields['enable_jwplayer_analytics'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable JWPlayer Analytics'),
      '#description' => t('Whether to enable JWPlayer analytics or not.'),
      '#default_value' => $values['enable_jwplayer_analytics'],
    );

    $fields['google_analytics_title'] = array(
      '#type' => 'textfield',
      '#title' => t('Google Analytics Title'),
      '#default_value' => $values['google_analytics_title'],
    );

    $fields['google_analytics_object'] = array(
      '#type' => 'textfield',
      '#title' => t('Google Analytics Object'),
      '#default_value' => $values['google_analytics_object'],
    );

    $fields['site_catalyst_media_name'] = array(
      '#type' => 'textfield',
      '#title' => t('SiteCatalyst Media Name'),
      '#default_value' => $values['site_catalyst_media_name'],
    );

    $fields['site_catalyst_player_name'] = array(
      '#type' => 'textfield',
      '#title' => t('Site Catalyst Player Name'),
      '#default_value' => $values['site_catalyst_player_name'],
    );
  }
  else {

    $fields['enable_jwplayer_analytics'] = array(
      '#type' => 'value',
      '#value' => $values['enable_jwplayer_analytics'],
    );

    $fields['google_analytics_title'] = array(
      '#type' => 'value',
      '#value' => $values['google_analytics_title'],
    );

    $fields['google_analytics_object'] = array(
      '#type' => 'value',
      '#value' => $values['google_analytics_object'],
    );

    $fields['site_catalyst_media_name'] = array(
      '#type' => 'value',
      '#value' => $values['site_catalyst_media_name'],
    );

    $fields['site_catalyst_player_name'] = array(
      '#type' => 'value',
      '#value' => $values['site_catalyst_player_name'],
    );
  }

  return $fields;
}

function tp_video_player_form_playlist_advertising_fields($values, $is_default = FALSE) {

  $fields = array();

  if ($is_default) {
    $fields['ad_client'] = array(
      '#type' => 'select',
      '#title' => t('Client'),
      '#description' => t('Which advertising system you are using.'),
      '#options' => array(
        'googima' => t('IMA'),
        'vast' => t('VAST'),
      ),
      '#default_value' => $values['ad_client'],
      '#required' => TRUE,
      '#access' => $is_default,
    );
  }
  else {
    $fields['ad_client'] = array(
      '#type' => 'value',
      '#value' => $values['ad_client'],
    );
  }

  $fields['ad_schedule'] = array(
    '#type' => 'select',
    '#title' => t('Schedule'),
    '#description' => t('Which type of ad schedule to use.'),
    '#options' => array(
      TP_VIDEO_PLAYER_NO_SCHEDULE => t('No Ads'),
      TP_VIDEO_PLAYER_VIDEO_SCHEDULE => t('Videos play their own ads'),
      TP_VIDEO_PLAYER_PLAYLIST_SCHEDULE => t('Use playlist frequency'),
    ),
    '#default_value' => $values['ad_schedule'],
    '#required' => TRUE,
  );

  $fields['ad_frequency'] = array(
    '#type' => 'select',
    '#title' => t('Playlist Frequency'),
    '#description' => t('Frequency at which ads should be played when using the playlist ad schedule.'),
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
    '#required' => TRUE,
  );

  $ad_tags = array();
  foreach (takepart_ads_load_tag_list() as $name => $tag) {
    $ad_tags[$name] = $tag->title;
  }
  $default_ad_tag_title = t('Tag [!link]', array(
    '!link' => '<a href="/admin/config/system/ads/tags" target="_blank">Manage Tags Here</a>',
  ));
  $fields['ad_tag'] = array(
    '#type' => 'select',
    '#title' => $is_default ? $default_ad_tag_title : t('Tag'),
    '#description' => t('The ad tag to use'),
    '#options' => $ad_tags,
    '#default_value' => $values['ad_tag'],
  );

  $fields['ad_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Message'),
    '#description' => t('Message to show during linear ad playback. <em>The value <strong>XX</strong> will be replaced with the number of seconds remaining for the ad.</em>'),
    '#default_value' => $values['ad_message'],
  );

  return $fields;
}

function tp_video_player_form_video_advertising_fields($values, $is_default = FALSE) {

  $fields = array();

  if ($is_default) {
    $fields['ad_client'] = array(
      '#type' => 'select',
      '#title' => t('Client'),
      '#description' => t('Which advertising system you are using.'),
      '#options' => array(
        'googima' => t('IMA'),
        'vast' => t('VAST'),
      ),
      '#default_value' => $values['ad_client'],
      '#required' => TRUE,
    );
  }
  else {
    $fields['ad_client'] = array(
      '#type' => 'value',
      '#value' => $values['ad_client'],
    );
  }

  $fields['ad_schedule'] = array(
    '#type' => 'value',
    '#value' => TP_VIDEO_PLAYER_VIDEO_SCHEDULE,
  );

  $fields['ad_frequency'] = array(
    '#type' => 'value',
    '#value' => 1,
  );

  $ad_tags = array('' => t('No Ads'));
  foreach (takepart_ads_load_tag_list() as $name => $tag) {
    $ad_tags[$name] = $tag->title;
  }
  $default_ad_tag_title = t('Tag [!link]', array(
    '!link' => '<a href="/admin/config/system/ads/tags" target="_blank">Manage Tags Here</a>',
  ));
  $fields['ad_tag'] = array(
    '#type' => 'select',
    '#title' => $is_default ? $default_ad_tag_title : t('Tag'),
    '#description' => t('The ad tag to use'),
    '#options' => $ad_tags,
    '#default_value' => $values['ad_tag'],
  );

  $fields['ad_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Message'),
    '#description' => t('Message to show during linear ad playback. <em>The value <strong>XX</strong> will be replaced with the number of seconds remaining for the ad.</em>'),
    '#default_value' => $values['ad_message'],
  );

  return $fields;
}

function tp_video_player_configuration_form($form, &$form_state, $configuration, $type) {

  $form_state['storage']['tp_video_player_configuration'] = $configuration;

  $form['#tree'] = TRUE;

  $is_default = isset($configuration->name);

  $values = (array) $configuration;

  $form['promo'] = tp_video_player_form_promo_fields($values, $is_default);
  if ($is_default) {
    $form['promo'] += array(
      '#type' => 'fieldset',
      '#title' => t('Promo'),
      '#collapsible' => TRUE,
    );
  }

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


  $form['playlist'] = tp_video_player_form_playlist_fields($values, $is_default);
  if ($is_default) {
    $form['playlist'] += array(
      '#type' => 'fieldset',
      '#title' => t('Playlist'),
      '#collapsible' => TRUE,
    );
  }

  $form['sharing'] = array(
    '#type' => 'fieldset',
    '#title' => t('Sharing'),
    '#collapsible' => TRUE,
  ) + tp_video_player_form_sharing_fields($values, $is_default);


  $form['analytics'] = tp_video_player_form_analytics_fields($values, $is_default);
  if ($is_default) {
    $form['analytics'] += array(
      '#type' => 'fieldset',
      '#title' => t('Analytics'),
      '#collapsible' => TRUE,
    );
  }

  if ($type === 'playlist') {
    $form['advertising'] = array(
      '#type' => 'fieldset',
      '#title' => t('Advertising'),
      '#collapsible' => TRUE,
    ) + tp_video_player_form_playlist_advertising_fields($values, $is_default);
  }
  else {
    $form['advertising'] = array(
      '#type' => 'fieldset',
      '#title' => t('Advertising'),
      '#collapsible' => TRUE,
    ) + tp_video_player_form_video_advertising_fields($values, $is_default);
  }

  if ($is_default) {
    $form['actions'] = array(
      'submit' => array(
        '#type' => 'submit',
        '#value' => t('Save defaults'),
      ),
    );
  }

  return $form;
}

function tp_video_player_configuration_form_submit($form, $form_state) {

  $configuration = $form_state['storage']['tp_video_player_configuration'];
  tp_video_player_update_configuration($configuration, $form_state['values']);
  tp_video_player_save_configuration($configuration);

  drupal_set_message('Defaults saved.');
}

/**
 * Updates an override configuration to have only those values that differ
 * from the defaults.
 */
function tp_video_player_update_configuration($configuration, $values) {

  $boolean_fields = array(
    'promo' => array(
      'show_promo_title',
    ),
    'layout' => array(
      'show_controls',
      'responsive',
    ),
    'playback' => array(
      'auto_start',
      'fallback',
      'mute_playback',
      'repeat_playback',
    ),
    'sharing' => array(
      'enable_share',
    ),
    'analytics' => array(
      'enable_jwplayer_analytics',
    ),
  );
  foreach ($boolean_fields as $group => $fields) {
    foreach ($fields as $name) {
      $configuration->{$name} = !empty($values[$group][$name]) ? 1 : 0;
    }
  }

  $scalar_fields = array(
    'promo' => array(
      'promo_image',
      'promo_title',
    ),
    'layout' => array(
      'width',
      'height',
      'skin',
      'stretching',
    ),
    'playback' => array(
      'primary_player',
    ),
    'playlist' => array(
      'playlist_position',
      'playlist_size',
      'playlist_layout',
    ),
    'sharing' => array(
      'share_heading',
      'share_url',
      'embed_code',
    ),
    'analytics' => array(
      'google_analytics_object',
      'google_analytics_title',
      'site_catalyst_media_name',
      'site_catalyst_player_name',
    ),
    'advertising' => array(
      'ad_schedule',
      'ad_frequency',
      'ad_client',
      'ad_tag',
      'ad_message',
    ),
  );
  foreach ($scalar_fields as $group => $fields) {
    foreach ($fields as $name) {
      $configuration->{$name} = $values[$group][$name];
    }
  }
}

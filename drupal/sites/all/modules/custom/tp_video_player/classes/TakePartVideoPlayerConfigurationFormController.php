<?php

class TakePartVideoPlayerConfigurationFormController {

  protected $configuration;

  public function __construct($configuration) {
    $this->configuration = $configuration;
  }

  public static function instance($form_state) {
    return $form_state[get_class()];
  }

  public function form($form, &$form_state) {

    $form['promo'] = $this->wrapInFieldset(
      t('Promo'), self::promoFields($this->configuration));
    $form['layout'] = $this->wrapInFieldset(
      t('Layout'), self::layoutFields($this->configuration));
    $form['playback'] = $this->wrapInFieldset(
      t('Playback'), self::playbackFields($this->configuration));
    $form['playlist'] = $this->wrapInFieldset(
      t('Playlist'), self::playlistFields($this->configuration));
    $form['sharing'] = $this->wrapInFieldset(
      t('Sharing'), self::sharingFields($this->configuration));
    $form['analytics'] = $this->wrapInFieldset(
      t('Analytics'), self::analyticsFields($this->configuration));
    $form['advertising'] = $this->wrapInFieldset(
      t('Advertising'), self::advertisingFields($this->configuration));

    $form['actions'] = array(
      'submit' => array(
        '#type' => 'submit',
        '#value' => t('Save Defaults'),
      ),
    );

    $form_state[get_class()] = $this;

    return $form;
  }

  public function submit($form_state) {

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
      $this->configuration->{$name} = !empty($values[$name]) ? 1 : 0;
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
      $this->configuration->{$name} = empty($values[$name]) ? NULL : $values[$name];
    }

    return $this->configuration;
  }

  private function wrapInFieldset($title, $fields) {
    $fields += array(
      '#type' => 'fieldset',
      '#title' => $title,
      '#collapsible' => TRUE,
      '#tree' => FALSE,
    );
    return $fields;
  }

  protected static function promoFields($configuration) {

    $fields = array();

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

  protected static function layoutFields($configuration) {

    $fields = array();

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

  protected static function playbackFields($configuration) {

    $fields = array();

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

  protected static function playlistFields($configuration) {

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

  protected static function sharingFields($configuration) {

    $fields = array();

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

  protected static function analyticsFields($configuration) {

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

  protected static function advertisingFields($configuration) {

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
}

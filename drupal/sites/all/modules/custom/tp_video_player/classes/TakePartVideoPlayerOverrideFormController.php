<?php

class TakePartVideoPlayerOverrideFormController extends TakePartVideoPlayerConfigurationFormController {

  public function form($form, &$form_state) {

    $form = parent::form($form, $form_state);

    # Custom theme to render form in a table.
    $form['#theme'] = 'tp_video_player_override_form';

    # Remove the submit actions as the places where this form is used have their
    # own submit actions.
    unset($form['actions']);

    # Remove fields that are not yet overridable
    unset($form['promo']);
    unset($form['layout']['show_controls']);
    unset($form['layout']['stretching']);
    unset($form['playback']['fallback']);
    unset($form['playback']['primary_player']);
    unset($form['playlist']);
    unset($form['analytics']);
    unset($form['advertising']['ad_client']);

    // $form['promo'] = $this->addOverride('promo', $form['promo']);
    $form['layout'] = $this->addOverride('layout', $form['layout']);
    $form['playback'] = $this->addOverride('playback', $form['playback']);
    // $form['playlist'] = $this->addOverride('playlist', $form['playlist']);
    $form['sharing'] = $this->addOverride('sharing', $form['sharing']);
    // $form['analytics'] = $this->addOverride('analytics', $form['analytics']);
    $form['advertising'] = $this->addOverride('advertising', $form['advertising']);

    return $form;
  }

  private function addOverride($group, $overrides) {

    $overrides['#tree'] = TRUE;

    foreach (element_children($overrides) as $name) {

      $override_field = $overrides[$name];

      // Extract the title for display in the first column
      $override_title = array(
        '#type' => 'markup',
        '#markup' => $override_field['#title'],
      );
      unset($override_field['#title']);

      $overrides[$name] = array(
        "{$name}_title" => $override_title,
        $name => $override_field,
      );
    }

    return $overrides;
  }

  public function submit($form_state) {
    // The override form is not submitted directly.
    return NULL;
  }

  public function update($values, $defaults) {

    $boolean_fields = array(
      // 'promo' => array(
      //   'show_promo_title',
      // ),
      'layout' => array(
        // 'show_controls',
        'responsive',
      ),
      'playback' => array(
        'auto_start',
        // 'fallback',
        'mute_playback',
        'repeat_playback',
      ),
      'sharing' => array(
        'enable_share',
      ),
      // 'analytics' => array(
      //   'enable_jwplayer_analytics',
      // ),
    );
    foreach ($boolean_fields as $group => $fields) {
      foreach ($fields as $name) {
        if (empty($defaults->$name) == empty($values[$group][$name][$name])) {
          // Value matches the default, so it is not overridden.
          $this->configuration->{$name} = NULL;
        }
        else {
          // Value does not match the default, store the override.
          $this->configuration->{$name} = !empty($values[$group][$name][$name]) ? 1 : 0;
        }
      }
    }

    $scalar_fields = array(
      // 'promo' => array(
      //   'promo_image',
      //   'promo_title',
      // ),
      'layout' => array(
        'width',
        'height',
        'skin',
        // 'stretching',
      ),
      // 'playback' => array(
      //   'primary_player',
      // ),
      // 'playlist' => array(
      //   'playlist_position',
      //   'playlist_size',
      //   'playlist_layout',
      // ),
      'sharing' => array(
        'share_heading',
        'share_url',
        'embed_code',
      ),
      // 'analytics' => array(
      //   'google_analytics_object',
      //   'google_analytics_title',
      //   'site_catalyst_media_name',
      //   'site_catalyst_player_name',
      // ),
      'advertising' => array(
        'ad_frequency',
        // 'ad_client',
        'ad_tag',
        'ad_message',
      ),
    );
    foreach ($scalar_fields as $group => $fields) {
      foreach ($fields as $name) {
        $value = $values[$group][$name][$name];
        if ($defaults->{$name} == $value) {
          // Value matches the default, so it is not overridden.
          $this->configuration->{$name} = NULL;
        }
        else {
          // Value does not match the default, store the override.
          $this->configuration->{$name} = $value;
        }
      }
    }

    return $this->configuration;
  }
}

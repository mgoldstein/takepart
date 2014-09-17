<?php
/**
 * @file
 * Video inline content controller.
 */

class InlineContentVideo extends InlineContentReplacementController {

  /**
   * Update the replacement content's display label.
   */
  public function updateLabel($replacement) {
    return t('Some Label');
  }

  /**
   * Render the replacement content.
   */
  public function view($replacement, $content, $view_mode = 'default', $langcode = NULL) {
    return array();
  }

  public function form($form, &$form_state, $replacement) {

    $controller = new TakePartVideoPlayerOverrideController();

    // Get the configuration for the inline content.
    $override = $controller->loadOverrideForEntity('inline_content', $replacement->id, 'inline_content');
    if (is_null($override)) {
      $override = $controller->create();
    }

    // Get the global defaults for inline content.
    $global_defaults = $controller->loadByName('inline_content');

    $storage_key = implode(":", $form['#parents']);
    if (isset($form_state['storage'][$storage_key])) {
      $active = $form_state['storage'][$storage_key];
    }
    else {
      // Merge to two configurations into the active configuration.
      $active = $controller->merge(array($global_defaults, $override));
      $form_state['storage'][$storage_key] = $active;
    }

    $form_controller = new TakePartVideoPlayerOverrideFormController($active);
    $form['tp_video_player'] = $form_controller->form(array(
      '#title' => t('Player Configuration'),
      '#tree' => TRUE,
    ), $form_state);

    return $form;
  }

  public function submit($form, &$form_state, $replacement) {

    $parents = $form['tp_video_player']['#parents'];
    $values = drupal_array_get_nested_value($form_state['values'], $parents);

    $controller = new TakePartVideoPlayerOverrideController();

    // Get the global defaults for inline content.
    $global_defaults = $controller->loadByName('inline_content');

    // Get the existing overrides for the inline content.
    $override = $controller->loadOverrideForEntity('inline_content',
      $replacement->id, 'inline_content');
    if (is_null($override)) {
      $override = $controller->create();
    }

    // Update the existing overrides.
    $form_controller = new TakePartVideoPlayerOverrideFormController($override);
    $updated_override = $form_controller->update($values, $global_defaults);

    // Update the active configuration.
    $storage_key = implode(":", $form['#parents']);
    $active = $controller->merge(array($global_defaults, $updated_override));
    $form_state['storage'][$storage_key] = $active;

    $replacement->tp_video_player = $updated_override;
  }

  public function save($replacement) {
    $controller = new TakePartVideoPlayerOverrideController();
    $controller->save($replacement->tp_video_player);
    $controller->attachOverrideToEntity($replacement->tp_video_player,
      'inline_content', $replacement->id, 'inline_content');
  }
}

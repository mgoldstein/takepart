<?php
/**
 * Implement hook_field_widget_info().
 */
function alt_media_widget_field_widget_info() {
  return array(
    'media_generic_alt' => array(
      'label' => t('Media file selector Alternative'),
      'field types' => array('media'),
      'settings' => array(
        'progress_indicator' => 'throbber',
        'allowed_types' => array('image'),
        'allowed_schemes' => array('public', 'private'),
      ),
      'behaviors' => array(
        'multiple values' => FIELD_BEHAVIOR_DEFAULT,
        'default value' => FIELD_BEHAVIOR_NONE,
      ),
    ),
  );
}

/*
 * implements hook_field_widget_settings_from
 * 
 * stilling mostly from the standard media field widget
 */
function alt_media_widget_field_widget_settings_form($field, $instance) {
  return media_field_widget_settings_form($field, $instance);
}

/**
 * Implements hook_field_widget_form().
 */
function alt_media_widget_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  $widget_settings = $instance['widget']['settings'];

  $permission = user_access('edit media');
  if (!$permission) {
    // @todo: show the default file upload field.
    return;
  }
  //find the current fid form_state beat element which beat items
  $fid = isset($items[$delta]['fid']) ? $items[$delta]['fid'] : 0;
  $fid = isset($element['#value']['fid']) ? $element['#value']['fid'] : $fid;
  $fid = isset($form_state['values'][$element['#field_name']][$langcode][$delta]['fid']) ?
    $form_state['values'][$element['#field_name']][$langcode][$delta]['fid'] : $fid;


  // if we are rebuilding after a trigger
  // get the action that triggered it as well as
  $action = NULL;
  $action_delta = NULL;
  if(isset($form_state['triggering_element']['#array_parents'])) {
    $action = end($form_state['triggering_element']['#array_parents']);
    $action_delta = prev($form_state['triggering_element']['#array_parents']);
    reset($form_state['triggering_element']['#array_parents']);
  }

  // if this is a delete then set the fid = 0;
  if(($action_delta == $delta) && ($action == 'delete')) {
    $fid = 0;
    $form_state['values'][$element['#field_name']][$langcode][$delta]['fid'] = $fid;
    $form_state['input'][$element['#field_name']][$langcode][$delta]['fid'] = $fid;
  }

  //wrapper our field so we can find and refesh it
  $wrapper_id = "{$element['#field_name']}-{$delta}";
  $element['#prefix'] = "<div class ='amw-field' id = '$wrapper_id'>";
  $element['#suffix'] = "<div class ='clearfix'></div></div>";

  //field to store value
  $element['fid'] = array(
    '#type' => 'textfield',
    '#default_value' => $fid,
    '#attributes' => array('class' => array('fid')),
    '#ajax' => array(
      'callback' => "alt_media_widget_amw_update_callback",
      'wrapper' => $wrapper_id,
      'event' => 'refresh',
    ),
  );

  $element['select'] = array(
    '#type' => 'button',
    '#value' => t('Select Media'),
    '#ajax' => array(
      'callback' => "alt_media_widget_amw_update_callback",
      'wrapper' => $wrapper_id,
    ),
  );
  if ($fid && ($file = file_load($fid))) {
    //display preview
    //$preview = media_get_thumbnail_preview($file);
    $preview = file_view($file, 'media_preview');
    $element['preview'] = $preview;
    $element['preview']['#weight'] = -100;
    $element['preview']['#prefix'] = '<div class ="amw-preview">';
    $element['preview']['#suffix'] = '</div>';

    // change title of select
    $element['select']['#title'] = t('Change Media');

    // add edit link
    $element['edit'] = array(
      '#type' => 'button',
      '#value' => 'Meta Data',
      '#title' => 'Meta Data',
      '#ajax' => array(
        'callback' => "alt_media_widget_amw_update_callback",
        'wrapper' => $wrapper_id,
      ),
    );

    //add remove link
    $element['delete'] = array(
      '#type' => 'button',
      '#value' => 'Remove',
      '#ajax' => array(
        'callback' => "alt_media_widget_amw_update_callback",
        'wrapper' => $wrapper_id,
      ),
   );
  }

  if(($action_delta === $delta) && ($action == 'edit')) {
    $file->dialog_inner = "media-dialog-inner-$wrapper_id";
    $dialog_form = drupal_get_form('media_edit', $file);
    $dialog_form['#prefix'] = "<div field = '$wrapper_id' class = 'media-dialog-wrapper' id = 'media-dialog-wrapper-$wrapper_id'><div class = 'media-dialog-inner' id = 'media-dialog-inner-$wrapper_id'>";
    $dialog_form['#suffix'] = "</div></div>";
    $element['dialog'] = array('#markup' => drupal_render($dialog_form));
  }
  if(($action_delta === $delta) && ($action == 'select')) {
      $dialog_form = alt_media_widget_amw_media_select("media-dialog-inner-$wrapper_id", $field);
    $dialog_form['#prefix'] = "<div field = '$wrapper_id' class = 'media-dialog-wrapper' id = 'media-dialog-wrapper-$wrapper_id'><div class = 'media-dialog-inner' id = 'media-dialog-inner-$wrapper_id'>";
    $dialog_form['#suffix'] = "</div></div>";
    $element['dialog'] = array('#markup' => drupal_render($dialog_form));
  }
  if(!isset($element['dialog'])) {
    $element['dialog'] = array(
      '#prefix' => "<div field = '$wrapper_id' class = 'media-dialog-wrapper' id = 'media-dialog-wrapper-$wrapper_id'>",
      '#suffix' => "</div>",
      '#markup' => "<div class = 'media-dialog-inner' id = 'media-dialog-inner-$wrapper_id'></div>",
    );
  }
  return $element;
}

/*
 * form for selecting media
 *
 */
function alt_media_widget_amw_media_select($dialog_inner, $field) {
$form['#type'] = "vertical_tabs";
$form['browse_set'] = array(
  '#type' => 'fieldset',
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
  '#title' => 'Browse',
  'browse_form' => drupal_get_form('media_widget_amw_media_browser', $types, $dialog_inner),
);
$types = array('image');
$form['other'] = array(
  '#type' => 'fieldset',
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
  '#title' => 'Meta Data',
  'browse_form' => array('#markup' => "baseball"),
);
$form['upload_set'] = array(
  '#type' => 'fieldset',
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
  '#title' => 'Upload',
  'browse_form' => drupal_get_form('media_add_upload', $types, $dialog_inner),
);

return $form;  
}

/*
 * form for views based browser
 */
function media_widget_amw_media_browser($form, $form_state, $types, $dialog_inner) {
  $form['#dialog_inner'] = $dialog_inner;
  $view_name = 'alt_media_widget_default';
  $view_display_name = 'default';
  $form['browser']['#markup'] = views_embed_view($view_name, $view_display_name);
  $form['fid'] = array(
    '#type' => 'textfield',
    '#ajax' => array(
       'callback' => 'alt_media_widget_amw_update_from_dialog_callback',
       'wrapper' => $dialog_inner,
       'event' => 'update',
     )
  );
return $form;
}



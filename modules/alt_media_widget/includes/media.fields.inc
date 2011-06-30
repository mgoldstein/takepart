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

function alt_media_widget_field_widget_settings_form($field, $instance) {
  return media_field_widget_settings_form($field, $instance);
}

/**
 * Implements hook_field_widget_form().
 */
function alt_media_widget_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  $widget_settings = $instance['widget']['settings'];
  $fid = isset($items[$delta]['fid']) ? $items[$delta]['fid'] : 0;
  $fid = isset($element['#value']['fid']) ? $element['#value']['fid'] : $fid;
  $permission = user_access('edit media');
  if (!$permission) {
    // @todo: show the default file upload field.
    return;
  }
  $wrapper_id = "{$element['#field_name']}-{$delta}";
  $element['#prefix'] = "<div class ='amw-field' id = '$wrapper_id'>";
  $element['#suffix'] = "</div>";
  $element['fid'] = array(
    '#type' => 'textfield',
    '#default_value' => $fid,
    '#attributes' => array('class' => array('fid')),
  );
  $element['select'] = array(
    '#type' => 'link',
    '#title' => t('Select Media'),
    '#href' => "media/amw/select/{$element['#field_name']}/$delta/$fid",
    '#ajax' => array(
      'page' => "media/amw/edit/{$element['#field_name']}/$delta/$fid",
      'wrapper' => "media-dialog-$wrapper_id",
      'event' => 'click',
    ),
  );
  if ($fid && ($file = file_load($fid))) {
    //display preview
    $preview = media_get_thumbnail_preview($file);
    $element['preview'] = $preview;
    $element['preview']['#weight'] = -100;

    // change title of select
    $element['select']['#title'] = t('Change Media');

    // add edit link
    $element['edit'] = array(
      '#type' => 'link',
      '#href' => "media/amw/edit/{$element['#field_name']}/$delta/$fid",
      '#value' => 'Meta Data',
      '#title' => 'Meta Data',
      '#ajax' => array(
        'page' => "media/amw/edit/{$element['#field_name']}/$delta/$fid",
        'wrapper' => "media-dialog-$wrapper_id",
        'event' => 'click',
      ),
    );

    //add remove link
    $element['delete'] = array(
      '#type' => 'link',
      '#title' => 'Remove',
      '#href' => 'admin/etb/5',
      //'#suffix' => '<div id = "media-edit-5"></div>',
      //'#weight' => -100000,
      '#ajax' => array(
        'callback' => 'etb_callback',
        'wrapper' => 'media-edit-5',
        'event' => 'click',
      ),
    );
  }
  if(isset($form_state['triggering_element']['#array_parents'])) {
    $action = end($form_state['triggering_element']['#array_parents']);
    reset($form_state['triggering_element']['#array_parents']);
    switch($action) {
      case 'select' :
        $form_state['values'][$element['#field_name']][$lang_code][$delta]['fid'] = 6;
        $form_state['input'][$element['#field_name']][$lang_code][$delta]['fid'] = 8;
        $element['fid']['#default_value'] = 7;
        $element['dialog'] = array(
          '#type' => 'markup',
          '#markup' => '',
          //'#suffix' => '<div id = "media-edit-5"></div>',
          //'#weight' => -100000,
          '#ajax' => array(
            'callback' => 'etb_callback',
            'wrapper' => 'media-edit-5',
            'event' => 'click',
          ),
        );
      break;
      case 'edit':
    }
  }
  $element['dialog'] = array(
    '#prefix' => "<div class = 'media-dialog-wrapper' id = 'media-dialog-wrapper-$wrapper_id'>",
    '#suffix' => "</div>",
    '#markup' => "<div id = 'media-dialog-$wrapper_id'></div>",
  );
  return $element;
}


function alt_media_widget_amw_media_select($form, $form_state) {
$view_name = 'alt_media_widget_browser';
$view_display_name = 'page_1';
$form['browser']['#markup'] = views_embed_view($view_name, $view_display_name);
$form['test']['#markup'] = "bob was here";
return $form;  
}

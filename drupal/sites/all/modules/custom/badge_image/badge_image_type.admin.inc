<?php
/**
 * @file
 * Administrative interface for Badge Image Types.
 */

class BadgeImageTypeUIController extends EntityDefaultUIController {

  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = t('Manage badge types.');
    return $items;
  }
}

/**
 * Badge Image Type entity form.
 */
function badge_image_type_form($form, &$form_state, $type, $op = 'edit') {

  $form_state['badge_image_type'] = $type;

  // Update the label and reset the type if we are cloning the type.
  if ($op == 'clone') {
    $type->id = '';
    $type->type = '';
    $type->label .= ' (cloned)';
    $type->blank_fid = 0;
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#description' => t('The human-readable name of the badge type'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#size' => 30,
    '#default_value' => $type->label,
  );

  $form['type'] = array(
    '#description' => t('A unqiue machine-readable name for this badge type. It must only contain lowercase letters, numbers and underscores.'),
    '#type' => 'machine_name',
    '#maxlength' => 32,
    '#machine_name' => array(
      'exists' => 'badge_image_type_load',
      'source' => array('label'),
    ),
    '#default_value' => $type->type,
  );

  $form['max_length'] = array(
    '#title' => t('Maximum Length'),
    '#description' => t('The maximum length of the dynamic text.'),
    '#size' => 20,
    '#type' => 'textfield',
    '#required' => TRUE,
    '#element_validate' => array('_element_validate_integer_positive'),
    '#default_value' => $type->max_length,
  );

  $form['redirect_url'] = array(
    '#title' => t('Redirect URL/Path'),
    '#description' => t('The URL or site path to redirect to after a badge is submitted'),
    '#type' => 'textfield',
    '#size' => 60,
    '#element_validate' => array('badge_image_validate_redirect_url'),
    '#default_value' => $type->redirect_url,
  );

  $form['share_url'] = array(
    '#title' => t('Common Share Path'),
    '#description' => t('The common site path for sharing all badges'),
    '#type' => 'textfield',
    '#size' => 60,
    '#element_validate' => array('badge_image_validate_share_url'),
    '#default_value' => $type->share_url,
  );

  $form['generator'] = array(
    '#title' => t('Generated Badge'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
  );

  $form['generator']['blank_fid'] = array(
    '#title' => t('Blank'),
    '#description' => t('The badge blank image'),
    '#type' => 'managed_file',
    '#default_value' => $type->blank_fid,
    '#upload_location' => 'public://badge_image/blanks/',
  );

  $form['generator']['image_font_size'] = array(
    '#title' => t('Font Size'),
    '#description' => t('The font size to use for the dynamic text.'),
    '#size' => 20,
    '#type' => 'textfield',
    '#required' => TRUE,
    '#element_validate' => array('_element_validate_integer_positive'),
    '#default_value' => $type->image_font_size,
  );

  $form['generator']['image_font_angle'] = array(
    '#title' => t('Font Angle'),
    '#description' => t('The font size to use for the dynamic text.'),
    '#size' => 20,
    '#type' => 'textfield',
    '#required' => TRUE,
    '#element_validate' => array('badge_image_validate_integer_non_negative'),
    '#default_value' => $type->image_font_angle,
  );

  $form['generator']['image_offset_y'] = array(
    '#title' => t('Vertical Offset'),
    '#description' => t('The number of pixels from the top of the image.'),
    '#size' => 20,
    '#type' => 'textfield',
    '#required' => TRUE,
    '#element_validate' => array('badge_image_validate_integer_non_negative'),
    '#default_value' => $type->image_offset_y,
  );

  $form['preview'] = array(
    '#title' => t('Badge Preview'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
  );

  $form['preview']['preview_fid'] = array(
    '#title' => t('Blank'),
    '#description' => t('The badge blank image for the generator preview'),
    '#type' => 'managed_file',
    '#default_value' => $type->preview_fid,
    '#upload_location' => 'public://badge_image/blanks/',
  );

  $form['preview']['preview_font_size'] = array(
    '#title' => t('Font Size'),
    '#description' => t('The font size to use for the dynamic text in the generator preview.'),
    '#size' => 20,
    '#type' => 'textfield',
    '#required' => TRUE,
    '#element_validate' => array('_element_validate_integer_positive'),
    '#default_value' => $type->preview_font_size,
  );

  $form['preview']['preview_font_angle'] = array(
    '#title' => t('Font Angle'),
    '#description' => t('The font size to use for the dynamic text in the generator preview.'),
    '#size' => 20,
    '#type' => 'textfield',
    '#required' => TRUE,
    '#element_validate' => array('badge_image_validate_integer_non_negative'),
    '#default_value' => $type->preview_font_angle,
  );

  $form['preview']['preview_offset_y'] = array(
    '#title' => t('Vertical Offset'),
    '#description' => t('The number of pixels from the top of the image in the generator preview.'),
    '#size' => 20,
    '#type' => 'textfield',
    '#required' => TRUE,
    '#element_validate' => array('badge_image_validate_integer_non_negative'),
    '#default_value' => $type->preview_offset_y,
  );

  $form['copy'] = array(
    '#title' => t('Heading and Instructions'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
  );

  $form['copy']['heading'] = array(
    '#title' => t('User Generation Form Heading'),
    '#description' => t('The heading for the user generation form'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#size' => 60,
    '#default_value' => $type->heading,
  );

  $form['copy']['instructions'] = array(
    '#title' => t('User Generation Form Instructions'),
    '#description' => t('The instructions for the user generation form'),
    '#type' => 'text_format',
    '#default_value' => $type->instructions_text,
    '#format' => $type->instructions_format,
  );

  $form['sharing'] = array(
    '#title' => t('Social Sharing'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
  );

  $form['sharing']['twitter_message'] = array(
    '#title' => t('Twitter Message'),
    '#description' => t('The default message to use when sharing the badge on Twitter.'),
    '#type' => 'textfield',
    '#size' => 60,
    '#default_value' => $type->twitter_message,
  );

  $form['sharing']['email_message'] = array(
    '#title' => t('Email Message'),
    '#description' => t('The default message to use when sharing the badge through email.'),
    '#type' => 'textarea',
    '#element_validate' => array('badge_image_validate_textarea_maxlength'),
    '#default_value' => $type->email_message,
  );
  
  $form['sharing']['token_help'] = array(
    '#title' => t('Replacement patterns'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['sharing']['token_help']['help'] = array(
    '#theme' => 'token_tree',
    '#token_types' => array('badge_image'),
  );

  $form['actions'] = array('#type' => 'actions');
  $submit = array();
  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#value' => t('Save badge type'),
    '#type' => 'submit',
    '#weight' => 40,
    '#submit' => $submit + array('badge_image_type_form_submit'),
  );

  // Only add the delete button if we are editting an existing type.
  $id = $type->identifier();
  if (!empty($id)) {
    $form['actions']['delete'] = array(
      '#value' => t('Delete badge type'),
      '#type' => 'submit',
      '#submit' => array('badge_image_type_form_submit_delete'),
      '#weight' => 45,
    );
  }

  $form['actions']['cancel'] = array(
    '#type' => 'markup',
    '#markup' => l(t('Cancel'), 'admin/structure/badge_types'),
    '#weight' => 50,
  );

  return $form;
}

function badge_image_validate_integer_non_negative($element, &$form_state) {
  $value = $element['#value'];
  if ($value !== '' && (!is_numeric($value) || intval($value) != $value 
  || $value < 0)) {
    form_error($element, t('%name must be a non-negative integer.',
      array('%name' => $element['#title'])));
  }
}

function badge_image_validate_textarea_maxlength($element, &$form_state) {
  $value = $element['#value'];
  $maxlength = isset($element['#maxlength']) ? $element['#maxlength'] : 255;
  if ($value !== '' && strlen($value) > $maxlength) {
    form_error($element, t('%name must be no more than %maxlength characters.',
      array('%name' => $element['#title'], '%maxlength' => $maxlength)));
  }
}

function badge_image_validate_redirect_url($element, &$form_state) {
  $value = $element['#value'];
  if ($value !== '' && !valid_url($value)) {
    form_error($element, t('%name must be a valid URL or site path.',
      array('%name' => $element['#title'])));
  }
}

function badge_image_validate_share_url($element, &$form_state) {
  $value = $element['#value'];
  if ($value !== '' && !valid_url($value)) {
    form_error($element, t('%name must be a valid site path.',
      array('%name' => $element['#title'])));
  }
  elseif (valid_url($value, TRUE)) {
    form_error($element, t('%name must be a valid path internal to the site.',
      array('%name' => $element['#title'])));
  }
}

/**
 * Badge Image Type entity form save (submit) handler.
 */
function badge_image_type_form_submit(&$form, &$form_state) {

  // Make a note of the original blank fid.
  $original_blank_fid = $form_state['badge_image_type']->blank_fid;
  $original_preview_fid = $form_state['badge_image_type']->preview_fid;

  // Build the type entity from the form.
  $type = entity_ui_form_submit_build_entity($form, $form_state);
  $type->instructions_text = $form_state['values']['instructions']['value'];
  $type->instructions_format = $form_state['values']['instructions']['format'];

  // Save the type.
  $status = $type->save();
  if ($status == SAVED_UPDATED) {
    drupal_set_message(t('The badge type @name has been updated.',
      array('@name' => $type->label)));
  }
  elseif ($status == SAVED_NEW) {
    drupal_set_message(t('The badge type @name has been added.',
      array('@name' => $type->label)));
  }

  if ($original_blank_fid != $type->blank_fid) {
    if (!empty($original_blank_fid)) {
      $file = file_load($original_blank_fid);
      file_usage_delete($file, 'badge_image', 'badge_image_type', $type->id);
      file_delete($file);
    }
    if (!empty($type->blank_fid)) {
      $file = file_load($type->blank_fid);
      $file->status = FILE_STATUS_PERMANENT;
      file_save($file);
      file_usage_add($file, 'badge_image', 'badge_image_type', $type->id);
    }
  }

  if ($original_preview_fid != $type->preview_fid) {
    if (!empty($original_preview_fid)) {
      $file = file_load($original_preview_fid);
      file_usage_delete($file, 'badge_image', 'badge_image_type', $type->id);
      file_delete($file);
    }
    if (!empty($type->preview_fid)) {
      $file = file_load($type->preview_fid);
      $file->status = FILE_STATUS_PERMANENT;
      file_save($file);
      file_usage_add($file, 'badge_image', 'badge_image_type', $type->id);
    }
  }

  // Clear the cached share path lookups
  cache_set('badge_image:common_share_paths', serialize(FALSE));
  
  // Go back to the list of types.
  $form_state['redirect'] = 'admin/structure/badge_types';
}

/**
 * Badge Image Type entity form delete (submit) handler.
 */
function badge_image_type_form_submit_delete(&$form, &$form_state) {

  // Go to the delete confirmation page.
  $form_state['redirect'] = array(
    'admin/structure/badge_types/manage/'
    . $form_state['badge_image_type']->identifier() . '/delete',
    array(
      'query' => array(
        'destination' => 'admin/structure/badge_types',
      ),
    ),
  );
}

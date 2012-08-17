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

  $form['fid'] = array(
    '#title' => t('Blank'),
    '#description' => t('The badge blank image'),
    '#type' => 'managed_file',
    '#default_value' => $type->fid,
    '#upload_location' => 'public://badge_image/blanks/',
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

  $form['font_size'] = array(
    '#title' => t('Font Size'),
    '#description' => t('The font size to use for the dynamic text.'),
    '#size' => 20,
    '#type' => 'textfield',
    '#required' => TRUE,
    '#element_validate' => array('_element_validate_integer_positive'),
    '#default_value' => $type->font_size,
  );

  $form['font_angle'] = array(
    '#title' => t('Font Angle'),
    '#description' => t('The font size to use for the dynamic text.'),
    '#size' => 20,
    '#type' => 'textfield',
    '#required' => TRUE,
    '#element_validate' => array('badge_image_validate_integer_non_negative'),
    '#default_value' => $type->font_angle,
  );

  $form['offset_y'] = array(
    '#title' => t('Vertical Offset'),
    '#description' => t('The number of pixels from the top of the image.'),
    '#size' => 20,
    '#type' => 'textfield',
    '#required' => TRUE,
    '#element_validate' => array('badge_image_validate_integer_non_negative'),
    '#default_value' => $type->offset_y,
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
  if ($value !== '' && (!is_numeric($value) || intval($value) != $value || $value < 0)) {
    form_error($element, t('%name must be a non-negative integer.', array('%name' => $element['#title'])));
  }
}

/**
 * Badge Image Type entity form save (submit) handler.
 */
function badge_image_type_form_submit(&$form, &$form_state) {

  // Make a note of the original blank fid
  $prev_fid = $form_state['badge_image_type']->fid;
    
  // Build the type entity from the form.
  $type = entity_ui_form_submit_build_entity($form, $form_state);

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

  if ($prev_fid != $type->fid) {
    if (!empty($prev_fid)) {
      $file = file_load($prev_fid);
      file_usage_delete($file, 'badge_image', 'badge_image_type', $type->id);
      file_delete($file);
    }
    if (!empty($type->fid)) {
      $file = file_load($type->fid);
      $file->status = FILE_STATUS_PERMANENT;
      file_save($file);
      file_usage_add($file, 'badge_image', 'badge_image_type', $type->id);
    }
  }
  
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

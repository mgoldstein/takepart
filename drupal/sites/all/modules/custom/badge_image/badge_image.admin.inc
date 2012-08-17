<?php
/**
 * @file
 * Administrative interface for Badge Images.
 */

class BadgeImageUIController extends EntityDefaultUIController {

  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path] = array(
      'title' => t('Badges'),
      'description' => t('List and edit badges.'),
      'page callback' => 'drupal_get_form',
      'page arguments' => array($this->entityType . '_overview_form',
        $this->entityType),
      'access callback' => 'entity_access',
      'access arguments' => array('view', $this->entityType),
      'type' => MENU_LOCAL_TASK | MENU_NORMAL_ITEM,
      'file' => 'badge_image.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
    );
    return $items;
  }
}

/**
 * Badge Image entity form.
 */
function badge_image_form($form, &$form_state, $entity, $op = 'edit') {

  $form_state['badge_image'] = $entity;
  $entity->type = 'no_mas_badge';

  // Reset the type if we are cloning the badge.
  if (!isset($form_state['values']) && $op == 'clone') {
    $entity->id = '';
    $entity->is_new = TRUE;
  }

  if (!empty($entity->fid)) {
    $file = file_load($entity->fid);
    $form['preview'] = array(
      '#title' => t('Preview'),
      '#type' => 'fieldset',
    );
    $form['preview']['badge'] = array(
      '#type' => 'markup',
      '#prefix' => '<p>',
      '#markup' => '<img src="' . file_create_url($file->uri) . '" />',
      '#suffix' => '</p>',
    );
  }

  $type = badge_image_type_load($entity->type);
  $form['text'] = array(
    '#title' => t('Text'),
    '#description' => t('The text entered by the user.'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#size' => 30,
    '#default_value' => $entity->text,
    '#maxlength' => $type->max_length,
  );

  $form['actions'] = array('#type' => 'actions');
  $submit = array();
  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save badge'),
    '#weight' => 40,
    '#submit' => $submit + array('badge_image_form_submit'),
  );

  // Only add the delete button if we are editting an existing entity.
  $id = $entity->identifier();
  if (!empty($id)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete badge'),
      '#submit' => $submit + array('badge_image_form_submit_delete'),
      '#weight' => 45,
    );
  }

  $form['actions']['cancel'] = array(
    '#type' => 'markup',
    '#markup' => l(t('Cancel'), 'admin/content/badge'),
    '#weight' => 50,
  );

  return $form;
}

/**
 * Badge Image entity form save (submit) handler.
 */
function badge_image_form_submit(&$form, &$form_state) {

  // Build the entity from the form.
  $entity = entity_ui_form_submit_build_entity($form, $form_state);
  $entity->type = 'no_mas_badge';

  // Save the entity.
  $status = $entity->save();
  if ($status !== FALSE) {
    badge_image_generate_image($entity);
  }
  if ($status == SAVED_UPDATED) {
    drupal_set_message(t('The @text badge has been updated.',
      array('@text' => $entity->text)));
  }
  elseif ($status == SAVED_NEW) {
    drupal_set_message(t('The @text badge has been added.',
      array('@text' => $entity->text)));
  }

  // Go back to the list of entities.
  $form_state['redirect'] = 'admin/content/badge';
}

/**
 * Badge Image entity form delete (submit) handler.
 */
function badge_image_form_submit_delete(&$form, &$form_state) {

  // Go to the delete confirmation page.
  $form_state['redirect'] = array(
    'admin/content/badge/manage/'
    . (string) $form_state['badge_image']->id . '/delete',
    array(
      'query' => array(
        'destination' => 'admin/content/badge',
      ),
    ),
  );
}

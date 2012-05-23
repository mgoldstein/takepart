<?php

/**
 * @file
 * Admin page callbacks for the Cleanup Pathauto module.
 *
 * @ingroup pathauto
 */

/**
 * Form builder; Configure the Cleanup Pathauto settings.
 *
 * @ingroup forms
 * @see system_settings_form()
 */
function cleanup_pathauto_settings_form($form) {
  $form['cleanup_pathauto_patterns'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('Patterns'),
    '#collapsible'   => TRUE,
    '#collapsed'     => FALSE,
  );
  $form['cleanup_pathauto_patterns']['cleanup_pathauto_check_nodes'] = array(
    '#type' => 'textarea',
    '#title' => t('Types of nodes to check'),
    '#default_value' => variable_get('cleanup_pathauto_check_nodes', 'article'),
    '#description' => t('Enter a list of node types to check, one per line.'),
  );
  $form['cleanup_pathauto_patterns']['cleanup_pathauto_allowed_chars'] = array(
    '#type' => 'textfield',
    '#title' => t('Allowed characters in aliases'),
    '#default_value' => variable_get('cleanup_pathauto_allowed_chars', '/[^a-zA-Z0-9#\-$\/]/'),
    '#description' => t('Display alias changes (except during bulk updates).'),
  );

  return system_settings_form($form);
}


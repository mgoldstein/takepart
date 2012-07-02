<?php

/**
 * @file
 * Admin page callbacks for the Cleanup Pathauto module.
 *
 * @ingroup pathauto
 */

/**
 * Form builder; Configure the video popup settings.
 *
 * @ingroup forms
 * @see system_settings_form()
 */
function takepart_vidpop_settings_form($form) {
  $form['takepart_vidpop_patterns'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('Patterns'),
    '#collapsible'   => TRUE,
    '#collapsed'     => FALSE,
  );
  $form['takepart_vidpop_patterns']['takepart_vidpop_check_nodes'] = array(
    '#type' => 'textarea',
    '#title' => t('Types of nodes to check'),
    '#default_value' => variable_get('takepart_vidpop_check_nodes', 'article'),
    '#description' => t('Enter a list of node types to check, one per line.'),
  );
  $form['takepart_vidpop_patterns']['takepart_vidpop_allowed_chars'] = array(
    '#type' => 'textfield',
    '#title' => t('Allowed characters in aliases'),
    '#default_value' => variable_get('takepart_vidpop_allowed_chars', '/[^a-zA-Z0-9#\-$\/]/'),
    '#description' => t('Display alias changes (except during bulk updates).'),
  );

  return system_settings_form($form);
}


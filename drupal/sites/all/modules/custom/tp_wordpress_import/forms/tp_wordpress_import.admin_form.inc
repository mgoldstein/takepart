<?php

/**
 *  @function:
 *    This function is used to provide an admin form for module.
 */
function tp_wordpress_import_admin_form() {
  //variables
  $form = array();

  //author nid
  $form['tp_wordpress_import_author_nid'] = array(
    '#type' => 'textfield',
    '#title' => t('Feeds - Takepart Wordpress Import - Author Profile NID'),
    '#description' => t('Author Profile NID used for mapping within feeds.'),
    '#default_value' => variable_get('tp_wordpress_import_author_nid', ''),
  );
  
  //author nid
  $form['tp_wordpress_import_content_prefix'] = array(
    '#type' => 'textarea',
    '#title' => t('Feeds - Takepart Wordpress Import - Content Prefix Message'),
    '#description' => t('This is the content prefix message that will display. Available token: @author'),
    '#default_value' => variable_get('tp_wordpress_import_content_prefix', 'This article was written by @author and it originally appeared on Dowser.org; a website focused on the practical and human elements of social innovation.'),
  );
  
  //admin_tag
  $form['tp_wordpress_import_admin_tag'] = array(
    '#type' => 'textfield',
    '#title' => t('Feeds - Takepart Wordpress Import - Admin Tag'),
    '#description' => t('Admin Tag Taxonomy Name'),
    '#default_value' => variable_get('tp_wordpress_import_admin_tag', 'Dowser'),
  );
  
  //tagging
  $form['tp_wordpress_import_tagging'] = array(
    '#type' => 'textfield',
    '#title' => t('Feeds - Takepart Wordpress Import - Tagging'),
    '#description' => t('Tagging Taxonomy Name'),
    '#default_value' => variable_get('tp_wordpress_import_tagging', 'Social Justice'),
  );

  //tap action widget
  $form['tp_wordpress_import_default_action_widget'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Default TAP Action Widget'),
    '#description' => t('Check if you want to have TAP action widget'),
    '#default_value' => variable_get('tp_wordpress_import_default_action_widget', 1),
  );
  
  return system_settings_form($form);
}
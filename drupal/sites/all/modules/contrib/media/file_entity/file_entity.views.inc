<?php

/**
 * Implements hook_views_data().
 */
function file_entity_views_data() {
  $data = array();

  // File entity type
  $data['file_managed']['type'] = array(
    'group' => 'File',
    'title' => t('File entity type'),
    'help' => t('The type of the file.'),
    'field' => array(
      'handler' => 'views_handler_field_file_entity_type',
     ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_file_entity_type',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_file_entity_type',
    ),
  );

  return $data;
}

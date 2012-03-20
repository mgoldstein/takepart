<?php

/**
 * @file
 * Provides extra functionality for the Contest UI via views
 */

/**
 * Implements hook_views_data()
 */
function takepart_contests_views_data_alter(&$data) { 

  $data['takepart_contests_contest']['link_contest'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a link to the contest.'),
      'handler' => 'contest_handler_link_field',
    ),
  );
  $data['takepart_contests_contest']['edit_contest'] = array(
    'field' => array(
      'title' => t('Edit Link'),
      'help' => t('Provide a link to the edit form for the contest.'),
      'handler' => 'contest_handler_edit_link_field',
    ),
  );
  $data['takepart_contests_contest']['delete_contest'] = array(
    'field' => array(
      'title' => t('Delete Link'),
      'help' => t('Provide a link to delete the contest.'),
      'handler' => 'contest_handler_delete_link_field',
    ),
  );
  // The content of this field is decided based on the menu structure that
  // follows contests/contest/%contest_id/op
  $data['takepart_contests_contest']['contest_operations'] = array(
    'field' => array(
      'title' => t('Operations Links'),
      'help' => t('Display all operations available for this contest.'),
      'handler' => 'contest_handler_contest_operations_field',
    ),
  );

  $data['takepart_contests_contest_entry']['link_entry'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a link to the contest entry.'),
      'handler' => 'contest_entry_handler_link_field',
    ),
  );
  $data['takepart_contests_contest_entry']['edit_entry'] = array(
    'field' => array(
      'title' => t('Edit Link'),
      'help' => t('Provide a link to the edit form for the contest entry.'),
      'handler' => 'contest_entry_handler_edit_link_field',
    ),
  );
  $data['takepart_contests_contest_entry']['delete_entry'] = array(
    'field' => array(
      'title' => t('Delete Link'),
      'help' => t('Provide a link to delete the contest entry.'),
      'handler' => 'contest_entry_handler_delete_link_field',
    ),
  );
  // The content of this field is decided based on the menu structure that
  // follows contests/contest/%contest_id/entry/%entry_id/op
  $data['takepart_contests_contest_entry']['entry_operations'] = array(
    'field' => array(
      'title' => t('Operations Links'),
      'help' => t('Display all operations available for this contest entry.'),
      'handler' => 'contest_entry_handler_contest_entry_operations_field',
    ),
  );
}

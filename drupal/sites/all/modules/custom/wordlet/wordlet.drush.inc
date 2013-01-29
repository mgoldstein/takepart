<?php
/**
 * @file
 * Drush commands for Wordlet module
 */

/**
 * Implements hook_drush_command().
 */
function wordlet_drush_command() {
  return array(
    'wordlet-publish' => array(
      'description' => dt('Publish a wordlet page.'),
      'arguments' => array(
        'name' => dt('name of the wordlet to publish'),
      ),
      'examples' => array(
        'Standard example' => 'drush wordlet-publish wordlet_page_name',
      ),
      'aliases' => array(
        'w-pub',
      ),
    ),
    'wordlet-unpublish' => array(
      'description' => dt('Unpublish a wordlet page.'),
      'arguments' => array(
        'name' => dt('name of the wordlet to unpublish'),
      ),
      'examples' => array(
        'Standard example' => 'drush wordlet-unpublish wordlet_page_name',
      ),
      'aliases' => array(
        'w-unpub',
      ),
    ),
    'wordlet-reset' => array(
      'description' => dt('Reset the publish state of a wordlet page.'),
      'arguments' => array(
        'name' => dt('name of the wordlet to reset'),
      ),
      'examples' => array(
        'Standard example' => 'drush wordlet-reset wordlet_page_name',
      ),
      'aliases' => array(
        'w-reset',
      ),
    ),
    'wordlet-state' => array(
      'description' => dt('Get publish state of a wordlet page.'),
      'arguments' => array(
        'name' => dt('name of the wordlet to check'),
      ),
      'examples' => array(
        'Standard example' => 'drush wordlet-state wordlet_page_name',
      ),
      'aliases' => array(
        'w-state',
      ),
    ),
    'wordlet-list' => array(
      'description' => dt('List the available wordlet pages.'),
      'arguments' => array(
      ),
      'examples' => array(
        'Standard example' => 'drush wordlet-list',
      ),
      'aliases' => array(
        'w-list',
      ),
    ),
  );
}

/**
 * Drush pubslish wordlet page
 */
function drush_wordlet_publish($page = NULL) {
  $config = _wordlet_configuration();
  if (isset($page) && isset($config[$page])) {
    variable_set("wordlet_{$page}_published", TRUE);
    drush_log(dt("Wordlet page @title published", array(
      '@title' => $page,
    )), 'ok');
  }
  else {
    drush_set_error('Unknown wordlet page.');
  }
}

/**
 * Drush unpubslish wordlet page
 */
function drush_wordlet_unpublish($page = NULL) {
  $config = _wordlet_configuration();
  if (isset($page) && isset($config[$page])) {
    variable_set("wordlet_{$page}_published", FALSE);
    drush_log(dt("Wordlet page @title unpublished", array(
      '@title' => $page,
    )), 'ok');
  }
  else {
    drush_set_error('Unknown wordlet page.');
  }
}

/**
 * Drush reset wordlet page publish state
 */
function drush_wordlet_reset($page = NULL) {
  $config = _wordlet_configuration();
  if (isset($page) && isset($config[$page])) {
    variable_del("wordlet_{$page}_published");
    drush_log(dt("Wordlet page @title reset to !state", array(
      '@title' => $page,
      '!state' => empty($config[$page]['published']) ? 'unpublished' : 'published',
    )), 'ok');
  }
  else {
    drush_set_error('Unknown wordlet page.');
  }
}

/**
 * Drush get publish state of a wordlet page
 */
function drush_wordlet_state($page = NULL) {
  $config = _wordlet_configuration();
  if (isset($page) && isset($config[$page])) {
    $published = variable_get("wordlet_{$page}_published",
      $config[$page]['published']);
    drush_log(dt("Wordlet page @title is !state", array(
      '@title' => $page,
      '!state' => $published ? 'published' : 'unpublished',
    )), 'ok');
  }
  else {
    drush_set_error('Unknown wordlet page.');
  }
}

/**
 * Drush list wordlet pages
 */
function drush_wordlet_list() {
  $paths = wordlet_page_paths();
  $rows = array();
  $rows[] = array('Name', 'Path');
  foreach ($paths as $path => $name) {
    $rows[] = array($name, $path);
  }
  drush_print_table($rows, TRUE);
}

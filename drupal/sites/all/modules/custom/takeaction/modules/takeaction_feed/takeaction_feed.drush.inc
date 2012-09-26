<?php
/**
 * @file
 * Drush commands for TakeAction Feeds module
 */

/**
 * Implements hook_drush_command().
 */
function takeaction_feed_drush_command() {
  return array(
    'tab-rebuild-feed' => array(
      'description' => dt('Rebuild the TakeAction action feed.'),
      'arguments' => array(
        'feed' => dt('An optional name of the feed to rebuild'),
      ),
      'examples' => array(
        'Standard example' => 'drush tab-rebuild-feed',
        'Argument example' => 'drush tab-rebuild-feed actions',
      ),
      'aliases' => array(
        'tabrbld',
      ),
    ),
  );
}

/**
 * Drush rebuild feed command callback.
 */
function drush_takeaction_feed_tab_rebuild_feed($feed = NULL) {
  if (!isset($feed) || $feed === 'actions') {
    $counts = array(
      'action' => 0,
      'petition_action' => 0,
      'pledge_action' => 0,
    );
    db_delete('takeaction_feed_actions');
    $nodes = db_select('node', 'n')
      ->fields('n', array('nid', 'type'))
      ->condition('n.type', array_keys($counts), 'IN')
      ->condition('n.status', 0, '!=')
      ->execute()
      ->fetchAllKeyed();
    foreach ($nodes as $nid => $type) {
      $node = node_load($nid);
      takeaction_feed_node_update($node);
      $counts[$type] += 1;
    }
    drush_log(dt('!total action items rebuilt', array(
      '!total' => array_sum($counts),
    )), 'ok');
  }
  else {
    drush_set_error('Unknown feed.');
  }
}

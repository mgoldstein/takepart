<?php

class TakePartVideoPlayerNodeOverrideController extends TakePartVideoPlayerConfigurationController {

  public function loadOverrideForNode($nid, $view_mode) {
    $query = db_select('tp_video_player_configuration', 'c')
      ->fields('c');
    $query->join('tp_video_player_node_configuration', 'n', 'n.configuration_id = c.id');
    $values = $query->condition('n.nid', $nid, '=')
      ->condition('n.view_mode', $view_mode, '=')
      ->range(0, 1)
      ->execute()
      ->fetchAssoc();
    if ($values !== FALSE) {
      return new TakePartVideoPlayerConfiguration($values);
    }
    return NULL;
  }

  public function attachOverrideToNode($configuration, $nid, $view_mode) {
    $fields = array(
      'configuration_id' => $configuration->id,
      'nid' => $nid,
      'view_mode' => $view_mode,
    );
    db_merge('tp_video_player_node_configuration')
      ->key(array('configuration_id' => $configuration->id))
      ->fields($fields)
      ->execute();
  }

  public function deleteOverridesForNode($nid) {
    $configuration_ids = db_select('tp_video_player_node_configuration', 'n')
      ->fields('n', array('configuration_id'))
      ->condition('n.nid', $nid, '=')
      ->execute()
      ->fetchCol();
    db_delete('tp_video_player_node_configuration')
      ->condition('nid', $nid, '=')
      ->execute();
    db_delete('tp_video_player_configuration')
      ->condition('id', $configuration_ids, 'IN')
      ->execute();
  }
}

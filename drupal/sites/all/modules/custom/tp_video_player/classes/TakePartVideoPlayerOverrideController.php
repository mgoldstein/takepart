<?php

class TakePartVideoPlayerOverrideController extends TakePartVideoPlayerConfigurationController {

  public function loadOverrideForEntity($entity_type, $entity_id, $view_mode) {
    $query = db_select('tp_video_player_configuration', 'c')
      ->fields('c');
    $query->join('tp_video_player_entity_configuration', 'e', 'e.configuration_id = c.id');
    $values = $query->condition('e.entity_type', $entity_type, '=')
      ->condition('e.entity_id', $entity_id, '=')
      ->condition('e.view_mode', $view_mode, '=')
      ->range(0, 1)
      ->execute()
      ->fetchAssoc();
    if ($values !== FALSE) {
      return new TakePartVideoPlayerConfiguration($values);
    }
    return NULL;
  }

  public function attachOverrideToEntity($configuration, $entity_type, $entity_id, $view_mode) {
    $fields = array(
      'configuration_id' => $configuration->id,
      'entity_type' => $entity_type,
      'entity_id' => $entity_id,
      'view_mode' => $view_mode,
    );
    db_merge('tp_video_player_entity_configuration')
      ->key(array('configuration_id' => $configuration->id))
      ->fields($fields)
      ->execute();
  }

  public function deleteOverridesForEntity($entity_type, $entity_id) {
    $configuration_ids = db_select('tp_video_player_entity_configuration', 'e')
      ->fields('e', array('configuration_id'))
      ->condition('e.entity_type', $entity_type, '=')
      ->condition('e.entity_id', $entity_id, '=')
      ->execute()
      ->fetchCol();
    db_delete('tp_video_player_entity_configuration')
      ->condition('entity_type', $entity_type, '=')
      ->condition('entity_id', $entity_id, '=')
      ->execute();
    db_delete('tp_video_player_configuration')
      ->condition('id', $configuration_ids, 'IN')
      ->execute();
  }
}

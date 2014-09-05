<?php

class TakePartVideoPlayerConfigurationController {

  public function create($values = array()) {
    return new TakePartVideoPlayerConfiguration($values);
  }

  public function createGlobalDefault($name = NULL) {
    return TakePartVideoPlayerConfiguration::createGlobalDefault($name);
  }

  public function loadByName($name) {
    $values = db_select('tp_video_player_configuration', 'c')
      ->fields('c')
      ->condition('name', $name, '=')
      ->range(0, 1)
      ->execute()
      ->fetchAssoc();
    if ($values !== FALSE) {
      return new TakePartVideoPlayerConfiguration($values);
    }
    return NULL;
  }

  public function save($configuration) {
    $values = $configuration->values();
    if (isset($values['id'])) {
      $configuration->updated_at = $values['updated_at'] = REQUEST_TIME;
      db_update('tp_video_player_configuration')
        ->fields($values)
        ->condition('id', $values['id'], '=')
        ->execute();
    }
    else {
      $configuration->created_at = $values['created_at'] = REQUEST_TIME;
      $configuration->updated_at = $values['updated_at'] = REQUEST_TIME;
      db_insert('tp_video_player_configuration')
        ->fields($values)
        ->execute();
      $configuration->id = Database::getConnection()->lastInsertId();
    }
  }

  public function merge($configurations) {
    $merged = new TakePartVideoPlayerConfiguration();
    foreach ($configurations as $configuration) {
      $merged->applyOverrides($configuration->values());
    }
    return $merged;
  }
}

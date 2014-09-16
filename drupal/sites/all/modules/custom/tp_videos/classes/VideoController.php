<?php

class TakePart_VideoController {

  public function create($values = array()) {
    return new TakePartVideo($values);
  }

  public function load($id) {
    $values = db_select('tp_video', 'v')
      ->fields('v')
      ->condition('id', $id, '=')
      ->range(0, 1)
      ->execute()
      ->fetchAssoc();
    if ($values !== FALSE) {
      $klass = $values['type'];
      if (class_exists($klass)) {
        return new $klass($values);
      }
    }
    return NULL;
  }

  public function loadByExternalKey($type, $key) {
    $values = db_select('tp_video', 'v')
      ->fields('v')
      ->condition('type', $type, '=')
      ->condition('external_key', $key, '=')
      ->range(0, 1)
      ->execute()
      ->fetchAssoc();
    if ($values !== FALSE) {
      $klass = $values['type'];
      if (class_exists($klass)) {
        return new $klass($values);
      }
    }
    return NULL;
  }

  public function loadPaginated($limit = 25) {
    $records = db_select('tp_video', 'v')
      ->fields('v')
      ->orderBy('updated_at', 'DESC')
      ->extend('PagerDefault')
      ->limit($limit)
      ->execute()
      ->fetchAllAssoc('id');
    $videos = array();
    foreach ($records as $id => $record) {
      $klass = $record->type;
      if (class_exists($klass)) {
        $videos[$id] = new $klass((array) $record);
      }
    }
    return $videos;
  }

  public function save($video) {
    $values = $video->values();
    if (isset($values['id'])) {
      $video->updated_at = $values['updated_at'] = REQUEST_TIME;
      db_update('tp_video')
        ->fields($values)
        ->condition('id', $values['id'], '=')
        ->execute();
    }
    else {
      $video->created_at = $values['created_at'] = REQUEST_TIME;
      $video->updated_at = $values['updated_at'] = REQUEST_TIME;
      db_insert('tp_video')
        ->fields($values)
        ->execute();
      $video->id = Database::getConnection()->lastInsertId();
    }
  }

  public function delete($video) {
    db_delete('tp_video')
      ->condition('id', $video->id, '=')
      ->execute();
  }
}

<?php
/**
 * @file
 * TakePart ad tag object.
 */

function takepart_ads_create_tag($values = array()) {
  $object = new StdClass();
  $values += array(
    'id' => NULL,
    'name' => NULL,
    'title' => NULL,
    'url' => NULL,
  );
  foreach ($values as $name => $value) {
    $object->{$name} = $value;
  }
  return $object;
}

function takepart_ads_load_tag($name) {
  $object = db_select('takepart_ads_tag', 't')
    ->fields('t')
    ->condition('name', $name, '=')
    ->isNotNull('name')
    ->range(0, 1)
    ->execute()
    ->fetchObject();
  // Use NULL for not found instead of FALSE.
  return $object !== FALSE ? $object : NULL;
}

function takepart_ads_load_tag_list() {
  $records = db_select('takepart_ads_tag', 't')
    ->fields('t')
    ->orderBy('title', 'ASC')
    ->execute()
    ->fetchAllAssoc('name');
  $values = array();
  foreach ($records as $id => $record) {
    $values[$id] = takepart_ads_create_tag((array) $record);
  }
  return $values;
}

function takepart_ads_save_tag($tag) {
  $values = (array) $tag;
  if (isset($values['id'])) {
    $tag->updated_at = $values['updated_at'] = REQUEST_TIME;
    db_update('takepart_ads_tag')
      ->fields($values)
      ->condition('id', $values['id'], '=')
      ->execute();
  }
  else {
    $tag->created_at = $values['created_at'] = REQUEST_TIME;
    $tag->updated_at = $values['updated_at'] = REQUEST_TIME;
    db_insert('takepart_ads_tag')
      ->fields($values)
      ->execute();
    $tag->id = Database::getConnection()->lastInsertId();
  }
}

function takepart_ads_delete_tag($tag) {
  if (is_object($tag)) { $tag = $tag->id; }
  db_delete('takepart_ads_tag')
    ->condition('id', $tag, '=')
    ->execute();
}

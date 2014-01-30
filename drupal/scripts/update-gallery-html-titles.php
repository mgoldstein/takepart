<?php

function read_metatag($nid) {
  $record = db_select('metatag', 'mt')
    ->fields('mt')
    ->condition('entity_type', 'node')
    ->condition('entity_id', $nid)
    ->execute()
    ->fetchObject();
  if ($record === FALSE) {
    $record = new StdClass();
    $record->entity_type = 'node';
    $record->entity_id = $nid;
    $record->data = serialize(array());
    $record->language = 'und';
    $record->is_new = TRUE;
  }
  else {
    $record->is_new = FALSE;
  }
  $record->data = unserialize($record->data);
  return $record;
}

function save_metatag($record) {
  $data = serialize($record->data);
  if ($record->is_new) {
    print "Inserting {$record->entity_id}\n";
    db_insert('metatag')
      ->fields(array(
        'entity_type' => $record->entity_type,
        'entity_id' => $record->entity_id,
        'data' => $data,
        'language' => $record->language,
      ))
      ->execute();
  }
  else {
    print "Updating {$record->entity_id}\n";
    db_update('metatag')
      ->fields(array(
        'data' => $data,
      ))
      ->condition('entity_type', 'node')
      ->condition('entity_id', $record->entity_id)
      ->execute();
  }
}

function node_titles() {
  $nodes = db_select('field_data_field_html_title', 'f')
    ->fields('f', array('entity_id', 'field_html_title_value'))
    ->condition('entity_type', 'node')
    ->condition('bundle', 'openpublish_photo_gallery')
    ->execute()
    ->fetchAllKeyed();
  $non_empty = array();
  foreach ($nodes as $id => $title) {
    if (strlen(trim($title)) > 0) {
      $non_empty[$id] = $title;
    }
  }
  return $non_empty;
}

foreach(node_titles() as $nid => $title) {
  $metatag = read_metatag($nid);
  if ($metatag->is_new) {
    $metatag->data = array(
      'title' => array('value' => "{$title} | [site:name]"),
    );
    save_metatag($metatag);
  }
  else { //if (!isset($metatag->data['title'])) {
    $metatag->data['title'] = array('value' => "{$title} | [site:name]");
    save_metatag($metatag);
  }
}

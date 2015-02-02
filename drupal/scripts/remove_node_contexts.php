<?php

function check_node($nid) { 
    $record = db_select('node', 'n')
            ->fields('n')
            ->condition('nid', $nid)
            ->execute()
            ->fetchObject();
    if ($record === FALSE) {
        echo 'node ' . $nid . ' not found' . "\r\n";
        delete_context($nid);
    } else {
        echo 'node ' . $nid . ' successfully found' . "\r\n";
    }
}

function delete_context($nid) {
    $context = 'context_field-node-' . $nid;
    sleep(1);
    $result = db_query("DELETE FROM {context} WHERE name = :name", array(':name' => $context));
    if ($result) {
        echo 'context ' . $context . ' deleted' . "\r\n";
    }
    else {
        echo 'attempt to delete context ' . $context . ' failed' . "\r\n";
    }
}

function context_names() {
    $nodes = db_select('context', 'c')
            ->fields('c', array('name'))
            ->condition('name', 'context_field-node-%', 'LIKE')
            ->execute()
            ->fetchAll();
    
    foreach ($nodes as $title) {
        $nid = substr($title->name, 19);
        check_node($nid);
    }
}

context_names();
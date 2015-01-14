<?php

function check_taxonomy($tid) { 
    $record = db_select('taxonomy_term_data', 't')
            ->fields('t')
            ->condition('tid', $tid)
            ->execute()
            ->fetchObject();
    if ($record === FALSE) {
        echo 'term ' . $tid . ' not found' . "\r\n";
        delete_taxonomy($nid);
    } else {
        echo 'term ' . $tid . ' successfully found as ' . $record-name . "\r\n";
    }
}

function delete_taxonomy($nid) {
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
            ->condition('name', 'context_field-taxonomy_term-%', 'LIKE')
            ->execute()
            ->fetchAll();
    
    foreach ($nodes as $title) {
        $tid = substr($title->name, 28);
        check_taxonomy($tid);
    }
}

context_names();
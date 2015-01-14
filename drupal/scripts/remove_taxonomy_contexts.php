<?php

function check_taxonomy($tid) { 
    $record = db_select('taxonomy_term_data', 't')
            ->fields('t')
            ->condition('tid', $tid)
            ->execute()
            ->fetchObject();
    if ($record === FALSE) {
        echo 'term ' . $tid . ' not found' . "\r\n";
        taxonomy_term_delete($tid);
    } else {
        echo 'term ' . $tid . ' successfully found as ' . $record-name . "\r\n";
    }
}

function get_context_names() {
    $nodes = db_select('context', 'c')
            ->fields('c', array('name'))
            ->condition('name', 'context_field-taxonomy_term-%', 'LIKE')
            ->execute()
            ->fetchAll();
    
    foreach ($nodes as $title) {
        sleep(1);
        $tid = substr($title->name, 28);
        check_taxonomy($tid);
    }
}

get_context_names();
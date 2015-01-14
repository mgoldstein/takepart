<?php

// define static var
define('DRUPAL_ROOT', getcwd());
// include bootstrap
include_once('./includes/bootstrap.inc');
// initialize stuff
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

function check_taxonomy($tid) { 
    $record = db_select('taxonomy_term_data', 't')
            ->fields('t')
            ->condition('tid', $tid)
            ->execute()
            ->fetchObject();
    if ($record === FALSE) {
        echo 'term ' . $tid . ' not found' . "\r\n";
        taxonomy_term_delete($tid);
        $increment = TRUE;
    } else {
        echo 'term ' . $tid . ' successfully found as ' . $record->name . "\r\n";
        $increment = FALSE;
    }
    return $increment;
}

function get_context_names() {
    $nodes = db_select('context', 'c')
            ->fields('c', array('name'))
            ->condition('name', 'context_field-taxonomy_term-%', 'LIKE')
            ->execute()
            ->fetchAll();
    $i = 0;
    foreach ($nodes as $title) {
        // sleep(1);
        $tid = substr($title->name, 28);
        $result = check_taxonomy($tid);
        if ($result) {
            $i++;
            echo 'Total terms removed = ' . $i . "\r\n";
        }
    }
}

get_context_names();
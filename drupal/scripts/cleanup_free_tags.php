<?php

/*
 * This script cleans up the free tag vocabulary by checking for free tags
 * (vid=4) created before July 2014 (created < 1404172800) that have
 * less than four nodes associated to that term. The script then deletes
 * all terms that match the criteria.
 */

// define static var
define('DRUPAL_ROOT', getcwd());
// include bootstrap
include_once('./includes/bootstrap.inc');
// initialize stuff
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

function delete_free_tags_with_few_nodes($limit) {
    $sql = "SELECT t.*, d.name, d.vid, count(t.nid) from taxonomy_index t "
            . "LEFT JOIN taxonomy_term_data d on t.tid = d.tid "
            . "WHERE 1 GROUP BY t.tid HAVING count(t.nid) < " . $limit . " "
            . "AND d.vid = 4 AND t.created < 1404172800 ORDER BY d.name";

    $results = db_query($sql);

    $i = 0;

    foreach ($results as $row) {
        $tid = $row->tid;
        taxonomy_term_delete($tid);
        $i++;
        echo $i . " Term #" . $tid . " \r\n";
    }
    echo "Free tags with less than " . $limit . " nodes deleted = " . $i . " \r\n";
    
    return $i;
}

function clear_empty_free_tags($subtotal) {
    $sql = "SELECT tid FROM taxonomy_term_data d "
            . "WHERE d.vid = 4 AND d.tid "
            . "NOT IN (SELECT t.tid FROM taxonomy_index t)";

    $results = db_query($sql);

    $i = 0;
    $j = $subtotal;

    foreach ($results as $row) {
        $tid = $row->tid;
        taxonomy_term_delete($tid);
        $i++;
        $j++;
        echo $i . " Term #" . $tid . " \r\n";
    }
    echo "Total empty free tags deleted = " . $i . " \r\n";
    echo "Total all free tags deleted = " . $j . " \r\n";
}

$subtotal = delete_free_tags_with_few_nodes(4);
clear_empty_free_tags($subtotal);
drupal_flush_all_caches();

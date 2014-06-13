<?php

/**
 * @file
 * takepart_publication_report.features.inc
 */

/**
 * Implements hook_views_api().
 */
function takepart_publication_report_views_api($module = NULL, $api = NULL) {
    return array(
        "api" => "3.0",
        "path" => drupal_get_path('module', 'takepart_publication_report'),
    );
}

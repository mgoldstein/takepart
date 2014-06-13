<?php

function _topic_search($array, $needle) {
    foreach ($array as $fields) {
        if ($fields['field'] === $needle) {
            return true;
        }
    }
    return false;
}

function takepart_publication_report_views_query_alter(&$view, &$query) {
    if ($view->name === 'publication_report') {
        if (_topic_search($query->where[1]['conditions'], "field_data_field_topic.field_topic_tid")) {
            $query->where[1]['conditions'][] = array(
                "field" => "field_data_field_topic.delta",
                "value" => "0",
                "operator" => "="
            );
        }
    }
}

/*
function takepart_publication_report_views_pre_execute(&$view) {
    if ($view->name == 'publication_report') {
        dpq($view->build_info['query']);
    }
}
*/
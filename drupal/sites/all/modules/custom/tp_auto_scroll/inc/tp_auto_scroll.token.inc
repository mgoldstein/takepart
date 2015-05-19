<?php

/* 
 * Token function (requires Token Function module) to generate node URL from
 * the node ID instead of the $_GET superglobal.
 */

function tp_auto_scroll_clean_url($nid) {
    if (!is_numeric($nid)) {
        return 'Not-A-Number';
    }
    $alias = url('node/' . $nid, array('absolute' => TRUE));
    return $alias;
}
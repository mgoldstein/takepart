<?php

function metatag_tab_token_info() {
    $info['types']['tab_metatags'] = array(
        'name' => t('Custom TAB'),
        'description' => t("Custom tokens for TAB metatags"),
    );

    $info['tokens']['tab_metatags']['topic_freetags'] = array(
        'name' => t('Topic and Free Tags'),
        'description' => t("Combines Topic and Free Tag values into "),
        'dynamic' => TRUE,
        'function' => array(
            'file' => drupal_get_path("module", "metatag_tab") . "/metatag_tab.token.inc",
            'function' => "metatag_tab_topic_freetags",
        ),
    );

    return $info;
}

function metatag_tab_topic_freetags($topic, $freetags = '') {
    $tag_array = array($topic);
    if ($freetags != '') {
        $ft_array=explode(",", $freetags);
        $tag_array = array_merge($tag_array, $ft_array);
    }
    $tag_str=implode(",", $tag_array);
    return rtrim($tag_str, ",");
}
<?php

function takepart_omniture_token_info() {
    $info['types']['tp_omniture'] = array(
        'name' => t('TakePart Omniture'),
        'description' => t("Tokens used for setting omniture variables"),
    );

    $info['tokens']['tp_omniture']['value_or_empty'] = array(
        'name' => t('Value or Empty'),
        'description' => t("Returns the token or empty string"),
        'dynamic' => TRUE,
        'function' => array(
            'file' => drupal_get_path("module", "takepart_omniture") . "/takepart_omniture.token.inc",
            'function' => "takepart_omniture_value_or_empty",
        ),
    );

    $info['tokens']['tp_omniture']['get_tab_uid'] = array(
        'name' => t('Get TAB user ID'),
        'description' => t('Retrieve the user\'s TAB ID, if set'),
        'dynamic' => TRUE,
        'function' => array(
            'file' => drupal_get_path("module", "takepart_omniture") . "/takepart_omniture.token.inc",
            'function' => "takeaction_tracking_get_guid",
        ),
    );

    $info['tokens']['tp_omniture']['get_author'] = array(
        'name' => t('Get Author'),
        'description' => t('Retrieve the node referenced authors for this node item'),
        'dynamic' => TRUE,
        'function' => array(
            'file' => drupal_get_path("module", "takepart_omniture") . "/takepart_omniture.token.inc",
            'function' => "takepart_omniture_get_author",
        ),
    );

    $info['tokens']['tp_omniture']['url_after_arg'] = array(
        'name' => t('Get URL after arg'),
        'description' => t('Retrieve the current URL beyond the arg provided.  e.g. http://example.com/article/1999/myblog/12'),
        'dynamic' => TRUE,
        'function' => array(
            'file' => drupal_get_path("module", "takepart_omniture") . "/takepart_omniture.token.inc",
            'function' => "takepart_omniture_url_after_arg",
        ),
    );

    $info['tokens']['tp_omniture']['str_decode'] = array(
        'name' => t('HTML entity decode'),
        'description' => t('Process token with html_entity_decode function.'),
        'dynamic' => TRUE,
        'function' => array(
            'file' => drupal_get_path("module", "takepart_omniture") . "/takepart_omniture.token.inc",
            'function' => "takepart_omniture_str_decode",
        ),
    );

    $info['tokens']['tp_omniture']['lowercase'] = array(
        'name' => t('Lowercase'),
        'description' => t('Set the value to all lowercase.'),
        'dynamic' => TRUE,
        'function' => array(
            'file' => drupal_get_path("module", "takepart_omniture") . "/takepart_omniture.token.inc",
            'function' => "takepart_omniture_lowercase",
        ),
    );

    $info['tokens']['tp_omniture']['first_word'] = array(
        'name' => t('Grab the first word'),
        'description' => t('Grab the first word with html_entity_decode function.'),
        'dynamic' => TRUE,
        'function' => array(
            'file' => drupal_get_path("module", "takepart_omniture") . "/takepart_omniture.token.inc",
            'function' => "takepart_omniture_first_word",
        ),
    );

    $info['tokens']['tp_omniture']['date'] = array(
        'name' => t('date YYYY/MM/DD'),
        'description' => t('Put date into YYYY/MM/DD format.'),
        'dynamic' => TRUE,
        'function' => array(
            'file' => drupal_get_path("module", "takepart_omniture") . "/takepart_omniture.token.inc",
            'function' => "takepart_omniture_date",
        ),
    );

    $info['tokens']['tp_omniture']['urldecode'] = array(
        'name' => t('urldecode'),
        'description' => t('call urldecode() on param.'),
        'dynamic' => TRUE,
        'function' => array(
            'file' => drupal_get_path("module", "takepart_omniture") . "/takepart_omniture.token.inc",
            'function' => "takepart_omniture_urldecode",
        ),
    );

    $info['tokens']['tp_omniture']['get_first_photo_title'] = array(
        'name' => t('Get First Photo Title'),
        'description' => t('Retrieve the title of the first photo in a gallery'),
        'dynamic' => TRUE,
        'function' => array(
            'file' => drupal_get_path("module", "takepart_omniture") . "/takepart_omniture.token.inc",
            'function' => "takepart_omniture_first_photo_title",
        ),
    );

    $info['tokens']['tp_omniture']['campaign_context'] = array(
        'name' => t('Get campaign context'),
        'description' => t('Get the name of the campaign this page belongs to'),
        'dynamic' => TRUE,
        'function' => array(
            'file' => drupal_get_path("module", "takepart_omniture") . "/takepart_omniture.token.inc",
            'function' => "takepart_omniture_campaign",
        ),
    );

    return $info;
}

function takepart_omniture_first_word($str) {
    $content_type_array = explode(" ", $str);
    return html_entity_decode($content_type_array[0], ENT_QUOTES);
}

function takepart_omniture_tab_uid($param) {
    $guid = FALSE;
    $from_db = FALSE;

    $cookie = variable_get('takeaction_action_cookie_name', 'TAKEACTIONGUID');
    $lifespan = variable_get('takeaction_action_cookie_lifespan', 0);
    $expire = empty($lifespan) ? 0 : time() + $lifespan;
    $path = variable_get('takeaction_action_cookie_path', '/');
    $domain = variable_get('takeaction_action_cookie_domain', '.takepart.com');

    // Check for a GUID tied to a logged in user.
    if (!empty($param)) {
        try {
            $result = db_select('takeaction_tracking_action_guid', 'g')
                    ->fields('g', array('uid', 'guid'))
                    ->condition('g.uid', $param, '=')
                    ->execute()
                    ->fetchAllKeyed();
            if (!empty($result)) {
                $guid = $result[$param];
                $from_db = TRUE;
                setcookie($cookie, $guid, $expire, $path, $domain);
            }
        } catch (Exception $e) {
            watchdog('takepart_omniture', 'Message: ' . $e->getMessage());
        }
    }

    // Check for an already set cookie.
    if (empty($guid) && !empty($_COOKIE[$cookie])) {
        $regex = '/^[0-9A-F]{8}(\-[0-9A-F]{4}){3}\-[0-9A-F]{12}$/';
        if (preg_match($regex, $_COOKIE[$cookie])) {
            $guid = $_COOKIE[$cookie];
        }
    }

    // If we still don't have a GUID generate one and set it.
    if (empty($guid)) {
        mt_srand((double) microtime() * 10000);
        $hash = strtoupper(md5(uniqid(rand(), TRUE)));
        $guid = implode('-', array(
            substr($hash, 0, 8),
            substr($hash, 8, 4),
            substr($hash, 12, 4),
            substr($hash, 16, 4),
            substr($hash, 20, 12),
                ));
        setcookie($cookie, $guid, $expire, $path, $domain);
    }

    // Tie the action GUID to the UID if it isn't already tied.
    if (!empty($param) && !$from_db) {
        try {
            db_insert('takeaction_tracking_action_guid')
                    ->fields(array(
                        'uid' => $param,
                        'guid' => $guid,
                        'created' => time(),
                    ))
                    ->execute();
        } catch (Exception $e) {
            watchdog('takepart_omniture', 'Message: ' . $e->getMessage());
        }
    }

    return $guid;
}

function takepart_omniture_value_or_empty($param) {
    // if param wrapped in brakets [], then token was not
    // found, just return empty string.
    $param = html_entity_decode($param, ENT_QUOTES);
    return preg_replace('/^\[[\w].*\]$/', '', $param);
}

function takepart_omniture_first_photo_title($nid) {

    if (!is_numeric($nid)) {
        return 'Not-A-Number';
    }

    $gallery = node_load($nid);
    $galTitle = $gallery->title;
    $file = $gallery->field_gallery_images['und'][0]['fid'];
    $photo = file_load($file);
    $photoTitle = $photo->field_image_title['und'][0]['safe_value'];
    return $galTitle . ': ' . $photoTitle;
}

/**
 * $nid - the node id
 * since entity field kills the system, find our own authors
 */
function takepart_omniture_get_author($nid) {
    if (!is_numeric($nid))
        return 'Not-A-Number';

    $query = db_select('field_data_field_author', 'a');
    $query->addField('a', 'field_author_nid');
    $query->condition('a.entity_id', $nid);

    $query->join('field_data_field_profile_last_name', 'fpl', 'a.field_author_nid = fpl.entity_id');
    $query->join('field_data_field_profile_first_name', 'fpf', 'a.field_author_nid = fpf.entity_id');
    $query->addField('fpl', 'field_profile_last_name_value', 'last_name');
    $query->addField('fpf', 'field_profile_first_name_value', 'first_name');
    $query->orderBy('last_name', 'ASC')->orderby('first_name', 'ASC');

    $result = $query->execute();

    $authors = array();
    foreach ($result as $record) {
        //$authors[] = $record->last_name ."-". $record->first_name ."-". $record->field_author_nid;
        $authors[] = trim($record->first_name) . " " . trim($record->last_name);
    }
    return implode('; ', $authors);
}

/**
 * provide the current_path token as the path.
 * get the current path and based on the given arg position,
 * skip those positions and return whats left of the url path.
 *       index:     0/   1/   2/   3/   4/      5
 * so, path: /article/blog/test/2011/1110/my-blog
 *
 * called with index 3 would return: 1110/my-blog
 */
function takepart_omniture_url_after_arg($path, $index = 0) {
    if (!is_numeric($index)) {
        return $path;
    }

    $path_arr = explode("/", $path);

    if ($index > count($path_arr)) {
        return $path;
    }

    for ($i = 0; $i <= $index; $i++) {
        $parts = array_shift($path_arr);
    }
    $clipped = implode('/', $path_arr);
    return $clipped;
}

/**
 * run string through html_entity_decode
 *
 */
function takepart_omniture_str_decode($str) {
    return html_entity_decode($str, ENT_QUOTES);
}

function takepart_omniture_lowercase($str) {
    return strtolower($str);
}

/**
 * built in date token with custom formatter was not working.
 */
function takepart_omniture_date($date_str) {
    return date('Y/m/d', $date_str);
}

/**
 * run $url through urldecode()
 */
function takepart_omniture_urldecode($url) {
    return urldecode($url);
}

function takepart_omniture_campaign($nid) {
    if (!is_numeric($nid)) {
        return 'Not-A-Number';
    }
    $node = node_load($nid);
    if (isset($node->field_multi_page_campaign['und'][0]['context']) && $node->field_multi_page_campaign['und'][0]['context'] != '') {
        $campaign_context_name = $node->field_multi_page_campaign['und'][0]['context'];
        $context = context_load($campaign_context_name);
        if ($context->description != '') {
            $campaign_name = $context->description;
        } else {
            $campaign_name = $campaign_context_name;
        }
    } else if ($node->type == 'takepart_campaign') {
        $campaign_name = $node->title;
    } else {
        $campaign_name = '';
    }
    return $campaign_name;
}
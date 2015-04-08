<?php

/**
 * @file
 * View template to render view fields as XML.
 *
 * - $view: The view in use.
 * - $rows: Array of row objects as rendered by _views_json_render_fields
 * - $attachment: not used currently
 * - $options: The options for the style passed in from the UI.
 *
 * @ingroup views_templates
 * @see views_xml.views.inc
 */
function _build_list_for_yahoo_rss_feed($content) {
    $parts = explode(',,,', $content);
    $ret = '';
    foreach ($parts as $part) {
        $part = trim($part);
        if ($part) {
            $ret .= '<p><strong>&bull; ' . $part . '</strong></p>';
        }
    }
    if ($ret) {
        return $ret;
    }
    return '';
}

/**
 * Template preprocess for RSS w/ Images
 * @param $vars
 * @return unknown_type
 *
  $options = parent::option_definition();
  $options['schema'] = array('default' => 'raw', 'translatable' => FALSE);
  $options['escape_as_CDATA'] = array('default' => 'no', 'translatable' => FALSE);
  $options['content_type'] = array('default' => 'text/xml', 'translatable' => FALSE);
 *
 */
function template_preprocess_views_views_takepart_rss_style_rssimages(&$vars) {
    $rows = $vars["rows"];
    $options = $vars["options"];
    $xml = "<?xml version=\"1.0\" encoding=\"utf-8\"?" . ">\n";
    $xml .= "<rss version=\"2.0\"";
    $xml .= " xmlns:content=\"http://purl.org/rss/1.0/modules/content/\">\n";
    $xml .= "\t<channel>\n";
    $xml .= "\t<title>TakePart</title>\n";
    $xml .= "\t<link>" . _takepart_rss_selfURL() . "</link>\n";
    $xml .= "\t<description>Stories That Matter, Action That Counts</description>\n";
    $xml .= "\t<language>en-us</language>\n";
    foreach ($rows as $row) {
        $xml .= "\t\t<item>\n";
        $content = '';
        $related_content = '';
        
        foreach ($row as $id => $object) {
            if ($id === 'created') {
                $xml .= "\t\t\t<pubDate><![CDATA[" . $object->content . "]]></pubDate>\n";
            } elseif ($id === 'title') {
                $headline = (array_key_exists('field_flashcard_page_headline', $row) ?
                                $row['field_flashcard_page_headline']->content :
                                $object->raw);
                $xml .= "\t\t\t<title><![CDATA[" . $headline . "]]></title>\n";
                $poslink = _takepart_rss_parseHref($object->content);
                if ($poslink) {
                    $xml .= "\t\t\t<link><![CDATA[" . $poslink . "]]></link>\n";
                    $xml .= "\t\t\t<guid isPermaLink=\"true\">" . $poslink . "</guid>\n";
                }
            } elseif ($id === 'field_author') {
                $xml .= "\t\t\t<author><![CDATA[" . $object->content . "]]></author>\n";
            } elseif ($id === 'field_display_tag' && $object->content != '') {
                $xml .= "\t\t\t<category><![CDATA[" . $object->content . "]]></category>\n";
            } elseif ($id === 'field_article_subhead' && $object->content != '' ||
                    $id == 'field_subhead' && $object->content != '') {
                $xml .= "\t\t\t<description><![CDATA[" . $object->content . "]]></description>\n";
            } elseif ($id == 'field_thumbnail' && $object->content != '') {
                $thumb = file_load($object->content);
                $xml .= "\t\t\t" . '<enclosure url="' . image_style_url("large", $thumb->uri) .
                        '" length="' . $thumb->filesize . '" type="' .
                        $thumb->filemime . '" />' . "\n";
            } elseif ($id == 'field_article_main_image' && $object->content != '') {
                preg_match('/(alt|title|src)="(?P<value>[^"]*)"/i', $object->content, $result);
                $head = array_change_key_case(get_headers($result['value'], TRUE));
                $xml .= "\t\t\t" . '<enclosure url="' . $result['value'] .
                        '" length="' . $head['content-length'] . '" type="' .
                        image_type_to_mime_type(exif_imagetype($result['value'])) . '" />' . "\n";
            } elseif ($id == 'field_related_stories' && $object->content != '') {
                $related_content .= _build_list_for_yahoo_rss_feed($object->content) . "\n\n";
            } elseif ($id == 'inline_content_embedded' && $object->content != '') {
                $related_content .= _build_list_for_yahoo_rss_feed($object->content) . "\n\n";
            } elseif ($id = 'body' && $object->content != '') {
                $content = $object->content;
            }
        }
        if ($related_content) {
            $content .= "\n\n<nav><h2><strong>Related stories on TakePart:</strong></h2><br/>\n\n" . $related_content . '</nav>';
        }
        $protocol = _takepart_rss_strleft(strtolower($_SERVER["SERVER_PROTOCOL"]), "/") . $s;
        $port = ($_SERVER["SERVER_PORT"] == "80") ? "" : (":" . $_SERVER["SERVER_PORT"]);
        $urlprefix = $protocol . "://" . $_SERVER['SERVER_NAME'] . $port;
        $content = preg_replace('#(href|src)="([^:"]*)(?:")#', '$1="' . $urlprefix . '$2"', $content);
        if ($content != '') {
            $xml .= "\t\t\t<content:encoded><![CDATA[" . str_replace('<hr>', '', $content) . "]]></content:encoded>\n";
        }
        $xml .= "\t\t</item>\n";
    }
    $xml .= "\t</channel>\n";
    $xml .= "</rss>";
    $vars["xml"] = $xml;
}

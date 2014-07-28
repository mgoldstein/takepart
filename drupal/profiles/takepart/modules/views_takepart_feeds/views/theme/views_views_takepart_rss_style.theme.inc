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
    $xml .= "  xmlns:dc=\"http://purl.org/dc/elements/1.1/\"";
    $xml .= "  xmlns:content=\"http://purl.org/rss/1.0/modules/content/\"";
    $xml .= "  xmlns:admin=\"http://webns.net/mvcb/\"";
    $xml .= "  xmlns:rdf=\"http://www.w3.org/1999/02/22-rdf-syntax-ns#\">\n";
    $xml .= "\t<channel>\n";

    // Titles will change depending on the type of content selected:
    /* foreach ($table_queue as $titles) {
      if ($titles['alias'] == 'node') {
      // @todo: what should the title / desc be if the view is being joined to a node?
      // $node = node_load($termid);
      // $title .= $node->title;
      }

      if (substr($titles['alias'], 0, 16) == 'field_data_field') {
      // if we're joining against taxonomy, pull the title out:
      $fieldname = substr($titles['alias'], 17, strlen($titles['alias']));
      // @todo: null check this:
      $termid = $vars['view']->args[0];
      // find titles based on the parent field and id argument when the arg is taxonomy:
      $terms = _takepart_rss_get_taxonomy_title($fieldname, $termid);

      foreach ($terms as $term) {
      $title .= $term->name;
      $description .= $term->description;
      }
      }
      } */

    // @todo: add check for $options['escape_as_CDATA'] == 'yes')
    $xml .= "\t<title><![CDATA[" . $options['title'] . $title . "]]></title>\n";
    $xml .= "\t<link>" . _takepart_rss_selfURL() . "</link>\n";
    // $xml .= "\t<description><![CDATA[" . $description . "]]></description>\n";
    dd($vars['view']->current_display);
    /*
      $view = $vars['view'];
      foreach ($view as $key => $value) {
      dd($key . ":" . $value . "\n");
      }
     */
    foreach ($rows as $row) {
        $xml .= "\t\t<item>\n";
        $content = '';
        $related_content = '';
        foreach ($row as $id => $object) {
            if ($id === 'published_at') {
                $xml .= "\t\t\t<pubDate><![CDATA[" . $object->content . "]]></pubDate>\n";
            } elseif ($id === 'title') {
                $headline = (array_key_exists('field_flashcard_page_headline', $row) ?
                                $row['field_flashcard_page_headline']->content :
                                $object->raw);
                $xml .= "\t\t\t<title><![CDATA[" . $headline . "]]></title>\n";
                $poslink = _takepart_rss_parseHref($object->content);
                if ($poslink) {
                    $xml .= "\t\t\t<link><![CDATA[" . $poslink . "]]></link>\n";
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

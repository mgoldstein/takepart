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
  $xml .= " xmlns:content=\"http://purl.org/rss/1.0/modules/content/\"";
  $xml .= " xmlns:wfw=\"http://wellformedweb.org/CommentAPI/\"";
  $xml .= " xmlns:dc=\"http://purl.org/dc/elements/1.1/\"";
  $xml .= " xmlns:atom=\"http://www.w3.org/2005/Atom\"";
  $xml .= " xmlns:sy=\"http://purl.org/rss/1.0/modules/syndication/\"";
  $xml .= " xmlns:slash=\"http://purl.org/rss/1.0/modules/slash/\"";
  $xml .= " xmlns:georss=\"http://www.georss.org/georss\"";
  $xml .= " xmlns:geo=\"http://www.w3.org/2003/01/geo/wgs84_pos#\"";
  $xml .= " xmlns:media=\"http://search.yahoo.com/mrss/\"";
  $xml .= ">\n";
  $xml .= "\t<channel>\n";
  $xml .= "\t<title>" . _takepart_rss_FeedTitle($vars['view']->args[0]) . "</title>\n";
  $xml .= "\t<link>http://www.takepart.com</link>\n";
  $xml .= "\t<atom:link href=\"" . _takepart_rss_selfURL() . "\" rel=\"self\" />\n";
  $xml .= "\t<description>Stories That Matter, Action That Counts</description>\n";
  $xml .= "\t<lastBuildDate>" . _takepart_rss_LastUpdated($vars['view']->result[0]->node_created) . "</lastBuildDate>\n";
  $xml .= "\t<language>en</language>\n";
  $xml .= "\t<copyright>Copyright " . date("Y") . " TakePart, LLC</copyright>\n";
  $xml .= "\t<webMaster>support@takepart.com (https://www.takepart.com/contact-us)</webMaster>\n";
  $xml .= "\t<image>\n";
  $xml .= "\t\t<title>TakePart</title>\n";
  $xml .= "\t\t<url>http://www.takepart.com/sites/all/themes/tp4/images/takepart_logo.png</url>\n";
  $xml .= "\t\t<link>http://www.takepart.com</link>\n";
  $xml .= "\t</image>\n";

  foreach ($rows as $row) {
    $xml .= "\t\t<item>\n";
    $content = '';
    $related_content = '';

    foreach ($row as $id => $object) {
	 if ($id === 'created') {
	   $xml .= "\t\t\t<pubDate>" . $object->content . "</pubDate>\n";
	 } elseif ($id === 'title') {
	   $headline = (array_key_exists('field_flashcard_page_headline', $row) ?
		  $row['field_flashcard_page_headline']->content :
		  $object->raw);
	   $xml .= "\t\t\t<title><![CDATA[" . $headline . "]]></title>\n";
	   $poslink = _takepart_rss_parseHref($object->content); // . "?cmpid=tp-rss";
	   if ($poslink) {
		$xml .= "\t\t\t<link>" . $poslink . "?cmpid=tp-rss</link>\n";
		$xml .= "\t\t\t<guid isPermaLink=\"false\">" . $poslink . "</guid>\n";
		$xml .= "\t\t\t<comments>" . $poslink . "#article-comments</comments>\n";
	   }
	 } elseif ($id === 'field_author') {
	   $xml .= "\t\t\t<dc:creator>" . $object->content . "</dc:creator>\n";
	   $xml .= "\t\t\t<author>" . $object->content . "</author>\n";
	 } elseif (($id === 'field_article_subhead' && $object->content != '') ||
	   ($id == 'field_subhead' && $object->content != '')) {
	   $xml .= "\t\t\t<description><![CDATA[" . $object->content . "]]></description>\n";
	 } elseif ($id === 'field_topic' && $object->content != '') {
	   $xml .= _build_category_nodes($object->content);
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

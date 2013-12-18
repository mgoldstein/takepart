<?php
/**
 * @file
 * takepart_gallery.box.inc
 */

/**
 * Implements hook_default_box().
 */
function takepart_gallery_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-3981ef30';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Ad - Right Rail Top';
  $box->options = array(
    'body' => '<script type=\'text/javascript\'>
GA_googleFillSlot("TP3_Home_RR_ATF_300x250");
</script>',
  );
  $export['box-3981ef30'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-6ab3a933';
  $box->plugin_key = 'simple';
  $box->title = 'Must Reads';
  $box->description = 'Right Rail Amazon General Reading List';
  $box->options = array(
    'body' => '<p>Editors\' choice books for a better world.</p><OBJECT classid="clsid:D27CDB6E-AE6D-11cf-96B8-444553540000" codebase="http://fpdownload.macromedia.com/get/flashplayer/current/swflash.cab" id="Player_6bd8aa4e-299a-40f5-b6d7-b0d927d5c1e0"  WIDTH="300px" HEIGHT="275px"> <param name="wmode" value="window"><PARAM NAME="movie" VALUE="http://ws.amazon.com/widgets/q?rt=tf_ssw&ServiceVersion=20070822&MarketPlace=US&ID=V20070822%2FUS%2Fparticiproduc-20%2F8003%2F6bd8aa4e-299a-40f5-b6d7-b0d927d5c1e0&Operation=GetDisplayTemplate"><PARAM NAME="quality" VALUE="high"><PARAM NAME="bgcolor" VALUE="#FFFFFF"><PARAM NAME="allowscriptaccess" VALUE="always"><embed src="http://ws.amazon.com/widgets/q?rt=tf_ssw&ServiceVersion=20070822&MarketPlace=US&ID=V20070822%2FUS%2Fparticiproduc-20%2F8003%2F6bd8aa4e-299a-40f5-b6d7-b0d927d5c1e0&Operation=GetDisplayTemplate" id="Player_6bd8aa4e-299a-40f5-b6d7-b0d927d5c1e0" quality="high" bgcolor="#ffffff" name="Player_6bd8aa4e-299a-40f5-b6d7-b0d927d5c1e0" allowscriptaccess="always"  type="application/x-shockwave-flash" align="middle" height="250px" width="275px"></embed></OBJECT> <NOSCRIPT><A HREF="http://ws.amazon.com/widgets/q?rt=tf_ssw&ServiceVersion=20070822&MarketPlace=US&ID=V20070822%2FUS%2Fparticiproduc-20%2F8003%2F6bd8aa4e-299a-40f5-b6d7-b0d927d5c1e0&Operation=NoScript">Amazon.com Widgets</A></NOSCRIPT>',
  );
  $export['box-6ab3a933'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-7d1ce087';
  $box->plugin_key = 'view';
  $box->title = 'TakePart Pics';
  $box->description = 'Popular Galleries';
  $box->options = array(
    'view' => 'photo_galleries--block',
    'settings' => array(
      'nid' => '36233+36151+36369',
    ),
    'view_object' => NULL,
    'view_more_text' => '',
    'view_more_link' => '',
    'expose_filters' => 0,
    'additional_classes' => '',
  );
  $export['box-7d1ce087'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-7fdc48e2';
  $box->plugin_key = 'field';
  $box->title = '';
  $box->description = 'Gallery Header';
  $box->options = array(
    'entity_type' => 'node',
    'entity_id' => '',
    'bundle' => 'openpublish_photo_gallery',
    'field' => array(
      'field_subhead' => 'field_subhead',
      'field_author' => 'field_author',
      'body' => 0,
      'field_gallery_images' => 0,
      'field_gallery_main_image' => 0,
      'field_free_tag' => 0,
      'field_thumbnail' => 0,
      'field_topic' => 0,
      'field_display_tag' => 0,
      'field_promo_headline' => 0,
      'field_promo_text' => 0,
      'field_series' => 0,
      'field_related_content' => 0,
      'field_related_actions' => 0,
      'field_suggest_content' => 0,
      'field_suggest_actions' => 0,
      'field_multi_page_campaign' => 0,
      'field_photo_gallery_slideshow' => 0,
    ),
    'use_page' => 1,
    'exclude_from_content' => 0,
    'view_mode' => 'default',
  );
  $export['box-7fdc48e2'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-944fcfe9';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Fix Facebook modal z-index';
  $box->options = array(
    'body' => '<style type="text/css">
.fb_iframe_widget_lift {
z-index:5000;
}
</style>',
    'additional_classes' => '',
    'selected_style' => '0',
  );
  $export['box-944fcfe9'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-e15d1292';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Take Action Button - Galleries';
  $box->options = array(
    'body' => '<div class="takepart-take-action" data-size="medium"></div>',
    'additional_classes' => 'tab-gallery',
  );
  $export['box-e15d1292'] = $box;

  return $export;
}

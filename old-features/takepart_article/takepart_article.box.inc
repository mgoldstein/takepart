<?php
/**
 * @file
 * takepart_article.box.inc
 */

/**
 * Implements hook_default_box().
 */
function takepart_article_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-15362653';
  $box->plugin_key = 'field';
  $box->title = '';
  $box->description = 'Series Graphic Header - Taxonomy';
  $box->options = array(
    'entity_type' => 'taxonomy_term',
    'entity_id' => '',
    'bundle' => '0',
    'field' => array(
      'field_series_graphic_header' => 'field_series_graphic_header',
      'field_series_context' => 0,
      'field_blog_branding_image' => 0,
      'field_blog_override' => 0,
      'field_free_tag_context' => 0,
      'field_topic_featured_quick_study' => 0,
      'field_topic_context' => 0,
      'field_topic_override' => 0,
      'field_blog_view' => 0,
      'field_feature_video' => 0,
      'field_video_series_context' => 0,
      'field_html_title' => 0,
      'field_series_graphic_header_link' => 0,
    ),
    'use_page' => 1,
    'exclude_from_content' => 0,
    'view_mode' => 'default',
  );
  $export['box-15362653'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-34ee1b08';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Outbrain Recommendation Content Widget';
  $box->options = array(
    'body' => '<script type="text/javascript" src="http://w.takepart.com/links/scripts/links.js"></script>',
    'additional_classes' => '',
    'selected_style' => '0',
  );
  $export['box-34ee1b08'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-9753089b';
  $box->plugin_key = 'field';
  $box->title = '';
  $box->description = 'Article Header';
  $box->options = array(
    'entity_type' => 'node',
    'entity_id' => '',
    'bundle' => 'openpublish_article',
    'field' => array(
      'field_article_subhead' => 'field_article_subhead',
      'field_author' => 'field_author',
      'field_article_main_image' => 'field_article_main_image',
      'body' => 0,
      'field_free_tag' => 0,
      'field_thumbnail' => 0,
      'field_topic' => 0,
      'field_article_action' => 0,
      'field_display_tag' => 0,
      'field_promo_headline' => 0,
      'field_promo_text' => 0,
      'field_series' => 0,
      'field_related_content' => 0,
      'field_related_actions' => 0,
      'field_suggest_campaigns' => 0,
      'field_suggest_content' => 0,
      'field_related_campaigns' => 0,
      'field_suggest_actions' => 0,
      'field_multi_page_campaign' => 0,
    ),
    'use_page' => 1,
    'exclude_from_content' => 0,
    'view_mode' => 'default',
  );
  $export['box-9753089b'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-b7c16541';
  $box->plugin_key = 'view';
  $box->title = 'Similar Campaigns';
  $box->description = 'Related Campaigns';
  $box->options = array(
    'view' => 'related_campaigns--block_1',
    'settings' => array(
      'null' => '132+28',
      'tid' => '',
    ),
    'view_object' => NULL,
    'view_more_text' => '',
    'view_more_link' => '',
    'additional_classes' => '',
  );
  $export['box-b7c16541'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-bedd1fbb';
  $box->plugin_key = 'simple';
  $box->title = 'TakePart Video';
  $box->description = 'Right Rail -- TPL Playlist';
  $box->options = array(
    'body' => '<br />
<script type="text/javascript" src="http://video.takepart.com/players/Y0y8DVG4-TPXPTQu4.js"></script>',
    'additional_classes' => '',
  );
  $export['box-bedd1fbb'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-c49bfd54';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Featured Contributors Module';
  $box->options = array(
    'body' => '<div style="width: 272px">
	<p>
	<img src="http://www.takepart.com/sites/default/files/featuredcontributors1.gif" alt="Featured Contributers" />
	</p>

<h2><span>Laura Bridgeman</span></h2>
	
	<div class="views-field views-field-field-thumbnail">
		<div class="field-content" style="padding: 5px 5px 10px 0;">
		<a href="http://www.takepart.com/author/laura-bridgeman" target="_self"><img src="http://www.takepart.com/sites/default/files/Laura_Bridgeman_70ss.jpg" alt="Laura Bridgeman" /></a>
	
			<div class="views-field views-field-field-promo-headline" style="float:right;  width:140px; padding: 0px 15px 0 0; font-size:14px"">
			<a href="http://www.takepart.com/article/2013/09/11/dolphin-intelligence-dumb-chickens-cetaceans" target="_self">Don\'t Believe the Lies You Hear About Dolphin Intelligence</a>
</a>

			</div>
		</div>
	</div>


<h2><span>Jennifer Feuerstein</span></h2>
	
	<div class="views-field views-field-field-thumbnail">
		<div class="field-content" style="padding: 5px 5px 10px 0;">
		<a href="http://www.takepart.com/author/jennifer-feuerstein" target="_self"><img src="http://www.takepart.com/sites/default/files/jennifer_Feuerstein.jpg" alt="Jennifer Feuerstein" /></a>
	
			<div class="views-field views-field-field-promo-headline" style="float:right;  width:140px; padding: 0px 15px 0 0; font-size:14px"">
			<a href="http://www.takepart.com/article/2013/09/02/chimp-island-chrissy-movies-entertainment-recovery" target="_self">Reason Number One Why Chimps Should Never Act in Movies</a>
</a>

			</div>
		</div>
	</div>


<h2><span>Alanna Mallon</span></h2>
	
	<div class="views-field views-field-field-thumbnail">
		<div class="field-content" style="padding: 5px 5px 10px 0;">
		<a href="http://www.takepart.com/author/alanna-mallon" target="_self"><img src="http://www.takepart.com/sites/default/files/Alanna-Mallon_0.jpg" alt="Alanna Mallon" /></a>
	
			<div class="views-field views-field-field-promo-headline" style="float:right;  width:140px; padding: 0px 15px 0 0; font-size:14px"">
			<a href="http://www.takepart.com/article/2013/08/26/op-ed-school-backpack-food-program-cambridge" target="_self">Facing the Hunger Crisis in Cambridge</a>
</a>

			</div>
		</div>
	</div>
</div>',
    'additional_classes' => '',
  );
  $export['box-c49bfd54'] = $box;

  return $export;
}
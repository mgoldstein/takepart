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
  $box->title = 'TakePart Tastemakers';
  $box->description = 'Right Rail -- TakePart Takes On';
  $box->options = array(
    'body' => '<div id="youtube_block" class="rr-preview">
  <div style="line-height: 12px;">&nbsp;</div>
  <img src="http://img.youtube.com/vi/oiY_UxZJMSM/mqdefault.jpg" width="275" height="155" />
  <div style="line-height: 5px;">&nbsp;</div>
  <strong><a href="http://www.youtube.com/embed/oiY_UxZJMSM">Read more and take action here.</a></strong>
  <a class="colorbox-inline" href="?width=870&amp;height=420&amp;inline=true#oiY_UxZJMSM"><div class="rr-preview-arrow"></div></a>
</div>
<div class="vidpop-overlay">
  <div id="oiY_UxZJMSM"><div class=\'rightrail-video-popup clearfix node-embedded vidpop-popup\' >
  <div class="inner-wrapper">
        <div class="contents">
      <div class="leftside">
        <div class="vidpop-popup right-rail-vidpop" style="height: 360px; width: 640px;">
  <iframe width="640" height="411" frameborder="0" type="text/html" class="youtube-player right-rail-vidpop-iframe" src="http://www.youtube.com/embed/oiY_UxZJMSM?version=3&amp;wmode=opaque" style="height: 360px; width: 640px;"></iframe>
</div>      </div>
      <div class="rightside">
        <div class="field-name-field-promo-headline">TakePart Tastemakers</div>
        <!-- subscribe button -->
        <div class="subscribe"><a target="_blank" href="http://www.youtube.com/subscription_center?add_user_id=FYRWsIH2BivGa_-2LVTsBA&amp;feature=creators_cornier-http%3A//s.ytimg.com/yt/img/creators_corner/Subscribe_to_my_videos/YT_Subscribe_160x27_red.png"><img alt="Subscribe to me on YouTube" src="http://s.ytimg.com/yt/img/creators_corner/Subscribe_to_my_videos/YT_Subscribe_160x27_red.png" /></a></div>

        <div id="vidpop-social" class="social-links">
          <div class="addthis_toolbox addthis_default_style">
            <a class="addthis_button_facebook_like"
               addthis:url=""
               fb:like:href="<?php echo url(NULL, array('absolute' => TRUE)); ?>"
               fb:like:action="like"
               fb:like:layout="button_count"></a>
            <a class="addthis_button_tweet"
               tw:counturl=""
               tw:count="horizontal"
               tw:url=""
               tw:text=""
               tw:via="TakePart"
               tw:title="Tweet"></a>
            <a class="addthis_button_email"
               title="Email"
               addthis:url=""></a>
          </div>
        </div>
        <div class="comment-link"></div>
      </div>
    </div>
  </div>
</div>
</div>
</div>',
    'additional_classes' => 'video-popup',
    'selected_style' => '0',
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

	<h2><span>Stephanie McMillan</span></h2>
	
	<div class="views-field views-field-field-thumbnail">
		<div class="field-content" style="padding: 5px 5px 10px 0;">
		<a href="http://www.takepart.com/author/stephanie-mcmillan" target="_self"><img src="http://www.takepart.com/sites/default/files/stephmcmillan70x70.jpeg" alt="Stephanie McMillan" /></a>
	
			<div class="views-field views-field-field-promo-headline" style="float:right;  width:140px; padding: 0px 15px 0 0; font-size:14px"">
			<a href="http://www.takepart.com/article/2012/12/05/op-ed-haitis-garment-workers-look-america-solidarity" target="_self">Hait\'s Garment Workers Join the Worldwide Fight Against Sweatshop Abuse</a>

			</div>
		</div>
	</div>


	<h2><span>Karen Blessen</span></h2>
	
	<div class="views-field views-field-field-thumbnail">
		<div class="field-content" style="padding: 5px 5px 10px 0;">
		<a href="http://www.takepart.com/author/karen-blessen" target="_self"><img src="http://www.takepart.com/sites/default/files/KarenBlessen70x70.jpg" alt="Karen Blessen" /></a>
	
			<div class="views-field views-field-field-promo-headline" style="float:right;  width:140px; padding: 0px 15px 0 0; font-size:14px"">
			<a href="http://www.takepart.com/article/2012/12/05/art-schools-why-inspire-peace" target="_self">Paintbrushes for Peace: Can Art in Schools Inspire Adults to Get Along?</a>

			</div>
		</div>
	</div>


	<h2><span>Tom Devine</span></h2>
	
	<div class="views-field views-field-field-thumbnail">
		<div class="field-content" style="padding: 5px 5px 10px 0;">
		<a href="http://www.takepart.com/author/tom-devine-legal-director-government-accountability-project" target="_self"><img src="http://www.takepart.com/sites/default/files/Tom_Devine70x70.jpeg" alt="Tom Devine" /></a>
	
			<div class="views-field views-field-field-promo-headline" style="float:right;  width:140px; padding: 0px 15px 0 0; font-size:14px"">
			<a href="http://www.takepart.com/article/2012/12/04/op-ed-dont-let-whistleblowers-get-blown-away" target="_self">Op-Ed: Don\'t Let Whistleblowers Get Blown Away</a>

			</div>
		</div>
	</div>

</div>
',
    'additional_classes' => '',
    'selected_style' => '0',
  );
  $export['box-c49bfd54'] = $box;

  return $export;
}

<?php
/**
 * @file
 * tpf_display_boxes.box.inc
 */

/**
 * Implements hook_default_box().
 */
function tpf_display_boxes_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'bg_skin_sponsor';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'GA: ROS Background Take-over';
  $box->options = array(
    'ga_ad_slot' => 'TP3_ROS_Background_1x1',
    'ga_ad_gpt_id' => 'div-gpt-ad-1391020952974-0',
    'additional_classes' => '',
  );
  $export['bg_skin_sponsor'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-1104adce';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'GA: ROS Bottom Right';
  $box->options = array(
    'ga_ad_slot' => 'TP3_ROS_RR_BTF_300x600',
    'ga_ad_gpt_id' => 'div-gpt-ad-1391020952974-3',
    'additional_classes' => 'block-boxes-ga_ad block-boxes-ga_ad-bottom',
  );
  $export['box-1104adce'] = $box;

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
  $box->delta = 'box-41040ece';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Take Action Banner';
  $box->options = array(
    'body' => '<a href="/take-action"><img src="/sites/default/files/TABHeader-2.png" id="take-action-980-banner"></a>',
    'additional_classes' => '',
    'selected_style' => '0',
  );
  $export['box-41040ece'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-5cd7d5ce';
  $box->plugin_key = 'field';
  $box->title = '';
  $box->description = 'Campaign: Take Action Block';
  $box->options = array(
    'entity_type' => 'node',
    'entity_id' => '',
    'bundle' => 'takepart_campaign',
    'field' => array(
      'field_action_related' => 'field_action_related',
      'body' => 0,
      'field_topic' => 0,
      'field_free_tag' => 0,
      'field_tp_campaign_4_things_link' => 0,
      'field_tp_campaign_5_things_head' => 0,
      'field_tp_campaign_cover_image' => 0,
      'field_tp_campaign_intro_html' => 0,
      'field_tp_campaign_intro_media' => 0,
      'field_tp_campaign_seg_1_html' => 0,
      'field_tp_campaign_seg_1_label' => 0,
      'field_tp_campaign_seg_1_rel' => 0,
      'field_tp_campaign_seg_2_html' => 0,
      'field_tp_campaign_seg_2_label' => 0,
      'field_tp_campaign_seg_2_rel' => 0,
      'field_tp_campaign_seg_3_html' => 0,
      'field_tp_campaign_seg_3_label' => 0,
      'field_tp_campaign_seg_3_rel' => 0,
      'field_tp_campaign_seg_4_html' => 0,
      'field_tp_campaign_seg_4_label' => 0,
      'field_tp_campaign_seg_4_rel' => 0,
      'field_tp_campaign_sl_html' => 0,
      'field_tp_campaign_sl_image' => 0,
      'field_tp_campaign_subheadline' => 0,
      'field_multi_page_campaign' => 0,
      'field_tp_campaign_cover_intro' => 0,
      'field_tp_campaign_sl_nodes' => 0,
      'field_tp_campaign_sponsors' => 0,
      'field_tp_campaign_context' => 0,
      'field_tp_campaign_alliances' => 0,
    ),
    'use_page' => 1,
    'exclude_from_content' => 0,
    'view_mode' => 'default',
  );
  $export['box-5cd7d5ce'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-66c05d6f';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'GA: ROS Top Right';
  $box->options = array(
    'ga_ad_slot' => 'TP3_ROS_RR_ATF_300x250',
    'ga_ad_gpt_id' => 'div-gpt-ad-1391020952974-2',
    'additional_classes' => 'block-boxes-ga_ad',
  );
  $export['box-66c05d6f'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-6c13820e';
  $box->plugin_key = 'field';
  $box->title = '';
  $box->description = 'Series Graphic Header - Content';
  $box->options = array(
    'entity_type' => 'node',
    'entity_id' => '',
    'bundle' => '0',
    'field' => array(
      'field_series' => 'field_series',
      'body' => 0,
      'field_author' => 0,
      'field_article_main_image' => 0,
      'field_profile_job_title' => 0,
      'field_blogpost_main_image' => 0,
      'field_gallery_images' => 0,
      'field_gallery_main_image' => 0,
      'field_video_embedded' => 0,
      'field_section_front_context' => 0,
      'field_profile_address' => 0,
      'field_profile_email' => 0,
      'field_profile_first_name' => 0,
      'field_profile_last_name' => 0,
      'field_profile_organization' => 0,
      'field_profile_phone' => 0,
      'field_profile_photo' => 0,
      'field_profile_user' => 0,
      'field_action_main_image' => 0,
      'field_action_related' => 0,
      'field_action_sponsor' => 0,
      'field_action_type' => 0,
      'field_action_url' => 0,
      'field_free_tag' => 0,
      'field_thumbnail' => 0,
      'field_topic' => 0,
      'field_article_action' => 0,
      'field_article_subhead' => 0,
      'field_display_tag' => 0,
      'field_promo_headline' => 0,
      'field_promo_text' => 0,
      'field_author_links' => 0,
      'field_blog_front_context' => 0,
      'field_blogpost_featured_action' => 0,
      'field_blogpost_subhead' => 0,
      'field_related_content' => 0,
      'field_group_location' => 0,
      'field_group_logo' => 0,
      'field_group_main_image' => 0,
      'field_group_subhead' => 0,
      'field_group_topic' => 0,
      'field_group_type' => 0,
      'field_group_url' => 0,
      'field_page_action' => 0,
      'field_page_main_image' => 0,
      'field_page_related_actions' => 0,
      'field_page_related_content' => 0,
      'field_page_subhead' => 0,
      'field_page_suggest_campaigns' => 0,
      'field_page_suggest_content' => 0,
      'field_quickstudy_main_image' => 0,
      'field_topic_front_context' => 0,
      'field_main_image' => 0,
      'field_subhead' => 0,
      'field_video_related' => 0,
      'field_tp_campaign_4_things_link' => 0,
      'field_tp_campaign_5_things_head' => 0,
      'field_tp_campaign_cover_image' => 0,
      'field_tp_campaign_intro_html' => 0,
      'field_tp_campaign_intro_media' => 0,
      'field_tp_campaign_seg_1_html' => 0,
      'field_tp_campaign_seg_1_label' => 0,
      'field_tp_campaign_seg_1_rel' => 0,
      'field_tp_campaign_seg_2_html' => 0,
      'field_tp_campaign_seg_2_label' => 0,
      'field_tp_campaign_seg_2_rel' => 0,
      'field_tp_campaign_seg_3_html' => 0,
      'field_tp_campaign_seg_3_label' => 0,
      'field_tp_campaign_seg_3_rel' => 0,
      'field_tp_campaign_seg_4_html' => 0,
      'field_tp_campaign_seg_4_label' => 0,
      'field_tp_campaign_seg_4_rel' => 0,
      'field_tp_campaign_sl_html' => 0,
      'field_tp_campaign_sl_image' => 0,
      'field_tp_campaign_subheadline' => 0,
      'field_slide_featured_item' => 0,
      'field_slide_headline_override' => 0,
      'field_slide_main_media' => 0,
      'field_related_actions' => 0,
      'field_suggest_campaigns' => 0,
      'field_suggest_content' => 0,
      'field_related_campaigns' => 0,
      'field_suggest_actions' => 0,
      'field_multi_page_campaign' => 0,
      'field_tp_campaign_cover_intro' => 0,
      'field_tp_campaign_sl_nodes' => 0,
      'field_tp_campaign_sponsors' => 0,
      'field_tp_campaign_context' => 0,
      'field_audio_asset' => 0,
      'field_photo_gallery_slideshow' => 0,
      'field_group_context' => 0,
      'field_blog_context' => 0,
      'field_tp_campaign_header' => 0,
      'field_tp_campaign_cover_link' => 0,
      'field_video_series' => 0,
      'field_tp_campaign_alliances' => 0,
      'field_suggest_video' => 0,
      'field_list_items' => 0,
      'field_tp_campaign_show_title' => 0,
      'field_description' => 0,
      'field_feed_item_description' => 0,
      'field_calendar' => 0,
      'field_altcontent' => 0,
      'field_actionheaderimghref' => 0,
      'field_actionheaderimg' => 0,
      'field_html_title' => 0,
      'field_video_display_mode' => 0,
      'field_petition_page_title' => 0,
      'field_petition_text' => 0,
      'field_petition_about' => 0,
      'field_petition_sponsor' => 0,
      'field_petition_recipient' => 0,
      'field_thank_you_message' => 0,
      'field_updates_message' => 0,
      'field_closed_message' => 0,
      'field_thank_you_share_bar' => 0,
      'field_signatures' => 0,
    ),
    'use_page' => 1,
    'exclude_from_content' => 0,
    'view_mode' => 'default',
  );
  $export['box-6c13820e'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-72e1be3c';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Take Action Button';
  $box->options = array(
    'body' => '<div class="takepart-take-action"></div>',
    'additional_classes' => '',
  );
  $export['box-72e1be3c'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-7afa6acd';
  $box->plugin_key = 'field';
  $box->title = '';
  $box->description = 'Topic Block';
  $box->options = array(
    'entity_type' => 'node',
    'entity_id' => '',
    'bundle' => 'action',
    'field' => array(
      'field_topic' => 'field_topic',
      'body' => 0,
      'field_action_main_image' => 0,
      'field_action_related' => 0,
      'field_action_sponsor' => 0,
      'field_action_type' => 0,
      'field_action_url' => 0,
      'field_free_tag' => 0,
      'field_thumbnail' => 0,
      'field_promo_headline' => 0,
      'field_promo_text' => 0,
      'field_related_content' => 0,
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
  $export['box-7afa6acd'] = $box;

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
  $box->delta = 'box-95b55e7';
  $box->plugin_key = 'field';
  $box->title = 'Sponsored By';
  $box->description = 'Campaign: Sponsored By Block';
  $box->options = array(
    'entity_type' => 'node',
    'entity_id' => '',
    'bundle' => 'takepart_campaign',
    'field' => array(
      'field_tp_campaign_sponsors' => 'field_tp_campaign_sponsors',
      'body' => 0,
      'field_thumbnail' => 0,
      'field_topic' => 0,
      'field_main_image' => 0,
      'field_tp_campaign_4_things_link' => 0,
      'field_tp_campaign_5_things_head' => 0,
      'field_tp_campaign_cover_image' => 0,
      'field_tp_campaign_intro_html' => 0,
      'field_tp_campaign_intro_media' => 0,
      'field_tp_campaign_seg_1_html' => 0,
      'field_tp_campaign_seg_1_label' => 0,
      'field_tp_campaign_seg_1_rel' => 0,
      'field_tp_campaign_seg_2_html' => 0,
      'field_tp_campaign_seg_2_label' => 0,
      'field_tp_campaign_seg_2_rel' => 0,
      'field_tp_campaign_seg_3_html' => 0,
      'field_tp_campaign_seg_3_label' => 0,
      'field_tp_campaign_seg_3_rel' => 0,
      'field_tp_campaign_seg_4_html' => 0,
      'field_tp_campaign_seg_4_label' => 0,
      'field_tp_campaign_seg_4_rel' => 0,
      'field_tp_campaign_sl_html' => 0,
      'field_tp_campaign_sl_image' => 0,
      'field_tp_campaign_subheadline' => 0,
      'field_related_actions' => 0,
      'field_suggest_actions' => 0,
      'field_multi_page_campaign' => 0,
      'field_tp_campaign_cover_intro' => 0,
      'field_tp_campaign_sl_nodes' => 0,
      'field_tp_campaign_context' => 0,
      'field_tp_campaign_header' => 0,
      'field_tp_campaign_cover_link' => 0,
      'field_tp_campaign_alliances' => 0,
      'field_tp_campaign_show_title' => 0,
      'field_calendar' => 0,
      'field_html_title' => 0,
      'field_google_map' => 0,
    ),
    'use_page' => 1,
    'exclude_from_content' => 0,
    'view_mode' => 'default',
  );
  $export['box-95b55e7'] = $box;

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

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ga_articles_bottom_right';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'GA: Articles Bottom Right';
  $box->options = array(
    'ga_ad_slot' => 'TP3_Articles_RR_BTF_300x600',
    'ga_ad_gpt_id' => 'div-gpt-ad-1348078874566-0',
  );
  $export['ga_articles_bottom_right'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ga_articles_top';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'GA: Articles Top';
  $box->options = array(
    'ga_ad_slot' => 'TP_Test_ATF_header_728x90',
    'ga_ad_gpt_id' => 'div-gpt-ad-1367984606334-0',
    'additional_classes' => '',
  );
  $export['ga_articles_top'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ga_articles_top_right';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'GA: Articles Top Right';
  $box->options = array(
    'ga_ad_slot' => 'TP3_Articles_RR_ATF_300x250',
    'ga_ad_gpt_id' => 'div-gpt-ad-1348078720053-0',
  );
  $export['ga_articles_top_right'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ga_homepage_bottom_right';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'GA: Homepage Bottom Right';
  $box->options = array(
    'ga_ad_slot' => 'TP3_Homepage_RR_BTF_300x600',
    'ga_ad_gpt_id' => 'div-gpt-ad-1376947919227-0',
    'additional_classes' => 'block-boxes-ga_ad',
  );
  $export['ga_homepage_bottom_right'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'takepart';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'GA: ROS Leaderboard';
  $box->options = array(
    'ga_ad_slot' => 'TP4_ROS_728x90_Responsive',
    'ga_ad_gpt_id' => 'div-gpt-ad-1459481133437-0',
    'ga_ad_width' => '728',
    'ga_ad_height' => '90',
    'additional_classes' => 'leaderboard ad-large-center',
  );
  $export['takepart'] = $box;

  return $export;
}

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
  $box->delta = 'action_header_image';
  $box->plugin_key = 'field';
  $box->title = '';
  $box->description = 'Action Header Image';
  $box->options = array(
    'entity_type' => 'node',
    'entity_id' => '',
    'bundle' => '0',
    'field' => array(
      'field_actionheaderimghref' => 'field_actionheaderimghref',
      'field_actionheaderimg' => 'field_actionheaderimg',
      'body' => 0,
      'field_author' => 0,
      'field_article_main_image' => 0,
      'field_profile_job_title' => 0,
      'field_blogpost_blog' => 0,
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
      'field_series' => 0,
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
      'field_slide_headline' => 0,
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
    ),
    'use_page' => 1,
    'exclude_from_content' => 0,
    'view_mode' => 'default',
  );
  $export['action_header_image'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'action_topic_and_share';
  $box->plugin_key = 'field';
  $box->title = '';
  $box->description = 'Action Topic and Sharing Block';
  $box->options = array(
    'entity_type' => 'node',
    'entity_id' => '',
    'bundle' => '0',
    'field' => array(
      'field_action_type' => 'field_action_type',
      'field_social_share_bar' => 'field_social_share_bar',
      'body' => 0,
      'field_author' => 0,
      'field_article_main_image' => 0,
      'field_profile_job_title' => 0,
      'field_blogpost_blog' => 0,
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
      'field_action_url' => 0,
      'field_free_tag' => 0,
      'field_thumbnail' => 0,
      'field_topic' => 0,
      'field_article_action' => 0,
      'field_article_subhead' => 0,
      'field_display_tag' => 0,
      'field_promo_headline' => 0,
      'field_promo_text' => 0,
      'field_series' => 0,
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
      'field_petition_text' => 0,
      'field_petition_about' => 0,
      'field_petition_sponsor' => 0,
      'field_petition_recipient' => 0,
      'field_thank_you_message' => 0,
      'field_updates_message' => 0,
      'field_closed_message' => 0,
      'field_thank_you_share_bar' => 0,
      'field_signatures' => 0,
      'field_priority' => 0,
      'field_tab_action' => 0,
      'field_tab_internal_title' => 0,
      'field_tab_internal_desc' => 0,
      'field_tab_external_title' => 0,
      'field_tab_external_desc' => 0,
      'field_tab_call_to_action' => 0,
      'field_tab_content_link' => 0,
      'field_tab_update_text' => 0,
      'field_action_form_title' => 0,
      'field_pledge_issue' => 0,
      'field_pledge_action_short' => 0,
      'field_pledge_action_long' => 0,
      'field_associated_content' => 0,
      'field_name' => 0,
      'field_storedescription' => 0,
      'field_storeinfo' => 0,
      'field_google_map' => 0,
      'field_action_organizer' => 0,
      'field_tab_link_only' => 0,
      'field_signed_message' => 0,
      'field_short_introduction' => 0,
      'field_closed_heading' => 0,
      'field_complete_heading' => 0,
      'field_signed_heading' => 0,
      'field_thank_you_heading' => 0,
      'field_tab_action_override' => 0,
      'field_complete_message' => 0,
      'field_tab_exclude' => 0,
    ),
    'use_page' => 1,
    'exclude_from_content' => 0,
    'view_mode' => 'default',
  );
  $export['action_topic_and_share'] = $box;

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
  $box->delta = 'box-1306f48f';
  $box->plugin_key = 'field';
  $box->title = '';
  $box->description = 'Campaign: Seg1';
  $box->options = array(
    'entity_type' => 'node',
    'entity_id' => '',
    'bundle' => '0',
    'field' => array(
      'field_tp_campaign_seg_1_label' => 'field_tp_campaign_seg_1_label',
      'field_tp_campaign_seg_1_html' => 'field_tp_campaign_seg_1_html',
      'field_tp_campaign_seg_1_rel' => 'field_tp_campaign_seg_1_rel',
      'body' => 0,
      'field_author' => 0,
      'field_article_main_image' => 0,
      'field_profile_job_title' => 0,
      'field_blogpost_blog' => 0,
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
      'field_series' => 0,
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
      'field_slide_headline' => 0,
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
    ),
    'use_page' => 0,
    'exclude_from_content' => 0,
    'view_mode' => 'default',
  );
  $export['box-1306f48f'] = $box;

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
  $box->delta = 'box-153f08e4';
  $box->plugin_key = 'field';
  $box->title = '';
  $box->description = 'Campaign: Seg3';
  $box->options = array(
    'entity_type' => 'node',
    'entity_id' => '',
    'bundle' => 'takepart_campaign',
    'field' => array(
      'field_tp_campaign_seg_3_html' => 'field_tp_campaign_seg_3_html',
      'field_tp_campaign_seg_3_label' => 'field_tp_campaign_seg_3_label',
      'field_tp_campaign_seg_3_rel' => 'field_tp_campaign_seg_3_rel',
      'body' => 0,
      'field_action_related' => 0,
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
    'use_page' => 0,
    'exclude_from_content' => 0,
    'view_mode' => 'default',
  );
  $export['box-153f08e4'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-18786b90';
  $box->plugin_key = 'simple';
  $box->title = 'TakePart Video';
  $box->description = 'Right Rail Video Player: Ads Auto Play';
  $box->options = array(
    'body' => '<script src="http://jwpsrv.com/library/esP2FhWwEeODmBIxOUCPzg.js"></script>
<div id="botr_Y0y8DVG4_TPXPTQu4_ply"></div>
<script type="text/javascript">

  // Use this variable to turn on/off pre-roll ads
  // true - Pre-roll ads with auto play
  // false - No ads and not auto play

  var enable_pre_roll_ads = false;

  // DO NOT EDIT BELOW THIS LINE
  var player_config = {
    analytics: {
     "enabled": false
    },
    aspectratio: "16:9",
    autostart: enable_pre_roll_ads,
    controls: true,
    displaytitle: false,
    fallback: false,
    flashplayer: "http://a.jwpcdn.com/player/6/653609/jwplayer.flash.swf",
    ga: {
      "idstring": "title"
    },
    height: 610,
    html5player: "http://a.jwpcdn.com/player/6/653609/jwplayer.html5.js",
    image: "http://video.takepart.com/thumbs/PYuSkFyj-640.jpg",
    listbar: {
      "position": "bottom",
      "size": 250
    },
    playlist: "http://video.takepart.com/jw6/Y0y8DVG4.xml",
    plugins: {
      "http://a.jwpcdn.com/player/6/653609/ping.js": {
        "pixel": "http://video.takepart.com/ping.gif"
      }
    },
    primary: "flash",
    repeat: false,
    sharing: {
      "code": "%3Ciframe%20src%3D%22http%3A//video.takepart.com/players/MEDIAID-TPXPTQu4.html%22%20width%3D%22640%22%20height%3D%22610%22%20frameborder%3D%220%22%20scrolling%3D%22auto%22%3E%3C/iframe%3E",
      "link": "http://video.takepart.com/previews/MEDIAID-TPXPTQu4"
    },
    skin: "http://a.jwpcdn.com/skins/f0EMcd6B.xml",
    stretching: "uniform",
    width: "100%",
    mute: enable_pre_roll_ads
  }
  if (enable_pre_roll_ads) {
    player_config[\'advertising\'] = {
      "client":"vast",
      "tag": "http://pubads.g.doubleclick.net/gampad/ads?sz=640x360&iu=/4355895/TP3_Video_Siderail_640x360&ciu_szs&impl=s&gdfp_req=1&env=vp&output=xml_vast2&unviewed_position_start=1&url=[referrer_url]&correlator=[timestamp]",
      "admessage":"You can skip this ad in XX more seconds"
    };
  }
  jwplayer("botr_Y0y8DVG4_TPXPTQu4_ply").setup(player_config);
</script>
',
    'additional_classes' => '',
  );
  $export['box-18786b90'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-1dae03d3';
  $box->plugin_key = 'field';
  $box->title = '';
  $box->description = 'Blog Post Header';
  $box->options = array(
    'entity_type' => 'node',
    'entity_id' => '',
    'bundle' => 'openpublish_blog_post',
    'field' => array(
      'field_blogpost_subhead' => 'field_blogpost_subhead',
      'field_author' => 'field_author',
      'field_blogpost_main_image' => 'field_blogpost_main_image',
      'body' => 0,
      'field_blogpost_blog' => 0,
      'field_free_tag' => 0,
      'field_thumbnail' => 0,
      'field_topic' => 0,
      'field_display_tag' => 0,
      'field_promo_headline' => 0,
      'field_promo_text' => 0,
      'field_series' => 0,
      'field_blogpost_featured_action' => 0,
      'field_related_content' => 0,
      'field_related_actions' => 0,
      'field_suggest_campaigns' => 0,
      'field_suggest_content' => 0,
      'field_suggest_actions' => 0,
      'field_multi_page_campaign' => 0,
      'field_related_campaign' => 0,
    ),
    'use_page' => 1,
    'exclude_from_content' => 0,
    'view_mode' => 'default',
  );
  $export['box-1dae03d3'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-208c3905';
  $box->plugin_key = 'view';
  $box->title = 'Most Popular';
  $box->description = 'Popular Videos';
  $box->options = array(
    'view' => 'video--block_2',
    'settings' => array(
      'nid' => '180+31+183',
    ),
    'view_object' => NULL,
    'view_more_text' => '',
    'view_more_link' => '',
    'additional_classes' => '',
  );
  $export['box-208c3905'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-2988d8fb';
  $box->plugin_key = 'field';
  $box->title = '';
  $box->description = 'Campaign: Header Block';
  $box->options = array(
    'entity_type' => 'node',
    'entity_id' => '',
    'bundle' => 'takepart_campaign',
    'field' => array(
      'field_tp_campaign_5_things_head' => 'field_tp_campaign_5_things_head',
      'field_tp_campaign_4_things_link' => 'field_tp_campaign_4_things_link',
      'field_tp_campaign_intro_html' => 'field_tp_campaign_intro_html',
      'field_trailer_video' => 'field_trailer_video',
      'field_tp_campaign_intro_media' => 'field_tp_campaign_intro_media',
      'body' => 0,
      'field_tp_campaign_cover_image' => 0,
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
      'field_topic' => 0,
      'field_multi_page_campaign' => 0,
      'field_tp_campaign_cover_intro' => 0,
      'field_tp_campaign_sl_nodes' => 0,
      'field_tp_campaign_sponsors' => 0,
      'field_tp_campaign_context' => 0,
      'field_tp_campaign_header' => 0,
      'field_tp_campaign_cover_link' => 0,
      'field_tp_campaign_alliances' => 0,
      'field_related_actions' => 0,
      'field_suggest_actions' => 0,
      'field_tp_campaign_show_title' => 0,
      'field_html_title' => 0,
      'field_main_image' => 0,
      'field_google_map' => 0,
      'field_thumbnail' => 0,
      'field_tab_action_override' => 0,
      'field_promo_content_collection' => 0,
    ),
    'use_page' => 1,
    'exclude_from_content' => 0,
    'view_mode' => 'default',
    'additional_classes' => '',
  );
  $export['box-2988d8fb'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-33756e58';
  $box->plugin_key = 'field';
  $box->title = 'Spotlight';
  $box->description = 'Campaign: Spotlight';
  $box->options = array(
    'entity_type' => 'node',
    'entity_id' => '',
    'bundle' => 'takepart_campaign',
    'field' => array(
      'field_tp_campaign_sl_image' => 'field_tp_campaign_sl_image',
      'field_tp_campaign_sl_html' => 'field_tp_campaign_sl_html',
      'field_tp_campaign_sl_nodes' => 'field_tp_campaign_sl_nodes',
      'body' => 0,
      'field_topic' => 0,
      'field_multi_page_campaign' => 0,
      'field_thumbnail' => 0,
      'field_suggest_actions' => 0,
      'field_related_actions' => 0,
      'field_tp_campaign_show_title' => 0,
      'field_html_title' => 0,
      'field_tab_action_override' => 0,
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
      'field_tp_campaign_subheadline' => 0,
      'field_tp_campaign_cover_intro' => 0,
      'field_tp_campaign_sponsors' => 0,
      'field_tp_campaign_context' => 0,
      'field_tp_campaign_header' => 0,
      'field_tp_campaign_cover_link' => 0,
      'field_tp_campaign_alliances' => 0,
      'field_google_map' => 0,
      'field_promo_content_collection' => 0,
    ),
    'use_page' => 1,
    'exclude_from_content' => 0,
    'view_mode' => 'default',
    'additional_classes' => '',
  );
  $export['box-33756e58'] = $box;

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
  $box->delta = 'box-4abd00a3';
  $box->plugin_key = 'field';
  $box->title = 'Alliances';
  $box->description = 'Campaign: Alliances Block';
  $box->options = array(
    'entity_type' => 'node',
    'entity_id' => '',
    'bundle' => 'takepart_campaign',
    'field' => array(
      'field_tp_campaign_alliances' => 'field_tp_campaign_alliances',
      'body' => 0,
      'field_action_related' => 0,
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
    ),
    'use_page' => 1,
    'exclude_from_content' => 0,
    'view_mode' => 'default',
  );
  $export['box-4abd00a3'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-4eb62add';
  $box->plugin_key = 'field';
  $box->title = '';
  $box->description = 'Current Node Topic';
  $box->options = array(
    'entity_type' => 'node',
    'entity_id' => '',
    'bundle' => 'openpublish_article',
    'field' => array(
      'field_topic' => 'field_topic',
      'field_free_tag' => 0,
      'body' => 0,
      'field_author' => 0,
      'field_article_main_image' => 0,
      'field_thumbnail' => 0,
      'field_article_action' => 0,
      'field_article_subhead' => 0,
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
      'field_tp_campaign_show_title' => 0,
      'field_html_title' => 0,
      'field_tab_action_override' => 0,
    ),
    'use_page' => 1,
    'exclude_from_content' => 0,
    'view_mode' => 'default',
    'additional_classes' => '',
  );
  $export['box-4eb62add'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-4f9af2b4';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Fix CSS for Five Things';
  $box->options = array(
    'body' => '<style type="text/css">
.field-name-field-tp-campaign-intro-html .field-items { width:520px; }
</style>',
  );
  $export['box-4f9af2b4'] = $box;

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
      'field_blogpost_blog' => 0,
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
  $box->delta = 'box-7fa6e22c';
  $box->plugin_key = 'view';
  $box->title = 'Popular Galleries';
  $box->description = 'News + Issues - Gallery Right Rail';
  $box->options = array(
    'view' => 'photo_galleries--block_2',
    'settings' => array(
      'nid' => '39187+38183+39216',
    ),
    'view_object' => NULL,
    'view_more_text' => '',
    'view_more_link' => '',
    'expose_filters' => 0,
    'additional_classes' => '',
  );
  $export['box-7fa6e22c'] = $box;

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
  $box->delta = 'box-81a645d6';
  $box->plugin_key = 'field';
  $box->title = '';
  $box->description = 'Campaign Cover Block';
  $box->options = array(
    'entity_type' => 'node',
    'entity_id' => '',
    'bundle' => 'takepart_campaign',
    'field' => array(
      'field_tp_campaign_cover_image' => 'field_tp_campaign_cover_image',
      'field_tp_campaign_cover_intro' => 'field_tp_campaign_cover_intro',
      'field_tp_campaign_cover_link' => 'field_tp_campaign_cover_link',
      'body' => 0,
      'field_action_related' => 0,
      'field_topic' => 0,
      'field_free_tag' => 0,
      'field_tp_campaign_4_things_link' => 0,
      'field_tp_campaign_5_things_head' => 0,
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
      'field_tp_campaign_sl_nodes' => 0,
      'field_tp_campaign_sponsors' => 0,
      'field_tp_campaign_context' => 0,
      'field_tp_campaign_alliances' => 0,
      'field_tp_campaign_header' => 0,
    ),
    'use_page' => 1,
    'exclude_from_content' => 0,
    'view_mode' => 'default',
  );
  $export['box-81a645d6'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-8a3f206b';
  $box->plugin_key = 'field';
  $box->title = '';
  $box->description = 'Campaign: Seg2';
  $box->options = array(
    'entity_type' => 'node',
    'entity_id' => '',
    'bundle' => 'takepart_campaign',
    'field' => array(
      'field_tp_campaign_seg_2_label' => 'field_tp_campaign_seg_2_label',
      'field_tp_campaign_seg_2_html' => 'field_tp_campaign_seg_2_html',
      'field_tp_campaign_seg_2_rel' => 'field_tp_campaign_seg_2_rel',
      'body' => 0,
      'field_topic' => 0,
      'field_tp_campaign_4_things_link' => 0,
      'field_tp_campaign_5_things_head' => 0,
      'field_tp_campaign_cover_image' => 0,
      'field_tp_campaign_intro_html' => 0,
      'field_tp_campaign_intro_media' => 0,
      'field_tp_campaign_seg_1_html' => 0,
      'field_tp_campaign_seg_1_label' => 0,
      'field_tp_campaign_seg_1_rel' => 0,
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
      'field_tp_campaign_sponsors' => 0,
      'field_tp_campaign_context' => 0,
      'field_tp_campaign_header' => 0,
      'field_tp_campaign_cover_link' => 0,
      'field_tp_campaign_alliances' => 0,
      'field_tp_campaign_show_title' => 0,
    ),
    'use_page' => 0,
    'exclude_from_content' => 0,
    'view_mode' => 'default',
  );
  $export['box-8a3f206b'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-907caa9b';
  $box->plugin_key = 'field';
  $box->title = '';
  $box->description = 'Campaign: Seg3';
  $box->options = array(
    'entity_type' => 'node',
    'entity_id' => '',
    'bundle' => 'takepart_campaign',
    'field' => array(
      'field_tp_campaign_seg_3_label' => 'field_tp_campaign_seg_3_label',
      'field_tp_campaign_seg_3_html' => 'field_tp_campaign_seg_3_html',
      'field_tp_campaign_seg_3_rel' => 'field_tp_campaign_seg_3_rel',
      'body' => 0,
      'field_topic' => 0,
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
      'field_tp_campaign_sponsors' => 0,
      'field_tp_campaign_context' => 0,
      'field_tp_campaign_header' => 0,
      'field_tp_campaign_cover_link' => 0,
      'field_tp_campaign_alliances' => 0,
      'field_tp_campaign_show_title' => 0,
    ),
    'use_page' => 0,
    'exclude_from_content' => 0,
    'view_mode' => 'default',
  );
  $export['box-907caa9b'] = $box;

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
  $box->delta = 'box-97545db1';
  $box->plugin_key = 'field';
  $box->title = '';
  $box->description = 'Campaign: Seg4';
  $box->options = array(
    'entity_type' => 'node',
    'entity_id' => '',
    'bundle' => 'takepart_campaign',
    'field' => array(
      'field_tp_campaign_seg_4_label' => 'field_tp_campaign_seg_4_label',
      'field_tp_campaign_seg_4_html' => 'field_tp_campaign_seg_4_html',
      'field_tp_campaign_seg_4_rel' => 'field_tp_campaign_seg_4_rel',
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
      'field_tp_campaign_sl_html' => 0,
      'field_tp_campaign_sl_image' => 0,
      'field_tp_campaign_subheadline' => 0,
      'field_related_actions' => 0,
      'field_suggest_actions' => 0,
      'field_multi_page_campaign' => 0,
      'field_tp_campaign_cover_intro' => 0,
      'field_tp_campaign_sl_nodes' => 0,
      'field_tp_campaign_sponsors' => 0,
      'field_tp_campaign_context' => 0,
      'field_tp_campaign_header' => 0,
      'field_tp_campaign_cover_link' => 0,
      'field_tp_campaign_alliances' => 0,
      'field_tp_campaign_show_title' => 0,
      'field_calendar' => 0,
      'field_html_title' => 0,
      'field_google_map' => 0,
    ),
    'use_page' => 0,
    'exclude_from_content' => 0,
    'view_mode' => 'default',
    'additional_classes' => '',
  );
  $export['box-97545db1'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-9ececd73';
  $box->plugin_key = 'field';
  $box->title = '';
  $box->description = 'Campaign: Content';
  $box->options = array(
    'entity_type' => 'node',
    'entity_id' => '',
    'bundle' => 'takepart_campaign',
    'field' => array(
      'field_tp_campaign_subheadline' => 'field_tp_campaign_subheadline',
      'body' => 'body',
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
      'field_related_actions' => 0,
      'field_suggest_actions' => 0,
      'field_multi_page_campaign' => 0,
      'field_tp_campaign_cover_intro' => 0,
      'field_tp_campaign_sl_nodes' => 0,
      'field_tp_campaign_sponsors' => 0,
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
  $export['box-9ececd73'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-b68f20b9';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Campaign: Share';
  $box->options = array(
    'body' => 'Share',
  );
  $export['box-b68f20b9'] = $box;

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
  $box->delta = 'box-bb0b625d';
  $box->plugin_key = 'field';
  $box->title = '';
  $box->description = 'Article Display Tag';
  $box->options = array(
    'entity_type' => 'node',
    'entity_id' => '',
    'bundle' => 'openpublish_article',
    'field' => array(
      'field_display_tag' => 'field_display_tag',
      'body' => 0,
      'field_author' => 0,
      'field_article_main_image' => 0,
      'field_free_tag' => 0,
      'field_thumbnail' => 0,
      'field_topic' => 0,
      'field_article_action' => 0,
      'field_article_subhead' => 0,
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
      'field_tp_campaign_show_title' => 0,
      'field_html_title' => 0,
      'field_tab_action_override' => 0,
    ),
    'use_page' => 1,
    'exclude_from_content' => 0,
    'view_mode' => 'default',
    'additional_classes' => '',
  );
  $export['box-bb0b625d'] = $box;

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

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-c5c30007';
  $box->plugin_key = 'field';
  $box->title = '';
  $box->description = 'Group Header';
  $box->options = array(
    'entity_type' => 'node',
    'entity_id' => '',
    'bundle' => 'takepart_group',
    'field' => array(
      'field_group_subhead' => 'field_group_subhead',
      'field_group_type' => 'field_group_type',
      'field_group_main_image' => 'field_group_main_image',
      'body' => 0,
      'field_group_location' => 0,
      'field_group_logo' => 0,
      'field_group_topic' => 0,
      'field_group_url' => 0,
      'field_group_context' => 0,
    ),
    'use_page' => 1,
    'exclude_from_content' => 0,
    'view_mode' => 'default',
  );
  $export['box-c5c30007'] = $box;

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
  $box->delta = 'box-e9e8814f';
  $box->plugin_key = 'view';
  $box->title = 'Popular Video';
  $box->description = 'Popular Video';
  $box->options = array(
    'view' => 'video--block_1',
    'settings' => array(
      'nid' => '25987',
    ),
    'view_object' => NULL,
    'view_more_text' => '',
    'view_more_link' => '',
    'additional_classes' => '',
    'selected_style' => '0',
  );
  $export['box-e9e8814f'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-f070c115';
  $box->plugin_key = 'field';
  $box->title = '';
  $box->description = 'Group Left Rail';
  $box->options = array(
    'entity_type' => 'node',
    'entity_id' => '',
    'bundle' => 'takepart_group',
    'field' => array(
      'field_group_logo' => 'field_group_logo',
      'field_group_url' => 'field_group_url',
      'body' => 0,
      'field_group_location' => 0,
      'field_group_main_image' => 0,
      'field_group_subhead' => 0,
      'field_group_topic' => 0,
      'field_group_type' => 0,
      'field_group_context' => 0,
    ),
    'use_page' => 1,
    'exclude_from_content' => 0,
    'view_mode' => 'default',
  );
  $export['box-f070c115'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-f8bddbae';
  $box->plugin_key = 'field';
  $box->title = 'Quick Study';
  $box->description = 'Topic Quick Study';
  $box->options = array(
    'entity_type' => 'taxonomy_term',
    'entity_id' => '',
    'bundle' => 'topic',
    'field' => array(
      'field_topic_featured_quick_study' => 'field_topic_featured_quick_study',
      'field_topic_context' => 0,
      'field_topic_override' => 0,
    ),
    'use_page' => 1,
    'exclude_from_content' => 0,
    'view_mode' => 'default',
  );
  $export['box-f8bddbae'] = $box;

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
  $box->delta = 'our_blogs_summary_1';
  $box->plugin_key = 'view';
  $box->title = 'Our Blogs';
  $box->description = 'Our Blogs';
  $box->options = array(
    'view' => 'blogs--block_1',
    'settings' => array(
      'tid' => '25+26',
    ),
    'view_object' => NULL,
    'view_more_text' => '',
    'view_more_link' => '',
    'additional_classes' => '',
  );
  $export['our_blogs_summary_1'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'right_rail_video_promo_articles';
  $box->plugin_key = 'field';
  $box->title = 'TakePart Video';
  $box->description = 'Right Rail Video Promo for Articles';
  $box->options = array(
    'entity_type' => 'node',
    'entity_id' => 'Clips from TakePart Live [id:42195]',
    'bundle' => 'video',
    'field' => array(
      'field_video' => 'field_video',
      'body' => 0,
      'field_author' => 0,
      'field_free_tag' => 0,
      'field_thumbnail' => 0,
      'field_topic' => 0,
      'field_article_subhead' => 0,
      'field_display_tag' => 0,
      'field_promo_headline' => 0,
      'field_promo_text' => 0,
      'field_series' => 0,
      'field_tab_action_override' => 0,
      'field_related_stories' => 0,
      'field_significance' => 0,
      'field_topic_box' => 0,
      'field_inline_replacements' => 0,
      'field_admin_tag' => 0,
      'field_promo_short_headline' => 0,
      'field_ads_client' => 0,
      'field_ads_tag' => 0,
      'field_allowed_regions' => 0,
      'field_auto_play' => 0,
      'field_mute_playback' => 0,
      'field_player_skin' => 0,
      'field_playlist_layout' => 0,
      'field_playlist_position' => 0,
      'field_playlist_size' => 0,
      'field_sharing_enabled' => 0,
      'field_share_url' => 0,
      'field_player_embeddable' => 0,
    ),
    'use_page' => 0,
    'exclude_from_content' => 0,
    'view_mode' => 'embed',
    'additional_classes' => '',
  );
  $export['right_rail_video_promo_articles'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'takepart';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'GA: ROS Leaderboard';
  $box->options = array(
    'ga_ad_slot' => 'TP3_ROS_Leaderboard_728x90',
    'ga_ad_gpt_id' => 'div-gpt-ad-1391020952974-1',
    'additional_classes' => 'leaderboard',
  );
  $export['takepart'] = $box;

  return $export;
}

<?php
/**
 * @file
 * takepart_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function takepart_search_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_default_search_api_facet().
 */
function takepart_search_default_search_api_facet() {
  $items = array();
  $items['site_node_index_field_blogpost_b'] = entity_import('search_api_facet', '{
    "delta" : "site_node_index_field_blogpost_b",
    "index_id" : "site_node_index",
    "field" : "field_blogpost_blog",
    "name" : "Site Node Index: Blog",
    "enabled" : "1",
    "options" : {
      "limit" : 10,
      "display_more_link" : false,
      "more_limit" : 10,
      "min_count" : 1,
      "sort" : "count",
      "missing" : false,
      "show_active" : true,
      "default_true" : true,
      "ids_list" : [],
      "type" : "",
      "field_name" : "Blog",
      "entity_type" : "taxonomy_term"
    },
    "rdf_mapping" : []
  }');
  $items['site_node_index_field_free_tag'] = entity_import('search_api_facet', '{
    "delta" : "site_node_index_field_free_tag",
    "index_id" : "site_node_index",
    "field" : "field_free_tag",
    "name" : "Site Node Index: Free Tag",
    "enabled" : "1",
    "options" : {
      "limit" : 10,
      "display_more_link" : false,
      "more_limit" : 10,
      "min_count" : 1,
      "sort" : "count",
      "missing" : false,
      "show_active" : true,
      "default_true" : true,
      "ids_list" : [],
      "type" : "",
      "field_name" : "Free Tag",
      "entity_type" : "taxonomy_term"
    },
    "rdf_mapping" : []
  }');
  $items['site_node_index_field_series'] = entity_import('search_api_facet', '{
    "delta" : "site_node_index_field_series",
    "index_id" : "site_node_index",
    "field" : "field_series",
    "name" : "Site Node Index: Series",
    "enabled" : "1",
    "options" : {
      "limit" : 10,
      "display_more_link" : false,
      "more_limit" : 10,
      "min_count" : 1,
      "sort" : "count",
      "missing" : false,
      "show_active" : true,
      "default_true" : true,
      "ids_list" : [],
      "type" : "",
      "field_name" : "Series",
      "entity_type" : "taxonomy_term"
    },
    "rdf_mapping" : []
  }');
  $items['site_node_index_field_topic'] = entity_import('search_api_facet', '{
    "delta" : "site_node_index_field_topic",
    "index_id" : "site_node_index",
    "field" : "field_topic",
    "name" : "Site Node Index: Topic",
    "enabled" : "1",
    "options" : {
      "limit" : 10,
      "display_more_link" : false,
      "more_limit" : 10,
      "min_count" : 1,
      "sort" : "count",
      "missing" : false,
      "show_active" : true,
      "default_true" : true,
      "ids_list" : [],
      "type" : "",
      "field_name" : "Topic",
      "entity_type" : "taxonomy_term"
    },
    "rdf_mapping" : []
  }');
  $items['site_node_index_type'] = entity_import('search_api_facet', '{
    "delta" : "site_node_index_type",
    "index_id" : "site_node_index",
    "field" : "type",
    "name" : "Site Node Index: Content type",
    "enabled" : "1",
    "options" : {
      "limit" : 10,
      "display_more_link" : false,
      "more_limit" : 10,
      "min_count" : 1,
      "sort" : "count",
      "missing" : false,
      "show_active" : true,
      "default_true" : true,
      "ids_list" : [],
      "type" : "options",
      "field_name" : "Content type",
      "options" : {
        "action" : "Action",
        "openpublish_article" : "Article",
        "audio" : "Audio",
        "blog_front" : "Blog Front",
        "openpublish_blog_post" : "Blog Post",
        "takepart_campaign" : "Campaign",
        "takepart_group" : "Group",
        "takepart_list" : "List",
        "takepart_page" : "Page",
        "openpublish_photo" : "Photo",
        "openpublish_photo_gallery" : "Photo Gallery",
        "profile" : "Profile",
        "takepart_quick_study" : "Quick Study",
        "takepart_slide" : "Rotator Slide",
        "section_front" : "Section Front",
        "topic_front" : "Topic Front",
        "openpublish_video" : "Video",
        "webform" : "Webform"
      }
    },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function takepart_search_default_search_api_index() {
  $items = array();
  $items['site_node_index'] = entity_import('search_api_index', '{
    "name" : "Site Node Index",
    "machine_name" : "site_node_index",
    "description" : null,
    "server" : "solr",
    "entity_type" : "node",
    "options" : {
      "cron_limit" : "50",
      "index_directly" : 1,
      "fields" : {
        "search_api_language" : {
          "name" : "Item language",
          "indexed" : 1,
          "type" : "string",
          "boost" : "1.0"
        },
        "nid" : { "name" : "Node ID", "indexed" : 1, "type" : "integer", "boost" : "1.0" },
        "vid" : {
          "name" : "Revision ID",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "is_new" : { "name" : "Is new", "indexed" : 1, "type" : "boolean", "boost" : "1.0" },
        "type" : {
          "name" : "Content type",
          "indexed" : 1,
          "type" : "string",
          "boost" : "1.0"
        },
        "title" : { "name" : "Title", "indexed" : 1, "type" : "text", "boost" : "1.0" },
        "language" : { "name" : "Language", "indexed" : 0, "type" : "string", "boost" : "1.0" },
        "url" : { "name" : "URL", "indexed" : 1, "type" : "uri", "boost" : "1.0" },
        "edit_url" : { "name" : "Edit URL", "indexed" : 0, "type" : "uri", "boost" : "1.0" },
        "status" : {
          "name" : "Published",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "promote" : {
          "name" : "Promoted to frontpage",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "sticky" : {
          "name" : "Sticky in lists",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "created" : {
          "name" : "Date created",
          "indexed" : 1,
          "type" : "date",
          "boost" : "1.0"
        },
        "changed" : {
          "name" : "Date changed",
          "indexed" : 0,
          "type" : "date",
          "boost" : "1.0"
        },
        "author" : {
          "name" : "Author",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "user",
          "boost" : "1.0"
        },
        "source" : {
          "name" : "Translation source node",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "log" : {
          "name" : "Revision log message",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "revision" : {
          "name" : "Creates revision",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "comment" : {
          "name" : "Comments allowed",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "comment_count" : {
          "name" : "Comment count",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "comment_count_new" : {
          "name" : "New comment count",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "views" : {
          "name" : "Number of views",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "day_views" : {
          "name" : "Views today",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "last_view" : { "name" : "Last view", "indexed" : 0, "type" : "date", "boost" : "1.0" },
        "field_author" : {
          "name" : "Author(s)",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_free_tag" : {
          "name" : "Free Tag",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_topic" : {
          "name" : "Topic",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_article_action" : {
          "name" : "Featured Action",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_article_subhead" : { "name" : "Subhead", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_display_tag" : {
          "name" : "Display Tag",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_promo_headline" : {
          "name" : "Promo Headline",
          "indexed" : 1,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_promo_text" : { "name" : "Promo Text", "indexed" : 1, "type" : "text", "boost" : "1.0" },
        "field_series" : {
          "name" : "Series",
          "indexed" : 1,
          "type" : "integer",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_related_content" : {
          "name" : "Releated Content",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_related_actions" : {
          "name" : "Related Actions",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_suggest_campaigns" : {
          "name" : "Suggest Related Campaigns?",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_suggest_content" : {
          "name" : "Suggest Related Content?",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_related_campaigns" : {
          "name" : "Related Campaigns",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_suggest_actions" : {
          "name" : "Suggest Related Actions?",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_blogpost_blog" : {
          "name" : "Blog",
          "indexed" : 1,
          "type" : "integer",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_blogpost_featured_action" : {
          "name" : "Featured Action",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_blogpost_subhead" : { "name" : "Subhead", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_subhead" : { "name" : "Sub Head", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_video_related" : {
          "name" : "Related Video",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_video_series" : {
          "name" : "Video Series",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_suggest_video" : {
          "name" : "Suggest Related Videos?",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_profile_job_title" : { "name" : "Job Title", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_profile_address" : { "name" : "Address", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_profile_email" : {
          "name" : "Email Address",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_profile_first_name" : { "name" : "First Name", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_profile_last_name" : { "name" : "Last Name", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_profile_organization" : {
          "name" : "Organization",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_profile_phone" : {
          "name" : "Phone Number",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_profile_user" : {
          "name" : "Associated User",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "user",
          "boost" : "1.0"
        },
        "field_action_related" : {
          "name" : "Related Actions",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_action_sponsor" : {
          "name" : "Action Sponsor",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_action_type" : {
          "name" : "Action Type",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_group_subhead" : { "name" : "Subhead", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_group_topic" : {
          "name" : "Topic",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_group_type" : {
          "name" : "Group Type",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_page_action" : {
          "name" : "Featured Action",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_page_related_actions" : {
          "name" : "Related Actions",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_page_related_content" : {
          "name" : "Related Content",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_page_subhead" : { "name" : "Subhead", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_page_suggest_campaigns" : {
          "name" : "Suggest Related Campaigns?",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_page_suggest_content" : {
          "name" : "Suggest Related Content?",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_tp_campaign_5_things_head" : {
          "name" : "5 things Header",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_tp_campaign_seg_1_html" : {
          "name" : "Segment 1 HTML",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_tp_campaign_seg_1_label" : {
          "name" : "Segment 1 Label",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_tp_campaign_seg_1_rel" : {
          "name" : "Segment 1 Related Content",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_tp_campaign_seg_2_html" : {
          "name" : "Segment 2 HTML",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_tp_campaign_seg_2_label" : {
          "name" : "Segment 2 Label",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_tp_campaign_seg_2_rel" : {
          "name" : "Segment 2 Related Content",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_tp_campaign_seg_3_html" : {
          "name" : " Segment 3 HTML",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_tp_campaign_seg_3_label" : {
          "name" : " Segment 3 Label",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_tp_campaign_seg_3_rel" : {
          "name" : " Segment 3 Related Content",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_tp_campaign_seg_4_html" : {
          "name" : "  Segment 4 HTML",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_tp_campaign_seg_4_label" : {
          "name" : "  Segment 4 Label",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_tp_campaign_seg_4_rel" : {
          "name" : "  Segment 4 Related Content",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_tp_campaign_sl_html" : {
          "name" : "Spotlight HTML",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_tp_campaign_subheadline" : {
          "name" : "Sub Headline",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_tp_campaign_sl_nodes" : {
          "name" : "Spotlight Nodes",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_tp_campaign_sponsors" : {
          "name" : "Campaign Sponsors",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_slide_featured_item" : {
          "name" : "Story Link",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_slide_headline" : { "name" : "Headline", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_slide_headline_override" : {
          "name" : "Main Image Headline",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "body:value" : {
          "name" : "The main body text \\u00bb Text",
          "indexed" : 1,
          "type" : "text",
          "boost" : "1.0"
        },
        "body:summary" : {
          "name" : "The main body text \\u00bb Summary",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "body:format" : {
          "name" : "The main body text \\u00bb Text format",
          "indexed" : 0,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_author:nid" : {
          "name" : "Author(s) \\u00bb Node ID",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_author:vid" : {
          "name" : "Author(s) \\u00bb Revision ID",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_author:is_new" : {
          "name" : "Author(s) \\u00bb Is new",
          "indexed" : 0,
          "type" : "list\\u003cboolean\\u003e",
          "boost" : "1.0"
        },
        "field_author:type" : {
          "name" : "Author(s) \\u00bb Content type",
          "indexed" : 0,
          "type" : "list\\u003cstring\\u003e",
          "boost" : "1.0"
        },
        "field_author:title" : {
          "name" : "Author(s) \\u00bb Title",
          "indexed" : 1,
          "type" : "list\\u003cstring\\u003e",
          "boost" : "1.0"
        },
        "field_author:language" : {
          "name" : "Author(s) \\u00bb Language",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_author:url" : {
          "name" : "Author(s) \\u00bb URL",
          "indexed" : 0,
          "type" : "list\\u003curi\\u003e",
          "boost" : "1.0"
        },
        "field_author:edit_url" : {
          "name" : "Author(s) \\u00bb Edit URL",
          "indexed" : 0,
          "type" : "list\\u003curi\\u003e",
          "boost" : "1.0"
        },
        "field_author:status" : {
          "name" : "Author(s) \\u00bb Published",
          "indexed" : 0,
          "type" : "list\\u003cboolean\\u003e",
          "boost" : "1.0"
        },
        "field_author:promote" : {
          "name" : "Author(s) \\u00bb Promoted to frontpage",
          "indexed" : 0,
          "type" : "list\\u003cboolean\\u003e",
          "boost" : "1.0"
        },
        "field_author:sticky" : {
          "name" : "Author(s) \\u00bb Sticky in lists",
          "indexed" : 0,
          "type" : "list\\u003cboolean\\u003e",
          "boost" : "1.0"
        },
        "field_author:created" : {
          "name" : "Author(s) \\u00bb Date created",
          "indexed" : 0,
          "type" : "list\\u003cdate\\u003e",
          "boost" : "1.0"
        },
        "field_author:changed" : {
          "name" : "Author(s) \\u00bb Date changed",
          "indexed" : 0,
          "type" : "list\\u003cdate\\u003e",
          "boost" : "1.0"
        },
        "field_author:author" : {
          "name" : "Author(s) \\u00bb Author",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "user",
          "boost" : "1.0"
        },
        "field_author:source" : {
          "name" : "Author(s) \\u00bb Translation source node",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_author:log" : {
          "name" : "Author(s) \\u00bb Revision log message",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_author:revision" : {
          "name" : "Author(s) \\u00bb Creates revision",
          "indexed" : 0,
          "type" : "list\\u003cboolean\\u003e",
          "boost" : "1.0"
        },
        "field_author:comment" : {
          "name" : "Author(s) \\u00bb Comments allowed",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_author:comment_count" : {
          "name" : "Author(s) \\u00bb Comment count",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_author:comment_count_new" : {
          "name" : "Author(s) \\u00bb New comment count",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_author:views" : {
          "name" : "Author(s) \\u00bb Number of views",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_author:day_views" : {
          "name" : "Author(s) \\u00bb Views today",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_author:last_view" : {
          "name" : "Author(s) \\u00bb Last view",
          "indexed" : 0,
          "type" : "list\\u003cdate\\u003e",
          "boost" : "1.0"
        }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "default" : "1", "bundles" : { "takepart_slide" : "takepart_slide" } }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : null },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : "title",
              "field_promo_headline" : "field_promo_headline",
              "field_promo_text" : "field_promo_text",
              "search_api_language" : 0,
              "nid" : 0,
              "is_new" : 0,
              "type" : 0,
              "url" : 0,
              "created" : 0,
              "field_free_tag" : 0,
              "field_topic" : 0,
              "field_series" : 0,
              "field_blogpost_blog" : 0,
              "field_group_topic" : 0,
              "field_series_videos_by_tag" : 0,
              "field_vs_free_term" : 0,
              "field_vs_topic_term" : 0
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : "title",
              "field_promo_headline" : "field_promo_headline",
              "field_promo_text" : "field_promo_text",
              "search_api_language" : 0,
              "nid" : 0,
              "is_new" : 0,
              "type" : 0,
              "url" : 0,
              "created" : 0,
              "field_free_tag" : 0,
              "field_topic" : 0,
              "field_series" : 0,
              "field_blogpost_blog" : 0,
              "field_group_topic" : 0,
              "field_series_videos_by_tag" : 0,
              "field_vs_free_term" : 0,
              "field_vs_topic_term" : 0
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : "title",
              "field_promo_headline" : "field_promo_headline",
              "field_promo_text" : "field_promo_text",
              "search_api_language" : 0,
              "nid" : 0,
              "is_new" : 0,
              "type" : 0,
              "url" : 0,
              "created" : 0,
              "field_free_tag" : 0,
              "field_topic" : 0,
              "field_series" : 0,
              "field_blogpost_blog" : 0,
              "field_group_topic" : 0,
              "field_series_videos_by_tag" : 0,
              "field_vs_free_term" : 0,
              "field_vs_topic_term" : 0
            },
            "spaces" : "[^\\\\p{L}\\\\p{N}^\']",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : { "file" : "", "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc" }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function takepart_search_default_search_api_server() {
  $items = array();
  $items['solr'] = entity_import('search_api_server', '{
    "name" : "Phase2 Development SOLR Server",
    "machine_name" : "solr",
    "description" : "This is the Phase2 Development SOLR Server to be used on P2 development sites.",
    "class" : "search_api_solr_service",
    "options" : {
      "host" : "solr.p2technology.com",
      "port" : "8081",
      "path" : "\\/solr-www.takepart.com",
      "http_user" : "",
      "http_pass" : ""
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}

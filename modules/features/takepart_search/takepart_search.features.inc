<?php
/**
 * @file
 * takepart_search.features.inc
 */

/**
 * Implementation of hook_default_search_api_facet().
 */
function takepart_search_default_search_api_facet() {
  $items = array();
  $items['standard_node_index_field_articl'] = entity_import('search_api_facet', '{
    "delta" : "standard_node_index_field_articl",
    "index_id" : "standard_node_index",
    "field" : "field_article_author",
    "name" : "Standard Node_index: Author(s)",
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
      "type" : null,
      "field_name" : "Author(s)"
    },
    "rdf_mapping" : []
  }');
  $items['standard_node_index_field_blogpo'] = entity_import('search_api_facet', '{
    "delta" : "standard_node_index_field_blogpo",
    "index_id" : "standard_node_index",
    "field" : "field_blogpost_blog",
    "name" : "Standard Node Index: Blog",
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
  $items['standard_node_index_field_topic'] = entity_import('search_api_facet', '{
    "delta" : "standard_node_index_field_topic",
    "index_id" : "standard_node_index",
    "field" : "field_topic",
    "name" : "Standard Node Index: Topic",
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
  $items['standard_node_index_field_vs_top'] = entity_import('search_api_facet', '{
    "delta" : "standard_node_index_field_vs_top",
    "index_id" : "standard_node_index",
    "field" : "field_vs_topic_term",
    "name" : "Standard Node_index: Topic",
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
  $items['standard_node_index_type'] = entity_import('search_api_facet', '{
    "delta" : "standard_node_index_type",
    "index_id" : "standard_node_index",
    "field" : "type",
    "name" : "Standard Node Index: Content type",
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
        "takepart_page" : "Page",
        "openpublish_photo" : "Photo",
        "openpublish_photo_gallery" : "Photo Gallery",
        "profile" : "Profile",
        "takepart_quick_study" : "Quick Study",
        "takepart_slide" : "Rotator Slide",
        "section_front" : "Section Front",
        "topic_front" : "Topic Front",
        "openpublish_video" : "Video",
        "video_series" : "Video Series",
        "webform" : "Webform"
      }
    },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implementation of hook_default_search_api_index().
 */
function takepart_search_default_search_api_index() {
  $items = array();
  $items['standard_node_index'] = entity_import('search_api_index', '{
    "name" : "Standard Node Index",
    "machine_name" : "standard_node_index",
    "description" : null,
    "server" : "db",
    "entity_type" : "node",
    "options" : {
      "cron_limit" : "50",
      "index_directly" : 0,
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
          "indexed" : 0,
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
          "indexed" : 0,
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
          "indexed" : 0,
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
        "field_related_campaign" : {
          "name" : "Related Campaigns",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_photo_credit" : {
          "name" : "Photo Credit",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_action_related" : {
          "name" : "Related Actions",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_action_suggest_related" : {
          "name" : "Suggest Related Actions?",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_suggest_related" : {
          "name" : "Suggest Related Content?",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_subhead" : { "name" : "Subhead", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_video_related" : {
          "name" : "Related Video",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
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
          "indexed" : 0,
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
        "field_series_videos_by_tag" : {
          "name" : "Series Videos by Tag",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_series_videos_refs" : {
          "name" : "Series Videos",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_vs_free_term" : {
          "name" : "Tags",
          "indexed" : 1,
          "type" : "integer",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_vs_topic_term" : {
          "name" : "Topic",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "taxonomy_term",
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
          "type" : "integer",
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
        }
      }
    },
    "enabled" : "0",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implementation of hook_default_search_api_server().
 */
function takepart_search_default_search_api_server() {
  $items = array();
  $items['db'] = entity_import('search_api_server', '{
    "name" : "DB",
    "machine_name" : "db",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "1",
      "indexes" : {
        "default_node_index" : {
          "search_api_language" : {
            "table" : "search_api_db_default_node_index_search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "type" : {
            "table" : "search_api_db_default_node_index_type",
            "type" : "string",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_default_node_index_title",
            "type" : "text",
            "boost" : "5.0"
          },
          "status" : {
            "table" : "search_api_db_default_node_index_status",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "promote" : {
            "table" : "search_api_db_default_node_index_promote",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "sticky" : {
            "table" : "search_api_db_default_node_index_sticky",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_default_node_index_created",
            "type" : "date",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_default_node_index_changed",
            "type" : "date",
            "boost" : "1.0"
          },
          "author" : {
            "table" : "search_api_db_default_node_index_author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "comment_count" : {
            "table" : "search_api_db_default_node_index_comment_count",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_article_author" : {
            "table" : "search_api_db_default_node_index_field_article_author",
            "type" : "list\\u003cinteger\\u003e",
            "boost" : "1.0"
          },
          "field_topic" : {
            "table" : "search_api_db_default_node_index_field_topic",
            "type" : "list\\u003cinteger\\u003e",
            "boost" : "1.0"
          },
          "field_series" : {
            "table" : "search_api_db_default_node_index_field_series",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_blogpost_blog" : {
            "table" : "search_api_db_default_node_index_field_blogpost_blog",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_vs_free_term" : {
            "table" : "search_api_db_default_node_index_field_vs_free_term",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_vs_topic_term" : {
            "table" : "search_api_db_default_node_index_field_vs_topic_term",
            "type" : "integer",
            "boost" : "1.0"
          },
          "author:name" : {
            "table" : "search_api_db_default_node_index_author_name",
            "type" : "string",
            "boost" : "1.0"
          },
          "author:roles" : {
            "table" : "search_api_db_default_node_index_author_roles",
            "type" : "list\\u003cinteger\\u003e",
            "boost" : "1.0"
          },
          "body:value" : {
            "table" : "search_api_db_default_node_index_body_value",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_topic:tid" : {
            "table" : "search_api_db_default_node_index_field_topic_tid",
            "type" : "list\\u003cinteger\\u003e",
            "boost" : "1.0"
          },
          "field_topic:name" : {
            "table" : "search_api_db_default_node_index_field_topic_name",
            "type" : "list\\u003ctext\\u003e",
            "boost" : "1.0"
          }
        },
        "standard_node_index" : {
          "search_api_language" : {
            "table" : "search_api_db_standard_node_index_search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "nid" : {
            "table" : "search_api_db_standard_node_index_nid",
            "type" : "integer",
            "boost" : "1.0"
          },
          "is_new" : {
            "table" : "search_api_db_standard_node_index_is_new",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "type" : {
            "table" : "search_api_db_standard_node_index_type",
            "type" : "string",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_standard_node_index_title",
            "type" : "text",
            "boost" : "1.0"
          },
          "url" : {
            "table" : "search_api_db_standard_node_index_url",
            "type" : "uri",
            "boost" : "1.0"
          },
          "field_free_tag" : {
            "table" : "search_api_db_standard_node_index_field_free_tag",
            "type" : "list\\u003cinteger\\u003e",
            "boost" : "1.0"
          },
          "field_topic" : {
            "table" : "search_api_db_standard_node_index_field_topic",
            "type" : "list\\u003cinteger\\u003e",
            "boost" : "1.0"
          },
          "field_promo_headline" : {
            "table" : "search_api_db_standard_node_index_field_promo_headline",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_promo_text" : {
            "table" : "search_api_db_standard_node_index_field_promo_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_blogpost_blog" : {
            "table" : "search_api_db_standard_node_index_field_blogpost_blog",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_series_videos_by_tag" : {
            "table" : "search_api_db_standard_node_index_field_series_videos_by_tag",
            "type" : "list\\u003cinteger\\u003e",
            "boost" : "1.0"
          },
          "field_vs_free_term" : {
            "table" : "search_api_db_standard_node_index_field_vs_free_term",
            "type" : "integer",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}

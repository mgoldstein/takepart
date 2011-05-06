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
  $items['default_node_index_field_blogpos'] = entity_import('search_api_facet', '{
    "delta" : "default_node_index_field_blogpos",
    "index_id" : "default_node_index",
    "field" : "field_blogpost_blog",
    "name" : "Default node index: Blog",
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
  $items['default_node_index_field_series'] = entity_import('search_api_facet', '{
    "delta" : "default_node_index_field_series",
    "index_id" : "default_node_index",
    "field" : "field_series",
    "name" : "Default node index: Series",
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
  $items['default_node_index_field_topic'] = entity_import('search_api_facet', '{
    "delta" : "default_node_index_field_topic",
    "index_id" : "default_node_index",
    "field" : "field_topic",
    "name" : "Default node index: Topic",
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
  $items['default_node_index_status'] = entity_import('search_api_facet', '{
    "delta" : "default_node_index_status",
    "index_id" : "default_node_index",
    "field" : "status",
    "name" : "Default node index: Published",
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
      "type" : "boolean",
      "field_name" : "Published"
    },
    "rdf_mapping" : []
  }');
  $items['default_node_index_type'] = entity_import('search_api_facet', '{
    "delta" : "default_node_index_type",
    "index_id" : "default_node_index",
    "field" : "type",
    "name" : "Default node index: Content type",
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
        "blog_front" : "Blog Front",
        "openpublish_blog_post" : "Blog Post",
        "openpublish_photo" : "Photo",
        "openpublish_photo_gallery" : "Photo Gallery",
        "profile" : "Profile",
        "takepart_quick_study" : "Quick Study",
        "section_front" : "Section Front",
        "openpublish_site_page" : "Site Page",
        "topic_front" : "Topic Front",
        "openpublish_video" : "Video",
        "video_series" : "Video Series"
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
  $items['default_node_index'] = entity_import('search_api_index', '{
    "name" : "Default node index",
    "machine_name" : "default_node_index",
    "description" : "An automatically created search index for indexing node data. Might be configured to specific needs.",
    "server" : "db",
    "entity_type" : "node",
    "options" : {
      "cron_limit" : "50",
      "data_alter_callbacks" : {
        "search_api_alter_add_fulltext" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0" }
      },
      "processors" : {
        "search_api_case_ignore" : { "status" : 1, "weight" : "0", "settings" : { "strings" : 0 } },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\n            h2 = 3\\n            h3 = 2\\n            strong = 2\\n            b = 2\\n            em = 1.5\\n            u = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : { "spaces" : "[^\\\\p{L}\\\\p{N}]", "ignorable" : "[-]" }
        }
      },
      "fields" : {
        "search_api_language" : {
          "name" : "Item language",
          "indexed" : 1,
          "type" : "string",
          "boost" : "1.0"
        },
        "nid" : { "name" : "Node ID", "indexed" : 0, "type" : "integer", "boost" : "1.0" },
        "vid" : {
          "name" : "Revision ID",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "is_new" : { "name" : "Is new", "indexed" : 0, "type" : "boolean", "boost" : "1.0" },
        "type" : {
          "name" : "Content type",
          "indexed" : 1,
          "type" : "string",
          "boost" : "1.0"
        },
        "title" : { "name" : "Title", "indexed" : 1, "type" : "text", "boost" : "5.0" },
        "language" : { "name" : "Language", "indexed" : 0, "type" : "string", "boost" : "1.0" },
        "url" : { "name" : "URL", "indexed" : 0, "type" : "uri", "boost" : "1.0" },
        "edit_url" : { "name" : "Edit URL", "indexed" : 0, "type" : "uri", "boost" : "1.0" },
        "status" : {
          "name" : "Published",
          "indexed" : 1,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "promote" : {
          "name" : "Promoted to frontpage",
          "indexed" : 1,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "sticky" : {
          "name" : "Sticky in lists",
          "indexed" : 1,
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
          "indexed" : 1,
          "type" : "date",
          "boost" : "1.0"
        },
        "author" : {
          "name" : "Author",
          "indexed" : 1,
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
          "indexed" : 1,
          "type" : "integer",
          "boost" : "1.0"
        },
        "comment_count_new" : {
          "name" : "New comment count",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_article_author" : {
          "name" : "Author(s)",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_free_tag" : {
          "name" : "Free Tag",
          "indexed" : 0,
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
        "field_article_display_tag" : {
          "name" : "Display Tag",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_article_related_actions" : {
          "name" : "Related Actions",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_article_related_content" : {
          "name" : "Releated Content",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_article_subhead" : { "name" : "Subhead", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_article_suggest_campaigns" : {
          "name" : "Suggest Related Campaigns?",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_article_suggest_content" : {
          "name" : "Suggest Releated Content?",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_promo_headline" : {
          "name" : "Promo Headline",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_promo_text" : { "name" : "Promo Text", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_series" : {
          "name" : "Series",
          "indexed" : 1,
          "type" : "integer",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_blogpost_author" : {
          "name" : "Author",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_blogpost_blog" : {
          "name" : "Blog",
          "indexed" : 1,
          "type" : "integer",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_blogpost_display_tag" : {
          "name" : "Display Tag",
          "indexed" : 0,
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
        "field_blogpost_related_actions" : {
          "name" : "Related Actions",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_blogpost_related_campaign" : {
          "name" : "Related Campaigns",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_blogpost_related_content" : {
          "name" : "Related Content",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_blogpost_subhead" : { "name" : "Subhead", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_blogpost_suggest_actions" : {
          "name" : "Suggest Related Actions?",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_blogpost_suggest_campaigns" : {
          "name" : "Suggest Related Campaigns?",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_blogpost_suggest_content" : {
          "name" : "Suggest Related Content?",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_photo_credit" : {
          "name" : "Photo Credit",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_gallery_author" : {
          "name" : "Author(s)",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
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
        "field_related_content" : {
          "name" : "Related Content",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_suggest_related" : {
          "name" : "Suggest Related Content?",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_video_author" : {
          "name" : "Author(s)",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_video_related" : {
          "name" : "Related Video",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_video_subhead" : { "name" : "Subhead", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_author" : {
          "name" : "Author(s)",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_subhead" : { "name" : "Subhead", "indexed" : 0, "type" : "text", "boost" : "1.0" },
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
        "field_action_promo_headline" : {
          "name" : "Promo Headline",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_action_promo_text" : { "name" : "Promo Text", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_action_related_campaigins" : {
          "name" : "Related Campaigns",
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
        "field_series_videos_by_tag" : {
          "name" : "Series Videos by Tag",
          "indexed" : 0,
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
          "indexed" : 1,
          "type" : "integer",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "author:uid" : {
          "name" : "Author \\u00bb User ID",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "author:name" : {
          "name" : "Author \\u00bb Name",
          "indexed" : 1,
          "type" : "string",
          "boost" : "1.0"
        },
        "author:mail" : {
          "name" : "Author \\u00bb Email",
          "indexed" : 0,
          "type" : "string",
          "boost" : "1.0"
        },
        "author:url" : {
          "name" : "Author \\u00bb URL",
          "indexed" : 0,
          "type" : "uri",
          "boost" : "1.0"
        },
        "author:edit_url" : {
          "name" : "Author \\u00bb Edit URL",
          "indexed" : 0,
          "type" : "uri",
          "boost" : "1.0"
        },
        "author:last_login" : {
          "name" : "Author \\u00bb Last login",
          "indexed" : 0,
          "type" : "date",
          "boost" : "1.0"
        },
        "author:created" : {
          "name" : "Author \\u00bb Created",
          "indexed" : 0,
          "type" : "date",
          "boost" : "1.0"
        },
        "author:roles" : {
          "name" : "Author \\u00bb User roles",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
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
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_topic:tid" : {
          "name" : "Topic \\u00bb Term ID",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_topic:name" : {
          "name" : "Topic \\u00bb Name",
          "indexed" : 1,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_topic:description" : {
          "name" : "Topic \\u00bb Description",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_topic:weight" : {
          "name" : "Topic \\u00bb Weight",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_topic:node_count" : {
          "name" : "Topic \\u00bb Node count",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_topic:url" : {
          "name" : "Topic \\u00bb URL",
          "indexed" : 0,
          "type" : "list\\u003curi\\u003e",
          "boost" : "1.0"
        },
        "field_topic:vocabulary" : {
          "name" : "Topic \\u00bb Vocabulary",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_vocabulary",
          "boost" : "1.0"
        },
        "field_topic:parent" : {
          "name" : "Topic \\u00bb Parent terms",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_topic:field_topic_featured_quick_study" : {
          "name" : "Topic \\u00bb Featured Quick Study",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_topic:field_topic_override" : {
          "name" : "Topic \\u00bb Override",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        }
      }
    },
    "enabled" : "1",
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
      "indexes" : { "default_node_index" : {
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
          "comment_count" : {
            "table" : "search_api_db_default_node_index_comment_count",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_default_node_index_search_api_language",
            "type" : "string",
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
          "author" : {
            "table" : "search_api_db_default_node_index_author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_article_author" : {
            "table" : "search_api_db_default_node_index_field_article_author",
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
          "field_topic" : {
            "table" : "search_api_db_default_node_index_field_topic",
            "type" : "list\\u003cinteger\\u003e",
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
        }
      }
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}

<?php
/**
 * @file
 * takepart_search_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function takepart_search_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_search_api_index().
 */
function takepart_search_feature_default_search_api_index() {
  $items = array();
  $items['site_node_index'] = entity_import('search_api_index', '{
    "name" : "Site Node Index",
    "machine_name" : "site_node_index",
    "description" : "Indexed content for TakePart.com",
    "server" : "takepart_solr_production",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "25",
      "fields" : {
        "body:value" : { "type" : "text" },
        "created" : { "type" : "date" },
        "field_action_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_action_url:title" : { "type" : "text" },
        "field_action_url:url" : { "type" : "uri" },
        "field_admin_tag" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_author" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_author:title" : { "type" : "list\\u003Cstring\\u003E" },
        "field_free_tag" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_free_tag:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_free_tag:url" : { "type" : "list\\u003Curi\\u003E" },
        "field_profile_photo:alt" : { "type" : "text" },
        "field_profile_photo:file" : { "type" : "integer", "entity_type" : "file" },
        "field_promo_headline" : { "type" : "text" },
        "field_promo_text" : { "type" : "text" },
        "field_series" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_series:name" : { "type" : "text" },
        "field_series:url" : { "type" : "uri" },
        "field_thumbnail:file:url" : { "type" : "uri" },
        "field_topic" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_topic:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_topic:url" : { "type" : "list\\u003Curi\\u003E" },
        "is_new" : { "type" : "boolean" },
        "nid" : { "type" : "integer" },
        "published_at" : { "type" : "date" },
        "search_api_aggregation_1" : { "type" : "text" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "boolean" },
        "title" : { "type" : "text" },
        "type" : { "type" : "string" },
        "url" : { "type" : "uri" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "panelizer" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "search_api_aggregation_1" : {
                "name" : "Terms",
                "type" : "fulltext",
                "fields" : [
                  "field_free_tag",
                  "field_series",
                  "field_topic",
                  "field_action_type",
                  "field_free_tag:name",
                  "field_series:name",
                  "field_topic:name"
                ],
                "description" : "A Fulltext aggregation of the following fields: Free Tag, Series, Topic, Action Type, Free Tag \\u00bb Name, Series \\u00bb Name, Topic \\u00bb Name."
              }
            }
          }
        },
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "0",
          "settings" : {
            "default" : "0",
            "bundles" : {
              "action" : "action",
              "openpublish_article" : "openpublish_article",
              "campaign" : "campaign",
              "feature_article" : "feature_article",
              "flashcard" : "flashcard",
              "fresh_gallery" : "fresh_gallery",
              "takepart_page" : "takepart_page",
              "openpublish_photo_gallery" : "openpublish_photo_gallery",
              "video" : "video",
              "video_playlist" : "video_playlist"
            }
          }
        }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_promo_headline" : true,
              "field_promo_text" : true
            }
          }
        },
        "content_taxonomy_autocomplete_moderated_terms" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "field_free_tag:name" : true,
              "field_series:name" : true,
              "field_topic:name" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_promo_headline" : true,
              "field_promo_text" : true,
              "body:value" : true
            },
            "title" : 1,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_promo_headline" : true,
              "field_promo_text" : true
            },
            "spaces" : "[^\\\\p{L}\\\\p{N}^\\u0027]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_promo_headline" : true,
              "field_promo_text" : true,
              "search_api_aggregation_1" : true,
              "body:value" : true,
              "field_free_tag:name" : true,
              "field_series:name" : true,
              "field_topic:name" : true,
              "field_profile_photo:alt" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_page().
 */
function takepart_search_feature_default_search_api_page() {
  $items = array();
  $items['site_search'] = entity_import('search_api_page', '{
    "index_id" : "site_node_index",
    "path" : "search",
    "name" : "Site Search",
    "machine_name" : "site_search",
    "description" : "",
    "options" : {
      "mode" : "terms",
      "fields" : {
        "title" : "title",
        "search_api_aggregation_1" : "search_api_aggregation_1",
        "body:value" : "body:value",
        "field_free_tag:name" : "field_free_tag:name",
        "field_series:name" : "field_series:name",
        "field_topic:name" : "field_topic:name"
      },
      "per_page" : "10",
      "result_page_search_form" : 1,
      "get_per_page" : 0,
      "view_mode" : "search_api_page_result"
    },
    "enabled" : "1"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function takepart_search_feature_default_search_api_server() {
  $items = array();
  $items['takepart_solr_production'] = entity_import('search_api_server', '{
    "name" : "TakePart SOLR (Production settings)",
    "machine_name" : "takepart_solr_production",
    "description" : "Used for SOLR on TakePart.com",
    "class" : "search_api_solr_service",
    "options" : {
      "clean_ids_form" : [],
      "clean_ids" : false,
      "site_hash_form" : [],
      "site_hash" : false,
      "scheme" : "http",
      "host" : "10.2.5.50",
      "port" : 8080,
      "path" : "\\/solr\\/takepart_core",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "skip_schema_check" : 0,
      "solr_version" : "",
      "http_method" : "AUTO"
    },
    "enabled" : "1"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_sort().
 */
function takepart_search_feature_default_search_api_sort() {
  $items = array();
  $items['site_node_index__created'] = entity_import('search_api_sort', '{
    "index_id" : "site_node_index",
    "field" : "created",
    "name" : "Date",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "site_node_index__created",
    "default_sort" : "1",
    "default_sort_no_terms" : "1",
    "default_order" : "desc",
    "options" : { "field_name" : "Date created" }
  }');
  $items['site_node_index__search_api_relevance'] = entity_import('search_api_sort', '{
    "index_id" : "site_node_index",
    "field" : "search_api_relevance",
    "name" : "Relevance",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "site_node_index__search_api_relevance",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "search_api_relevance" }
  }');
  $items['site_node_index__status'] = entity_import('search_api_sort', '{
    "index_id" : "site_node_index",
    "field" : "status",
    "name" : "Published",
    "enabled" : "0",
    "weight" : "0",
    "identifier" : "site_node_index__status",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "Status" }
  }');
  $items['site_node_index__title'] = entity_import('search_api_sort', '{
    "index_id" : "site_node_index",
    "field" : "title",
    "name" : "Title",
    "enabled" : "0",
    "weight" : "0",
    "identifier" : "site_node_index__title",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "Title" }
  }');
  $items['site_node_index__type'] = entity_import('search_api_sort', '{
    "index_id" : "site_node_index",
    "field" : "type",
    "name" : "Type",
    "enabled" : "0",
    "weight" : "0",
    "identifier" : "site_node_index__type",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "Content type" }
  }');
  return $items;
}

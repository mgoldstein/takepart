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
}

/**
 * Implements hook_default_search_api_index().
 */
function takepart_search_feature_default_search_api_index() {
  $items = array();
  $items['site_node_index'] = entity_import('search_api_index', '{
    "name" : "Site Node Index",
    "machine_name" : "site_node_index",
    "description" : null,
    "server" : "takepart_solr_production",
    "item_type" : "node",
    "options" : {
      "cron_limit" : "200",
      "index_directly" : 1,
      "fields" : {
        "search_api_language" : { "type" : "string" },
        "search_api_aggregation_1" : { "type" : "text" },
        "nid" : { "type" : "integer" },
        "is_new" : { "type" : "boolean" },
        "type" : { "type" : "string" },
        "title" : { "type" : "text" },
        "url" : { "type" : "uri" },
        "status" : { "type" : "boolean" },
        "created" : { "type" : "date" },
        "field_author" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_free_tag" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_topic" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_promo_headline" : { "type" : "text" },
        "field_promo_text" : { "type" : "text" },
        "field_series" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_blogpost_blog" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_group_topic" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "body:value" : { "type" : "text" },
        "field_author:title" : { "type" : "list\\u003Cstring\\u003E" },
        "field_free_tag:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_free_tag:url" : { "type" : "list\\u003Curi\\u003E" },
        "field_topic:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_topic:url" : { "type" : "list\\u003Curi\\u003E" },
        "field_series:name" : { "type" : "text" },
        "field_series:url" : { "type" : "uri" },
        "field_video_series:name" : { "type" : "text" },
        "field_video_series:url" : { "type" : "uri" },
        "field_profile_photo:file" : { "type" : "integer", "entity_type" : "file" },
        "field_profile_photo:alt" : { "type" : "text" },
        "field_group_topic:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_group_topic:url" : { "type" : "list\\u003Curi\\u003E" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "0",
          "settings" : {
            "default" : "0",
            "bundles" : {
              "action" : "action",
              "openpublish_article" : "openpublish_article",
              "audio" : "audio",
              "blog_front" : "blog_front",
              "openpublish_blog_post" : "openpublish_blog_post",
              "takepart_campaign" : "takepart_campaign",
              "takepart_page" : "takepart_page",
              "petition_action" : "petition_action",
              "openpublish_photo_gallery" : "openpublish_photo_gallery",
              "pledge_action" : "pledge_action",
              "profile" : "profile",
              "takepart_quick_study" : "takepart_quick_study",
              "section_front" : "section_front",
              "topic_front" : "topic_front",
              "venue" : "venue",
              "openpublish_video" : "openpublish_video",
              "webform" : "webform"
            }
          }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "search_api_aggregation_1" : {
                "name" : "Terms",
                "type" : "fulltext",
                "fields" : [
                  "field_free_tag",
                  "field_topic",
                  "field_display_tag",
                  "field_series",
                  "field_video_series",
                  "field_group_topic",
                  "field_free_tag:name",
                  "field_topic:name",
                  "field_series:name",
                  "field_video_series:name",
                  "field_group_topic:name"
                ]
              }
            }
          }
        },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] }
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
function takepart_search_feature_default_search_api_server() {
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
    "enabled" : "0",
    "rdf_mapping" : []
  }');
  $items['takepart_solr_production'] = entity_import('search_api_server', '{
    "name" : "TakePart SOLR Production",
    "machine_name" : "takepart_solr_production",
    "description" : "Used for TakePart SOLR on production.",
    "class" : "search_api_solr_service",
    "options" : {
      "host" : "qa-solr.dev.takepart.com",
      "port" : "8080",
      "path" : "\\/solr",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}

<?php
/**
 * @file
 * tpf_taxonomy_topic.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function tpf_taxonomy_topic_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'field_collection_item-field_promo_content_collection-field_promo_content'.
  $field_instances['field_collection_item-field_promo_content_collection-field_promo_content'] = array(
    'bundle' => 'field_promo_content_collection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Reference to promotional content.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_promo_content',
    'label' => 'Promo Content',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_promo_content_collection-field_promo_headline'.
  $field_instances['field_collection_item-field_promo_content_collection-field_promo_headline'] = array(
    'bundle' => 'field_promo_content_collection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Override the Promo Headline that is being referenced.  If left blank, the Promo Headline from the content that is being referenced will be used.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_promo_headline',
    'label' => 'Promo Headline',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'campaign_full_html' => 'campaign_full_html',
          'full_html' => 'full_html',
          'limited_html' => 'limited_html',
          'no_wysiwg_full_html' => 'no_wysiwg_full_html',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'campaign_full_html' => array(
              'weight' => 0,
            ),
            'full_html' => array(
              'weight' => 0,
            ),
            'limited_html' => array(
              'weight' => 0,
            ),
            'no_wysiwg_full_html' => array(
              'weight' => 0,
            ),
            'php_code' => array(
              'weight' => -10,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_promo_content_collection-field_promo_label'.
  $field_instances['field_collection_item-field_promo_content_collection-field_promo_label'] = array(
    'bundle' => 'field_promo_content_collection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Override for the promo label.
Text that labels what the promo is ("Most Popular"  "Trending").',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_promo_label',
    'label' => 'Promo Label',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_promo_content_collection-field_promo_thumbnail'.
  $field_instances['field_collection_item-field_promo_content_collection-field_promo_thumbnail'] = array(
    'bundle' => 'field_promo_content_collection',
    'deleted' => 0,
    'description' => 'Overrides the promo image in the content being referenced.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'media_image_formatter',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_promo_thumbnail',
    'label' => 'Promo Thumbnail',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'taxonomy_term-topic-field_html_title'.
  $field_instances['taxonomy_term-topic-field_html_title'] = array(
    'bundle' => 'topic',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_html_title',
    'label' => 'HTML title tag',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-topic-field_promo_content_collection'.
  $field_instances['taxonomy_term-topic-field_promo_content_collection'] = array(
    'bundle' => 'topic',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'tp4_support',
        'settings' => array(),
        'type' => 'tp4_promo_content',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'tp4_support',
        'settings' => array(),
        'type' => 'tp4_promo_content',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_promo_content_collection',
    'label' => 'Promo Content',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'taxonomy_term-topic-field_topic_context'.
  $field_instances['taxonomy_term-topic-field_topic_context'] = array(
    'bundle' => 'topic',
    'default_value' => array(
      0 => array(
        'context' => '',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'context_field',
        'settings' => array(),
        'type' => 'context_field_context',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_topic_context',
    'label' => 'Context',
    'required' => 0,
    'settings' => array(
      'allowed_blocks' => array(
        'Boxes for Field Box' => 0,
        'Boxes for View Box' => 0,
        'addthis' => 0,
        'boxes' => 'boxes',
        'comment' => 0,
        'context_ui' => 0,
        'devel' => 0,
        'diff' => 0,
        'menu' => 0,
        'node' => 0,
        'search' => 0,
        'search_api_facets' => 0,
        'shortcut' => 0,
        'system' => 0,
        'user' => 0,
        'views' => 'views',
      ),
      'default_context' => 'topic_default_context',
      'use_default' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'context_field',
      'settings' => array(
        'form_element' => array(
          'user_toggle' => 0,
        ),
        'widget_setting' => 'bob',
      ),
      'type' => 'context_field',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'taxonomy_term-topic_box-field_topic_box_image'.
  $field_instances['taxonomy_term-topic_box-field_topic_box_image'] = array(
    'bundle' => 'topic_box',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'media_image_formatter',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_topic_box_image',
    'label' => 'Topic Box Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'topic_box_images',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'required_for_pub' => FALSE,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'taxonomy_term-topic_box-field_topic_box_link'.
  $field_instances['taxonomy_term-topic_box-field_topic_box_link'] = array(
    'bundle' => 'topic_box',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_topic_box_link',
    'label' => 'Topic Box Link',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'required_for_pub' => FALSE,
      'title' => 'none',
      'title_label_use_field_label' => FALSE,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Context');
  t('HTML title tag');
  t('Override for the promo label.
Text that labels what the promo is ("Most Popular"  "Trending").');
  t('Override the Promo Headline that is being referenced.  If left blank, the Promo Headline from the content that is being referenced will be used.');
  t('Overrides the promo image in the content being referenced.');
  t('Promo Content');
  t('Promo Headline');
  t('Promo Label');
  t('Promo Thumbnail');
  t('Reference to promotional content.');
  t('Topic Box Image');
  t('Topic Box Link');

  return $field_instances;
}

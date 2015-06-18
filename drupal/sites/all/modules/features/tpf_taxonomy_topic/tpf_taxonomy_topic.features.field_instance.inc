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

  // Exported field_instance: 'field_collection_item-field_promo_content_collection-field_promo_content'
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
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_promo_content_collection-field_promo_headline'
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
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_promo_content_collection-field_promo_label'
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

  // Exported field_instance: 'field_collection_item-field_promo_content_collection-field_promo_thumbnail'
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

  // Exported field_instance: 'taxonomy_term-topic-field_featured_video'
  $field_instances['taxonomy_term-topic-field_featured_video'] = array(
    'bundle' => 'topic',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 5,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_featured_video',
    'label' => 'Featured Video',
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
      'type' => 'entityreference_autocomplete_tags',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'taxonomy_term-topic-field_html_title'
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

  // Exported field_instance: 'taxonomy_term-topic-field_promo_content_collection'
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

  // Translatables
  // Included for use with string extractors like potx.
  t('Featured Video');
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

  return $field_instances;
}

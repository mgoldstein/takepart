<?php
/**
 * @file
 * tpf_content_photo_gallery.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function tpf_content_photo_gallery_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_deprecated|node|openpublish_photo_gallery|form';
  $field_group->group_name = 'group_deprecated';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openpublish_photo_gallery';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Deprecated',
    'weight' => '6',
    'children' => array(
      0 => 'field_html_title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-deprecated field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_deprecated|node|openpublish_photo_gallery|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_photo_gallery_main|node|openpublish_photo_gallery|form';
  $field_group->group_name = 'group_photo_gallery_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openpublish_photo_gallery';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '1',
    'children' => array(
      0 => 'body',
      1 => 'field_author',
      2 => 'field_gallery_main_image',
      3 => 'field_subhead',
      4 => 'field_tp_campaign_show_title',
      5 => 'field_display_cover',
      6 => 'field_display_tab_banner',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_photo_gallery_main|node|openpublish_photo_gallery|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_photo_gallery_photos|node|openpublish_photo_gallery|form';
  $field_group->group_name = 'group_photo_gallery_photos';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openpublish_photo_gallery';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Photos',
    'weight' => '2',
    'children' => array(
      0 => 'field_gallery_images',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_photo_gallery_photos|node|openpublish_photo_gallery|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_photo_gallery_promo|node|openpublish_photo_gallery|form';
  $field_group->group_name = 'group_photo_gallery_promo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openpublish_photo_gallery';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Promo',
    'weight' => '5',
    'children' => array(
      0 => 'field_promo_headline',
      1 => 'field_promo_text',
      2 => 'field_thumbnail',
      3 => 'field_promo_short_headline',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_photo_gallery_promo|node|openpublish_photo_gallery|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_photo_gallery_related|node|openpublish_photo_gallery|form';
  $field_group->group_name = 'group_photo_gallery_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openpublish_photo_gallery';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related',
    'weight' => '3',
    'children' => array(
      0 => 'field_related_content',
      1 => 'field_suggest_actions',
      2 => 'field_related_actions',
      3 => 'field_suggest_content',
      4 => 'field_related_stories',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_photo_gallery_related|node|openpublish_photo_gallery|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_photo_gallery_tagging|node|openpublish_photo_gallery|form';
  $field_group->group_name = 'group_photo_gallery_tagging';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openpublish_photo_gallery';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tagging',
    'weight' => '4',
    'children' => array(
      0 => 'field_series',
      1 => 'field_free_tag',
      2 => 'field_topic',
      3 => 'field_multi_page_campaign',
      4 => 'field_display_tag',
      5 => 'field_admin_tag',
      6 => 'field_topic_box',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_photo_gallery_tagging|node|openpublish_photo_gallery|form'] = $field_group;

  return $export;
}

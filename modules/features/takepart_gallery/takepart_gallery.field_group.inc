<?php
/**
 * @file
 * takepart_gallery.field_group.inc
 */

/**
 * Implementation of hook_field_group_info().
 */
function takepart_gallery_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_photo_gallery_main|node|openpublish_photo_gallery|form';
  $field_group->group_name = 'group_photo_gallery_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openpublish_photo_gallery';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '5',
    'children' => array(
      0 => 'group_photo_gallery_photos',
      1 => 'group_photo_gallery_promo',
      2 => 'group_photo_gallery_related',
      3 => 'group_photo_gallery_tagging',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_photo_gallery_main|node|openpublish_photo_gallery|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_photo_gallery_photos|node|openpublish_photo_gallery|form';
  $field_group->group_name = 'group_photo_gallery_photos';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openpublish_photo_gallery';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_photo_gallery_main';
  $field_group->data = array(
    'label' => 'Photos',
    'weight' => '25',
    'children' => array(
      0 => 'field_gallery_images',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_photo_gallery_photos|node|openpublish_photo_gallery|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_photo_gallery_promo|node|openpublish_photo_gallery|form';
  $field_group->group_name = 'group_photo_gallery_promo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openpublish_photo_gallery';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_photo_gallery_main';
  $field_group->data = array(
    'label' => 'Promo',
    'weight' => '28',
    'children' => array(
      0 => 'field_promo_headline',
      1 => 'field_promo_text',
      2 => 'field_thumbnail',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_photo_gallery_promo|node|openpublish_photo_gallery|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_photo_gallery_related|node|openpublish_photo_gallery|form';
  $field_group->group_name = 'group_photo_gallery_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openpublish_photo_gallery';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_photo_gallery_main';
  $field_group->data = array(
    'label' => 'Related',
    'weight' => '26',
    'children' => array(
      0 => 'field_action_related',
      1 => 'field_action_suggest_related',
      2 => 'field_related_content',
      3 => 'field_suggest_related',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_photo_gallery_related|node|openpublish_photo_gallery|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_photo_gallery_tagging|node|openpublish_photo_gallery|form';
  $field_group->group_name = 'group_photo_gallery_tagging';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openpublish_photo_gallery';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_photo_gallery_main';
  $field_group->data = array(
    'label' => 'Tagging',
    'weight' => '27',
    'children' => array(
      0 => 'field_series',
      1 => 'field_free_tag',
      2 => 'field_topic',
      3 => 'field_multi_page_campaign',
    ),
    'format_type' => 'htab',
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

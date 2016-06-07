<?php
/**
 * @file
 * tpf_content_photo_gallery.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function tpf_content_photo_gallery_field_group_info() {
  $field_groups = array();

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
    'weight' => '7',
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
  $field_groups['group_deprecated|node|openpublish_photo_gallery|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_editorial_dates|node|openpublish_photo_gallery|form';
  $field_group->group_name = 'group_editorial_dates';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openpublish_photo_gallery';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Editorial Info',
    'weight' => '17',
    'children' => array(
      0 => 'field_assigned_editor',
      1 => 'field_due_date',
      2 => 'field_run_date',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Editorial Info',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_editorial_dates|node|openpublish_photo_gallery|form'] = $field_group;

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
    'weight' => '5',
    'children' => array(
      0 => 'body',
      1 => 'field_author',
      2 => 'field_gallery_main_image',
      3 => 'field_thumbnail',
      4 => 'field_subhead',
      5 => 'field_tab_action_override',
      6 => 'field_display_cover',
      7 => 'field_inline_replacements',
      8 => 'field_display_tab_banner',
      9 => 'field_related_stories',
      10 => 'field_main_img_to_thumb',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Main',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_photo_gallery_main|node|openpublish_photo_gallery|form'] = $field_group;

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
    'weight' => '6',
    'children' => array(
      0 => 'field_gallery_images',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Photos',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_photo_gallery_photos|node|openpublish_photo_gallery|form'] = $field_group;

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
    'weight' => '0',
    'children' => array(
      0 => 'field_promo_headline',
      1 => 'field_promo_text',
      2 => 'field_promo_short_headline',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_photo_gallery_promo|node|openpublish_photo_gallery|form'] = $field_group;

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
    'weight' => '6',
    'children' => array(
      0 => 'field_related_stories',
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
  $field_groups['group_photo_gallery_related|node|openpublish_photo_gallery|form'] = $field_group;

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
    'weight' => '8',
    'children' => array(
      0 => 'field_series',
      1 => 'field_free_tag',
      2 => 'field_topic',
      3 => 'field_admin_tag',
      4 => 'field_sponsored',
      5 => 'field_topic_box',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Tagging',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_photo_gallery_tagging|node|openpublish_photo_gallery|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Deprecated');
  t('Editorial Info');
  t('Main');
  t('Photos');
  t('Promo');
  t('Related');
  t('Tagging');

  return $field_groups;
}

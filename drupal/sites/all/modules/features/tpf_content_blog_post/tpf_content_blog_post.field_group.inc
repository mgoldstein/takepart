<?php
/**
 * @file
 * tpf_content_blog_post.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function tpf_content_blog_post_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_blogpost_actions|node|openpublish_blog_post|form';
  $field_group->group_name = 'group_blogpost_actions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openpublish_blog_post';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_blogpost_main';
  $field_group->data = array(
    'label' => 'Actions',
    'weight' => '21',
    'children' => array(
      0 => 'field_blogpost_featured_action',
      1 => 'field_related_actions',
      2 => 'field_suggest_actions',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => ' group-blogpost-actions field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_blogpost_actions|node|openpublish_blog_post|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_blogpost_body|node|openpublish_blog_post|form';
  $field_group->group_name = 'group_blogpost_body';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openpublish_blog_post';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_blogpost_main';
  $field_group->data = array(
    'label' => 'Body Content',
    'weight' => '19',
    'children' => array(
      0 => 'body',
      1 => 'field_author',
      2 => 'field_blogpost_blog',
      3 => 'field_blogpost_subhead',
      4 => 'field_tp_campaign_show_title',
      5 => 'field_html_title',
      6 => 'title',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Body Content',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-blogpost-body field-group-htab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_blogpost_body|node|openpublish_blog_post|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_blogpost_campaigns|node|openpublish_blog_post|form';
  $field_group->group_name = 'group_blogpost_campaigns';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openpublish_blog_post';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_blogpost_main';
  $field_group->data = array(
    'label' => 'Campaigns',
    'weight' => '23',
    'children' => array(
      0 => 'field_suggest_campaigns',
      1 => 'field_multi_page_campaign',
      2 => 'field_related_campaigns',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => ' group-blogpost-campaigns field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_blogpost_campaigns|node|openpublish_blog_post|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_blogpost_content|node|openpublish_blog_post|form';
  $field_group->group_name = 'group_blogpost_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openpublish_blog_post';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_blogpost_main';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '22',
    'children' => array(
      0 => 'field_related_content',
      1 => 'field_suggest_content',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => ' group-blogpost-content field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_blogpost_content|node|openpublish_blog_post|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_blogpost_htab1|node|openpublish_blog_post|form';
  $field_group->group_name = 'group_blogpost_htab1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openpublish_blog_post';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '2',
    'children' => array(
      0 => 'group_blogpost_main',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Content',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-blogpost-htab1 field-group-tab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_blogpost_htab1|node|openpublish_blog_post|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_blogpost_main|node|openpublish_blog_post|form';
  $field_group->group_name = 'group_blogpost_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openpublish_blog_post';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_blogpost_htab1';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '16',
    'children' => array(
      0 => 'group_blogpost_body',
      1 => 'group_blogpost_promos',
      2 => 'group_blogpost_campaigns',
      3 => 'group_blogpost_terms',
      4 => 'group_blogpost_actions',
      5 => 'group_blogpost_media',
      6 => 'group_blogpost_content',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => ' group-blogpost-main field-group-htabs',
      ),
    ),
  );
  $export['group_blogpost_main|node|openpublish_blog_post|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_blogpost_media|node|openpublish_blog_post|form';
  $field_group->group_name = 'group_blogpost_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openpublish_blog_post';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_blogpost_main';
  $field_group->data = array(
    'label' => 'Media',
    'weight' => '20',
    'children' => array(
      0 => 'field_blogpost_main_image',
      1 => 'field_thumbnail',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => ' group-blogpost-media field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_blogpost_media|node|openpublish_blog_post|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_blogpost_promos|node|openpublish_blog_post|form';
  $field_group->group_name = 'group_blogpost_promos';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openpublish_blog_post';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_blogpost_main';
  $field_group->data = array(
    'label' => 'Promos',
    'weight' => '24',
    'children' => array(
      0 => 'field_promo_headline',
      1 => 'field_promo_text',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => ' group-blogpost-promos field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_blogpost_promos|node|openpublish_blog_post|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_blogpost_terms|node|openpublish_blog_post|form';
  $field_group->group_name = 'group_blogpost_terms';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openpublish_blog_post';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_blogpost_main';
  $field_group->data = array(
    'label' => 'Tags',
    'weight' => '25',
    'children' => array(
      0 => 'field_display_tag',
      1 => 'field_free_tag',
      2 => 'field_series',
      3 => 'field_topic',
      4 => 'field_admin_tag',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => ' group-blogpost-terms field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_blogpost_terms|node|openpublish_blog_post|form'] = $field_group;

  return $export;
}

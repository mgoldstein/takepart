<?php
/**
 * @file
 * tpf_content_campaigns.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function tpf_content_campaigns_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background_image|node|campaign_card_ad|form';
  $field_group->group_name = 'group_background_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_ad';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_background';
  $field_group->data = array(
    'label' => 'Background Image',
    'weight' => '18',
    'children' => array(
      0 => 'field_campaign_background',
      1 => 'field_campaign_bgw_image',
      2 => 'field_campaign_bg_crop',
      3 => 'field_campaign_bg_image_position',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background-image field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background_image|node|campaign_card_ad|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background_image|node|campaign_card_branding|form';
  $field_group->group_name = 'group_background_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_branding';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_background';
  $field_group->data = array(
    'label' => 'Background Image',
    'weight' => '12',
    'children' => array(
      0 => 'field_campaign_background',
      1 => 'field_campaign_bgw_image',
      2 => 'field_campaign_bg_crop',
      3 => 'field_campaign_bg_image_position',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background-image field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background_image|node|campaign_card_branding|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background_image|node|campaign_card_empty|form';
  $field_group->group_name = 'group_background_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_empty';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_background';
  $field_group->data = array(
    'label' => 'Background Image',
    'weight' => '4',
    'children' => array(
      0 => 'field_campaign_background',
      1 => 'field_campaign_bgw_image',
      2 => 'field_campaign_bg_crop',
      3 => 'field_campaign_bg_image_position',
      4 => 'field_campaign_bg_parallax',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background-image field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background_image|node|campaign_card_empty|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background_image|node|campaign_card_iframe|form';
  $field_group->group_name = 'group_background_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_iframe';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_background';
  $field_group->data = array(
    'label' => 'Background Image',
    'weight' => '23',
    'children' => array(
      0 => 'field_campaign_background',
      1 => 'field_campaign_bgw_image',
      2 => 'field_campaign_bg_crop',
      3 => 'field_campaign_bg_image_position',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background-image field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background_image|node|campaign_card_iframe|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background_image|node|campaign_card_media|form';
  $field_group->group_name = 'group_background_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_media';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_background';
  $field_group->data = array(
    'label' => 'Background Image',
    'weight' => '8',
    'children' => array(
      0 => 'field_campaign_background',
      1 => 'field_campaign_bgw_image',
      2 => 'field_campaign_bg_crop',
      3 => 'field_campaign_bg_image_position',
      4 => 'field_campaign_bg_parallax',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background-image field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background_image|node|campaign_card_media|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background_image|node|campaign_card_multi_column|form';
  $field_group->group_name = 'group_background_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_multi_column';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_background';
  $field_group->data = array(
    'label' => 'Background Image',
    'weight' => '11',
    'children' => array(
      0 => 'field_campaign_background',
      1 => 'field_campaign_bgw_image',
      2 => 'field_campaign_bg_crop',
      3 => 'field_campaign_bg_image_position',
      4 => 'field_campaign_bg_parallax',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background-image field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background_image|node|campaign_card_multi_column|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background_image|node|campaign_card_news|form';
  $field_group->group_name = 'group_background_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_news';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_background';
  $field_group->data = array(
    'label' => 'Background Image',
    'weight' => '10',
    'children' => array(
      0 => 'field_campaign_background',
      1 => 'field_campaign_bgw_image',
      2 => 'field_campaign_bg_crop',
      3 => 'field_campaign_bg_image_position',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background-image field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background_image|node|campaign_card_news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background_image|node|campaign_card_social|form';
  $field_group->group_name = 'group_background_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_social';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_background';
  $field_group->data = array(
    'label' => 'Background Image',
    'weight' => '13',
    'children' => array(
      0 => 'field_campaign_background',
      1 => 'field_campaign_bgw_image',
      2 => 'field_campaign_bg_crop',
      3 => 'field_campaign_bg_image_position',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background-image field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background_image|node|campaign_card_social|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background_image|node|campaign_card_tap_widget|form';
  $field_group->group_name = 'group_background_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_tap_widget';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_background';
  $field_group->data = array(
    'label' => 'Background Image',
    'weight' => '14',
    'children' => array(
      0 => 'field_campaign_background',
      1 => 'field_campaign_bgw_image',
      2 => 'field_campaign_bg_crop',
      3 => 'field_campaign_bg_image_position',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background-image field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background_image|node|campaign_card_tap_widget|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background_image|node|campaign_card_text|form';
  $field_group->group_name = 'group_background_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_text';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_background';
  $field_group->data = array(
    'label' => 'Background Image',
    'weight' => '14',
    'children' => array(
      0 => 'field_campaign_background',
      1 => 'field_campaign_bgw_image',
      2 => 'field_campaign_bg_crop',
      3 => 'field_campaign_bg_image_position',
      4 => 'field_campaign_bg_parallax',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Background Image',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-background-image field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_background_image|node|campaign_card_text|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background_image|node|campaign_card_twitter|form';
  $field_group->group_name = 'group_background_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_twitter';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_background';
  $field_group->data = array(
    'label' => 'Background Image',
    'weight' => '21',
    'children' => array(
      0 => 'field_campaign_background',
      1 => 'field_campaign_bgw',
      2 => 'field_campaign_bgw_image',
      3 => 'field_campaign_bg_crop',
      4 => 'field_campaign_bg_image_position',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background-image field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background_image|node|campaign_card_twitter|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background_image|node|campaign_tray|form';
  $field_group->group_name = 'group_background_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_tray';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_background';
  $field_group->data = array(
    'label' => 'Background Image',
    'weight' => '14',
    'children' => array(
      0 => 'field_campaign_background',
      1 => 'field_campaign_bgw_image',
      2 => 'field_campaign_bg_crop',
      3 => 'field_campaign_bg_image_position',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background-image field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background_image|node|campaign_tray|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background_image|node|campaign|form';
  $field_group->group_name = 'group_background_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_header_branding';
  $field_group->data = array(
    'label' => 'Background Image',
    'weight' => '20',
    'children' => array(
      0 => 'field_campaign_background',
      1 => 'field_campaign_bgw_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background-image field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background_image|node|campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background_video|node|campaign_card_ad|form';
  $field_group->group_name = 'group_background_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_ad';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_background';
  $field_group->data = array(
    'label' => 'Background Video',
    'weight' => '19',
    'children' => array(
      0 => 'field_campaign_bg_video',
      1 => 'field_campaign_bg_video_poster',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background-video field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background_video|node|campaign_card_ad|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background_video|node|campaign_card_branding|form';
  $field_group->group_name = 'group_background_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_branding';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_background';
  $field_group->data = array(
    'label' => 'Background Video',
    'weight' => '13',
    'children' => array(
      0 => 'field_campaign_bg_video',
      1 => 'field_campaign_bg_video_poster',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background-video field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background_video|node|campaign_card_branding|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background_video|node|campaign_card_empty|form';
  $field_group->group_name = 'group_background_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_empty';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_background';
  $field_group->data = array(
    'label' => 'Background Video',
    'weight' => '6',
    'children' => array(
      0 => 'field_campaign_bg_video',
      1 => 'field_campaign_bg_video_poster',
      2 => 'field_audio_volume',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background-video field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background_video|node|campaign_card_empty|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background_video|node|campaign_card_iframe|form';
  $field_group->group_name = 'group_background_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_iframe';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_background';
  $field_group->data = array(
    'label' => 'Background Video',
    'weight' => '24',
    'children' => array(
      0 => 'field_campaign_bg_video',
      1 => 'field_campaign_bg_video_poster',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background-video field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background_video|node|campaign_card_iframe|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background_video|node|campaign_card_media|form';
  $field_group->group_name = 'group_background_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_media';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_background';
  $field_group->data = array(
    'label' => 'Background Video',
    'weight' => '9',
    'children' => array(
      0 => 'field_campaign_bg_video',
      1 => 'field_campaign_bg_video_poster',
      2 => 'field_audio_volume',
      3 => 'field_ambient_video',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background-video field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background_video|node|campaign_card_media|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background_video|node|campaign_card_multi_column|form';
  $field_group->group_name = 'group_background_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_multi_column';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_background';
  $field_group->data = array(
    'label' => 'Background Video',
    'weight' => '12',
    'children' => array(
      0 => 'field_campaign_bg_video',
      1 => 'field_campaign_bg_video_poster',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background-video field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background_video|node|campaign_card_multi_column|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background_video|node|campaign_card_news|form';
  $field_group->group_name = 'group_background_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_news';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_background';
  $field_group->data = array(
    'label' => 'Background Video',
    'weight' => '11',
    'children' => array(
      0 => 'field_campaign_bg_video',
      1 => 'field_campaign_bg_video_poster',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background-video field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background_video|node|campaign_card_news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background_video|node|campaign_card_social|form';
  $field_group->group_name = 'group_background_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_social';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_background';
  $field_group->data = array(
    'label' => 'Background Video',
    'weight' => '14',
    'children' => array(
      0 => 'field_campaign_bg_video',
      1 => 'field_campaign_bg_video_poster',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background-video field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background_video|node|campaign_card_social|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background_video|node|campaign_card_tap_widget|form';
  $field_group->group_name = 'group_background_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_tap_widget';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_background';
  $field_group->data = array(
    'label' => 'Background Video',
    'weight' => '15',
    'children' => array(
      0 => 'field_campaign_bg_video',
      1 => 'field_campaign_bg_video_poster',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background-video field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background_video|node|campaign_card_tap_widget|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background_video|node|campaign_card_text|form';
  $field_group->group_name = 'group_background_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_text';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_background';
  $field_group->data = array(
    'label' => 'Background Video',
    'weight' => '15',
    'children' => array(
      0 => 'field_campaign_bg_video',
      1 => 'field_campaign_bg_video_poster',
      2 => 'field_ambient_video',
      3 => 'field_audio_volume',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background-video field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background_video|node|campaign_card_text|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background_video|node|campaign_card_twitter|form';
  $field_group->group_name = 'group_background_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_twitter';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_background';
  $field_group->data = array(
    'label' => 'Background Video',
    'weight' => '22',
    'children' => array(
      0 => 'field_campaign_bg_video',
      1 => 'field_campaign_bg_video_poster',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background-video field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background_video|node|campaign_card_twitter|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background|node|campaign_card_ad|form';
  $field_group->group_name = 'group_background';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_ad';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Background',
    'weight' => '7',
    'children' => array(
      0 => 'field_campaign_bg_color',
      1 => 'field_campaign_bgw',
      2 => 'group_background_video',
      3 => 'group_background_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background|node|campaign_card_ad|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background|node|campaign_card_branding|form';
  $field_group->group_name = 'group_background';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_branding';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Background',
    'weight' => '4',
    'children' => array(
      0 => 'field_campaign_bg_color',
      1 => 'field_campaign_bgw',
      2 => 'group_background_video',
      3 => 'group_background_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background|node|campaign_card_branding|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background|node|campaign_card_empty|form';
  $field_group->group_name = 'group_background';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_empty';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Background',
    'weight' => '3',
    'children' => array(
      0 => 'field_campaign_bg_color',
      1 => 'field_campaign_bgw',
      2 => 'group_background_image',
      3 => 'group_background_video',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background|node|campaign_card_empty|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background|node|campaign_card_iframe|form';
  $field_group->group_name = 'group_background';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_iframe';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Background',
    'weight' => '10',
    'children' => array(
      0 => 'field_campaign_bg_color',
      1 => 'field_campaign_bgw',
      2 => 'group_background_image',
      3 => 'group_background_video',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background|node|campaign_card_iframe|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background|node|campaign_card_media|form';
  $field_group->group_name = 'group_background';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_media';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Background',
    'weight' => '9',
    'children' => array(
      0 => 'field_campaign_bg_color',
      1 => 'field_campaign_bgw',
      2 => 'group_background_image',
      3 => 'group_background_video',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background|node|campaign_card_media|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background|node|campaign_card_multi_column|form';
  $field_group->group_name = 'group_background';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_multi_column';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Background',
    'weight' => '6',
    'children' => array(
      0 => 'field_campaign_bg_color',
      1 => 'field_campaign_bgw',
      2 => 'group_background_image',
      3 => 'group_background_video',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background|node|campaign_card_multi_column|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background|node|campaign_card_news|form';
  $field_group->group_name = 'group_background';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_news';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Background',
    'weight' => '10',
    'children' => array(
      0 => 'field_campaign_bg_color',
      1 => 'field_campaign_bgw',
      2 => 'group_background_video',
      3 => 'group_background_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background|node|campaign_card_news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background|node|campaign_card_social|form';
  $field_group->group_name = 'group_background';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_social';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Background',
    'weight' => '8',
    'children' => array(
      0 => 'field_campaign_bg_color',
      1 => 'field_campaign_bgw',
      2 => 'group_background_video',
      3 => 'group_background_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background|node|campaign_card_social|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background|node|campaign_card_tap_widget|form';
  $field_group->group_name = 'group_background';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_tap_widget';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Background',
    'weight' => '12',
    'children' => array(
      0 => 'field_campaign_bg_color',
      1 => 'field_campaign_bgw',
      2 => 'group_background_image',
      3 => 'group_background_video',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background|node|campaign_card_tap_widget|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background|node|campaign_card_text|form';
  $field_group->group_name = 'group_background';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_text';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Background',
    'weight' => '8',
    'children' => array(
      0 => 'field_campaign_bg_color',
      1 => 'field_campaign_bgw',
      2 => 'group_background_image',
      3 => 'group_background_video',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background|node|campaign_card_text|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background|node|campaign_card_twitter|form';
  $field_group->group_name = 'group_background';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_twitter';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Background',
    'weight' => '5',
    'children' => array(
      0 => 'field_campaign_bg_color',
      1 => 'group_background_video',
      2 => 'group_background_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background|node|campaign_card_twitter|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background|node|campaign_tray|form';
  $field_group->group_name = 'group_background';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_tray';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Background',
    'weight' => '5',
    'children' => array(
      0 => 'field_campaign_bg_color',
      1 => 'field_campaign_bgw',
      2 => 'group_background_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background|node|campaign_tray|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cic|node|campaign|form';
  $field_group->group_name = 'group_cic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content Inside Campaign',
    'weight' => '9',
    'children' => array(
      0 => 'field_content_menu',
      1 => 'field_content_menu_description',
      2 => 'field_content_menu_logo',
      3 => 'field_content_issue_volume',
      4 => 'field_content_promo_bg',
      5 => 'field_content_banner_bg',
      6 => 'field_content_dark_menu_logo',
      7 => 'field_suppress_cic',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cic field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_cic|node|campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_custom_styling|node|campaign|form';
  $field_group->group_name = 'group_custom_styling';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Custom Styling',
    'weight' => '11',
    'children' => array(
      0 => 'field_css',
      1 => 'field_fonts_for_css',
      2 => 'field_images_for_css',
      3 => 'field_campaign_style_setting',
      4 => 'field_campaign_style',
      5 => 'field_s3_css_filename',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-custom-styling field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_custom_styling|node|campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_header_branding|node|campaign|form';
  $field_group->group_name = 'group_header_branding';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Header/Branding',
    'weight' => '6',
    'children' => array(
      0 => 'field_campaign_bg_color',
      1 => 'field_campaign_bgw',
      2 => 'field_campaign_min_height',
      3 => 'field_campaign_mobile_min_height',
      4 => 'group_background_image',
      5 => 'group_logo',
      6 => 'group_menu',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Header/Branding',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-header-branding field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_header_branding|node|campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_iframe|node|campaign_card_iframe|form';
  $field_group->group_name = 'group_iframe';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_iframe';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'iFrame',
    'weight' => '4',
    'children' => array(
      0 => 'body',
      1 => 'field_campaign_iframe_height',
      2 => 'field_campaign_iframe_width',
      3 => 'field_campaign_iframe',
      4 => 'field_campaign_iframe_type',
      5 => 'field_campaign_iframe_full_width',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-iframe field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_iframe|node|campaign_card_iframe|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_logo|node|campaign|form';
  $field_group->group_name = 'group_logo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_header_branding';
  $field_group->data = array(
    'label' => 'Logo',
    'weight' => '21',
    'children' => array(
      0 => 'field_campaign_logo',
      1 => 'field_campaign_logo_position',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-logo field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_logo|node|campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media|node|campaign_card_media|form';
  $field_group->group_name = 'group_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_media';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Media',
    'weight' => '6',
    'children' => array(
      0 => 'field_campaign_media_type',
      1 => 'field_campaign_media_caption',
      2 => 'field_campaign_media_image_link',
      3 => 'field_campaign_media_photo',
      4 => 'field_campaign_media_title',
      5 => 'field_campaign_media_video',
      6 => 'field_media_video_playlist',
      7 => 'field_campaign_full_width',
      8 => 'field_campaign_video_modal',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-media field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_media|node|campaign_card_media|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_menu_background_image|node|campaign|form';
  $field_group->group_name = 'group_menu_background_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_menu';
  $field_group->data = array(
    'label' => 'Menu Background Image',
    'weight' => '28',
    'children' => array(
      0 => 'field_campaign_menu_bg_image',
      1 => 'field_campaign_menu_bg_image_w',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-menu-background-image field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_menu_background_image|node|campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_menu|node|campaign|form';
  $field_group->group_name = 'group_menu';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_header_branding';
  $field_group->data = array(
    'label' => 'Menu',
    'weight' => '24',
    'children' => array(
      0 => 'field_campaign_menu',
      1 => 'field_campaign_menu_bg_color',
      2 => 'field_campaign_menu_color_child',
      3 => 'field_campaign_menu_width',
      4 => 'field_menu_color_parent',
      5 => 'group_menu_background_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-menu field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_menu|node|campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_promo|node|campaign_page|form';
  $field_group->group_name = 'group_promo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Promo',
    'weight' => '15',
    'children' => array(
      0 => 'field_article_subhead',
      1 => 'field_promo_headline',
      2 => 'field_promo_short_headline',
      3 => 'field_promo_text',
      4 => 'field_tab_action_override',
      5 => 'field_thumbnail',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-promo field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_promo|node|campaign_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_promo|node|campaign|form';
  $field_group->group_name = 'group_promo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Promo',
    'weight' => '7',
    'children' => array(
      0 => 'field_article_subhead',
      1 => 'field_promo_headline',
      2 => 'field_promo_short_headline',
      3 => 'field_promo_text',
      4 => 'field_tab_action_override',
      5 => 'field_thumbnail',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-promo field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_promo|node|campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_seo|node|campaign_page|form';
  $field_group->group_name = 'group_seo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'SEO',
    'weight' => '8',
    'children' => array(
      0 => 'field_campaign_seo_title',
      1 => 'xmlsitemap',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-seo field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_seo|node|campaign_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tagging|node|campaign_page|form';
  $field_group->group_name = 'group_tagging';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tagging',
    'weight' => '21',
    'children' => array(
      0 => 'field_author',
      1 => 'field_free_tag',
      2 => 'field_series',
      3 => 'field_topic',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tagging field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_tagging|node|campaign_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tagging|node|campaign|form';
  $field_group->group_name = 'group_tagging';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tagging',
    'weight' => '8',
    'children' => array(
      0 => 'field_series',
      1 => 'field_topic',
      2 => 'field_sponsored',
      3 => 'field_campaign_type',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tagging field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_tagging|node|campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_twitter_feed|node|campaign_card_twitter|form';
  $field_group->group_name = 'group_twitter_feed';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_twitter';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Twitter Feed',
    'weight' => '4',
    'children' => array(
      0 => 'field_authentication_link',
      1 => 'field_number_of_tweets',
      2 => 'field_oauth_token',
      3 => 'field_oauth_token_secret',
      4 => 'field_twitter_list_slug',
      5 => 'field_twitter_pin',
      6 => 'field_twitter_type',
      7 => 'field_twitter_username',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-twitter-feed field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_twitter_feed|node|campaign_card_twitter|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Background');
  t('Background Image');
  t('Background Video');
  t('Content Inside Campaign');
  t('Custom Styling');
  t('Header/Branding');
  t('Logo');
  t('Media');
  t('Menu');
  t('Menu Background Image');
  t('Promo');
  t('SEO');
  t('Tagging');
  t('Twitter Feed');
  t('iFrame');

  return $field_groups;
}

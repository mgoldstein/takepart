<?php
/**
 * @file
 * tpf_content_campaigns.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function tpf_content_campaigns_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background_image|node|campaign_card_ad|form';
  $field_group->group_name = 'group_background_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_ad';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Background Image',
    'weight' => '7',
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
  $export['group_background_image|node|campaign_card_ad|form'] = $field_group;

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
    'weight' => '11',
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
  $export['group_background_image|node|campaign_card_branding|form'] = $field_group;

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
  $export['group_background_image|node|campaign_card_empty|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background_image|node|campaign_card_iframe|form';
  $field_group->group_name = 'group_background_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_iframe';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_card_background';
  $field_group->data = array(
    'label' => 'Background Image',
    'weight' => '18',
    'children' => array(
      0 => 'field_campaign_bgw_image',
      1 => 'field_campaign_background',
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
  $export['group_background_image|node|campaign_card_iframe|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background_image|node|campaign_card_media|form';
  $field_group->group_name = 'group_background_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_media';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_card_background';
  $field_group->data = array(
    'label' => 'Background Image',
    'weight' => '5',
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
  $export['group_background_image|node|campaign_card_media|form'] = $field_group;

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
    'weight' => '6',
    'children' => array(
      0 => 'field_campaign_bgw_image',
      1 => 'field_campaign_background',
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
  $export['group_background_image|node|campaign_card_news|form'] = $field_group;

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
      0 => 'field_campaign_bgw_image',
      1 => 'field_campaign_background',
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
  $export['group_background_image|node|campaign_card_social|form'] = $field_group;

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
    'weight' => '13',
    'children' => array(
      0 => 'field_campaign_bgw_image',
      1 => 'field_campaign_background',
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
  $export['group_background_image|node|campaign_card_text|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background_image|node|campaign_card_twitter|form';
  $field_group->group_name = 'group_background_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_twitter';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_card_background';
  $field_group->data = array(
    'label' => 'Background Image',
    'weight' => '18',
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
  $export['group_background_image|node|campaign_card_twitter|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background_image|node|campaign_tray|form';
  $field_group->group_name = 'group_background_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_tray';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tray_background';
  $field_group->data = array(
    'label' => 'Background Image',
    'weight' => '17',
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
  $export['group_background_image|node|campaign_tray|form'] = $field_group;

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
    'weight' => '21',
    'children' => array(
      0 => 'field_campaign_background',
      1 => 'field_campaign_bgw',
      2 => 'field_campaign_bgw_image',
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
  $export['group_background_image|node|campaign|form'] = $field_group;

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
    'weight' => '6',
    'children' => array(
      0 => 'field_campaign_bg_color',
      1 => 'field_campaign_bgw',
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
  $export['group_background|node|campaign_card_ad|form'] = $field_group;

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
    'weight' => '3',
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
  $export['group_background|node|campaign_card_branding|form'] = $field_group;

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
    'weight' => '2',
    'children' => array(
      0 => 'field_campaign_bgw',
      1 => 'field_campaign_bg_color',
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
  $export['group_background|node|campaign_card_empty|form'] = $field_group;

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
    'weight' => '3',
    'children' => array(
      0 => 'field_campaign_bgw',
      1 => 'field_campaign_bg_color',
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
  $export['group_background|node|campaign_card_news|form'] = $field_group;

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
    'weight' => '7',
    'children' => array(
      0 => 'field_campaign_bgw',
      1 => 'field_campaign_bg_color',
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
  $export['group_background|node|campaign_card_social|form'] = $field_group;

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
    'weight' => '7',
    'children' => array(
      0 => 'field_campaign_bgw',
      1 => 'field_campaign_bg_color',
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
  $export['group_background|node|campaign_card_text|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_card_background|node|campaign_card_iframe|form';
  $field_group->group_name = 'group_card_background';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_iframe';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Background',
    'weight' => '8',
    'children' => array(
      0 => 'field_campaign_bgw',
      1 => 'field_campaign_bg_color',
      2 => 'group_background_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-card-background field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_card_background|node|campaign_card_iframe|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_card_background|node|campaign_card_media|form';
  $field_group->group_name = 'group_card_background';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_media';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Background',
    'weight' => '7',
    'children' => array(
      0 => 'field_campaign_bgw',
      1 => 'field_campaign_bg_color',
      2 => 'group_background_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-card-background field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_card_background|node|campaign_card_media|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_card_background|node|campaign_card_twitter|form';
  $field_group->group_name = 'group_card_background';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_twitter';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Background',
    'weight' => '14',
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
        'classes' => 'group-card-background field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_card_background|node|campaign_card_twitter|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_color_scheme|node|campaign|form';
  $field_group->group_name = 'group_color_scheme';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Color Scheme',
    'weight' => '45',
    'children' => array(
      0 => 'field_color_scheme',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-color-scheme field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_color_scheme|node|campaign|form'] = $field_group;

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
    'weight' => '3',
    'children' => array(
      0 => 'field_campaign_min_height',
      1 => 'field_campaign_bg_color',
      2 => 'field_campaign_mobile_min_height',
      3 => 'group_background_image',
      4 => 'group_logo',
      5 => 'group_menu',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-header-branding field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_header_branding|node|campaign|form'] = $field_group;

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
    'weight' => '22',
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
  $export['group_logo|node|campaign|form'] = $field_group;

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
    'weight' => '5',
    'children' => array(
      0 => 'field_campaign_media_photo',
      1 => 'field_campaign_media_video',
      2 => 'field_campaign_media_title',
      3 => 'field_campaign_media_caption',
      4 => 'field_campaign_media_type',
      5 => 'field_campaign_media_image_link',
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
  $export['group_media|node|campaign_card_media|form'] = $field_group;

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
    'weight' => '30',
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
  $export['group_menu_background_image|node|campaign|form'] = $field_group;

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
    'weight' => '25',
    'children' => array(
      0 => 'field_campaign_menu',
      1 => 'field_campaign_menu_width',
      2 => 'field_campaign_menu_bg_color',
      3 => 'field_campaign_menu_color_child',
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
  $export['group_menu|node|campaign|form'] = $field_group;

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
    'weight' => '5',
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
  $export['group_promo|node|campaign_page|form'] = $field_group;

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
    'weight' => '4',
    'children' => array(
      0 => 'field_promo_headline',
      1 => 'field_promo_short_headline',
      2 => 'field_article_subhead',
      3 => 'field_promo_text',
      4 => 'field_thumbnail',
      5 => 'field_tab_action_override',
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
  $export['group_promo|node|campaign|form'] = $field_group;

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
    'weight' => '4',
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
  $export['group_seo|node|campaign_page|form'] = $field_group;

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
    'weight' => '5',
    'children' => array(
      0 => 'field_topic',
      1 => 'field_series',
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
  $export['group_tagging|node|campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tray_background|node|campaign_tray|form';
  $field_group->group_name = 'group_tray_background';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_tray';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Background',
    'weight' => '4',
    'children' => array(
      0 => 'field_campaign_bg_color',
      1 => 'field_campaign_bgw',
      2 => 'field_campaign_style',
      3 => 'group_background_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tray-background field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tray_background|node|campaign_tray|form'] = $field_group;

  return $export;
}

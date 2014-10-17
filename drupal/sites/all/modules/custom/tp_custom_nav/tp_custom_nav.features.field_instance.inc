<?php
/**
 * @file
 * tp_custom_nav.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function tp_custom_nav_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'taxonomy_term-brand-field_load_context'
  $field_instances['taxonomy_term-brand-field_load_context'] = array(
    'bundle' => 'brand',
    'deleted' => 0,
    'description' => 'This will allow you to activate any context for this specific taxonomy. Note that this will active that context regardless of condition set on it.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_load_context',
    'label' => 'Load Context',
    'required' => 0,
    'settings' => array(
      'allowed_blocks' => array(
        'Boxes for Box' => 0,
        'Boxes for Field Box' => 0,
        'Boxes for GA Ad' => 0,
        'Boxes for Screaming Headline' => 0,
        'Boxes for View Box' => 0,
        'akamai' => 0,
        'badge_image' => 0,
        'bean' => 0,
        'block' => 0,
        'boxes' => 0,
        'comment' => 0,
        'comment_block_simple' => 0,
        'context_related_menu' => 0,
        'context_ui' => 0,
        'devel' => 0,
        'diff' => 0,
        'facetapi' => 0,
        'menu' => 0,
        'menu_block' => 0,
        'newsletter_campaign' => 0,
        'nice_menus' => 0,
        'node' => 0,
        'panels_mini' => 0,
        'pm_interstitial' => 0,
        'search' => 0,
        'search_api_page' => 0,
        'search_api_sorts' => 0,
        'shortcut' => 0,
        'system' => 0,
        'takepart_addthis' => 0,
        'takepart_custom' => 0,
        'takepart_gallery_support' => 0,
        'tp4_support' => 0,
        'tp_campaigns' => 0,
        'tp_custom_nav' => 0,
        'tp_flashcards' => 0,
        'tp_megamenu' => 0,
        'tp_tpl' => 0,
        'user' => 0,
        'views' => 0,
        'waterfallapi' => 0,
        'zendesk_forms' => 0,
      ),
      'default_context' => 'context_field_default_context',
      'use_default' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'context_field',
      'settings' => array(
        'form_element' => array(
          'allow_create' => 0,
          'category' => '',
        ),
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'context_field_autocomplete',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'taxonomy_term-brand-field_slim_nav_bg_color'
  $field_instances['taxonomy_term-brand-field_slim_nav_bg_color'] = array(
    'bundle' => 'brand',
    'default_value' => array(
      0 => array(
        'jquery_colorpicker' => '000000',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_slim_nav_bg_color',
    'label' => 'Slim Nav BG Color',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'jquery_colorpicker',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'jquery_colorpicker',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'taxonomy_term-brand-field_slim_nav_font_color'
  $field_instances['taxonomy_term-brand-field_slim_nav_font_color'] = array(
    'bundle' => 'brand',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_slim_nav_font_color',
    'label' => 'Slim Nav Font Color',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'jquery_colorpicker',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'jquery_colorpicker',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'taxonomy_term-brand-field_slim_nav_logo'
  $field_instances['taxonomy_term-brand-field_slim_nav_logo'] = array(
    'bundle' => 'brand',
    'deleted' => 0,
    'description' => 'Upload a logo to use. On mobile this image will shrink to fit with a max width of 75px.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_slim_nav_logo',
    'label' => 'Slim Nav Logo',
    'required' => 1,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'filefield_paths' => array(
        'active_updating' => 0,
        'file_name' => array(
          'options' => array(
            'pathauto' => 0,
            'transliterate' => 0,
          ),
          'value' => '[file:ffp-name-only-original].[file:ffp-extension-original]',
        ),
        'file_path' => array(
          'options' => array(
            'pathauto' => 0,
            'transliterate' => 0,
          ),
          'value' => '',
        ),
        'retroactive_update' => 0,
      ),
      'filefield_paths_enabled' => 1,
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'jwplatform-channel' => 0,
          'jwplatform-video' => 0,
          'public' => 'public',
          'vimeo' => 0,
          'youtube' => 0,
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_my_files' => 0,
          'media_internet' => 0,
          'upload' => 0,
        ),
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'media_generic',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'taxonomy_term-brand-field_slim_nav_logo_url'
  $field_instances['taxonomy_term-brand-field_slim_nav_logo_url'] = array(
    'bundle' => 'brand',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This link will be used on the logo',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_slim_nav_logo_url',
    'label' => 'Slim Nav Logo URL',
    'required' => 1,
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'link_field',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'taxonomy_term-brand-field_slim_nav_menu'
  $field_instances['taxonomy_term-brand-field_slim_nav_menu'] = array(
    'bundle' => 'brand',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter a menu to use. This can be found in the URL when you edit the links in the menu. The URL will typically look like "/admin/structure/menu/manage/menu-pivot-menu".The last portion is the Menu ID. The "menu-pivot-menu" is what will need to be entered in.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_slim_nav_menu',
    'label' => 'Slim Nav Menu',
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
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'taxonomy_term-brand-field_slim_nav_mobile_bg'
  $field_instances['taxonomy_term-brand-field_slim_nav_mobile_bg'] = array(
    'bundle' => 'brand',
    'default_value' => array(
      0 => array(
        'jquery_colorpicker' => '000000',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'jquery_colorpicker',
        'settings' => array(),
        'type' => 'jquery_colorpicker_color_display',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_slim_nav_mobile_bg',
    'label' => 'Slim Nav Mobile BG',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'jquery_colorpicker',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'jquery_colorpicker',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'taxonomy_term-brand-field_slim_nav_social_menu'
  $field_instances['taxonomy_term-brand-field_slim_nav_social_menu'] = array(
    'bundle' => 'brand',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter a menu to use. This can be found in the URL when you edit the links in the menu. The URL will typically look like "/admin/structure/menu/manage/menu-pivot-social-menu".The last portion is the Menu ID. The "menu-pivot-social-menu" is what will need to be entered in. When creating the social menu, add the following class to each item to pull in the correct icon. Possible options are "blue-social-facebook", "blue-social-youtube", "blue-social-twitter", and "blue-social-instagram"',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_slim_nav_social_menu',
    'label' => 'Slim Nav Social Menu',
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
      'weight' => 5,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Enter a menu to use. This can be found in the URL when you edit the links in the menu. The URL will typically look like "/admin/structure/menu/manage/menu-pivot-menu".The last portion is the Menu ID. The "menu-pivot-menu" is what will need to be entered in.');
  t('Enter a menu to use. This can be found in the URL when you edit the links in the menu. The URL will typically look like "/admin/structure/menu/manage/menu-pivot-social-menu".The last portion is the Menu ID. The "menu-pivot-social-menu" is what will need to be entered in. When creating the social menu, add the following class to each item to pull in the correct icon. Possible options are "blue-social-facebook", "blue-social-youtube", "blue-social-twitter", and "blue-social-instagram"');
  t('Load Context');
  t('Slim Nav BG Color');
  t('Slim Nav Font Color');
  t('Slim Nav Logo');
  t('Slim Nav Logo URL');
  t('Slim Nav Menu');
  t('Slim Nav Mobile BG');
  t('Slim Nav Social Menu');
  t('This link will be used on the logo');
  t('This will allow you to activate any context for this specific taxonomy. Note that this will active that context regardless of condition set on it.');
  t('Upload a logo to use. On mobile this image will shrink to fit with a max width of 75px.');

  return $field_instances;
}

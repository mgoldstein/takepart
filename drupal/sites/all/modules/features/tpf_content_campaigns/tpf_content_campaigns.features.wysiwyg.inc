<?php
/**
 * @file
 * tpf_content_campaigns.features.wysiwyg.inc
 */

/**
 * Implements hook_wysiwyg_default_profiles().
 */
function tpf_content_campaigns_wysiwyg_default_profiles() {
  $profiles = array();

  // Exported profile: campaign_full_html
  $profiles['campaign_full_html'] = array(
    'format' => 'campaign_full_html',
    'editor' => 'ckeditor',
    'settings' => array(
      'default' => 1,
      'user_choose' => 0,
      'show_toggle' => 1,
      'theme' => 'advanced',
      'language' => 'en',
      'buttons' => array(
        'default' => array(
          'Bold' => 1,
          'Italic' => 1,
          'Underline' => 1,
          'JustifyLeft' => 1,
          'JustifyCenter' => 1,
          'JustifyRight' => 1,
          'BulletedList' => 1,
          'NumberedList' => 1,
          'Undo' => 1,
          'Redo' => 1,
          'Link' => 1,
          'Unlink' => 1,
          'Anchor' => 1,
          'Blockquote' => 1,
          'Source' => 1,
          'HorizontalRule' => 1,
          'Cut' => 1,
          'Copy' => 1,
          'Paste' => 1,
          'PasteText' => 1,
          'PasteFromWord' => 1,
          'RemoveFormat' => 1,
          'Styles' => 1,
          'Table' => 1,
          'Scayt' => 1,
        ),
        'drupal_path' => array(
          'Link' => 1,
        ),
        'drupal' => array(
          'embed' => 1,
          'entity' => 1,
          'node' => 1,
          'media' => 1,
          'break' => 1,
        ),
      ),
      'toolbar_loc' => 'top',
      'toolbar_align' => 'left',
      'path_loc' => 'bottom',
      'resizing' => 1,
      'verify_html' => 1,
      'preformatted' => 0,
      'convert_fonts_to_spans' => 1,
      'remove_linebreaks' => 1,
      'apply_source_formatting' => 1,
      'paste_auto_cleanup_on_paste' => 1,
      'block_formats' => 'p,h2,h3,h4,h5,h6,div.primary',
      'css_setting' => 'self',
      'css_path' => '/sites/all/themes/tp4/css/campaign-wysiwyg.css?v=2',
      'css_classes' => 'h1=h1
h2=h2
h3=h3
h4=h4
h5=h5
h6=h6
primary button=span.primary-button
secondary button=span.secondary-button
media caption=span.media-caption',
    ),
  );

  return $profiles;
}

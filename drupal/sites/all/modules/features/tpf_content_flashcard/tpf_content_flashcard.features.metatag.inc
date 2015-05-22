<?php
/**
 * @file
 * tpf_content_flashcard.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function tpf_content_flashcard_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: node:flashcard.
  $config['node:flashcard'] = array(
    'instance' => 'node:flashcard',
    'config' => array(
      'description' => array(
        'value' => '[node:field_article_subhead]',
      ),
      'abstract' => array(
        'value' => '[node:field_article_subhead]',
      ),
      'og:description' => array(
        'value' => '[node:field_article_subhead]',
      ),
    ),
  );

  return $config;
}

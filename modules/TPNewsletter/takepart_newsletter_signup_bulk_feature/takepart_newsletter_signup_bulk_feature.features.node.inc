<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _takepart_newsletter_signup_bulk_feature_node_info() {
  $items = array(
    'email_batch_load' => array(
      'name' => t('Email Batch'),
      'module' => 'features',
      'description' => t('Used to load and then record the loading of emails via .csv file'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

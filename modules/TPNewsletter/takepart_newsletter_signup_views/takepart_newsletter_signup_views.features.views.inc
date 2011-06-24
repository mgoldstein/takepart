<?php

/**
 * Helper to implementation of hook_views_default_views().
 */
function _takepart_newsletter_signup_views_views_default_views() {
  $views = array();

  // Exported view: takepart_newsletter_signups
  $view = new view;
  $view->name = 'takepart_newsletter_signups';
  $view->description = '';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'tp_newsletter_signups';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'status' => array(
      'label' => 'status',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 0,
      'id' => 'status',
      'table' => 'tp_newsletter_signups',
      'field' => 'status',
      'relationship' => 'none',
    ),
    'campaign_id' => array(
      'label' => 'campaign_id',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 0,
      'id' => 'campaign_id',
      'table' => 'tp_newsletter_signups',
      'field' => 'campaign_id',
      'relationship' => 'none',
    ),
    'mail' => array(
      'label' => 'mail',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 0,
      'id' => 'mail',
      'table' => 'tp_newsletter_signups',
      'field' => 'mail',
      'relationship' => 'none',
    ),
    'uid' => array(
      'label' => 'uid',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'set_precision' => FALSE,
      'precision' => 0,
      'decimal' => '.',
      'separator' => ',',
      'prefix' => '',
      'suffix' => '',
      'exclude' => 0,
      'id' => 'uid',
      'table' => 'tp_newsletter_signups',
      'field' => 'uid',
      'relationship' => 'none',
    ),
    'source' => array(
      'label' => 'source',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 0,
      'id' => 'source',
      'table' => 'tp_newsletter_signups',
      'field' => 'source',
      'relationship' => 'none',
    ),
    'subscribe_date' => array(
      'label' => 'subscribe_date',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'set_precision' => FALSE,
      'precision' => 0,
      'decimal' => '.',
      'separator' => ',',
      'prefix' => '',
      'suffix' => '',
      'exclude' => 0,
      'id' => 'subscribe_date',
      'table' => 'tp_newsletter_signups',
      'field' => 'subscribe_date',
      'relationship' => 'none',
    ),
    'unsubscribe_date' => array(
      'label' => 'unsubscribe_date',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'set_precision' => FALSE,
      'precision' => 0,
      'decimal' => '.',
      'separator' => ',',
      'prefix' => '',
      'suffix' => '',
      'exclude' => 0,
      'id' => 'unsubscribe_date',
      'table' => 'tp_newsletter_signups',
      'field' => 'unsubscribe_date',
      'relationship' => 'none',
    ),
    'tns_id' => array(
      'label' => 'tns_id',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'set_precision' => FALSE,
      'precision' => 0,
      'decimal' => '.',
      'separator' => ',',
      'prefix' => '',
      'suffix' => '',
      'exclude' => 0,
      'id' => 'tns_id',
      'table' => 'tp_newsletter_signups',
      'field' => 'tns_id',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'campaign_id' => array(
      'operator' => '=',
      'value' => '',
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'campaign_id_op',
        'identifier' => 'campaign_id',
        'label' => 'campaign_id',
        'optional' => 1,
        'remember' => 1,
      ),
      'case' => 1,
      'id' => 'campaign_id',
      'table' => 'tp_newsletter_signups',
      'field' => 'campaign_id',
      'relationship' => 'none',
    ),
    'mail' => array(
      'operator' => '=',
      'value' => '',
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 1,
        'operator' => 'mail_op',
        'identifier' => 'mail',
        'label' => 'mail',
        'optional' => 1,
        'remember' => 1,
      ),
      'case' => 1,
      'id' => 'mail',
      'table' => 'tp_newsletter_signups',
      'field' => 'mail',
      'relationship' => 'none',
    ),
    'source' => array(
      'operator' => '=',
      'value' => '',
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'source_op',
        'identifier' => 'source',
        'label' => 'source',
        'optional' => 1,
        'remember' => 1,
      ),
      'case' => 1,
      'id' => 'source',
      'table' => 'tp_newsletter_signups',
      'field' => 'source',
      'relationship' => 'none',
    ),
    'status' => array(
      'operator' => '=',
      'value' => '',
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'status_op',
        'identifier' => 'status',
        'label' => 'status',
        'optional' => 1,
        'remember' => 1,
      ),
      'case' => 1,
      'id' => 'status',
      'table' => 'tp_newsletter_signups',
      'field' => 'status',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('items_per_page', 50);
  $handler->override_option('use_pager', '1');
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'columns' => array(
      'campaign_id' => 'campaign_id',
      'mail' => 'mail',
      'source' => 'source',
      'status' => 'status',
      'subscribe_date' => 'subscribe_date',
      'tns_id' => 'tns_id',
      'uid' => 'uid',
      'unsubscribe_date' => 'unsubscribe_date',
    ),
    'info' => array(
      'campaign_id' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'mail' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'source' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'status' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'subscribe_date' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'tns_id' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'uid' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'unsubscribe_date' => array(
        'sortable' => 0,
        'separator' => '',
      ),
    ),
    'default' => '-1',
  ));
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->override_option('path', 'admin/settings/takepart-newsletter-signup/signups');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));

  $views[$view->name] = $view;

  // Exported view: tp_newsletter_signup_bulk_queue
  $view = new view;
  $view->name = 'tp_newsletter_signup_bulk_queue';
  $view->description = '';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'tp_newsletter_signup_bulk_queue';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'action' => array(
      'id' => 'action',
      'table' => 'tp_newsletter_signup_bulk_queue',
      'field' => 'action',
    ),
    'email' => array(
      'id' => 'email',
      'table' => 'tp_newsletter_signup_bulk_queue',
      'field' => 'email',
    ),
    'campaign_code' => array(
      'id' => 'campaign_code',
      'table' => 'tp_newsletter_signup_bulk_queue',
      'field' => 'campaign_code',
    ),
    'source' => array(
      'id' => 'source',
      'table' => 'tp_newsletter_signup_bulk_queue',
      'field' => 'source',
    ),
    'is_processed' => array(
      'id' => 'is_processed',
      'table' => 'tp_newsletter_signup_bulk_queue',
      'field' => 'is_processed',
    ),
    'is_preprocessed' => array(
      'id' => 'is_preprocessed',
      'table' => 'tp_newsletter_signup_bulk_queue',
      'field' => 'is_preprocessed',
    ),
    'has_error' => array(
      'id' => 'has_error',
      'table' => 'tp_newsletter_signup_bulk_queue',
      'field' => 'has_error',
    ),
    'error_msg' => array(
      'id' => 'error_msg',
      'table' => 'tp_newsletter_signup_bulk_queue',
      'field' => 'error_msg',
    ),
    'load_nid' => array(
      'id' => 'load_nid',
      'table' => 'tp_newsletter_signup_bulk_queue',
      'field' => 'load_nid',
    ),
    'send_welcome' => array(
      'id' => 'send_welcome',
      'table' => 'tp_newsletter_signup_bulk_queue',
      'field' => 'send_welcome',
    ),
    'queue_id' => array(
      'id' => 'queue_id',
      'table' => 'tp_newsletter_signup_bulk_queue',
      'field' => 'queue_id',
    ),
  ));
  $handler->override_option('filters', array(
    'action' => array(
      'operator' => '=',
      'value' => '',
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'action_op',
        'identifier' => 'action',
        'label' => 'action',
        'optional' => 1,
        'remember' => 1,
      ),
      'case' => 0,
      'id' => 'action',
      'table' => 'tp_newsletter_signup_bulk_queue',
      'field' => 'action',
      'relationship' => 'none',
    ),
    'email' => array(
      'operator' => '=',
      'value' => '',
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 1,
        'operator' => 'email_op',
        'identifier' => 'email',
        'label' => 'email',
        'optional' => 1,
        'remember' => 1,
      ),
      'case' => 0,
      'id' => 'email',
      'table' => 'tp_newsletter_signup_bulk_queue',
      'field' => 'email',
      'relationship' => 'none',
    ),
    'load_nid' => array(
      'operator' => '=',
      'value' => array(
        'value' => '',
        'min' => '',
        'max' => '',
      ),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 1,
        'operator' => 'load_nid_op',
        'identifier' => 'load_nid',
        'label' => 'load_nid',
        'optional' => 1,
        'remember' => 1,
      ),
      'id' => 'load_nid',
      'table' => 'tp_newsletter_signup_bulk_queue',
      'field' => 'load_nid',
      'relationship' => 'none',
    ),
    'is_preprocessed' => array(
      'operator' => '=',
      'value' => array(
        'value' => '',
        'min' => '',
        'max' => '',
      ),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'is_preprocessed_op',
        'identifier' => 'is_preprocessed',
        'label' => 'is_preprocessed',
        'optional' => 1,
        'remember' => 1,
      ),
      'id' => 'is_preprocessed',
      'table' => 'tp_newsletter_signup_bulk_queue',
      'field' => 'is_preprocessed',
      'relationship' => 'none',
    ),
    'is_processed' => array(
      'operator' => '=',
      'value' => array(
        'value' => '',
        'min' => '',
        'max' => '',
      ),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'is_processed_op',
        'identifier' => 'is_processed',
        'label' => ' is_processed',
        'optional' => 1,
        'remember' => 1,
      ),
      'id' => 'is_processed',
      'table' => 'tp_newsletter_signup_bulk_queue',
      'field' => 'is_processed',
      'relationship' => 'none',
    ),
    'has_error' => array(
      'operator' => '=',
      'value' => array(
        'value' => '',
        'min' => '',
        'max' => '',
      ),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'has_error_op',
        'identifier' => 'has_error',
        'label' => ' has_error',
        'optional' => 1,
        'remember' => 1,
      ),
      'id' => 'has_error',
      'table' => 'tp_newsletter_signup_bulk_queue',
      'field' => 'has_error',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('items_per_page', 50);
  $handler->override_option('use_pager', '1');
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'columns' => array(
      'action' => 'action',
      'campaign_code' => 'campaign_code',
      'email' => 'email',
      'error_msg' => 'error_msg',
      'has_error' => 'has_error',
      'is_preprocessed' => 'is_preprocessed',
      'is_processed' => 'is_processed',
      'load_nid' => 'load_nid',
      'queue_id' => 'queue_id',
      'send_welcome' => 'send_welcome',
      'source' => 'source',
    ),
    'info' => array(
      'action' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'campaign_code' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'email' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'error_msg' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'has_error' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'is_preprocessed' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'is_processed' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'load_nid' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'queue_id' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'send_welcome' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'source' => array(
        'sortable' => 0,
        'separator' => '',
      ),
    ),
    'default' => '-1',
  ));
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->override_option('path', 'admin/settings/takepart-newsletter-signup/queue');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));

  $views[$view->name] = $view;

  return $views;
}

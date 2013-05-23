<?php
/**
 * @file
 * takepart_mos.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function takepart_mos_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'takepart_mos_admin_signatures';
  $view->description = 'Messages of Support Signatures admin page';
  $view->tag = 'default';
  $view->base_table = 'signature';
  $view->human_name = 'Messages of Support Signatures admin page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Messages of Support Signatures';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer mos signatures';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'id' => 'id',
    'field_sig_first_name' => 'field_sig_first_name',
    'field_sig_last_name' => 'field_sig_last_name',
    'field_sig_country' => 'field_sig_country',
    'field_sig_state' => 'field_sig_state',
    'field_sig_city' => 'field_sig_city',
    'created' => 'created',
    'nothing' => 'nothing',
    'field_mos_user_custom_message' => 'field_mos_user_custom_message',
    'nothing_1' => 'nothing_1',
    'display_1' => 'display_1',
    'status' => 'status',
    'php' => 'php',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_sig_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_sig_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_sig_country' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_sig_state' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_sig_city' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mos_user_custom_message' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'display_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Bulk operations: Signature */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'signature';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::signature_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::signature_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Signature: Signature ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'signature';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: Signature: First Name */
  $handler->display->display_options['fields']['field_sig_first_name']['id'] = 'field_sig_first_name';
  $handler->display->display_options['fields']['field_sig_first_name']['table'] = 'field_data_field_sig_first_name';
  $handler->display->display_options['fields']['field_sig_first_name']['field'] = 'field_sig_first_name';
  $handler->display->display_options['fields']['field_sig_first_name']['exclude'] = TRUE;
  /* Field: Signature: Last Name */
  $handler->display->display_options['fields']['field_sig_last_name']['id'] = 'field_sig_last_name';
  $handler->display->display_options['fields']['field_sig_last_name']['table'] = 'field_data_field_sig_last_name';
  $handler->display->display_options['fields']['field_sig_last_name']['field'] = 'field_sig_last_name';
  $handler->display->display_options['fields']['field_sig_last_name']['exclude'] = TRUE;
  /* Field: Signature: Country */
  $handler->display->display_options['fields']['field_sig_country']['id'] = 'field_sig_country';
  $handler->display->display_options['fields']['field_sig_country']['table'] = 'field_data_field_sig_country';
  $handler->display->display_options['fields']['field_sig_country']['field'] = 'field_sig_country';
  $handler->display->display_options['fields']['field_sig_country']['exclude'] = TRUE;
  /* Field: Signature: State */
  $handler->display->display_options['fields']['field_sig_state']['id'] = 'field_sig_state';
  $handler->display->display_options['fields']['field_sig_state']['table'] = 'field_data_field_sig_state';
  $handler->display->display_options['fields']['field_sig_state']['field'] = 'field_sig_state';
  $handler->display->display_options['fields']['field_sig_state']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sig_state']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_sig_state']['alter']['text'] = ', [field_sig_state]';
  /* Field: Signature: City */
  $handler->display->display_options['fields']['field_sig_city']['id'] = 'field_sig_city';
  $handler->display->display_options['fields']['field_sig_city']['table'] = 'field_data_field_sig_city';
  $handler->display->display_options['fields']['field_sig_city']['field'] = 'field_sig_city';
  $handler->display->display_options['fields']['field_sig_city']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sig_city']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_sig_city']['alter']['text'] = ', [field_sig_city]';
  /* Field: Signature: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'signature';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Author';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_sig_first_name] [field_sig_last_name]  ';
  /* Field: Signature: User Custom Message */
  $handler->display->display_options['fields']['field_mos_user_custom_message']['id'] = 'field_mos_user_custom_message';
  $handler->display->display_options['fields']['field_mos_user_custom_message']['table'] = 'field_data_field_mos_user_custom_message';
  $handler->display->display_options['fields']['field_mos_user_custom_message']['field'] = 'field_mos_user_custom_message';
  $handler->display->display_options['fields']['field_mos_user_custom_message']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_mos_user_custom_message']['settings'] = array(
    'trim_length' => '120',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Location';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_sig_country][field_sig_state][field_sig_city]';
  /* Field: Signature: Display */
  $handler->display->display_options['fields']['display_1']['id'] = 'display_1';
  $handler->display->display_options['fields']['display_1']['table'] = 'signature';
  $handler->display->display_options['fields']['display_1']['field'] = 'display';
  $handler->display->display_options['fields']['display_1']['label'] = 'Public Display';
  $handler->display->display_options['fields']['display_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['display_1']['alter']['text'] = 'Yes';
  $handler->display->display_options['fields']['display_1']['empty'] = 'No';
  $handler->display->display_options['fields']['display_1']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['display_1']['separator'] = '';
  /* Field: Signature: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'signature';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['status']['alter']['text'] = 'Published';
  $handler->display->display_options['fields']['status']['empty'] = 'Not Published';
  $handler->display->display_options['fields']['status']['empty_zero'] = TRUE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Operations';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php print l(t(\'Edit\'), \'admin/content/signature/manage/\'.$row->id, array(\'query\' => drupal_get_destination())); ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Filter criterion: Signature: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'signature';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'mos_signature' => 'mos_signature',
  );
  /* Filter criterion: Signature: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'signature';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['status']['group_info']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['group_info']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Published',
      'operator' => '=',
      'value' => array(
        'value' => '1',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => 'Not Published',
      'operator' => '=',
      'value' => array(
        'value' => '0',
        'min' => '',
        'max' => '',
      ),
    ),
  );
  /* Filter criterion: Signature: Display */
  $handler->display->display_options['filters']['display']['id'] = 'display';
  $handler->display->display_options['filters']['display']['table'] = 'signature';
  $handler->display->display_options['filters']['display']['field'] = 'display';
  $handler->display->display_options['filters']['display']['exposed'] = TRUE;
  $handler->display->display_options['filters']['display']['expose']['operator_id'] = 'display_op';
  $handler->display->display_options['filters']['display']['expose']['label'] = 'Display';
  $handler->display->display_options['filters']['display']['expose']['operator'] = 'display_op';
  $handler->display->display_options['filters']['display']['expose']['identifier'] = 'display';
  $handler->display->display_options['filters']['display']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['display']['group_info']['label'] = 'Display';
  $handler->display->display_options['filters']['display']['group_info']['identifier'] = 'display';
  $handler->display->display_options['filters']['display']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Yes',
      'operator' => '=',
      'value' => array(
        'value' => '1',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => 'No',
      'operator' => '=',
      'value' => array(
        'value' => '0',
        'min' => '',
        'max' => '',
      ),
    ),
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/config/mos-signatures';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Messages of Support Signatures';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $export['takepart_mos_admin_signatures'] = $view;

  $view = new view();
  $view->name = 'takepart_mos_signatures';
  $view->description = 'Messages of Support Signatures admin page';
  $view->tag = 'default';
  $view->base_table = 'signature';
  $view->human_name = 'Messages of Support Signatures Block';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Messages of Support Signatures';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Signature: First Name */
  $handler->display->display_options['fields']['field_sig_first_name']['id'] = 'field_sig_first_name';
  $handler->display->display_options['fields']['field_sig_first_name']['table'] = 'field_data_field_sig_first_name';
  $handler->display->display_options['fields']['field_sig_first_name']['field'] = 'field_sig_first_name';
  $handler->display->display_options['fields']['field_sig_first_name']['exclude'] = TRUE;
  /* Field: Signature: Last Name */
  $handler->display->display_options['fields']['field_sig_last_name']['id'] = 'field_sig_last_name';
  $handler->display->display_options['fields']['field_sig_last_name']['table'] = 'field_data_field_sig_last_name';
  $handler->display->display_options['fields']['field_sig_last_name']['field'] = 'field_sig_last_name';
  $handler->display->display_options['fields']['field_sig_last_name']['exclude'] = TRUE;
  /* Field: Signature: Country */
  $handler->display->display_options['fields']['field_sig_country']['id'] = 'field_sig_country';
  $handler->display->display_options['fields']['field_sig_country']['table'] = 'field_data_field_sig_country';
  $handler->display->display_options['fields']['field_sig_country']['field'] = 'field_sig_country';
  $handler->display->display_options['fields']['field_sig_country']['exclude'] = TRUE;
  /* Field: Signature: State */
  $handler->display->display_options['fields']['field_sig_state']['id'] = 'field_sig_state';
  $handler->display->display_options['fields']['field_sig_state']['table'] = 'field_data_field_sig_state';
  $handler->display->display_options['fields']['field_sig_state']['field'] = 'field_sig_state';
  $handler->display->display_options['fields']['field_sig_state']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sig_state']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_sig_state']['alter']['text'] = ', [field_sig_state]';
  /* Field: Signature: City */
  $handler->display->display_options['fields']['field_sig_city']['id'] = 'field_sig_city';
  $handler->display->display_options['fields']['field_sig_city']['table'] = 'field_data_field_sig_city';
  $handler->display->display_options['fields']['field_sig_city']['field'] = 'field_sig_city';
  $handler->display->display_options['fields']['field_sig_city']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sig_city']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_sig_city']['alter']['text'] = ', [field_sig_city]';
  /* Field: Signature: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'signature';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['date_format'] = 'time ago';
  /* Field: Signature: User Custom Message */
  $handler->display->display_options['fields']['field_mos_user_custom_message']['id'] = 'field_mos_user_custom_message';
  $handler->display->display_options['fields']['field_mos_user_custom_message']['table'] = 'field_data_field_mos_user_custom_message';
  $handler->display->display_options['fields']['field_mos_user_custom_message']['field'] = 'field_mos_user_custom_message';
  $handler->display->display_options['fields']['field_mos_user_custom_message']['label'] = '';
  $handler->display->display_options['fields']['field_mos_user_custom_message']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mos_user_custom_message']['settings'] = array(
    'trim_length' => '120',
  );
  /* Field: Author */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Author';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_sig_first_name] [field_sig_last_name]  ';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Location */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Location';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_sig_country][field_sig_state][field_sig_city] ([created])';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Sort criterion: Signature: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'signature';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Signature: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'signature';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'mos_action' => 'mos_action',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['access'] = TRUE;
  /* Filter criterion: Signature: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'signature';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'mos_signature' => 'mos_signature',
  );
  /* Filter criterion: Signature: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'signature';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['operator'] = '!=';
  $handler->display->display_options['filters']['status']['value']['value'] = '0';
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['status']['group_info']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['group_info']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Published',
      'operator' => '=',
      'value' => array(
        'value' => '1',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => 'Not Published',
      'operator' => '=',
      'value' => array(
        'value' => '0',
        'min' => '',
        'max' => '',
      ),
    ),
  );
  /* Filter criterion: Signature: Display */
  $handler->display->display_options['filters']['display']['id'] = 'display';
  $handler->display->display_options['filters']['display']['table'] = 'signature';
  $handler->display->display_options['filters']['display']['field'] = 'display';
  $handler->display->display_options['filters']['display']['operator'] = '!=';
  $handler->display->display_options['filters']['display']['value']['value'] = '0';
  $handler->display->display_options['filters']['display']['expose']['operator_id'] = 'display_op';
  $handler->display->display_options['filters']['display']['expose']['label'] = 'Display';
  $handler->display->display_options['filters']['display']['expose']['operator'] = 'display_op';
  $handler->display->display_options['filters']['display']['expose']['identifier'] = 'display';
  $handler->display->display_options['filters']['display']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['display']['group_info']['label'] = 'Display';
  $handler->display->display_options['filters']['display']['group_info']['identifier'] = 'display';
  $handler->display->display_options['filters']['display']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Yes',
      'operator' => '=',
      'value' => array(
        'value' => '1',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => 'No',
      'operator' => '=',
      'value' => array(
        'value' => '0',
        'min' => '',
        'max' => '',
      ),
    ),
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $export['takepart_mos_signatures'] = $view;

  return $export;
}

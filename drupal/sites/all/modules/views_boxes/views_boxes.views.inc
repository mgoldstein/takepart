<?php

function views_boxes_views_data() {
  $data['views_boxes']['table']['group']  = t('Boxes');
  $data['views_boxes']['table']['join'] = array(
    '#boxes' => array(),
  );
  $data['views']['limit'] = array(
    'title' => t('Limit'),
    'help' => t('Limit the number of records returned.'),
    'argument' => array(
      'handler' => 'views_boxes_handler_argument_limit',
    ),
  );
  $data['views']['sort'] = array(
    'title' => t('Sort'),
    'help' => t('Limit which items can but used for sort.'),
    'filter' => array(
      'handler' => 'views_boxes_handler_filter_sort',
    ),
  );
  /*
  $data['views_sort_by_arg_order']['table']['group']  = t('Arguments');
  $data['views_sort_by_arg_order']['table']['join']  = array(
      '#global' => array(),

  );
  $data['views_sort_by_arg_order']['weight'] = array(
    'title' => t('Multi-item Argument Order'),
    'help' => t('Sort by the order of items in an multi-item argument'),
    'sort' => array(
      'handler' => 'views_sort_by_arg_order_handler_sort',
    ),
  );
*/
  return $data;
}



<?php

function takepart_custom_block_info() {

  return array(
    'page_title_h1' => array(
      'info' => t('Page Title in H1'),
    ),
  );
}
function takepart_custom_block_view($delta='page_title') {
  $block['content'] = '<h1>' . drupal_get_title(). '</h1>';
  return $block;
}

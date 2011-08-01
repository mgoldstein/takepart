<?php

function takepart_custom_block_info() {

  return array(
    'page_title_h1' => array(
      'info' => t('Page Title in H1'),
    ),
    'slideshow_controls' => array(
      'info' => t('SlideShow Controls'),
    ),
  );
}
function takepart_custom_block_view($delta='page_title') {
  switch($delta) {
    case 'slideshow_controls':
      $block['content'] = "<div id='ss_controls'></div>";
      drupal_add_js(drupal_get_path("module", "takepart_custom") ."/takepart_custom.ss_controls.js", array("scope"=>"footer"));
    break;
    default :
      $block['content'] = '<h1>' . drupal_get_title(). '</h1>';
  }
  return $block;
}

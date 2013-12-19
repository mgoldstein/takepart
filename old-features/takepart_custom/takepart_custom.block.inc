<?php

function takepart_custom_block_info() {

  return array(
    'page_title_h1' => array(
      'info' => t('Page Title in H1'),
    ),
    'slideshow_controls' => array(
      'info' => t('SlideShow Controls'),
    ),
    'gallery_embed' => array(
      'info' => t('Gallery Embed'),
    ),
  );
}
function takepart_custom_block_view($delta='page_title') {
  switch($delta) {
    case 'slideshow_controls':
      $block['content'] = "<div id='ss_controls'></div>";
      drupal_add_js(drupal_get_path("module", "takepart_custom") ."/takepart_custom.ss_controls.js", array("scope"=>"footer"));
    break;
    case 'gallery_embed':
     $view = views_get_view('photo_gallery');
     $embed = $view->preview('block_2');
     $block['content'] = "embed : <input value ='$embed'>";

    break;
    default :
      $block['content'] = '<h1 class="title"><span>' . drupal_get_title() . '</span></h1>';
  }
  return $block;
}

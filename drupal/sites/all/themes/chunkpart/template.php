<?php
/*
  Preprocess
*/

/*
function chunkpart_preprocess_html(&$vars) {
  //  kpr($vars['content']);
}

function chunkpart_preprocess_page(&$vars,$hook) {
  //typekit
  //drupal_add_js('http://use.typekit.com/XXX.js', 'external');
  //drupal_add_js('try{Typekit.load();}catch(e){}', array('type' => 'inline'));

  //webfont
  //drupal_add_css('http://cloud.webtype.com/css/CXXXX.css','external');
  
  //googlefont 
  //  drupal_add_css('http://fonts.googleapis.com/css?family=Bree+Serif','external');
 
}

function chunkpart_preprocess_region(&$vars,$hook) {
  //  kpr($vars['content']);
}

function chunkpart_preprocess_block(&$vars, $hook) {
  //  kpr($vars['content']);

  //lets look for unique block in a region $region-$blockcreator-$delta
   $block =  
   $vars['elements']['#block']->region .'-'. 
   $vars['elements']['#block']->module .'-'. 
   $vars['elements']['#block']->delta;
   
  // print $block .' ';
   switch ($block) {
     case 'header-menu_block-2':
       $vars['classes_array'][] = '';
       break;
     case 'sidebar-system-navigation':
       $vars['classes_array'][] = '';
       break;
    default:
    
    break;

   }


  switch ($vars['elements']['#block']->region) {
    case 'header':
      $vars['classes_array'][] = '';
      break;
    case 'sidebar':
      $vars['classes_array'][] = '';
      $vars['classes_array'][] = '';
      break;
    default:

      break;
  }

}

function chunkpart_preprocess_node(&$vars,$hook) {
  //  kpr($vars['content']);
}

function chunkpart_preprocess_comment(&$vars,$hook) {
  //  kpr($vars['content']);
}

function chunkpart_preprocess_field(&$vars,$hook) {
  //  kpr($vars['content']);
  //add class to a specific field
  switch ($vars['element']['#field_name']) {
    case 'field_ROCK':
      $vars['classes_array'][] = 'classname1';
    case 'field_ROLL':
      $vars['classes_array'][] = 'classname1';
      $vars['classes_array'][] = 'classname2';
      $vars['classes_array'][] = 'classname1';
    case 'field_FOO':
      $vars['classes_array'][] = 'classname1';
    case 'field_BAR':
      $vars['classes_array'][] = 'classname1';    
    default:
      break;
  }

}

function chunkpart_preprocess_maintenance_page(){
  //  kpr($vars['content']);
}
*/

function takepart3_preprocess_entity(&$variables, $hook) {

    $variables["custom_render"] = array();

    switch ($variables['entity_type']) {
        case "bean":
            if($variables['bean']->{'type'} == "of_the_day") {
                //Look for a tpl file called bean--of-the-day-custom.tpl.php:
                $variables['theme_hook_suggestions'][] = 'bean__of_the_day_custom';
                $acnids = $variables['bean']->{'field_associated_content'}['und'];

                for ($i = 0; $i <= sizeof($acnids); $i++) {

                    $acnid = $variables['bean']->{'field_associated_content'}['und'][$i]['nid'];
                    $node = node_load($acnid);

                    if($node->type == 'openpublish_article') {
                        $main_image = field_get_items('node', $node, 'field_article_main_image');
                    }
                    if($node->type == 'action') {
                        $main_image = field_get_items('node', $node, 'field_action_main_image');
                    }
                    if($node->type == 'openpublish_photo_gallery') {
                        $main_image = field_get_items('node', $node, 'field_gallery_main_image');
                    }                                                   
                    if($node->type == 'openpublish_video') {
                        $main_image = field_get_items('node', $node, 'field_main_image');
                    }

                    if(isset($main_image[0]['fid'])) {
                        $img_url = file_load($main_image[0]['fid']);
                        if(isset($img_url->{'uri'})){
                            $variables['custom_render'][$i]['thumbnail'] = image_style_url('thumbnail', $img_url->{'uri'});
                        }
                    }

                    $types = node_type_get_types();
                    if(isset($types[$node->type]->{'name'})) {
                        $variables['custom_render'][$i]['type'] = $types[$node->type]->{'name'};
                    }

                    if(isset($node->{'title'})) {
                        $variables['custom_render'][$i]['title'] = $node->{'title'};
                    }

                    $variables['custom_render'][$i]['url'] = url('node/'. $node->nid);
                }
            }
          break;
    }
}


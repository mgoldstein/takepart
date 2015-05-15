<ul class="promo-content">
  <?php
    foreach($items as $item){
      $field_collection = entity_load('field_collection_item', array($item['value']));
      $key = $item['value'];
      $node = node_load($field_collection[$key]->field_promo_content['und'][0]['target_id']);
      $path = drupal_get_path_alias('node/'. $node->nid);

      //Promo Headline
      $promo_headline = '';
      if(isset($field_collection[$key]->field_promo_headline['und'][0]['value'])){
        $promo_headline = $field_collection[$key]->field_promo_headline['und'][0]['value'];
      }
      elseif(isset($node->field_promo_headline['und'][0]['value'])){
        $promo_headline = $node->field_promo_headline['und'][0]['value'];
      }
      else{
        $promo_headline = $node->title;
      }

      //Promo Image
      $promo_image = '';
      if(isset($field_collection[$key]->field_promo_thumbnail['und'][0]['uri'])){
        $thumb_uri = $field_collection[$key]->field_promo_thumbnail['und'][0]['uri'];
        $promo_image = '<img src="'. image_style_url('topic_feature', $thumb_uri). '">';
      }
      else{
        $thumb = file_load($node->field_thumbnail['und'][0]['fid']);
        $promo_image = '<img src="'. image_style_url('topic_feature', $thumb->uri). '">';
      }

      //Output
      $output = '<li>';
      $output .= '<div class="promo-image">'. l($promo_image, $path, array('html' => true)). '</div>';
      $output .= '<div class="promo-headline">'. l($promo_headline, $path, array('html' => true)). '</div>'._tp4_support_sponsor_flag($node);
      $output .= '</li>';

      print $output;
    }
  ?>
</ul>
<div class="clearfix"></div>
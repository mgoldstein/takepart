<?php
/**
 * @file
 * Campaign promo sidebar inline content controller.
 */

class InlineContentCampaignPromo extends InlineContentReplacementController {

  /**
   * Update the replacement content's display label.
   */
  public function updateLabel($replacement) {

    // Format the label.
    $replacement->label = t('Campaign Promo Sidebar');
  }

  /**
   * Return the replacement content.
   */
  public function view($replacement, $content, $view_mode = 'default', $langcode = NULL) {

    //Find the campaign referenced on the current node
    $current_article_nid = $replacement -> nid;
    $node = node_load($current_article_nid);
    if (!isset($node -> field_editor_campaign_reference['und'][0]['target_id'])) {
      return false;
    }
    $campaign_id = $node -> field_editor_campaign_reference['und'][0]['target_id'];

    //Campaign Associated Info
    $campaign_info = array();
    $campaign = node_load($campaign_id);
    $campaign_info['title'] = $campaign -> title;
    $campaign_info['description'] = $campaign ->field_content_menu_description[LANGUAGE_NONE][0]['value'];
    $campaign_info['url'] = url('node/'.$campaign_id, array('absolute' => TRUE));
    $campaign_info['vol'] = $campaign ->field_content_issue_volume[LANGUAGE_NONE][0]['value'];
    $campaign_info['bg_color'] = $campaign ->field_content_promo_bg[LANGUAGE_NONE][0]['rgb'];

    //Queue for all the nodes that reference the campaign_id
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
    ->propertyCondition('status', 1)
    ->addTag('CICPromoPub')
    ->fieldCondition('field_editor_campaign_reference','target_id',$campaign_id,'=');

    $result = $query->execute();

    $campaign_info['story_num'] = count($result['node']);

    $article_ctr = 0;

    //$cic_info array will hold promo title and img
    $cic_info = array();

    //Check if auto grab promos or custom override promos
    if($override_promos = field_get_items('inline_content', $replacement, 'field_ic_campaign_promos')) {
      //Custom Promo Display
      //set to 3 to enter display
      foreach($override_promos AS $override_promo) {
        $this->getStoryNodes($cic_info, $override_promo['entity'], $article_ctr);
        $article_ctr++;
      }
    }

    if($article_ctr < 3) {
      foreach ($result['node'] as $key => $cid) {
        //Don't display the current article
        if ($current_article_nid != $cid->nid) {
          $this->getStoryNodes($cic_info, $cid, $article_ctr);

          $article_ctr++;
          //Only 3 stories diplayed on the sidebar
          if ($article_ctr == 3) {
            break;
          }
        }
      }
    }

    //Admin check show unpublished
    if($article_ctr < 3) {
      if(user_access('view any unpublished content')) {
        //Provide unpublished articles
        $query = new EntityFieldQuery();
        $query->entityCondition('entity_type', 'node')
        ->propertyCondition('status', 0)
        ->propertyOrderBy('created', 'DESC')
        ->fieldCondition('field_editor_campaign_reference','target_id',$campaign_id,'=');
        $result = $query->execute();

        foreach ($result['node'] as $key => $cid) {
          //Don't display the current article
          if ($current_article_nid != $cid->nid) {
            $this->getStoryNodes($cic_info, $cid, $article_ctr);
            $article_ctr++;
            //Only 3 stories diplayed on the sidebar
            if ($article_ctr == 3) {
              break;
            }
          }
        }
        $campaign_info['story_num'] = $campaign_info['story_num'] + count($result['node']);
      }
    }

    //Nothing will show up if there is only 1 node tagged
    if ($article_ctr > 0) {
      if($campaign_info['story_num'] >= 5) {
        $campaign_info['footer'] = t('See all @numb stories', array('@numb' => $campaign_info['story_num']));
      } else {
        $campaign_info['footer'] = t('See all stories', array('@numb' => $campaign_info['story_num']));
      }
      $markup = theme('inline_content_campaign_promo' , array(
        'campaign_info' => $campaign_info,
        'cic_info' => $cic_info
      ));
      $content['#replacements'][] = array(
        '#type' => 'markup',
        '#markup' => $markup,
      );
    }

    return $content;

  }

  /**
   * Function to get the node information and add it to the info array
   */
  public function getStoryNodes(&$cic_info, $cid, $article_ctr) {
      //Grab the promo title and thumbnail image
      $cic  = node_load($cid->nid);
      $cic_info[$article_ctr]['title'] = $cic->field_promo_headline['und'][0]['value'];
      $cic_info[$article_ctr]['nid'] = $cid->nid;
      $cic_info[$article_ctr]['status'] = $cic->status;
      $fid = $cic->field_thumbnail['und'][0]['fid'];
      if(!isset($fid) || empty($fid)) {
        return;
      }
      $cic_thumb = file_load($fid);
      //This image style could differ once we have final designs.
      $cic_info[$article_ctr]['thumbnail'] = image_style_url('inline_thumbnail', $cic_thumb->uri);
  }

}

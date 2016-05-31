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
    $replacement->label = t('Campaing Promo SideBar');
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
    $campaign = node_load($campaign_id);
    $campaign_title = $campaign -> title;
    $campaign_description = $campaign ->field_content_menu_description['und'][0]['value'];
    $campaign_url = url('node/'.$campaign_id, array('absolute' => TRUE));

    //Queue for all the nodes that reference the campaign_id
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
    ->propertyCondition('status', 1)
    ->propertyOrderBy('changed', 'DESC')
    ->fieldCondition('field_editor_campaign_reference','target_id',$campaign_id,'=');

    $result = $query->execute();
    $article_ctr = 0;
    //$cic_info array will hold promo title and img
    $cic_info = array();
    foreach ($result['node'] as $key => $cid) {
      //Don't display the current article
      if ($current_article_nid != $cid->nid) {
        //Grab the promo title and thumbnail image
        $cic  = node_load($cid->nid);
        $cic_info[$article_ctr]['title'] = $cic->field_promo_headline['und'][0]['value'];
        $fid = $cic->field_thumbnail['und'][0]['fid'];
        $cic_thumb = file_load($fid);
        //This image style could differ once we have final designs.
        $cic_info[$article_ctr]['thumbnail'] = image_style_url('inline_thumbnail', $cic_thumb->uri);

        $article_ctr++;
        //Only 3 stories diplayed on the sidebar
        if ($article_ctr == 3) {
          break;
        }
      }
    }
    $story_num = count($result['node']);
    //TODO:Need to determine what to display when this the only node associated with the campaign.
    if ($story_num > 0) {
    $markup = theme('inline_content_campaign_promo' , array(
      'campaign_title' => $campaign_title,
      'campaing_stories' => $story_num,
      'campaign_description' => $campaign_description,
      'campaign_url' => $campaign_url,
      'cic_info' => $cic_info
    ));
     $content['#replacements'][] = array(
      '#type' => 'markup',
        '#markup' => $markup,
     );
    }

    return $content;

  }

}

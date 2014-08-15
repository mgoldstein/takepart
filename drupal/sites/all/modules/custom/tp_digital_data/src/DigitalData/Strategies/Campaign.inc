<?php

class ddCampaign extends ddContent {

  public static function claim($path, $page) {
    // Claim campaign content pages
    if (parent::claim($path, $page)) {
      $node = reset($page['content']['system_main']['nodes']);
      return $node['#bundle'] == 'campaign_page';
    }
    return FALSE;
  }

  protected function getCampaignName($node) {
    $items = field_get_items('node', $node, 'field_campaign_reference');
    if ($items && $item = reset($items)) {
      if ($campaign_node = node_load($item['target_id'])) {
        return $campaign_node->title;
      }
    }
    return NULL;
  }

  public function build($page) {

    $data = parent::build($page);

    $node = menu_get_object();

    $campaign_name = $this->getCampaignName($node);
    if (!is_null($campaign_name)) {
      $data['page']['category']['campaign'] = $campaign_name;
    }

    return $data;
  }
}

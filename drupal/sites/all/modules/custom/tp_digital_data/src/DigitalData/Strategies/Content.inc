<?php

class ddContent extends ddDefaultPage {

  public static function claim($path, $page) {
    // Claim node pages.
    return preg_match('/^node\/[0-9]+/', $path);
  }

  protected function categoryForContentType($type) {
    $categories = array(
      'openpublish_article' => 'Article',
      'campaign_page' => 'Campaign',
      'page' => 'Page',
    );
    return array_key_exists($type, $categories) ? $categories[$type] : $type;
  }

  public function build($page) {

    $node = menu_get_object();

    $pageID = "node/{$node->nid}";

    $data = array(
      'pageInstanceID' => ENVIRONMENT . ': ' . $pageID,
      'page' => array(
        'pageInfo' => array(
          'pageID' => $pageID,
          'pageName' => $node->title,
        ),
        'category' => array(
          'primaryCategory' => $this->categoryForContentType($node->type),
        ),
      ),
    );
		/* This needs to come last to override default */
	  $data += parent::build($page);

    return $data;
  }
}

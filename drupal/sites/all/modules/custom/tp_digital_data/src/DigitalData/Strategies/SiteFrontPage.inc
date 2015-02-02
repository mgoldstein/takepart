<?php

class ddSiteFrontPage extends ddDefaultPage {

  public static function claim($path, $page) {
    // Claim the front page.
    $site_frontpage = variable_get('site_frontpage', 'node');
    return ($site_frontpage == $path);
  }

  public function build($page) {

    $pageID = 'Front Page';
    $environment = ENVIRONMENT;
    global $base_url;

    $data = array(
      'pageInstanceID' => "{$pageID} - {$environment}",
      'page' => array(
        'pageInfo' => array(
          'pageID' => $pageID,
          'primaryCateogry' => 'home',
          'siteSection' => 'home',
          'pageUrl' => $base_url,
          'pageUrlAlias' => 'home'
        ),
      ),
    );

	  $data += parent::build($page);

    return $data;
  }
}

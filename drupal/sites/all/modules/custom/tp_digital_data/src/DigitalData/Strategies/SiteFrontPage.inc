<?php

class ddSiteFrontPage extends ddDefaultPage {

  public static function claim($path, $page) {
    // Claim the front page.
    $site_frontpage = variable_get('site_frontpage', 'node');
    return ($site_frontpage == $path);
  }

  public function build($page) {

    $environment = ENVIRONMENT;

    $data = parent::build($page);

    $pageID = '<front>';

    $data['pageInstanceID'] = "{$environment}: {$pageID}";
    $data['page']['pageInfo']['pageID'] = $pageID;
    $data['page']['pageInfo']['title'] = "TakePart Home";

    return $data;
  }
}

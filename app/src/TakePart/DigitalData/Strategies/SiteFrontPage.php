<?php
namespace TakePart\DigitalData\Strategies;

use TakePart\DigitalData\BuildStrategy;
use TakePart\DigitalData\DigitalData;

class SiteFrontPage extends DefaultPage {

  public static function claim($path, $page) {
    // Claim the front page.
    $site_frontpage = variable_get('site_frontpage', 'node');
    return ($site_frontpage == $path);
  }

  public function build($page) {

    $data = parent::build($page);

    $pageID = 'Front Page';
    $environment = ENVIRONMENT;

    $data += array(
      'pageInstanceID' => "{$pageID} - {$environment}",
      'page' => array(
        'pageInfo' => array(
          'pageID' => $pageID,
          'pageName' => '',
        ),
      ),
    );

    return $data;
  }
}

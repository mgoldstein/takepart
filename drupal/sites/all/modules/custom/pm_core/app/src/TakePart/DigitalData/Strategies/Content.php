<?php
namespace TakePart\DigitalData\Strategies;

class Content extends DefaultPage {

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

    $data = parent::build($page);

    $pageID = "node/{$node->nid}";

    $data += array(
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

    return $data;
  }
}

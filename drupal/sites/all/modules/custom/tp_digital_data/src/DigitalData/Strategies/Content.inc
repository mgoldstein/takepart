<?php

class ddContent extends ddDefaultPage {

  public static function claim($path, $page) {
    // Claim node pages.
    return preg_match('/^node\/[0-9]+/', $path);
  }

  protected function contentTypeName($type) {
    $types = node_type_get_types();
    if (array_key_exists($type, $types)) {
      return $types[$type]->name;
    }
    return $type;
  }

  protected function termList($node, $field_name) {
    $items = field_get_items('node', $node, $field_name);
    $terms = array();
    if ($items !== FALSE && count($items) > 0) {
      foreach ($items as $item) {
        if (isset($item['taxonomy_term'])) {
          $terms[] = $item['taxonomy_term']->name;
        }
      }
    }
    return $terms;
  }

  protected function authorList($node, $field_name) {
    $items = field_get_items('node', $node, $field_name);
    $authors = array();
    if ($items !== FALSE && count($items) > 0) {
      $nids = array();
      foreach ($items as $item) { $nids[] = $item['nid']; }
      $author_nodes = entity_load('node', $nids);
      foreach($author_nodes as $node){
        $authors[] = $node->title;
      }
    }
    return $authors;
  }

  public function build($page) {

    $environment = ENVIRONMENT;

	  $data = parent::build($page);

    $node = menu_get_object();

    $pageID = "node/{$node->nid}";

    // Page
    $data['pageInstanceID'] = "{$environment}: {$pageID}";
    $data['page']['pageInfo']['pageID'] = $pageID;
    $data['page']['pageInfo']['title'] = $node->title;
    $data['page']['pageInfo']['template'] = $node->type;

	  // Authors
    $authors = $this->authorList($node, 'field_author');
    if (!empty($authors)) {
      $data['page']['pageInfo']['authors'] = $authors;
    }

    // Published date
    $publish_date = date('Y-m-d', $node->published_at);
    if (!is_null($publish_date)) {
      $data['page']['pageInfo']['issueDate'] = $publish_date;
    }

    // Categorization
    $data['page']['category'] = array(
      'primaryCategory' => $this->contentTypeName($node->type),
    );

	  // Topics
    $topics = $this->termList($node, 'field_topic');
    if (!empty($topics)) {
      $data['page']['category']['topics'] = $topics;
    }

	  // Series
    $series = $this->termList($node, 'field_series');
    if (!empty($series)) {
      $data['page']['category']['series'] = $series;
    }

	  // Free Tags
    $free_tags = $this->termList($node, 'field_free_tag');
    if (!empty($free_tags)) {
      $data['page']['category']['freeTags'] = $free_tags;
    }

    return $data;
  }
}

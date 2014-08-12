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

	  $data = array();
    $node = menu_get_object();

    $pageID = "node/{$node->nid}";

	  //authors
	  $ids = array();
	  if($authors = field_get_items('node', $node, 'field_author')){
		  foreach($authors as $id){
			  $ids[] = $id['nid'];
		  }

		  /* page: pageInfo: authors */
		  $author_entities = entity_load('node', $ids);
		  $author_names = array();
		  foreach($author_entities as $author){
			  $author_names[] = $author->title;
		  }
		  $author_names = implode(', ', $author_names);
		  $data['page']['pageInfo']['authors'] = $author_names;

		  /* page: pageInfo: author */
		  $author = reset($author_entities);
		  $author = $author->title;
		  $data['page']['pageInfo']['author'] = $author;
	  }

	  /*page: pageInfo: issueDate */
	  $publish_date = $node->published_at;
	  $publish_date = date('Y/m/d', $publish_date);
	  $data['page']['pageInfo']['issueDate'] = $publish_date;

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
		/* This needs to come last to override default */
	  $data += parent::build($page);

    return $data;
  }
}

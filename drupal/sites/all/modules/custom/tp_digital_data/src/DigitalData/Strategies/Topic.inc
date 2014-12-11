<?php

/**
 * Class ddTopic
 * Digital data layer for Topic pages that inherit settings from default
 *
 * Topic ID (
 */
class ddTopic extends ddDefaultPage {

  public static function claim($path, $page) {
    // Claim node taxonomy topic pages.
    if(preg_match('/^taxonomy\/term\/[0-9]+/', $path)){
      $bundle = $page['content']['system_main']['#bundle'];
      if($bundle == 'topic'){
        return TRUE;
      }
    }
  }

  public function build($page) {

    /* Load the term */
    $term = taxonomy_term_load(arg(2));

    /* Stuff for pageURL, pageUrlAlias, siteSection */
    global $base_url;
    $request_path = request_path();
    $url = $base_url. '/'. $request_path;

	  $data = array();

    $data['page']['pageInfo']['pageName'] = $term->name;
    $data['page']['pageInfo']['primaryCategory'] = $term->vocabulary_machine_name;
    $data['page']['pageInfo']['primaryTopic'] = $term->name;
    $data['page']['pageInfo']['siteSection'] = 'topic';
    $data['page']['pageInfo']['pageUrl'] = $url;
    $data['page']['pageInfo']['pageUrlAlias'] = $request_path;
	  
	  $data += parent::build($page);

    return $data;
  }
}
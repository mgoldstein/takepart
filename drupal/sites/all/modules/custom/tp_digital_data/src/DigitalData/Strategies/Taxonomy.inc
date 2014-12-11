<?php

/**
 * Class ddTopic
 * Digital data layer for Topic pages that inherit settings from default
 *
 * Topic ID (
 */
class ddTaxonomy extends ddDefaultPage {

  public static function claim($path, $page) {

    /* Claim taxonomy pages */
    return preg_match('/^taxonomy\/term\/[0-9]+/', $path);
  }

  public function build($page) {

    /* Load the term */
    $term = taxonomy_term_load(arg(2));

    /* Stuff for pageURL, pageUrlAlias, siteSection */
    global $base_url;
    $request_path = request_path();
    $url = $base_url. '/'. $request_path;
    $site_section = explode('/', $request_path);
    $site_section = $site_section[0];

    /* Set the data to be returned */
	  $data = array();
    $data['page']['pageInfo']['pageName'] = $term->name;
    $data['page']['pageInfo']['primaryCategory'] = $term->vocabulary_machine_name;
    $data['page']['pageInfo']['primaryTopic'] = $term->name;
    $data['page']['pageInfo']['siteSection'] = $site_section;
    $data['page']['pageInfo']['pageUrl'] = $url;
    $data['page']['pageInfo']['pageUrlAlias'] = $request_path;

    /* Taxonomy specific data */
    $data['page']['pageInfo']['taxonomy']['termName'] = $term->name;
    $data['page']['pageInfo']['taxonomy']['termID'] = $term->tid;
    $data['page']['pageInfo']['taxonomy']['termVocab'] = $term->vocabulary_machine_name;
	  
	  $data += parent::build($page);

    return $data;
  }
}
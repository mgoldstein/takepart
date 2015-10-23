<?php

function pm_metatag_sailthru_token_info() {
  $info['types']['sailthru_metatags'] = array(
    'name' => t('Custom SailThru'),
    'description' => t("Custom tokens for SailThru metatags"),
  );
  $info['tokens']['sailthru_metatags']['tags_type'] = array(
    'name' => t('Topic, Free Tags, and Content Type'),
    'description' => t("Combines Topic, Free Tags, and Content Type values into comma separated string for metatag"),
  );
  $info['tokens']['sailthru_metatags']['author'] = array(
    'name' => t('Content authors for Sailthru'),
    'description' => t("Authors in a comma separated string for metatag fields"),
  );
  return $info;
}

function _pm_metatag_sailthru_build($node) {
  $topics = $node->field_topic['und'];
  if (!empty($topics)) {
    foreach ($topics as $topic) {
	 $tid = $topic['tid'];
	 $term = taxonomy_term_load($tid);
	 $stripamp = str_replace(" & ", " ", $term->name);
	 $tag_array[] = str_replace(" ", "-", $stripamp);
    }
  }
  $freetags = $node->field_free_tag['und'];
  if (!empty($freetags)) {
    foreach ($freetags as $tag) {
	 $tid = $tag['tid'];
	 $term = taxonomy_term_load($tid);
	 $stripamp = str_replace(" & ", " ", $term->name);
	 $tag_array[] = str_replace(" ", "-", $stripamp);
    }
  }
  $tag_array[] = $node->type;
  $tag_str = implode(",", $tag_array);
  return strtolower($tag_str);
}

function _pm_metatag_sailthru_get_authors($node) {
  $aid = array();
  foreach (field_get_items('node', $node, 'field_author') as $delta => $item) {
    $aid[] = $item['nid'];
  }
  if (!empty($aid)) {
    $authors = array();
    foreach ($aid as $nid) {
	 $author = node_load($nid);
	 $authors[] = $author->title;
    }
  }
  return implode(', ', $authors);
}

function pm_metatag_sailthru_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  if ($type == 'sailthru_metatags') {
    foreach ($tokens as $name => $original) {
	 switch ($name) {
	   case 'tags_type':
		$replacements[$original] = _pm_metatag_sailthru_build($data['node']);
		break;

	   case 'author':
		$replacements[$original] = _pm_metatag_sailthru_get_authors($data['node']);
		break;
	 }
    }
    return $replacements;
  }
}

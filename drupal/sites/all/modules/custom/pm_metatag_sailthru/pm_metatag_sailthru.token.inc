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
  return $info;
}

function _pm_metatag_sailthru_build($node) {
  $topics = $node->field_topic['und'];
  if (!empty($topics)) {
    foreach ($topics as $topic) {
	 $tid = $topic['tid'];
	 $term = taxonomy_term_load($tid);
	 $tag_array[] = str_replace(" ", "-", $term->name);
    }
  }

  $freetags = $node->field_free_tag['und'];
  if (!empty($freetags)) {
    foreach ($freetags as $tag) {
	 $tid = $tag['tid'];
	 $term = taxonomy_term_load($tid);
	 $tag_array[] = str_replace(" ", "-", $term->name);
    }
  }

  $tag_array[] = $node->type;
  $tag_str = implode(",", $tag_array);
  $tag_fstr = strtolower($tag_str);
  return $tag_fstr;
}

function pm_metatag_sailthru_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  $sanitize = !empty($options['sanitize']);
  if ($type == 'sailthru_metatags') {
    foreach ($tokens as $name => $original) {
	 switch ($name) {
	   case 'tags_type':
		$replacements[$original] = _pm_metatag_sailthru_build($data['node']);
		break;
	 }
    }

    return $replacements;
  }
}

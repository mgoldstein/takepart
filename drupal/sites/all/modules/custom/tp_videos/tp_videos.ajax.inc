<?php
/**
 * @file
 * Custom implementation of two functions from entitiyreference
 * module to prevent having to patch the module.
 *
 *
 */

/**
 * Custom menu callback for autocompleting featured video widgets.
 *
 * @see entityreference_autocomplete_callback().
 */
function tp_videos_autocomplete_callback($type, $field_name, $entity_type, $bundle_name, $entity_id = '', $string = '') {
  // If the request has a '/' in the search text, then the menu system will have
  // split it into multiple arguments and $string will only be a partial. We want
  //  to make sure we recover the intended $string.
  $args = func_get_args();
  // Shift off the $type, $field_name, $entity_type, $bundle_name, and $entity_id args.
  array_shift($args);
  array_shift($args);
  array_shift($args);
  array_shift($args);
  array_shift($args);
  $string = implode('/', $args);

  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle_name);

  return tp_videos_autocomplete_callback_get_matches($type, $field, $instance, $entity_type, $entity_id, $string);
}

/**
 * Return matches for the menu callback, and preserve delimiting
 * quotation marks if they exist
 *
 * @see entityreference_autocomplete_callback_get_matches().
 */

function tp_videos_autocomplete_callback_get_matches($type, $field, $instance, $entity_type, $entity_id = '', $string = '') {

  $matches = array();

  $entity = NULL;
  if ($entity_id !== 'NULL') {
    $entity = entity_load_single($entity_type, $entity_id);
    if (!$entity || !entity_access('view', $entity_type, $entity)) {
      return MENU_ACCESS_DENIED;
    }
  }

  $handler = entityreference_get_selection_handler($field, $instance, $entity_type, $entity);

  if ($type == 'tags') {
    // The user enters a comma-separated list of tags. We only autocomplete the last tag.
    $tags_typed = drupal_explode_tags($string);
    $tag_last = drupal_strtolower(array_pop($tags_typed));
    if (!empty($tag_last)) {
      foreach ($tags_typed as $key => $tag) {
        if (strpos($tag, ',') !== FALSE || strpos($tag, '"') !== FALSE) {
          $tags_typed[$key] = '"' . str_replace('"', '""', $tag) . '"';
        }
      }
      $prefix = count($tags_typed) ? implode(', ', $tags_typed) . ', ' : '';
    }
  }
  else {
    // The user enters a single tag.
    $prefix = '';
    $tag_last = $string;
  }

  if (isset($tag_last)) {
    // Get an array of matching entities.
    $entity_labels = $handler->getReferencableEntities($tag_last, $instance['widget']['settings']['match_operator'], 10);

    // Loop through the products and convert them into autocomplete output.
    foreach ($entity_labels as $values) {
      foreach ($values as $entity_id => $label) {
        $key = "$label ($entity_id)";
        // Strip things like starting/trailing white spaces, line breaks and tags.
        $key = preg_replace('/\s\s+/', ' ', str_replace("\n", '', trim(decode_entities(strip_tags($key)))));
        // Names containing commas or quotes must be wrapped in quotes.
        if (strpos($key, ',') !== FALSE || strpos($key, '"') !== FALSE) {
          $key = '"' . str_replace('"', '""', $key) . '"';
        }
        $matches[$prefix . $key] = '<div class="reference-autocomplete">' . $label . '</div>';
      }
    }
  }

  drupal_json_output($matches);
}

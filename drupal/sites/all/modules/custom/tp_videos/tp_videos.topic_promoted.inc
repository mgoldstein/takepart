<?php
/**
 * @file
 * Promoted Videos on the Topic Taxonomy
 */

/**
 * Generate the Topic Promoted Videos form.
 */
function tp_videos_topic_promoted_admin_form($form, &$form_state) {
  // save a couple of things for convenience
  $entity_type = 'taxonomy_term';
  $bundle_name = 'topic';
  $field_name = 'field_featured_video';
  $langcode = LANGUAGE_NONE;

  // global video override
  $form['global'] = array(
    '#type' => 'fieldset',
    '#title' => t('Site-Wide Promoted Video'),
  );

  // get the global videos variable
  // and load each entity to get its title
  $global_field_values = array();
  $global_videos = variable_get('tp_videos_global_video', array());
  $global_video_nodes = node_load_multiple($global_videos);
  foreach ($global_video_nodes as $nid => $node) {
    $global_field_values[] = "{$node->title} ($nid)";
  }

  $form['global']['global_video'] = array(
    '#type' => 'textfield',
    '#weight' => -99,
    '#title' => t('Videos'),
    '#description' => t('The video(s) you enter here will be promoted on all the content that doesn\'t have a topic-specific video listed below.'),
    '#maxlength' => 1024,
    '#value' => implode(', ', $global_field_values),

    // hard-coded to match the values of topic taxonomy
    // field_featured_video
    '#entity_type' => $entity_type,
    '#bundle' => $bundle_name,
    '#field' => $field_name,
    '#language' => $langcode,
    '#autocomplete_path' => 'entityreference/autocomplete/tags/field_featured_video/taxonomy_term/topic/NULL',
  );
  $form['global']['topic_override'] = array(
    '#type' => 'checkbox',
    '#default_value' => variable_get('tp_videos_global_video_override', 0),
    '#weight' => -98,
    '#title' => t('Override topic-specific videos'),
    '#description' => t('If you check this box, your site-wide promoted video(s) will override the topic-specific selections below.'),
  );

  // load the topic taxonomy
  $topic = taxonomy_vocabulary_machine_name_load('topic');
  $tree = taxonomy_get_tree($topic->vid, 0, NULL, TRUE);


  // load settings of the featured video field
  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle_name);

  // Hold onto the original values of the field
  // so we can check if there are changes on submit.
  $form['original_values'] = array(
    '#type' => 'value',
    '#value' => array(),
  );

  // loop through the topic taxonomy
  // and create form elements for each term's
  // featured video field
  foreach ($tree as $index => $term) {
    $items = field_get_items($entity_type, $term, $field_name);
    $field_form = field_default_form($entity_type, $entity, $field, $instance, $langcode, $items, $form, $form_state);

    // store the original value of the featured video field
    // (create a dummy array if the field is empty)
    $default = empty($term->field_featured_video) ?
      array(LANGUAGE_NONE => array()) :
      $term->field_featured_video;
    $form['original_values']['#value']['tax_term_' . $term->tid] = $default;

    // create the form element
    $form['tax_term_' . $term->tid] = $field_form['field_featured_video'];
    $form['tax_term_' . $term->tid]['#weight'] = $index;
    $form['tax_term_' . $term->tid][$langcode]['#title'] = $term->name;
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => 99,
  );

  return $form;
}

/**
 * Validate handler for the tp_videos_topic_promoted_admin_form.
 */
function tp_videos_topic_promoted_admin_form_validate($form, &$form_state) {
  // validate the the global video overide
  $value = array();

  // We only do this if someone entered a value
  if (!empty($form_state['values']['global_video'])) {
    $entities = drupal_explode_tags($form_state['values']['global_video']);
    $value = array();
    foreach ($entities as $entity) {
      // Take the pattern "label (eid)" and match
      // the ID in the parentheses.
      if (preg_match("/.+\((\d+)\)/", $entity, $matches)) {
        $value[] = array($matches[1]);
      } else {
        form_set_error('global_video', t('Your global videos aren\'t all actual videos. Use the autocomplete options!'));
      }
    }
  }

  form_set_value($form['global']['global_video'], $value, $form_state);
}

/**
 * Submit handler for the tp_videos_topic_promoted_admin_form.
 */
function tp_videos_topic_promoted_admin_form_submit($form, &$form_state) {
  foreach ($form_state['values'] as $element_name => $value) {
    if (1 === preg_match('/^tax_term_/', $element_name)) {
      if($value != $form['original_values']['#value'][$element_name]) {
        $tid = intval(str_replace('tax_term_', '', $element_name));
        $term_wrapper = new EntityDrupalWrapper('taxonomy_term', $tid);
        foreach($value[LANGUAGE_NONE] as $index => $value) {
          $term_wrapper->field_featured_video[$index]->set($value['target_id']);
        }
        $term_wrapper->save();
      }
    } elseif ('global_video' === $element_name) {
      variable_set('tp_videos_global_video', $value);
    } elseif ('topic_override' === $element_name) {
      variable_set('tp_videos_global_video_override', $value);
    }
  }
  drupal_set_message(t('Your featured video options have been saved.'));
}

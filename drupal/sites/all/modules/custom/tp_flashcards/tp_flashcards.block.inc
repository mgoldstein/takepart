<?php
/**
 * @file
 * Blocks defined by the tp_flashcards module
 */

/**
 * Implements hook_block_info().
 */
function tp_flashcards_block_info() {
  $blocks = array();

  $blocks['flashcard_related_content'] = array(
    'info' => t('Flashcard Related Content'),
    'cache' => DRUPAL_CACHE_PER_PAGE,
  );

  $blocks['flashcard_get_more'] = array(
    'info' => t('Flashcard Get More'),
    'cache' => DRUPAL_CACHE_PER_PAGE,
  );

  $blocks['flashcard_comments'] = array(
    'info' => t('Flashcard Comments'),
    'cache' => DRUPAL_CACHE_PER_PAGE,
  );

  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function tp_flashcards_block_view($delta = '') {
  $block = array();

  switch ($delta) {
    case 'flashcard_related_content':
      $block['content'] = _tp_flashcards_related_content_block();
      break;

    case 'flashcard_get_more':
      $block['subject'] = 'Get More';
      $block['content'] = _tp_flashcards_get_more_block();
      break;

    case 'flashcard_comments':
      $block['content'] = _tp_flashcards_comments_block();
      break;
  }

  return $block;
}

/**
 * Render the "related content" module for a flashcard page.
 *
 * @param  integer $nodes_to_show the number of nodes to show in the list
 *
 * @return array A renderable array with the block contents.
 */
function _tp_flashcards_related_content_block($nodes_to_show = 8) {
  $contents = array();

  $node = menu_get_object();
  if ($node->type === "flashcard") {
    // first get the related content overrides
    $overrides = array_map('_tp_flashcards_get_target_id', field_get_items('node', $node, 'field_flashcard_related'));

    if (count($overrides) < $nodes_to_show) {
      $tids = array_map('_tp_flashcards_get_target_id', field_get_items('node', $node, 'field_flashcard_related_category'));

      if (!empty($tids)) {
        // @todo this is inefficient
        $category_nodes = array();
        foreach (array('field_topic', 'field_free_tag') as $field) {
          $query = new EntityFieldQuery();
          $query->entityCondition('entity_type', 'node')
            ->entityCondition('bundle', array('flashcard', 'openpublish_article', 'feature_article', 'openpublish_photo_galery', 'video'))
            ->propertyCondition('status', 1)
            ->fieldCondition($field, 'tid', $tids, 'IN')
            ->propertyOrderBy('created', 'DESC')
            ->range(0,$nodes_to_show - count($overrides));

          if (!empty($overrides)) {
            $query->propertyCondition('nid', $overrides, 'NOT IN');
          }

          $result = $query->execute();
          if ($result['node']) {
            $category_nodes = $category_nodes + $result['node'];
          }
        }

        $query = new EntityFieldQuery();
        $query->entityCondition('entity_type', 'node')
          ->propertyOrderBy('created', 'DESC')
          ->entityCondition('entity_id', array_keys($category_nodes))
          ->range(0,$nodes_to_show - count($overrides));

        $result = $query->execute();
        $category_nodes = array_keys($result['node']);

        // build the call to action link based on the first
        // taxonomy term in the related category list
        $path = url('taxonomy/term/' . $tids[0]);
        $items = field_get_items('node', $node, 'field_flashcard_related_cta_text');
        $text = drupal_render(field_view_value('node', $node, 'field_flashcard_related_cta_text', $items[0]));
        $cta_link = array(
          '#weight' => 10,
          '#prefix' => '<div class="flashcard-related-content-cta-wrapper">',
          '#suffix' => '</div>',
          '#theme' => 'link',
          '#text' => $text,
          '#path' => substr($path, 1),
          '#options' => array('attributes' => array('class' => array('flashcard-cta-link'))),
        );
      }

      $all_related_nodes = empty($overrides) ? array() : $overrides;
      $all_related_nodes = empty($category_nodes) ? $all_related_nodes : array_merge($all_related_nodes, $category_nodes);
      $contents = node_view_multiple(node_load_multiple($all_related_nodes), 'feature_secondary');

      if (!empty($all_related_nodes)) {
        $contents['nodes']['#prefix'] = '<h2 class="section-header top-border">Go Deeper on the Issue</h2><div class="flashcard-related-content-wrapper">';
        $contents['nodes']['#suffix'] = '</div>';
        $contents['cta_link'] = $cta_link;
      }
    }
  }
  return $contents;
}

/**
 * Return a render array for the Flashcards tag block;
 */
function _tp_flashcards_get_more_block() {
  $node = menu_get_object();
  $topics = field_get_items('node', $node, 'field_topic');
  $tags = field_get_items('node', $node, 'field_free_tag');

  $links = array();
  foreach ($topics as $topic) {
    $links[] = drupal_render(field_view_value('node', $node, 'field_topic', $topic));
  }
  foreach ($tags as $tag) {
    $links[] = drupal_render(field_view_value('node', $node, 'field_free_tag', $tag));
  }

  return array(
    '#theme' => 'item_list',
    '#items' => $links,
    '#type' => 'ul',
    '#attributes' => array(
      'class' => array('topic-links', 'links', 'inline')
    ),
  );
}

function _tp_flashcards_comments_block() {
  $url = url(current_path(), array('absolute' => TRUE));

  return array(
    '#markup' => '<h2 class="section-header top-border">Comments '
      . '<span>(<fb:comments-count href="' . $url.  '">0'
      . '</fb:comments-count>)</span></h2>'
      . '<fb:comments numposts="15" href="' . $url.  '"></fb:comments>',
  );
}

/**
 * Utility function to return 'target_id' key from an array
 * @param  array $item An array with a 'target id' 
 * @return             The value of the 'target_id' key       
 */
function _tp_flashcards_get_target_id($item) {
  return isset($item['target_id']) ? $item['target_id'] : FALSE;
}

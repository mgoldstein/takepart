<?php
  foreach ($items as $key => $item) {
    $node = node_load($item['target_id']);
    print '<div id="slider_'. $key. '" class="swipe slider">';
    print drupal_render(node_view($node, 'full', NULL));
    print '</div>';
  }
?>
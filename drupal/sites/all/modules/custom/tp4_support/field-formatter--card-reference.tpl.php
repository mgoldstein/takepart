<?php
  foreach ($items as $key => $item) {
    $node = node_load($item['target_id']);

    //Set the background of the card
    //If Tray contains a background image, use it.  Otherwise, use the background at the card level.
    $background = $node->field_campaign_background['und'][0]['uri'];
    $background = file_create_url($background);

    //Card classes in the CSS control background properties.
    $card_classes = '';

    print '<div class="card '. $card_classes. '" style="background-image: url(\''. $background. '\');">'. drupal_render(node_view($node, 'full', NULL)). '</div>';
  }
?>
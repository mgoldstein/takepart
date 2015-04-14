<?php

// Remove Height and Width Inline Styles from Drupal Images
function base_preprocess_image(&$variables) {
  foreach (array('width', 'height') as $key) {
    unset($variables[$key]);
  }
}
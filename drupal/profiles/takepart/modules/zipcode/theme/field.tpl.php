<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
?>
<div class="zip-code-wrapper">
  <div class="zip-code-5"><?php print drupal_render($content['zip_code']); ?></div>
  <div class="zip-code-dash">-</div>
  <div class="zip-code-4"><?php print drupal_render($content['plus_four']); ?></div>
  <div class="zip-code-help"><?php print drupal_render($content['zip_help']); ?></div>
  <div class="zip-code-clear"></div>
</div>

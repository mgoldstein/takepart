<?php
/**
 * Documentation here
 */
?>
<div class="social-wrapper">
  <ul class="social-menu">
<!--    --><?php //print_r($variables); ?>
    <?php foreach($variables['items'] as $key => $item): ?>
      <li class="<?php print $key; ?>"><?php print $item; ?></li>
    <?php endforeach; ?>
  </ul>
  <div class="tap-influence-overlay"></div>
</div>
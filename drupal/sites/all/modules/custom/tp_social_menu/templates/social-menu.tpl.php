<?php
/**
 * Documentation here
 */
?>
<div class="social-wrapper">
  <ul class="parent-social-menu">
    <?php foreach($variables['items'] as $key => $item): ?>
      <li class="<?php print $key; ?>"><?php print $item; ?></li>
    <?php endforeach; ?>
  </ul>
</div>
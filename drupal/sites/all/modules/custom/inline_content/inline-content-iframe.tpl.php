<?php
/**
 * Template file for Inline Content Interactive iframe
 * To override, add inline-content-iframe.tpl.php to your theme
 */
?>

<div class="inline-interactive-iframe-wrapper">
  <?php print $iframe; ?>
  <?php if($caption): ?>
    <div class = "caption col-xxs-12">
      <?php print $caption; ?>
    </div>
  <?php endif; ?>
</div>

<?php
/**
 * Template file for Inline Content Pullquotes
 * To override, add inline-content-pullquote.tpl.php in your theme
 * To override variables availabile use hook_preprocess_HOOK
 */
?>
<blockquote class="align-left pull-quote-alt">
  <p class="quotation"><?php print $quote; ?></p>
  <?php if($cite): ?>
    <cite>- <?php print $cite; ?></cite>
  <?php endif; ?>
</blockquote>
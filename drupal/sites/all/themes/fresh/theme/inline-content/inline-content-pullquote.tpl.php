<?php
/**
 * Template file for Inline Content Pullquotes
 * To override, add inline-content-pullquote.tpl.php in your theme
 * To override variables availabile use hook_preprocess_HOOK
 */
?>
<blockquote class="pullquote text-center row">
  <div class="col-xs-10 col-xs-offset-1">
    <div class="separator separator-style-1"></div>
    <p class="quotation"><?php print $quote; ?></p>
    <?php if ($cite): ?>
      <h4 class="cite"><?php print $cite; ?></h4>
    <?php endif; ?>
    <div class="icon i-quote-end"></div>
  </div>
</blockquote>
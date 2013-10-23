<div class="footer-block">
  <div class="footer-menu">
    <span class="footer-title">takepart</span>
    <?php print drupal_render(menu_tree('menu-takepart-topics')); ?>
  </div>
  <div class="footer-menu">
    <span class="footer-title">films</span>
    <?php print drupal_render(menu_tree('menu-takepart-film-campaigns')); ?>
  </div>
  <div class="footer-menu">
    <span class="footer-title">about takepart</span>
    <?php print drupal_render(menu_tree('menu-takepart-links')); ?>
  </div>
</div>
<?php print $footer_text; ?>
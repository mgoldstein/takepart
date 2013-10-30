<div class="footer-left">
  <div class="footer-menu">
    <span class="footer-title">takepart</span>
    <?php print drupal_render(menu_tree('menu-takepart-topics')); ?>
  </div>
  <div class="footer-menu">
    <span class="footer-title">films</span>
    <?php print drupal_render(menu_tree('menu-takepart-film-campaigns')); ?>
    <div class="more"><?php print l('More films', '/films', array('attributes' => array('class' => array('more')))); ?></a></div>
  </div>
  <div class="footer-menu">
    <span class="footer-title">about takepart</span>
    <?php print drupal_render(menu_tree('menu-takepart-links')); ?>
  </div>
</div>
<div class="footer-right">
  <div class="follow-us">
    <span class="footer-title social">connect</span>
    <?php print drupal_render(menu_tree('menu-social-footer-follow')); ?>
  </div>
  <div class="text">
    <?php print $footer_text; ?>
  </div>
</div>
<div class="footer-bottom">
  <div class="footer-bottom-inner">
    <span class="footer-title">takepart is a part of participant media:</span> <?php print drupal_render(menu_tree('menu-corporate-footer')); ?>
  </div>
</div>
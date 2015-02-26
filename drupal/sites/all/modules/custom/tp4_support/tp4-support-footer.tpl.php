<div class="footer-text">
  <h2 class="footer-title">about takepart</h2>
  <?php print $footer_text; ?>
</div>

<div class="follow-us footer-social">
  <h2 class="footer-title">follow us</h2>
  <?php print render($social_links); ?>
</div>

<div class="footer-menu">
  <?php print str_replace('//campaigns', '//www', $footer_menu_links); ?>
</div>

<div class="footer-bottom">
  <div class="footer-bottom-inner">
    <?php print render($corporate_links); ?>
  </div>
</div>

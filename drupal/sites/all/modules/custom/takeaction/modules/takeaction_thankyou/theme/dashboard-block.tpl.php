<?php
/**
 * @file
 * Take Action dashboard promo template.
 */
?>
<div class="takeaction-dashboard-promo <?php print $logged_in ? 'logged-in' : 'logged-out'?>">
<?php if ($logged_in): ?>
  <a class="dashboard-link" href="<?php print $dashboard_url; ?>"><?php print $dashboard_link; ?></a> 
<?php else: ?>
  <div class="content">
  <div class='inner_content_left'>
    <img class="preview" src="/profiles/takepart/themes/takepart3/images/tab/imgPrev.jpg" />
  </div>
  <div class='inner_content_right'>
    <p><?php print $text; ?></p>
    <a class="facebook-login" href="<?php print $login_url; ?>"><?php print $login_link; ?></a>
  </div>
  </div>
<?php endif ?>
</div>

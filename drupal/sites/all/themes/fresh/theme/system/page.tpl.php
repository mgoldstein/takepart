<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 */
?>
<?php
  $cic_experience = ($variables['page']['campaign_ref']) ? TRUE : FALSE;
  $campaign_experience = ($cic_experience) ? ' class="campaign-experience"' : '';
  $menu = ($cic_experience) ? 'cic-menu' : 'mobile-menu';
  $menu_inner = ($cic_experience) ? 'cic-menu-inner' : 'mobile-menu-inner';
?>

<nav id="<?php print $menu; ?>" class="menu">
  <div class="<?php print $menu_inner; ?>">
    <?php print render($page['left_drawer']); ?>
  </div>
</nav>
<div id="page-wrapper" <?php print $campaign_experience; ?>>
  <?php print render($page['header']); ?>
  <div class="main-content" id="content" role="main">
    <div class="container">
      <div class="row">
          <?php print render($title_prefix); ?>
          <?php print render($title_suffix); ?>
          <?php print $messages; ?>
          <?php print render($tabs); ?>
          <?php print render($page['content']); ?>
      </div>
    </div>
  </div>
</div>
<div id="footer-wrapper" class="footer">
  <?php print render($page['footer']); ?>
</div>
<?php print render($page['page_bottom']); ?>
<div id="highlight_menu" style="display:none;">

  <ul class="side-by-side">
    <li><a target="_blank" href="https://www.facebook.com/dialog/feed?app_id=247137505296280&display=popup&amp;caption=An%20example%20caption&link=https%3A%2F%2Fwww.takepart.com&redirect_uri=http://www.takepart.com"><img width="20px" src="https://cdn1.iconfinder.com/data/icons/logotypes/32/square-facebook-512.png"></a></li>
    <li><a target="_blank" href="https://twitter.com/intent/tweet?url=http%3A%2F%2Ftakepart.local%2Farticle%2F2016%2F06%2F14%2Frace-fix-airbnb-while-black-problem%3Fcmpid%3Dorganic-share-twitter&amp;via=TakePart&amp;text=The%20Race%20to%20Fix%20the%20Airbnb%20While%20Black%20Problem"><img width="20px" src="https://cdn1.iconfinder.com/data/icons/logotypes/32/square-twitter-512.png"></a></li>
  </ul>

  <div class="caret"></div>

</div>

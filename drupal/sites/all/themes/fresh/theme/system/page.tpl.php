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

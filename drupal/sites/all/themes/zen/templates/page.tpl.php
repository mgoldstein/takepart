<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 */
?>

<div id="tp-drawers" class="snap-drawers scrollable">
  <div class="snap-drawer snap-drawer-left">
    <?php print render($page['left_drawer']); ?>
  </div>
</div>

<div id="page">
  <header class="header" id="header" role="banner">
    <?php print render($page['header']); ?>
  </header>
  <div id="main">
    <div id="content" class="column" role="main">
      <a id="main-content"></a>
      <?php print render($title_prefix); ?>
      <?php print render($title_suffix); ?>
      <?php print $messages; ?>
      <?php print render($tabs); ?>
      <?php print render($page['content']); ?>
    </div>
  </div>
  <?php print render($page['footer']); ?>
</div>
<?php print render($page['bottom']); ?>

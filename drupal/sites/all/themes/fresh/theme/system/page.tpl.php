<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 */
?>

<nav id="mobile-menu" class="menu">
  <div class="mobile-menu-inner">
    <?php print render($page['left_drawer']); ?>
  </div>
</nav>

<div id="page-wrapper">
  <div class="row">
    <div id="page" class="col-xxs-12">
      <header class="header col-xxs-12" id="header" role="banner">
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
  </div>

</div>
<?php print render($page['bottom']); ?>

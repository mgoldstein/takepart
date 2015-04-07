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
  <header class="header" id="header" role="banner">
    <div class="container">
      <div class="row">
        <div class="col-xxs-12">
          <?php print render($page['header']); ?>
        </div>
      </div>
    </div>
  </header>
  <div class="main-content" id="content" role="main">
    <div class="container">
      <div class="row">
        <div class="col-xxs-12">
          <a id="main-content"></a>
          <?php print render($title_prefix); ?>
          <?php print render($title_suffix); ?>
          <?php print $messages; ?>
          <?php print render($tabs); ?>
          <?php print render($page['content']); ?>
        </div>
      </div>
    </div>
  </div>
  <div class="footer">
    <div class="container">
      <div class="row">
        <div class="col-xxs-12">
          <?php print render($page['footer']); ?>
        </div>
      </div>
    </div>
  </div>
</div>
<?php print render($page['bottom']); ?>

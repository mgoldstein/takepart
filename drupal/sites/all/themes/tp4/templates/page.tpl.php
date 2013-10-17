<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
?>


<div class="header-wrapper">
  <header id="header">
    <!-- header content goes here -->
  </header>
</div>
<div class="preface-wrapper">
  <div id="preface">
    <?php print render($tabs); ?>
    <?php print $messages; ?>
    <?php print $breadcrumb; ?>
    <?php print render($page['preface']); ?>
  </div>
</div>
<div class="main-wrapper">
  <main id="main">
    <div id="primary" class="<?php print $content_classes; ?>">
      <?php print render($page['help']); ?>
      <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php print render($page['content']); ?>
    </div>
    <div id="skinny">
      <?php ($skinny ? print $skinny : ''); ?>
    </div>
    <div id="sidebar">
      <?php ($sidebar ? print $sidebar : ''); ?>
    </div>
  </main>
</div>
<div class="suffix-wrapper">
  <div id="suffix">
    <?php print render($page['suffix']); ?>
  </div>
</div>
<div class="footer-wrapper">
  <footer>
    <?php print render($page['footer']); ?>
  </footer>
</div>


<?php print render($page['bottom']); ?>

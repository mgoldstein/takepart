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
    <?php print render($page['header']); ?>
  </header>
</div>
<div class="preface-wrapper">
  <div id="preface">
    <?php print render($tabs); ?>
    <?php print $messages; ?>
    <?php print $breadcrumb; ?>
    <?php print render($page['preface']); ?>
    <?php if(drupal_is_front_page()) : // TODO Move this literally anywhere else ?>
    <div class="date">
      <?php print date('l, F j, Y'); ?>
    </div>
    <?php endif; ?>
  </div>
</div>
<div class="main-wrapper">
  <main id="main" class="<?php print $content_classes; ?>">
    <div id="primary">
      <?php print render($page['help']); ?>
      <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php print render($page['content']); ?>
    </div>
    <?php if ($sidebar) : ?>
    <div id="sidebar">
      <?php print $sidebar; ?>
    </div>
    <?php endif; ?>
    <?php if ($skinny) : ?>
    <div id="skinny">
      <?php print $skinny; ?>
    </div>
    <?php endif; ?>
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

<?php
/**
 * @file
 * Returns the HTML for a single Campaign Foldout page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
?>
<div class="snap-drawers scrollable">
    <div class="snap-drawer snap-drawer-left">
    <?php print render($page['left_drawer']); ?>
  </div>
</div>
<div id="page-wrap">
  <div class="header-wrapper">
    <header id="header">
      <?php print render($page['header']); ?>
    </header>
  </div>
  <div class="preface-wrapper">
    <div id="preface">
      <?php print render($tabs); ?>
      <?php print $messages; ?>
      <?php print ($preface = render($page['preface'])); ?>
    </div>
  </div>
  <main id="main" class="<?php print $content_classes; ?>">
    <div id="primary">
      <?php print render($title_prefix); ?>
      <?php if ($title): ?>
        <h1 class="page__title title" id="page-title"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php print render($page['help']); ?>
      <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php print render($page['content']); ?>
    </div>
  </main>
  <div class="suffix-wrapper">
    <div id="suffix">
      <?php print render($page['suffix']); ?>
    </div>
  </div>

  <div class="footer-wrapper">
    <?php print render($page['footer']); ?>
  </div>
  <?php print render($page['bottom']); ?>
</div>
<?php
/**
 * @file
 * Returns the HTML for a single Campaign Foldout page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */

  drupal_add_js(array('tp_campaigns' => array(
      'stickupParts' => (object) $variables['anchor_tags'],
    )), 'setting');
?>
<div id="tp-drawers" class="snap-drawers scrollable">
    <div class="snap-drawer snap-drawer-left">  
    <?php print render($page['left_drawer']); ?>
  </div>
</div>

<div id="campaign-drawers" class="snap-drawers scrollable">
  <div class="snap-drawer snap-drawer-right">
    <div id="block-menu-menu" class="block block-menu first last odd" role="navigation">
      <?php print $variables['promo_title']; ?>
      <?php print render($variables['campaign_menu']); ?>
    </div>
  </div>
</div>

<div id="page-wrap">
  <div class="header-wrapper">
    <header id="header">
      <?php print render($page['header']); ?>
    </header>
  </div>

  <div id="main-wrap">
    <main id="main" class="<?php print $content_classes. ' '. implode($variables['classes_array'], ' '); ?>">
      <div class="preface">
        <?php print render($tabs); ?>
        <?php print $messages; ?>
        <?php print render($page['preface']); ?>
      </div>
      <div id="primary">
        <?php print render($campaign_content_meta); ?>
        <?php print render($page['content']); ?>
      </div>
    </main>
    <div class="suffix-wrapper">
      <div id="suffix">
        <?php print render($page['suffix']); ?>
      </div>
    </div>
  </div>

  <div class="footer-wrapper">
    <?php print render($page['footer']); ?>
  </div>
  <?php print render($page['bottom']); ?>
</div>

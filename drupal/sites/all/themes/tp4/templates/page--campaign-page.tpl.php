<?php
/**
 * @file
 * Returns the HTML for a single Campaign Foldout page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
?>
<?php dpm(get_defined_vars(), 'get defined vars adsfd'); ?>
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
  <main id="main" class="<?php print $content_classes. ' '. implode($variables['classes_array'], ' '); ?>">
  <div class="preface">
    <?php print render($page['preface']); ?>
  </div>
    <div id="primary">
      <?php print $messages; ?>
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




<script type="text/javascript">
  //initiating jQuery  
  jQuery(function($) {
    $(document).ready( function() {
      //enabling stickUp on the '.navbar-wrapper' class
      $('#block-tp-campaigns-tp-campaigns-hero').stickUp({
        parts: {
        <?php
        foreach($variables['anchor_tags'] as $key => $item){
          print $key. ': \''. $item. '\',';
        }
        ?>
        },
        itemClass: 'parent-item',
        itemHover: 'active'
      });
    });
  });

</script>
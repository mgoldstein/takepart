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
  
<div class="snap-drawers-campaign scrollable">
    <div class="snap-drawer-campaign snap-drawer-left">
    	<div id="block-menu-menu-campaign" class="block block-menu first last odd" role="navigation">
	    <?php print render($variables['campaign_menu']); ?>
	    </div>
	  </div>
 </div>

  <main id="main" class="<?php print $content_classes. ' '. implode($variables['classes_array'], ' '); ?>">
  <div class="preface">
    <?php print render($tabs); ?>
    <?php print $messages; ?>
    <?php print render($page['preface']); ?>
  </div>
    <div id="primary">
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



<!--
<script type="text/javascript">
  //initiating jQuery  
  jQuery(function($) {
    $(document).ready( function() {
      //enabling stickUp on the '.navbar-wrapper' class
      $('#block-tp-campaigns-tp-campaigns-hero').stickUp({
        parts: {
        <?php
        foreach($variables['anchor_tags'] as $key => $item){
          print $key. ': \''. $item. '\','. PHP_EOL;
        }
        ?>
        },
        itemClass: 'anchored',
        itemHover: 'active'
      });
    });
  });

</script>

-->
<?php
/**
 * @file
 * Template for panel layout for the tp4 theme's homepage.
 *
 * This template provides a one column panel display layout, with
 * areas for primary and secondary features for both articles and
 * .
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['main_featured']: Main featued area (top of layout)
 *   - $content['secondary_featured']: Secondary Featured Articles
 *   - $content['tpl_featured']: Main TPL Feature
 *   - $content['tpl_secondary_featured']: Secondary TPL Features
 */



?>
<div class="panel-takepart-homepage clearfix panel-display" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
    <div class="panel-main-featured panel-panel">
      <?php print $content['main_featured']; ?>
    </div>
    <div class="panel-secondary-featured panel-panel">
      <?php print $content['secondary_featured']; ?>
    </div>
    <div class="panel-tpl-featured panel-panel">
      <h2 class="tpl-headline"><span class="tpl-title"></span><span class="tpl-time"></span></h2>
      <?php print $content['tpl_featured']; ?>
    </div>
    <div class="panel-tpl-secondary-featured panel-panel">
      <?php print $content['tpl_secondary_featured']; ?>
    </div>
    <?php
      $block = module_invoke('bean', 'block_view', 'tpl-live-long');
      $image = $block['content']['bean']['tpl-live-long']['#entity']->field_tpl_block_homepage_cta;
      $image = file_create_url($image[LANGUAGE_NONE][0]['uri']);
      $image = '<div class="tpl-cta"><img src="'. $image. '"></div>';
      print l($image, '//takepart.com/live', array('html' => true));
    ?>
</div>

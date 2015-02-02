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
</div>

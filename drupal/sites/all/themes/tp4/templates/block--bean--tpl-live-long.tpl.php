<?php
/**
 * @file
 * Returns the HTML for a block.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728246
 */
?>
<div id="<?php print $block_html_id; ?>" class="tpl-block <?php print $classes; ?>"<?php print $attributes; ?>>
  <?php
  $output = '';
  $output .= render($title_prefix);
  $output .= '<h2 class="block__title"> TakePart Live </h2>';
  $output .= render($title_suffix);
  print $output;
  print $content;
  ?>
  <div class="find-pivot">
    <?php print l('', 'http://find.pivot.tv', array('attributes' => array('target' => '_blank'), 'absolute' => TRUE)); ?>
  </div>

</div>

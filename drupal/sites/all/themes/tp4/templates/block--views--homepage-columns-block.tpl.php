<?php
/**
 * @file
 * Returns the HTML for a block.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728246
 */
?>
<div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php
  $output = '';
  $output .= render($title_prefix);
  if($variables['elements']['#block']->bid == 'views-takeaction_homepage-block'){
    $output .= '<div class="megaphone"></div>';
    $path = '//takeaction.takepart.com';
  }
  else{
    global $base_url;
    $path = $base_url. '/features-columns';
  }
  $output .= '<div class="line"></div>';
  if ($title){
    $output .= '<h2'. $title_attributes. '>'. $title. '</h2>';
  }
  $output .= render($title_suffix);

  print l($output, $path, array('html' => true, 'attributes' => array('class' => array('column-header'))));
  print $content;
  ?>

</div>

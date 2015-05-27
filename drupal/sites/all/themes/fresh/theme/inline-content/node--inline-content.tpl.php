<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
?>

<a class="inline-content-link" href="<?php print $variables['url']; ?>">
  <div class="line line-style-3 top"></div>
  <div class="inline-label text-center">Related</div>
  <div class="inline-content-inner">
    <?php
    hide($content['comments']);
    hide($content['links']);
    print render($content);
    ?>
    <h3 class="inline-title text-center"><?php print $variables['title']; ?></h3>
  </div>
  <div class="line line-style-3 bottom"></div>
</a>

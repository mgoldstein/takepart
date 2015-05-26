<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */

// Replace the $title with the promo headline if there is one
$field_promo_headline = field_get_items('node' ,$node, 'field_promo_headline');
$field_promo_headline = $field_promo_headline[0]['value'];

$promoted = _tp4_support_sponsor_flag($node, false);

?>
<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <header>
    <a class="inline-content-link" href="<?php print $url_local; ?>">
    <?php
    	hide($content['comments']);
    	hide($content['links']);
    	print render($content); 
    ?>
    <?php if (!$page && $title && $type != "poll") : ?>
    <h2 class="inline-title"><?php print ($field_promo_headline ? $field_promo_headline : $title).$promoted; ?></h2>
    <?php endif; ?>
    </a>
  </header>
</article>

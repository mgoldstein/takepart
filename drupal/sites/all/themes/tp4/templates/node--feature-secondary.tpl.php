<?php
/**
 * @file
 * Returns the HTML for the secondary featured nodes
 * on the TP4 Homepage.
 */

$headline = !empty($node->field_promo_headline) ? $node->field_promo_headline['und'][0]['safe_value'] : $title;
?>
<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    print render($content);
  ?>
  <?php if ($title_prefix || $title_suffix || $display_submitted || $unpublished || !$page && $headline): ?>
    <?php print render($title_prefix); ?>
    <?php if (!$page && $headline): ?>
      <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $headline; ?></a></h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
    <?php if ($unpublished): ?>
      <mark class="unpublished"><?php print t('Unpublished'); ?></mark>
    <?php endif; ?>
  <?php endif; ?>
</article>

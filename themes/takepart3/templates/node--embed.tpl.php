<div class='<?php print $classes ?> clearfix node-embedded' <?php print ($attributes) ?>>
  <?php if (!empty($title)): ?>
    <h2 <?php if (!empty($title_attributes)) print $title_attributes ?>>
      <a href="<?php print $node_url ?>"><?php print $title ?></a>
    </h2>
  <?php endif; ?>
</div>

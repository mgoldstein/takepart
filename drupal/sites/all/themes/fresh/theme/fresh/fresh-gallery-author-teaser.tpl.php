<?php
  if (!empty($variables['author'])) {
    $authors = '';
    foreach ($variables['author'] as $key => $val) {
      if ($key > 0) {
        $authors .= ', ';
      }
      $authors .= $val -> title;
    }
  }
?>

<div class="author-teaser">
  <div class = "author-teaser-inner">
    <?php if (!empty($variables['published_at'])): ?>
      <span class="published-at"><?php print date('M j, Y', $variables['published_at']); ?>  |  </span>
    <?php endif; ?>
    <?php if (isset($authors) && !empty($authors)): ?>
      <span class="author-name"><?php print $authors; ?></span>
    <?php endif; ?>
  </div>
  <div class="author-border"></div>
</div>


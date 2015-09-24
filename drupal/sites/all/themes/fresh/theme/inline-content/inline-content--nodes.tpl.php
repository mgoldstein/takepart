<?php
/**
 * @file
 * Template for wrapping inline-content nodereferences in articles.
 *
 * @see inline_content.module
 *
 * Variables
 *
 * $element - the piece of inline content being rendered
 *
 * $element['#inline_content'] - Inline content entity instance (essentially the
 *   original model for the replacement)
 * $element['#replacements'] - Render arrays of all items that make up this ONE
 *   replacement, indexed by node id.
 * $element['#orientation'] - The orientation of the replacement
 * $element['#attributes'] - The attributes (class, id, etc...) of the replacement
 */
?>
<aside class="inline-content col-sm-5 pull-right">
  <?php foreach ($element['#replacements'] as $key => $item): ?>
    <?php
      // Add unpublished class for inline nodes
      $published = $element['#replacements'][$key]['#node'] -> status; ?>
    <div class = "inline-content-wrapper<?php print (!$published) ? " unpublished" : ""; ?>">
      <?php print render($item); ?>
  <?php endforeach; ?>
</div></aside>

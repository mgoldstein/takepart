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
<?php

  $nid = $variables['element']['#inline_content']->field_ic_content['und'][0]['nid'];
  $path = url('node/'. $nid); // drupal_get_path_alias('node/'. $nid);
  $type = ($element['#replacements'][0]['#bundle'] != null) ? "inline-node-".$element['#replacements'][0]['#bundle'] : "";
?>
<a href="<?php print $path; ?>">
  <aside class="inline-content inline-content-nodes <?=$element['#orientation']?> <?=$type?>">
    <?php foreach ($element['#replacements'] as $key => $item): ?>
      <?php print render($item); ?>
    <?php endforeach; ?>
  </aside>
</a>
<?php
/**
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
<div <?=drupal_attributes($element['#attributes'])?>>
<?php foreach ($element['#replacements'] as $node): ?>
  <div>
    <?php echo render($node['field_thumbnail']) ?>
    <p><?php echo l($node['#node']->title, 'node/' . $node['#node']->nid)  ?></p>
  </div>
<?php endforeach ?>
</div>

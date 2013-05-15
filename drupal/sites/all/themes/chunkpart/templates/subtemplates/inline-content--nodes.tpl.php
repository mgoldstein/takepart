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

<aside class="drupal-embed inline-content <?=$element['#orientation']?>">
	<? foreach ($element['#replacements'] as $item): ?>
		<p>
			<a href="<?=_surl($item['#node']) ?>">
				<?=_simage($item['field_thumbnail']['#object'], 'field_thumbnail', 'node', $item['field_thumbnail'][0]['#image_style'])?>
				<span><?=$item['#node']->title ?></span>
			</a>
		</p>
	<? endforeach ?>
</aside>

<? if ( list($delta, $item) = _seach($items) ): ?>
	<figure id="article-image" class="<?=$classes ?> <?=$item['#image_style']?>"<?=$attributes ?>>
		<?=render($item) ?>

		<? if ( ($image = _s($element['#object'], 'field_article_main_image')) ): ?>
			<? if ( $caption = _s($image['file'], 'field_media_caption', 'file') ): ?>
				<figcaption>
					<?=_s($caption) ?>
				</figcaption>
			<? endif ?>
		<? endif ?>
	</figure>
<? endif ?>
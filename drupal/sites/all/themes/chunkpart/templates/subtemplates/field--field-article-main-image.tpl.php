<? if ( list($delta, $item) = _seach($items) ): ?>
	<figure id="article-image" class="<?=$classes ?> <?=$item['#image_style']?>"<?=$attributes ?>>
		<?php
			//@todo: get this to work with field_view_field if possible:
		  if(isset($item['#item']['field_media_alt']['und'][0]['safe_value'])) {
		  	$item['#item']['alt'] = $item['#item']['field_media_alt']['und'][0]['safe_value'];
		  }
		?>
		<?=render($item) ?>
		<? if ( ($image = _snode($element['#object'], 'field_article_main_image')) ): ?>
			<? if ( $caption = _s($image[0]['file'], 'field_media_caption', 'file') ): ?>
				<figcaption>
					<?=_s($caption) ?>
				</figcaption>
			<? endif ?>
		<? endif ?>
	</figure>
<? endif ?>

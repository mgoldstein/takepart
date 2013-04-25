<section class="section">
	<h3 class="section_header"><?=$variables['header'] ?></h3>
	<div id="<?=$variables['response_id'] ?>">
		<? /*<p class="message"><?=$variables['body'] ?></p>*/ ?>
		<?=drupal_render($variables['form']) ?>
		<p class="tos-link"><?=drupal_render($variables['tos_link']) ?></p>
	</div>
</section>

<section class="section follow_us">
	<h3 class="section_header"><?=t('Follow Us') ?></h3>
	<ul>
		<? foreach ( $variables['social_links'] as $link ): ?>
			<li><?=drupal_render($link) ?></li>
		<? endforeach ?>
	</ul>
</section>
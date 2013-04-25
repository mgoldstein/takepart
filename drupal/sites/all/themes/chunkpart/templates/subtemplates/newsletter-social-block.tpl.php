<div id="<?=$variables['response_id'] ?>">
	<p class="message"><?=$variables['body'] ?></p>
	<?=drupal_render($variables['form']) ?>
	<p class="terms-of-service"><?=drupal_render($variables['tos_link']) ?></p>
</div>
<h3><?=t('Follow Us') ?></h3>
<ul>
	<? foreach ( $variables['social_links'] as $link ): ?>
		<li><?=drupal_render($link) ?></li>
	<? endforeach ?>
</ul>
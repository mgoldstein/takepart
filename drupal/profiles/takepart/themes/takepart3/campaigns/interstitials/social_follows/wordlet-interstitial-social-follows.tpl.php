<header class="header">
	<div <?=wa('promo-image') ?> >
		<? if ( $promo_image = w('promo-image') ): ?>
			<img src="<?=$promo_image->img_src ?>" alt="<?=$promo_image->single(false) ?>">
		<? endif ?>
	</div>

	<h1 class="headline">
		<?=w('header') ?>
	</h1>
</header>

<div class="content">
	<div class="body">
		<?=w('body') ?>
		<p id="dont">
			<a href="#"><?=w('do_not_show') ?></a>
		</p>
	</div>

	<div class="socials" <?=wa('socials') ?>>
		<? foreach ( wl('socials') as $social ): ?>
			<a href="<?=$social->href ?>" class="social" data-service="<?=$social->token ?>" target="_blank">
				<img src="<?=$social->img_src ?>" alt="<?=$social->single(false) ?>">
			</a>
		<? endforeach ?>
	</div>
</div>

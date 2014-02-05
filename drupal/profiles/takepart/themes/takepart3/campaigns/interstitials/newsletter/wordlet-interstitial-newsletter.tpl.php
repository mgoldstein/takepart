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
	</div>

	<div class="form">
		<?=w('newsletter_form') ?>
	</div>

	<p id="dont">
		<a href="#"><?=w('do_not_show') ?></a>
	</p>
</div>

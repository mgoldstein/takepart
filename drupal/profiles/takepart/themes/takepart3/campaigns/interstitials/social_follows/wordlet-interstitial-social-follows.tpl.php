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
		<div class="fb-like" data-href="https://www.facebook.com/takepart" data-colorscheme="light" data-layout="button" data-action="like" data-show-faces="false" data-share="false"></div>
		<a href="//twitter.com/takepart" class="twitter-follow-button" data-show-count="false" data-size="large" data-show-screen-name="false" data-lang="en">Follow</a>
		<script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0];if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src="//platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");</script>
		<p id="dont">
			<a href="#"><?=w('do_not_show') ?></a>
		</p>
	</div>
</div>

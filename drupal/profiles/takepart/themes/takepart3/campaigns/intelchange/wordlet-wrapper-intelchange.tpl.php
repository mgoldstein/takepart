<div id="page-wrapper" class="campaign">
	<?=$header ?>

	<!-- start -->

	<div class="page-wrap">
		<div class="main">
			<header class="header">
				<? if ( $w = w('header_image') ): ?>
					<h1 <?=wa('header_image')?>>
						<span><?=$w->single?></span>
						<a href="<?=wu('intelchange_home')?>"><img src="<?=$w->img_src?>" alt="intel for change logo" /></a>
					</h1>
				<? endif ?>
				<p class="presented" <?=wa('presented_by')?>>
					<? if ( $w = w('presented_by') ): ?>
						<span class="by"><?=$w->single(false)?></span>
						<img src="<?=$w->img_src?>" alt="intel logo" />
					<? endif ?>
				</p>
			</header>
			<nav class="menu">
				<ul <?=wa('menu')?>>
					<? foreach( wl('menu') as $w ): ?>
						<li><a href="<?=$w->href?>"><?=$w->single(false)?></a></li>
					<? endforeach ?>
				</ul>
				<div class="addThis">
                    <a class="addthis_button_facebook_like"></a>
                    <a class="addthis_button_tweet"></a>
                    <a class="addthis_button_email"></a>
                </div>
			</nav>
			<main id="page" class="content">
				<?=$content?>
			</main>
			<footer class="footer" <?=wa('footer_image')?>>
				<? if ( ($w = w('footer_image')) && $w->img_src ): ?>
					<img src="<?=$w->img_src?>" alt="<?=$w->single(false)?>" />
				<? endif ?>
			</footer>
		</div>
	</div><!-- /.page-wrap -->

	<!-- end -->

	<?=$footer ?>
</div>
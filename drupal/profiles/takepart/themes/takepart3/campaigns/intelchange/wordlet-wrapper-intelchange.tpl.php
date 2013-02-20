<div id="page-wrapper" class="campaign">
	<?=$header ?>

	<!-- start -->

	<div class="page-wrap">
		<div class="main">
			<div class="header">
				<? if ( $w = w('header_image') ): ?>
					<h1 <?=wa('header_image')?>>
						<span><?=$w->single(false)?></span>
						<a href="<?=$w->href?>"><img src="<?=$w->img_src?>" alt="intel for change logo" /></a>
					</h1>
				<? endif ?>
				<? if ( $w = w('presented_by') ): ?>
					<p class="presented">
						<span class="by"><?=$w->single?></span>
						<img src="<?=$w->img_src?>" alt="intel logo" />
					</p>
				<? endif ?>
				<div class="menu">
					<ul <?=wa('menu')?>>
						<? foreach( wl('menu') as $w ): ?>
							<li><a href="<?=$w->href?>"><?=$w->single(false)?></a></li>
						<? endforeach ?>
					</ul>
				</div>
			</div>
			<div class="content">
				<?=$content?>
			</div>
		</div>
	</div><!-- /.page-wrap -->

	<!-- end -->

	<?=$footer ?>
</div>
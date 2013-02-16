<div id="page-wrapper" class="campaign">
	<?=$header ?>

	<!-- start -->

	<div class="page-wrap">
		<div class="main">
			<div class="header">
				<? if ( $w = w('header_image') ): ?>
					<h1 <?=wa('header_image')?>>
						<span><?=$w->single(false)?></span>
						<img src="<?=$w->img_src?>" alt="eye level logo" />
					</h1>
				<? endif ?>
				<div class="menu">
					<ul <?=wa('menu')?>>
						<? foreach( wl('menu') as $w ): ?>
							<li><a href="<?=$w->href?>"><?=$w->single(false)?></a></li>
						<? endforeach ?>
					</ul>
				</div>
			</div>
			<?=$content?>
		</div>
	</div><!-- /.page-wrap -->

	<!-- end -->

	<?=$footer ?>
</div>
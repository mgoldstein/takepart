<div class="column column-1">
	<div class="content">
		<ol>
			<? foreach ( wl('side_links') as $w ): ?>
				<li><a href="<?=$w->href?>">
					<?=$w->single?>
				</a></li>
			<? endforeach ?>
		</ol>
		<div class="social"><img src="http://stage.bltdigital.com/apatt/images/interior-social-icons.png" width="116" height="60" alt="Social Icons"></div>
	</div>
</div><!-- /.column-1 -->
<div class="column column-2">
	<div class="inner">
		<div class="overview">
			<h3><?=w('header')?></h3>
			<?=w('body')?>
		</div>
	</div><!-- /.inner -->
</div><!-- /.column-2 -->
<div class="column column-3">
	<div class="content">
		<div class="email-signup">
			<form name="email-form" action="" method="get">
			<h3>email signup</h3>
		    <div class="input"><input type="text"  name="email"></div>
            <div class="submit"><input type="image" value="Submit" src="/profiles/takepart/themes/takepart3/campaigns/patt/images/interior-form-btn.png"></div>
			</form>
		</div>
		<div class="sponsored">
			<h4>sponsored by:</h4>
			<?=we('sponsor_links')?>
			<? if ( w('sponsor_links') ): ?>
				<ul>
					<? foreach ( wl('sponsor_links') as $w ): ?>
						<li><a href="<?=$w->href?>">
							<img src="<?=$w->img_src?>" alt="<?=$w->single(false)?>" />
						</a></li>
					<? endforeach ?>
				</ul>
			<? endif ?>
		</div>
	</div>
</div><!-- /.column-3 -->
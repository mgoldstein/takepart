<div class="column column-3">
	<div class="content">
		<div class="email-signup">
			<form name="email-form" action="" method="get">
			<h3><?=w('email_signup')?></h3>
		    <div class="input"><input type="text"  name="email"></div>
            <div class="submit"><input type="image" value="Submit" src="/profiles/takepart/themes/takepart3/campaigns/patt/images/interior-form-btn.png"></div>
			</form>
		</div>
		<div class="sponsored">
			<h4><?=w('sponsored_by')?></h4>
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
		<div class="follow">
			<h4><?=w('follow_us')?></h4>
			<?=we('follow_links')?>
			<? if ( w('follow_links') ): ?>
				<ul>
					<? foreach ( wl('follow_links') as $w ): ?>
						<li><a href="<?=$w->href?>">
							<img src="<?=$w->img_src?>" alt="<?=$w->single(false)?>" />
						</a></li>
					<? endforeach ?>
				</ul>
			<? endif ?>
		</div>
	</div>
</div><!-- /.column-3 -->
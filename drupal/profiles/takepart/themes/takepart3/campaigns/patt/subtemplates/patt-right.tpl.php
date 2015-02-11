<div class="column column-3">
	<div class="content">
		<div class="email-signup">
			<h4><?=w('email_signup')?></h4>
			<div><?=w('email_signup_form')?></div>
		</div>
		<div class="promo-rail cms">
			<?=w('promo_rail')?>
		</div>
		<div class="follow">
			<h4><?=w('follow_us')?></h4>
			<ul <?=wa('follow_links')?>>
				<?php foreach ( wl('follow_links') as $w ): ?>
					<li><a href="<?=$w->href?>">
						<img src="<?=$w->img_src?>" alt="<?=$w->single(false)?>" />
					</a></li>
				<?php endforeach ?>
			</ul>
		</div>
		<div class="sponsored">
			<h4><?=w('sponsored_by')?></h4>

			<ul <?=wa('sponsor_links')?>>
				<?php foreach ( wl('sponsor_links') as $w ): ?>
					<li><a href="<?=$w->href?>">
						<img src="<?=$w->img_src?>" alt="<?=$w->single(false)?>" />
					</a></li>
				<?php endforeach ?>
			</ul>
		</div>
	</div>
</div><!-- /.column-3 -->
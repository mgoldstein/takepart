<div class="content">
	<div class="primary">
		<h2><?=w('headline')?></h2>
		<div class="cms">
			<?=w('body')?>
		</div>
	</div>
	<div class="secondary">
		<div class="signup_form">
			<h3><?=w('signup_headline')?></h3>
		</div>
		<div class="partners">
			<ul <?=wa('partners')?>>
				<? foreach( wl('partners') as $w ): ?>
					<li><a href="<?=$w->href?>">
						<img src="<?=$w->img_src?>" alt="<?=$w->single(false)?>" />
					</a></li>
				<? endforeach ?>
			</ul>
		</div>
	</div>
</div>
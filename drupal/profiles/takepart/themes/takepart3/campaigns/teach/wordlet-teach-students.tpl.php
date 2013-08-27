<div class="content">
	<div class="primary">
		<h2><?=w('headline')?></h2>
		<div class="body cms">
			<?=w('body')?>
		</div>
	</div>
	<div class="secondary">
		<div class="signup_form" <?=wa('signup_form')?>>
			<? if ( $w = w('signup_form') ): ?>
				<h3><?=$w->single(false)?></h3>
				<?=$w->form?>
			<? endif ?>
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
	<? include_once('templates/teach-social-block.tpl.php') ?>
</div>
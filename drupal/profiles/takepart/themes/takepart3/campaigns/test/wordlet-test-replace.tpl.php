<pre>
modal_confirm:
<div>
	<?=w('modal_confirm') ?>
</div>

____________________________________________

<div <?=wa('finalists') ?>>
	<? foreach ( wl('finalists') as $finalist ): ?>
		$finalist->single: <?=$finalist->single ?>


		wr(w('modal_confirm'), $finalist):
		<div>
			<?=wr(w('modal_confirm'), $finalist) ?>
		</div>
		____________________________________________
	<? endforeach ?>
</div>

</pre>
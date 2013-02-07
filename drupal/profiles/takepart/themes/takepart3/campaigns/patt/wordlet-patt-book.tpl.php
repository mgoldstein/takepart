<div class="column column-1">
	<div class="content">
		<?=we('side_links')?>
		<ol>
			<? foreach ( wl('side_links') as $w ): ?>
				<li><a href="<?=$w->href?>">
					<?=$w->single(false)?>
				</a></li>
			<? endforeach ?>
		</ol>
	</div>
</div><!-- /.column-1 -->
<div class="column column-2">
	<div class="inner">
		<div class="overview">
			<?=w('body')?>
		</div>
	</div><!-- /.inner -->
</div><!-- /.column-2 -->
<? include_once('subtemplates/patt-right.tpl.php') ?>
<div class="column column-1">
	<div class="content">
		<p class="side_header">
			<?=w('side_header')?>
		</p>
		<?=we('side_links')?>
		<ol>
			<? foreach ( wl('side_links') as $w ): ?>
				<li><a href="<?=$w->href?>">
					<?=$w->single?>
				</a></li>
			<? endforeach ?>
		</ol>
	</div>
</div><!-- /.column-1 -->
<div class="column column-2">
	<div class="inner">
		<div class="overview">
			<div class="cms">
				<?=w('body')?>
			</div>
		</div>
	</div><!-- /.inner -->
</div><!-- /.column-2 -->
<? include_once('subtemplates/patt-right.tpl.php') ?>
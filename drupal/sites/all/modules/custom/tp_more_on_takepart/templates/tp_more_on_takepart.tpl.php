<footer id="more-on-takepart" class="clearfix">
	<h2><?php print t('More on TakePart'); ?></h2>

	<?php foreach($variables['article'] as $v) { print $v; } ?>

	<?php foreach($variables['global'] as $v) { print $v; } ?>

    <?php print $variables['taboola']; ?>

</footer>

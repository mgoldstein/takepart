<footer id="article-footer">
	<h3><?php print t('Related Stories on TakePart'); ?></h3>

	<?php foreach($variables['article'] as $v) { print $v; } ?>

    <h3 class="top-border"><?php print t('Takepart&#8217;s Most Popular'); ?></h3>

	<?php foreach($variables['global'] as $v) { print $v; } ?>

    <h3><?php print t('From The Web'); ?></h3>

    <?php print $variables['taboola']; ?>

</footer>

<header class="header">
	<div>
		<?php echo $image ?>
	</div>

	<h1 class="headline">
		<?php echo t($header) ?>
	</h1>
</header>

<div class="content">
	<div class="body">
		<?php echo t($body) ?>
	</div>

	<div class="socials">
	<?php echo $facebook."\n".$twitter; ?>
	</div>

	<p id="dont">
		<a href="#"><?php echo t($do_not_show) ?></a>
	</p>
</div>

<header class="header">
	<div>
		<?php $image ?>
	</div>

	<h1 class="headline">
		<?php t($header) ?>
	</h1>
</header>

<div class="content">
	<div class="body">
		<?php t($body) ?>
	</div>

	<div class="socials">
	<?php $facebook."\n".$twitter; ?>
	</div>

	<p id="dont">
		<a href="#"><?php t($do_not_show) ?></a>
	</p>
</div>

<header class="header">
	<div>
		<?= $image ?>
	</div>

	<h1 class="headline">
		<?= t($header) ?>
	</h1>
</header>

<div class="content">
	<div class="body">
		<?= t($body) ?>
	</div>

	<div class="form">
		<?= $newsletter_form; ?>
	</div>

	<p id="dont">
		<a href="#"><?= t($do_not_show) ?></a>
	</p>
</div>

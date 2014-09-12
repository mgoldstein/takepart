<?php
/**
 * @file
 * Returns the HTML for Playlist Navigation
 */
?>
<?php if ($title_prefix || $title_suffix || $display_submitted || $unpublished || !$page && $title): ?>
	<header>
		<?php print render($title_prefix); ?>
		<?php print render($title_suffix); ?>
	</header>
<?php endif; ?>
<?php
	hide($content['comments']);
	hide($content['links']);
	print render($content);
?>

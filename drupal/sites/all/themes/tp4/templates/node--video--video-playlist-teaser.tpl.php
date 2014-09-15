<?php
/**
 * @file
 * Returns the HTML for Playlist Navigation
 * We need to update the display of the image field.  Rather than altering a field formatter or using the hook_theme_field
 * function we will render out the two fields individually.  hook_theme_field is not possible for this field as it is widly
 * used throughout TP and altering the field formatter will result in slow the site down.
 */
?>
<div class="image-wrapper">
	<img src="<?php print $variables['thumbnail']; ?>">
	<div class="overlay">
		<div class="now-playing"><?php print t('now playing'); ?></div>
		<div class="play-me">play me</div>
	</div>
</div>
<div class="promo-headline">
	<?php print $variables['promo_headline']; ?>
</div>
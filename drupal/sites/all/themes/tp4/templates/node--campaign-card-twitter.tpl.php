<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
?>
<?php if($variables['background_class']) { ?>
<style>
.<?php print $variables['background_class']; ?> {
  <?php print $variables['background_image_mobile'][0]; ?>
}
@media only screen and (min-width: 728px) {
  .<?php print $variables['background_class']; ?> {
    <?php print $variables['background_image_tablet'][0]; ?>
  }
}
@media only screen and (min-width: 980px) {
  .<?php print $variables['background_class']; ?> {
    <?php print $variables['background_image_desktop'][0]; ?>
  }
}
</style>
<?php } ?>
<div class="card <?php print implode(' ', $variables['classes_array']); ?>" style="<?php print implode(' ', $variables['styles']); ?>">

  <article class="card-inner">
  <?php print render($title_suffix);  // contextual links ?>
    <?php if(isset($node->field_campaign_card_title['und'][0]['value']) == true): ?>
      <div class="title-wrapper"><h1 class="card-title"><?php print $node->field_campaign_card_title['und'][0]['value']; ?></h1></div>
    <?php endif; ?>


	<div class="tweet-card">
		<div class="tweet-card-inner">
	<?php

	$tweet_count = count($variables['tweet']);

	for($x=0; $x < $tweet_count; $x++){


	?>
	<div class="tweet">
		<div class="tweet-left">
			<img src="<?php print $variables['profile_pic'][$x]; ?>" class="profile-pic"></img>
		</div>

		<div class="tweet-right">
			<h3 class="tweet-username">@<?php print $variables['username'][$x]; ?></h3>
			<h6><?php print $variables['created_at'][$x]; ?></h6>
			<p><?php print $variables['tweet'][$x]; ?></p>
		</div>
	</div>

	<?php
	}
	?>

	</div>
	<div class="twitter-descriptive-text"><?php print $descriptive_text; ?></div>
</div>


</article>

</div>

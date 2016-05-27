<?php
/**
 * Template file for Campaign promo sidebar
 * To override, add inline-content-iframe.tpl.php to your theme
 */
?>

<div class="inline-interactive-campaign-promo">
  <h1 class="campaign-title">
    <?php print $campaign_title; ?>
  </h1>
  <p class= "number">
    <?php print $campaing_stories; ?>
  </p>
  <p class = "campaign-description">
    <?php print $campaign_description; ?>
  </p>
  <div class = "stories-wrapper">
    <!-- Just a placeholder till we have final designs -->
    <?php //TODO: Loop through $cic_info array for image and promo title?>
  </div>
  <a class = "see-more" href = " <?php print $campaign_url ?> ">More <?php print $campaign_title ?></a>

</div>

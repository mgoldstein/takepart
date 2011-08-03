<?php
/*
 * This is the template for the action embed not that we are NOT RENDERING
 * THE CONTENT OF THE DISPLAY MODE SETTING.  This is an isolated case
 * of just action embeds so it might not be a problem.
 *
 * We are going to leave the embed display mode empty so it is 
 * clear that we are not using those settings
 */
?>
<div class = "embed-action-wrapper">
  <div class = "embed-action">
    <?php print l($node->title, "node/{$node->nid}");  ?>
  </div>
</div>

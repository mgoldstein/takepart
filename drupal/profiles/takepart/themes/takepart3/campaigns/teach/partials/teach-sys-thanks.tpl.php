<div class="sys-thanks-social-share">
  <div class="row">
    <div class="col-2-3"><h3><?php print w('thanks_share_headline'); ?></h3></div>
    <div class="col-1-3">
     <div class="campaign-social-share scribble-share large" <?php print wa('thanks_share_data'); ?>
        <?php $w = w('thanks_share_data'); ?>
        data-shareURL="<?php print $w->href_raw; ?>"
        data-shareTitle="<?php print $w->single_no_markup; ?>"
        data-shareDescription="<?php print $w->multi_short_no_markup; ?>"
      ></div>
   </div>
  </div>
</div>
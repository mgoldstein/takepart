<?php
// node template to create vidpop preview for mobile devices
//
// vars:
//    $p_youtube_id         id of youtube video
//    $p_overlay_image      image for overlay
//    $p_promo_headline     headline of promo
//    $p_promo_text         text of promo
//    $vp_class             enclosing div class
?>
<div class="mobile-vidpop-notused">
  <div class="vidpop-preview <?print $vp_class; ?>"><iframe width="480" height="360" src="http://www.youtube.com/embed/<?print $p_youtube_id;?>?rel=0" frameborder="0" allowfullscreen></iframe>
    <a class="<?php print $link_class;?>" href="<?php print $href_string;?>" title="<?php print $node_title;?>"><div class="vidpop-preview-overlay"><?php print $overlay_image;?>
      <div class="vidpop-preview-overlay-text">
        <div class="line1"><span class="watch">WATCH</span><?php print $promo_headline;?></div>
        <div class="line2"><?php print $promo_text;?></div>
      </div>
    </div></a>
  </div>
</div>

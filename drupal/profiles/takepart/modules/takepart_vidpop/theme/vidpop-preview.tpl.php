<?php
// node template to create vidpop preview
//
// vars:
//    $p_youtube_id         id of youtube video
//    $p_overlay_image      image for overlay
//    $p_promo_headline     headline of promo
//    $p_promo_text         text of promo
//    $p_link_class         class for link
//    $p_href_string        string for href
//    $vp_class             enclosing div class
?>
<div class="vidpop-embed-promo-headline"><!-- promo_headline999 --></div>
<div class="vidpop-preview <?print $vp_class; ?>"><?php print $preview_image;?>
  <a class="<?php print $link_class;?>" href="<?php print $href_string;?>" title="<?php print $promo_headline;?>"><div class="vidpop-preview-overlay"><?php print $overlay_image;?>
    <div class="vidpop-preview-overlay-text">
      <div class="line1"><span class="watch">WATCH</span><?php print $promo_headline;?></div>
      <div class="line2"><?php print $promo_text;?></div>
    </div>
  </div></a>
</div>
<div class="vidpop-embed-promo-text">
  <!-- promo_text999 -->
</div>

<?php
  //Setting a random number so that each carousel will be unique
  $rand = rand();
?>

<div class="cic_bottom_promo_block_container tp-fresh-bottom-content" style="background-color:<?php print $campaign_info['bg_color'] ?>">
  <div<?php print $attributes; ?> class="<?php print $classes; ?> clearfix">
    <?php if($campaign_info['menu_logo']): ?>
      <h2><img src="<?php print $campaign_info['menu_logo']; ?>" ALT="<?php print $campaign_info['title']; ?>" /></h2>
    <?php else: ?>
      <h2><?php print $campaign_info['title'] ?></h2>
    <?php endif; ?>
    <div class="cic_bottom_promo_numb_stories"><?php print $campaign_info['story_num'] ?> STORIES</div>
    <div class="cic_bottom_promo<?php print $rand ?>">
      <?php  foreach($cic_info AS $cic): ?>
        <div class="item">
          <div class="cic_bottom_promo_item">
            <?php
              $item = theme_image(array('path' => $cic['thumbnail'],'alt' => $cic['title']));
              $item .= '<h3 class="'.($cic['status']?'':'node-unpublished').'">'.truncate_utf8($cic['title'], 70, TRUE, TRUE).'</h3>';
              print l($item, 'node/'.$cic['nid'], array('html'=>TRUE, 'attributes' => array('class' => 'cic_bottom_promo_story')));
            ?>
          </div>
        </div>
      <?php endforeach; ?>
    </div>
    <div class="owl-nav-custom">
      <div class="owl-prev-custom owl-prev-custom-<?php print $rand ?>" style="background-color:rgba(<?php print $campaign_info['rbg_color'][0].','.$campaign_info['rbg_color'][1].','.$campaign_info['rbg_color'][2] ?>,.8)"></div>
      <div class="owl-next-custom owl-next-custom-<?php print $rand ?>" style="background-color:rgba(<?php print $campaign_info['rbg_color'][0].','.$campaign_info['rbg_color'][1].','.$campaign_info['rbg_color'][2] ?>,.8)"></div>
    </div>
    <div class="cic_bottom_promo_see_more">
      <?php print l("Go to ".$campaign_info['title'], $campaign_info['url'], array('attributes' => array('class' => 'cic_bottom_promo_goto_campaign'))); ?>
    </div>
    <script>
      jQuery(document).ready(function(){
        var owl<?php print $rand ?> = jQuery('.cic_bottom_promo<?php print $rand ?>').owlCarousel({
          loop:true,
          margin:30,
          nav:false,
          responsive:{
            0:{
                items:1,
                slideBy:1,
                center:true,
                stagePadding:20,
                margin:5
            },
            374:{
                items:1,
                slideBy:1,
                center:true,
                stagePadding:50
            },
            600:{
                items:2,
                slideBy:2,
                center:false,
                stagePadding:0
            },
            980:{
                items:3,
                slideBy:3,
                center:false,
                stagePadding:0
            }
          }
        });
        jQuery('.owl-prev-custom-<?php print $rand ?>').click(function() {
            owl<?php print $rand ?>.trigger('prev.owl.carousel');
        });
        // Go to the previous item
        jQuery('.owl-next-custom-<?php print $rand ?>').click(function() {
            // With optional speed parameter
            // Parameters has to be in square bracket '[]'
            owl<?php print $rand ?>.trigger('next.owl.carousel', [300]);
        });
      });
    </script>
  </div>
</div>

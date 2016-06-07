<?php
/**
 * Template file for Campaign promo sidebar
 * To override, add inline-content-iframe.tpl.php to your theme
 */
?>

<div class="inline-interactive-campaign-promo">
  <div class="stories-header" style="background-color: <?php print $campaign_info['bg_color']; ?>">
    <h3 class="campaign-title">
      <?php print l($campaign_info['title'], $campaign_info['url'], array('attributes' => array('class' => array('stories-header-link')))); ?>
    </h3>
    <h4>
      BIG ISSUE vol. <?php print $campaign_info['vol']; ?>
    </h4>
    <p class = "campaign-description">
      <?php print $campaign_info['description']; ?>
    </p>
  </div>
  <div class = "stories-wrapper" style="border: 2px solid <?php print $campaign_info['bg_color']; ?>">
    <?php  //Loop through $cic_info array for image and promo title
      foreach($cic_info AS $k => $cic):
        print '<div class="stories-item stories-item-'.$k.'">';
        $item = theme_image(array('path' => $cic['thumbnail'],'alt' => $cic['title']));
        $item .= '<p class="stories-title">'.$cic['title'].'</p>';
        print l($item, 'node/'.$cic['nid'], array('html'=>TRUE));
        print '</div>';
      endforeach;
    ?>
  </div>

  <?php //PLACEHOLDER for link to stories landing print $campaing_info['stories']; ?>
</div>

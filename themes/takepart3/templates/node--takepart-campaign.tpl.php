<?php if (!empty($pre_object)) print render($pre_object) ?>

<div class='layout-col-3 <?php print $classes ?> clearfix' <?php print ($attributes) ?>>
  
  <?php if ($title): ?><h1 class='page-title'><?php print $title ?></h1><?php endif; ?>
  <?php if (isset($primary_local_tasks)): ?><ul class='links clearfix'><?php print render($primary_local_tasks) ?></ul><?php endif; ?>
  
  
  <?php /*
  
  Campaign Header with Graphic/Video
  
  */?>
  <div id='node-type-takepart-campaign-header'>    
    <div class='node-type-takepart-campaign-five-things'>
      
    <?php print render($content['field_tp_campaign_5_things_head']); ?>
    <?php
      $output = '<ul>';
      foreach ($node->field_tp_campaign_4_things_link['und'] as $link => $value) {
          $output .= "<li>" . l(t($value['title']), $value['url'], array('attributes' => array('class' => array('campaign-five-things-num-'.($link+1))))) . "</li>";
      }
      print $output . "</ul>";
    ?>
    </div>  
    
    
    <?php // print render($content['field_tp_campaign_intro_html']); ?>
    
  </div>
  
  <?php if (!empty($title_prefix)) print render($title_prefix); ?>

  <?php if (!empty($content)): ?>
    <div class='content clearfix col <?php if (!empty($is_prose)) print 'prose' ?>'>
      <div class='inner-content'>
      <?php // print render($content) ?>
      
      <?php print render($content['field_tp_campaign_subheadline']); ?>
      <?php print render($content['body']); ?>
      
      <!-- Seg 1 -->
      <?php print render($content['field_tp_campaign_seg_1_label']); ?>
      <?php print render($content['field_tp_campaign_seg_1_rel']); ?>
      
      <!-- Seg 2 -->
      <?php print render($content['field_tp_campaign_seg_2_label']); ?>
      <?php print render($content['field_tp_campaign_seg_2_rel']); ?>
      
      
      <!-- Seg 3 -->
      <?php print render($content['field_tp_campaign_seg_3_label']); ?>
      <?php print render($content['field_tp_campaign_seg_3_rel']); ?>
      
      <!-- Seg 4 -->
      <?php print render($content['field_tp_campaign_seg_4_label']); ?>
      <?php print render($content['field_tp_campaign_seg_4_rel']); ?> 
      
      </div>
    </div>
  <?php endif; ?>
  
  
  
  <div class='sidebar-first col'>
    <div class='inner-content'>
      <?php print render($content['field_tp_campaign_cover_image']); ?>
      <br/>
      Available on DVD and Digital Download<br/><br/>
      Learn More 
    </div>
  </div>
  
  
  <div class='sidebar-second col'>
    <div class='inner-content'>
      <div class='tag-sponsored-by'><h3>Sponsored By:</h3></div>
      <div class='tag tag-take-action'><h3>Take Action!</h3></div>
      <div class='tag tag-alliances'><h3>Alliances</h3></div>
      <!-- Alliances -->
      <?php // print render($content['field_tp_campaign_allances']); ?>
      <div class='tag tag-spotlight'><h3>Spotlight</h3></div>
      <!-- Spotlight -->
      <?php // print render($content['field_tp_campaign_sl_image']); // Image ?>
      <?php // print render($content['field_tp_campaign_sl_html']); // HTML ?>
    </div>
  </div>
  
  

  <?php if (!empty($links)): ?>
    <div class='links clearfix'>
      <?php print render($links) ?>
    </div>
  <?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object) ?>

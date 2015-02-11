<?php global $base_url; ?>
<?php global $is_https; ?>
<div class="content" id="foodinc-howto">
  <section class="page-body-content cms">

    <!-- Intro  -->
    <div class="page-title"><h3>HOW TO ENTER</h3></div>
    <div class="intro">
      <div class="title"><?php print w('foodinc_howto_intro')->single; ?></div>
      <div class="description"><?php print w('foodinc_howto_intro')->multi; ?></div>
      <?php if(w('foodinc_howto_intro')->video != NULL): ?>
        <div class="video">
          <?php if(substr(w('foodinc_howto_intro')->video, 0, 7 ) === "http://"): ?>
            <?php $youtube_id = substr(w('foodinc_howto_intro')->video, strpos(w('foodinc_howto_intro')->video, '=') +1); ?>
            <?php $count = 1; ?>
            <?php $youtube_id = str_replace('&', '?', $youtube_id, $count); ?>
            <iframe width="635" height="360" src="//www.youtube.com/embed/<?php print $youtube_id; ?>" frameborder="0" allowfullscreen></iframe>
          <?php else: ?>
            <?php if($base_url == 'https://foodinc.takepart.com' || $is_https != NULL): ?>
              <script type="text/javascript" src="https://content.jwplatform.com/players/<?php print w('foodinc_howto_intro')->video; ?>.js"></script>
            <?php else: ?>
              <script type="text/javascript" src="//content.jwplatform.com/players/<?php print w('foodinc_howto_intro')->video; ?>.js"></script>
            <?php endif; ?>
          <?php endif; ?>
        </div>
      <?php else: ?>
        <img src="<?php print w('foodinc_howto_intro')->img_src; ?>" alt="food inc awards">
      <?php endif; ?>
    </div>

    <!-- CATEGORIES  -->
    <div class="categories">
      <?php foreach( wl('foodinc_howto_categories') as $key => $w ): ?>
        <div class="row row-id-<?php print $key; ?> <?php print ($key % 2 == 0 ? 'row-odd' : 'row-even'); ?>">
          <div class="title"><?php print $w->single; ?></div>
          <div class="description"><?php print $w->multi; ?></div>
        </div>
      <?php endforeach ?>
    </div>

    <!-- ADDITIONAL INFO  -->
    <div class="additional-info">
      <?php foreach( wl('foodinc_howto_additional_info') as $key => $w ): ?>
        <div class="row row-id-<?php print $key; ?> <?php print ($key % 2 == 0 ? 'row-odd' : 'row-even'); ?>">
          <div class="title"><?php print $w->single; ?></div>
          <div class="description"><?php print $w->multi; ?></div>
          <?php if($w->video != NULL): ?>
            <div class="video">
              <?php if(substr($w->video, 0, 7 ) === "http://"): ?>
                <?php $youtube_id = substr($w->video, strpos($w->video, '=') +1); ?>
                <?php $count = 1; ?>
                <?php $youtube_id = str_replace('&', '?', $youtube_id, $count); ?>
                <iframe width="635" height="360" src="//www.youtube.com/embed/<?php print $youtube_id; ?>" frameborder="0" allowfullscreen></iframe>
              <?php else: ?>
                <?php if($base_url == 'https://foodinc.takepart.com' || $is_https != NULL): ?>
                  <script type="text/javascript" src="https://content.jwplatform.com/players/<?php print w('foodinc_howto_additional_info')->video; ?>.js"></script>
                <?php else: ?>
                  <script type="text/javascript" src="//content.jwplatform.com/players/<?php print w('foodinc_howto_additional_info')->video; ?>.js"></script>
                <?php endif; ?>
              <?php endif; ?>
            </div>
          <?php elseif($W->img_src != NULL): ?>
            <img src="<?php print $w->img_src; ?>" alt="<?php print $w->single; ?>">
          <?php endif; ?>
        </div>
      <?php endforeach ?>
    </div>
  </section>
    <section class="right-rail">
    <div class="ad">
            <!-- place in the <body> to display the 300x250 ad -->
      <!-- TP3_ROS_RR_ATF_300x250 -->
      <div id='div-gpt-ad-1379616725962-0' style='width:300px; height:250px;'>
      <script type='text/javascript'>
      googletag.cmd.push(function()
      { googletag.display('div-gpt-ad-1379616725962-0'); }
      );
      </script>
      </div>
    </div>
  </section>
</div>









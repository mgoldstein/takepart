<div class="content" id="foodinc-howto">
  <h2>FOOD, INC. AWARDS 2013</h2> <!--how to add it back -->
  <section class="page-body-content cms">

    <!-- Intro  -->
    <div class="page-title"><h3>HOW TO ENTER</h3></div>
    <div class="intro">
      <div class="title"><?php print w('foodinc_howto_intro')->single; ?></div>
      <div class="description"><?php print w('foodinc_howto_intro')->multi; ?></div>
      <?php if(w('foodinc_howto_intro')->video != NULL): ?>
        <div class="video">
          <?php if(substr(w('foodinc_howto_intro')->video, 0, 7 ) === "http://"): ?>
            <?php $youtube_id = substr(w('foodinc_howto_intro')->video, strrpos(w('foodinc_howto_intro')->video, '=') + 1);; ?>
            <iframe width="510" height="285" src="//www.youtube.com/embed/<?php print $youtube_id; ?>" frameborder="0" allowfullscreen></iframe>
          <?php else: ?>
            <script type="text/javascript" src="http://video.takepart.com/players/<?php print w('foodinc_howto_intro')->video; ?>.js"></script>
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
      <? endforeach ?>
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
                <?php $youtube_id = substr($w->video, strrpos($w->video, '=') + 1);; ?>
                <iframe width="510" height="285" src="//www.youtube.com/embed/<?php print $youtube_id; ?>" frameborder="0" allowfullscreen></iframe>
              <?php else: ?>
                <script type="text/javascript" src="http://video.takepart.com/players/<?php print w('foodinc_howto_additional_info')->video; ?>.js"></script>
              <?php endif; ?>
            </div>
          <?php else: ?>
            <img src="<?php print w('foodinc_howto_additional_info')->img_src; ?>" alt="<?php print w('foodinc_howto_additional_info')->single; ?>">
          <?php endif; ?>
        </div>
      <? endforeach ?>
    </div>
  </section>
    <section class="right-rail">
      <div class="instruction-block">
        <div class="top"></div>
        <div class="mid">
          <?php foreach( wl('foodinc_howto_instruction_steps') as $key => $w ): ?>
            <?php $number = $key + 1; ?>
            <div class="item"><div class="number"><?php print $number; ?></div><span><?php print $w->single; ?></span></div>
          <?php endforeach; ?>
          <div class="button"><?php print l(w('foodinc_howto_instruction_button')->single, w('foodinc_howto_instruction_button')->href); ?></div>
          <div class="extra"><?php print w('foodinc_howto_instruction_block')->multi; ?></div>
        </div>
        <div class="bottom"></div>
      </div>
    <div class="ad"><?php print (w('foodinc_howto_adblock') != NULL ? render(w('foodinc_howto_adblock')) : ''); ?></div>
  </section>
</div>









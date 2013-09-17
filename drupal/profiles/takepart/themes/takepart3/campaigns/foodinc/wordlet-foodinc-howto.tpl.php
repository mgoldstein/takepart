<div class="content" id="foodinc-howto">
  <h2>FOOD, INC. AWARDS 2013</h2> <!--how to add it back -->
  <section class="page-body-content cms">

    <!-- Intro  -->
    <h4>HOW TO ENTER</H4>
    <?php print w('foodinc_howto_intro')->single; ?>
    <?php print w('foodinc_howto_intro')->multi; ?>
    <?php if(w('foodinc_howto_intro')->video != NULL): ?>
      <div class="video">
        <?php if(substr(w('foodinc_howto_intro')->video, 0, 7 ) === "http://"): ?>
          <?php $youtube_id = substr(w('foodinc_howto_intro')->video, strrpos(w('foodinc_howto_intro')->video, '=') + 1);; ?>
          <iframe width="520" height="315" src="//www.youtube.com/embed/<?php print $youtube_id; ?>" frameborder="0" allowfullscreen></iframe>
        <?php else: ?>
          <script type="text/javascript" src="http://video.takepart.com/players/<?php print w('foodinc_howto_intro')->video; ?>.js"></script>
        <?php endif; ?>
      </div>
    <?php else: ?>
      <img src="<?php print w('foodinc_howto_intro')->img_src; ?>" alt="food inc awards">
    <?php endif; ?>

    <!-- CATEGORIES  -->
    <?php foreach( wl('foodinc_howto_categories') as $key => $w ): ?>
      <div class="row row-id-<?php print $key; ?> <?php print ($key % 2 == 0 ? 'row-odd' : 'row-even'); ?>">
        <div class="title"><?php print $w->single; ?></div>
        <div class="description"><?php print $w->multi; ?></div>
      </div>
    <? endforeach ?>

    <!-- ADDITIONAL INFO  -->
    <?php foreach( wl('foodinc_howto_additional_info') as $key => $w ): ?>
      <div class="row row-id-<?php print $key; ?> <?php print ($key % 2 == 0 ? 'row-odd' : 'row-even'); ?>">
        <div class="title"><?php print $w->single; ?></div>
        <div class="description"><?php print $w->multi; ?></div>
        <?php if(w('foodinc_howto_intro')->video != NULL): ?>
          <div class="video">
            <?php if(substr(w('foodinc_howto_additional_info')->video, 0, 7 ) === "http://"): ?>
              <?php $youtube_id = substr(w('foodinc_howto_additional_info')->video, strrpos(w('foodinc_howto_additional_info')->video, '=') + 1);; ?>
              <iframe width="520" height="315" src="//www.youtube.com/embed/<?php print $youtube_id; ?>" frameborder="0" allowfullscreen></iframe>
            <?php else: ?>
              <script type="text/javascript" src="http://video.takepart.com/players/<?php print w('foodinc_howto_additional_info')->video; ?>.js"></script>
            <?php endif; ?>
          </div>
        <?php else: ?>
          <img src="<?php print w('foodinc_howto_additional_info')->img_src; ?>" alt="<?php print w('foodinc_howto_additional_info')->single; ?>">
        <?php endif; ?>
      </div>
    <? endforeach ?>
  </section>
    <section class="right-rail">
      <?php print w('foodinc_howto_instruction_block'); ?>
    <div class="ad"><?php print (w('foodinc_howto_adblock') != NULL ? render(w('foodinc_howto_adblock')) : ''); ?></div>
  </section>
</div>

<div class="content" id="foodinc-entryreceived">
  <h2>FOOD, INC. AWARDS 2013</h2> <!--how to add it back -->
  <section class="page-body-content cms">

    <!-- Entry Received  -->
    <div class="page-title"><?php print w('foodinc_entryreceived_main')->single; ?></h3></div>
    <div class="intro">
      <div class="text"><?php print w('foodinc_entryreceived_main')->multi; ?></div>
    </div>


    <!-- ADDITIONAL INFO  -->
    <div class="additional-info">
      <?php foreach( wl('foodinc_entryreceived_additional') as $key => $w ): ?>
        <div class="row row-id-<?php print $key; ?> <?php print ($key % 2 == 0 ? 'row-odd' : 'row-even'); ?>">
          <div class="title"><?php print $w->single; ?></div>
          <div class="description"><?php print $w->multi; ?></div>
        </div>
      <? endforeach ?>
    <div class="social-block">
      <div class="facebook social"></div>
      <div class="twitter social"></div>
      <div class="googleplus social"></div>
      <div class="email social"></div>
    </div>
    </div>
  </section>

    <section class="right-rail">
    <div class="ad"><?php print (w('foodinc_entryreceived_adblock') != NULL ? render(w('foodinc_entryreceived_adblock')) : ''); ?></div>
  </section>
</div>









<div class="content" id="foodinc-entryreceived">
  <section class="page-body-content cms">

    <!-- Entry Received  -->
    <div class="page-title"><?php print w('foodinc_entryreceived_main')->single; ?></h3></div>
    <div class="intro">
      <div class="text"><p><?php print w('foodinc_entryreceived_main')->multi; ?></p></div>
    </div>


    <!-- ADDITIONAL INFO  -->
    <div class="additional-info">
      <?php foreach( wl('foodinc_entryreceived_additional') as $key => $w ): ?>
        <div class="row row-id-<?php print $key; ?> <?php print ($key % 2 == 0 ? 'row-odd' : 'row-even'); ?>">
          <div class="title"><?php print $w->single; ?></div>
          <div class="description"><?php print $w->multi; ?></div>
        </div>
      <? endforeach ?>
      <aside id="foodinc-social" class="social entry-received">
        <div class="tp-social"></div>
      </aside>

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







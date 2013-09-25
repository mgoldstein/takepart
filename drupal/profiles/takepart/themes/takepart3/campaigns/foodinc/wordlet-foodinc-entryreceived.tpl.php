<?php
  $imgpath = image_style_url('thumb', w('foodinc_entryreceived_facebook_image')->single);
  $og_image = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'property' => 'og:image',
      'content' => $imgpath,
    ),
  );
  drupal_add_html_head($og_image, 'og_image');

  $description = w('foodinc_entryreceived_facebook_caption')->multi;
  $og_description = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'property' => 'og:description',
      'content' => $description,
    ),
  );
  drupal_add_html_head($og_description, 'og_description');

?>

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
                  <?php wa('foodinc_social_title'); ?>
            <?php wa('foodinc_social_image'); ?>
            <?php wa('foodinc_social_text'); ?>
            <?php wa('foodinc_social_caption'); ?>
            <?php wa('foodinc_social_twitter_via'); ?>
      <aside id="foodinc-social-received" class="social" facebook-title="<?php print w('foodinc_entryreceived_facebook_title')->single; ?>"
        facebook-url="<?php print w('foodinc_entryreceived_facebook_url')->single; ?>" facebook-image="<?php print w('foodinc_entryreceived_facebook_image')->img_src; ?>"
        facebook-text="<?php print w('foodinc_entryreceived_facebook_caption')->multi; ?>" email-title="<?php print w('foodinc_entryreceived_email_title')->single; ?>"
        email-url="<?php print w('foodinc_entryreceived_email_url')->single; ?>" email-text="<?php print w('foodinc_entryreceived_email_text')->single; ?>"
        google-title="<?php print w('foodinc_entryreceived_googleplus_title')->single; ?>" google-url="<?php print w('foodinc_entryreceived_googleplus_url')->single; ?>"
        twitter-via="<?php print w('foodinc_entryreceived_twitter_via')->single; ?>" twitter-text="<?php print w('foodinc_entryreceived_twitter_text')->single; ?>"
        twitter-url="<?php print w('foodinc_entryreceived_twitter_url')->single; ?>">
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






<?php
    $og_description = array(
      '#tag' => 'meta',
      '#attributes' => array(
        'property' => 'og:description',
        'content' => w('fb_description')->multi,
      ),
    );
    drupal_add_html_head($og_description, 'og_description');
    global $base_url;
    global $is_https;
    global $messages;
?>
<div class="content" id="foodinc-awards">
  <header>
    <div class="hero">
      <?php if(w('hero_content')->video != NULL): ?>
        <div class="video">
          <?php if(substr(w('hero_content')->video, 0, 7 ) === "http://"): ?>
            <?php $youtube_id = substr(w('hero_content')->video, strpos(w('hero_content')->video, '=') +1); ?>
            <?php $count = 1; ?>
            <?php $youtube_id = str_replace('&', '?', $youtube_id, $count); ?>
            <iframe width="510" height="285" src="//www.youtube.com/embed/<?php print $youtube_id; ?>" frameborder="0" allowfullscreen></iframe>
          <?php else: ?>
            <div class="botr">
              <?php if($base_url == 'https://foodinc.takepart.com' || $is_https != NULL): ?>
                <script type="text/javascript" src="https://content.jwplatform.com/players/<?php print w('hero_content')->video; ?>.js"></script></div>
              <?php else: ?>
                <script type="text/javascript" src="//content.jwplatform.com/players/<?php print w('hero_content')->video; ?>.js"></script></div>
              <?php endif; ?>
          <?php endif; ?>
        </div>
      <?php else: ?>
        <img src="<?php print w('hero_content')->img_src; ?>" alt="food inc awards">
      <?php endif; ?>
      <div class="hero-title"><?php print w('hero_content')->single; ?></div>
      <div class="hero-description"><?php print w('hero_content')->multi; ?></div>
      <div class="learn-more">
      <p>Interested?</p>
        <?php foreach( wl('foodinc_awards_hero_links') as $key => $w ): ?>
          <?php print l($w->single, $w->href); ?>
        <?php endforeach; ?>
      </div>
    </div>
  </header>
  <section class="page-body-content cms">
    <div id="foodinc-categories">
      <?php foreach( wl('foodinc_awards_categories') as $key => $w ): ?>
        <?php if($key == 0): ?>
        <div class="row row-id-<?php print $key; ?>">
          <div class="image"><img src="<?php print $w->img_src; ?>"></div>
          <div class="category-info">
            <div class="category-title"><h2>THE CATEGORIES</h2></div>
            <div class="categories-title"><?php print $w->single; ?></div>
            <div class="category-text"><?php print $w->multi; ?></div>
          </div>
        </div>
      <?php else: ?>
        <div class="row row-id-<?php print $key; ?> <?php print ($key % 2 == 0 ? 'row-even' : 'row-odd'); ?>">
          <div class="image"><img src="<?php print $w->img_src; ?>"></div>
          <div class="category-info">
            <div class="title-wrapper"><div class="categories-title"><?php print $w->single; ?></div></div>
            <div class="category-text"><?php print $w->multi; ?></div>
          </div>
        </div>
      <?php endif; ?>
      <?php endforeach ?>
    </div> <!-- end categories -->
    <div class="judges" id="judges">
      <h2>THE JUDGES</h2>
      <?php foreach( wl('foodinc_awards_judges') as $key => $w ): ?>
        <div class="row row-id-<?php print $key; ?> <?php print ($key % 2 == 0 ? 'row-odd' : 'row-even'); ?>">
          <img src="<?php print $w->thumb_src; ?>">
          <div class="info">
            <div class="name"><?php print $w->single; ?></div>
            <div class="bio show-more-height"><?php print $w->multi; ?></div>
          </div>
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
    <div class="newsletter">
      <div class="title"><?php print w('foodinc_awards_stayconnected')->single; ?></div>
      <div class="form-wrapper-first">
        <?php print w('foodinc_awards_stayconnected')->form; ?>
      </div>
    </div>
  </section>
</div>


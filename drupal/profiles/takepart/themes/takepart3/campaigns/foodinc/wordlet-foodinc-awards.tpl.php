<div class="content" id="foodinc-awards">
  <header>
    <h2 class="content-header"><span><?=w('foodinc_title')?></span></h2>
    <div class="hero">

      <?php if(w('hero_content')->video != NULL): ?>
        <div class="video">
          <?php if(substr(w('hero_content')->video, 0, 7 ) === "http://"): ?>
            <?php $youtube_id = substr(w('hero_content')->video, strrpos(w('hero_content')->video, '=') + 1);; ?>
            <iframe width="510" height="285" src="//www.youtube.com/embed/<?php print $youtube_id; ?>" frameborder="0" allowfullscreen></iframe>
          <?php else: ?>
            <script type="text/javascript" src="http://video.takepart.com/players/<?php print w('hero_content')->video; ?>.js"></script>
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
            <div class="category-title"><?php print $w->single; ?></div>
            <div class="category-text"><?php print $w->multi; ?></div>
          </div>
        </div>
      <?php else: ?>
        <div class="row row-id-<?php print $key; ?> <?php print ($key % 2 == 0 ? 'row-even' : 'row-odd'); ?>">
          <div class="image"><img src="<?php print $w->img_src; ?>"></div>
          <div class="category-info">
            <div class="category-title"><?php print $w->single; ?></div>
            <div class="category-text"><?php print $w->multi; ?></div>
          </div>
        </div>
      <?php endif; ?>
      <? endforeach ?>
    </div> <!-- end categories -->
    <div class="judges">
      <h2>THE JUDGES</h2>
      <?php foreach( wl('foodinc_awards_judges') as $key => $w ): ?>
        <div class="row row-id-<?php print $key; ?> <?php print ($key % 2 == 0 ? 'row-odd' : 'row-even'); ?>">
          <img src="<?php print $w->thumb_src; ?>">
          <div class="info">
            <div class="name"><?php print $w->single; ?></div>
            <div class="bio show-more-height"><?php print $w->multi; ?></div>
            <div class="show-more">See More</div>
          </div>
        </div>
      <? endforeach ?>
    </div>
  </section>
  <section class="right-rail">
    <div class="ad"><?php print (w('foodinc_awards_adblock') != NULL ? render(w('foodinc_awards_adblock')) : ''); ?></div>
    <div class="newsletter">
      <div class="top"><div class="title"><?php print w('foodinc_awards_stayconnected')->single; ?></div></div>
      <div class="mid"><?php print w('foodinc_awards_stayconnected')->multi; ?></div>
      <div class="bottom"></div>
      <div class="extra"><?php print w('foodinc_awards_stayconnected')->block; ?></div>
    </div>
  </section>
</div>




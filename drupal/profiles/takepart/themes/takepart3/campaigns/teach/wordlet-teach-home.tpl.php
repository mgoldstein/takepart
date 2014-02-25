<div class="page-body-content">
  <div class="row" <?php print wa('home_sections'); ?> >
    <?php foreach (wl('home_sections') as $w) : ?>
    <div class="col-1-3 home-section">
      <div class="image-wrapper"><img src="<?php print $w->img_src; ?>"></div>
      <h2 class="headline"><?php print $w->single; ?></h2>
      <div class="body"><?php print $w->multi; ?></div>
    </div>
    <?php endforeach; ?>
  </div>
  <section class="featured-articles">
    <h2><?php print w('featured_articles_headline'); ?></h2>
    <div><?php print w('featured_stories_block');?></div>
  </section>
  <section class="social-menu">
    <? include('partials/teach-social-block.tpl.php') ?>
  </section>
</div>

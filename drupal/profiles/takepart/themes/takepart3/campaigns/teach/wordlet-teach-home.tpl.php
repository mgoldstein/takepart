<div class="page-body-content">
  <div class="row" <?php print wa('home_sections'); ?> >
    <?php foreach (wl('home_sections') as $w) : ?>
    <div class="col-1-3 home-section">
      <div class="image-wrapper"><a href="<?php print $w->href; ?>"><img src="<?php print $w->img_src; ?>"></a></div>
      <h2 class="headline"><?php print $w->single; ?></h2>
      <div class="body"><?php print $w->multi; ?></div>
    </div>
    <?php endforeach; ?>
  </div>
  <section class="teach-home-featured-articles">
    <h2><span><?php print w('featured_articles_headline'); ?></span></h2>
    <div><?php print w('featured_stories_block');?></div>
    <div class="more-news" <?php print wa('more_news'); ?>>
      <?php $w = w('more_news'); ?>
      <a href="<?php print $w->href; ?>"><?php print $w->single; ?></a>
    </div>
  </section>
  <section class="social-menu">
    <? include('partials/teach-social-block.tpl.php') ?>
  </section>
  <?php include('partials/teach-watch-promo.tpl.php'); ?>
</div>

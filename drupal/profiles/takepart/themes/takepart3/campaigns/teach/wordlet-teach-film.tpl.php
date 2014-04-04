<div class="content teach-film-page teach-video-page">
  <h1 class="content-preheader"><?php print w('film_headline'); ?></h1>
  <h2 class="content-subheadline"><?php print w('film_subheadline'); ?></h2>

  <div data-jwposter-frame="<?= w('video')->src; ?>"
       data-jwplaylist="<?= w('video')->href; ?>"
       id="main-video-wrapper"
       class="main-video-wrapper" <?= wa('video'); ?>>
      <div id="main-video"></div>
  </div>

  <div class="row">
    <div class="col-1-2">
      <h3 class="sect-headline"><?php print w('film_section_headline'); ?></h3>
      <div class="sect-body"><?php print w('film_section_body'); ?></div>
      <h3 class="sect-headline"><?php print w('screening_headline'); ?></h3>
      <div class="sect-body"><?php print w('screening_body'); ?></div>
      <ol <?php print wa('screening_steps'); ?>>
        <?php foreach (wl('screening_steps') as $w) : ?>
        <li><?php print $w->multi; ?></li>
        <?php endforeach; ?>
      </ol>
    </div>
    <div class="col-1-2">
      <?php include('partials/teach-watch-promo.tpl.php'); ?>
      <aside class="screening-tips">
        <h3 class="tips-header"><?php print w('screening_tips_headline'); ?></h3>
        <div><?php print w('screening_tips_body'); ?></div>
      </aside>
    </div>
  </div>
  <section class="social-menu">
  <?php include('partials/teach-social-block.tpl.php'); ?>
  </section>
</div>

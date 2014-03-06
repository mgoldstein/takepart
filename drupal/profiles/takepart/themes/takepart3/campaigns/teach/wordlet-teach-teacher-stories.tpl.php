<div class="content teach-story-content teach-teacher-stories-content">
  <h1 class="sys-headline"><span><?php print w('teacher_stories_headline'); ?></span></h1>
  <div class="sys-intro-body"><?php print w('teacher_stories_intro_body'); ?></div>
  <div class="row">
    <div class="col-1-2">
      <section class="sys-stats">
        <div class="sys-stats-content">
          <h2>
            <span>Headline Number 1</span>
            <span>Headline Number 2</span>
            <span>Headline Number 3</span>
          </h2>
          <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</p>
          <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</p>
          <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</p>
        </div>
      </section>
    </div>
    <div class="col-1-2">
      <?php include('partials/teach-sys-cta.tpl.php'); ?>
      <section class="featured-stories" <?php print wa('featured_stories'); ?>>
        <h2 class="short-headline"><span><?php print w('featured_stories_headline'); ?></span></h2>
        <?php foreach(wl('featured_stories') as $w) : ?>
        <article data-storyid="<?php print $w->single_no_markup; ?>" class="featured-story"></article>
        <?php endforeach; ?>
      </section>
    </div>
  </div>
  <section class="social-menu">
  <?php include('partials/teach-social-block.tpl.php'); ?>
  </section>
</div>
<script type="text/x-microtemplate" id="featured_story_template">
  <img src="http://placehold.it/350x240" data-src=".jpg" data-width="350" data-height="240" data-crop="fill" data-gravity="faces"/>
  <blockquote>Story Preview Blockquote Lorem ipsum dolor sit amet, consectetur adipisicing elit.</blockquote>
  <div class="story-content">
    <h2 class="teacher-name">Teacher Name</h2>
    <p class="story-meta">
      School Name<br />
      City Name, ST <a href="#">read story &raquo;</a>
    </p>
  </div>
</script>

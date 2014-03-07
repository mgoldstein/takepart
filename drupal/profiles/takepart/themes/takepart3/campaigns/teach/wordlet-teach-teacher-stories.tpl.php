<div class="content teach-story-content teach-teacher-stories-content">
  <h1 class="sys-headline"><span><?php print w('teacher_stories_headline'); ?></span></h1>
  <div class="sys-intro-body"><?php print w('teacher_stories_intro_body'); ?></div>
  <div class="row">
    <div class="col-1-2">
      <section class="sys-stats">
        <div class="sys-stats-content">

          <h2>
            <span>Find Stories from</span>
            <span>Your School</span>
          </h2>
          <div>WIDGET GOES HERE</div>

          <h2 class="teach-fund-headline"><span>the</span><span>Teach Fund</span></h2>
          <div class="teach-fund-count"><span class="campaign-stat count"><?php print w('update_count'); ?></span><span>and counting</span></div>
          <div class="teach-fund-body"><?php print w('teach_fund_body'); ?></div>
          <?php $w = w('teach_fund_button'); ?>
          <div class="teach-fund-button"><a href="<?php print $w->href; ?>" wa('teach_fund_button')><?php print $w->single; ?></a></div>

          <h2 class="most-stories-headline"><span>Schools with the Most Stories</span></h2>
          <ol class="most-stories-list" id="most-stories-latest">
            <li>LATEST School Name<br>City Name, ST</li>
            <li>School Name<br>City Name, ST</li>
            <li>School Name<br>City Name, ST</li>
            <li>School Name<br>City Name, ST</li>
            <li>School Name<br>City Name, ST</li>
          </ol>
          <ol class="most-stories-list" id="most-stories-overall">
            <li>OVERALL School Name<br>City Name, ST</li>
            <li>School Name<br>City Name, ST</li>
            <li>School Name<br>City Name, ST</li>
            <li>School Name<br>City Name, ST</li>
            <li>School Name<br>City Name, ST</li>
          </ol>
          <nav id="most-stories-nav" class="most-stories-nav"><a href="#most-stories-latest">show latest</a> | <a href="#most-stories-overall">overall</a></nav>

          <h2><span>Teacher Story Stats</span></h2>
          <div class="teacher-story-stat stats-stories">
            <span class="campaign-stat">54,321</span>
            <span class="stat-label">Stories</span>
          </div>
          <div class="teacher-story-stat stats-teachers">
            <span class="campaign-stat">54,321</span>
            <span class="stat-label">Teachers</span>
          </div>
          <div class="teacher-story-stat stats-schools">
            <span class="campaign-stat">54,321</span>
            <span class="stat-label">Schools</span>
          </div>
          <div class="teacher-story-stat stats-states">
            <span class="campaign-stat">53</span>
            <span class="stat-label">States</span>
          </div>
          <nav><a href="/teach/stories">browse stories</a>
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

<div class="content teach-story-content teach-teacher-stories-content">
  <div class="preface">
    <h1 class="sys-headline"><span><?php print w('teacher_stories_headline'); ?></span></h1>
    <div class="sys-intro-body"><?php print w('teacher_stories_intro_body'); ?></div>
  </div>
  <div class="row">
    <div class="col-1-2">
      <section class="sys-stats">
        <div class="sys-stats-content">

          <h2>
            <span>Find Stories from</span>
            <span>Your School</span>
          </h2>
          <?php include ('partials/teach-sys-browse-by-school.tpl.php'); ?>

          <h2 class="teach-fund-headline"><span>the</span><span>Teach Fund</span></h2>
          <div class="teach-fund-count"><span>Help Us Raise</span><span class="campaign-stat count">50,000</span><span>For Classrooms!</span></div>
          <div class="teach-fund-body"><?php print w('teach_fund_body'); ?></div>
          <?php $w = w('teach_fund_button'); ?>
          <div class="teach-fund-button"><a href="<?php print $w->href; ?>" wa('teach_fund_button')><?php print $w->single; ?></a></div>

          <h2 class="most-stories-headline"><span>Schools with the Most Stories</span></h2>
          <ol class="most-stories-list" id="most-stories-latest"></ol>
          <ol class="most-stories-list" id="most-stories-overall"></ol>
          <nav id="most-stories-nav" class="most-stories-nav"><a href="#most-stories-latest">show latest</a> | <a href="#most-stories-overall">overall</a></nav>

          <h2><span>Teacher Story Stats</span></h2>
          <div class="teacher-story-stat stats-stories">
            <span class="campaign-stat">&nbsp;</span>
            <span class="stat-label">Stories</span>
          </div>
          <div class="teacher-story-stat stats-schools">
            <span class="campaign-stat">&nbsp;</span>
            <span class="stat-label">Schools</span>
          </div>
          <div class="teacher-story-stat stats-states">
            <span class="campaign-stat">&nbsp;</span>
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
  <img src="http://placehold.it/350x240" data-src="<%=teacher.image_uid%>.jpg" data-width="350" data-height="240" data-crop="fill" data-gravity="faces"/>
  <% if (story.preview) { %>
  <blockquote><%= story.preview %></blockquote>
  <% } %>
  <div class="story-content">
    <h2 class="teacher-name"><%= teacher.first_name %> <%= teacher.last_name %></h2>
    <p class="story-meta">
      <%= school.name %><br>
      <% if (school.city) { %>
      <%= school.city %>,&nbsp;
      <% } %>
      <%= school.state %> <a href="/teach/stories#story/<%=id%>">read story &raquo;</a>
    </p>
  </div>
</script>
<script type="text/x-microtemplate" id="most_stories_list_template">
  <li data-schoolid="<%=external_id%>" data-state="<%=state%>">
    <%=school_name%><br>
    <% if (city) { %>
    <%=city%>,
    <% } %>
    <%=state%>
    </li>
</script>

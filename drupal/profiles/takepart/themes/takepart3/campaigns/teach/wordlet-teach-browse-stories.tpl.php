<div class="content teach-story-content teach-browse-stories-content">
  <h1 class="sys-headline"><span><?php print w('browse_stories_headline'); ?></span></h1>
  <div class="sys-intro-body"><?php print w('browse_stories_intro'); ?></div>
  <?php include('partials/teach-sys-cta.tpl.php'); ?>
  <section id="app" class="teach-app">
    <p style="text-align: center;">Loading&hellip;</p>
  </section>
  <section id="social-menu" class="social-menu">
  <?php include('partials/teach-social-block.tpl.php'); ?>
  </section>
</div>
<script type="text/x-template" id="app_view">
  <nav id="app-nav" class="app-nav">
    <a id="nav-featured" href="#featured">Editor&rsquo;s Picks</a>
    <a id="nav-popular" href="#popular">Most Popular</a>
    <a id="nav-recent" href="#recent">Most Recent</a>
    <a id="nav-school" href="#school">Find a School</a>
  </nav>
</script>
<script type="text/x-template" id="story_view">
  <img src="http://placehold.it/300x300&text=loading..." data-src="<%=teacher.image_uid%>.jpg" data-width="300" data-height="600" data-crop="fit" />
  <h2 class="teacher-name"><%= teacher.first_name %> <%= teacher.last_name %></h2>
  <p class="story-meta">
    <%= school.name %><br />
    <% if (school.city) { %>
    <%= school.city %>,&nbsp;
    <% } %>
    <%= school.state %>
  </p>
  <h3 class="story-title"><%= story.title %><h3>
</script>
<script type="text/x-template" id="load_more_stories_view">
<div class="load-more-stories"><a class="load-more-stories-button" href="#"><%= button_text %></a></div>
</script>
<script type="text/x-template" id="school_view">
  <?php include ('partials/teach-sys-browse-by-school.tpl.php'); ?>
</script>
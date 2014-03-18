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
  <p class="story-meta">
  <% if (story.preview !== '') { %>
    <%= story.preview %>
  <% } %>
  <a href="#">read more &raquo;</a>
  </p>
</script>
<script type="text/x-template" id="story_full_view">
  <h2 class="sys-story-headline"><span>Teacher Stories From <span class="teach-logo">Teach</span></span></h2>
  <div class="sys-story-teacher-image-wrapper">
    <img id="sys-story-teacher-image" class="sys-story-teacher-image" src="http://placehold.it/350x410&text=loading..." data-src="<%=teacher.image_uid%>.jpg" data-width="350" data-height="410" data-crop="fill" data-gravity="faces">
    <div id="story-social-share" class="scribble-share story-social-share"><span>Share This Story</span></div>
  </div>
  <div class="content">
    <h3>Teacher</h3>
    <h2 class="sys-story-subhead"><%=teacher.first_name%> <%=teacher.last_name%></h2>
    <div class="sys-story-user-image-wrapper"><img id="sys-story-user-image" class="sys-story-user-image" src="http://placehold.it/150x200&text=loading..." data-src="<%=image_uid%>.jpg" data-width="150" data-height="200" data-crop="fill" data-gravity="faces"></div>
    <h3>School</h3>
    <p>
      <%=school.name%><br />
      <%=school.city%>, 
      <%=school.state%><br />
      <%=story.year%>
    </p>
    <h3>Submitted By</h3>
    <p><%=first_name%> <%=last_name%></p>
    <% 
      var paragraphs = [];
      _.each(story.body.split(/\n+/g), function(paragraph) {
        paragraphs.push(paragraph.replace(/^\s+|\s+$/g, ''));
      });
    %>
    <p><%=paragraphs.join('</p><p>')%></p>
    <% 
      var tags = [];
      if (story.tags) {
        _.each(story.tags.split(/,\s?/g), function(tag) {
          tags.push('<a href="' + window.location.pathname + '#tag/' + encodeURIComponent(tag)  + '">' + tag + '</a>');
        });
      }
    %>
    <% if (story.tags && tags[0] !== "") { %>
    <h3>Tags</h3>
    <p id="story-tags"><%=tags.join(', ')%></p>
    <% } %>
  </div>
  <div class="orange-button-container"><a href="/teach/share-your-story">Add Your Teacher Story</a></p></div>
  <div id="story-comments" class="story-comments">
    <h3>Comments</h3>
    <div class="story-fb-like"><fb:like href="<%=window.location.href%>" layout="button" action="like" show_faces="false" share="false"></fb:like></div>
    <fb:comments href="<%=window.location.href%>" width="638" numposts="5" colorscheme="light"></fb:comments>
  </div>
</script>
<script type="text/x-template" id="stories_view">
<div class="view-messages"></div>
<div class="stories-wrapper"></div>
</script>
<script type="text/x-template" id="load_more_stories_view">
<div class="load-more-stories orange-button-container"><a class="load-more-stories-button" href="#"><%= button_text %></a></div>
</script>
<script type="text/x-template" id="school_view">
  <?php include ('partials/teach-sys-browse-by-school.tpl.php'); ?>
</script>
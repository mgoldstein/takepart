<div id="sys-form-content" class="content teach-story-content teach-sys-content">
    <div class="row">
        <div class="col-1-2">
            <div class="sys-intro">
                <h1 class="sys-headline"><span><?php print w('page_headline'); ?></span></h1>
                <div><?php print w('intro_body'); ?></div>
            </div>
            <?php include('partials/teach-sys-form.tpl.php'); ?>
        </div>
        <div class="col-1-2">
            <aside class="sys-tips">
        		<h2 class="sys-headline"><span><?php print w('update_count'); ?></span></h2>
                <section class="featured-stories" <?php print wa('sys_form_featured_stories'); ?>>
                    <?php foreach(wl('sys_form_featured_stories') as $w) : ?>
                    <article data-storyid="<?php print $w->single_no_markup; ?>" class="featured-story"></article>
                    <?php endforeach; ?>
                </section>
                <script type="text/x-microtemplate" id="featured_story_template">
                  <img src="http://placehold.it/350x240" data-src="<%=teacher.image_uid%>.jpg" data-width="350" data-height="240" data-crop="fill" data-gravity="faces"/>
                  <% if (story.preview) { %>
                  <blockquote><%= story.preview %></blockquote>
                  <% } %>
                  <div class="story-content">
                    <h2 class="teacher-name"><%= teacher.first_name %> <%= teacher.last_name %></h2>
                    <p class="story-meta">
                      <%= school.name %>,
                      <% if (school.city) { %>
                      <%= school.city %>,&nbsp;
                      <% } %>
                      <%= school.state %><br/>
                      Written by <%=first_name%> <%=last_name%> <a href="/teach/stories#story/<%=id%>">read story &raquo;</a>
                    </p>
                  </div>
                </script>
            </aside>
            <aside class="sys-tips">
                <h2 class="sys-headline"><span><?php print w('tips_headline'); ?></span></h2>
                <p><?php print w('tips_body'); ?></p>
            </aside>
        </div>
    </div>
</div>
<div id="sys-coppa-content" class="content teach-story-content teach-sys-content teach-sys-coppa-content initially-hidden">
    <h1 class="sys-headline"><span><?php print w('coppa_headline'); ?></span></h1>
    <?php print w('coppa_message'); ?>
</div>
<div id="sys-thanks-content" class="content teach-story-content teach-sys-content teach-sys-thanks-content initially-hidden">
    <h1 class="sys-headline"><span><?php print w('thanks_headline'); ?></span></h1>
    <div><?php print w('thanks_message'); ?></div>
    <?php include('partials/teach-sys-thanks.tpl.php'); ?>
</div>

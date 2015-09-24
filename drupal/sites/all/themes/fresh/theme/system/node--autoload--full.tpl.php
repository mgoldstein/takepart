<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
?>

<div class="fresh-content-wrapper">
  <?php
    $node_type = $variables['type'];
    $node_type = ($node_type == 'openpublish_article') ? 'article' : $node_type; ?>
  <div class = "<?php print $node_type ?>-wrapper clearfix">
  <?php if (!empty($variables['social'])): ?>
    <aside class="social social-vertical stick">
   <?php print $variables['social']; ?>
    </aside>
  <?php endif; ?>
  <article class="col-xs-10 col-xs-offset-1 clearfix <?php print $classes; ?>"<?php print $attributes; ?>>

    <?php if (!empty($variables['advertisement'])): ?>
      <div class="advertisement">
     <?php print $variables['advertisement']; ?>
      </div>
    <?php endif; ?>
    <div class="section">
   <?php if (!empty($variables['topic_box'])): ?>
     <?php print $variables['topic_box']; ?>
   <?php endif; ?>
   <?php print render($title_prefix); ?>
      <h1 class="title"><?php print $title; ?></h1>
   <?php print render($title_suffix); ?>
   <?php if (!empty($variables['headline'])): ?>
     <?php print $variables['headline']; ?>
   <?php endif; ?>
    </div>
    <div class="section">
   <?php if (!empty($variables['media'])): ?>
     <div class="row row-remove-xs">
    <?php print $variables['media']; ?>
     </div>
   <?php endif; ?>
    </div>
    <div class="section">
   <?php if (!empty($variables['sponsored'])): ?>
     <?php print $variables['sponsored']; ?>
   <?php endif; ?>
   <?php if (!empty($variables['author_teaser'])): ?>
     <div class="row">
    <?php print $variables['author_teaser']; ?>
     </div>
   <?php endif; ?>
   <?php if (!empty($variables['body'])): ?>
     <div class="main-content">
    <?php print $variables['body']; ?>
     </div>
   <?php endif; ?>
    </div>
    <?php if (!empty($variables['sponsor_disclosure'])): ?>
      <div class="sponsor-disclosure">
     <?php print $variables['sponsor_disclosure']; ?>
      </div>
    <?php endif; ?>
    <?php if (!empty($variables['series_navigation'])): ?>
      <div class="series-navigation-wrapper row">
     <?php print $variables['series_navigation']; ?>
      </div>
    <?php endif; ?>

    <?php if (!empty($variables['comments'])): ?>
   <?php if ($show_fb_comments): ?>
        <div class="comments"><a name="article-comments"></a>
    <?php print $variables['comments']; ?>
        </div>
   <?php endif; ?>
    <?php endif; ?>

    <?php if (!empty($variables['more_on_takepart'])): ?>
   <?php print $variables['more_on_takepart']; ?>
    <?php endif; ?>
  </article>
</div></div>

<?php if (!empty($variables['auto-scroll'])): ?>
  <?php print $variables['auto-scroll']; ?>
<?php endif; ?>
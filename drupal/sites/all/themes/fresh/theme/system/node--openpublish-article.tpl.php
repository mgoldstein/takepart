<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
?>

<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php if(!empty($variables['advertisement'])): ?>
    <div class="advertisement">
      <?php print $variables['advertisement']; ?>
    </div>
  <?php endif; ?>
  <div class="section col-xxs-12">
    <?php if(!empty($variables['topic_box'])): ?>
        <?php print $variables['topic_box']; ?>
    <?php endif; ?>
    <?php print render($title_prefix); ?>
    <h1><?php print $title; ?></h1>
    <?php print render($title_suffix); ?>
    <?php if(!empty($variables['headline'])): ?>
        <?php print $variables['headline']; ?>
    <?php endif; ?>
  </div>
  <div class="section">
    <?php if(!empty($variables['media'])): ?>
      <div class="row">
        <?php print $variables['media']; ?>
      </div>
    <?php endif; ?>
    <div class="section col-xxs-12">
    <?php if(!empty($variables['sponsored'])): ?>
        <?php print $variables['sponsored']; ?>
    <?php endif; ?>
    <?php if(!empty($variables['author_teaser'])): ?>
      <div class="row">
        <?php print $variables['author_teaser']; ?>
      </div>
    <?php endif; ?>
    <?php if(!empty($variables['body'])): ?>
      <div class="main-content">
        <?php print $variables['body']; ?>
      </div>
    <?php endif; ?>
  </div>
  <?php if(!empty($variables['sponsor_disclosure'])): ?>
    <div class="sponsor-disclosure">
      <?php print $variables['sponsor_disclosure']; ?>
    </div>
  <?php endif; ?>
  <?php if(!empty($variables['article_nav'])): ?>
    <div class="article-navigation">
      <?php print $variables['article_nav']; ?>
    </div>
  <?php endif; ?>
  <?php if(!empty($variables['comments'])): ?>
    <div class="comments">
      <?php print $variables['comments']; ?>
    </div>
  <?php endif; ?>
<?php if (!empty($pre_object)) print render($pre_object) ?>

<div class='<?php print $classes ?> clearfix' <?php print ($attributes) ?>>
  <?php if (!empty($title_prefix)) print render($title_prefix); ?>

  <?php // dprint_r($node); ?>
  
  <?php print render($content['field_display_tag']); ?>

  <?php if (!empty($title)): ?>
    <h2 <?php if (!empty($title_attributes)) print $title_attributes ?>>
      <?php if (!empty($new)): ?><span class='new'><?php print $new ?></span><?php endif; ?>
      <a href="<?php print $node_url ?>"><?php print $title ?></a>
    </h2>
  <?php endif; ?>

  <?php if (!empty($title_suffix)) print render($title_suffix); ?>

  <?php if (!empty($content)): ?>
    <div class='content clearfix <?php if (!empty($is_prose)) print 'prose' ?>'>
      
      <?php print render($content['field_article_subhead']); ?>
      
      <?php if (!empty($submitted)): ?>
      <div class='submitted-wrapper'>
        <div class='submitted clearfix'>
          <?php print render($content['field_author']); ?>
          <div class='field article-date'><?php print $date; ?></div>
          <div class='field article-comment-count'>
            <a href='#comments'>
              <?php print $node->comment_count; ?> comments
            </a>
          </div>
        </div>
      </div>
      <?php endif; ?>
      
    <?php print render($content['body']); ?>
    
    </div>
  <?php endif; ?>

  <?php if (!empty($links)): ?>
    <div class='links clearfix'>
      <?php print render($links) ?>
    </div>
  <?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object) ?>

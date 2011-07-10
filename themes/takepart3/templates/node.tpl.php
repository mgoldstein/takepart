<?php if (!empty($pre_object)) print render($pre_object) ?>

<div class='<?php print $classes ?> clearfix' <?php print ($attributes) ?>>
  <?php if (!empty($title_prefix)) print render($title_prefix); ?>
  
  
  <?php
    if(isset($content['field_display_tag']) & ($view_mode == 'full')){
      print render($content['field_display_tag']);
    }
  ?>
  
  <?php if (!empty($title)): ?>
    <h2 <?php if (!empty($title_attributes)) print $title_attributes ?> class='title'>
      <?php if (!empty($new)): ?><span class='new'><?php print $new ?></span><?php endif; ?>
      <a href="<?php print $node_url ?>"><?php print $title ?></a>
    </h2>
  <?php endif; ?>

  <?php if (!empty($title_suffix)) print render($title_suffix); ?>
  
  <?php 
    // Defined in template.php for consistancy
    if(isset($content['subhead'])){
      print '<div class="node-subhead">' . render($content['subhead']) . '</div>';
    }
  ?>

  <?php if (!empty($submitted)): ?>
    <?php print $submitted ?>
  <?php endif; ?>

  <?php if (!empty($content)): ?>
    <?php hide($content['subhead']); ?>
    <?php hide($content['field_free_tag']); ?>
    <?php hide($content['field_topic']); ?>
    <?php hide($content['field_article_action']); ?>
    <?php hide($content['body']); ?>
    
    <div class='content content-top clearfix <?php if (!empty($is_prose)) print 'prose' ?>'>
      <?php print render($content); ?>
    </div>
    
    <div class='content content-bottom clearfix <?php if (!empty($is_prose)) print 'prose' ?>'>
      <?php print render($content['body']); ?>
    </div>
    
  <?php endif; ?>
  
  <?php if( !empty($sidebar_first) && $view_mode == 'full'): // Print the sidebar region within the content ?>
    <div id="left" class="clearfix">
      <?php print render($sidebar_first); ?>
    </div>
  <?php endif; ?>
  
  <?php if( (isset($content['field_free_tag']['#items']) || isset($content['field_topic']['#items']) ) & ($view_mode == 'full')) : ?>
      <?php show($content['field_free_tag']); ?>
      <?php show($content['field_topic']); ?>
      <?php print _render_tp3_taxonomy_links($content); ?>
  <?php endif; ?>

  <?php if (!empty($links)): ?>
    <div class='links clearfix'>
      <?php print render($links) ?>
    </div>
  <?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object) ?>

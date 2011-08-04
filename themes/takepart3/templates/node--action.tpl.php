<?php if (!empty($pre_object)) print render($pre_object) ?>

<div class='<?php print $classes ?> clearfix' <?php print ($attributes) ?>>
  <?php if (!empty($title_prefix)) print render($title_prefix); ?>
  
  <?php if (!empty($title)): ?>
    <h2 <?php if (!empty($title_attributes)) print $title_attributes ?> class='title'>
      <?php if (!empty($new)): ?><span class='new'><?php print $new ?></span><?php endif; ?>
      <a href="<?php print $node_url ?>"><?php print $title ?></a>
    </h2>
  <?php endif; ?>

  <?php if (!empty($title_suffix)) print render($title_suffix); ?>

  <?php if (!empty($submitted)): ?>
    <?php //print $submitted ?>
  <?php endif; ?>

  <?php if (!empty($content)): ?>
    
    <?php hide($content['comments']); ?>
    
    <div class='content content-bottom clearfix <?php if (!empty($is_prose)) print 'prose' ?>'>
      
      <?php if($view_mode == 'teaser'): ?>
        <?php hide($content['field_free_tag']); ?>
        <?php hide($content['field_topic']); ?>
        <?php hide($content['body']); ?>
      <?php endif; ?>
      
      <?php print render($content); ?>
      
      <?php if($view_mode == 'teaser'): ?>
        <?php show($content['field_topic']); ?>
        <?php print takepart3_addthis_button(); ?>    
        <?php print render($content['body']); ?>
        <?php print render($content['field_topic']); ?>
      <?php endif; ?>
      
      <form id='take-action'>
        <input id='take-action-btn' type='button' value='Take Action'>
      </form>
      
    </div>
    
  <?php endif; ?>

  <?php if (!empty($links)): ?>
    <div class='links clearfix'>
      <?php //print render($links) ?>
    </div>
  <?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object) ?>

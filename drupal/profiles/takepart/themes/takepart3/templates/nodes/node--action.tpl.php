<?php if (!empty($pre_object)) print render($pre_object) ?>
<div class='action <?php print $classes ?> clearfix' <?php print ($attributes) ?>>
  <?php if (!empty($title_prefix)) print render($title_prefix); ?>
  <?php if (!empty($title) && !($remove_title)): ?>
  <h1 <?php if (!empty($title_attributes)) print $title_attributes ?> class='title'>
    <?php if (!empty($new)): ?><span class='new'><?php print $new ?></span><?php endif; ?>
    <a href="<?php print $node_url ?>"><?php print $title ?></a>
  </h1>
  <?php endif; ?>
  <?php if (!empty($title_suffix)) print render($title_suffix); ?>
  <?php if (!empty($content)): ?>
    <?php hide($content['comments']); ?>
    <div class='content content-bottom clearfix <?php if (!empty($is_prose)) print 'prose' ?>'>
      <?php if ($view_mode == 'teaser'): ?>
        <?php hide($content['field_free_tag']); ?>
        <?php hide($content['field_topic']); ?>
        <?php hide($content['body']); ?>
      <?php endif; ?>
      <div id="action_copy">
      <?php print render($content); ?>
      </div>
      <div id="action_alt_copy">
      <?php
        if (function_exists('media_filter')) { //Alternate Content
          print media_filter($content['body']['#object']->field_altcontent['und'][0]['value']);
        }
        else {
          print ($content['body']['#object']->field_altcontent['und'][0]['value']);
        }
      ?>
      </div>
      <?php if ($view_mode == 'teaser'): ?>
        <?php show($content['field_topic']); ?>
        <?php print render($content['body']); ?>
        <?php print render($content['field_topic']); ?>
      <?php endif; ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($links)): ?>
    <div class='links clearfix'>
    <?php // print render($links) ?>
    </div>
  <?php endif; ?>
</div>
<?php if (!empty($post_object)) print render($post_object) ?>

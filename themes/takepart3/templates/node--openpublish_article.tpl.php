<?php
 // print render(block_get_blocks_by_region('content_left'));
?>

<?php if (!empty($pre_object)) print render($pre_object) ?>

<div class='<?php print $classes ?> clearfix' <?php print ($attributes) ?>>
  <?php if (!empty($title_prefix)) print render($title_prefix); ?>
  
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
      
      <?php // dprint_r($content); ?>
      
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
        
        <?php print render($content['field_article_main_image']); ?>

        <?php print render($content['body']); ?>
        
        <div class='secondary-content-col'>
          
          <ul class='social-media'>
            <li class='social-media-digg'>Digg This</li>
            <li class='social-media-stumble'>Stumble This</li>
            <li class='social-media-email'>Email a friend</li>
          </ul>
          
          <?php print render(block_get_blocks_by_region('content_left'));?>
          
          <!--
          <div class="block-boxes-view-name-similar_campaigns">
            <h2>Similar Campaigns</h2>
            
          <div class="views-row views-row-1 views-row-odd views-row-first">

            <div class="views-field views-field-field-promo-headline">
              <div class="field-content">
                <a href="/article/2011/05/26/del-taco-mac-n-cheese-crunch-bites">Promo headline ipsum dolor sit amet</a>
              </div>
            </div>

          <div class="views-row views-row-2 views-row-even views-row-last">

            <div class="views-field views-field-field-promo-headline">
              <div class="field-content">
                <a href="/article/2011/05/26/del-taco-mac-n-cheese-crunch-bites">Promo headline ipsum dolor sit amet</a>
              </div>
            </div>
            
          </div>
          
          </div>
          
        </div>
        
        -->
          
        </div>
      
    </div>
  <?php endif; ?>

  <?php if (!empty($links)): ?>
    <div class='links clearfix'>
      <?php print render($links) ?>
    </div>
  <?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object) ?>

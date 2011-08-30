<div class='main-content clearfix <?php print $classes ?> clearfix' <?php print ($attributes) ?>>
  <div id='author_info'>
   
    <?php if (!empty($node->field_profile_photo)): ?>
      <div class='author-bio-photo'>
      <?php
        print theme_image_formatter(
            array('item' => $node->field_profile_photo['und'][0],
              'image_style' => 'thumbnail'
              )
          );
      ?>
      </div>
    <?php endif; ?>
     <?php if (!empty($title)): ?>
      <h2><?php print $title ?></h2>
    <?php endif; ?>
    <?php if (!empty($node->field_profile_job_title)): ?>
      <h3><?php print $node->field_profile_job_title['und'][0]['safe_value'] ?></h3>
    <?php endif; ?>
    <?php if (!empty($node->field_author_links)): ?>
      <div class='author-links social-links wireframe'><?php print takepart3_dolinks($node->field_author_links['und']);?></div>
    <?php endif; ?>
    <?php if (!empty($node->body)): ?>
      <div class='auhor-bio wireframe'><?php print $node->body['und'][0]['safe_value'] ?></div>
    <?php endif; ?>
  </div>
  <div id='author-contributions'>
    <h2>Contributions</h2>
    <?php print views_embed_view('author_contributions', 'page', array($node->nid)); ?>
  </div>
</div>
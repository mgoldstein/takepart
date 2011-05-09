<div class='wireframe <?php print $classes ?> clearfix' <?php print ($attributes) ?>>
  <div id='author_info'>
    <?php if (!empty($title)): ?>
      <h2><?php print $title ?></h2>
      <h3><?php print $node->field_profile_job_title['und'][0]['safe_value'] ?></h3>
      <div class='author-links social-links wireframe'><?php print takepart3_dolinks($node->field_author_links['und']);?></div>
      <div class='auhor-bio wireframe'><?php print $node->body['und'][0]['safe_value'] ?></div>
    <?php endif; ?>
  </div>
  <div id='author-contributions'>
    <h2>Contributions</h2>
    <?php print $node->nid; ?><br/>
    <?php print views_embed_view('contributions', 'page', array($node->nid)); ?>
  </div>
</div>
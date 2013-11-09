<?php
/**
 * @file
 * Returns the HTML for a full openpublish_article node.
 *
 */
?>
<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php if ($title_prefix || $title_suffix || $unpublished || $title): ?>
    <header class="article-header">
      <?php print render($content['field_topic_box']); ?>
      <?php print render($title_prefix); ?>
      <?php if ($title): ?>
	<h1<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>

      <? print render($content['field_article_subhead']); ?>

      <?php if ($unpublished): ?>
	<mark class="unpublished"><?php print t('Unpublished'); ?></mark>
      <?php endif; ?>
    </header>
  <?php endif; ?>

    <aside id="article-social" class="social"><div class="inner">
      <h3 class="tp-social-headline">Take Action</h3>
      <h3 class="tp-social-headline">Share</h3>
      <div class="tp-social" id="article-share"></div>
      <p id="article-comments-link" class="comments-link">
        <a href="#article-comments"><?php print t('Comments'); ?><span class="count"></span></a>
      </p>
      <div id="article-social-more">
    	<h4 class="trigger"><a href="#article-more-shares">More</a></h4>
    	<div id="article-more-shares">
    	  <h5 class="header"><?php print t('Share with your friends'); ?></h5>
  	  <p></p>
	</div>
      </div>
    </div></aside>

  <div id="article-content">

    <?php if ($main_image_image) : ?>
    <figure class="article-main-image">
      <?php print $main_image_image; ?>
      <?php if ($main_image_caption) : ?>
      <figcaption>
	<?php print $main_image_caption; ?>
      </figcaption>
      <?php endif; ?>
    </figure>
    <?php endif; ?>

    <div class="author-bio">
      <?php print render($content['field_author']); ?>
      <?php ?>
    </div>

  <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    print render($content);
  ?>

  </div>



</article>

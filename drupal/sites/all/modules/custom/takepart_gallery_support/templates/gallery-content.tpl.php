<?php
/**
 * @file
 * Template for Takepart Photo Gallery Content
 */
?>
<article id="node-<?php print $node->nid; ?>" class="gallery-content">
  <header id="gallery-header">
    <?php if (isset($field_topic_box_top)) : ?>
    <div class="topic-box">
      <?php print $field_topic_box_top; ?>
    </div>
    <?php endif; ?>
    <h1 class="gallery-headline"><?php print $gallery_title; ?></h1>
    <?php print render($gallery_subhead); ?>
    <div class="author">
      <date class="publish-date" datetime="<?php print date('c', $node->created); ?>"><?php print date('F d, Y',$node->created) ?></date>
      <span class="byline author">By <?php print $gallery_authors; ?></span>
    </div>
    <aside id="gallery-content-social" class="social">
      <h3 class="headline"><?=t('Share Photo') ?></h3>
      <div class="tp-social" id="gallery-cover-share"></div>
    </aside>
  </header>

  <ul id="slides">
    <?php foreach($slides as $delta => $slide) : ?>
    <li<?php print drupal_attributes($slide['attributes']) ?>>
      <figure>
        <div class="slide-image-wrapper">
          <?php print $slide['image']; ?>
        </div>
        <figcaption class="slide-caption">
          <h2 class="slide-caption-headline"><?php print $slide['title']; ?></h2>
          <div class="slide-caption-content"><?php print $slide['caption']; ?></div>
        </figcaption>
      </figure>
    </li>
    <?php endforeach; ?>
  </ul>
  <?php kpr($slides_temp); ?>
</article>
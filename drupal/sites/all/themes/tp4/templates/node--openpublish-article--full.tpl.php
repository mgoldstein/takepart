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
      <?php if (isset($field_topic_box_top)) : ?>
      <div class="topic-box">
	<?php print $field_topic_box_top; ?>
      </div>
      <?php endif; ?>
      <?php print render($title_prefix); ?>
      <?php if ($title): ?>
	<h1<?php print $title_attributes; ?>><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>

      <? print render($content['field_article_subhead']); ?>

      <?php if ($unpublished): ?>
	<mark class="unpublished"><?php print t('Unpublished'); ?></mark>
      <?php endif; ?>
    </header>
  <?php endif; ?>

    <aside id="article-social" class="social"><div class="inner">
      <div id="article-tab">
	<h3 class="tp-social-headline take-action-headline">Take Action</h3>
	<p class="takepart-take-action"></p>
      </div><!--
      --><h3 class="tp-social-headline share-headline">Share</h3>
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
    </div></aside><!-- / #article-social -->


  <div id="article-content">

  <?php if (!empty($content['field_video'])) {
    print render($content['field_video']);
  }
  else {
    print render($content['field_article_main_image']);
  } ?>
  <?php print render($content['field_author']); ?>

  <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    hide($content['field_related_stories']);
    hide($content['field_topic']);
    hide($content['field_free_tag']);
    print render($content);
  ?>
  </div>

  <?php if (isset($series_nav)) : ?>
  <nav id="series-navigation">
  <div class="left-border"></div><div class="right-border"></div>
    <?php print $series_nav; ?>
  </nav>
  <?php endif; ?>

  <footer id="article-footer">
    <h3>Related Stories on TakePart</h3>
    <?php print render($content['field_related_stories']); ?>
    <h3>Get More</h3>
    <ul class="topic-links links inline">
      <?php print render($content['field_topic']); ?>
      <?php print render($content['field_free_tag']); ?>
    </ul>

    <div class="OUTBRAIN" data-src="<?php print $url_production; ?>" data-widget-id="TR_1" data-ob-template="TakePart" ></div>
    <script type="text/javascript" async="async" src="http://widgets.outbrain.com/outbrain.js"></script>


    <h3 class="top-border">Takepart&#8217;s Most Popular</h3>
    <div id='taboola-bottom-main-column-mix'></div>
    <script type="text/javascript">
      window._taboola = window._taboola || [];
      _taboola.push({mode:'thumbs-1r-organic', container:'taboola-bottom-main-column-mix', placement:'bottom-main-column', target_type:'mix'});
    </script>



    <h3>From The Web</h3>
    <div id='taboola-below-main-column'></div>
    <script type="text/javascript">
    window._taboola = window._taboola || [];
    _taboola.push({mode:'thumbs-1r', container:'taboola-below-main-column', placement:'below-main-column'});
    </script>


    <?php print render($on_our_radar); ?>
  </footer>

  <div id="article-comments">
    <h3 class="top-border">Comments <span>(<fb:comments-count href="<?php print $url_local; ?>"></fb:comments-count>)</span></h3>
    <fb:comments href="<?php print $url_local; ?>" numposts="15"></fb:comments>
  </div>
</article>

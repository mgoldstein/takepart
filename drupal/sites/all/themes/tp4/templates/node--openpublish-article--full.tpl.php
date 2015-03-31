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

            <?php print render($content['field_article_subhead']); ?>

            <?php if ($unpublished): ?>
                <mark class="unpublished"><?php print t('Unpublished'); ?></mark>
            <?php endif; ?>
        </header>
    <?php endif; ?>

      <aside class="social social-vertical stick">
        <?php
        $social_elements = array('action', 'share', 'subscribe', 'facebook', 'overlay');
        $options = array('comments' => TRUE, 'overlay' => TRUE);
        print theme('tp_social_menu', array('elements' => $social_elements, 'options' => $options));
        ?>
      </aside><!-- / #article-social -->


    <div id="article-content">

        <?php
        if (!empty($content['field_video'])) {
            print render($content['field_video']);
        } else {
            print render($content['field_article_main_image']);
        }
        ?>

        <?php if (isset($content['field_video_list'])): ?>
            <?php print render($content['field_video_list']); ?>
        <?php endif; ?>

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

		<?php if ($show_fb_comments): ?>
			<div id="article-comments">
					<h3 class="top-border">Comments <span>(<fb:comments-count href="<?php print $url_local; ?>"></fb:comments-count>)</span></h3>
					<fb:comments href="<?php print $url_local; ?>" numposts="15"></fb:comments>
			</div>
		<?php endif; ?>
</article>

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
            <?php if (isset($variables['topic_box_top'])) : ?>
                <div class="topic-box">
                    <?php print $variables['topic_box_top']; ?>
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
				$social_elements = array(
						'share',
						'action' => array(
								'data-desktop-pos' => '0',
						),
						'overlay'
				);
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

    <footer id="article-footer">
        <h3>Related Stories on TakePart</h3>
        <?php print render($content['field_related_stories']); ?>
        <h3>Get More</h3>
        <ul class="topic-links links inline">
            <?php print render($content['field_topic']); ?>
            <?php print render($content['field_free_tag']); ?>
        </ul>



        <h3 class="top-border"><?php print t('Takepart&#8217;s Most Popular'); ?></h3>

        <div id="taboola-below-article-thumbnails"></div>
        <script type="text/javascript">
            window._taboola = window._taboola || [];
            _taboola.push(
                    {mode: 'organic-thumbnails-a', container: 'taboola-below-article-thumbnails', placement: 'Below Article Thumbnails', target_type: 'mix'}
            );
        </script>

        <!--
        <div id='taboola-bottom-main-column-mix'></div>
        <script type="text/javascript">
            window._taboola = window._taboola || [];
            _taboola.push({mode: 'thumbs-1r-organic', container: 'taboola-bottom-main-column-mix', placement: 'bottom-main-column', target_type: 'mix'});
        </script>
        -->

        <h3><?php print t('From The Web'); ?></h3>
        <div id="taboola-below-article-thumbnails-2nd"></div>
        <script type="text/javascript">
            window._taboola = window._taboola || [];
            _taboola.push(
                    {mode: 'thumbnails-a', container: 'taboola-below-article-thumbnails-2nd', placement: 'Below Article Thumbnails 2nd', target_type: 'mix'}
            );
        </script>

        <!--
        <div id='taboola-below-main-column'></div>
        <script type="text/javascript">
        window._taboola = window._taboola || [];
        _taboola.push({mode:'thumbs-1r', container:'taboola-below-main-column', placement:'below-main-column'});
        </script>
        -->

        <?php print render($on_our_radar); ?>
    </footer>

		<?php if ($show_fb_comments): ?>
			<div id="article-comments">
					<h3 class="top-border">Comments <span>(<fb:comments-count href="<?php print $url_local; ?>"></fb:comments-count>)</span></h3>
					<fb:comments href="<?php print $url_local; ?>" numposts="15"></fb:comments>
			</div>
		<?php endif; ?>
</article>

<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
?>
<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <header class="article-header">
        <?php print render($title_prefix); ?>
        <div class="flashcard-branding"><a href="/flashcards"><span>fl</span>ashcards</a></div>
        <?php print render($content['field_flashcard_page_headline']); ?>
        <?php print render($content['field_article_subhead']); ?>
        <?php print render($title_suffix); ?>

		<?php print isset($variables['content']['sponsored']) ? $variables['content']['sponsored'] : ''; ?>

        <?php if ($unpublished): ?>
            <mark class="unpublished"><?php print t('Unpublished'); ?></mark>
        <?php endif; ?>
    </header>

    <aside class="social social-vertical stick">
      <?php
        $social_elements = array(
            'share',
            'action' => array(
                'data-desktop-pos' => '0',
            ),
            'overlay'
        );
        $options = array('overlay' => TRUE);
        print theme('tp_social_menu', array('elements' => $social_elements, 'options' => $options));
      ?>
    </aside><!-- / #article-social -->

    <?php
    hide($content['comments']);
    hide($content['links']);
    hide($content['body']);
    print render($content);

    show($content['body']);
    print render($content['body']);
    ?>

	<?php print isset($variables['content']['sponsor_disclaimer']) ? $variables['content']['sponsor_disclaimer'] : ''; ?>

</article>

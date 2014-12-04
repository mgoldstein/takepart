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

        <?php if ($unpublished): ?>
            <mark class="unpublished"><?php print t('Unpublished'); ?></mark>
        <?php endif; ?>
    </header>

    <aside id="article-social" class="social">
        <div class="inner">
            <div id="article-tab">
                <h3 class="tp-social-headline take-action-headline">Take Action</h3>
                <p class="takepart-take-action"></p>
            </div>
            <div class="tp-sharing-container">
                <h3 class="tp-social-headline share-headline">Share</h3>
                <div class="tp-social" id="article-share"></div>
                <p id="article-comments-link" class="comments-link">
                    <a href="#article-comments"><?php print t('Comments'); ?><span class="count"></span></a>
                </p>
                <!-- <div id="article-social-more">
                    <h4 class="trigger"><a href="#article-more-shares">More</a></h4>
                    <div id="article-more-shares">
                        <h5 class="header"><?php print t('Share with your friends'); ?></h5>
                        <p></p>
                    </div>
                </div> -->
            </div>
            <div class="tap-influence-overlay"></div>
        </div>
    </aside><!-- / #article-social -->

    <?php
    hide($content['comments']);
    hide($content['links']);
    hide($content['body']);
    print render($content);

    show($content['body']);
    print render($content['body']);
    ?>

</article>

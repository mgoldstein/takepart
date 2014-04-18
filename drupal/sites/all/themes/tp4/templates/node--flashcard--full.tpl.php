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
    <div class="flashcard-branding"><a href="#"><img alt="TakePart Flashcards" src="http://placehold.it/1000x75&text=Flashcard+Branding"></a></div>
    <?php print render($content['field_flashcard_page_headline']); ?>
    <?php print render($content['field_article_subhead']); ?>
    <?php print render($title_suffix); ?>

    <?php if ($unpublished): ?>
      <mark class="unpublished"><?php print t('Unpublished'); ?></mark>
    <?php endif; ?>
  </header>

  <?php
    hide($content['comments']);
    hide($content['links']);
    hide($content['body']);
    print render($content);

    show($content['body']);
    print render($content['body']);
  ?>

</article>

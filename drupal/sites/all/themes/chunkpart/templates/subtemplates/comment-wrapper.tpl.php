<?php
/**
 * @file
 * Default theme implementation to provide an HTML container for comments.
 *
 * Available variables:
 * - $content: The array of content-related elements for the node. Use
 *   render($content) to print them all, or
 *   print a subset such as render($content['comment_form']).
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default value has the following:
 *   - comment-wrapper: The current template type, i.e., "theming hook".
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * The following variables are provided for contextual information.
 * - $node: Node object the comments are attached to.
 * The constants below the variables show the possible values and should be
 * used for comparison.
 * - $display_mode
 *   - COMMENT_MODE_FLAT
 *   - COMMENT_MODE_THREADED
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess_comment_wrapper()
 * @see theme_comment_wrapper()
 */
?>
<section class="<?=$classes ?>"<?=$attributes ?>>
  <? if ($content['#fb_comments']['enabled']): ?>
    <?=render($title_prefix) ?>
    <div class="fb_comments"></div>
    <script class="fb_comments_template" type="text/x-javascript-template">
      <div class='comments-header'>
        <h3 class="header">
          <?=$content['comments_title'] ?>
          <span class='comment-count'><fb:comments-count href="<?=$content['#fb_comments']['url'] ?>"></fb:comments-count></span>
        </h3>
      </div>
      <?=render($title_suffix) ?>
      <fb:comments href="<?=$content['#fb_comments']['url'] ?>"
        num_posts="<?=$content['#fb_comments']['amount'] ?>"
        width="<?=$content['#fb_comments']['width'] ?>"
        mobile="<?=$content['#fb_comments']['mobile'] ?>"
        colorscheme="<?=$content['#fb_comments']['style'] ?>"></fb:comments>
    </script>
  <? else: ?>
    <? if ($content['#node']->comment_count > 0): ?>
      <?=render($title_prefix) ?>
      <h3 class="header">
        <?=$content['comments_title'] ?>
        <span class='comment-count'><?=$content['#node']->comment_count ?></span>
      </h3>
      <?=render($title_suffix) ?>
      <?=render(array_reverse($content['comments'])) ?>
    <? endif ?>
  <? endif ?>
</section>

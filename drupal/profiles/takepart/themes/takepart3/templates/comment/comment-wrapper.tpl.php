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
<div id="comments" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>
  <div class='comments-header'>
    <h2 class="title"><?php print t('Comments'); ?></h2>
    <?php if ($content['#fb_comments']['enabled']): ?>
      <span class='comment-count'><fb:comments-count href="<?php print $content['#fb_comments']['url'] ?>"></fb:comments-count></span>
    <?php else: ?>
      <span class='comment-count'><?php print $content['#node']->comment_count; ?></span>
    <?php endif; ?>
  </div>
  <?php print render($title_suffix); ?>
   
  <?php if ($content['#fb_comments']['enabled']): ?>
    
    <div id="fb-root"></div>
    <script>
      (function(d, s, id) {
        var js, fjs = d.getElementsByTagName(s)[0];
        if (d.getElementById(id)) {return;}
        js = d.createElement(s); js.id = id;
        js.src = "//connect.facebook.net/en_US/all.js#xfbml=1";
        fjs.parentNode.insertBefore(js, fjs);
    }(document, "script", "facebook-jssdk"));
    </script>
    <div class="fb-comments"
         data-href="<?php print $content['#fb_comments']['url'] ?>"
         data-num-posts="<?php print $content['#fb_comments']['amount'] ?>"
         data-width="<?php print $content['#fb_comments']['width'] ?>"
         data-colorscheme="<?php print $content['#fb_comments']['style'] ?>"></div>

  <?php else: ?>

    <?php 
      $comments = array_reverse($content['comments']);
      print render($comments);
    ?>

  <?php endif; ?>
</div>

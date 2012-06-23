<?php
// node template to display embedded video on page
?>

<?php if (!empty($pre_object)) print render($pre_object) ?>
<div class='<?php print $classes ?> clearfix node-embedded' <?php print ($attributes) ?>>
  <?php print $content['thumbnail_image'] ?>
</div>
<?php if (!empty($post_object)) print render($post_object) ?>

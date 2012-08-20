<?php
/**
 * @file
 * Badge Image user generated badge form template.
 *
 * $heading
 * $instructions
 * $form
 * $image_src
 * $css_prefix
 */
?>
<div class="badge-image-generator <?php print $css_prefix; ?>-generator">
<h2 class="badge-image-heading <?php print $css_prefix; ?>-heading"><?php print $heading; ?></h2>
<div class="badge-image-instructions <?php print $css_prefix; ?>-instructions"><?php print $instructions; ?></div>
<?php print render($form) ?>
<img class="badge-image-preview <?php print $css_prefix; ?>-preview"
     src="<?php print $image_src; ?>" />
</div>

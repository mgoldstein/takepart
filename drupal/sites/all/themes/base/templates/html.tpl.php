<?php
/**
 * @file
 * Returns the HTML for the basic html structure of a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728208
 */
?>
<!DOCTYPE html>
<html <?php print $html_attributes; ?> prefix="og: http://ogp.me/ns# fb: http://ogp.me/ns/fb#">
<head>
  <title><?php print $head_title; ?></title>
  <?php if (!empty($tp_digital_data)): ?>
  <script type="text/javascript">
    window.digitalData = <?php print $tp_digital_data ?>;
  </script>
  <?php endif; ?>
  <?php print $head; ?>
  <?php if ($default_mobile_metatags): ?>
  <meta name="MobileOptimized" content="320">
  <meta name="HandheldFriendly" content="true">
<!--  <meta name="viewport" content="width=device-width">-->
  <meta name="viewport" content="width=device-width, height=device-height, initial-scale=1.0, user-scalable=0, minimum-scale=1.0, maximum-scale=1.0">
  <?php endif; ?>
  <meta http-equiv="cleartype" content="on">
  <?php print $styles; ?>
  <?php print $scripts; ?>
  <script src="<?php print variable_get('digital_data_wrapper_js'); ?>"></script>
  <script src="<?php print variable_get('centralized_login_widget_js'); ?>"></script>
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <?php if ($skip_link_text && $skip_link_anchor): ?>
    <p id="skip-link">
      <a href="#<?php print $skip_link_anchor; ?>" class="element-invisible element-focusable"><?php print $skip_link_text; ?></a>
    </p>
  <?php endif; ?>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>

</body>
</html>

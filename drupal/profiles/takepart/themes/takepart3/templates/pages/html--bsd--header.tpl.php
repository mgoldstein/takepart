<?php
/**
 * @file
 * Render TakePart header for inclusion in BSD wrappers.
 */
?>

<?php print $styles; ?>
<?php print $scripts; ?>


<!--[if IE]>
<?php
drupal_add_css(drupal_get_path('theme', 'takepart3') . '/css/bsd_wrappers_ie.css');
?>
<![endif]-->

<div id="page-wrapper">
<?php print $custom; ?>

<div id='page' class='page clearfix'>
<div class='main-content'>
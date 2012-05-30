<?php
/**
 * @file
 * Render TakePart header for inclusion in BSD wrappers.
 */
?>

<?php print $styles; ?>
<?php print $scripts; ?>
<!--[if IE]>
<style type="test/css" media="all">
#join-login-top {
text-align: right;
display: block;
width: 200px;
}
</style>
<![endif]-->

<div id="page-wrapper">
<?php print $custom; ?>

<div id='page' class='page clearfix'>
<div class='main-content'>
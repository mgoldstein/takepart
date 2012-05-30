<?php
/**
 * @file
 * Render TakePart header for inclusion in BSD wrappers.
 */
?>

<?php print $styles; ?>
<?php print $scripts; ?>


<!--[if IE]>
<style type="text/css" media="all">@import url("http://alpha.takepart.com/profiles/takepart/themes/takepart3/css/bsd_wrappers_ie.css");</style>
<![endif]-->

<div id="page-wrapper">
<?php print $custom; ?>

<div id='page' class='page clearfix'>
<div class='main-content'>
<?php
/**
 * @file
 * Render TakePart header for inclusion in BSD wrappers.
 */
?>

<div id="page-wrapper">
<?php print $styles; ?>
<?php print $scripts; ?>
<style type="text/css">
@font-face {
    font-family: 'NewsGothicBoldCondensed';
    src: url('http://www.takepart.com/profiles/takepart/themes/takepart3/includes/news-2-webfont.woff') format('woff'),
         url('http://www.takepart.com/profiles/takepart/themes/takepart3/includes/ufonts.com_trade-gothic-lt-com-bold-condensed-no.-20.ttf') format('truetype'),
         url('http://www.takepart.com/profiles/takepart/themes/takepart3/includes/news-2-webfont.svg#NewsGothicBoldCondensed') format('svg'),
         url("http://www.takepart.com/profiles/takepart/themes/takepart3/includes/news-2-webfont.eot") /* EOT file for IE */;
    font-weight: normal;
    font-style: normal;
}    
</style>
<?php print $custom; ?>

<div id='page' class='page clearfix'>
<div class='main-content'>
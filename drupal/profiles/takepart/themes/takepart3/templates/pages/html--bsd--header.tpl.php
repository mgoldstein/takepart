<?php
/**
 * @file
 * Render TakePart header for inclusion in BSD wrappers.
 */
?>

<div id="page-wrapper">
<?php print $styles; ?>
<style type="text/css">
@font-face {
    font-family: 'NewsGothicBoldCondensed';
    src: url("http://www.takepart.com/profiles/takepart/themes/takepart3/css/webfonts/news-2-webfont.eot"); /* EOT file for IE9 */
    src: url("http://www.takepart.com/profiles/takepart/themes/takepart3/css/webfonts/news-2-webfont.eot") format('embedded-opentype'), /* IE6-8 */
         url('http://www.takepart.com/profiles/takepart/themes/takepart3/css/webfonts/news-2-webfont.woff') format('woff'), /* Modern broswers */
         url('http://www.takepart.com/profiles/takepart/themes/takepart3/css/webfonts/news-2-webfont.ttf') format('truetype'), /* Safari, Android, iOS */
         url('http://www.takepart.com/profiles/takepart/themes/takepart3/css/webfonts/news-2-webfont.svg#NewsGothicBoldCondensed') format('svg'); /* legacy iOS */
    font-weight: normal;
    font-style: normal;
}    
</style>
<?php print $scripts; ?>
<?php print $custom; ?>

<div id='page' class='page clearfix'>
<div class='main-content'>
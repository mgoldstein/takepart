<?php
/**
 * @file
 * Render TakePart header for inclusion in BSD wrappers.
 */
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.0//EN"
    "http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" version="XHTML+RDFa 1.0" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?> >
     <head profile="<?php print $grddl_profile; ?>">
        <?php print $head; ?>
        <meta property="fb:admins" content="1327833247" />
        <meta property="fb:app_id" content="247137505296280" />
        <title>News &amp; Lifestyle Coverage on Important Topics Like Food, Environment, Social Justice, Animal Rights, Education &amp; Health | TakePart </title>
        <?php print $styles; ?>
        <?php print $scripts; ?>
    </head>
    <body class="<?php print $classes; ?>" <?php print $attributes; ?>>
        <div id="page-wrapper">
            <?php print $custom; ?>

            <div id='page' class='page clearfix'>
                <div class='main-content'>
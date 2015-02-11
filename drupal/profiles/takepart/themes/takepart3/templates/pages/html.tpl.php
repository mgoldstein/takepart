<?php
/**
 * @file
 * Default theme implementation to display the basic html structure of a single
 * Drupal page.
 *
 * Variables:
 * - $css: An array of CSS files for the current page.
 * - $language: (object) The language the site is being displayed in.
 *   $language->language contains its textual representation.
 *   $language->dir contains the language direction. It will either be 'ltr' or 'rtl'.
 * - $rdf_namespaces: All the RDF namespace prefixes used in the HTML document.
 * - $grddl_profile: A GRDDL profile allowing agents to extract the RDF data.
 * - $head_title: A modified version of the page title, for use in the TITLE
 *   tag.
 * - $head_title_array: (array) An associative array containing the string parts
 *   that were used to generate the $head_title variable, already prepared to be
 *   output as TITLE tag. The key/value pairs may contain one or more of the
 *   following, depending on conditions:
 *   - title: The title of the current page, if any.
 *   - name: The name of the site.
 *   - slogan: The slogan of the site, if any, and if there is no title.
 * - $head: Markup for the HEAD section (including meta tags, keyword tags, and
 *   so on).
 * - $styles: Style tags necessary to import all CSS files for the page.
 * - $scripts: Script tags necessary to load the JavaScript files and settings
 *   for the page.
 * - $page_top: Initial markup from any modules that have altered the
 *   page. This variable should always be output first, before all other dynamic
 *   content.
 * - $page: The rendered page content.
 * - $page_bottom: Final closing markup from any modules that have altered the
 *   page. This variable should always be output last, after all other dynamic
 *   content.
 * - $classes String of classes that can be used to style contextually through
 *   CSS.
 *
 * @see template_preprocess()
 * @see template_preprocess_html()
 * @see template_process()
 */

?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.0//EN"
    "//www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd">
<html xmlns="//www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" version="XHTML+RDFa 1.0" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?> >
<head profile="<?php print $grddl_profile; ?>">
  <title><?php print $head_title; ?></title>
  <?php if (!empty($tp_digital_data)): ?>
  <script type="text/javascript">
    window.digitalData = <?php print $tp_digital_data ?>;
  </script>
  <?php endif; ?>

        <?php print $head; ?>
        <?php if ( $is_iframed ): ?>
            <base href="<?php print '//' . $_SERVER['HTTP_HOST']; ?>" target="_parent" />
        <?php endif ?>
        <meta name="viewport" content="width=device-width">
        <?php print $styles; ?>
        <!--[if lt IE 9]>
            <script src="/sites/all/themes/takepart_core/js/html5shiv.js"></script>
        <![endif]-->
        <?php print $scripts; ?>
        <?php if ( $is_iframed ): ?>
            <script type="text/javascript">
                jQuery( document ).ready(function() {
                    jQuery('a.join-login').attr('href', function(i, val) {
                        return val + '?destination=' + document.referrer
                    });
                });
            </script>
        <?php endif ?>
    </head>
    <body class="<?php print $classes; ?>" <?php print $attributes; ?>>
        <?php if ( !$is_iframed ): ?>
            <div id="skip-link">
                <a href="#page" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
            </div>
        <?php endif ?>
        <?php
        if (isset($page_top)):
            echo $page_top;
        endif;
        ?>
        <?php
        if (isset($page)):
            echo $page;
        endif;
        ?>
        <?php
        if (isset($custom)):
            echo $custom;
        endif;
        ?>
        <?php
        if (isset($page_bottom)):
            echo $page_bottom;
        endif;
        ?>
        <?php
        if (isset($tp_sysinfo_comment_tags)):
            echo $tp_sysinfo_comment_tags;
        endif;
        ?>
    </body>
</html>

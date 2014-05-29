<?php
/**
 * @file panels-pane.tpl.php
 * Main panel pane template
 *
 * Variables available:
 * - $pane->type: the content type inside this pane
 * - $pane->subtype: The subtype, if applicable. If a view it will be the
 *   view name; if a node it will be the nid, etc.
 * - $title: The title of the content
 * - $content: The actual content
 * - $links: Any links associated with the content
 * - $more: An optional 'more' link (destination only)
 * - $admin_links: Administrative links associated with the content
 * - $feeds: Any feed icons or associated with the content
 * - $display: The complete panels display object containing all kinds of
 *   data including the contexts and all of the other panes being displayed.
 */
$headline = !empty($content['#node']->field_promo_headline) ? $content['#node']->field_promo_headline['und'][0]['safe_value'] : $title;
?>
<?php if ($pane_prefix): ?>
  <?php print $pane_prefix; ?>
<?php endif; ?>
<div class="<?php print $classes; ?>" <?php print $id; ?>>
  <?php if ($admin_links): ?>
    <?php print $admin_links; ?>
  <?php endif; ?>

    <header class="entry-header">
      <?php if (!empty($variables['content']['field_video'])) {
        print render($variables['content']['field_video']);
      }
      else {
        print render($variables['content']['field_thumbnail']);
      } ?>
      <?php print render($title_prefix); ?>
      <?php 
        if ($headline) {
          if (!empty($title_link)) {
            $title_heading = '<a href="' . $title_link . '">' . $headline . '</a>';
          }
          else {
            $title_heading = $headline;
          }
        print '<h2' . $title_attributes . '>' . $title_heading . '</h2>';
        } 
      ?>
      <?php print render($title_suffix); ?>
      <?php if ($unpublished): ?>
        <mark class="unpublished"><?php print t('Unpublished'); ?></mark>
      <?php endif; ?>
    </header>

    <?php
      hide($variables['content']['comments']);
      hide($variables['content']['links']);
      $tab_title_override = variable_get('main_feature_tab_title_override', NULL);
      if($tab_title_override != NULL){
        $variables['content']['field_tab_action_override'][0]['#title'] = $tab_title_override;
      }
      
      if (!empty($title_link)) {
        $variables['content']['field_article_subhead'][0]['#markup'] .= ' <a id="mf-more-link" href="' . $title_link . '">more</a>';
      }
      //dd($variables['content']['field_article_subhead']);
    ?>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($variables['content']['comments']);
      hide($variables['content']['links']);
      print render($variables['content']['field_author']);
      print render($variables['content']);
    ?>
</div>

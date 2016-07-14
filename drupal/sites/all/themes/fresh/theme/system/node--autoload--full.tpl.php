<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
?>

  <?php
    $node_type = $variables['type'];
    $node_type = ($node_type == 'openpublish_article') ? 'article' : $node_type;
    $autoloaded = ($variables['autoscroll_load']) ? TRUE : FALSE;
    //cic determins whether the current article(1 or autoloaded) is tagged with a campaign
    $cic = (!empty($variables['campaign_info']['nid'])) ? ' cic' : '';
  ?>
  <div class = "<?php print $node_type;?>-wrapper fresh-content-wrapper clearfix<?php print ($autoloaded) ? ' autoloaded' : ' first'; print $cic . ' ';?>">
  <?php if (!empty($variables['social'])): ?>
    <aside class="social social-vertical stick">
   <?php print $variables['social']; ?>
    </aside>
  <?php endif; ?>
  <?php if (!empty($variables['advertisement'])): ?>
    <div class="advertisement">
      <?php print $variables['advertisement']; ?>
    </div>
  <?php endif; ?>
  <?php
  //Campaign banner is ONLY displayed for the first node tagged with a campaign for the in-campaign experience.
  //On regular auto-load experience, banner will be added to ALL autoloaded nodes tagged with a campaign.
    if (!empty($variables['campaign_info']['banner'])): ?>
    <div class = "campaign-ref-wrapper" style="background-image: url('<?php print $variables['campaign_info']['banner']; ?>')">
      <?php if (!empty($variables['campaign_info']['logo'])): ?>
        <div class = "campaign-logo">
          <img src="<?php print $variables['campaign_info']['logo']; ?>">
        </div>
      <?php endif; ?>
      <?php if (!empty($variables['campaign_info']['vol'])): ?>
        <h4 class = "campaign-vol">TAKEPART BIG ISSUE <span>vol. <?php print $variables['campaign_info']['vol']; ?></span></h4>
      <?php endif; ?>
    </div>
  <?php endif; ?>

  <div class="fresh-inner-content-wrapper clearfix">
    <article class="col-xs-10 col-xs-offset-1 clearfix <?php print $classes; ?>"<?php print $attributes; ?>>

      <div class="section">
     <?php if (!empty($variables['topic_box'])): ?>
       <?php print $variables['topic_box']; ?>
     <?php endif; ?>
     <?php print render($title_prefix); ?>
        <h1 class="title"><?php print $title; ?></h1>
     <?php print render($title_suffix); ?>
     <?php if (!empty($variables['headline'])): ?>
       <?php print $variables['headline']; ?>
     <?php endif; ?>
      </div>
      <div class="section">
        <div class = "align-sticky"></div>
     <?php if (!empty($variables['media'])): ?>
       <div class="row row-remove-xs">
      <?php print $variables['media']; ?>
       </div>
     <?php endif; ?>
      </div>
      <div class="section">
     <?php if (!empty($variables['sponsored'])): ?>
       <?php print $variables['sponsored']; ?>
     <?php endif; ?>
     <?php if (!empty($variables['author_teaser'])): ?>
       <div class="row">
      <?php print $variables['author_teaser']; ?>
       </div>
     <?php endif; ?>
     <?php if (!empty($variables['body'])): ?>
       <div class="main-content">
      <?php print $variables['body']; ?>
       </div>
     <?php endif; ?>
      </div>
      <?php if (!empty($variables['sponsor_disclosure'])): ?>
        <div class="sponsor-disclosure">
       <?php print $variables['sponsor_disclosure']; ?>
        </div>
      <?php endif; ?>
      <?php if (!empty($variables['series_navigation'])): ?>
        <div class="series-navigation-wrapper row">
       <?php print $variables['series_navigation']; ?>
        </div>
      <?php endif; ?>

      <?php if (!empty($variables['comments'])): ?>
     <?php if ($show_fb_comments): ?>
          <div class="comments"><a name="article-comments"></a>
      <?php print $variables['comments']; ?>
          </div>
     <?php endif; ?>
      <?php endif; ?>

    </article>
  </div>
  <?php if (!empty($variables['more_on_takepart'])): ?>
    <?php print $variables['more_on_takepart']; ?>
  <?php endif; ?>
</div>

<?php if (!empty($variables['auto-scroll'])): ?>
  <?php print $variables['auto-scroll']; ?>
<?php endif; ?>

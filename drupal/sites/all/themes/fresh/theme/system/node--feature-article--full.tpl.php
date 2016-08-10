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
    $cic = (!empty($variables['campaign_info']['nid'])) ? ' cic' : '';
    $autoloaded = ($variables['autoscroll_load']) ? TRUE : FALSE;
  ?>

<div class = "<?php print $node_type;?>-wrapper fresh-content-wrapper clearfix<?php print ($autoloaded) ? ' autoloaded' : ' first'; print $cic . ' ';?>">
  <?php if (!empty($variables['social'])): ?>
    <aside class="social social-vertical stick">
   <?php print $variables['social']; ?>
    </aside>
  <?php endif; ?>

  <?php //Campaign banner is displayed only if its not autoloaded.
  if ($cic && !empty($variables['campaign_info']['banner']) && !$autoloaded): ?>
    <div class = "campaign-ref-wrapper" style="background-image: url('<?php print $variables['campaign_info']['banner'];?>')">
      <?php if (!empty($variables['campaign_info']['logo'])): ?>
        <div class = "campaign-logo">
          <a href="<?php print $variables['campaign_info']['url']; ?>">
            <img src="<?php print $variables['campaign_info']['logo']; ?>">
          </a>
        </div>
      <?php endif; ?>
      <?php if (!empty($variables['campaign_info']['vol'])): ?>
        <div class = "big-issue">
          <a href ="http://www.takepart.com/big-issues">TAKEPART'S BIG ISSUE </a><span class="campaign-vol">vol. <?php print $variables['campaign_info']['vol']; ?></span>
        </div>
      <?php endif; ?>
    </div>
  <?php endif; ?>
  <div class="fresh-inner-content-wrapper clearfix">
    <article class="col-xs-10 col-xs-offset-1 clearfix <?php print $classes; ?>"<?php print $attributes; ?>>
      <div class="section header full-width">
       <div class="row row-remove-xs">
          <header class="article-header">
            <?php if (!empty($variables['media'])): ?>
            <?php print $variables['media']; ?>
            <div class = "title-block">
              <?php if (!empty($variables['field_article_featured_link'])): ?>
                <?php print $variables['field_article_featured_link']; ?>
              <?php endif; ?>
              <?php print render($title_prefix); ?>
              <h1 class="title"><?php print $title; ?></h1>
              <?php print render($title_suffix); ?>
              <?php if (!empty($variables['headline'])): ?>
                <?php print $variables['headline']; ?>
              <?php endif; ?>
            </div>
        <?php endif; ?>
          </header>
        </div>
      </div>
      <div class="section top">
        <?php if ($cic && $autoloaded): ?>
          <div class = "feature-campaign-ref">
            <?php if(!empty($variables['campaign_info']['dark_logo'])): ?>
              <div class="campaign-dark-logo">
                <img src="<?php print $variables['campaign_info']['dark_logo']; ?>">
              </div>
            <?php endif; ?>
            <?php if (!empty($variables['campaign_info']['vol'])): ?>
              <div class = "big-issue">
                <a href ="http://www.takepart.com/big-issues">TAKEPART'S BIG ISSUE </a><span class="campaign-vol">vol. <?php print $variables['campaign_info']['vol']; ?></span>
              </div>
            <?php endif; ?>
          </div>
        <?php endif ?>
        <?php if (!empty($variables['topic_box'])): ?>
          <?php print $variables['topic_box']; ?>
        <?php endif; ?>
        <?php if (!empty($variables['author_teaser'])): ?>
          <div class="row">
            <?php print $variables['author_teaser']; ?>
          </div>
        <?php endif; ?>
        <?php if (!empty($variables['sponsored'])): ?>
          <?php print $variables['sponsored']; ?>
        <?php endif; ?>
      </div>
    <div class="section main-content">
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

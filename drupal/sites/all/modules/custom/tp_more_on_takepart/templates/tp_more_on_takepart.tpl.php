<div id="more-on-takepart" class="clearfix">
  <h2><?php print t('More on TakePart'); ?></h2>
  <div class="row">
    <?php foreach($variables['related'] as $v) { print $v; } ?>

    <?php foreach($variables['promoted'] as $v) { print $v; } ?>

    <?php print $variables['taboola']; ?>
  </div>
</div>

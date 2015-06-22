<div id="more-on-takepart" class="clearfix row">
  <h2 class="tp-more__title"><?php print t('More on TakePart'); ?></h2>
<?php if ($variables['promoted_video']) : ?>
    <div class="col-md-6">
      <div class="row">

<?php endif; ?>
    <?php foreach($variables['related'] as $v) { print $v; } ?>

    <?php foreach($variables['promoted'] as $v) { print $v; } ?>

    <?php print $variables['taboola']; ?>

<?php if ($variables['promoted_video']) : ?>
      </div>
    </div>

  <?php print $variables['promoted_video']; ?>

<?php endif; ?>

</div>

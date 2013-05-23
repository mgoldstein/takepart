<?php
  $id = $variables['ncid'];
  $body_wrapper_id = "takepart-newsletter-{$id}-body";
  $form_wrapper_id = "wrapper-form-{$id}";
  $result_wrapper_id = "takepart-newsletter-{$id}-results";
?>
<div class="takepart-newsletter-wrapper">
  <div id="<?= $body_wrapper_id ?>">
    <div class="takepart-newsletter-promo-text">
      <?php echo $variables['body'] ?>
    </div>
    <div class="takepart-newsletter-form">
      <div id="<?= $form_wrapper_id ?>">
        <?php echo drupal_render($variables['form']); ?>
      </div>
    </div>
    <div class="takepart-newsletter-terms">
      <?php echo drupal_render($variables['tos_link']); ?>
    </div>
  </div>
  <div id="<?= $result_wrapper_id ?>" class="takepart-newsletter-message">
  </div>
</div>

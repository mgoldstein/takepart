<?php
  /**
   *  Variables defined in takeart_newsletter_signup.module
   *
   *  $promo_text - promotional text
   *  $signup_form - the rendered form html  
   *  $form_id - for ajax purposes
   */
 
?>
<div class="takepart-newsletter-embed-wrapper">
  <div id="takepart-newsletter-embed-<?php print $form_id; ?>-body">
    <div class="takepart-newsletter-embed-promo-text">
      <?php print $promo_text; ?>
    </div>
    <div class="takepart-newsletter-embed-form">
      <div id="wrapper-form-<?php print $form_id; ?>">
        <?php print drupal_render($signup_form); ?>
      </div>
    </div>
  </div>
  <div class="takepart-newsletter-embed-terms"><?php
    print l(t("Terms & Conditions"), "terms-of-use",
      array('attributes'=>array('target'=>'_blank')));
    ?></div>
  <div id="takepart-newsletter-embed-<?php print $form_id; ?>-results" class="takepart-newsletter-embed-message"></div>
</div>
  <div class="tp-pet-progress-block">
  <div class="tp-pet-progress-image">
    <img src="/profiles/takepart/modules/takepart_petition/images/Water_Logo_300x160.png" />
  </div>
  <div class="tp-pet-progress-info">
    <div class="tp-pet-progress-count">
    <span id="tp_signatures_to_date">Signatures to Date: <?php print number_format($variables['signature_count']) ?></span>
    </div>
    <img id="tp_signatures_bar" src="<?php print $variables['progress_bar_url'] ?>" />
    <div class="tp-pet-progress-count">
    <span>Signature Goal: <?php print number_format($variables['goal']) ?></span>
    </div>
    <div class="tp-pet-progress-count">
    <span id="tp_signatures_percent">PROGRESS: <?php print number_format($variables['percent_to_goal'], 1) ?>%</span>
    </div>
  </div>
  </div>

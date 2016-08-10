<div class = "sticky-cic-header" style=" background-image: url('<?php print $camp_banner; ?>')">
  <div class = "campaign-info-wrapper" style="background-color:<?php print $camp_bg_color; ?>">
    <div class="toggle-menu toggle-left"></div>
      <div class = "campaign-info">
        <a href="<?php print $camp_url; ?>">
          <img src="<?php print $camp_logo; ?>">
        </a>
        <div class = "big-issue">
          <?php print l(t("TAKEPART'S BIG ISSUE"), "big-issues"); ?> <span class="volume">vol. <?php print $camp_vol; ?></span>
        </div>
      </div>
    </div>
</div>

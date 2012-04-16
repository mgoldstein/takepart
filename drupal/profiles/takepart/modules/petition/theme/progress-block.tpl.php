<?php
/**
 * $bar - The path the thermometer bar image for the progress percentage
 * $percent - The progress percentage
 * $decimals - The number of decimal places to show for the progress percentage
 * $count - The number of signatures on the petition
 * $goal - The signature goal for the petition
 *
 */
?>
<div class="petition-progress-block">
  <img class="petition-progress-bar" src="<?php print $bar; ?>"
     alt="<?php print number_format($percent, $decimals); ?>% COMPLETE"/>
  <p class="petition-progress-count">
    <?php print number_format($count); ?> of <?php print number_format($goal); ?> signatures
  </p>
  <p class="petition-progress-complete">
    <span class="petition-progress-percent"><?php print number_format($percent, $decimals); ?>%</span> COMPLETE
  </p>
</div>

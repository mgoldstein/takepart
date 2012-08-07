<?php
/**
 * $id - The id of the progress summary block
 * $bar - The path to the progress bar image for the progress percentage
 * $complete_classes - List of additional classes for the progress percentage
 *   paragragh.
 * $percent - The progress percentage
 * $count_classes - List of additional classes for the progress count paragraph.
 * $progress - Progress message
 * $count - The number of signatures
 * $goal - The signature goal
 * $days_left - The number of days left until signature collection ends
 * $state - The signature collection state
 */
?>
<div class="signature-progress" id="<?php print $summary_id; ?>">
  <p class="signature-progress-complete <?php print $complete_classes?>">
    <span class="signature-progress-percent"><?php print $percent; ?>%</span> Complete
  </p>
  <img class="signature-progress-bar" src="<?php print $bar; ?>"
       alt="<?php print $percent; ?>% Complete"/>
  <p class="signature-progress-count <?php print $count_classes?>"><?php print render($progress); ?></p>
</div>

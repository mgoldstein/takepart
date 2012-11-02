<?php
/**
 * @file
 * Thank You block template.
 */

/**
 * Variables
 *
 * $action_taken - Action take message.
 * $progress_percent - Signature' progress percentage
 * $progress_needed - Signature's needed message.
 * $share_bar - AddThis small icon share bar.
 */
?>
<div class="<?php print $classes; ?>">
<?php render($thankyou_heading); ?>
<?php render($action_taken); ?>
<div class="progress">
<?php render($progress_percent); ?>
<?php render($progress_needed); ?>
</div>
<div class="sharing">
<?php render($share_heading); ?>
<?php render($share_bar); ?>
</div>
</div>

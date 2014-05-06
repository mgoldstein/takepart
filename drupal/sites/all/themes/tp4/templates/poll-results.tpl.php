<?php
/**
 * @file
 * Default theme implementation to display the poll results in a block.
 *
 * Variables available:
 * - $title: The title of the poll.
 * - $results: The results of the poll.
 * - $votes: The total results in the poll.
 * - $links: Links in the poll.
 * - $nid: The nid of the poll
 * - $cancel_form: A form to cancel the user's vote, if allowed.
 * - $raw_links: The raw array of links.
 * - $vote: The choice number of the current user's vote.
 *
 * @see template_preprocess_poll_results()
 *
 * @ingroup themeable
 */
?>

  <ul class="meters">
    <?php print $results; ?>
  </ul>
  <div class="hidden">
    <label class="total">Total votes: </label>
    <span class="value"><?php print t('@votes', array('@votes' => $votes)); ?></span>
  </div>
    
  <?php if (!empty($cancel_form)): ?>
    <?php print $cancel_form; ?>
  <?php endif; ?>

<?php if (!empty($cta)): ?>
    <?php print $cta; ?>
  <?php endif; ?>
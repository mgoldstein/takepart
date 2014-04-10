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
<div class="poll">
  <h3>what do you think?</h3>
  <div class="question"><?php print $title ?></div>
  <ul class="meters">
    <?php print $results; ?>
  </ul>
  <label class="total">Total votes: </label>
  <span class="value"><?php print t('@votes', array('@votes' => $votes)); ?></span>
  
  <?php if (!empty($cancel_form)): ?>
    <?php print $cancel_form; ?>
  <?php endif; ?>
</div>
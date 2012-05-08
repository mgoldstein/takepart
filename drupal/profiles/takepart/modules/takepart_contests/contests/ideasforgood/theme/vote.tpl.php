<?php
/**
 * @file
 * Theme implementation for Ideas for Good Contest Voting Dialog
 *
 * Variables
 * - $ideasforgood_finalist: the finalist entity
 * - $content: contains the fields on the finalist entity
 */
?>
<p>Do you want to confirm your vote for
  <?php print render($content['ideasforgood_finalist_first_name']); ?>
  <?php print render($content['ideasforgood_finalist_last_name']); ?>
</p>
<?php print render($content['vote_form']); ?>
<img src="/<?php print $content['cancel_button']; ?>" alt="Cancel" class="ideasforgood-cancel-button">

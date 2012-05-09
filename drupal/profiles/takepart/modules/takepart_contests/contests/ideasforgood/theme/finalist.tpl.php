<?php
/**
 * @file
 * Theme implementation for Ideas for Good Contest Finalists
 *
 * Variables
 * - $ideasforgood_finalist: the finalist entity
 * - $content: contains the fields on the finalist entity and the voting_dialog
 */
?>
<div id="ideasforgood-finalist-<?php print $ideasforgood_finalist->id; ?>"
     class="ideasforgood-finalist-item">
  <?php print render($content['ideasforgood_finalist_image']); ?>
  <div class="ideasforgood-finalist-label-bg"></div>
  <div class="ideasforgood-finalist-label-text">
    <?php print render($content['ideasforgood_finalist_first_name']); ?>
    <?php print render($content['ideasforgood_finalist_idea_title']); ?>
  </div>
  <div id="ideasforgood-finalist-<?php print $ideasforgood_finalist->id; ?>-idea"
       class="ideasforgood-finalist-idea">
    <?php print render($content['ideasforgood_finalist_idea_body']); ?>
    <img src="/<?php print $content['vote_for_me_button']['off']; ?>" class="ideasforgood-vote-button rollover-image-off" alt="Vote for Me!">
    <img src="/<?php print $content['vote_for_me_button']['on']; ?>" class="rollover-image-on">
  </div>
  <div id="ideasforgood-finalist-<?php print $ideasforgood_finalist->id; ?>-dialog"
       class="ideasforgood-finalist-dialog">
    <div id="ideasforgood-finalist-<?php print $ideasforgood_finalist->id; ?>-dialog-body">
      <?php print render($content['voting_dialog']); ?>
    </div>
  </div>
</div>

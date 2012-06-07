<?php
/**
 * @file
 * Theme implementation for Ideas for Good Contest Finalists
 *
 * Variables
 * - $ideasforgood_finalist: the finalist entity
 * - $content: contains the following
 *     ideasforgood_finalist_image: the finalist entity image field
 *     ideasforgood_finalist_first_name: the finalist entity first name field
 *     ideasforgood_finalist_last_name: the finalist entity last name field
 *     ideasforgood_finalist_idea_title: the finalist entity idea title field
 *     ideasforgood_finalist_idea_body: the finalist entity idea body field
 * - $ideasforgood_finalist_image: the image field values
 * - $ideasforgood_finalist_first_name: the first name field values
 * - $ideasforgood_finalist_last_name: the last name field values
 * - $ideasforgood_finalist_idea_title: the idea title field values
 * - $ideasforgood_finalist_idea_body: the idea body field values
 *
 * Additional $content values
 *   vote_for_me_buttton: the src attribute for both the on and off 'Vote for
 *     Me' button images, keyed by image state
 *   voting_dialog_title: the title of the voting dialog
 *   voting_dialog: the content of the voting dialog
 */
?>
<div id="ideasforgood-finalist-<?php print $ideasforgood_finalist->id; ?>"
     class="ideasforgood-finalist-item">
  <?php print render($content['ideasforgood_finalist_image']); ?>
  <div class="ideasforgood-finalist-label-bg"></div>
  <div class="ideasforgood-finalist-label-text">
    <div class="ideasforgood-finalist-full-name">
    <?php print render($content['ideasforgood_finalist_first_name']); ?>
    <?php print render($content['ideasforgood_finalist_last_name']); ?>
    </div>
    <?php print render($content['ideasforgood_finalist_idea_title']); ?>
  </div>
  <div id="ideasforgood-finalist-<?php print $ideasforgood_finalist->id; ?>-idea"
       class="ideasforgood-finalist-idea">
    <?php print render($content['ideasforgood_finalist_idea_body']); ?>
    <img src="/<?php print $content['vote_for_me_button']['off']; ?>"
         class="ideasforgood-vote-button rollover-image-off" alt="Vote for Me!">
    <img src="/<?php print $content['vote_for_me_button']['on']; ?>"
         class="rollover-image-on">
    <div style="clear: both"></div>
  </div>
  <div id="ideasforgood-finalist-<?php print $ideasforgood_finalist->id; ?>-dialog"
       class="ideasforgood-finalist-dialog"
       title="<?php print $content['voting_dialog_title']; ?>">
    <div id="ideasforgood-finalist-<?php print $ideasforgood_finalist->id; ?>-dialog-body">
      <?php print render($content['voting_dialog']); ?>
    </div>
  </div>
</div>

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
<div id="ideasforgood-finalist-<?php print $ideasforgood_finalist->id; ?>">
  <div class="ideasforgood-finalist-item">
    <?php print render($content['ideasforgood_finalist_image']); ?>
    <div class="ideasforgood-finalist-label">
      <span class="ideasforgood-finalist-name"><?php print render($content['ideasforgood_finalist_first_name']); ?></span>
      <span class="ideasforgood-finalist-title"><?php print render($content['ideasforgood_finalist_idea_title']); ?></span>
    </div>
    <div id="ideasforgood-finalist-<?php print $ideasforgood_finalist->id; ?>-idea">
      <?php print render($content['ideasforgood_finalist_idea_body']); ?>
      <img src="/<?php print $content['vote_for_me_button']['off']; ?>" class="rollover-image-off" alt="Vote for Me!">
      <img src="/<?php print $content['vote_for_me_button']['on']; ?>" class="rollover-image-on">
    </div>
    <div id="ideasforgood-finalist-<?php print $ideasforgood_finalist->id; ?>-dialog">
      <div id="ideasforgood-finalist-<?php print $ideasforgood_finalist->id; ?>-dialog-body">
        <?php print render($content['voting_dialog']); ?>
      </div>
    </div>
  </div>
</div>

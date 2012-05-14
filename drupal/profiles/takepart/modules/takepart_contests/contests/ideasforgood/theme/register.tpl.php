<?php
/**
 * @file
 * Theme implementation for Ideas for Good Contest Voting Dialog
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
 *   register_message: the thank you message to display to the user
 *   destination: the page to load after registration/login is complete
 *   connect_button: the src attribute for the Facebook Connect button
 *   cancel_button: the src attribute for the cancel button
 */
?>
<?php print render($content['voting_group']['ideasforgood_group_register']); ?>
<div class="ideasforgood-register-buttons">
  <div>
    <a href="/user?destination=<?php print $content['destination']; ?>"><img src="/<?php print $content['connect_button']; ?>" alt="Connect with Facebook"></a>
  </div>
  <div>
    <img src="/<?php print $content['cancel_button']; ?>" alt="Cancel" class="ideasforgood-cancel-button">
  </div>
</div>

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
 *   thankyou_message: the thank you message to display to the user
 *   facebook_button: the src attribute for the Facebook share button
 *   twitter_button: the src attribute for the Twitter share button
 *   email_button: the src attribute for the Email share button
 */
?>
<?php
  if ($ideasforgood_finalist->vote_accepted) {
    print render($content['voting_group']['ideasforgood_group_thank_you']);
  }
  else {
    print render($content['voting_group']['ideasforgood_group_already_voted']);
  }
?>
<?php if ($ideasforgood_finalist->vote_accepted): ?>
<div class="ideasforgood-centered-content">
<div id="ideasforgood-share-facebook"
     class="addthis_toolbox addthis_default_style addthis_32x32_style">
  <a class="addthis_button_facebook"><img src="/<?php print $content['facebook_button']; ?>" alt="Share on Facebook" /></a>
</div>
<div id="ideasforgood-share-twitter"
     class="addthis_toolbox addthis_default_style addthis_32x32_style">
  <a class="addthis_button_twitter"><img src="/<?php print $content['twitter_button']; ?>" alt="Share on Twitter" /></a>
</div>
<div id="ideasforgood-share-email"
     class="addthis_toolbox addthis_default_style addthis_32x32_style">
  <a class="addthis_button_email"><img src="/<?php print $content['email_button']; ?>" alt="Share by E-mail" /></a>
</div>
</div>
<?php endif ?>


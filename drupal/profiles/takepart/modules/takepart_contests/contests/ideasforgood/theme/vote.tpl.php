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
 *   vote_form: the form for casting a vote for a finalist
 */
?>
<?php print render($content['vote_form']); ?>

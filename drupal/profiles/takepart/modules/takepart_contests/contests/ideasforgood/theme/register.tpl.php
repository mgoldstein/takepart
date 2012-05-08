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
<p>In order to vote for you must be a registered member with TakePart.com. Click
  the Connect with Facebook button to join TakePart with no obligation.
</p>
<p>Or, if you already have an account with TakePart.com, click the Connect with
  Facebook button to log in.
</p>
<a href="/user?destination=<?php print $_GET['q']; ?>"><img src="/<?php print $content['connect_button']; ?>" alt="Connect with Facebook"></a>
<a href="#" class="ideasforgood-cancel-button"><img src="/<?php print $content['cancel_button']; ?>" alt="Cancel"></a>

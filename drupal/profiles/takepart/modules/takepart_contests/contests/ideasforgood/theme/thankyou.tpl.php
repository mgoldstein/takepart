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
<div id="ideasforgood-share-bar" class="addthis_toolbox addthis_default_style addthis_32x32_style">
  <a class="addthis_button_facebook"><img src="/<?php print $content['facebook_button']; ?>" alt="Share on Facebook" /></a>
  <a class="addthis_button_twitter"><img src="/<?php print $content['twitter_button']; ?>" alt="Share on Twitter" /></a>
  <a class="addthis_button_email"><img src="/<?php print $content['email_button']; ?>" alt="Share by E-mail" /></a>
</div>

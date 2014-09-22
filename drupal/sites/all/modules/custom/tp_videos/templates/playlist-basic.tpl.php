<?php
/**
 * Template for the Playlist BASIC View Mode
 */
?>
<div class="playlist" data-playlist-type="basic">
  <div class="video">
    <?php print render($playlist_player); ?>
  </div>
  <?php print render($navigation); ?>
</div>

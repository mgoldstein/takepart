<?php
  $iframe = w('game_iframe')->single;
  $browser = browscap_get_browser();
?>
<?php if($browser['ismobiledevice'] == 'true'): ?>
    <?php drupal_goto($iframe); ?>
<?php else: ?>
  <div class="game">
    <iframe src="<?php print w('game_iframe')->single; ?>"></iframe>
  </div>
<?php endif; ?>

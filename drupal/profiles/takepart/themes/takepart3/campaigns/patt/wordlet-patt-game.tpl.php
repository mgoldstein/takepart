<?php
  $iframe = w('game_iframe')->single(false);
  if (!empty($_GET['cmpid'])) {
    $iframe = url($iframe, array(
      'query' => array('cmpid' => $_GET['cmpid'],),
    ));
  }
  $browser = browscap_get_browser();
?>
<?php if($browser['ismobiledevice'] == 'true'): ?>
    <?php drupal_goto($iframe); ?>
<?php else: ?>
  <div class="game" <?=wa('game_iframe')?>>
    <iframe src="<?php print $iframe; ?>"></iframe>
  </div>
<?php endif; ?>

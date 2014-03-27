<?php
  $iframe = w('game_iframe')->single(false);
  if (!empty($_GET['cmpid'])) {
    $iframe = url($iframe, array(
      'query' => array('cmpid' => $_GET['cmpid'],),
    ));
  }
  $browser = browscap_get_browser();
?>
<div class="game" <?=wa('game_iframe')?>>
  <iframe src="<?php print $iframe; ?>"></iframe>
</div>

<script language=javascript>
<!--
if ((navigator.userAgent.match(/iPhone/i)) || (navigator.userAgent.match(/iPod/i) || (navigator.userAgent.match(/Android/i))) {
   location.replace("<?=wa('game_iframe')?>");
}
-->
</script>
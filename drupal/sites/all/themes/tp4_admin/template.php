<?php

function tp4_admin_js_alter(&$javascript) {

  /* Update our version of jQuery to 1.7 */
  $jquery_path = 'https://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js';
  $javascript['misc/jquery.js']['data'] = $jquery_path;
  $javascript['misc/jquery.js']['type'] = 'external';
  unset($javascript['sites/all/libraries/colorbox/colorbox/jquery.colorbox-min.js']);
  unset($javascript['sites/all/modules/contrib/colorbox/js/colorbox.js']);
  unset($javascript['sites/all/modules/contrib/colorbox/styles/default/colorbox_default_style.js']);
  unset($javascript['sites/all/modules/contrib/colorbox/js/colorbox_load.js']);
  unset($javascript['sites/all/modules/contrib/colorbox/js/colorbox_inline.js']);

}
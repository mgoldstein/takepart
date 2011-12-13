<?php

class views_handler_addthis extends views_handler_field {
  function option_definition() {
    $options = parent::option_definition();

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  function query() {
    // do nothing -- to override the parent query.
  }

  function render($values) {
    $curnid = $values->nid;
    $curtitle = $values->node_title;
    $theURL = url(drupal_lookup_path('alias', 'node/'.$curnid),array('absolute'=> TRUE ) );

    $ret = <<<EOV
<!-- AddThis Button BEGIN -->
<div class="addthis_toolbox addthis_default_style "
  addthis:url="$theURL"
  addthis:title="$curtitle"
>
  <a class="addthis_button_facebook"></a>
  <a class="addthis_button_twitter" tw:via="<?php print $variables['takepart_addthis_tweet_via']; ?>"></a>
  <a class="addthis_button_linkedin">LinkedIn</a>
  <a class="addthis_button_email"></a>
  <a class="addthis_button_print"></a>
  <a class="addthis_counter addthis_bubble_style"></a>
</div>
EOV;

    return $ret;
  }
}

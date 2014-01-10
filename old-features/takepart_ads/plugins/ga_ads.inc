<?php

class boxes_ga_ad extends boxes_box {

  public function options_defaults() {
    return array(
      'ga_ad_slot' => '',
      'ga_ad_gpt_id' => '',
    );
  }

  public function options_form(&$form_state) {
    //update options from form state
    foreach($this->options as $key => $value) {
      if (isset($form_state['values'][$key])) {
        $this->options[$key] = $form_state['values'][$key];
      }
    }

    $form = array();

    //Select entity type
    $entities_info = entity_get_info();
    foreach($entities_info as $key=>$info) {
      if($info['fieldable']) {
        $entity_type_options[$key] = $info['label'];
      }
    }
    $form['ga_ad_slot'] = array(
      '#type' => 'textfield',
      '#title' => 'Ad Slot',
      '#default_value' => $this->options['ga_ad_slot'],
    );
    $form['ga_ad_gpt_id'] = array(
        '#type' => 'textfield',
        '#title' => 'GPT ID',
        '#default_value' => $this->options['ga_ad_gpt_id'],
    );
    return $form;
  }

  public function render() {

    if (function_exists('wordlet_active_page')) {
      $wordlet_page = wordlet_active_page();
      if ($wordlet_page !== FALSE) {
        if ($wordlet_page['suppress_ad_block']) {
          return array(
            'delta' => $this->delta,
            'title' => $this->title,
            'subject' => $this->title,
            'content' => '',
          );
        }
      }
    }

    if( ($slot = $this->options['ga_ad_slot']) &&
       ($dpf = variable_get('takepart_ads_dfp_property_code', ''))
      ) {

      $gptid = false;
      if($this->options['ga_ad_gpt_id']) {
        $gptid = array($slot => $this->options['ga_ad_gpt_id']);
        takepart_gpt_ads($gptid);
      }

     //register the slot
     takepart_ads($slot);

     if ($gptid) {
       $adsize = substr( strrchr( $slot, '_' ), 1);
       $lr = explode("x", $adsize);

       $gptfunction = substr(str_shuffle("abcdefghijklmnopqrstuvwxyz"), 0, 10);


       $content = <<<HTM
<!-- $slot -->
<div id='$gptid[$slot]' style='width:$lr[0]px; height:$lr[1]px;'>
<script type='text/javascript'>
  function $gptfunction() {
   if (typeof(googletag) !== 'undefined') {
    googletag.cmd.push(function() { googletag.display('$gptid[$slot]'); });
   } else {
    setTimeout("$gptfunction()",1000);
   }
  }
  $gptfunction();
</script>
</div>
HTM;
     } else {
      $content = <<<HTM
<script type='text/javascript'>
  GA_googleFillSlot('$slot');
</script>
HTM;
     }

    return array(
      'delta' => $this->delta, // Crucial.
      'title' => $this->title,
      'subject' => $this->title,
      'content' => $content,
      // I do not know why i have to render this
      //'content' => $render_array,
    );
    }
  }
}
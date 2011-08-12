<?php

class boxes_ga_ad extends boxes_box {

  public function options_defaults() {
    return array(
      'ga_ad_slot' => '',
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
      '#default_value' => $this->options['entity_type'],
    );  

    return $form; 
  }  

  public function render() {
    if(($slot = $this->options['ga_ad_slot']) &&
       ($dpf = variable_get('takepart_ads_dfp_property_code', ''))
      ) {
     //register the slot
     takepart_ads($slot);
      $content = <<<HTM
<script type='text/javascript'>
  GA_googleFillSlot('$slot');
</script> 
HTM;
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

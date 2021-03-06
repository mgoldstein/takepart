<?php

class boxes_ga_ad extends boxes_box {

  public function options_defaults() {
    return array(
	 'ga_ad_slot' => '',
	 'ga_ad_gpt_id' => '',
   'ga_ad_width' => '',
   'ga_ad_height' => '',
    );
  }

  public function options_form(&$form_state) {
    //update options from form state
    foreach ($this->options as $key => $value) {
	 if (isset($form_state['values'][$key])) {
	   $this->options[$key] = $form_state['values'][$key];
	 }
    }

    $form = array();

    //Select entity type
    $entities_info = entity_get_info();
    foreach ($entities_info as $key => $info) {
	 if ($info['fieldable']) {
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
    $form['ga_ad_width'] = array(
    '#type' => 'textfield',
    '#title' => 'Ad Width',
    '#default_value' => $this->options['ga_ad_width'],
    );
    $form['ga_ad_height'] = array(
    '#type' => 'textfield',
    '#title' => 'Ad Height',
    '#default_value' => $this->options['ga_ad_height'],
    );
    return $form;
  }

  public function render() {

    $refresh = variable_get('takepart_ads_dfp_refresh', '31');
    $refresh = $refresh * 1000; //convert seconds to millisecons
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

    if (($slot = $this->options['ga_ad_slot']) && ($dpf = variable_get('takepart_ads_dfp_property_code', ''))) {
      $gptid = false;
      if ($this->options['ga_ad_gpt_id']) {
       $gptid = array($slot => $this->options['ga_ad_gpt_id']);
       takepart_gpt_ads($gptid);
      }

	 //register the slot
	 takepart_ads($slot);

	 if ($gptid) {
     //Adding ad size to form. Keeping reg ex split for legacy
     if($this->options['ga_ad_width'] && $this->options['ga_ad_height']) {
       $lr = array($this->options['ga_ad_width'], $this->options['ga_ad_height']);
       //Registering the height and width of the ads if they exist
       $gpthw[$slot] = $lr;
       takepart_hw_ads($gpthw);
     } else {
       $adsize = '';
       preg_match('/[0-9]+x[0-9]+/', $slot, $adsize);
       $lr = explode("x", $adsize[0]);
     }

     $gptfunction = substr(str_shuffle("abcdefghijklmnopqrstuvwxyz"), 0, 10);

	   if ($slot === 'TP_Mobile_320x50') {
		$content = <<<HTM
            <!-- $slot -->
            <div id='$gptid[$slot]' style='width:320px; height:50px;'>
            <script type='text/javascript'>
            function $gptfunction() {
              if (typeof(googletag) !== 'undefined') {
                if (ad_call_check($lr[0])) {
                  googletag.cmd.push(function() {
                    var slot1 = googletag.defineSlot('/4355895/$slot', [320, 50], '$gptid[$slot]').addService(googletag.pubads());
                    googletag.pubads().enableSingleRequest();
                    googletag.enableServices();
                    googletag.display('$gptid[$slot]');
                  });
                } else {
                  jQuery('#$gptid[$slot]').css({'width': '0', height: '0'});
                }
              }
              setInterval(function(){
                googletag.pubads().refresh();
              }, $refresh);
            }
            $gptfunction();
            </script>
            </div>
HTM;
	   } else if (strpos($slot, 'Responsive') !== FALSE) {
       //The same ad leaderboard tag is put on the page to display the
       //ad in the correct spot. This id helps pick the correct slot.
       $resp_size_id = $gptid[$slot].'-'.$lr[0];
		$content = <<<HTM
            <!-- $slot -->
            <div id="$resp_size_id" class="leaderboard-ad">
            <script type='text/javascript'>
            function $gptfunction() {
              if (typeof(googletag) !== 'undefined') {
                if (ad_call_check($lr[0])) {
                  googletag.cmd.push(function() {
                    googletag.display('$resp_size_id');
                  });
                } else {
                  jQuery('#$resp_size_id').css({'width': '0', height: '0'});
                }
              }
              setInterval(function(){
                googletag.pubads().refresh();
              }, $refresh);
            }
            $gptfunction();
            </script>
            </div>
HTM;
	   } else if ($slot === 'VideoOverlay_HP') {
		$content = <<<HTM
            <!-- $slot -->
            <div id='$gptid[$slot]'>
            <script type='text/javascript'>
              function $gptfunction() {
               if (typeof(googletag) !== 'undefined') {
                   googletag.cmd.push(function() { googletag.display('$gptid[$slot]'); });
               }
              }
              $gptfunction();
            </script>
            </div>
HTM;
	   } else {
       $content = <<<HTM
             <!-- $slot -->
             <div id='$gptid[$slot]' class="leaderboard-ad" style='width:$lr[0]px; height:$lr[1]px;'>
             <script type='text/javascript'>
               function $gptfunction() {
                if (typeof(googletag) !== 'undefined') {
                  if (ad_call_check($lr[0])) {
                    googletag.cmd.push(function() { googletag.display('$gptid[$slot]'); });
                  }
                  else {
                    jQuery('#$gptid[$slot]').css({'width': '0', height: '0'});
                  }
                }
               }
               $gptfunction();
             </script>
             </div>
HTM;
     }
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
     'height' => $this->options['ga_ad_height'],
     'width' => $this->options['ga_ad_width']
	 );
    }
  }

}

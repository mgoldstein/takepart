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
        $adsize = '';
        preg_match('/[0-9]+x[0-9]+/', $slot, $adsize);
        $lr = explode("x", $adsize[0]);
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
        }
        else if ($slot === 'TP_Mobile_Interstitial_1x1') {
          $content = <<<HTM
            <!-- $slot -->
            <div id='$gptid[$slot]' style='width:$lr[0]px; height:$lr[1]px;'>
            <script type='text/javascript'>
              function $gptfunction() {
               if (typeof(googletag) !== 'undefined') {
                 if (window.innerWidth < 768) {
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

            <!-- TP_Mobile_Interstitial_1x1 out-of-page -->
            <div id='div-gpt-ad-1413399742891-0-oop'>
              <script type='text/javascript'>
                function mobile_interstitial_oop() {
                  if (typeof(googletag) !== 'undefined') {
                    if (window.innerWidth < 768) {
                      googletag.cmd.push(function () {
                          googletag.display('div-gpt-ad-1413399742891-0-oop');
                      });
                    } else {
                      jQuery('#div-gpt-ad-1413399742891-0-oop').css({'width': '0', height: '0'});
                    }
                  }
                }
              mobile_interstitial_oop();
              </script>
            </div>
HTM;
        }else if ($slot === 'TP_Mobile_Overlay_300x250') {
          $content = <<<HTM
            <!-- $slot -->
            <div id='$gptid[$slot]' style='width:300px; height:250px;'>
            <script type='text/javascript'>
            function $gptfunction() {
              if (typeof(googletag) !== 'undefined') {
                if (ad_call_check($lr[0])) {
                  googletag.cmd.push(function() {
                    var slot1 = googletag.defineSlot('/4355895/$slot', [300, 250], '$gptid[$slot]').addService(googletag.pubads());
                    googletag.pubads().enableSingleRequest();
                    googletag.enableServices();
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
        }else {
          $content = <<<HTM
            <!-- $slot -->
            <div id='$gptid[$slot]' class="leaderboard-ad"style='width:$lr[0]px; height:$lr[1]px;'>
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
        // I do not know why i have to render this
        //'content' => $render_array,
      );
    }
  }

}

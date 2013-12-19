<?php
/**
 * @file
 * tp_feature_contexts.box.inc
 */

/**
 * Implements hook_default_box().
 */
function tp_feature_contexts_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'bg_skin_sponsor';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'GA: ROS Background Take-over';
  $box->options = array(
    'ga_ad_slot' => 'TP3_ROS_Background_1x1',
    'ga_ad_gpt_id' => 'div-gpt-ad-1371853059233-0',
    'additional_classes' => '',
  );
  $export['bg_skin_sponsor'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-18786b90';
  $box->plugin_key = 'simple';
  $box->title = 'TakePart Video';
  $box->description = 'Right Rail Video Player: Ads Auto Play';
  $box->options = array(
    'body' => '<script src="http://jwpsrv.com/library/esP2FhWwEeODmBIxOUCPzg.js"></script>
<div id="botr_Y0y8DVG4_TPXPTQu4_ply"></div>
<script type="text/javascript">

  // Use this variable to turn on/off pre-roll ads
  // true - Pre-roll ads with auto play
  // false - No ads and not auto play

  var enable_pre_roll_ads = false;

  // DO NOT EDIT BELOW THIS LINE
  var player_config = {
    analytics: {
     "enabled": false
    },
    aspectratio: "16:9",
    autostart: enable_pre_roll_ads,
    controls: true,
    displaytitle: false,
    fallback: false,
    flashplayer: "http://a.jwpcdn.com/player/6/653609/jwplayer.flash.swf",
    ga: {
      "idstring": "title"
    },
    height: 610,
    html5player: "http://a.jwpcdn.com/player/6/653609/jwplayer.html5.js",
    image: "http://video.takepart.com/thumbs/PYuSkFyj-640.jpg",
    listbar: {
      "position": "bottom",
      "size": 250
    },
    playlist: "http://video.takepart.com/jw6/Y0y8DVG4.xml",
    plugins: {
      "http://a.jwpcdn.com/player/6/653609/ping.js": {
        "pixel": "http://video.takepart.com/ping.gif"
      }
    },
    primary: "flash",
    repeat: false,
    sharing: {
      "code": "%3Ciframe%20src%3D%22http%3A//video.takepart.com/players/MEDIAID-TPXPTQu4.html%22%20width%3D%22640%22%20height%3D%22610%22%20frameborder%3D%220%22%20scrolling%3D%22auto%22%3E%3C/iframe%3E",
      "link": "http://video.takepart.com/previews/MEDIAID-TPXPTQu4"
    },
    skin: "http://a.jwpcdn.com/skins/f0EMcd6B.xml",
    stretching: "uniform",
    width: "100%",
    mute: enable_pre_roll_ads
  }
  if (enable_pre_roll_ads) {
    player_config[\'advertising\'] = {
      "client":"vast",
      "tag": "http://pubads.g.doubleclick.net/gampad/ads?sz=640x360&iu=/4355895/TP3_Video_Siderail_640x360&ciu_szs&impl=s&gdfp_req=1&env=vp&output=xml_vast2&unviewed_position_start=1&url=[referrer_url]&correlator=[timestamp]",
      "admessage":"You can skip this ad in XX more seconds"
    };
  }
  jwplayer("botr_Y0y8DVG4_TPXPTQu4_ply").setup(player_config);
</script>
',
    'additional_classes' => '',
  );
  $export['box-18786b90'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ga_homepage_bottom_right';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'GA: Homepage Bottom Right';
  $box->options = array(
    'ga_ad_slot' => 'TP3_Homepage_RR_BTF_300x600',
    'ga_ad_gpt_id' => 'div-gpt-ad-1376947919227-0',
    'additional_classes' => 'block-boxes-ga_ad',
  );
  $export['ga_homepage_bottom_right'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ga_homepage_header';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'GA: Homepage Leaderboard';
  $box->options = array(
    'ga_ad_slot' => 'TP3_Homepage_Leaderboard_728x90',
    'ga_ad_gpt_id' => 'div-gpt-ad-1376947900543-0',
    'additional_classes' => 'leaderboard',
  );
  $export['ga_homepage_header'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ga_homepage_top_right';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'GA: Homepage Top Right';
  $box->options = array(
    'ga_ad_slot' => 'TP3_Homepage_RR_ATF_300x250',
    'ga_ad_gpt_id' => 'div-gpt-ad-1376947911678-0',
    'additional_classes' => 'block-boxes-ga_ad',
  );
  $export['ga_homepage_top_right'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ga_hp_1x1_background';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'GA: Homepage Background Take-over';
  $box->options = array(
    'ga_ad_slot' => 'TP3_Homepage_Background_1x1',
    'ga_ad_gpt_id' => 'div-gpt-ad-1376947700448-0',
    'additional_classes' => '',
  );
  $export['ga_hp_1x1_background'] = $box;

  return $export;
}

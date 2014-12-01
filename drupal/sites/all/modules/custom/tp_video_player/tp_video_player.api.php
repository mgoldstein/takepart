<?php

/**
 *  @function:
 *    This function is called after the combining of the configurations.
 *    The configuration contains all information regarding the player.
 *
 *    This hook is called within tp_video_player_build_settings() in tp_video_player.configuration.inc
 *
 *    @param:
 *      config - this is the configuration for the player and will be for both video and playlist
 *      display - this is non-alterable as this is late in the stack.
 *      file - the video file. noting that playlist returns only the first file, so using this for video content type is good.
 */
function hook_tp_video_player_config_alter(&$config, &$display, &$file) {
  //example to add auto start to everything
  $config['autostart'] = FALSE;

  //example to pull the global configuration and convert it to the tag url  
  $default_config = tp_video_player_load_default_configuration('video_block');
  $tag_url = takepart_ads_tag_url($default_config->ad_tag . '');
  
  //adjusts the config to override the ads
  if (!empty($tag_url)) {
    $config['advertising'] = array(
      'admessage' => $default_config->ad_message,
      'client' => $default_config->ad_client,
      'tag' => $tag_url,
    );
  }
}

/**
 *  @function:
 *    This function is called after performing a retrieve for a playlist via tp_video_player_list_from_nid().
 *
 *    @param:
 *      player - configuration for the player
 */
function hook_tp_video_player_get_alter(&$player) {
  
}
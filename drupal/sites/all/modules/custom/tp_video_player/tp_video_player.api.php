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
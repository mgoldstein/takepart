<?php

/**
 *  Implements hook_tp_video_player_config_alter().
 */
function tp_videos_tp_video_player_config_alter(&$config, &$display, &$file) {
  //variables
  $menu_obj = menu_get_object();

  /**
   *  Main Detail Pages override
   *
   *  @logic:
   *    - Video Playlist Detail
   *      - Autostart set to TRUE
   *    - Video Detail
   *      - Autostart set to TRUE
   *      - SiteCat videoSource set to filemime type.
   */
  //only does it for the video playlist page
  if (is_object($menu_obj) && $menu_obj->type == 'video_playlist' && $display == 'playlist_display') {
    //makes all video playlist autostart only on detail page
    $config['autostart'] = TRUE;
  }

  //only does it for the video page
  if (is_object($menu_obj) && $menu_obj->type == 'video' && $display == 'video_full_page') {
    //makes all video autostart only on detail page
    $config['autostart'] = TRUE;

    //adds video source into the site cat variable
    $config['sitecatalyst']['videoSource'] = $file['filemime'];
  }

  /**
   *  Blocks override
   *
   *  @logic:
   *    - Video Block
   *      - Pull in default to override node level ads
   */
  if ($display == 'video_block') {
  }
}

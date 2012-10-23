<?php
/**
 * @file rightrail-video-preview.tpl.php
 * Display right rail block preview
 *
 * - $p_title     block title
 * - $p_video_id  id of video
 * - $p_preview   preview image
 * - $p_body      block body
 *
 * @ingroup views_templates
 */
?>
<div id="youtube_block">
  <div style="line-height: 5px;">&nbsp;</div>
  <br>
  <div style="line-height: 5px;">&nbsp;</div>
  <img src="http://img.youtube.com/vi/<?php echo $p_video_id; ?>/0.jpg" width="275" height="155"></img>
  <div style="line-height: 5px;">&nbsp;</div>
  <strong><a href="http://www.youtube.com/embed/<?php echo $p_video_id; ?>">Read more and take action here.</a></strong></div>

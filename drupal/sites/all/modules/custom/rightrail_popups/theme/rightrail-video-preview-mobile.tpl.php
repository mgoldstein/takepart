<?php
/**
 * @file rightrail-video-preview-mobile.tpl.php
 * Display right rail block preview
 *
 * - $p_title     block title
 * - $p_video_id  id of video
 * - $p_vid_link  link to open video
 *
 * @ingroup views_templates
 */

?>
<div id="youtube_block" class="rr-preview">
  <div style="line-height: 12px;">&nbsp;</div>
  <iframe width="275" height="155" src="http://www.youtube.com/embed/<?php echo $p_video_id; ?>?rel=0" frameborder="0" allowfullscreen></iframe>
  <div style="line-height: 5px;">&nbsp;</div>
  <strong>Read more and take action here.</strong>
</div>

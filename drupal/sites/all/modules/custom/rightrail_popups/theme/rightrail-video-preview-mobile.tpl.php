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
  <img src="http://img.youtube.com/vi/<?php echo $p_video_id; ?>/mqdefault.jpg" width="275" height="155" />
  <div style="line-height: 5px;">&nbsp;</div>
  <strong><a class="rrpop-<?php print $p_video_id; ?>" href="http://www.youtube.com/embed/<?php echo $p_video_id; ?>">Read more and take action here.</a></strong>
  <a href="<?php print $p_vid_link; ?>"><div class="rr-preview-arrow"></div></a>
</div>

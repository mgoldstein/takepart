<?php
/**
 * @file rightrail-video-preview.tpl.php
 * Display right rail block preview
 *
 * - $p_title     block title
 * - $p_video_id  id of video
 * - $p_popup     popup html
 *
 * @ingroup views_templates
 */

?>
<div id="youtube_block" class="rr-preview">
  <div style="line-height: 12px;">&nbsp;</div>
  <img src="http://img.youtube.com/vi/<?php echo $p_video_id; ?>/mqdefault.jpg" width="275" height="155" />
  <div style="line-height: 5px;">&nbsp;</div>
  <strong><a href="http://www.youtube.com/embed/<?php echo $p_video_id; ?>">Read more and take action here.</a></strong>
  <a class="colorbox-inline rrpop-<?php print $p_video_id; ?>" href="?width=870&amp;height=420&amp;inline=true#<?php print $p_video_id; ?>"><div class="rr-preview-arrow"></div></a>
</div>
<div class="vidpop-overlay">
  <div id="<?php echo $p_video_id; ?>"><?php print $p_popup; ?></div>
</div>

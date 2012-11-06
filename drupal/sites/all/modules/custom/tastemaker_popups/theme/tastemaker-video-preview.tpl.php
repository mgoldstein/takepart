<?php
/**
 * @file tastemaker-video-preview.tpl.php
 * Display right rail block preview
 *
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
  <a class="colorbox-inline" href="?width=870&amp;height=420&amp;inline=true#<?php print $p_video_id; ?>"><div class="rr-preview-arrow"></div></a>
</div>
<?php
if (!takepart_vidpop_mobile_browser()) {
// add hidden popups if on non-mobile
$formatted .= <<<EOT
<div class="vidpop-overlay">
  <div id="$p_video_id">$p_popup</div>
</div>
EOT;
echo $formatted;
}
?>

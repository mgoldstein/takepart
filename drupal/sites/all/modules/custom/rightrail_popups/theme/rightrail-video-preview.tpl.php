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
<div id="youtube_block">
  <div style="line-height: 5px;">&nbsp;</div>
  <br>
  <div style="line-height: 5px;">&nbsp;</div>
  <a class="colorbox-inline" href="?width=870&amp;height=420&amp;inline=true#<?php print $p_video_id; ?>"><img src="http://img.youtube.com/vi/<?php echo $p_video_id; ?>/0.jpg" width="275" height="155" /></a>
  <div style="line-height: 5px;">&nbsp;</div>
  <strong><a href="http://www.youtube.com/embed/<?php echo $p_video_id; ?>">Read more and take action here.</a></strong>
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

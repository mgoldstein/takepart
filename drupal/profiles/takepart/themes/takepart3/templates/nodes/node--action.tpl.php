<?php if (!empty($pre_object)) print render($pre_object) ?>

<div class='action <?php print $classes ?> clearfix'
<?php print ($attributes) ?>>

<?php
//Action Header Image:
//$field_actionheaderimg_path = file_create_url($content['body']['#object']->field_actionheaderimg['und'][0]['uri']);
/*
$field_actionheaderimg_path = ($content['body']['#object']->field_actionheaderimg['und'][0]['uri']);
if($field_actionheaderimg_path) {
  $field_actionheaderimg_path = str_replace("public://", "/sites/default/files/styles/action_header_image/public/", $field_actionheaderimg_path);
  print '<a href="' . $content['body']['#object']->field_actionheaderimghref['und'][0]['display_url'] . '"><img src="' . $field_actionheaderimg_path . '" alt="' . $content['body']['#object']->field_actionheaderimghref['und'][0]['title'] . '"></a>';
}
 * 
 */
?>

<?php if (!empty($title_prefix)) print render($title_prefix); ?>


<?php if (!empty($title) && !($remove_title)): ?>
<h1 <?php if (!empty($title_attributes)) print $title_attributes ?>
class='title'>

<?php if (!empty($new)): ?>
<span class='new'><?php print $new ?>
</span>
<?php endif; ?>
<a href="<?php print $node_url ?>"><?php print $title ?></a>
</h1>
<?php endif; ?>

<?php if (!empty($title_suffix)) print render($title_suffix); ?>

<?php // if (!empty($submitted)): ?>
    <?php // print $submitted ?>
  <?php // endif; ?>

  <?php if (!empty($content)): ?>
<?php hide($content['comments']); ?>
<div class='content content-bottom clearfix <?php if (!empty($is_prose)) print 'prose' ?>'>
<?php if($view_mode == 'teaser'): ?>
<?php hide($content['field_free_tag']); ?>
<?php hide($content['field_topic']); ?>
<?php hide($content['body']); ?>
<?php endif; ?>
<div id="action_copy">
<div id="article_image">
<?php
/*
print render($content['field_action_main_image']); 
$addthisblock = module_invoke("takepart_addthis", 'block_view', 'addthis_full');
print '<div id="action_addthisblock">'. $addthisblock['content'] .'</div>';
 * 
 */
?>
</div>
<?php
      if (function_exists('media_filter')) {
      print media_filter($content['body']['#object']->body['und'][0]['value']);
      } else {
      print ($content['body']['#object']->body['und'][0]['value']);
      }
   
    $takeactionurl = $content['body']['#object']->field_action_url['und'][0]['display_url'];
    $takeactionurl_parts = parse_url($takeactionurl);
   
?>

<?php if((array_key_exists('host', $takeactionurl_parts)) && ($takeactionurl_parts['host'] == $_SERVER['HTTP_HOST']) || ($takeactionurl_parts['host'] == '')) { ?>
	<a href="<?php print $takeactionurl; //Take Action Button ?>" class="take_action_button" onclick="this.blur(); return false;"><span>Take Action</span></a>
<?php } else { ?>
	<a href="<?php print $takeactionurl; //Take Action Button ?>" class="take_action_button" target="_blank" onclick="this.blur(); return false;"><span>Take Action</span></a>
<?php } ?>
        </div>
   
        <div id="action_alt_copy">
    <?php
      if (function_exists('media_filter')) { //Alternate Content
        print media_filter($content['body']['#object']->field_altcontent['und'][0]['value']);
      } else {
        print ($content['body']['#object']->field_altcontent['und'][0]['value']);
      }
    ?>
</div>
<?php if($view_mode == 'teaser'): ?>
<?php show($content['field_topic']); ?>
<?php print render($content['body']); ?>
<?php print render($content['field_topic']); ?>
<?php endif; ?>
</div>
<?php endif; ?>
<?php if (!empty($links)): ?>
<div class='links clearfix'>
<?php // print render($links) ?>
</div>
<?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object) ?>
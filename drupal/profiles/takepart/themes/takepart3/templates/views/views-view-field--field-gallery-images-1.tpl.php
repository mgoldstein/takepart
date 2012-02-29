<?php
$mediaalttag = false;
try {
  $trim = 8;
  //@todo, hacky, move this to a preprocess function:  
  preg_match('/src=[\'"]?([^\'" >]+)[\'" >]/', $output, $matches);
  $imgfile = urldecode(basename($matches[1]));
  $imgfile = str_replace ("size_", "", $imgfile);
  for ($i=0; $i<sizeof($row->_field_data['nid']['entity']->field_gallery_images['und']); $i++) {
    if(substr($imgfile,0,($trim))  == substr($row->_field_data['nid']['entity']->field_gallery_images['und'][$i]['file']->filename,0,($trim)) ) {
      if(!$mediaalttag) {
        $mediaalttag = ($row->_field_data['nid']['entity']->field_gallery_images['und'][$i]['file']->field_media_alt['und'][0]['value']);
      }
      if(!$mediaalttag) {
        $mediaalttag = ($row->_field_data['nid']['entity']->field_gallery_images['und'][$i]['file']->field_image_title['und'][0]['value']);
      }
      if(!$mediaalttag) {
        $mediaalttag = ($row->_field_data['nid']['entity']->field_gallery_images['und'][$i]['file']->field_title['und'][0]['value']);
      }
      if(!$mediaalttag) {
        $mediaalttag = "";
      }      
      break;
    }
  }
} catch (Exception $e) { }
?>
<?php print str_replace('alt=""', 'alt="'.$mediaalttag.'"', $output); ?>
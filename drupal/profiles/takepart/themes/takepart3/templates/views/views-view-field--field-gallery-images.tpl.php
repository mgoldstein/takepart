<?php
try {
  $trim = 6;
  //@todo, hacky, move this to a preprocess function:  
  preg_match('/src=[\'"]?([^\'" >]+)[\'" >]/', $output, $matches);
  $imgfile = urldecode(basename($matches[1]));
  for ($i=0; $i<sizeof($row->_field_data['nid']['entity']->field_gallery_images['und']); $i++) {
    if(substr($imgfile,0,($trim*-1))  == substr($row->_field_data['nid']['entity']->field_gallery_images['und'][$i]['file']->filename,0,($trim*-1)) ) {
      $mediaalttag = ($row->_field_data['nid']['entity']->field_gallery_images['und'][$i]['file']->field_title['und'][0]['value']);
      if(!$mediaalttag) {
        $mediaalttag = ($row->_field_data['nid']['entity']->field_gallery_images['und'][$i]['file']->field_image_title['und'][0]['value']);
      }
      if(!$mediaalttag) {
        $mediaalttag = ($row->_field_data['nid']['entity']->field_gallery_images['und'][$i]['file']->field_media_alt['und'][0]['value']);
      }
      break;
    }
  }
} catch (Exception $e) {
  $mediaalttag = "";
}
?>
<?php print str_replace('alt=""', 'alt="'.$mediaalttag.'"', $output); ?>
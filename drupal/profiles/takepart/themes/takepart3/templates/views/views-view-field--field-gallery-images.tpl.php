<?php
try {
  //@todo, hacky, move this to a preprocess function:  
  preg_match('/src=[\'"]?([^\'" >]+)[\'" >]/', $output, $matches);
  $imgfile = urldecode(basename($matches[1]));
  for ($i=0; $i<sizeof($row->_field_data['nid']['entity']->field_gallery_images['und']); $i++) {
    if($imgfile == $row->_field_data['nid']['entity']->field_gallery_images['und'][$i]['file']->filename) {
      $mediaalttag = ($row->_field_data['nid']['entity']->field_gallery_images['und'][$i]['file']->field_media_alt['und'][0]['value']);
      break;
    }
  }
} catch (Exception $e) {
  $mediaalttag = "";
}
?>
<?php print str_replace('alt=""', 'alt="'.$mediaalttag.'"', $output); ?>
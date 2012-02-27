<?php
try {
  $trim = 3;
  //@todo, hacky, move this to a preprocess function:  
  preg_match('/src=[\'"]?([^\'" >]+)[\'" >]/', $output, $matches);
  $imgfile = urldecode(basename($matches[1]));
  print "\n";
  print "\n";
  print "\n";
  print $imgfile;
  print "\n";
  for ($i=0; $i<sizeof($row->_field_data['nid']['entity']->field_gallery_images['und']); $i++) {
    print $row->_field_data['nid']['entity']->field_gallery_images['und'][$i]['file']->filename;
    print "\n";
    if(substr($imgfile,0,($trim*-1))  == substr($row->_field_data['nid']['entity']->field_gallery_images['und'][$i]['file']->filename,0,($trim*-1)) ) {
      $mediaalttag = ($row->_field_data['nid']['entity']->field_gallery_images['und'][$i]['file']->field_media_alt['und'][0]['value']);
      break;
    }
  }
} catch (Exception $e) {
  $mediaalttag = "";
}
?>
<?php print str_replace('alt=""', 'alt="'.$mediaalttag.'"', $output); ?>
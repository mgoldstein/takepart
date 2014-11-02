<?php

  $fids = db_select('file_managed', 'f')
    ->fields('f', array('fid'))
    ->condition('f.filemime', array(
      'video/youtube',
      'video/vimeo',
      'video/jwplatform',
    ), 'IN')
    ->orderBy('f.timestamp', 'DESC')
    ->execute()
    ->fetchCol();
  $count = count($fids);
  print "{$count}\n";
  $i = 0;
  
  foreach ($fids as $fid) {
    print "{$fid}\n";
  }
  
  foreach ($fids as $fid) {
    $file = file_load($fid);
    tp_videos_entity_update($file, 'file');
    $i++;
    print "{$i} ";
    print "{$fid} ";
    print "{$file->filemime}\n";
    sleep(1);
  }

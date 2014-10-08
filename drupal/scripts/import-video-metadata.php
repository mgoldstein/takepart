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

  foreach ($fids as $fid) {
    $file = file_load($fid);

    tp_videos_entity_update($file, 'file');

    print "{$file->filemime}\n";

    sleep(5);
  }

<?php

  $nids = db_query("SELECT nid, nid FROM node WHERE type = 'action'")->fetchCol();
  foreach ($nids as $nid) {
    $source = "node/" . $nid;
    db_query("DELETE FROM url_alias WHERE source = :source", array(":source" => $source));
  }

<?php

class TakePartVideoPlayerFileFieldBuilder {

  private function allowedRegions($node) {

    $regions = array();
    $items = field_get_items('node', $node, 'field_allowed_regions');
    if ($items !== FALSE && count($items) > 0) {
      foreach ($items as $item) {
        $value = str_replace(array(','), ' ', $item['value']);
        $chunks = explode(' ', $value);
        $trimmed = array_map('trim', $chunks);
        $list = array_filter($trimmed, 'strlen');
        $regions += array_map('strtolower', $list);
      }
    }
    return $regions;
  }

}

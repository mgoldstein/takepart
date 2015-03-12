<?php

/**
 *  @function:
 *    Implements hook_tp_wordpress_import_item().
 *
 *    @param:
 *      $item = current item before it gets added into the processor list
 *      $original_item = original DOMdocument item
 */
function hook_tp_wordpress_import_item_alter(&$item, &$original_item) {
  //alters the item's author
  $item['author'] = 'Anonymous';
}
<?php

class TakePartContestEntryUIController extends EntityDefaultUIController {

  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = 'Manage contest types, including adding and removing fields and the display of fields.';
    return $items;
  }
}

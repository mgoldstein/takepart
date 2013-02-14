<?php

class ExternalActionAnalyticsController extends TakeActionAnalyticsController {

  public function entityView($entity, $view_mode, $langcode) {

    if ($view_mode === 'full' || $view_mode === 'embed') {

      $items = field_get_items('node', $entity, 'field_tab_link_only');
      $link_only = FALSE;
      if (!empty($items)) {
        // Use only the first value (there should be only one).
        $item = reset($items);
        $link_only = !empty($item['value']);
      }

      if ($view_mode === 'embed' && $link_only) {
        // External action taken (on-site and link only).
        $instance_name = "external_action_click-{$entity->nid}";
        $event = tp_analytics_event('external_action_click', array(
          'title' => check_plain($entity->title),
          'view_mode' => $view_mode,
        ));
        $this->addFrontEndEventInstance($instance_name, $event);
      }
    }
    parent::entityView($entity, $view_mode, $langcode);
  }
}

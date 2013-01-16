<?php

class TakeActionAnalyticsController extends TakePartAnalyticsController {

  public function entityView($entity, $view_mode, $langcode) {

    $tracked_views = array('full', 'embedaction', 'embedaction_expanded');
    if (in_array($view_mode, $tracked_views)) {

      if ($view_mode === 'full') {

        // TAB - full page action view.
        $event = tp_analytics_event(
          'action_view',
          $this->getEventArgs($entity),
          'session',
          "action-view-node-{$entity->nid}"
        );
        $this->addPageloadEvent($event);

        if ($entity->type === 'action') {
          // TAB - full page action taken (external actions only).
          $instance_name = "action_taken-{$entity->nid}";
          $event = tp_analytics_event(
            'action_taken',
            $this->getEventArgs($entity),
            'page',
            "action_taken-{$entity->nid}"
          );
          $this->addFrontEndEventInstance($instance_name, $event);
        }
      }

      // TAB - See more actions button click
      $event = tp_analytics_event('see_more_actions_click');
      $this->addFrontEndEventInstance('see_more_actions_click', $event);
    }
    elseif ($view_mode === 'embed' && $entity->type === 'action') {

      // TAB - See more actions button click
      $event = tp_analytics_event('see_more_actions_click');
      $this->addFrontEndEventInstance('see_more_actions_click', $event);
    }

    parent::entityView($entity, $view_mode, $langcode);
  }

  public function addShareEventInstance($entity, $view_mode) {
    $instance_name = "action_share-{$entity->nid}";
    $args = $this->getEventArgs($entity);
    $args['view_mode'] = $view_mode;
    $event = tp_analytics_event('action_share', $args);
    $this->addFrontEndEventInstance($instance_name, $event);
  }

  public function getActionTakenEventCommand($entity, $view_mode) {
    // TAB - action taken (petitions and pledges) AJAX command.
    $event = tp_analytics_event(
      'action_taken',
      $this->getEventArgs($entity),
      'page',
      "action-taken-node-{$entity->nid}"
    );
    return $this->getFireEventCommand($event);
  }

  protected function getEventArgs($entity) {

    // Extract the action type term ids from the field.
    $action_type = '';
    $items = field_get_items('node', $entity, 'field_action_type');
    if (!empty($items)) {
      // Use only the first one (there should be only one).
      $item = reset($items);
      $tag = taxonomy_term_load($item['tid']);
      if (isset($tag->name)) {
        $mapping = array(
          'Petition' => t('Petition'),
          'Pledge' => t('Pledge'),
          'Contribution' => t('Donation'),
          'Donation' => t('Donation'),
          'Awareness' => t('Awareness'),
        );
        $action_type = isset($mapping[$tag->name]) ? $mapping[$tag->name]
          : t('Awareness');
      }
    }

    // Extract the topic term ids from the field.
    $items = field_get_items('node', $entity, 'field_display_tag');
    $tids = array();
    if (!empty($items)) {
      foreach ($items as $delta => $item) {
        $tids[] = $item['tid'];
      }
    }
    $tags = taxonomy_term_load_multiple($tids);
    $topic = taxonomy_implode_tags($tags);

    // Extract the sponsor
    $sponsor = '';
    $items = field_get_items('node', $entity, 'field_action_sponsor');
    if (!empty($items)) {
      $first = reset($items);
      $sponsor_node = node_load($first['nid']);
      if ($sponsor_node !== FALSE) {
        $sponsor = check_plain($sponsor_node->title);
      }
    }

    return array(
      'title' => check_plain($entity->title),
      'action_type' => $action_type,
      'topic' => $topic,
      'empowered_by' => $sponsor,
    );
  }
}

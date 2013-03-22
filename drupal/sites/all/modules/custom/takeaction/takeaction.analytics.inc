<?php

class TakeActionAnalyticsController extends TakePartAnalyticsController {

  public function entityView($entity, $view_mode, $langcode) {

    $tracked_views = array('full', 'embedaction', 'embedaction_expanded');
    if (in_array($view_mode, $tracked_views)) {

      if ($view_mode === 'full') {

        // TAB - full page action view.
        $event = tp_analytics_event(
          'action_view',
          $this->getEventArgs($entity, $view_mode),
          'session',
          "action-view-node-{$entity->nid}-{$view_mode}"
        );
        $this->addPageloadEvent($event);

        if ($entity->type === 'action') {
          // TAB - full page action taken (external actions only).
          $instance_name = "action_taken-{$entity->nid}";
          $event = tp_analytics_event(
            'action_taken',
            $this->getEventArgs($entity, $view_mode),
            'page',
            "action_taken-{$entity->nid}"
          );
          $this->addFrontEndEventInstance($instance_name, $event);
        }
      }
      elseif ($entity->type !== 'action') {
        // Embedded action thank you share.
        $this->addShareEventInstance($entity, $view_mode);
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
    $args = $this->getEventArgs($entity, $view_mode);
    $event = tp_analytics_event('action_share', $args);
    $this->addFrontEndEventInstance($instance_name, $event);
  }

  public function getActionTakenEventCommand($entity, $view_mode) {
    // TAB - action taken (petitions and pledges) AJAX command.
    $event = tp_analytics_event(
      'action_taken',
      $this->getEventArgs($entity, $view_mode),
      'page',
      "action-taken-node-{$entity->nid}"
    );
    return $this->getFireEventCommand($event);
  }

  public function getSignedEvents($entity, $view_mode, $opt_ins) {
    $events = array();

    $type_name = node_type_get_name($entity);
    $action_name = $type_name . ': ' . check_plain($entity->title);

    $short_names = array(
      'pledge_action' => 'Pledge',
      'petition_action' => 'Petition',
    );
    $type_short_name = $short_names[$entity->type];

    // TAB action taken event.
    //if ($view_mode === 'full') {
      $args = $this->getEventArgs($entity, $view_mode);
      $events[] = tp_analytics_event(
        'action_taken',
        $args,
        'page',
        "action_taken-{$entity->nid}"
      );
    //}

    // Newsletter signup events.
    $settings = entity_load_single('signature_node', $entity->nid);
    foreach ($opt_ins as $delta => $opt_in) {
      if ($opt_in) {
        $events[] = tp_analytics_event(
          "newsletter_action_opt_in",
          array(
            'group' => check_plain($settings->newsletter_opt_ins[$delta]['group']),
            'title' => check_plain($entity->title),
            'view_mode' => $view_mode,
            'type_short_name' => $type_short_name,
            'action_name' => $action_name,
          ),
          'page',
          "newsletter-signup-{$delta}-node-{$entity->nid}"
        );
      }
    }

    return $events;
  }

  protected function getEventArgs($entity, $view_mode) {

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

    if ($view_mode === 'full') {
      $events = array(
        'petition_action' => 'event56,event27',
        'pledge_action' => 'event56,event32',
        'action' => 'event56,event37',
      );
      $completion = 'Action Page Completion';
    }
    /* Remove metrics from embedded tab banners
    else {
      $events = array(
        'petition_action' => 'event64,event27',
        'pledge_action' => 'event64,event32',
        'action' => 'event64,event37',
      );
      $completion = 'Embedded Action Completion';
    } */
    $fired_events = $events[$entity->type];

    $type_name = node_type_get_name($entity);
    $action_name = $type_name . ': ' . check_plain($entity->title);

    return array(
      'fired_events' => $fired_events,
      'type_name' => $type_name,
      'view_mode' => $view_mode,
      'action_name' => $action_name,
      'action_type' => $action_type,
      'topic' => $topic,
      'empowered_by' => $sponsor,
      'completion' => $completion
    );
  }
}

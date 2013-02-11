<?php

class SignatureAnalyticsController extends TakeActionAnalyticsController {

  public function entityView($entity, $view_mode, $langcode) {

    $tracked_views = array('full', 'embedaction', 'embedaction_expanded');
    if (in_array($view_mode, $tracked_views)) {

      // Petition/Pledge action view.
      $event = tp_analytics_event(
        "{$entity->type}_view",
        array(
          'title' => check_plain($entity->title),
          'view_mode' => $view_mode,
        ),
        'session',
        "viewed-signature-action-node-{$entity->nid}-{$view_mode}"
      );
      $this->addPageLoadEvent($event);

      if ($view_mode !== 'full') {
        // Embedded action thank you share.
        $this->addShareEventInstance($entity, $view_mode);
      }

    }

    parent::entityView($entity, $view_mode, $langcode);
  }

  public function getSignedEvents($entity, $view_mode, $opt_ins) {
    $events = array();

    $url = url('node/' . $entity->nid);
    $args = explode("/", $url);
    if (!$args[0]) {
      array_shift($args);
    }

    $title = html_entity_decode($entity->title, ENT_QUOTES);
    $title = strtolower($title);
    $page_name = implode(':', array(
      'takepart',
      $args[0],
      $title,
    ));

    // Petition/pledge signed event.
    $events[] = tp_analytics_event(
      "{$entity->type}_submit",
      array(
        'title' => check_plain($entity->title),
        'view_mode' => $view_mode,
        'page_name' => $page_name,
      ),
      'page',
      "action-submit-node-{$entity->nid}"
    );

    // Newsletter signup events.
    $settings = entity_load_single('signature_node', $entity->nid);
    foreach ($opt_ins as $delta => $opt_in) {
      if ($opt_in) {
        $events[] = tp_analytics_event(
          "{$entity->type}_opt_in",
          array(
            'title' => check_plain($entity->title),
            'view_mode' => $view_mode,
            'page_name' => $page_name,
            'group' => check_plain($settings->newsletter_opt_ins[$delta]['group']),
          ),
          'page',
          "newsletter-signup-{$delta}-node-{$entity->nid}"
        );
      }
    }

    // TAB action taken event.
    if ($view_mode === 'full') {
      $args = $this->getEventArgs($entity);
      $events[] = tp_analytics_event(
        'action_taken',
        $args,
        'page',
        "action_taken-{$entity->nid}"
      );
    }

    return $events;
  }
}

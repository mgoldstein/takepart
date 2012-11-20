<?php

class TakePartAnalyticsController {

  protected $entityType;
  protected $bundle;

  public function __construct($entity_type, $bundle) {
    $this->entityType = $entity_type;
    $this->bundle = $bundle;
  }

  public function addPageLoadEvent($event) {
    // Make sure the event script file and jQuery cookie library will be
    // available.
    if ($event['scope'] === 'session') {
      drupal_add_library('system', 'jquery.cookie');
    }
    drupal_add_js(array('analytics' => array(
     'events' => array($event),
    )), 'setting');
  }

  public function addFrontEndEventInstance($instance_name, $event) {
    // Make sure the event script file and jQuery cookie library will be
    // available.
    if ($event['scope'] === 'session') {
      drupal_add_library('system', 'jquery.cookie');
    }
    drupal_add_js(array('analytics' => array(
     'instances' => array($instance_name => $event),
    )), 'setting');
  }

  public function getFireEventCommand($event) {
    return ajax_command_invoke('body', 'analyticstracking',
      array('fireEvent', $event));
  }

  public function entityView($entity, $view_mode, $langcode) {
    // Add the jQuery cookie library used client side.
    drupal_add_library('system', 'jquery.cookie');
  }
}

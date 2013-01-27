<?php
/**
 * @file
 * Administrative interface for Wordlets
 */

/**
 * Wordlet API UI Controller
 */
class WordletUIController extends EntityDefaultUIController {

  public function hook_menu() {

    $items = array(
      'wordlet/%/word/%wordlet/edit' => array(
        'title' => 'Edit',
        'page callback' => 'drupal_get_form',
        'page arguments' => array('wordlet_edit_form', 3), 
        'access callback' => 'wordlet_access',
        'access arguments' => array('administer'),
        'load arguments' => array(1),
        'weight' => 0,
        'type' => MENU_LOCAL_TASK,
      ),
      'wordlet/%/word/%wordlet/configure' => array(
        'title' => 'Configure',
        'page callback' => 'drupal_get_form',
        'page arguments' => array('wordlet_configure_form', 3), 
        'access callback' => 'wordlet_access',
        'access arguments' => array('administer'),
        'load arguments' => array(1),
        'weight' => 0,
        'type' => MENU_LOCAL_TASK,
      ),
    );

    return $items;
  }
}

function wordlet_edit_form($form, &$form_state, $wordlet) {
  return $form;
}

function wordlet_configre_form($form, &$form_state, $wordlet) {
  return $form;
}

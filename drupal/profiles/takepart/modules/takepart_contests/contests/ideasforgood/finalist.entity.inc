<?php
/**
 * @file
 * Ideas for Good Finalist Entity.
 */

class IdeasForGoodFinalist extends Entity {

  public $vote_accepted = TRUE;

  public function __construct($values = array(),
    $entity_type = 'ideasforgood_finalist') {
    parent::__construct($values, $entity_type);
  }

  protected function defaultUri() {
    $info = $this->entityInfo();
    if (isset($info['admin ui']) && isset($info['admin ui']['path'])) {
      $base = $info['admin ui']['path'];
      return array('path' => $base . '/manage/' . (string) $this->identifier());
    }
    return NULL;
  }

  protected function defaultLabel() {
    return "[{$this->voting_group}] {$this->token}";
  }
}

class IdeasForGoodFinalistController extends EntityAPIController {

  public function create(array $values = array()) {
    $values += array(
      'id' => '',
      'token' => '',
      'voting_group' => '',
      'created' => 0,
      'changed' => 0,
    );
    return parent::create($values);
  }

  public function buildContent($entity, $view_mode = 'full', $langcode = NULL,
    $content = array()) {

    // add in the voting group content
    $content['voting_group'] = ideasforgood_group_content($entity);

    if ($view_mode == 'full') {
      $content += $this->fullViewContent($entity, $view_mode, $langcode, FALSE);
    }
    else if ($view_mode == 'locked') {
      $content += $this->fullViewContent($entity, $view_mode, $langcode, TRUE);
    }
    else if ($view_mode == 'vote') {
      $content += $this->voteViewContent($entity, $view_mode, $langcode);
    }
    else if ($view_mode == 'register') {
      $content += $this->registerViewContent($entity, $view_mode, $langcode);
    }
    else if ($view_mode == 'thankyou') {
      $content += $this->thankYouViewContent($entity, $view_mode, $langcode);
    }
    return parent::buildContent($entity, $view_mode, $langcode, $content);
  }

  protected function fullViewContent($entity, $view_mode, $langcode, $locked) {
    global $user;
    $content = array(
      'voting_locked' => $locked,
    );
    if (!empty($user->uid)) {
      $content['voting_dialog'] = $this->view(array($entity), 'vote');
      $content['voting_dialog_title'] = t('Please Confirm Your Vote');
    }
    else {
      $content['voting_dialog'] = $this->view(array($entity), 'register');
      $content['voting_dialog_title'] = t('Registration Required');
    }
    $content['vote_for_me_button'] = array(
      'off' =>  implode('/', array(
        drupal_get_path('module', 'ideasforgood'),
        'images',
        'vote_button_off.png',
      )),
      'on' => implode('/', array(
        drupal_get_path('module', 'ideasforgood'),
        'images',
        'vote_button_on.png',
      )),
    );
    drupal_add_library('system', 'ui.dialog');
    $path = implode('/', array(
      drupal_get_path('module', 'ideasforgood'),
      'js',
      'jquery.qtip.min.js'
    ));
    drupal_add_js($path, array('group' => JS_DEFAULT, 'type' => 'file'));
    $path = implode('/', array(
      drupal_get_path('module', 'ideasforgood'),
      'js',
      'finalist.js'
    ));
    drupal_add_js($path, array('group' => JS_DEFAULT, 'type' => 'file'));
    $path = implode('/', array(
      drupal_get_path('module', 'ideasforgood'),
      'css',
      'finalist.css'
    ));
    drupal_add_css($path, array('group' => CSS_DEFAULT, 'type' => 'file'));
    return $content;
  }

  protected function voteViewContent($entity, $view_mode, $langcode) {
    return array(
      'vote_form' => drupal_get_form('ideasforgood_vote_form', $entity),
    );
  }

  protected function registerViewContent($entity, $view_mode, $langcode) {

    $pos = strpos($_GET['q'], '?');
    if ($pos === FALSE) {
      $destination = $_GET['q'] . "?selected={$entity->id}";
    }
    else {
      $pieces = explode('?', $_GET['q'], 2);
      $destination = $pieces[0] . "?selected={$entity->id}" . "&" . $pieces[1];
    }

    if (function_exists('_takepart_facebookapis_getfblogin')) {
      $connect_button = _takepart_facebookapis_getfblogin($destination);
    }
    else {
      $connect_src = implode('/', array(
        drupal_get_path('module', 'ideasforgood'),
        'images',
        'sign_up_backup.png',
      ));
      $connect_button = '<a class="ideasforgood-button-link"'
        . ' href="/user/register?destination=' . urlencode($destination) . '">'
        . '<img src="/' . $connect_src . '" alt="Sign Up for Takepart" />'
        . '</a>';
    }

    $cancel_src = implode('/', array(
      drupal_get_path('module', 'ideasforgood'),
      'images',
      'cancel_button.png',
    ));
    $cancel_button = '<img src="/' . $cancel_src . '" alt="Cancel"'
      . 'class="ideasforgood-cancel-button" />';

    return array(
      'connect_button' => $connect_button,
      'cancel_button' => $cancel_button,
      'sign_in_url' => '/user?destination=' . urlencode($destination),
    );
  }

  protected function thankYouViewContent($entity, $view_mode, $langcode) {
    return array(
      'facebook_button' => implode('/', array(
        drupal_get_path('module', 'ideasforgood'),
        'images',
        'facebook_share.png',
      )),
      'twitter_button' => implode('/', array(
        drupal_get_path('module', 'ideasforgood'),
        'images',
        'twitter_share.png',
      )),
      'email_button' => implode('/', array(
        drupal_get_path('module', 'ideasforgood'),
        'images',
        'email_share.png',
      )),
    );
  }

  public function save($entity, DatabaseTransaction $transaction = NULL) {
    // Set/update the created and changed timestamps
    $entity->is_new = isset($entity->is_new) ? $entity->is_new : FALSE;
    if ($entity->is_new) {
      $entity->created = time();
    }
    $entity->changed = time();
    return parent::save($entity, $transaction);
  }
}

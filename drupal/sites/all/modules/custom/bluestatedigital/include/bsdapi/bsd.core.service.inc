<?php
/**
 * @file
 * Blue State Digital Services.
 */

/**
 * Include the signup API class.
 */
include_once dirname(__FILE__) . '/bsd.signup.api.inc';

/**
 * Include the basic cache controller class.
 */
include_once dirname(__FILE__) . '/bsd.cache.inc';

class BlueStateDigitalService {

  protected static $cache = NULL;

  protected $cacheController;
  protected $signupApi;

  public static function init() {
    if (!isset(self::$cache)) {
      self::$cache = new BlueStateDigitalCacheController();
    }
  }

  public function setCacheController($controller) {
    $this->cacheController = $controller;
  }

  public function cacheGet($key, &$value) {
    $cache = $this->cacheController ? $this->cacheController : self::$cache;
    return $cache->get($key, $value);
  }

  public function cacheSet($key, $value) {
    $cache = $this->cacheController ? $this->cacheController : self::$cache;
    return $cache->set($key, $value);
  }

  public function cacheClear() {
    $cache = $this->cacheController ? $this->cacheController : self::$cache;
    return $cache->clear();
  }

  public function __construct($api_id, $api_secret, $rest_method, $request_base,
    $request_timeout = 10) {

    // Use the class wide cache controller by default.
    $cacheController = NULL;

    // The signup API is use by most every service as it is the primary means by
    // which information is submitted to BSD. It is also needed for the core
    // signup form template functionality.
    $this->signupApi = new BlueStateDigitalSignupApi($api_id, $api_secret,
      $rest_method, $request_base, $request_timeout);
  }

  public function listTemplates() {
    return $this->listInstances('Template');
  }

  protected function createName($template, $title = '') {
    return $template . " - " . $title;
  }

  protected function createSlug($template, $ext_id) {
    $prefix = str_replace(" ", "-", strtolower($template));
    return $prefix . "-" . (string) $ext_id;
  }

  protected function listInstances($template) {
    $forms = $this->signupApi->listForms();
    $instances = array();
    $key = $this->createName($template);
    $len = strlen($key);
    foreach ($forms as $id => $form) {
      $name = $form['signup_form_name'];
      if (strlen($name) > $len && substr($name, 0, $len) === $key) {
        $instances[$id] = $form;
      }
    }
    return $instances;
  }

  protected function getInstanceByTitle($template, $title) {
    $key = $this->createName($template, $title);
    $forms = $this->signupApi->listForms();
    foreach ($forms as $id => $form) {
      if ($form['signup_form_name'] === $key) {
        return $form;
      }
    }
    return FALSE;
  }

  protected function getInstanceByExtId($template, $ext_id) {
    $key = $this->createSlug($template, $ext_id);
    $forms = $this->signupApi->listForms();
    foreach ($forms as $id => $form) {
      if ($form['signup_form_slug'] == $key) {
        return $form;
      }
    }
    return FALSE;
  }

  protected function getTemplateId($title) {
    $template = $this->getInstanceByTitle('Template', $title);
    if ($template !== FALSE) {
      return $template['id'];
    }
    return FALSE;
  }

  protected function cloneSignupFromTemplate($template, $title, $ext_id) {
    $template_id = $this->getTemplateId($template);
    if ($template_id !== FALSE) {
      $form_name = $this->createName($template, $title);
      $slug = $this->createSlug($template, $ext_id);
      return $this->signupApi->cloneForm($template_id, $title, $form_name, $slug);
    }
    return FALSE;
  }
}

BlueStateDigitalService::init();

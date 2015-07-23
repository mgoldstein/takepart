<?php

function pm_signup_endpoint_load_by_name($name) {
  return SignupEndpoint::loadByName($name);
}

function pm_signup_endpoint_page_title($endpoint) {
  $title = $endpoint->getLabel();
  return empty($title) ? t('Unlabeled Endpoint') : $title;
}

class SignupEnpointListingPage {

  protected $_records;

  public static function labelForType($type) {
    $labels = array(
      'NewsletterCampaignSignupEndpoint' => 'Newsletter',
      'PartnerOptInSignupEndpoint' => 'Partner',
      'TakePartOptInSignupEndpoint' => 'Action',
    );
    if (isset($labels[$type])) {
      return $labels[$type];
    }
    return $type;
  }

  public function __construct($limit = 25) {
    $types = array(
      'NewsletterCampaignSignupEndpoint',
      'PartnerOptInSignupEndpoint',
      'TakePartOptInSignupEndpoint',
    );
    $data_query = db_select('pm_signup_endpoint', 'ep')
      ->fields('ep', array('id', 'label', 'name', 'type'))
      ->condition('type', $types, 'IN')
      ->orderBy('label');
    $paged_query = $data_query->extend('PagerDefault')->limit($limit);
    $this->_records = $paged_query->execute()->fetchAllAssoc('id');
  }

  public function headers() {
    return array(
      t('ID'),
      t('Type'),
      t('Label'),
      t('Name'),
      array(
        'data' => t('Operations'),
        'colspan' => 2,
      ),
    );
  }

  public function row($record) {
    $path = 'admin/config/signups/endpoints/manage/' . $record->id;
    return array(
      l($record->id, $path),
      self::labelForType($record->type),
      $record->label,
      $record->name,
      l(t('edit'), $path),
      l(t('delete'), $path . '/delete'),
    );
  }

  public function rows() {
    $rows = array();
    foreach ($this->_records as $record) {
      $rows[] = $this->row($record);
    }
    return $rows;
  }

  public function content() {
    return array(
      'table' => array(
        '#theme' => 'table',
        '#header' => $this->headers(),
        '#rows' => $this->rows(),
        '#empty' => t('None.'),
      ),
      'pager' => array('#theme' => 'pager'),
    );
  }
}

function pm_signup_endpoint_listing_page() {
  $page = new SignupEnpointListingPage();
  return $page->content();
}

class SignupEndpointDeleteForm {

  protected $_endpoint;
  protected $_form;

  public function __construct($endpoint) {
    $this->_endpoint = $endpoint;
  }

  public function form($form, &$form_state) {
    $form_state['SignupEndpointDeleteForm'] = $this;
    $question = t('Are you sure you want to delete signup endpoint %label?',
      array('%label' => $this->_endpoint->getLabel())
    );
    return confirm_form($form, $question, 'admin/config/signups/endpoints');
  }

  public static function submit($form, &$form_state) {
    $form_state['SignupEndpointDeleteForm']->_submit($form, $form_state);
  }

  protected function _submit($form, &$form_state) {$this->_endpoint->delete();
    drupal_set_message(t('Signup endpoint %label deleted.', array(
      '%label' => $this->_endpoint->getLabel()
    )));
    $form_state['redirect'] = 'admin/config/signups/endpoints';
  }
}

function pm_signup_endpoint_delete_form($form, &$form_state, $endpoint) {
  $controller = new SignupEndpointDeleteForm($endpoint);
  return $controller->form($form, $form_state);
}

function pm_signup_endpoint_delete_form_submit($form, &$form_state) {
  SignupEndpointDeleteForm::submit($form, $form_state);
}

class SignupEndpointEditForm {

  protected $_endpoint;
  protected $_operation;

  public function __construct($endpoint = NULL, $op = 'add') {
    $this->_endpoint = $endpoint;
    $this->_operation = $op;
  }

  public function workingEndpoint() {
    if (!is_null($this->_endpoint)) {
      return $this->_endpoint;
    }
    static $endpoint = FALSE;
    if ($endpoint === FALSE) {
      $endpoint = new NewsletterCampaignSignupEndpoint();
    }
    return $endpoint;
  }

  public static function types() {
    return array(
      'NewsletterCampaignSignupEndpoint' => t('Newsletter'),
      'PartnerOptInSignupEndpoint' => t('Action Opt-In (Partner)'),
      'TakePartOptInSignupEndpoint' => t('Action Opt-In (TakePart)'),
    );
  }

  public function typeField() {
    return $this->_operation === 'add' ? $this->typeFieldNew()
      : $this->typeFieldExisting();
  }

  public function typeFieldNew() {
    return array(
      '#title' => t('Type'),
      '#description' => t('The type of signup endpoint'),
      '#type' => 'select',
      '#options' => self::types(),
      '#required' => TRUE,
      '#default_value' => 'NewsletterCampaignSignupEndpoint',
    );
  }

  public function typeFieldExisting() {
    $types = self::types();
    return array(
      '#title' => t('Type'),
      '#type' => 'item',
      '#markup' => $types[get_class($this->_endpoint)],
    );
  }

  public function labelField() {
    return array(
      '#title' => t('Label'),
      '#description' => t('The human-readable name of the signup endpoint'),
      '#type' => 'textfield',
      '#required' => TRUE,
      '#size' => 60,
      '#default_value' => $this->workingEndpoint()->getLabel(),
    );
  }

  public function nameField() {
    return array(
      '#title' => t('Name'),
      '#description' => t('A unqiue machine-readable name for this signature type. It must only contain lowercase letters, numbers and underscores.'),
      '#type' => 'machine_name',
      '#maxlength' => 255,
      '#machine_name' => array(
        'exists' => 'pm_signup_endpoint_load_by_name',
        'source' => array('label'),
      ),
      '#default_value' => $this->workingEndpoint()->getName(),
    );
  }

  public function promptField() {
    return array(
      '#title' => t('User Prompt'),
      '#description' => t('Prompt shown to the user.'),
      '#type' => 'text_format',
      '#required' => TRUE,
      '#rows' => 1,
      '#default_value' => $this->workingEndpoint()->getUserPrompt(),
    );
  }

  public function checkedByDefaultField() {
    return array(
      '#title' => t('Checked By Default'),
      '#type' => 'checkbox',
      '#default_value' => $this->workingEndpoint()->getCheckedByDefault(),
    );
  }

  public function handlerClasses() {
    $classes = array();
    $plugins = ctools_get_plugins('pm_signup', 'handler');
    foreach ($plugins as $id => $plugin) {
      $class = ctools_plugin_get_class($plugin, 'handler');
      if (class_exists($class)) {
        $classes[$id] = $class;
      }
    }
    return $classes;
  }

  public static function handlerElement($id, $prop = NULL) {
    $name  = str_replace(array('-', '.'), '_', $id);
    return is_null($prop) ? $name : $name . '_' . $prop;
  }

  public function pluginEnabledField($id, $enabled) {
    return array(
      '#title' => t('Enabled'),
      '#type' => 'checkbox',
      '#default_value' => $enabled,
    );
  }

  public function pluginConfigurationField($id, $configuration) {
    $is_false = $configuration === FALSE;
    $is_array = is_array($configuration);
    $is_empty = empty($configuration);
    $json = ($is_false || ($is_array && $is_empty)) ? ''
      : json_encode($configuration);
    return array(
      '#title' => t('Configuration'),
      '#type' => 'textarea',
      '#default_value' => $json,
      '#rows' => 10,
    );
  }

  public function pluginFieldset($id, $enabled, $configuration) {
    return array(
      '#title' => $id,
      '#type' => 'fieldset',
      self::handlerElement($id, 'enabled')
        => $this->pluginEnabledField($id, $enabled),
      self::handlerElement($id, 'configuration')
        => $this->pluginConfigurationField($id, $configuration),
    );
  }

  public function addHandlerFieldsets(&$form, $endpoint_type) {
    foreach (array_keys($this->handlerClasses()) as $id) {
      $form[self::handlerElement($id)] = $this->pluginFieldset($id,
        $this->workingEndpoint()->getPluginEnabled($id),
        $this->workingEndpoint()->getPluginConfiguration($id)
      );
    }
  }

  public function submitButton($weight = 40) {
    return array(
      '#type' => 'actions',
      'submit' => array(
        '#type' => 'submit',
        '#value' => t('Save endpoint'),
      ),
      '#weight' => $weight,
    );
  }

  public function form($form, &$form_state) {
    $form_state['SignupEndpointEditForm'] = $this;
    $form['submit_top'] = $this->submitButton(-40);
    $form['type'] = $this->typeField();
    $form['label'] = $this->labelField();
    $form['name'] = $this->nameField();
    $form['prompt'] = $this->promptField();
    $form['checked_by_default'] = $this->checkedByDefaultField();
    $this->addHandlerFieldsets($form);
    $form['submit'] = $this->submitButton();
    return $form;
  }

  public static function validate($form, $form_state) {
    $form_state['SignupEndpointEditForm']->_validate($form, $form_state);
  }

  protected function _validateConfiguration($id, $class, $type, $configuration) {
    if (!is_null($configuration)) {
      $errors = $class::validateConfiguration($type, $configuration);
      foreach ($errors as $error) {
        form_set_error(self::handlerElement($id, 'configuration'), $error);
      }
    }
    else {
      form_set_error(self::handlerElement($id, 'configuration'), t(
       'Invalid configuration syntax for %label configuration',
        array('%label' => $id)
      ));
    }
  }

  protected function _validate($form, $form_state) {
    $values = $form_state['values'];
    foreach ($this->handlerClasses() as $id => $class) {
      $json = trim($values[self::handlerElement($id, 'configuration')]);
      $this->_validateConfiguration($id, $class, $values['type'],
        $json === '' ? array() : json_decode($json));
    }
  }

  public static function submit($form, &$form_state) {
    $form_state['SignupEndpointEditForm']->_prepare($form, $form_state);
    $form_state['SignupEndpointEditForm']->_submit($form, $form_state);
  }

  protected function _create($form, $form_state) {
    $type = $form_state['values']['type'];
    if (class_exists($type)) {
      $this->_endpoint = new $type();
    }
  }

  protected function _prepareHandler($id, $values) {
    $enabled = $values[self::handlerElement($id, 'enabled')] ? TRUE : FALSE;
    $this->_endpoint->setPluginEnabled($id, $enabled);
    $json = trim($values[self::handlerElement($id, 'configuration')]);
    $configuration = $json === '' ? array() : json_decode($json);
    $this->_endpoint->setPluginConfiguration($id, $configuration);
  }

  protected function _prepare($form, $form_state) {
    if ($this->_operation === 'add') {
      $this->_create($form, $form_state);
    }
    $values = $form_state['values'];
    $this->_endpoint->labelForExport($values['label'], $values['name']);
    $this->_endpoint->setUserPrompt($values['prompt']);
    $this->_endpoint->setCheckedByDefault($values['checked_by_default']);
    foreach (array_keys($this->handlerClasses()) as $id) {
      $this->_prepareHandler($id, $values);
    }
  }

  protected function _submit($form, &$form_state) {
    $action = is_null($this->_endpoint->getID()) ? 'added' : 'updated';
    $this->_endpoint->save();
    drupal_set_message(t('The signup endpoint %label has been !action.', array(
      '%label' => $this->_endpoint->getLabel(),
      '!action' => $action,
    )));
    $form_state['redirect'] = 'admin/config/signups/endpoints';
  }
}

function pm_signup_endpoint_form($form, &$form_state, $endpoint, $op) {
  $controller = new SignupEndpointEditForm($endpoint, $op);
  return $controller->form($form, $form_state);
}

function pm_signup_endpoint_form_validate($form, $form_state) {
  SignupEndpointEditForm::validate($form, $form_state);
}

function pm_signup_endpoint_form_submit($form, &$form_state) {
  SignupEndpointEditForm::submit($form, $form_state);
}

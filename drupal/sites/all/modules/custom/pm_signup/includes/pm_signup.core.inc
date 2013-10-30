<?php
/**
 * @file
 * Signup data and signup endpoint classes.
 */

/**
 * Common exception for the module.
 */
class SignupException extends Exception {}

class SignupValidationException extends SignupException {
  public $messages;
  public function __construct($messages = array()) {
    parent::__construct("signup validation errors", 0);
    $this->messages = $messages;
  }
}

class SignupSubmissionException extends SignupException {
  public $children;
  public function __construct($children = array()) {
    parent::__construct("signup submission exceptions", 0);
    $this->children = $children;
  }
}

class SignupDuplicateException extends SignupException {
  public $key;
  public function __construct($key) {
    parent::__construct("duplicate signup error", 0);
    $this->key = $key;
  }
}

class SignupNoSuchEndpointException extends SignupException {
  public $endpoint;
  public function __construct($endpoint) {
    parent::__construct("endpoint does not exist", 0);
    $this->endpoint = $endpoint;
  }
}

class SignupHandlerException extends SignupException {}

/**
 * Standard signup field set.
 */
abstract class SignupFieldSet {

  /* Field definitions.
   ****************************************************************************/
  public static function fields() {
    return array();
  }

  public static function requiredFields() {
    return array_filter(static::fields(), 'SignupFieldSet::fieldIsRequired');
  }

  public static function fieldIsRequired($field) {
    return $field['required'];;
  }
}


/**
 * Common signup payload.
 */
abstract class Signup extends SignupFieldSet implements ArrayAccess {

  /* Construction.
   ****************************************************************************/
  protected $values;

  public static function create() {
    $values = array();
    foreach (static::fields() as $name => $field) {
      $values[$name] = $field['default'];
    }
    return new static($values);
  }

  protected function __construct($values = array()) {
    $this->values = $values;
  }


  /* Array access.
   ****************************************************************************/
  public function offsetExists($offset) {
    // The offset must be one of the fields defined when the signup was created.
    if (!is_null($offset) && isset($this->values[$offset])) {
      // An empty string is considered not set.
      return $this->values[$offset] !== '';
    }
    return FALSE;
  }

  public function offsetGet($offset) {
    // The offset must be one of the fields defined when the signup was created.
    if (!is_null($offset) && isset($this->values[$offset])) {
      return $this->values[$offset];
    }
    // Return NULL to indicate that the field isn't even valid.
    return NULL;
  }

  public function offsetSet($offset, $value) {
    // The offset must be one of the fields defined when the signup was created.
    if (!is_null($offset) && isset($this->values[$offset])) {
      // Translate NULLs to empty strings.
      $this->values[$offset] = is_null($value) ? '' : $value;
    }
  }

  public function offsetUnset($offset) {
    // The offset must be one of the fields defined when the signup was created.
    if (!is_null($offset) && isset($this->values[$offset])) {
      // Clear the field value
      $this->values[$offset] = '';
    }
  }


  /* Field access helpers.
   ****************************************************************************/
  public function getFullName() {
    if (isset($this['name.full'])) {
      return $this['name.full'];
    }
    if (isset($this['name.first']) && isset($this['name.last'])) {
      return implode(' ', array($this['name.first'], $this['name.last']));
    }
    return '';
  }

  public function getSanitizedPhoneNumber($use_parts = NULL) {
    // Build it up.
    $sanitized = '';
    if (isset($this['phone-number']) && $use_parts !== TRUE) {
      $number = $this['phone-number'];
      $sanitized = str_replace(array('(',')',' ','-','.'), '', "{$number}");
    }
    elseif (isset($this['phone-number.area-code'])
      && isset($this['phone-number.exchange'])
      && isset($this['phone-number.number'])
      && $use_parts !== FALSE) {
      $sanitized = implode('', array(
        $this['phone-number.area-code'],
        $this['phone-number.exchange'],
        $this['phone-number.number'],
      ));
    }
    // Tear it down.
    $matches = array();
    if (preg_match('/^(\d{3})(\d{3})(\d{4})?$/', $sanitized, $matches) === 1) {
      return array(
        'area-code' => $matches[1],
        'exchange' => $matches[2],
        'number' => $matches[3],
      );
    }
    return FALSE;
  }

  public function getPhoneNumber($delimiter = '-', $use_parts = NULL) {
    $number = $this->getSanitizedPhoneNumber($use_parts);
    if ($number !== FALSE) {
      return implode($delimiter, $number);
    }
    return '';
  }

  public function getAreaCode($use_parts = NULL) {
    $number = $this->getSanitizedPhoneNumber($use_parts);
    if ($number !== FALSE) {
      return $number['area-code'];
    }
    return '';
  }

  public static function stateNames() {
    return array(
      'AL' => 'Alabama',
      'AK' => 'Alaska',
      'AS' => 'American Samoa',
      'AZ' => 'Arizona',
      'AR' => 'Arkansas',
      'CA' => 'California',
      'CO' => 'Colorado',
      'CT' => 'Connecticut',
      'DE' => 'Delaware',
      'DC' => 'District of Columbia',
      'FL' => 'Florida',
      'GA' => 'Georgia',
      'GU' => 'Guam',
      'HI' => 'Hawaii',
      'ID' => 'Idaho',
      'IL' => 'Illinois',
      'IN' => 'Indiana',
      'IA' => 'Iowa',
      'KS' => 'Kansas',
      'KY' => 'Kentucky',
      'LA' => 'Louisiana',
      'ME' => 'Maine',
      'MH' => 'Marshall Islands',
      'MD' => 'Maryland',
      'MA' => 'Massachusetts',
      'MI' => 'Michigan',
      'FM' => 'Micronesia',
      'MN' => 'Minnesota',
      'MS' => 'Mississippi',
      'MO' => 'Missouri',
      'MT' => 'Montana',
      'NE' => 'Nebraska',
      'NV' => 'Nevada',
      'NH' => 'New Hampshire',
      'NJ' => 'New Jersey',
      'NM' => 'New Mexico',
      'NY' => 'New York',
      'NC' => 'North Carolina',
      'ND' => 'North Dakota',
      'MP' => 'Northern Marianas',
      'OH' => 'Ohio',
      'OK' => 'Oklahoma',
      'OR' => 'Oregon',
      'PW' => 'Palau',
      'PA' => 'Pennsylvania',
      'PR' => 'Puerto Rico',
      'RI' => 'Rhode Island',
      'SC' => 'South Carolina',
      'SD' => 'South Dakota',
      'TN' => 'Tennessee',
      'TX' => 'Texas',
      'UT' => 'Utah',
      'VT' => 'Vermont',
      'VI' => 'Virgin Islands',
      'VA' => 'Virginia',
      'WA' => 'Washington',
      'WV' => 'West Virginia',
      'WI' => 'Wisconsin',
      'WY' => 'Wyoming',
    );
  }

  public function getAddressState($use_code = NULL) {
    if (isset($this['address.state']) && $use_code !== TRUE) {
      return $this['address.state'];
    }
    if (isset($this['address.state.code']) && $use_code !== FALSE) {
      $code = $this['address.state.code'];
      $names = self::stateNames();
      return isset($names[$code]) ? $names[$code] : '';
    }
    return '';
  }

  public function getSanitizedZIPCode() {

    // If there is a postal code type, it must be ZIP.
    if (isset($this['address.postal-code.type'])) {
      if ($this['address.postal-code.type'] !== 'ZIP') {
        return FALSE;
      }
    }

    // Build it up.
    $zip_code = $this['address.postal-code'];
    if (isset($this['address.postal-code.plus-four'])) {
      $zip_code .= '-' . $this['address.postal-code.plus-four'];
    }

    // Tear it down.
    $matches = array();
    if (preg_match('/^(\d{5})(-(\d{4}))?$/', $zip_code, $matches) === 1) {
      return array(
        'zip-code' => $matches[1],
        'plus-four' => isset($matches[3]) ? $matches[3] : '',
      );
    }
    return FALSE;
  }

  public function getZIPCode($include_plus_four = TRUE) {
    $zip_code = $this->getSanitizedZIPCode();
    if ($zip_code !== FALSE) {
      if ($include_plus_four && strlen($zip_code['plus-four'])) {
        return implode('-', array(
          $zip_code['zip-code'],
          $zip_code['plus-four'],
        ));
      }
      return $zip_code['zip-code'];
    }
    return '';
  }


  /* Field validation.
   ****************************************************************************/
  public function validEmail() {
    if (isset($this['email'])) {
      return valid_email_address($this['email']);
    }
    return FALSE;
  }

  public function validPhoneNumber($use_parts = NULL) {
    $number = $this->getSanitizedPhoneNumber($use_parts);
    return $number !== FALSE;
  }

  public function validAddressStateCode() {
    if (isset($this['address.state.code'])) {
      $names = self::stateNames();
      return array_key_exists($this['address.state.code'], $names);
    }
    return FALSE;
  }

  public function validZIPCode($require_plus_four = FALSE) {
    $zip_code = $this->getSanitizedZIPCode();
    if ($zip_code !== FALSE && $require_plus_four) {
      return strlen($zip_code['plus-four']) !== 0;
    }
    return $zip_code !== FALSE;
  }

  public function validate() {

    $errors = array();

    // Make sure the signup has all required fields.
    $fields = static::fields();
    foreach ($fields as $name => $field) {
      if ($field['required']) {
        if (!isset($this[$name])) {
          $errors[$name] = $name . ' is required';
        }
      }
    }

    // The email field has additional validation.
    if (isset($this['email'])) {
      if (!$this->validEmail()) {
        $errors['email'] = 'invalid email address';
      }
    }

    // The single phone number field has additional validation.
    if (isset($this['phone-number'])) {
      if (!$this->validPhoneNumber(FALSE)) {
        $errors['phone-number'] = 'invalid phone number';
      }
    }
    $have_phone_parts
      =  isset($this['phone-number.area-code'])
      || isset($this['phone-number.exchange'])
      || isset($this['phone-number.number']);
    if ($have_phone_parts) {
      if (!$this->validPhoneNumber(TRUE)) {
        // Put the error on all the part fields.
        $errors['phone-number.area-code'] = 'invalid phone number';
        $errors['phone-number.exchange'] = 'invalid phone number';
        $errors['phone-number.number'] = 'invalid phone number';
      }
    }

    // The address state code field has additional validation.
    if (isset($this['address.state.code'])) {
      if (!$this->validAddressStateCode()) {
        $errors['address.state.code'] = 'invalid state code';
      }
    }

    // If the postal code type is set to ZIP then additional validation is needed.
    if ($this['address.postal-code.type'] === 'ZIP') {

      $have_postal_code_parts = isset($this['address.postal-code'])
        || isset($this['address.postal-code.plus-four']);
      if ($have_postal_code_parts) {
        $require_plus_four = isset($this['address.postal-code.plus-four']);
        if (!$this->validZIPCode($require_plus_four)) {
          // Put the error on the type field, as it is what is imposing the
          // limitations on the postal code
          $errors['address.postal-code.type'] = 'invalid zip code';
        }
      }
    }

    if (count($errors) > 0) {
      throw new SignupValidationException($errors);
    }
  }

  public function provides() {
    $names = array_keys(static::fields());
    return array_filter($names, array($this, 'offsetExists'));
  }

  public function key() {
    // By default, there is no unique key.
    return array();
  }

  public function key_data() {
    $key_data = array();
    foreach ($this->key() as $field) {
      $key_data[$field] = $this[$field];
    }
    return $key_data;
  }
}

/**
 * Base signup endpoint class.
 */
abstract class SignupEndpoint extends SignupFieldSet {

  /* Storage and retrieval.
   ****************************************************************************/
  protected $id;
  protected $type;

  protected $name;
  protected $label;

  protected $configuration;
  protected $plugins;

  public function __construct($record = NULL) {
    if (!is_null($record)) {
      $this->id = $record->id;
      $this->type = $record->type;
      $this->name = $record->name;
      $this->label = $record->label;
      $this->configuration = unserialize($record->configuration);
      $this->plugins = unserialize($record->plugins);
    }
    else {
      $this->id = NULL;
      $this->type = get_class($this);
      $this->name = NULL;
      $this->label = NULL;
      $this->configuration = array();
      $this->plugins = array();
    }
  }

  public static function load($id) {
    $record = db_select('pm_signup_endpoint', 'ep')
      ->fields('ep')
      ->condition('id', $id)
      ->execute()
      ->fetchObject();
    if ($record !== FALSE) {
      if (class_exists($record->type)) {
        $type = $record->type;
        return new $type($record);
      }
    }
    return FALSE;
  }

  public static function loadByName($name) {
    $record = db_select('pm_signup_endpoint', 'ep')
      ->fields('ep')
      ->condition('name', $name)
      ->execute()
      ->fetchObject();
    if ($record !== FALSE) {
      if (class_exists($record->type)) {
        $type = $record->type;
        return new $type($record);
      }
    }
    return FALSE;
  }

  public function save() {
    if (isset($this->id)) {
      return db_update('pm_signup_endpoint')
        ->fields(array(
          'type' => $this->type,
          'name' => $this->name,
          'label' => $this->label,
          'configuration' => serialize($this->configuration),
          'plugins' => serialize($this->plugins),
        ))
        ->condition('id', $this->id)
        ->execute();
    }
    else {
      db_insert('pm_signup_endpoint')
        ->fields(array(
          'type' => $this->type,
          'name' => $this->name,
          'label' => $this->label,
          'configuration' => serialize($this->configuration),
          'plugins' => serialize($this->plugins),
        ))
        ->execute();
      $this->id = Database::getConnection()->lastInsertId();
    }
  }

  public static function deleteByID($type, $id) {
    db_delete('pm_signup_endpoint')
      ->condition('id', $id)
      ->condition('type', $type)
      ->execute();
  }

  public function delete() {
    if (isset($this->id)) {
      db_delete('pm_signup_endpoint')
        ->condition('id', $this->id)
        ->execute();
    }
  }

  public function getID() {
    return $this->id;
  }

  public function getLabel() {
    return $this->label;
  }

  public function getName() {
    return $this->name;
  }

  public function labelForExport($label, $name = NULL) {
    // Build a machine name if one wasn't provided.
    if (is_null($name) && !is_null($label)) {
      $lowered = strtolower($label);
      $underlined = preg_replace('/[^a-z0-9_]+/', '_', $lowered);
      $deduped = preg_replace('/__+/', '_', $underlined);
      $name = trim($deduped, '_');
    }
    $this->label = $label;
    $this->name = $name;
  }

  public function clearExportLabel() {
    $this->label = NULL;
    $this->name = NULL;
  }

  public function getConfiguration() {
    return $this->configuration;
  }

  public function setConfiguration($configuration) {
    $this->configuration = $configuration;
  }

  public function getPluginEnabled($id) {
    if (isset($this->plugins[$id])) {
      return $this->plugins[$id]['enabled'];
    }
    return FALSE;
  }

  public function setPluginEnabled($id, $enabled) {
    if (isset($this->plugins[$id])) {
      $this->plugins[$id]['enabled'] = $enabled;
    }
    else {
      $this->plugins[$id] = array(
        'enabled' => $enabled,
        'configuration' => array(),
      );
    }
  }

  public function getPluginConfiguration($id) {
    if (isset($this->plugins[$id])) {
      return $this->plugins[$id]['configuration'];
    }
    return FALSE;
  }

  public function setPluginConfiguration($id, $configuration) {
    if (isset($this->plugins[$id])) {
      $this->plugins[$id]['configuration'] = $configuration;
    }
    else {
      $this->plugins[$id] = array(
        'enabled' => TRUE,
        'configuration' => $configuration,
      );
    }
  }


  /* Signup processing.
   ****************************************************************************/
  protected function validate($signup) {

    // Make sure the signup provides all required fields
    $required = array_keys(static::requiredFields());
    $provided = $signup->provides();
    $missing = array_diff($required, $provided);
    if (count($missing) > 0) {
      $errors = array();
      foreach ($missing as $name) {
        $errors[$name] = $name . ' not provided to endpoint';
      }
      throw new SignupValidationException($errors);
    }
  }

  protected function limit($signup) {

    $key = $signup->key_data();
    if (!empty($key)) {
      $record = db_select('pm_signup_ledger', 'sl')
        ->fields('sl')
        ->condition('type', get_class($signup))
        ->condition('signup_key', implode(':', $key))
        ->execute()
        ->fetchObject();
      if ($record !== FALSE) {
        throw new SignupDuplicateException($key);
      }
    }
  }

  protected function record($signup) {
    $key = $signup->key_data();
    if (!empty($key)) {
      db_insert('pm_signup_ledger')
        ->fields(array(
          'type' => get_class($signup),
          'signup_key' => implode(':', $key),
          'created' => REQUEST_TIME,
        ))
        ->execute();
    }
  }

  public function submit($signup) {

    $this->validate($signup);

    $this->limit($signup);

    $plugins = ctools_get_plugins('pm_signup', 'handler');
    $errors = array();
    foreach ($plugins as $id => $plugin) {

      if ($this->getPluginEnabled($id)) {

        $class = ctools_plugin_get_class($plugin, 'handler');
        if (class_exists($class)) {

          // Get the plugins configuration.
          $configuration = $this->getPluginConfiguration($id);

          // Create the handler
          $handler = new $class($plugin, $configuration);

          // Submit the signup
          try {
            $handler->submit($signup);
          }
          catch (SignupHandlerException $she) {
            if (variable_get('pm_signup_log', FALSE)) {
              db_insert('pm_signup_log')
                ->fields(array(
                  'handler' => $id,
                  'message' => $she->getMessage(),
                  'exception' => print_r($she, true),
                  'backtrace' => print_r(debug_backtrace(), true),
                  'created' => REQUEST_TIME,
                ))
                ->execute();
            }
            $errors[] = $she;
          }
        }
      }
    }

    if (count($errors) > 0) {
      throw new SignupSubmissionException($errors);
    }

    $this->record($signup);
  }


  /* Features export and (re)build.
   ****************************************************************************/
  public function exportToFeature() {
    return array(
      'type' => $this->type,
      'name' => $this->name,
      'label' => $this->label,
      'configuration' => $this->configuration,
      'plugins' => $this->plugins,
    );
  }

  public function rebuildFromFeature($item) {
    $this->type = $item['type'];
    $this->name = $item['name'];
    $this->label = $item['label'];
    $this->configuration = $item['configuration'];
    $this->plugins = $item['plugins'];
  }
}

class DefaultSignupEndpoint extends SignupEndpoint {}

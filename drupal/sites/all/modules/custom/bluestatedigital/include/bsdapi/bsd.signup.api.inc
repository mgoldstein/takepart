<?php
/**
 * @file
 * Blue State Digital Signup API.
 */

/**
 * Include the core API class.
 */
include_once dirname(__FILE__) . '/bsd.core.api.inc';

class BlueStateDigitalSignupApi extends BlueStateDigitalApi {

  /**
   * Get a list of all signup forms.
   *
   * @return array
   *   An associative array of signup form descriptions keyed by signup form
   *   ID. Each signup form description contains:
   *   - id: Integer id of the signup form.
   *   - signup_form_slug: String used to generate the signup form URL.
   *   - signup_form_name: String used for the internal name of the signup
   *     form.
   *   - form_public_title: String title for the signup form, displayed in the
   *     user's browser title bar.
   *   - create_dt: String created timestamp of the signup form.
   *   - modified_dt: String last modified timestamp of the signup form.
   *
   * @throws BlueStateDigitalApiException
   */
  public function listForms() {

    // Request for the form list.
    $response = $this->callAPI('signup/list_forms');

    // Check the response code.
    if ($response['http_code'] != self::HTTP_CODE_OK) {
      throw new BlueStateDigitalApiException(
        'Unexpected response status code.' . print_r($response, TRUE),
        BlueStateDigitalApiException::FAILED_RESPONSE_CODE,
        $response['http_code'], $response['body']);
    }

    // Parse the response body.
    $api = simplexml_load_string($response['body']);
    if ($api === FALSE) {
      throw new BlueStateDigitalApiException(
        'Unable to parse XML response.',
        BlueStateDigitalApiException::INVALID_RESPONSE_BODY,
        $response['http_code'], $response['body']);
    }

    // Build the list of forms.
    $forms = array();
    foreach ($api as $signup_form) {
      $key = (int) $signup_form->attributes()->id;
      $forms[$key] = array(
        'id' => $key,
        'signup_form_slug' => (string) $signup_form->signup_form_slug,
        'signup_form_name' => (string) $signup_form->signup_form_name,
        'form_public_title' => (string) $signup_form->form_public_title,
        'create_dt' => $this->convertTimestamp(
          (string) $signup_form->create_dt),
        'modified_dt' => $this->convertTimestamp(
          (string) $signup_form->attributes()->modified_dt),
      );
    }

    return $forms;
  }

  /**
   * Get a list of all form fields for a signup form.
   *
   * @param int $signup_form_id
   *   The signup form ID that is being queried.
   *
   * @return array
   *   An associative array of signup form field descriptions keyed by signup
   *   form ID. Each signup form description contains:
   *   - id: Integer id of the signup form field.
   *   - label: String label for the signup form field.
   *   - description: String description of the signup form field.
   *   - display_order: Integer index of the signup form field in the signup
   *     form.
   *   - is_shown: Integer indicating if the signup form field is shown:
   *     0 = not shown, 1 = shown.
   *   - is_required: Integer indicating if the signup form field is required:
   *     0 = not required, 1 = required.
   *   - is_custom_field: Integer indicating if the signup form field is a
   *     strandard field on every signup form, or a custom field: 0 = standard,
   *     1 = custom.
   *   - created_dt: String created timestamp of the signup form field.
   *   - cons_field_id: Integer constituent field ID if the field is a
   *     constituent field, 0 otherwise.
   *
   * @throws BlueStateDigitalApiException
   */
  public function listFormFields($signup_form_id) {

    // Request the field list.
    $response = $this->callAPI('signup/list_form_fields',
      array('signup_form_id' => $signup_form_id));

    // Check the response code.
    if ($response['http_code'] != self::HTTP_CODE_OK) {
      throw new BlueStateDigitalApiException(
        'Unexpected response status code.',
        BlueStateDigitalApiException::FAILED_RESPONSE_CODE,
        $response['http_code'], $response['body']);
    }

    // Parse the response body.
    $api = simplexml_load_string($response['body']);
    if ($api === FALSE) {
      throw new BlueStateDigitalApiException(
        'Unable to parse XML response.',
        BlueStateDigitalApiException::INVALID_RESPONSE_BODY,
        $response['http_code'], $response['body']);
    }

    // Build the field list.
    $fields = array();
    foreach ($api as $signup_form_field) {
      $key = (int) $signup_form_field->attributes()->id;
      $fields[$key] = array(
        'id' => $key,
        'label' => (string) $signup_form_field->label,
        'description' => (string) $signup_form_field->description,
        'display_order' => (int) $signup_form_field->display_order,
        'is_shown' => (int) $signup_form_field->is_shown,
        'is_required' => (int) $signup_form_field->is_required,
        'is_custom_field' => (int) $signup_form_field->is_custom_field,
        'create_dt' => $this->convertTimestamp(
          (string) $signup_form_field->create_dt),
        'cons_field_id' => (int) $signup_form_field->cons_field_id,
      );
    }

    return $fields;
  }

  /**
   * Parse the response to the signup_count API call.
   *
   * @param array $response
   *   An associative array containing:
   *   - http_code: Integer HTTP code of the response.
   *   - body: String body of the the response.
   *
   * @return int
   *   Integer signup count.
   *
   * @throws BlueStateDigitalApiException
   */
  protected function parseSignupCountResponse($response) {

    // Check the response code.
    if ($response['http_code'] != self::HTTP_CODE_OK) {
      throw new BlueStateDigitalApiException(
        'Unexpected response status code.',
        BlueStateDigitalApiException::FAILED_RESPONSE_CODE,
        $response['http_code'], $response['body']);
    }

    // Parse the response body.
    $api = simplexml_load_string($response['body']);
    if ($api === FALSE) {
      throw new BlueStateDigitalApiException(
        'Unable to parse XML response.',
        BlueStateDigitalApiException::INVALID_RESPONSE_BODY,
        $response['http_code'], $response['body']);
    }

    // Return the signup count.
    return (int) $api->count;
  }

  /**
   * Get the number of signups for a signup form, optionally limiting the count.
   *
   * @param int $signup_form_id
   *   The signup form ID that is being queried.
   * @param array $required_field_ids
   *   An array of integer signup form field IDs that must have a value for
   *   the signup to be counted.
   * @param array $excluded_field_ids
   *   An array of integer signup form field IDs that must NOT have a value
   *   for the signup to be counted.
   * @param boolean $block
   *   TRUE: Wait for the deferred result, then return the signup count.
   *   FALSE: Do not wait for the deferred result, immediately return the
   *   deferred result ID.
   *
   * @return int|string
   *   The return value depends on the $block parameter.
   *   - TRUE: Integer count of signups that meet the selection criteria
   *     specified by $signup_form_field_ids.
   *   - FALSE: String deferred result ID.
   *
   * @throws BlueStateDigitalApiException
   */
  public function signupCount($signup_form_id, $required_field_ids = array(),
    $excluded_field_ids = array(), $block = TRUE) {

    // Convert the required form field IDs to strings.
    $required = array_map('strval', $required_field_ids);

    // Add *'s to all the excluded form field IDs.
    $excluded = array();
    foreach ($excluded_field_ids as $field_id) {
      $excluded[] = "{$field_id}*";
    }

    // Build the request.
    $params = array('signup_form_id' => $signup_form_id);
    $criteria = $required + $excluded;
    if (!empty($criteria)) {
      $params['signup_form_field_ids'] = implode(',', $criteria);
    }

    // Make the request.
    $response = $this->callDeferredAPI('signup/signup_count', $params, NULL,
      $block);

    if ($block) {
      return $this->parseSignupCountResponse($response);
    }
    return $response;
  }

  /**
   * Get the deferred result of a non-blocking call to signup_count.
   *
   * @param string $deferred_id
   *   The string deferred ID from the original request.
   *
   * @return int|boolean
   *   Integer count of signups that meet the selection criteria specified in
   *   the original call to signup_count, or FALSE if the deferred result is
   *   stil being compiled.
   *
   * @see signupCount()
   */
  public function signupCountDeferred($deferred_id) {
    $response = $this->getDeferredResult($deferred_id);
    if ($response !== FALSE) {
      return $this->parseSignupCountResponse($response);
    }
    return $response;
  }

  /**
   * Get the number of signups for a signup form using the /utils/cons_counter
   * URL instead of the deferred API call.
   *
   * @param int $signup_form_id
   *   The signup form ID that is being queried.
   *
   * @throws BlueStateDigitalApiException
   */
  public function signupCountUtil($signup_form_id) {

    $components = parse_url($this->httpRequestBase);
    $components['path'] = "/utils/cons_counter/signup_counter.ajax.php";
    $components['query'] = "signup_form_id={$signup_form_id}";

    $url = implode('', array(
      $components['scheme'],
      '://',
      $components['host'],
      $components['path'],
      '?',
      $components['query'],
    ));

    // Send the request.
    if ($this->restMethod == self::REST_METHOD_STREAM_WRAPPER) {
      $response = $this->streamWrapper($url);
    }
    else /* self::REST_METHOD_CURL */ {
      $response = $this->curl($url);
    }

    // Check the response code.
    if ($response['http_code'] != self::HTTP_CODE_OK) {
      throw new BlueStateDigitalApiException(
        'Unexpected response status code.',
        BlueStateDigitalApiException::FAILED_RESPONSE_CODE,
        $response['http_code'], $response['body']);
    }

    return (int) $response['body'];
  }

  /**
   * Parse the response to the count_by_field API call.
   *
   * @param array $response
   *   An associative array containing:
   *   - http_code: Integer HTTP code of the response.
   *   - body: String body of the the response.
   *
   * @return array
   *   An associative array of the counts for each value in the field keyed
   *   by value.
   *
   * @throws BlueStateDigitalApiException
   */
  protected function parseCountByFieldResponse($response) {

    // Check the response code.
    if ($response['http_code'] != self::HTTP_CODE_OK) {
      throw new BlueStateDigitalApiException(
        'Unexpected response status code.',
        BlueStateDigitalApiException::FAILED_RESPONSE_CODE,
        $response['http_code'], $response['body']);
    }

    // Parse the response body.
    $api = simplexml_load_string($response['body']);
    if ($api === FALSE) {
      throw new BlueStateDigitalApiException(
        'Unable to parse XML response.',
        BlueStateDigitalApiException::INVALID_RESPONSE_BODY,
        $response['http_code'], $response['body']);
    }

    // Build the count list.
    $counts = array();
    foreach ($api as $field) {
      $key = (string) $field->value;
      $counts[$key] = (int) $field->count;
    }

    return $counts;
  }

  /**
   * Get the number of signups per value for a signup form field.
   *
   * @param int $signup_form_id
   *   The signup form ID that is being queried.
   * @param int $signup_form_field_id
   *   The ID of the field on the signup form.
   * @param boolean $block
   *   TRUE: Wait for the deferred result, then return the signup counts.
   *   FALSE: Do not wait for the deferred result, immediately return the
   *   deferred result ID.
   *
   * @return array|string:
   *   The return value depends on the $block parameter.
   *   - $block == TRUE: An associative array of the counts for each value in
   *     the field keyed by value.
   *   - $block == FALSE: String deferred result ID.
   *
   * @throws BlueStateDigitalApiException
   */
  public function countByField($signup_form_id, $signup_form_field_id,
    $block = TRUE) {

    // Build the request.
    $params = array(
      'signup_form_id' => $signup_form_id,
      'signup_form_field_id' => $signup_form_field_id,
    );

    // Make the request.
    $response = $this->callDeferredAPI('signup/count_by_field', $params, NULL,
      $block);

    if ($block) {
      return $this->parseCountByFieldResponse($response);
    }
    return $response;
  }

  /**
   * Get the deferred result of a non-blocking call to count_by_field().
   *
   * @param string $deferred_id
   *   The string deferred ID from the original request.
   *
   * @return array
   *   An associative array of the counts for each value in the the field,
   *   keyed by the value, or FALSE if the deferred result is still being
   *   compiled.
   *
   * @see countByField()
   */
  public function countByFieldDeferred($deferred_id) {
    $response = $this->getDeferredResult($deferred_id);
    if ($response !== FALSE) {
      return $this->parseCountByFieldResponse($response);
    }
    return $response;
  }

  /**
   * Send a signup to Blue State Digital.
   *
   * Signups processed through the API may contain multiple signup forms in a
   * single request. The structure of a single signup form data array in the
   * $signup parameter is comatible with the field list returned by
   * list_form_fields().
   *
   * Example:
   *
   * @code
   * $signup = array(
   *   1 => array(            // Signup Form 1
   *     100 => array(        // Signup Field 100
   *       'value' => array(
   *         'type' => 'value',
   *         'value' => 'Some Value'
   *       ),
   *     ),
   *     101 => array(        // Signup Field 101
   *       'value' => array(
   *         'type' => 'items',
   *         'items' => array(
   *           'Item 1',
   *           'Item 2',
   *           'Item 3',
   *         ),
   *       ),
   *     ),
   *   ),
   *   2 => array(            // Signup Form 2
   *     200 => array(        // Signup Field 200
   *       'value' => array(
   *         'type' => 'file',
   *         'filename' => 'some_file.bin',
   *         'data' => 'U2FtcGxlIERhdGE=',
   *       ),
   *     ),
   *   ),
   * );
   * $api->process_signup($signup);
   * @endcode
   *
   * @param array $signup
   *   An associative array of signup form data arrays keyed by signup form ID.
   *   Each signup form data array is an associative array of signup form field
   *   values keyed by signup form field ID. Each signup form field value is an
   *   associative array containing the following:
   *   - value: An associative array containing
   *     - type: The type of value, one of: value, items, or file.
   *     - value: A string value (only used when type == value).
   *     - items: An array of string values (only used when type == items).
   *     - data: Base64 encoded file data (only used when type == file).
   *     - filename: String filename for the file data (only used when type
   *       == file).
   *
   * @throws BlueStateDigitalApiException
   *
   * @see listFormFields()
   */
  public function processSignup($signup) {

    // Build the request.
    $api = new SimpleXMLElement(
      '<?xml version="1.0" encoding="utf-8"?><api></api>');
    foreach ($signup as $form_id => $fields) {

      $signup_form = $api->addChild('signup_form');
      $signup_form->addAttribute('id', $form_id);

      foreach ($fields as $field_id => $field) {

        // Use only those fields that have a value set, this is done o allow the
        // user to reuse the form field list returned by listFormFields.
        if (isset($field['value'])) {

          $value = $field['value'];
          switch ($value['type']) {

            case 'value':
              $signup_field = $signup_form->addChild('signup_form_field',
                $value['value']);
              $signup_field->addAttribute('id', $field_id);
              break;

            case 'items':
              $signup_field = $signup_form->addChild('signup_form_field');
              $signup_field->addAttribute('id', $field_id);
              $items = $signup_field->addChild('items');
              foreach ($value['items'] as $item) {
                $items->addChild('item', $item);
              }
              break;

            case 'file':
              $signup_field = $signup_form->addChild('signup_form_field');
              $signup_field->addAttribute('id', $field_id);
              $file = $signup_field->addChild('file');
              $file->addChild('filename', $value['filename']);
              $file->addChild('data', $value['data']);
              break;
          }
        }
      }
    }

    // Send the signup.
    $response = $this->callAPI('signup/process_signup', array(), $api->asXML());

    // Check the response code.
    if ($response['http_code'] != self::HTTP_CODE_OK) {
      throw new BlueStateDigitalApiException(
        'Unexpected response status code.',
        BlueStateDigitalApiException::FAILED_RESPONSE_CODE,
        $response['http_code'], $response['body']);
    }
  }

  public static function signupValue($value) {
    return array(
      'value' => array(
        'type' => 'value',
        'value' => $value,
      ),
    );
  }

  public static function signupItems($items) {
    return array(
      'value' => array(
        'type' => 'items',
        'items' => $items,
      ),
    );
  }

  public static function signupFile($filename, $data) {
    return array(
      'value' => array(
        'type' => 'file',
        'filename' => $filename,
        'data' => $data,
      ),
    );
  }

  /**
   * Parse the response to the get_signups_by_email and get_signups_by_form_id
   * API calls.
   *
   * @param array $response
   *   An associative array containing:
   *   - http_code: Integer HTTP code of the response.
   *   - body: String body of the the response.
   *
   * @return array
   *   An array of the signups for the provided query parameter.
   *
   * @throws BlueStateDigitalApiException
   */
  protected function parseSignupListResponse($response) {

    // Check the response code.
    if ($response['http_code'] != self::HTTP_CODE_OK) {
      throw new BlueStateDigitalApiException(
        'Unexpected response status code.',
        BlueStateDigitalApiException::FAILED_RESPONSE_CODE,
        $response['http_code'], $response['body']);
    }

    // Parse the response body.
    $api = simplexml_load_string($response['body']);
    if ($api === FALSE) {
      throw new BlueStateDigitalApiException(
        'Unable to parse XML response.',
        BlueStateDigitalApiException::INVALID_RESPONSE_BODY,
        $response['http_code'], $response['body']);
    }

    // Fields
    $signup_field = array(
      'stg_signup_id' => 'integer',
      'signup_form_id' => 'integer',
      'cons_upload_id' => 'integer',
      'stg_invitation_id' => 'integer',
      'cons_source_id' => 'integer',
      'ext_id' => 'integer',
      'ext_type' => 'string',
      'mailing_recipient_id' => 'integer',
      'mailing_link_id' => 'integer',
      'stg_contribution_id' => 'integer',
      'spk_letter_id' => 'integer',
      'email' => 'string',
      'work_email' => 'string',
      'email_opt_in' => 'boolean',
      'prefix' => 'string',
      'firstname' => 'string',
      'middlename' => 'string',
      'lastname' => 'string',
      'suffix' => 'string',
      'salutation' => 'string',
      'gender' => 'string',
      'birth_dt' => 'date',
      'title' => 'string',
      'employer' => 'string',
      'occupation' => 'string',
      'income' => 'string',
      'mobile_opt_in' => 'boolean',
      'mobile' => 'string',
      'phone' => 'string',
      'work_phone' => 'string',
      'fax' => 'string',
      'addr1' => 'string',
      'addr2' => 'string',
      'addr3' => 'string',
      'city' => 'string',
      'state_cd' => 'string',
      'zip' => 'string',
      'zip_4' => 'string',
      'country' => 'string',
      'transaction_amt' => 'string',
      'transaction_dt' => 'date',
      'contribution_status' => 'string',
      'source' => 'string',
      'subsource' => 'string',
      'is_contrib_recurring' => 'boolean',
      'opt_in' => 'boolean',
      'create_dt' => 'date',
      'create_app' => 'string',
      'create_user' => 'string',
      'create_ip_addr' => 'string',
      'create_user_agent' => 'string',
      'status' => 'integer',
      'note' => 'integer',
      'chapter_id' => 'integer',
    );

    $signups = array();
    foreach ($api->stg_signups->children() as $node) {

      // Extract the core fields of the signup.
      $signup = array();
      foreach ($signup_field as $name => $type) {
        switch ($type) {
        case 'string':
          $signup[$name] = (string) $node->{$name};
          break;
        case 'integer':
          $signup[$name] = (int) $node->{$name};
          break;
        case 'boolean':
          $signup[$name] = (int) $node->{$name} ? TRUE : FALSE;
          break;
        case 'date':
          $signup[$name] = $this->convertTimestamp(
            (string) $node->{$name});
          break;
        }
      }

      // Extract the extra fields (and values) of the signup.
      // TODO: Extend this to support lists and file uploads
      $signup['extra_fields'] = array();
      foreach ($node->xpath('stg_signup_extra') as $extra) {
        $id = (int) $extra->signup_form_field_id;
        $signup['extra_fields'][$id] = array(
          'varchar' => (string) $extra->stg_signup_extra_value->value_varchar,
          'text' => (string) $extra->stg_signup_extra_value->value_text,
        );
      }

      // Add the signup to the list.
      $signups[] = $signup;
    }

    return $signups;
  }

  public function getSignupsByEmail($email) {

     // Request the field list.
    $response = $this->callAPI('signup/get_signups_by_email',
      array('email' => $email));

    return $this->parseSignupListResponse($response);
  }

  public function getSignupsByFormId($signup_form_id) {

     // Request the field list.
    $response = $this->callAPI('signup/get_signups_by_form_id',
      array('signup_form_id' => $signup_form_id));

    return $this->parseSignupListResponse($response);
  }

  public function cloneForm($signup_form_id, $title, $signup_form_name, $slug) {

    // Build the request.
    $data = http_build_query(array(
      'signup_form_id' => $signup_form_id,
      'title' => $title,
      'signup_form_name' => $signup_form_name,
      'slug' => $slug,
    ));

    // Make the request.
    $response = $this->callAPI('signup/clone_form', array(), $data);

    // Check the response code.
    if ($response['http_code'] != self::HTTP_CODE_OK) {
      throw new BlueStateDigitalApiException(
        'Unexpected response status code.',
        BlueStateDigitalApiException::FAILED_RESPONSE_CODE,
        $response['http_code'], $response['body']);
    }

    // Parse the response body.
    $api = simplexml_load_string($response['body']);
    if ($api === FALSE) {
      throw new BlueStateDigitalApiException(
        'Unable to parse XML response.',
        BlueStateDigitalApiException::INVALID_RESPONSE_BODY,
        $response['http_code'], $response['body']);
    }

    // Return the new signup form id.
    return (int) $api->signup_form->id;
  }

  public function setFormConsGroup($signup_form_id, $cons_group_id) {

    // Build the request.
    $data = http_build_query(array(
      'signup_form_id' => $signup_form_id,
      'cons_group_id' => $cons_group_id,
    ));

    // Make the request.
    $response = $this->callAPI('signup/set_cons_group', array(), $data);

    // The API call does not return a value
    $this->checkNoContentResponse($response, self::HTTP_CODE_OK);
  }

  public function setFieldConsGroup($signup_form_field_id, $cons_group_id) {

    // Build the request.
    $data = http_build_query(array(
      'signup_form_field_id' => $signup_form_field_id,
      'cons_group_id' => $cons_group_id,
    ));

    // Make the request.
    $response = $this->callAPI('signup/set_cons_group', array(), $data);

    // The API call does not return a value
    $this->checkNoContentResponse($response, self::HTTP_CODE_OK);
  }
}

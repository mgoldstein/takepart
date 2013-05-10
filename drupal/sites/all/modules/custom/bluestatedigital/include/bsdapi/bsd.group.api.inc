<?php
/**
 * @file
 * Blue State Digital Constituent Group API.
 */

/**
 * Include the core API class.
 */
include_once dirname(__FILE__) . '/bsd.core.api.inc';

class BlueStateDigitalConstituentGroupApi extends BlueStateDigitalApi {

  /**
   * Parse a list of constituent groups response.
   *
   * @param array $response
   *   An associative array containing the following:
   *   - http_code: The integer HTTP status code of the response.
   *   - body: The string body of the response.
   *
   * @return array
   *   An associative array of constituent group records, keyed by group id.
   *   Each group record is an associative array containing:
   *   - id: The group's ID
   *   - modified_dt: Timestamp of when the group was last modified.
   *   - name: The name of the group.
   *   - slug:
   *   - description: A description of the group.
   *   - is_banned:
   *   - create_dt: Timestamp of when the group was created.
   *   - group_type: The type of group.
   *   - members:
   *   - unique_emails:
   *   - unique_emails_subscribed:
   *   - count_dt:
   *
   * @throws BlueStateDigitalApiException
   */
  protected function parseGroupListResponse($response) {

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

    // Build the list of groups.
    $groups = array();
    foreach ($api as $group) {
      $key = (int) $group->attributes()->id;
      $groups[$key] = array(
        'id' => $key,
        'modified_dt' => $this->convertTimestamp(
          (string) $group->attributes()->modified_dt),
        'name' => (string) $group->name,
        'slug' => (string) $group->slug,
        'description' => (string) $group->description,
        'is_banned' => (string) $group->is_banned,
        'create_dt' => $this->convertTimestamp((string) $group->create_dt),
        'group_type' => (int) $group->group_type,
        'members' => (int) $group->members,
        'unique_emails' => (int) $group->unique_emails,
        'unique_emails_subscribed' => (int) $group->unique_emails_subscribed,
        'count_dt' => $this->convertTimestamp((string) $group->count_dt),
      );
    }

    return $groups;
  }

  /**
   * Get a list of constituent groups.
   *
   * @return array
   *   An associative array of constituent group records as returned by
   *   parseGroupListResponse().
   *
   * @see parseGroupListResponse()
   */
  public function listConstituentGroups() {

    // Make the request.
    $response = $this->callAPI('cons_group/list_constituent_groups');

    // Parse and return the response.
    return $this->parseGroupListResponse($response);
  }

  /**
   * Get a single constituent group.
   *
   * @param int $cons_group_id
   *   The id of the group to retrieve.
   *
   * @return array|boolean
   *   The first (and only) group record as returned by parseGroupListResponse()
   *   or FALSE if no group was found.
   *
   * @see parseGroupListResponse()
   */
  public function getConstituentGroup($cons_group_id) {

    // Make the request.
    $response = $this->callAPI('cons_group/get_constituent_group',
      array('cons_group_id' => $cons_group_id));

    // Parse the response to a list, then return the first item.
    $groups = $this->parseGroupListResponse($response);
    return reset($groups);
  }

  /**
   * Create one or more constituent groups.
   *
   * @param array $group_names
   *   A list of the names for the groups.
   *
   * @return array
   *   A list of group records as returned by parseGroupListResponse().
   *
   * @see parseGroupListResponse()
   */
  public function addConstituentGroups($group_names) {

    // Build the request.
    $api = new SimpleXMLElement(
      '<?xml version="1.0" encoding="utf-8"?><api></api>');
    foreach ($group_names as $name) {
      $cons_group = $api->addChild('cons_group');
      $cons_group->addChild('name', $name);
    }

    // Make the request.
    $response = $this->callAPI('cons_group/add_constituent_groups', array(),
      $api->asXML());

    // Parse and return the response.
    return $this->parseGroupListResponse($response);
  }

  /**
   * Rename an existing constituent group.
   *
   * @param int $cons_group_id
   *   The id of the constituent group to rename.
   * @param string $new_name
   *   The new name of the constituent group.
   */
  public function renameGroup($cons_group_id, $new_name) {

    // Build the request.
    $data = http_build_query(array(
      'cons_group_id' => $cons_group_id,
      'new_name' => $new_name,
    ));

    // Make the request.
    $response = $this->callAPI('cons_group/rename_group', array(), $data);

    $this->checkNoContentResponse($response);
  }

  /**
   * Delete one or more constituent groups.
   *
   * @param array $cons_group_ids
   *   An array of constituent group ids to delete.
   * @param boolean $block
   *   (optional) Boolean flag for controlling whether the call blocks until the
   *   result is ready, defaults to TRUE.
   *   - TRUE: block until the result is ready.
   *   - FALSE: immediately return the deferred id.
   *
   * @return boolean|string
   *   The return values depends on the $block parameter.
   *   - TRUE: A boolean TRUE value.
   *   - FALSE: A string deferred id for retrieving the results at a later time.
   *
   * @see BlueStateDigitalApi::checkNoContentResponse()
   */
  public function deleteConstituentGroups($cons_group_ids, $block = TRUE) {

    // Build the request.
    $data = http_build_query(array(
      'cons_group_ids' => implode(',', $cons_group_ids),
    ));

    // Make the request.
    $response = $this->callDeferredAPI('cons_group/delete_constituent_groups',
      array(), $data, $block);

    if ($block) {
      $this->checkNoContentResponse($response);
      return TRUE;
    }
    return $response;
  }

  /**
   * Get the deferred response to a cons_group/delete_constituent_groups call.
   *
   * @param string $deferred_id
   *   The deferred id returned from the original call to get.
   *
   * @return boolean
   *   TRUE if the constituent group has been deleted, or FALSE if the result is
   *   still being compiled.
   */
  public function deleteConstituentGroupsDeferred($deferred_id) {
    $response = $this->getDeferredResult($deferred_id);
    if ($response !== FALSE) {
      $this->checkNoContentResponse($response);
      return TRUE;
    }
    return $response;
  }

  /**
   * Parse the response to a cons_group/get_cons_ids_for_group API call.
   *
   * @param array $response
   *   An associative array containing the following:
   *   - http_code: The integer HTTP status code of the response.
   *   - body: The string body of the response.
   *
   * @return array
   *   An array of constituent ids in the group.
   *
   * @ throws BlueStateDigitalApiException
   */
  protected function parseGetConsIdsForGroupResponse($response) {

    // Check the response code.
    if ($response['http_code'] != self::HTTP_CODE_OK) {
      throw new BlueStateDigitalApiException(
        'Unexpected response status code.',
        BlueStateDigitalApiException::FAILED_RESPONSE_CODE,
        $response['http_code'], $response['body']);
    }

    // Parse the response body.
    $ids = explode(',', $response['body']);
    $ids = array_map('trim', $ids);
    $ids = array_filter($ids, 'strlen');

    return $ids;
  }

  /**
   * Get a list of constituent ids for a group.
   *
   * @param int $cons_group_id
   *   The id of the group to query.
   * @param boolean $block
   *   (optional) Boolean flag for controlling whether the call blocks until the
   *   result is ready.
   *   - TRUE: block until the result is ready.
   *   - FALSE: immediately return the deferred id.
   *
   * @return array|string
   *   The return values depends on the $block parameter.
   *   - TRUE: An array of constituent ids in the group as returned by
   *     BlueStateDigitalGroupApi::parseGetConsIdsForGroupResponse().
   *   - FALSE: A string deferred id for retrieving the results at a later time.
   *
   * @see BlueStateDigitalGroupApi::parseGetConsIdsForGroupResponse()
   */
  public function getConsIdsForGroup($cons_group_id, $block = TRUE) {

    // Make the request.
    $response = $this->callDeferredAPI('cons_group/get_cons_ids_for_group',
      array('cons_group_id' => $cons_group_id), NULL, $block);

    if ($block) {
      return $this->parseGetConsIdsForGroupResponse($response);
    }
    return $response;
  }

  /**
   * Get the deferred response to a cons_group/get_cons_ids_for_group API call.
   *
   * @param string $deferred_id
   *   The deferred id returned from the original call to get
   *
   * @return array|boolean
   *   An array of constituent ids in the group as returned by
   *   BlueStateDigitalGroupApi::parseGetConsIdsForGroupResponse(), or FALSE
   *   if the result is still being compiled.
   *
   * @see BlueStateDigitalGroupApi::parseGetConsIdsForGroupResponse()
   */
  public function getConsIdsForGroupDeferred($deferred_id) {
    $response = $this->getDeferredResult($deferred_id);
    if ($response !== FALSE) {
      return $this->parseGetConsIdsForGroupResponse($response);
    }
    return $response;
  }

  /**
   * Set the constituent ids for a group.
   *
   * @param int $cons_group_id
   *   The id of the group to update.
   * @param array $cons_ids
   *   An array of constituent ids to set as the group's members.
   * @param boolean $block
   *   (optional) Boolean flag for controlling whether the call blocks until the
   *   result is ready.
   *   - TRUE: block until the result is ready.
   *   - FALSE: immediately return the deferred id.
   *
   * @return boolean|string
   *   The return values depends on the $block parameter.
   *   - TRUE: A boolean TRUE value.
   *   - FALSE: A string deferred id for retrieving the results at a later time.
   *
   * @see BlueStateDigitalApi::checkNoContentResponse()
   */
  public function setConsIdsForGroup($cons_group_id, $cons_ids, $block = TRUE) {

    // Build the request.
    $data = http_build_query(array(
      'cons_group_id' => $cons_group_id,
      'cons_ids' => implode(',', $cons_ids),
    ));

    // Make the request.
    $response = $this->callDeferredAPI('cons_group/set_cons_ids_for_group',
      array(), $data, $block);

    if ($block) {
      $this->checkNoContentResponse($response);
      return TRUE;
    }
    return $response;
  }

  /**
   * Get the deferred response to a cons_group/set_cons_ids_for_group API call.
   *
   * @param string $deferred_id
   *   The deferred id returned from the original call to get.
   *
   * @return boolean
   *   TRUE if the group member list has been updated, or FALSE if the result
   *   is still being compiled.
   */
  public function setConsIdsForGroupDeferred($deferred_id) {
    $response = $this->getDeferredResult($deferred_id);
    if ($response !== FALSE) {
      $this->checkNoContentResponse($response);
      return TRUE;
    }
    return $response;
  }

  /**
   * Add constituent ids to a group.
   *
   * @param int $cons_group_id
   *   The id of the group to update.
   * @param array $cons_ids
   *   An array of constituent ids to add to the group's members list.
   * @param boolean $block
   *   (optional) Boolean flag for controlling whether the call blocks until the
   *   result is ready.
   *   - TRUE: block until the result is ready.
   *   - FALSE: immediately return the deferred id.
   *
   * @return boolean|string
   *   The return values depends on the $block parameter.
   *   - TRUE: A boolean TRUE value.
   *   - FALSE: A string deferred id for retrieving the results at a later time.
   *
   * @see BlueStateDigitalApi::checkNoContentResponse()
   */
  public function addConsIdsToGroup($cons_group_id, $cons_ids, $block = TRUE) {

    // Build the request.
    $data = http_build_query(array(
      'cons_group_id' => $cons_group_id,
      'cons_ids' => implode(',', $cons_ids),
    ));

    // Make the request.
    $response = $this->callDeferredAPI('cons_group/add_cons_ids_to_group',
      array(), $data, $block);

    if ($block) {
      $this->checkNoContentResponse($response);
      return TRUE;
    }
    return $response;
  }

  /**
   * Get the deferred response to a cons_group/add_cons_ids_to_group API call.
   *
   * @param string $deferred_id
   *   The deferred id returned from the original call to get
   *
   * @return boolean
   *   TRUE if the group member list has been updated, or FALSE if the result
   *   is still being compiled.
   */
  public function addConsIdsToGroupDeferred($deferred_id) {
    $response = $this->getDeferredResult($deferred_id);
    if ($response !== FALSE) {
      $this->checkNoContentResponse($response);
      return TRUE;
    }
    return $response;
  }

  /**
   * Remove constituent ids from a group.
   *
   * @param int $cons_group_id
   *   The id of the group to update.
   * @param array $cons_ids
   *   An array of constituent ids to remove from the group's members list.
   * @param boolean $block
   *   (optional) Boolean flag for controlling whether the call blocks until the
   *   result is ready.
   *   - TRUE: block until the result is ready.
   *   - FALSE: immediately return the deferred id.
   *
   * @return boolean|string
   *   The return values depends on the $block parameter.
   *   - TRUE: A boolean TRUE value.
   *   - FALSE: A string deferred id for retrieving the results at a later time.
   *
   * @see BlueStateDigitalApi::checkNoContentResponse()
   */
  public function removeConsIdsFromGroup($cons_group_id, $cons_ids,
    $block = TRUE) {

    // Build the request.
    $data = http_build_query(array(
      'cons_group_id' => $cons_group_id,
      'cons_ids' => implode(',', $cons_ids),
    ));

    // Make the request.
    $response = $this->callDeferredAPI('cons_group/remove_cons_ids_from_group',
      array(), $data, $block);

    if ($block) {
      $this->checkNoContentResponse($response);
      return TRUE;
    }
    return $response;
  }

  /**
   * Get the deferred response to a cons_group/remove_cons_ids_from_group call.
   *
   * @param string $deferred_id
   *   The deferred id returned from the original call to get
   *
   * @return boolean
   *   TRUE if the group member list has been updated, or FALSE if the result
   *   is still being compiled.
   */
  public function removeConsIdsFromGroupDeferred($deferred_id) {
    $response = $this->getDeferredResult($deferred_id);
    if ($response !== FALSE) {
      $this->checkNoContentResponse($response);
      return TRUE;
    }
    return $response;
  }

  /**
   * Parse the response to a cons_group/get_ext_ids_for_group API call.
   *
   * @param array $response
   *   An associative array containing the following:
   *   - http_code: The integer HTTP status code of the response.
   *   - body: The string body of the response.
   *
   * @return array
   *   An array of external ids in the group.
   *
   * @throws BlueStateDigitalApiException
   */
  protected function parseGetExtIdsForGroupResponse($response) {

    // Check the response code.
    if ($response['http_code'] != self::HTTP_CODE_OK) {
      throw new BlueStateDigitalApiException(
        'Unexpected response status code.',
        BlueStateDigitalApiException::FAILED_RESPONSE_CODE,
        $response['http_code'], $response['body']);
    }

    // Parse the response body.
    $ids = explode(',', $response['body']);
    $ids = array_map('trim', $ids);
    $ids = array_filter($ids, 'strlen');

    return $ids;
  }

  /**
   * Get a list of external ids for a group.
   *
   * @param int $cons_group_id
   *   The id of the group to query.
   * @param string $ext_type
   *   The type of external id to retrieve.
   * @param boolean $block
   *   (optional) Boolean flag for controlling whether the call blocks until the
   *   result is ready.
   *   - TRUE: block until the result is ready.
   *   - FALSE: immediately return the deferred id.
   *
   * @return array|string
   *   The return values depends on the $block parameter.
   *   - TRUE: An array of constituent ids in the group as returned by
   *     BlueStateDigitalGroupApi::parseGetExtIdsForGroupResponse().
   *   - FALSE: A string deferred id for retrieving the results at a later time.
   *
   * @see BlueStateDigitalGroupApi::parseGetExtIdsForGroupResponse()
   */
  public function getExtIdsForGroup($cons_group_id, $ext_type, $block = TRUE) {

    // Make the request.
    $params = array(
      'cons_group_id' => $cons_group_id,
      'ext_type' => $ext_type,
    );
    $response = $this->callDeferredAPI('cons_group/get_ext_ids_for_group',
      $params, NULL, $block);

    if ($block) {
      return $this->parseGetExtIdsForGroupResponse($response);
    }
    return $response;
  }

  /**
   * Get the deferred response to a cons_group/get_ext_ids_for_group API call.
   *
   * @param string $deferred_id
   *   The deferred id returned from the original call to get
   *
   * @return array|boolean
   *   An array of external ids in the group as returned by
   *   BlueStateDigitalGroupApi::parseGetExtIdsForGroupResponse(), or FALSE if
   *   the result is still being compiled.
   */
  public function getExtIdsForGroupDeferred($deferred_id) {
    $response = $this->getDeferredResult($deferred_id);
    if ($response !== FALSE) {
      return $this->parseGetExtIdsForGroupResponse($response);
    }
    return $response;
  }

  /**
   * Set the external ids for a group.
   *
   * @param int $cons_group_id
   *   The id of the group to update.
   * @param string $ext_type
   *   The type of external id.
   * @param array $ext_ids
   *   An array of external ids to set as the group's members.
   * @param boolean $block
   *   (optional) Boolean flag for controlling whether the call blocks until the
   *   result is ready.
   *   - TRUE: block until the result is ready.
   *   - FALSE: immediately return the deferred id.
   *
   * @return boolean|string
   *   The return values depends on the $block parameter.
   *   - TRUE: A boolean TRUE value.
   *   - FALSE: A string deferred id for retrieving the results at a later time.
   *
   * @see BlueStateDigitalApi::checkNoContentResponse()
   */
  public function setExtIdsForGroup($cons_group_id, $ext_type, $ext_ids,
    $block = TRUE) {

    // Build the request.
    $data = http_build_query(array(
      'cons_group_id' => $cons_group_id,
      'ext_type' => $ext_type,
      'ext_ids' => implode(',', $ext_ids),
    ));

    // Make the request.
    $response = $this->callDeferredAPI('cons_group/set_ext_ids_for_group',
      array(), $data, $block);

    if ($block) {
      $this->checkNoContentResponse($response);
      return TRUE;
    }
    return $response;
  }

  /**
   * Get the deferred response to a cons_group/set_ext_ids_for_group API call.
   *
   * @param string $deferred_id
   *   The deferred id returned from the original call to get
   *
   * @return boolean
   *   TRUE if the group member list has been updated, or FALSE if the result
   *   is still being compiled.
   */
  public function setExtIdsForGroupDeferred($deferred_id) {
    $response = $this->getDeferredResult($deferred_id);
    if ($response !== FALSE) {
      $this->checkNoContentResponse($response);
      return TRUE;
    }
    return $response;
  }

  /**
   * Add external ids to a group.
   *
   * @param int $cons_group_id
   *   The id of the group to update.
   * @param string $ext_type
   *   The type of external id.
   * @param array $ext_ids
   *   An array of external ids to add to the group's members list.
   * @param boolean $block
   *   (optional) Boolean flag for controlling whether the call blocks until the
   *   result is ready.
   *   - TRUE: block until the result is ready.
   *   - FALSE: immediately return the deferred id.
   *
   * @return boolean|string
   *   The return values depends on the $block parameter.
   *   - TRUE: A boolean TRUE value.
   *   - FALSE: A string deferred id for retrieving the results at a later time.
   *
   * @see BlueStateDigitalApi::checkNoContentResponse()
   */
  public function addExtIdsToGroup($cons_group_id, $ext_type, $ext_ids,
    $block = TRUE) {

    // Build the request.
    $data = http_build_query(array(
      'cons_group_id' => $cons_group_id,
      'ext_type' => $ext_type,
      'ext_ids' => implode(',', $ext_ids),
    ));

    // Make the request.
    $response = $this->callDeferredAPI('cons_group/add_ext_ids_to_group',
      array(), $data, $block);

    if ($block) {
      $this->checkNoContentResponse($response);
      return TRUE;
    }
    return $response;
  }

  /**
   * Get the deferred response to a cons_group/add_ext_ids_for_group API call.
   *
   * @param string $deferred_id
   *   The deferred id returned from the original call to get
   *
   * @return boolean
   *   TRUE if the group member list has been updated, or FALSE if the result
   *   is still being compiled.
   */
  public function addExtIdsToGroupDeferred($deferred_id) {
    $response = $this->getDeferredResult($deferred_id);
    if ($response !== FALSE) {
      $this->checkNoContentResponse($response);
      return TRUE;
    }
    return $response;
  }

  /**
   * Remove external ids from a group.
   *
   * @param int $cons_group_id
   *   The id of the group to update.
   * @param string $ext_type
   *   The type of external id.
   * @param array $ext_ids
   *   An array of external ids to remove from the group's members list.
   * @param boolean $block
   *   (optional) Boolean flag for controlling whether the call blocks until the
   *   result is ready.
   *   - TRUE: block until the result is ready.
   *   - FALSE: immediately return the deferred id.
   *
   * @return boolean|string
   *   The return values depends on the $block parameter.
   *   - TRUE: A boolean TRUE value.
   *   - FALSE: A string deferred id for retrieving the results at a later time.
   *
   * @see BlueStateDigitalApi::checkNoContentResponse()
   */
  public function removeExtIdsFromGroup($cons_group_id, $ext_type, $ext_ids,
    $block = TRUE) {

    // Build the request.
    $data = http_build_query(array(
      'cons_group_id' => $cons_group_id,
      'ext_type' => $ext_type,
      'ext_ids' => implode(',', $ext_ids),
    ));

    // Make the request.
    $response = $this->callDeferredAPI('cons_group/remove_ext_ids_from_group',
      array(), $data, $block);

    if ($block) {
      $this->checkNoContentResponse($response);
      return TRUE;
    }
    return $response;
  }

  /**
   * Get the deferred response to a cons_group/remove_ext_ids_for_group call.
   *
   * @param string $deferred_id
   *   The deferred id returned from the original call to get
   *
   * @return boolean
   *   TRUE if the group member list has been updated, or FALSE if the result
   *   is still being compiled.
   */
  public function removeExtIdsFromGroupDeferred($deferred_id) {
    $response = $this->getDeferredResult($deferred_id);
    if ($response !== FALSE) {
      $this->checkNoContentResponse($response);
      return TRUE;
    }
    return $response;
  }
}

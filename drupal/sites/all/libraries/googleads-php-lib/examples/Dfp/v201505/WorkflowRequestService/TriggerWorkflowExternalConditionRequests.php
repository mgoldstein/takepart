<?php
/**
 * This example triggers all workflow external condition requests belonging to a
 * specific proposal. Workflow external condition requests must be triggered or
 * skipped for a workflow to finish. To determine which proposals exist, run
 * GetAllProposals.php.
 *
 * PHP version 5
 *
 * Copyright 2014, Google Inc. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @package    GoogleApiAdsDfp
 * @subpackage v201505
 * @category   WebServices
 * @copyright  2014, Google Inc. All Rights Reserved.
 * @license    http://www.apache.org/licenses/LICENSE-2.0 Apache License,
 *             Version 2.0
 */
error_reporting(E_STRICT | E_ALL);

// You can set the include path to src directory or reference
// DfpUser.php directly via require_once.
// $path = '/path/to/dfp_api_php_lib/src';
$path = dirname(__FILE__) . '/../../../../src';
set_include_path(get_include_path() . PATH_SEPARATOR . $path);

require_once 'Google/Api/Ads/Dfp/Lib/DfpUser.php';
require_once 'Google/Api/Ads/Dfp/Util/v201505/StatementBuilder.php';
require_once dirname(__FILE__) . '/../../../Common/ExampleUtils.php';

// Set the ID of the proposal to trigger workflow external conditions for.
$proposalId = 'INSERT_PROPOSAL_ID_HERE';

try {
  // Get DfpUser from credentials in "../auth.ini"
  // relative to the DfpUser.php file's directory.
  $user = new DfpUser();

  // Log SOAP XML request and response.
  $user->LogDefaults();

  // Get the WorkflowRequestService.
  $workflowRequestService = $user->GetService('WorkflowRequestService',
      'v201505');

  // Create a statement to select workflow external condition requests for a
  // proposal.
  $statementBuilder = new StatementBuilder();
  $statementBuilder->Where('WHERE entityId = :entityId and entityType = '
      . ':entityType and type = :type')
      ->OrderBy('id ASC')
      ->WithBindVariableValue('entityId', $proposalId)
      ->WithBindVariableValue('entityType', 'PROPOSAL')
      ->WithBindVariableValue('type', 'WORKFLOW_EXTERNAL_CONDITION_REQUEST');

  // Default for total result set size.
  $totalResultSetSize = 0;

  do {
    // Get workflow requests by statement.
    $page = $workflowRequestService->getWorkflowRequestsByStatement(
        $statementBuilder->ToStatement());

    // Display results.
    if (isset($page->results)) {
      $totalResultSetSize = $page->totalResultSetSize;
      $i = $page->startIndex;
      foreach ($page->results as $workflowRequest) {
        printf("%d) Workflow external condition request with ID %d, for '%s', "
            . "with ID %d will be triggerd.\n",
            $i++,
            $workflowRequest->id,
            $workflowRequest->entityType,
            $workflowRequest->entityId
        );
      }
    }

    $statementBuilder->IncreaseOffsetBy(StatementBuilder::SUGGESTED_PAGE_LIMIT);
  } while ($statementBuilder->GetOffset() < $totalResultSetSize);

  printf("Number of workflow external condition requests to be triggerd: %d\n",
      $totalResultSetSize);

  if ($totalResultSetSize > 0) {
    // Remove limit and offset from statement.
    $statementBuilder->RemoveLimitAndOffset();

    // Create action.
    $action = new TriggerWorkflowExternalConditionRequests();

    // Perform action.
    $result = $workflowRequestService->performWorkflowRequestAction($action,
        $statementBuilder->ToStatement());

    // Display results.
    if (isset($result) && $result->numChanges > 0) {
      printf("Number of workflow external condition requests triggerd: %d\n",
          $result->numChanges);
    } else {
      printf("No workflow external condition requests were triggerd.\n");
    }
  }
} catch (OAuth2Exception $e) {
  ExampleUtils::CheckForOAuth2Errors($e);
} catch (ValidationException $e) {
  ExampleUtils::CheckForOAuth2Errors($e);
} catch (Exception $e) {
  printf("%s\n", $e->getMessage());
}


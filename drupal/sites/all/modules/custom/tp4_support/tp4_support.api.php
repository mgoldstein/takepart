<?php

/**
 *  @function:
 *    This function allows users to modify the output of a token before it's rendered.
 *    Noting that this is cached so it will require flushing cache to see each alteration.
 *
 *  @param:
 *    node - the node that is passed in
 *    output - this is the string markup that is outputted as a final result
 *    level - a markup to allow a developer to know where in the stack its called
 */
function hook_tp4_token_campaign_alter(&$node, &$field_name, &$output, &$level) {
  //example for output
  $output = 'Example';
}
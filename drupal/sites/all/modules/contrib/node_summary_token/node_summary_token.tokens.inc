<?php
/**
 * @file A work-around for the core bug that means that node:summary tokens
 * don't work in some cases - specifically to support metatag descriptions.
 *
 * At this date, the issue http://drupal.org/node/1300920
 * [The [node:summary] token does not output anything for body fields without a manual summary]
 * has been open as a core issue for a year, and 'work' is on D8.
 *
 * Work-arounds are needed. A core patch for D7 can be made, but this pluggable
 * module will let us avoid doing so.
 * REMOVE this module if core ever gets fixed.
 *
 * The core [node:summary] token is OVERRIDDEN by my module here, using
 * hook_tokens_alter(). http://drupal.org/node/731518
 * This is so that normal default metatags behavior, and existing sites that
 * already are trying to use that (broken) token will start working again.
 *
 * This module code originally lifted from the metatag queue issue
 * http://drupal.org/node/1295524#comment-5825254
 * but then modified into a hook_alter and cut down a bit.
 */


 /**
  * Alter the value of node:summary token to ensure it is built if blank.
  *
  * HOOK_tokens_alter()
  */
function node_summary_token_tokens_alter(array &$replacements, array $context) {
  if ($context['type'] == 'node' && !empty($context['data']['node'])) {
    $node = $context['data']['node'];
    $teaser_length = 200;

    // Alter the [node:summary] to generate the truncated version if not
    // already set.
    $body_field_items = field_get_items('node', $node, 'body');
    if (isset($body_field_items[0]['summary']) && $body_field_items[0]['summary'] != '') {
      $trimmed_or_summary = $body_field_items[0]['summary'];
    }
    else {
      $text = isset($body_field_items[0]["value"]) ? check_markup($body_field_items[0]["value"], $body_field_items[0]["format"]) : '';
      // When a html closing tag is immediately followed by an openening tag, put a space in between.
      $text = preg_replace('/(<\/[^>]+?>)(<[^>\/][^>]*?>)/', '$1 $2', $text);
      $trimmed_or_summary = truncate_utf8(strip_tags($text), $teaser_length, TRUE, FALSE);
    }

    // Needed to scan all tokens to find the one called summary as a key
    // for some inefficient reason?
    /*
    foreach ($context['tokens'] as $name => $original) {
      $trimmed_or_summary = '';
      $split_name = explode(':', $name);
      if ($split_name[0] == 'summary') {
        $replacements[$original] = $sanitize ? filter_xss($trimmed_or_summary) : $trimmed_or_summary;
        if (isset($split_name[1])) {
          $teaser_length = (int) $split_name[1];
        }
      }
    }
    */

    // No, just set the thing I know I need to set.
    $sanitize = !empty($context['options']['sanitize']);
    $replacements['[node:summary]'] = $sanitize ? filter_xss($trimmed_or_summary) : $trimmed_or_summary;
  }
}
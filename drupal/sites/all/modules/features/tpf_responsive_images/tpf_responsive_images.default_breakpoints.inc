<?php
/**
 * @file
 * tpf_responsive_images.default_breakpoints.inc
 */

/**
 * Implements hook_default_breakpoints().
 */
function tpf_responsive_images_default_breakpoints() {
  $export = array();

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'breakpoints.theme.base.base_large_desktop';
  $breakpoint->name = 'base_large_desktop';
  $breakpoint->breakpoint = '(min-width: 980px)';
  $breakpoint->source = 'base';
  $breakpoint->source_type = 'theme';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['breakpoints.theme.base.base_large_desktop'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'breakpoints.theme.base.base_large_mobile';
  $breakpoint->name = 'base_large_mobile';
  $breakpoint->breakpoint = '(min-width: 0px)';
  $breakpoint->source = 'base';
  $breakpoint->source_type = 'theme';
  $breakpoint->status = 1;
  $breakpoint->weight = 2;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['breakpoints.theme.base.base_large_mobile'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'breakpoints.theme.base.base_large_tablet';
  $breakpoint->name = 'base_large_tablet';
  $breakpoint->breakpoint = '(min-width: 768px)';
  $breakpoint->source = 'base';
  $breakpoint->source_type = 'theme';
  $breakpoint->status = 1;
  $breakpoint->weight = 1;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['breakpoints.theme.base.base_large_tablet'] = $breakpoint;

  return $export;
}

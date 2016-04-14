<?php
/**
 * @file
 * tpf_responsive_images.default_breakpoint_group.inc
 */

/**
 * Implements hook_default_breakpoint_group().
 */
function tpf_responsive_images_default_breakpoint_group() {
  $export = array();

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'large';
  $breakpoint_group->name = 'Large';
  $breakpoint_group->breakpoints = array(
    0 => 'breakpoints.theme.base.base_large_desktop',
    1 => 'breakpoints.theme.base.base_large_tablet',
    2 => 'breakpoints.theme.base.base_large_mobile',
  );
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['large'] = $breakpoint_group;

  return $export;
}

<?php

// Plugin definition
$plugin = array(
  'title' => t('TakePart Homepage'),
  'category' => t('TakePart Layouts'),
  'icon' => 'takepart_homepage.png',
  'theme' => 'panels_takepart_homepage',
  // We'll do CSS in the tp4 theme CSS
  // Though that may kind of mess up the admin UI
  // 'css' => 'pivot_curated.css',
  'regions' => array(
    'main_featured' => t('Main Feature'),
    'secondary_featured' => t('Secondary Features'),
    'tpl_featured' => t('TakePart Live Feature'),
    'tpl_secondary_featured' => t('TakePart Live Secondary Features'),
  ),
);

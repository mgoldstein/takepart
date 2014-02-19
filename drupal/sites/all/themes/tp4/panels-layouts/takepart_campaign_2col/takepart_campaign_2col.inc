<?php

// Plugin definition
$plugin = array(
  'title' => t('TakePart Campaign 2 Column'),
  'category' => t('TakePart Layouts'),
  'icon' => 'takepart_campaign_2col.png',
  'theme' => 'panels_takepart_campaign_2col',
  'css' => 'takepart_campaign_2col.css',
  'regions' => array(
    'instructional_copy' => t('Instructional Copy'),
    'left_col' => t('Left Column'),
    'right_col' => t('Right Column'),
  ),
);

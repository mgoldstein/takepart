<?php

// Plugin definition
$plugin = array(
  'title' => t('Campaign One Column'),
  'category' => t('TakePart Layouts'),
  'icon' => 'tp-campaign-1col.png',
  'theme' => 'panels_tp_campaign_1col',
  'css' => 'tp-campaign-1col.css',
  'regions' => array(
    'instructional' => t('instructional'),
    'column' => t('Column'),
  ),
);

<?php

// Plugin definition
$plugin = array(
  'title' => t('Campaign Two Column Right'),
  'category' => t('TakePart Layouts'),
  'icon' => 'tp-campaign-2col-right.png',
  'theme' => 'panels_tp_campaign_2col_right',
  'css' => 'tp-campaign-2col-right.css',
  'regions' => array(
    'instructional' => t('instructional'),
    'left' => t('Left side'),
    'right' => t('Right side')
  ),
);

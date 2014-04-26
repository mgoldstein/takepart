<?php

// Plugin definition
$plugin = array(
  'title' => t('Campaign Two Column Left Large'),
  'category' => t('TakePart Layouts'),
  'icon' => 'tp-campaign-2col-left.png',
  'theme' => 'panels_tp_campaign_2col_left',
  'css' => 'tp-campaign-2col-left.css',
  'regions' => array(
    'instructional' => t('instructional'),
    'left' => t('Left side'),
    'right' => t('Right side')
  ),
);

<?php

// Plugin definition
$plugin = array(
  'title' => t('Campaign Two Column'),
  'category' => t('TakePart Layouts'),
  'icon' => 'tp-campaign-2col.png',
  'theme' => 'panels_tp_campaign_2col',
  'css' => 'tp-campaign-2col.css',
  'regions' => array(
    'instructional' => t('instructional'),
    'left' => t('Left side'),
    'right' => t('Right side')
  ),
);

<?php

/**
* Implements hook_preprocess_html();
*/
function fresh_preprocess_html(&$variables) {
// Pass the digital data to the HTML template.
$variables['tp_digital_data'] =  isset($variables['page']['tp_digital_data'])
? $variables['page']['tp_digital_data'] : NULL;
}
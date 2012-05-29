<?php

function _fbregistration_admin_form_load(&$elements, &$form = array(), &$i = 0) {
  foreach (element_children($elements) as $key) {
    if (isset($elements[$key]) && $elements[$key]) {
      
      if ((array_key_exists('#type', $elements[$key])) && ($elements[$key]['#type'] == 'textfield' || 
            $elements[$key]['#type'] == 'radios' || 
            $elements[$key]['#type'] == 'date_combo' ||
            $elements[$key]['#type'] == 'checkboxes' ||
            $elements[$key]['#type'] == 'checkbox' ||
            $elements[$key]['#type'] == 'select' ||
            $elements[$key]['#type'] == 'textarea' ||
            $elements[$key]['#type'] == 'password')) { 

            $i++;
            $uid = isset($elements[$key]['#field_name']) ? $elements[$key]['#field_name'] : $key;

            $form[$uid] = array(
              '#type' => 'select',
              '#foreign' => $elements[$key],
              '#default_value' => variable_get('fbregistration_form_mapping_' . $uid, 'not_mapped'),
              '#title' => $i . " " . t($elements[$key]['#title']  . " : " . $elements[$key]['#type']),
              '#options' => _fbregistration_admin_get_fbregmappings(),
            );
            
      } else {
        _fbregistration_admin_form_load($elements[$key], $form, $i);
      }
    }
  }
}


function _fbregistration_admin_get_fbregmappings() {
  return array( 'name' => t('Full name of the user'),
                'birthday' => t('Birthday'),
                'email' => t('Email'),
                'gender' => t('Gender'),
                'location' => t('Name and ID of the user\'s current city'),
                'password' => t('Password (not their Facebook password)'),
                'captcha' => t('Captcha'),
                'first_name' => t('First Name'),
                'last_name' => t('Last Name'),
                'custom_text' => t('Custom Text Field'),
                'custom_date' => t('Custom Date Field'),
                'custom_select' => t('Custom Select Box'),
                'custom_checkbox' => t('Custom Check Box'),
                'custom_typeahead' => t('Custom Type-ahead'),
                'custom_hidden' => t('Hidden'),
                'not_mapped' => t('Not Mapped'));
}

function _fbregistration_bsd_form_load(&$elements, &$form = array(), &$i = 0) {
  foreach (element_children($elements) as $key) {
    if (isset($elements[$key]) && $elements[$key]) {
      if ((array_key_exists('#type', $elements[$key])) && ($elements[$key]['#type'] == 'checkbox')) {
        $uid = isset($elements[$key]['#field_name']) ? $elements[$key]['#field_name'] : $key;
        $form[$uid] = takepart_bsd_form_id_select_field(variable_get('fbregistration_bsd_mapping_' . $uid, '0'));
        $form[$uid]['#title'] = $form[$uid]['#title'] . " : " . $elements[$key]['#title'];
      } else {
        _fbregistration_bsd_form_load($elements[$key], $form, $i);
      }
    }
  }
}
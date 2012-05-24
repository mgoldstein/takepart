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
          
          //if($elements[$key]['#type'] == 'date_combo') {
          
                      
          
            //@todo: need a better match:
            //$uid =  str_replace(" ", "", substr($elements[$key]['#title'],0,10)) . "_" . $elements[$key]['#type']  . "_" . $key;
            
            $uid = isset($elements[$key]['#field_name']) ? $elements[$key]['#field_name'] : $key;
            
            //$uid = $i;
            $form[$uid] = array(
              '#type' => 'select',
              '#foreign' => $elements[$key],
              '#default_value' => variable_get('fbregistration_form_mapping_' . $uid, 'not_mapped'),
              '#title' => $i . " " . t($elements[$key]['#title']  . " : " . $elements[$key]['#type']),
              '#options' => _fbregistration_admin_get_fbregmappings(),
            );
            
            
            
            //print "<pre>";
            //print_r($form);
            //print "</pre>";
            //print "<br/> --------------------------------- <br/> ";
            
            
            //}
        
      } else {
        _fbregistration_admin_form_load($elements[$key], $form, $i);
      }
    }
  }
}

/*
 *         print "<pre>$uid : ";
        print_r($elements);
        print "<pre>";
 */


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

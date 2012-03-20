<?php

function marigold_hotel_contest_form($form, &$form_state, $no_js_use = FALSE) {
  
  $callback = 'marigold_hotel_contest_form_callback';
  $wrapper = 'marigold-hotel-contest-form-wrapper';

  // Provide a wrapper around the entire form, since we'll replace the whole
  // thing with each submit.
  $form['#prefix'] = '<div id="' . $wrapper . '">';
  $form['#suffix'] = '</div>';
  $form['#tree'] = TRUE; // We want to deal with hierarchical form values.

  $form['description'] = array(
    '#markup' => '<div>' . 
      t('Prototype form for the Marigold Hotel Contest')
    . '</div>',
  );
  
  $reqtext = '<span class="reqtext"><span class="form-required">*</span>Indicates required field</span>';
      
  // $form_state['storage'] has no specific drupal meaning, but it is
  // traditional to keep variables for multistep forms there.
  $step = empty($form_state['storage']['step']) ? 1 : $form_state['storage']['step'];
  $form_state['storage']['step'] = $step;

  switch ($step) {
    case 1:
      $form['step1'] = array(
        '#type' => 'fieldset',
        '#title' => t('1 TELL US ABOUT YOUR IDEA'),
      );
      $form['step1']['custom-265'] = array(
        '#type' => 'textarea',
        '#rows' => 2,
        '#columns' => 40,
        '#attributes' => array('maxlength' => "140"),
        '#title' => t('Describe your idea in 140 charecters or less (this is the summary we\'ll use throughout the site):'),
        '#default_value' => empty($form_state['values']['step1']['custom-265']) ? '' : $form_state['values']['step1']['custom-265'],
        '#required' => TRUE,
        '#weight' => 10,
      );
      $form['step1']['custom-266'] = array(
          '#type' => 'textarea',
          '#rows' => 8,
          '#columns' => 40,
          '#attributes' => array('maxlength' => "700"),
          '#title' => t('How does your idea address a community, national or international social problem? Share your answer here in 700 charecters or less (around 100 words):'),
          '#default_value' => empty($form_state['values']['step1']['custom-266']) ? '' : $form_state['values']['step1']['custom-266'],
          '#required' => FALSE,
          '#weight' => 20,
      );
      $form['step1']['custom-267'] = array(
          '#type' => 'textarea',
          '#rows' => 8,
          '#columns' => 40,
          '#attributes' => array('maxlength' => "700"),
          '#title' => t('How would winning $5000 and the support of the Encore Careers Community would help you get your idea off the ground? Share your answer here in 700 charecters or less (around 100 words):'),
          '#default_value' => empty($form_state['values']['step1']['custom-267']) ? '' : $form_state['values']['step1']['custom-267'],
          '#required' => FALSE,
          '#weight' => 30,
      );
      $form['step1']['custom-268'] = array(
          '#type' => 'textfield',
          '#title' => t('Have you already turned your idea into an organization, a startup, a nonprofit or a business? If so, tell us the name here:'),
          '#default_value' => empty($form_state['values']['step2']['custom-268']) ? '' : $form_state['values']['step2']['custom-268'],
          '#required' => FALSE,
          '#weight' => 40,
      );
      $form['step1']['custom-269'] = array(
          '#type' => 'checkboxes',
          '#title' => t('Select categories for your idea (you may choose more than one):'),
          '#default_value' => 'X',
          '#options' => array(0 => t('<strong>Education:</strong> Ideas that create educational opportunities for people of any age'), 
                              1 => t('<strong>Social Services:</strong> Ideas that improve services and access to the service for those in need'), 
                              2 => t('<strong>Environment:</strong> Ideas that improve the environment in your community'),
                              3 => t('<strong>Health Care:</strong> Ideas that increase awareness of health issues and/or access to health care'),
                              4 => t('<strong>Encore Careers:</strong> Ideas for engaging more people in careers combining purpose and passion'),
                              5 => t('<strong>Other:</strong> Ideas that do not apply to any of the listed categories'),),
          '#required' => FALSE,
          '#weight' => 50,
      );
      $form['step1']['reqtext'] = array(
          '#markup' => $reqtext,
          '#weight' => 60,
      );
      break;

    case 2:
      $form['step2'] = array(
        '#type' => 'fieldset',
        '#title' => t('2 TELL US ABOUT YOU'),
        '#weight' => 70,
      );
      $form['step2']['custom-270'] = array(
          '#type' => 'textarea',
          '#rows' => 8,
          '#columns' => 40,
          '#attributes' => array('maxlength' => "700"),
          '#title' => t('What inspires you about this idea and what excites you about the potential to make it a reality? Share your answer here in 700 charecters or less (around 100 words):'),
          '#default_value' => empty($form_state['values']['step1']['custom-270']) ? '' : $form_state['values']['step1']['custom-270'],
          '#required' => FALSE,
          '#weight' => 80,
      );
      $form['step2']['custom-271'] = array(
          '#type' => 'textarea',
          '#rows' => 8,
          '#columns' => 40,
          '#attributes' => array('maxlength' => "700"),
          '#title' => t('How will your work and life experiance help you turn your idea into a reality? Share your answer here in 700 charecters or less (around 100 words):'),
          '#default_value' => empty($form_state['values']['step1']['custom-271']) ? '' : $form_state['values']['step1']['custom-271'],
          '#required' => FALSE,
          '#weight' => 90,
      );
      $form['step2']['custom-272'] = array(
          '#type' => 'checkboxes',
          '#title' => t('Participants must be 45 years or older to be eligable for this contest.'),
          '#default_value' => 'X',
          '#options' => array(0 => t('I confirm that I am 45 years old or older and a U.S. Citizen or legal resident.'),),
          '#required' => FALSE,
          '#weight' => 100,
      );
      //How to match BSD select boxes?
      $dob = strtotime("-1 day", time());
      $form['step2']['custom-273'] = array (
          '#title' => t('Date of birth:'),
          '#type' => 'date',
          '#default_value' => array(
              'month' => format_date($dob, 'custom', 'n'),
              'day' => format_date($dob, 'custom', 'j'),
              'year' => format_date($dob, 'custom', 'Y'),
          ),
          '#weight' => 110,
      );
      
      $form['step2']['reqtext'] = array(
          '#markup' => $reqtext,
          '#weight' => 120,
      );
      
      break;

    case 3:
      $form['step3'] = array(
        '#type' => 'fieldset',
        '#title' => t('3 FINAL INFORMATION'),
        '#weight' => 130,
      );
      $form['step3']['email'] = array(
        '#type' => 'textfield',
        '#title' => t('Email'),
        '#default_value' => empty($form_state['values']['step3']['email']) ? '' : $form_state['values']['step3']['email'],
        '#required' => FALSE,
        '#weight' => 140,
      );
      $form['step3']['firstname'] = array(
          '#type' => 'textfield',
          '#title' => t('First Name'),
          '#default_value' => empty($form_state['values']['step3']['firstname']) ? '' : $form_state['values']['step3']['firstname'],
          '#required' => FALSE,
          '#weight' => 150,
      );
      $form['step3']['lastname'] = array(
          '#type' => 'textfield',
          '#title' => t('Last Name'),
          '#default_value' => empty($form_state['values']['step3']['lastname']) ? '' : $form_state['values']['step3']['lastname'],
          '#required' => FALSE,
          '#weight' => 160,
      );
      //How are these mapped in BSD?
      $form['step3']['addr1'] = array(
          '#type' => 'textfield',
          '#title' => t('Address'),
          '#default_value' => empty($form_state['values']['step3']['addr1']) ? '' : $form_state['values']['step3']['addr1'],
          '#required' => FALSE,
          '#weight' => 170,
      );
      $form['step3']['addr2'] = array(
          '#type' => 'textfield',
          '#default_value' => empty($form_state['values']['step3']['addr2']) ? '' : $form_state['values']['step3']['addr2'],
          '#required' => FALSE,
          '#weight' => 180,
      );
      $form['step3']['city'] = array(
          '#type' => 'textfield',
          '#title' => t('City'),
          '#default_value' => empty($form_state['values']['step3']['city']) ? '' : $form_state['values']['step3']['city'],
          '#required' => FALSE,
          '#weight' => 190,
      );
      $fullstates = _marigold_hotel_contest_form_getstates();
      $states = array();
      foreach ($fullstates as $key=>$val) {
        array_push($states, t($key));
      }
      $form['step3']['state_cd'] = array(
          '#default_value' => empty($form_state['values']['step3']['state_cd']) ? '' : $form_state['values']['step3']['state_cd'],
          '#required' => FALSE,
          '#type' => 'select',
          '#title' => t('State/Region/Province'),
          '#options' => $states,
          '#weight' => 200,
      );
      $form['step3']['zip'] = array(
          '#type' => 'textfield',
          '#title' => t('Zip/Postal Code'),
          '#default_value' => empty($form_state['values']['step3']['zip']) ? '' : $form_state['values']['step3']['zip'],
          '#required' => FALSE,
          '#weight' => 210,
      );
      $form['step3']['phone'] = array(
          '#type' => 'textfield',
          '#title' => t('Phone'),
          '#default_value' => empty($form_state['values']['step3']['phone']) ? '' : $form_state['values']['step3']['phone'],
          '#required' => FALSE,
          '#weight' => 220,
      );
      $form['step3']['reqtext'] = array(
          '#markup' => $reqtext,
          '#weight' => 230,
      );
      break;
      case 4:
        $form['step4'] = array(
        '#type' => 'fieldset',
        '#title' => t('4 REVIEW AND SUBMIT'),
        );
        foreach ($form_state['storage']['values'] as $step => $values) {
          $value_message .= "<br/><br/>$step: ";
          foreach ($values as $key => $value) {
            $value_message .= "<br/>$key=$value, ";
          }
        }
        $form['step4']['preview'] = array(
            '#type' => 'item',
            '#title' => t('Sample BSD Form'),
            '#markup' => '<div style="border: solid 1px red">' . $value_message . '</div>',
        );
        break;
  }
  if ($step == 4) {
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t("Submit your information"),
      '#weight' => 2000,
    );
  }
  if ($step < 4) {
    $form['next'] = array(
      '#type' => 'submit',
      '#value' => t('Next step'),
      '#ajax' => array(
        'wrapper' => $wrapper,
        'callback' => $callback,
      ),
      '#weight' => 2000,
    );
  }
  if ($step > 1) {
    $form['prev'] = array(
      '#type' => 'submit',
      '#value' => t("Previous step"),

      // Since all info will be discarded, don't validate on 'prev'.
      '#limit_validation_errors' => array(),
      // #submit is required to use #limit_validation_errors
      '#submit' => array('marigold_hotel_contest_form_submit'),
      '#ajax' => array(
        'wrapper' => $wrapper,
        'callback' => $callback,
      ),
      '#weight' => 2010,
    );
  }
  
  $form['#step'] = array('#type' => 'hidden', '#value' => $step);

  //$form['#after_build'] = array('marigold_hotel_contest.forms.onformrender');
  /*
  $settings['ajaxComment'] = array(
      // this is all random data we're passing into the js object -- don't worry about it right now
      'nid' => $form['nid']['#value'],
      'cid' => $form['cid']['#value'],
      'uid' => $form['uid']['#value'],
      'pid' => $form['pid']['#value'],
  );
  */
  //drupal_add_js($settings, 'setting');
  
  return $form;
  
}

function marigold_hotel_contest_form_callback($form, $form_state) {
  
  $form['jstrigger'] = array(
      '#markup' => "<script>//alert('ok');</script>",
  );
  /*
      $form['#attached']['js'][] = array(
        'type' => 'inline',
        'weight' => 100,
        'data' => '(function ($) {
              alert("test");
            };
          })(jQuery);',
      );  
      
      */
      /*
      $form['#attached']['js'] = array(
          // Add some inline JavaScript.
          'alert("You are visiting the example form.");' => 'inline',
          // Add a JavaScript setting. Note that when the key is a number, the 'data' property will be used.
          array(
              'data' => array('takepart_contests' => array('test')),
              'type' => 'setting'
          ),
      );
      */
  
  //$commands = array();
  //$commands[] = ajax_command_invoke('#new-id', 'html', array('<div id="new-id2">#new.id2 here!</div>'));
  //$commands[] = ajax_command_invoke('#new-id2', 'addClass', array('error'));
  //return array('#type' => 'ajax', '#commands' => $commands);
  
  
  return $form;
}


function marigold_hotel_contest_form_submit($form, &$form_state) {

  // Save away the current information.
  $current_step = 'step' . $form_state['storage']['step'];
  if (!empty($form_state['values'][$current_step])) {
    $form_state['storage']['values'][$current_step] = $form_state['values'][$current_step];
  }

  // Increment or decrement the step as needed. Recover values if they exist.
  if ($form_state['triggering_element']['#value'] == t('Next step')) {
    $form_state['storage']['step']++;
    // If values have already been entered for this step, recover them from
    // $form_state['storage'] to pre-populate them.
    $step_name = 'step' . $form_state['storage']['step'];
    if (!empty($form_state['storage']['values'][$step_name])) {
      $form_state['values'][$step_name] = $form_state['storage']['values'][$step_name];
    }
  }
  if ($form_state['triggering_element']['#value'] == t('Previous step')) {
    $form_state['storage']['step']--;
    // Recover our values from $form_state['storage'] to pre-populate them.
    $step_name = 'step' . $form_state['storage']['step'];
    $form_state['values'][$step_name] = $form_state['storage']['values'][$step_name];
  }

  // If they're done, submit.
  if ($form_state['triggering_element']['#value'] == t('Submit your information')) {
    $value_message = t('Submit trigged ... on to preview, when that gets coded.') . ' ';
    foreach ($form_state['storage']['values'] as $step => $values) {
      $value_message .= "$step: ";
      foreach ($values as $key => $value) {
        $value_message .= "<br/>$key=$value, ";
      }
    }
    print ($value_message);
    exit();
    $form_state['rebuild'] = FALSE;
    return;
  }

  // Otherwise, we still have work to do.
  $form_state['rebuild'] = TRUE;
}

function _marigold_hotel_contest_form_getstates() {
  $states_arr = array('AL'=>"Alabama",'AK'=>"Alaska",'AZ'=>"Arizona",'AR'=>"Arkansas",'CA'=>"California",'CO'=>"Colorado",'CT'=>"Connecticut",'DE'=>"Delaware",'DC'=>"District Of Columbia",'FL'=>"Florida",'GA'=>"Georgia",'HI'=>"Hawaii",'ID'=>"Idaho",'IL'=>"Illinois", 'IN'=>"Indiana", 'IA'=>"Iowa",  'KS'=>"Kansas",'KY'=>"Kentucky",'LA'=>"Louisiana",'ME'=>"Maine",'MD'=>"Maryland", 'MA'=>"Massachusetts",'MI'=>"Michigan",'MN'=>"Minnesota",'MS'=>"Mississippi",'MO'=>"Missouri",'MT'=>"Montana",'NE'=>"Nebraska",'NV'=>"Nevada",'NH'=>"New Hampshire",'NJ'=>"New Jersey",'NM'=>"New Mexico",'NY'=>"New York",'NC'=>"North Carolina",'ND'=>"North Dakota",'OH'=>"Ohio",'OK'=>"Oklahoma", 'OR'=>"Oregon",'PA'=>"Pennsylvania",'RI'=>"Rhode Island",'SC'=>"South Carolina",'SD'=>"South Dakota",'TN'=>"Tennessee",'TX'=>"Texas",'UT'=>"Utah",'VT'=>"Vermont",'VA'=>"Virginia",'WA'=>"Washington",'WV'=>"West Virginia",'WI'=>"Wisconsin",'WY'=>"Wyoming");
  return $states_arr;
}










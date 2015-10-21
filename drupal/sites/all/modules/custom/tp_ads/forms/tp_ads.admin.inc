<?php

/**
 *  @function:
 *    @dev: currently displayed in the module level
 */
function tp_ads_admin_general_form() {
  $form = array();

  return $form;
}

/**
 *  @function:
 *    This function is used to provide an admin form for module.
 */
function tp_ads_admin_form() {
  //variables
  $form = array();
  $i = 0;
  $break = FALSE;

  //Add For loop for the 5 articles that autoload
  for($ad = 0; $ad < TP_ADS_NO_AUTOLOAD; $ad++) {
    $leader_settings = variable_get('tp_ads_article_leader_'.$ad, '');
    //These are for the 5 leaderboard ads
    //ad fieldset
    $form['tp_ads_article_leader']['tp_ads_article_leader_'.$ad] = array(
      '#tree' => TRUE,
      '#type' => 'fieldset',
      '#title' => t('Leaderboard Advertisement For Ad '.($ad+1)),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE
    );

    $form['tp_ads_article_leader']['tp_ads_article_leader_'.$ad]['selector'] = array(
      '#type' => 'textfield',
      '#title' => t('Selector to insert ad'),
      '#default_value' => $leader_settings['selector'],
    );

    $form['tp_ads_article_leader']['tp_ads_article_leader_'.$ad]['ad_slot'] = array(
      '#type' => 'textfield',
      '#title' => t('Ad Slot'),
      '#description' => t('Such as TP_Mobile_320x50'),
      '#default_value' => $leader_settings['ad_slot'],
    );

    $form['tp_ads_article_leader']['tp_ads_article_leader_'.$ad]['ad_gpd_id'] = array(
      '#type' => 'textfield',
      '#title' => t('Ad GPD ID'),
      '#description' => t('Such as div-gpt-ad-1382144784236-0a'),
      '#default_value' => $leader_settings['ad_gpd_id'],
    );

    $form['tp_ads_article_leader']['tp_ads_article_leader_'.$ad]['ad_width'] = array(
      '#type' => 'textfield',
      '#title' => t('Ad Width'),
      '#description' => t('Such as 320 or for multiple sizes use a comma separated list of sizes such as 768,320'),
      '#default_value' => $leader_settings['ad_width'],
    );

    $form['tp_ads_article_leader']['tp_ads_article_leader_'.$ad]['ad_height'] = array(
      '#type' => 'textfield',
      '#title' => t('Ad Height'),
      '#description' => t('Such as 50 or for multiple sizes use a comma separated list of sizes such as 50,60'),
      '#default_value' => $leader_settings['ad_height'],
    );

    $form['tp_ads_article_leader']['tp_ads_article_leader_'.$ad]['desktop'] = array(
      '#tree' => TRUE,
      '#type' => 'fieldset',
      '#title' => t('Leader Ad for Article - Desktop'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE
    );

    $form['tp_ads_article_leader']['tp_ads_article_leader_'.$ad]['desktop']['ad_slot'] = array(
      '#type' => 'textfield',
      '#title' => t('Ad Slot'),
      '#description' => t('Such as TP_Mobile_320x50'),
      '#default_value' => $leader_settings['desktop']['ad_slot'],
    );

    $form['tp_ads_article_leader']['tp_ads_article_leader_'.$ad]['desktop']['ad_gpd_id'] = array(
      '#type' => 'textfield',
      '#title' => t('Ad GPD ID'),
      '#description' => t('Such as div-gpt-ad-1382144784236-0a'),
      '#default_value' => $leader_settings['desktop']['ad_gpd_id'],
    );

    $form['tp_ads_article_leader']['tp_ads_article_leader_'.$ad]['desktop']['ad_width'] = array(
      '#type' => 'textfield',
      '#title' => t('Ad Width'),
      '#description' => t('Such as 320 or for multiple sizes use a comma separated list of sizes such as 768,320'),
      '#default_value' => $leader_settings['desktop']['ad_width'],
    );

    $form['tp_ads_article_leader']['tp_ads_article_leader_'.$ad]['desktop']['ad_height'] = array(
      '#type' => 'textfield',
      '#title' => t('Ad Height'),
      '#description' => t('Such as 50 or for multiple sizes use a comma separated list of sizes such as 50,60'),
      '#default_value' => $leader_settings['desktop']['ad_height'],
    );

    $form['tp_ads_article_leader']['tp_ads_article_leader_'.$ad]['desktop']['selector'] = array(
      '#type' => 'textfield',
      '#title' => t('Desktop Selector Override'),
      '#description' => t('.fresh-first-ad'),
      '#default_value' => $leader_settings['desktop']['selector'],
    );

    //These are the ads that load inside the article
    $settings = variable_get('tp_ads_settings_'.$ad, '');
    //js selector
    $form['tp_ads_settings']['tp_ads_settings_'.$ad] = array(
      '#tree' => TRUE,
      '#type' => 'fieldset',
      '#title' => t('Advertisement Insertion for Ad '.($ad+1)),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE
    );

    $form['tp_ads_settings']['tp_ads_settings_'.$ad]['tp_ads_settings_selector'] = array(
      '#type' => 'textfield',
      '#title' => t('Selector for Ad Logic for Ad '.($ad+1)),
      '#default_value' => $settings['tp_ads_settings_selector'],
      '#description' => t('Selector for page')
    );

    $break = FALSE;
    $i = 0;
    //dynamicly generate the form elements
    do {
      //checks to ensures that the next one is not set
      if (!isset($settings['tp_ads_setting_'.$ad.'_'.$i]) && empty($settings['tp_ads_setting_'.$ad.'_'.$i]['ad_slot'])) {
        $break = TRUE;
        //sets each step to empty
        $ad_slot = '';
        $ad_gpd_id = '';
        $ad_width = '';
        $ad_height = '';
        $placement = '';
        $desktop_ad_slot = '';
        $desktop_ad_gpd_id = '';
        $desktop_ad_width = '';
        $desktop_ad_height = '';
        $desktop_placement = '';
      }
      else {
        //this is for the dynamic variable values
        $ad_slot = $settings['tp_ads_setting_'.$ad.'_'.$i]['ad_slot'];
        $ad_gpd_id = $settings['tp_ads_setting_'.$ad.'_'.$i]['ad_gpd_id'];
        $ad_width = $settings['tp_ads_setting_'.$ad.'_'.$i]['ad_width'];
        $ad_height = $settings['tp_ads_setting_'.$ad.'_'.$i]['ad_height'];
        $placement = $settings['tp_ads_setting_'.$ad.'_'.$i]['placement'];

        //desktop overrides
        $desktop_ad_slot = $settings['tp_ads_setting_'.$ad.'_'.$i]['desktop_overrides']['ad_slot'];
        $desktop_ad_gpd_id = $settings['tp_ads_setting_'.$ad.'_'.$i]['desktop_overrides']['ad_gpd_id'];
        $desktop_ad_width = $settings['tp_ads_setting_'.$ad.'_'.$i]['desktop_overrides']['ad_width'];
        $desktop_ad_height = $settings['tp_ads_setting_'.$ad.'_'.$i]['desktop_overrides']['ad_height'];
        $desktop_placement = $settings['tp_ads_setting_'.$ad.'_'.$i]['desktop_overrides']['placement'];
      }

      //each form item
      $form['tp_ads_settings']['tp_ads_settings_'.$ad]['tp_ads_setting_'.$ad.'_'.$i] = array(
        '#type' => 'fieldset',
        '#title' => t('Advertisement - ' . ($i + 1) .  ' - ' . (!empty($ad_slot) ? $ad_slot : 'New Advertisement')),
        '#collapsible' => TRUE,
        '#collapsed' => (!empty($ad_slot)) ? TRUE : FALSE
      );

      $form['tp_ads_settings']['tp_ads_settings_'.$ad]['tp_ads_setting_'.$ad.'_'.$i]['ad_slot'] = array(
        '#type' => 'textfield',
        '#title' => t('Ad Slot'),
        '#description' => t('Such as TP_Campaign_300x250_c'),
        '#default_value' => $ad_slot,
      );

      $form['tp_ads_settings']['tp_ads_settings_'.$ad]['tp_ads_setting_'.$ad.'_'.$i]['ad_gpd_id'] = array(
        '#type' => 'textfield',
        '#title' => t('Ad GPD ID'),
        '#description' => t('Such as div-gpt-ad-1427756284687-0'),
        '#default_value' => $ad_gpd_id,
      );

      $form['tp_ads_settings']['tp_ads_settings_'.$ad]['tp_ads_setting_'.$ad.'_'.$i]['ad_width'] = array(
        '#type' => 'textfield',
        '#title' => t('Ad Width'),
        '#description' => t('Such as 300 or for multiple sizes use a comma separated list of sizes such as 300,320'),
        '#default_value' => $ad_width,
      );

      $form['tp_ads_settings']['tp_ads_settings_'.$ad]['tp_ads_setting_'.$ad.'_'.$i]['ad_height'] = array(
        '#type' => 'textfield',
        '#title' => t('Ad Height'),
        '#description' => t('Such as 250 or for multiple sizes use a comma separated list of sizes such as 250,600'),
        '#default_value' => $ad_height,
      );

      $form['tp_ads_settings']['tp_ads_settings_'.$ad]['tp_ads_setting_'.$ad.'_'.$i]['placement'] = array(
        '#type' => 'textfield',
        '#title' => t('Placement after paragraph continue from previous ad placement'),
        '#default_value' => $placement,
      );

      $form['tp_ads_settings']['tp_ads_settings_'.$ad]['tp_ads_setting_'.$ad.'_'.$i]['desktop_overrides'] = array(
        '#type' => 'fieldset',
        '#title' => t('Desktop Advertisement'),
        '#description' => t('If empty it will use same as mobile'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE
      );

      $form['tp_ads_settings']['tp_ads_settings_'.$ad]['tp_ads_setting_'.$ad.'_'.$i]['desktop_overrides']['ad_slot'] = array(
        '#type' => 'textfield',
        '#title' => t('Ad Slot'),
        '#description' => t('Such as TP_Campaign_300x250_c'),
        '#default_value' => $desktop_ad_slot,
      );

      $form['tp_ads_settings']['tp_ads_settings_'.$ad]['tp_ads_setting_'.$ad.'_'.$i]['desktop_overrides']['ad_gpd_id'] = array(
        '#type' => 'textfield',
        '#title' => t('Ad GPD ID'),
        '#description' => t('Such as div-gpt-ad-1427756284687-0'),
        '#default_value' => $desktop_ad_gpd_id,
      );

      $form['tp_ads_settings']['tp_ads_settings_'.$ad]['tp_ads_setting_'.$ad.'_'.$i]['desktop_overrides']['ad_width'] = array(
        '#type' => 'textfield',
        '#title' => t('Ad Width'),
        '#description' => t('Such as 300 or for multiple sizes use a comma separated list of sizes such as 300,320'),
        '#default_value' => $desktop_ad_width,
      );

      $form['tp_ads_settings']['tp_ads_settings_'.$ad]['tp_ads_setting_'.$ad.'_'.$i]['desktop_overrides']['ad_height'] = array(
        '#type' => 'textfield',
        '#title' => t('Ad Height'),
        '#description' => t('Such as 250 or for multiple sizes use a comma separated list of sizes such as 250,600'),
        '#default_value' => $desktop_ad_height,
      );

      $i++;
    } while (!$break);
  }

  //adds custom submit handler to unset values that are empty
  $form['#submit'][] = 'tp_ads_admin_form_submit';
  //$form['#validate'][] = 'tp_ads_admin_form_validate';

  //returns the system form
  return system_settings_form($form);
}

/**
 *  @function:
 *    custom submit handler that it used to unset values before being saved
 */
function tp_ads_admin_form_submit(&$form, &$form_state) {
  //Loop through for each of the 5 autoload articles
  for($ad = 0; $ad < TP_ADS_NO_AUTOLOAD; $ad++) {
    //variables
    $values = $form_state['values']['tp_ads_settings_'.$ad];
    $values = array_reverse($values);
    //does for each value to unset backwards until the last one with data
    foreach ($values as $key => $value) {
      if (empty($value['ad_slot'])) {
        unset($values[$key]);
      }
      elseif(!empty($value['ad_slot'])) {
        break;
      }
    }

    //puts it back into the array
    $form_state['values']['tp_ads_settings_'.$ad] = array_reverse($values);
  }

}

/**
 *  @function:
 *    custom validation handler that it used to not allow the same ad ids
 */
function tp_ads_admin_form_validate(&$form, &$form_state) {
  //Loop through for each of the 5 autoload articles
  //There will be a lot of repitive checks, but an identical
  //ad tag will result in a broken site
  //Lets check the leader ads first
  foreach($form_state['values'] AS $name => $values) {
    if(is_array($values)){
      //The leader ads are a single array the articles are a double array
      if(strpos($name,'leader') !== FALSE) {
        $checkid = $values['ad_gpd_id'];
        $dtcheckid = $values['desktop']['ad_gpd_id'];
        //Loop through all the values again looking for doubles
        foreach($form_state['values'] AS $name2 => $values2) {
          //Do not want to check the id on itself
          if($name2 != $name) {
            //The leader ads are a single array the articles are a double array
            if(strpos($name2,'leader') !== FALSE) {
              if($values2['ad_gpd_id'] != '') {
                //Do the final check for leader ads
                if( $checkid == $values2['ad_gpd_id']
                  || $dtcheckid == $values2['ad_gpd_id'] ) {
                  //Error same gpd ids
                  form_set_error($name, 'There are ads with the same Ad GPD ID. Leader '.$name.' to Leader '.$name2);
                }
              }
              if($values2['desktop']['ad_gpd_id'] != '') {
                //Do the final check for leader ads
                if( $dtcheckid == $values2['desktop']['ad_gpd_id']
                  || $checkid == $values2['desktop']['ad_gpd_id']) {
                  //Error same gpd ids
                  form_set_error($name, 'There are ads with the same Ad GPD ID. Leader '.$name.' to Leader '.$name2);
                }
              }
            } else {
              //Now do the check for article ads
              foreach($values2 as $artn => $arti) {
                //I do not care about the selector
                if(strpos($artn, 'selector') === FALSE) {
                  //Do the final check for leader ads to article ads
                  if($arti['ad_gpd_id'] != '') {
                    //Do the final check for leader ads
                    if( $checkid == $arti['ad_gpd_id']
                      || $dtcheckid == $arti['ad_gpd_id'] ) {
                      //Error same gpd ids
                      form_set_error($name, 'There are ads with the same Ad GPD ID. Leader '.$name.' to Article '.$artn);
                    }
                  }
                  if($arti['desktop']['ad_gpd_id'] != '') {
                    //Do the final check for leader ads
                    if( $dtcheckid == $arti['desktop']['ad_gpd_id']
                      || $checkid == $arti['desktop']['ad_gpd_id']) {
                      //Error same gpd ids
                      form_set_error($name, 'There are ads with the same Ad GPD ID Desktop. Leader '.$name.' to Article '.$artn);
                    }
                  }
                }
              }
            }
          }
        }
      } else {
        //Now do the check for article ads
        foreach($values as $artn => $arti) {
          //I do not care about the selector
          if(strpos($artn, 'selector') === FALSE) {
            $checkid = $arti['ad_gpd_id'];
            $dtcheckid = $arti['desktop']['ad_gpd_id'];

            foreach($form_state['values'] AS $name2 => $values2) {
              //Do not want to check the id on itself
              if($name2 != $artn) {
                //The leader ads are a single array the articles are a double array
                if(strpos($name2,'leader') !== FALSE) {
                  if($values2['ad_gpd_id'] != '') {
                    //Do the final check for leader ads
                    if( $checkid == $values2['ad_gpd_id']
                      || $dtcheckid == $values2['ad_gpd_id'] ) {
                      //Error same gpd ids
                      form_set_error($artn, 'There are ads with the same Ad GPD ID. Article '.$artn.' to Leader '.$name2);
                    }
                  }
                  if($values2['desktop']['ad_gpd_id'] != '') {
                    //Do the final check for leader ads
                    if( $dtcheckid == $values2['desktop']['ad_gpd_id']
                      || $checkid == $values2['desktop']['ad_gpd_id']) {
                      //Error same gpd ids
                      form_set_error($name, 'There are ads with the same Ad GPD ID Desktop. Article '.$artn.' to Leader '.$name2);
                    }
                  }
                } else {
                  //Now do the check for article ads
                  foreach($values2 as $artn2 => $arti2) {
                    //I do not care about the selector
                    if(strpos($artn2, 'selector') === FALSE) {

                      if($artn2 != $artn) {
                        //Do the final check for leader ads to article ads
                        if($arti2['ad_gpd_id'] != '') {
                          //Do the final check for leader ads
                          if( $checkid == $arti2['ad_gpd_id']
                            || $dtcheckid == $arti2['ad_gpd_id'] ) {
                            //Error same gpd ids
                            form_set_error($artn, 'There are ads with the same Ad GPD ID. Article '.$artn.' to Article '.$artn2);
                          }
                        }
                        if($arti2['desktop']['ad_gpd_id'] != '') {
                          //Do the final check for leader ads
                          if( $dtcheckid == $arti['desktop']['ad_gpd_id']
                            || $checkid == $arti['desktop']['ad_gpd_id']) {
                            //Error same gpd ids
                            form_set_error($name, 'There are ads with the same Ad GPD ID Desktop. Leader '.$artn.' to Article '.$artn2);
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

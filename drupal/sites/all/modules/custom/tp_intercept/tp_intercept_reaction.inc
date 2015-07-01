<?php

/**
 *  Reaction class extends context_reaction
 */
class tp_intercept_reaction extends context_reaction {
  /**
   *  option for form not really needed.
   */
  function options_form($context) {
    $values = $this->fetch_from_context($context);
    $form = array();
    
    $form['tp_intercept_status'] = array(
      '#markup' => t('TP Intercept Code JS')
    );
    
    $form['enable_tp_intercept'] = array(
      '#type' => 'select',
      '#options' => array(
        1 => 'Enable',
      ),
      '#default_value' => $values['enable_tp_intercept']
    );
    
    return $form;
  }

  /**
   * Output a list of active contexts.
   */
  function execute() {
    //variables
    $api = variable_get('tp_intercept_js_path', 'api/intercept/intercept.js');
    
    drupal_add_js($api, array(
      'preprocess' => FALSE
    ));
  }
}

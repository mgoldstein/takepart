<?php
class omniture_reaction extends context_reaction {
  /*
   * implements context_reaction::options_form()
   *
   * Add a text area for placing variables as well as a
   * token help section that show all of avaiable tokens
   */
  function options_form($context) {
    $settings = $this->fetch_from_context($context);
    $form = array(
      '#title' => 'Omniture Variables',
      '#type' => 'fieldset'
    );
    $form['variables'] = array(
      '#title' => 'Name',
      '#type' => 'textarea',
      '#description' => t('A list of variables to set for omniture each line should be of the form VARIABLE = VALUE.  tokens can be used for the value. variables examples are s.eVar10 or s.prop5'),
      '#default_value' => isset($settings['variables'])? $settings['variables'] : 0,
    );
    $form['token_help'] = array(
      '#theme' => 'token_tree',
      '#token_types' => array('node'),

    );
    return $form;
  }

  /*
   * implements context_reaction::execute()
   *
   * go through all active context and covert the
   * stored text in to variables. making sure we replace tokens
   * before for sending it out
   */
  function execute(&$vars) {
    $settings = array();
    //grab the node object so we can use node tokens
    $node = menu_get_object();
    foreach ($this->get_contexts() as $context) {
      if (isset($context->reactions[$this->plugin])) {
        $settings = $context->reactions[$this->plugin]['variables'];
        $settings = token_replace($settings, array("node" => $node));
        $lines = explode("\n", $settings);
        foreach($lines as $line) {
          if(preg_match("/^ *(.*?) *= *(.*?) *$/", $line, $match)) {
            $variables[$match[1]] = $match[2];

          }
        }
      }
    }
    return $variables;
  }

}

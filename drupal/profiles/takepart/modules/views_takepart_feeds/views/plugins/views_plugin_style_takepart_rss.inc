<?php
/**
 * @file
 * Implements views_plugin_style for views_xml
 */

/**
 * Implements views_plugin_style
 */

//class views_plugin_style_takepart_rss extends views_plugin_style_rss {
class views_plugin_style_takepart_rss extends views_plugin_style {
    
  /**
   * Implementation of views_plugin_style::option_definition
   */
  function option_definition() {
  
    $options = parent::option_definition();
    $options['schema'] = array('default' => 'raw', 'translatable' => FALSE);
    $options['title'] = array('default' => '', 'translatable' => FALSE);
    //$options['escape_as_CDATA'] = array('default' => 'no', 'translatable' => FALSE);
    //$options['content_type'] = array('default' => 'text/xml', 'translatable' => FALSE);
    //$options['header'] = array('default' => NULL, 'translatable' => FALSE);
    return $options;
  }

  /**
   * Provide a form for setting options.
   */
  function options_form(&$form, &$form_state) {
  
    $form['schema'] = array(
      '#type' => 'radios',
      '#title' => t('XML schema'),
      '#description' => t('The schema or format of the XML data document.'),
      '#options' => views_takepart_rss_views_formats(),
      '#default_value' => $this->options['schema'],
    );
    $form['title'] = array(
          '#type' => 'textfield',
          '#title' => t('Title'),
          '#description' => t('Append this to the front of auto-generated titles.'),
          '#default_value' => $this->options['title'],
    	  '#size' => 60,
          '#maxlength' => 128,
    );
    /*
    $form['escape_as_CDATA']  = array(
      '#type' => 'radios',
      '#title' => t('Escape row content as CDATA'),
      '#description' => t('For each row in the view, escape the row field content as XML CDATA sections.'),
      '#options' => array('yes' => t('Yes'), 'no' => t('No')),
      '#default_value' => $this->options['escape_as_CDATA'],
      //'#process' => array('views_process_dependency'),
      //'#dependency' => array('edit-style-options-element-output-options' => array('nested')),
    );
    $form['header'] = array(
      '#type' => 'textarea',
      '#title' => t('XML document header'),
      '#description' => t('You can use this to place any additional lines you want after the document declaration (like !DOCTYPE.)'),
      '#default_value' => $this->options['header'],
    );
    $form['content_type'] = array(
      '#type' => 'radios',
      '#title'  => t('Content-Type'),
      '#options' => array(
        'default' => t('Default: text/xml for raw documents, text/html for OPML, application/atom+xml for Atom.'),
        'text/xml' => t('text/xml'),
        'text/html' => t('text/html'),
        'text/x-opml' => t('application/rss+xml'),
      ),
      '#default_value' => $this->options['content_type'],
      '#description' => t('The Content-Type header that will be sent with the XML output.'),
    );
    */
  }

  /**
   * Implementation of views_style_plugin::theme_functions(). Returns an array of theme functions to use.
   * for the current style plugin
   * @return array
   */
  function theme_functions() {
  
    $options = $this->options;
    //problem here:
    $hook = 'views_views_takepart_rss_style_' . $options['schema'];
    //echo $hook . "<br/>";
    //$hook = 'views_views_xml_style_' . $options['schema'];
    //echo $hook;
    //exit();
    return views_theme_functions($hook, $this->view, $this->display);
  }

  /**
   * Implements views_style_plugin::additional_theme_functions(). Returns empty array.
   * @return array
   */
  function additional_theme_functions() {
  
    return array();
  }

  /**
   * Implementation of view_style_plugin::render()
   */
  function render() {
    
  
    $view = $this->view;
    $options = $this->options;
    $field = $view->field;

    $rows = array();
    foreach ($view->result as $count => $row) {
      $view->row_index = $count;
      //@todo: make this a row_plugin?:
      $rows[] = _views_takepart_rss_render_fields($view, $row);
      
    }
   
    
    unset($view->row_index);
     
    $render = theme($this->theme_functions(), array('view' => $view, 'options' => $options, 'rows' => $rows));
   
    return ($render);
    
  }

}
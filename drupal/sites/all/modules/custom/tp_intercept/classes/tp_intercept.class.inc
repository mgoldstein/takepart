<?php

class tp_intercept {
  public $script;
  public $freq;
  public $js_var = array();
  
  /**
   *  @method:
   *    Method used to construct the tp_intercept object
   */
  public function __construct() {
    $this->script = '';
    $this->freq = '';
  }
  
  /**
   *  @method:
   *    Method use to add correct head to the page to render out
   */
  private function _add_header() {
    drupal_add_http_header('Content-Type', 'text/javascript; utf-8');
  }
  
  /**
   *  @method:
   *    Method used to sanitize the value to remove unneeded data
   */
  private function _sanitize($value) {
    $value = trim($value);
    $value = str_replace(array("\r", "\n"), '', $value);
    $value = str_replace('"', '\'', $value);
    
    return $value;
  }
  
  /**
   *  @method:
   *    Method used to get cache or set cache version
   */
  public function cache($op = 'get', $data) {
    $cache_cid = 'tp_intercept';
    $cache_time = variable_get('tp_intercept_cache_time', 60);
    
    switch ($op) {
      case 'set':
        //set if op
        cache_set($cache_cid, $data,'cache', REQUEST_TIME + ($cache_time * 60));
        break;
      default:
        //get by default
        $cache = cache_get($cache_cid, 'cache');
        return $cache;
        break;
    }
  }
  
  /**
   *  @method:
   *    Method used to generate the JS file
   */
  public function generate_js() {
    $cache = $this->cache();
    $break_cache = $_GET['bypass'];
    
    //if cache is empty then generate
    if (empty($cache) || $break_cache) {
      $output = '';
      //adds the necessary header for javascript
      $this->_add_header();
      
      //adds the data for the js template
      $this->js_vars('script', $this->script);
      $this->js_vars('freq', $this->freq);
      
      //calls the js theme
      $output = theme('tp_intercept_js',
        array(
          'vars' => implode($this->js_var, ", ")
        )
      );
    }
    //otherwise set output to cache version
    else {
      $output = $cache;
    }

    //returns the output  
    print $output;
    
    //call to exit out of everything
    drupal_exit();
  }
  
  /**
   *  @method:
   *    Method used to add values into javascript format
   */
  public function js_vars($key, $value = '""') {
    if (empty($value)) {
      $value = '';
    }

    //calls to sanitize the value
    $value = $this->_sanitize($value);
    
    //adds the variables into javascript format
    $this->js_var[$key] = 'tp_inter_' . $key . ' = "' . $value . '"';
  }
}

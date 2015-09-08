<?php

/**
 *  @class:
 *    This class provides a custom obj for oembed for takepart.
 *    Object's info will allow the user to override the info from video if needed for the output.
 *
 *  @uses:
 *    $oembed = new TPVideoOembed($url, [$format]);
 *    $oembed->add_info(array(
 *      'support' => 'test'
 *    ));
 *    echo $oembed->get_output();
 *    drupal_exit();
 */
class TPVideoOembed {
  //obj variables
  public $url;
  public $format;
  public $standard_info;
  public $info;
  public $video;
  public $data;
  public $status;
  public $secure_request;
  
  /**
   *  @method:
   *    Public constructor
   */
  public function __construct($url, $format = 'json') {
    $this->url = str_replace('www.', '', $url);
    $this->format = $format;
    $this->_init();
  }
  
  /**
   *  @method:
   *    Private function that sets the standard information
   */
  private function _init() {
    //global variable
    global $base_url;
    
    $secure = (strpos($this->url, 'https') === FALSE) ? 0 : 1;
    
    //declares the standard information for all videos
    $this->standard_info = array(
      'url' => $this->url,
      'format' => $this->format,
      'type' => 'video',
      'version' => '1.0',
      'provider_name' => variable_get('site_name', ''),
      'provider_url' => $base_url,
      'html' => '',
      'secure_request' => $secure
    );
    
    //auto set to fail
    $this->set_status();
  }
  
  /**
   *  @method:
   *    Private method that is used to set and get the cache info for the video
   */
  private function _cached($action = 'get', $data = array()) {
    $nid = $this->get_nid();
    $width = '';
    
    //ensures that it caches the width version
    if (is_numeric($_GET['width'])) {
      $width = '_' . $_GET['width'];
    }
    else if ($_GET['width'] == 'full') {
      $width = '_full';
    }
    
    //sets a cache version
    if (empty($nid)) {
      $cache_cid = 'tp_oembed_no_node';
    }
    else {
      $cache_cid = 'tp_oembed_' . $nid . $width . $this->standard_info['secure_request'];
    }

    $cache_time = variable_get('takepart_oembed_cache_time', 10);
    
    //switch based on action
    switch ($action) {
      //sets the cached and cache for x minutes
      case 'set':
        cache_set($cache_cid, $data,'cache', REQUEST_TIME + ($cache_time * 60));
        break;
      //returns cache if available
      default:
        $cache = cache_get($cache_cid, 'cache');
        return $cache;
        break;
    }

  }
  
  /**
   *  @method:
   *    This method is used to return the output of the obj
   */
  public function get_output() {
    //calls the process functions
    $this->get_video();
    $this->parse_obj();
    
    //switch based on format type
    switch ($this->format) {
      //case for xml
      case 'xml':
        drupal_add_http_header('Content-Type', 'application/xml; charset=utf-8');
        return $this->getXML();
        break;
      //case for default - json
      default:
        drupal_add_http_header('Content-Type', 'application/json');
        return drupal_json_encode($this->getJSON());
        break;
    }
  }
  
  /**
   *  @method:
   *    Loads additional info into the obj
   */
  public function add_info($array = array()) {
    $this->info = $array;
  }
  
  /**
   *  @method:
   *    Public method that is used to return the nid
   *
   *    @param:
   *      node_requested = TRUE will return the node obj if found
   */
  public function get_nid($node_requested = FALSE) {
    //default variable
    $requested_url = '';
    
    //load global base url
    global $base_url;
    global $base_root;
        
    //check if url exist
    $original_url = $this->url;
    
    //adding watchdog debug
    if (variable_get('takepart_oembed_debug_mode', 0)) {
      watchdog('Takepart Oembed Debug','Requested Obj: <pre>' . print_r($this, 1) . '</pre>');
    }
    
    $url_params = parse_url($original_url);
    
    //adding watchdog debug
    if (variable_get('takepart_oembed_debug_mode', 0)) {
      watchdog('Takepart Oembed Debug','Base URL: <pre>' . print_r($base_url, 1) . '</pre>');
    }

    $original_url = ltrim($url_params['path'], '/');

    //lookups the path
    $url = drupal_lookup_path('source', $original_url);

    //adding watchdog debug
    if (variable_get('takepart_oembed_debug_mode', 0)) {
      watchdog('Takepart Oembed Debug','Node Path: <pre>' . print_r($url, 1) . '</pre>');
    }
    
    //ensures that the system url is returned
    if (!empty($url)) {
      $node_id = str_replace('node/', '', $url);
      $node = node_load($node_id);
      
      //gets the requested node if available
      if ($node_requested) {
        $node = node_load($node_id);
        return $node;
      }
      else {
        return $node_id;
      }
    }

    return NULL;
  }
  
  /**
   *  @method:
   *    Private method that is used to return the xml
   */
  private function getXML() {
    //declares a new document
    $oembed_xml = new DOMDocument("1.0", "UTF-8");
    $oembed_xml->formatOutput = true;
    
    //creates the oembed container
    $oembed_container = $oembed_xml->createElement('oembed');
    
    //adds each of the data into the container
    foreach ($this->data as $key => $value) {
      $key_type = $oembed_xml->createElement($key, $value);
      $oembed_container->appendChild($key_type);
    }
    
    //appends the container to the doc
    $oembed_xml->appendChild($oembed_container);
    
    //returns the xml
    return $oembed_xml->saveXML();
  }
  
  /**
   *  @method:
   *    Private method that will return the json data
   */
  private function getJSON() {
    return $this->data;
  }
  
  /**
   *  @method:
   *    Private method that is used to retrieve the field_video from the node video
   */
  private function get_video() {
    global $base_url;
    
    //allows for breaking cache
    if ($_GET['break_cache'] != 'true') {
      //gets cached if available
      $cached = $this->_cached();
      
      //if cached version then return the cache
      if (!empty($cached)) {
        $this->video = $cached->data;
        
        //mark this as success if video data is found
        if (!empty($this->video)) {
          $this->set_status(1);
        }
        
        return;
      }
    }
    
    //returns node
    $node = $this->get_nid(TRUE);
    
    //ensures that the node is an object and only serve up video content types
    if (is_object($node) && $node->type == 'video') {
      $items = field_get_items('node', $node, 'field_video');
      $file = reset($items);
      
      //only continue if the file is found
      if (!empty($file)) {
        $file = file_load(array($file['fid']));

        //ensures that there is a file
        if (empty($file)) {
          $this->_cached('set', array());
          return;
        }
        
        //gets the video's spec
        $height = $file->tp_videos_metadata->height;
        $width = $file->tp_videos_metadata->width;
        
        //allows for override to width ratio
        if (is_numeric($_GET['width'])) {
          $ratio = 1 / ($width / $_GET['width']);
          $height = round($height * $ratio);
          $width = round($_GET['width']);
        }
        
        //allows for width to auto set to full 100%
        if ($_GET['width'] == 'full') {
          $width = '100%';
          $height = 'auto';
        }
        
        //creates the iframe markup for the video
        $src_url = $base_url . '/entity_iframe/node/' . $node->nid;
        list(, $resource) = explode('://', $src_url, 2);
        
        //sets schema type based on request
        $scheme = $this->standard_info['secure_request'] ? 'https://' : 'http://';
        
        $html = theme('html_tag', array(
          'element' => array(
            '#tag' => 'iframe',
            '#value' => '',
            '#attributes' => array(
              'width' => $width,
              'height' => $height,
              'src' => $scheme . $resource,
              'frameborder' => '0',
              'class' => 'entity_iframe entity_iframe_node',
              'id' => 'entity_iframe_node_' . $node->nid
        ))));
        
        //creates html wrapper for html
        $html_wrapper = theme('html_tag', array(
          'element' => array(
            '#tag' => 'div',
            '#value' => $html,
            '#attributes' => array(
              'class' => 'takepart-oembed-wrapper',
        ))));

        //creates the video array
        $video = array(
          'title' => $file->filename,
          'width' => $width,
          'height' => $height,
          'html' => $html_wrapper
        );
      
        //adds the video info into this object
        $this->video = $video;
        
        //sets the status to success
        $this->set_status(1);
        
        //cache the result to optimize on next
        $this->_cached('set', $video);
      }
    }
    else {
      $this->_cached('set', array());
    }
  }
  
  /**
   *  @method:
   *    Private method that will set the status message so there is no redundant code
   */
  private function set_status($status = '') {
    //validates first
    if (empty($this->url)) {
      $status = 'no-url';
    }
  
    //switch based on status
    switch ($status) {
      case 'no-url':
        $this->status = array(
          'message' => t('URL required'),
          'status' => 0
        );
        break;
      //successful
      case 1:
        $this->status = array(
          'message' => t('Video Retrieved'),
          'status' => 1
        );
        break;
      //failed
      default:
        $this->status = array(
          'message' => t('No video on requested URL'),
          'status' => 0
        );
        break;
    }
  }
  
  /**
   *  @method:
   *    Private function that is used to parse this obj
   */
  private function parse_obj() {
    //does for each group and adds it to single level
    $values = array(
      'standard_info',
      'video',
      'info',
      'status'
    );
    
    //calls custom array walk function
    array_walk($values, '_takepart_oembed_array_walk', $this);
  }
}

/**
 *  @function:
 *    Function is used to array walk through the keys to add data to the object.
 *    Object that is used is TPVideoOembed
 */
function _takepart_oembed_array_walk($value, $key, &$obj) {
  //only add if there is data
  if (!empty($obj->$value)) {
    foreach ($obj->$value as $value_key => $value_value) {
      $obj->data[$value_key] = $value_value;
    }
  }
}
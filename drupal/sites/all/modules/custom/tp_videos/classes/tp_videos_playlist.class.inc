<?php

/**
 *  This class is used to generate a list with a specific filter
 */
class tp_playlist_filter {
  //variables
  public $filter_count;
  public $filter_arr;
  public $videos_arr;
  public $max_items;
  public $filter_sort;

  /**
   *  Class contructor
   *
   *  @param:
   *    max_items = max_items for return is 0
   */
  public function __construct($max_items = 0, $sort = 'DESC') {
    $this->reset_class();
    $this->max_items = $max_items;
    $this->filter_sort = $sort;
  }
  
  /**
   *  @method:
   *    This method is used to reset the obj
   */
  public function reset_class() {
    $this->filter_count = 0;
    $this->filter_arr = array();
    $this->videos_arr = array();
  }
  
  /**
   *  @method:
   *    Add the nid into the system
   */
  public function add_video_nid($nid) {
    //ensures that the key and value are the same so there are no duplicates
    $this->videos_arr[$nid] = $nid;
  }
  
  /**
   *  @method:
   *    This function will return all set nids in the obj
   */
  public function get_video_nids() {
    $result = array();
    
    if (!empty($this->videos_arr)) {
      foreach ($this->videos_arr as $key => $value) {
        $result[] = array(
          'nid' => $key,
          'access' => TRUE
        );
      }
    }
    
    return $result;
  }
  
  /**
   *  @method:
   *    This method is used to add a new filter 
   */
  public function add_filter($filter) {
    //ensures that no empty filter is added
    if (!empty($filter)) {
      $this->filter_arr[] = $filter;
      $this->filter_count++;
    }
  }
  
  /**
   *  @method:
   *    This method is used to return the filters list
   */
  public function get_filters() {
    return $this->filter_arr;
  }
  
  /**
   *  @method:
   *    This method is used to return the results in an array list
   *
   *    @param:
   *      video_output = TRUE will format to match tp_videos.module
   */
  public function get_results($video_output = TRUE) {
    //default variables
    $result = array();
    $node_types = array(
      'video'
    );
    
    //defines a new query
    $videos = new EntityFieldQuery();
    $videos->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', $node_types)
      ->propertyCondition('status', 1)
      ->propertyOrderBy('created', 'DESC')
      ->age(FIELD_LOAD_CURRENT);
    
    ////sets a max to return
    $get_nodes = $this->max_items - count($this->videos_arr);
    if ($get_nodes < 0) {
      $get_nodes = 0;
    }

    //adds filter into the query
    foreach ($this->filter_arr as $key => $value) {
      //variables
      $target_id = $value['target_id'];
      $machine_name = $value['vocab']->machine_name;
      $table = 'field_data_field_' . $machine_name;
      
      //fix for system as table is free_tag but machine name is free_tags
      if ($machine_name == 'free_tags') {
        $machine_name = 'free_tag';
      }
    
      $videos->fieldCondition('field_' . $machine_name, 'tid', $target_id);
    }
    
    $videos->range(0, $get_nodes);

    //execute the query
    $result = $videos->execute();
    
    //return output
    $manual = $this->get_video_nids();

    if ($video_output) {
      $sanitized_list = array_merge($manual, $this->output_sanitizer($result));
      return $sanitized_list;
    }
    else {
      return $result;
    }
  }
  
  /**
   *  @method:
   *    This method is used to map the array to the output
   */
  private function output_sanitizer($result = array()) {
    $output = array();
    
    //sanitizes the output to match the tp_videos.module
    if (!empty($result['node'])) {
      foreach ($result['node'] as $key => $value) {
        $output[] = array(
          'nid' => $key,
          'access' => TRUE
        );
      }
    }

    //reverse latest desc
    if ($this->filter_sort == 'ASC') {
      $output = array_reverse($output);
    }

    return $output;
  }
}
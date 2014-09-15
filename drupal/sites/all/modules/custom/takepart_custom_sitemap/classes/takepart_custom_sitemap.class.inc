<?php

/**
 *  General class for video sitemap
 */
class VideoSiteMap {
  //variables
  public $urlset;
  public $items;
  
  /**
   *  Class contructor to initialize urlset
   */
  public function __construct() {
    $this->urlset = "http://www.sitemaps.org/schemas/sitemap/0.9";
  }

  /**
   *  @method:
   *    Class function for adding video items into the list.
   *    No validation.
   */
  public function add_video_item($item = array()) {
    $this->items[] = $item;
  }

  /**
   *  @method:
   *    Private method for generating the items into the xml
   */
  private function get_video_items(&$xml, $root) {
    $prefix = 'video:';
    
    //does for each item in the loop
    foreach ($this->items as $item => $values) {
      $sitemap_item = $xml->createElement("url");
      
      //creates location element
      $loc = $xml->createElement('loc', $values['loc']);
      $sitemap_item->appendChild($loc);
      
      //creates container
      $video = $xml->createElement($prefix . 'video');
      
      //adds each key into the video element
      if (isset($values['keys'])) {
        foreach ($values['keys'] as $key => $key_value) {
          $video_key = $xml->createElement($prefix . $key, $key_value);
          $video->appendChild($video_key);
        }
      }
      
      $sitemap_item->appendChild($video);
      $root->appendChild($sitemap_item);
    }
  }

  /**
   *  @method:
   *    This method is used to call the method.
   */
  public function generate_xml() {
    //default variables
    $result = NULL;
    
    //declares a new doc
    $sitemap = new DOMDocument("1.0", "UTF-8");
    $sitemap->formatOutput = true;
    
    //initial urlset
    $root = $sitemap->createElementNS($this->urlset, "urlset");
    $root->setAttribute('xmlns:video', "http://www.google.com/schemas/sitemap-video/1.1");

    //calls private function to generate the items
    self::get_video_items($sitemap, $root);

    $sitemap->appendChild($root);    
    $result = $sitemap->saveXML();
    
    return $result;
  }
}
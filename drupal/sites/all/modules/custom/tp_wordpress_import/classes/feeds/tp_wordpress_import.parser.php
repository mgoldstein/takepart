<?php

/**
 *  @class:
 *    Class extends the feeds parser to allow takepart to have a custom xml importer
 */
class tp_wordpress_import_parser extends FeedsParser {
  /**
   *  @method:
   *    This method is used to parse the data
   */
  public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    //grab the raw data from the batch
    $raw_data = $fetcher_result->getRaw();
    $file_path = $fetcher_result->getFilePath();
    
    //parses the extension correctly
    $file_path = pathinfo($file_path);
    $file_type = $file_path['extension'];
    
    //declares new variables
    $parser_result = new FeedsParserResult();
    $items = array();
    
    //switch based on file type
    switch ($file_type) {
      case 'xml':
        //declares the new domdocument
        $rss = new DOMDocument();
        $rss->loadXML($raw_data);
        $items = array();

        //does for each of the elements
        foreach ($rss->getElementsByTagName('item') as $node) {
          //variables
          $creator = $node->getElementsByTagName('creator')->item(0)->nodeValue;
          $content_prefix_var = variable_get('tp_wordpress_import_content_prefix', '<i>This article was written by @author and it originally appeared on Dowser.org; a website focused on the practical and human elements of social innovation.</i>');
          
          //ensures that the message is different if user is admin
          if ($creator == 'admin') {
            $content_prefix_var = variable_get('tp_wordpress_import_content_admin_prefix', "<i>This article originally appeared on Dowser.org; a website focused on the practical and human elements of social innovation.</i>");
          }
          
          $content_prefix = theme('html_tag', array(
            'element' => array(
              '#tag' => 'p',
              '#value' => t($content_prefix_var, array('@author' => $creator)),
              '#attributes' => array(
                'class' => 'importer-author',
          ))));
          
          $allowed_tags = variable_get('tp_wordpress_import_allow_tags', '<i><iframe><a><h1><h2><h3><h4><h5>');
        
          //creates the item and adds it into the list
          //@dev: this area is where the items will be set to allow users to MAP items to the correct node.
          //use NODE mapping to map items such as title(xml) => title (node)
          $content = preg_replace("/\[youtube\](.*?)\[\/youtube]/s", " ", $node->getElementsByTagName('encoded')->item(0)->nodeValue);
          $item = array (
            'title' => $node->getElementsByTagName('title')->item(0)->nodeValue,
            'author' => variable_get('tp_wordpress_import_author_nid', ''), 
            'creator' => $creator,
            'link' => $node->getElementsByTagName('link')->item(0)->nodeValue,
            'pubDate' => $node->getElementsByTagName('pubDate')->item(0)->nodeValue,
            'description' => $node->getElementsByTagName('description')->item(0)->nodeValue,
            'content' => $content_prefix . nl2br(strip_tags($content, $allowed_tags)),
            'admin_tag' => variable_get('tp_wordpress_import_admin_tag', 'Dowser'),
            'tagging' => variable_get('tp_wordpress_import_tagging', 'Social Justice')
          );
          
          //allows other modules to alter the item before its added
          drupal_alter('tp_wordpress_import_item', $item, $node);
          
          //adds current item into the items array
          $items[] = $item;
        }
        break;
    }
    
    $parser_result->items = $items;
    
    //returns the parsed item
    return $parser_result;
  }
}
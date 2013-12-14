<?php
  if($variables['items'] != NULL){
    $authors = '';
    $number_of_authors = count($variables['items']);
    $authors .= '<span' . $variables['content_attributes'] . '>';
    foreach ($variables['items'] as $delta => $item) {
      $authors .= '<span class="byline-author"' . $variables['item_attributes'][$delta] . '>';
      $author_node = node_load($item['nid']);
      $author_path = drupal_get_path_alias('node/'. $author_node->nid);
      $authors .= l($author_node->title, $author_path, array(
        'attributes' => array(
            'rel' => 'author'
            ) 
        ) );
      $authors .= '</span>';
      // add commas for lists of 3 or greater ($delta is zero-indexed)
      $authors .= ($number_of_authors > 2 && $delta < $number_of_authors - 2 ) ? ', ' :'';
      // add 'and' for lists of 2 or greater ($delta is zero-indexed)
      $authors .= ($number_of_authors > 1 && $delta == $number_of_authors - 2 ) ? ' and ' :'';
    }
    $authors .= '</span>';

    // Get first Author image  field_profile_photo
    $author_node = node_load($items[0]['nid']);

    $thumb = file_load($author_node->field_profile_photo['und'][0]['fid']);
    $thumb_src = image_style_url('thumbnail_v2', $thumb->uri);//TODO: what image style are authors using?
    $author_path = drupal_get_path_alias('node/'. $author_node->nid);

    $bio_link = l('full bio', $author_path, array(
        'attributes' => array(
            'class' => array('more')
            ) 
        ));
    $social_links = '';
    if(!empty($author_node->field_follow_twitter['und'][0]['url'])){
      $social_links .= l('<span class="social-twitter-black"></span>', $author_node->field_follow_twitter['und'][0]['url'], array('html' => true, 'attributes' => array('target' => '_blank', 'title' => $author_node->field_follow_twitter['und'][0]['title'] )));
    }
    if(!empty($author_node->field_follow_google['und'][0]['url'])){
      $social_links .= l('<span class="social-googleplus-black"></span>', $author_node->field_follow_google['und'][0]['url'], array('html' => true, 'attributes' => array('target' => '_blank', 'title' => $author_node->field_follow_google['und'][0]['title'] )));
    }
  }
?>
<?php if($variables['items'] != NULL): ?>
<div class="author-bio">
  <date class="date" itemprop="datePublished" datetime="<?php print date('c', $entity->created); ?>"><?php print date('F d, Y',$entity->created) ?></date>
  <span class="byline author <?php print $variables['classes']?>" <?php print $variables['attributes']?>>
    By <?php print $authors; ?>
  </span>
  <div class="bio-inner">
    <div class="profile-photo"><img src="<?php print $thumb_src; ?>"></div>
    <div class="bio">
      <?php print $author_node->body['und'][0]['summary']; ?>
      <div class="more-links">
	<?php print $bio_link; ?>
	<?php if (!empty($social_links)) : ?>
	<span class="more">follow me
	  <?php print $social_links; ?>
	</span>
	<? endif; ?>
       </div>
    </div>
  </div>
</div>
<?php endif; ?>

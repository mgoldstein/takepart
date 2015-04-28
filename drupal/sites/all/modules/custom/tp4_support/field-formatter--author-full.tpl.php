<?php
  if($variables['items'] != NULL){

		$authors = array();

    $number_of_authors = count($variables['items']);

    $byline = '<span' . $variables['content_attributes'] . '>';

    foreach ($variables['items'] as $delta => $item) {
      $byline .= '<span class="byline-author"' . $variables['item_attributes'][$delta] . '>';
      $author_node = node_load($item['nid']);
      $author_path = drupal_get_path_alias('node/'. $author_node->nid);
      $byline .= l($author_node->title, $author_path, array(
        'attributes' => array(
            'rel' => 'author'
					)
        )
      );
      $byline .= '</span>';
      // add commas for lists of 3 or greater ($delta is zero-indexed)
      $byline .= ($number_of_authors > 2 && $delta < $number_of_authors - 2 ) ? ', ' :'';
      // add 'and' for lists of 2 or greater ($delta is zero-indexed)
      $byline .= ($number_of_authors > 1 && $delta == $number_of_authors - 2 ) ? ' and ' :'';

			$thumb = file_load($author_node->field_profile_photo['und'][0]['fid']);

	    $social_links = '';

	    if(!empty($author_node->field_follow_twitter['und'][0]['url'])){
	      $social_links .= l('<span class="social-twitter-black"></span>', $author_node->field_follow_twitter['und'][0]['url'], array('html' => TRUE, 'absolute' => TRUE, 'external' => TRUE,'attributes' => array('target' => '_blank', 'title' => $author_node->field_follow_twitter['und'][0]['title'] )));
	    }

	    if(!empty($author_node->field_follow_google['und'][0]['url'])){
	      $social_links .= l('<span class="social-googleplus-black"></span>', $author_node->field_follow_google['und'][0]['url'], array('html' => TRUE, 'absolute' => TRUE, 'external' => TRUE, 'attributes' => array('target' => '_blank', 'title' => $author_node->field_follow_google['und'][0]['title'] )));
	    }

			$authors[] = array(
				'summary' => $author_node->body['und'][0]['summary'],
				'thumb' => image_style_url('thumbnail_v2', $thumb->uri),
				'path' => drupal_get_path_alias('node/'. $author_node->nid),
				'bio_link' => l('full bio', $author_path, array(
	        'attributes' => array(
	            'class' => array('more')
	          ) 
	        )
	      ),
	      'social_links' => $social_links,
			);

    }
    $byline .= '</span>';
  }
?>
<?php if($variables['items'] != NULL): ?>
<div class="author-bio">
  <date class="date" itemprop="datePublished" datetime="<?php print date('c', $entity->created); ?>"><?php print date('F d, Y',$entity->created) ?></date>
  <span class="byline author <?php print $variables['classes']?>" <?php print $variables['attributes']?>>
    By <?php print $byline; ?>
  </span>
<?php foreach($authors as $author): ?>
  <div class="bio-inner">
    <div class="profile-photo"><img src="<?php print $author['thumb_src']; ?>"></div>
    <div class="bio">
      <?php print $author['summary']; ?>
      <div class="more-links">
	<?php print $author['bio_link']; ?>
	<?php if (!empty($author['social_links'])) : ?>
	<span class="more">follow me
	  <?php print $author['social_links']; ?>
	</span>
	<?php endif; ?>
       </div>
    </div>
  </div>
<?php endforeach; ?>
</div>
<?php endif; ?>

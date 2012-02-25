<?php if (!empty($pre_object)) print render($pre_object) ?>
<div class='<?php print $classes ?> clearfix node-embedded' <?php print ($attributes) ?>>
    <div class="embedded-gallery-header">Related Gallery</div>
  <?php
   print render($content['field_photo_gallery_slideshow']);
   print render($content['field_promo_headline']);
   print render($content['field_promo_text']);
   print l('See Full Gallery', $uri['path'], array('attributes' => array('class' => array('see-full-gallery'))) );
  ?>
</div>
<?php if (!empty($post_object)) print render($post_object) ?>

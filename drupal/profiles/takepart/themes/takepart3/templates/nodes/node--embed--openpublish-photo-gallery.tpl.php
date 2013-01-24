<?php if (!empty($pre_object))
    print render($pre_object) ?>
<div class="embed-gallery-wrapper">
    <div class='<?php print $classes ?> clearfix node-embedded' <?php print ($attributes) ?>>
        <div class="embedded-gallery-header">Related Gallery</div>
        <?php
        print render($content['field_photo_gallery_slideshow']);
        // print render($content['field_promo_headline']);
        $headline = l($field_promo_headline[0]['safe_value'], 'node/'.$nid, array('attributes' => array('class' => array('gallery-headline') ), 'html' => TRUE));
        print render($headline);
        print render($content['field_promo_text']);
        print l('See Full Gallery', 'node/'.$nid, array('attributes' => array('class' => array('see-full-gallery'))));
        ?>
    </div>
</div>
<?php 
if (!empty($post_object)) {
    print render($post_object);
}
dpm($node);
?>

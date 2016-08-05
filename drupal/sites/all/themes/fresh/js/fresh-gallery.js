/**
 * @file
 * A JavaScript file for photo gallery on fresh.
 *
 */

(function ($, Drupal, window, document, undefined) {
  $(document).ready(function(){

    var galleryData = {
      "title": $('.node-fresh-gallery').attr('data-tp-og-title'),
      "adTag": "TP_ROS_728x90_1_Responsive",
      "adFrequency": 2
    };

    var jsonId = $('.node-fresh-gallery').attr('data-ddl-page-id');
    galleryData.photos = eval('gallery_' + jsonId + '_json');

    var galleryElement = $(".gallery-wrapper").get(0);

    showImageGallery(galleryData, galleryElement);
  });

})(jQuery, Drupal, this, this.document);

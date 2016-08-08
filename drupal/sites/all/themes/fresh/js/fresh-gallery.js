/**
 * @file
 * A JavaScript file for photo gallery on fresh.
 *
 */

(function ($, Drupal, window, document, undefined) {
  $(document).ready(function(){

    // Build the object we need.
    var galleryData = {
      "title": $('.node-fresh-gallery').attr('data-tp-og-title'),
      "adTag": Drupal.settings.tp_ads_fresh_gallery.tp_ad_single_tag,
      "adFrequency": Drupal.settings.tp_ads_fresh_gallery.tp_ad_single_freq
    };

    var jsonId = $('.node-fresh-gallery').attr('data-ddl-page-id');
    galleryData.photos = eval('gallery_' + jsonId + '_json');

    var galleryElement = $(".gallery-wrapper").get(0);

    showImageGallery(galleryData, galleryElement);
  });

})(jQuery, Drupal, this, this.document);

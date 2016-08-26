/**
 * @file
 * A JavaScript file for photo gallery on fresh.
 *
 */
(function ($, Drupal, window, document, undefined) {
  $(document).ready(function () {
    if ($('.node-fresh-gallery').length > 0) {
      // Build the object we need.
      var page_url = $('.node-fresh-gallery').data('tpOgUrl');
      var adMeta = Drupal.settings.tpAutoScroll[0]['auto_updates'][page_url]['targets'];

      var galleryData = {
        "title": $('.node-fresh-gallery').attr('data-tp-og-title'),
        "adTag": Drupal.settings.tp_ads_fresh_gallery.tp_ad_single_tag,
        "adFrequency": Drupal.settings.tp_ads_fresh_gallery.tp_ad_single_freq,
        "adMeta": adMeta,
      };


        var jsonId = $('.node-fresh-gallery').attr('data-ddl-page-id');
        galleryData.images = eval('gallery_' + jsonId + '_json.images');

        var galleryElement = $(".gallery-wrapper").get(0);

        showImageGallery(galleryData, galleryElement);
        $('.node-fresh-gallery').addClass("gallery-processed");

      if (!digitalData.page.pageInfo.gallery) {
        digitalData.page.pageInfo.gallery = {};
      }

      digitalData.page.pageInfo.gallery.slideCount = galleryData.images.length;
      digitalData.page.pageInfo.gallery.viewType = 'Single Page';
      digitalData.page.pageInfo.gallery.shareType = 'Gallery';
    }
  });

})(jQuery, Drupal, this, this.document);

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

      if (typeof Drupal.settings.tpAutoScroll[0]['auto_updates'][page_url] == 'undefined') {
        var adMeta = null;
      }
      else {
        var adMeta = Drupal.settings.tpAutoScroll[0]['auto_updates'][page_url]['targets'];

        //Don't pass an array if there is only one element in the ad targeting
        if (Array.isArray(adMeta.FreeTag)) {
          adMeta.FreeTag = adMeta.FreeTag[0];
        }
        else {
          adMeta.FreeTag = JSON.parse(adMeta.FreeTag);
        }
        if (Array.isArray(adMeta.Topic)) {
          adMeta.Topic = adMeta.Topic[0];
        }
        else {
          adMeta.Topic = JSON.parse(adMeta.Topic);
        }
        if (Array.isArray(adMeta.Series)) {
          adMeta.Series = adMeta.Series[0];
        }
        else {
          adMeta.Series = JSON.parse(adMeta.Series);
        }
        if (Array.isArray(adMeta.Sponsor)) {
          adMeta.Sponsor = adMeta.Sponsor[0];
        }
        else {
          adMeta.Sponsor = JSON.parse(adMeta.Sponsor);
        }
      }

      var galleryData = {
        "title": $('.node-fresh-gallery').attr('data-tp-og-title'),
        "subhead": $('.node-fresh-gallery').attr('data-tp-og-description'),
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

    }
  });

})(jQuery, Drupal, this, this.document);


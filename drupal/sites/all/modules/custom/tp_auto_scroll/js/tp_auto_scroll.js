/**
 * @file
 * A JavaScript file for autoscroll.
 *
 */

(function ($, Drupal, window, document, undefined) {

  Drupal.behaviors.tpAutoScroll = {
    attach: function(context, settings) {

      /* Settings need to be set */
      if(Drupal.settings.tpAutoScroll.length == 1) {
        var settings = Drupal.settings.tpAutoScroll[0];
        var alreadyloading = false;
        var page = -1;
        var page_limit = settings.limit - 1;

        $(window).scroll(function() {
          var $window = $(window),
            elTop = $('#next-article').offset().top;

          /* when the page scrolls to within 480px of #next-article */
          if ($window.scrollTop() + $(window).height() + 480 > elTop && page < page_limit) {
            if (alreadyloading == false) {

              /* Set the URL */
              var url = settings.articles[page + 1];
              alreadyloading = true;
              $.post(url, function(data) {
                /* Where to post */
                $('#next-article').before(data);
                alreadyloading = false;
                page++;
              });
            }
          }
        });
      }
    }
  }

})(jQuery, Drupal, this, this.document);
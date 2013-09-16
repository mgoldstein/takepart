(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.expandJudges = {
    attach: function (context) {
      $(".show-more").click(function () {
          if($(this).prev().hasClass("show-more-height")) {
              $(this).text("See Less");
          } else {
              $(this).text("See More");
          }

          $(this).prev().toggleClass("show-more-height");
      });
    }
  }
})(jQuery, Drupal, this, this.document);












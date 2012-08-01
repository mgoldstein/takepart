(function ($) {
  Drupal.behaviors.petitionReadMore = {
    attach: function (context, settings) {
      $('div.node-petition-action').once('petition-read-more-processed', function (index) {
        var nid = $(this).attr('nid');
        var readMore = $('<span id="read-more-' + nid + '"> <a href="#">Read more.</a></span>');
        $('div.field-name-body div.field-item', this).append(readMore);
        var tabs = $('div.group-petition-tabs', this);
        $('a', readMore).click({tabs: tabs}, function (event) {
          var tabs = event.data['tabs'];
          event.preventDefault();
          $('.group-about.field-group-htab', tabs).data('horizontalTab').tabShow();
          $('html,body').animate({scrollTop:$(tabs).offset().top}, 500);
        });
      });
    }
  }
})(jQuery);

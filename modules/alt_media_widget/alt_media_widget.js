(function($) {

Drupal.behaviors.alt_media_widget = {
  attach: function(context) {
    $(".media-dialog-wrapper div").bind("close", function(e) {
      $(this).parent().dialog('destroy');
    });
    $(".media-dialog-wrapper div").bind("open", function(e) {
      $(this).parent().dialog({
        title: 'Edit Meta Data',
      //  autoOpen: false,
      //  height: 400,
        hide: 'slide',
        show: 'slide',
        width: $('body').width() - 40,
        modal: true,
        dialogClass: 'media_dialog'
      });
    });
  },
};

})(jQuery);

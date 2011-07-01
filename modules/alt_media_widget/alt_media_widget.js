(function($) {

Drupal.behaviors.alt_media_widget = {
  attach: function(context) {
     
    $('.amw-field', context).each(function(e) {
      if($(this).hasClass("amw-processed")) {
      }
      else {
        $(this).addClass("amw-processed");

        // this action updates the fid field and then
        // triggers a ajax refresh of the the element
        $(this).bind("update", function(e, newid) {
          if (newid) {
            $(this).find('input.fid').val(newid);
          }
            $(this).find('input.fid').trigger("refresh");
        });
      }
    });
    $(".media-dialog-wrapper .media-dialog-inner").each(function() {
      if($(this).hasClass("amw-processed")) {
      }
      else {
        $(this).addClass("amw-processed");

        // this close the dialog and updates the related
        // element
        $(this).bind("update", function(e, newid) {
          $(this).parent().dialog('destroy');
          field_id = $(this).parent().attr("field");
          $("#" + field_id ).trigger("update", newid);
        });
        $(this).bind("open", function(e) {
          $(this).parent().dialog({
            title: 'Edit Meta Data',
          //  autoOpen: false,
          //  height: 400,
            hide: 'slide',
            show: 'slide',
            width: $('body').width() * .9,
            modal: true,
            dialogClass: 'media_dialog'
          });
        });
      }
    });
  }

};

})(jQuery);

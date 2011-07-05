(function($) {

Drupal.behaviors.media_views_widget = {
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
            // This should not be need as it should be close 
            // but the function that calls this one
            $('.media-dialog-wrapper').dialog('destroy');
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
          Drupal.attachBehaviors(this);
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
    // make views selectings
    $(".media-dialog-inner .views-row").each(function(e) {
      if($(this).hasClass("amw-processed")) {
      }
      else {
        $(this).addClass("amw-processed");
        $(this).click(function(e) {
          e.preventDefault();
          results = Drupal.settings.amw_results;
          //going to closure need to define the row
          row = this;
          $.each(results, function(i, value) {
            i ++;
            if($(row).hasClass("views-row-" + i)) {
              $(row).parents(".media-dialog-inner").find("[name='fid']").val(value.fid).trigger("update");
            }
          });
        });
      }
    });
  }

};

})(jQuery);

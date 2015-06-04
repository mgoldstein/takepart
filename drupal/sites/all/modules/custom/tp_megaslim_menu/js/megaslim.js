/**
 * @file
 * Scripts for the MegaSlim module.
 */
(function ($, Drupal, window, document, undefined) {

  $( document ).ready(function() {
    $('#megaslim > li > a').hover(function(){

      var $menu_link = $(this);
      /* if the li element does not have class 'processed', add the class and then make the ajax call */
      if(!$(this).parent().hasClass('processed')){
        $(this).parent().addClass('processed');
        var mlid = $(this).data('mlid');
        var url = window.location.protocol + '//' + window.location.hostname + '/ajax/megaslim/' + mlid;
        /* Make ajax call and append it */
        $.get(url, function(data) {
          /* Add MegaSlim menu item to the list element */
          data = jQuery.parseJSON(data);
          $menu_link.after(data);
        });
      }
    });
  });

})(jQuery, Drupal, this, this.document);
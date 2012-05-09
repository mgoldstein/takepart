(function ($) {
  Drupal.behaviors.ideasforgood = {
    attach: function (context, settings) {
      if ($('#ideasforgood-share-bar').length) {
        $('#ideasforgood-share-bar').once('ideasforgood', function() {
          window.addthis.toolbox('#ideasforgood-share-bar');
        });
      }
    }
  };

  $(document).ready(function() {
     $('.ideasforgood-finalist-item').click(function() {
       var item_dialog = '#' + $(this).attr('id') + '-dialog';
       var prompt = $(item_dialog).dialog({
         autoOpen: false,
         resizable: false,
         modal: true,
         title: "Testing",
         width: 400,
         height: 300
       });
       $('img.ideasforgood-cancel-button').click(function() {
         prompt.dialog('close');
       });
       prompt.dialog('open');
     });
     $('.ideasforgood-finalist-item').each(function() {
       var item_idea = '#' + $(this).attr('id') + '-idea';
       $(this).qtip({
         content: $(item_idea),
         position: {
           corner: {
             target: 'bottomLeft',
             tooltip: 'topLeft'
           }
         },
         hide: {
           fixed: true,
           delay: 200
         },
         style: {
           width: 480,
           padding: 10,
           background: '#ffffff',
           color: '#000000',
           textAlign: 'left',
           border: {
             width: 1,
             radius: 0,
             color: '#ff9900'
           },
           name: 'light'
         }
       });
     });
  });
})(jQuery);

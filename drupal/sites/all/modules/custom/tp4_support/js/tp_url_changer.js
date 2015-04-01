(function ($, Drupal, window, document, undefined) {
  //creates a drupal behavior
  Drupal.behaviors.tp_auto_changer = {
    attach: function(context, settings) {
      //binds to the scroll
      $(window).bind('scroll', function() {
        //default variables for this scope
        var url = window.location.pathname;
        var title = document.title;
        var win = $(window);
        var viewport = {
          top : win.scrollTop(),
          left : win.scrollLeft(),
        };
        
        //does for each data-tp-url
        $('[data-tp-url]').each(function(index, value) {
          var tp_url = $(this).data('tpUrl'); //maps to data-tp-url
          var tp_url_title = $(this).data('tpUrlTitle'); //maps to data-tp-url-title
          var offset = $(this).offset();
          
          //ensures that the tp url is set before changing
          if (typeof tp_url !== 'undefined') {
            //compares offset and viewport
            if (offset.top < viewport.top) {
              url = tp_url;
              
              //only change the title if it's not undefined
              if (typeof tp_url_title !== 'undefined') {
                title = tp_url_title;
              }
              
              return;
            }
          }
        });
        
        //only change the url if it's not the same
        if (url != window.location.pathname) {
          tp_url_changer(url, title);
        }
      });
    }
  }
  
  /**
   * @function:
   *  window function that is used to update the URL and is binded to the scroll.
   */
  window.tp_url_changer = function(url, title) {
    //change url if not empty
    if (url != '') {
      //change url with pushstate so that the page doesnt reload
      window.history.pushState({}, url, url);
      document.title = title;
    }
  }
})(jQuery, Drupal, this, this.document);


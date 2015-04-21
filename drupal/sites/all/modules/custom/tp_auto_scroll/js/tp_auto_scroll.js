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
  
  //creates a drupal behavior
  /**
   *
   *  @function:
   *    This drupal behavior is used to change the URL and Title on the page.
   *    Note that some specific browser does not respect title changes
   *
   *  @example:
   *    This can be implemented via adding the following to any html tag
   *      data-tp-url="/example"
   *      data-tp-url-title="Test" *Note that some browsers does not respect this
   *
   */
  Drupal.behaviors.tp_auto_changer = {
    attach: function(context, settings) {
      //variables
      window.lastScrollTop = 0;
      window.tp_url_orig = window.location.href;
      window.tp_url_title_orig = document.title;
      
      //binds to the scroll
      $(window).bind('scroll', function() {
        //default variables for this scope
        var url = window.location.pathname;
        var title = document.title;
        var win = $(window);
        var viewport = {
          top : win.scrollTop(),
          left : win.scrollLeft(),
          bottom : win.scrollTop() + win.height()
        };
        
        //creates offset based on device height
        var offset_pad = -1 * (win.height() / 2);
        
        //checks which direction the scroll is occurring on. note in use but built
        if (viewport.top < lastScrollTop) {
          direction = 'up';
        }
        else {
          direction = 'down';
        }
        
        //does for each data-tp-url
        $('[data-tp-url]').each(function(index, value) {
          var tp_url = $(this).data('tpUrl'); //maps to data-tp-url
          var tp_url_title = $(this).data('tpUrlTitle'); //maps to data-tp-url-title
          var offset = $(this).offset();
          offset.bottom = $(this).height() + offset.top;
          
          //ensures that if the height is bigger then the div then change it to whichever is smaller
          if (offset_pad < $(this).height() / 2) {
            offset_pad = -1 * $(this).height() / 2;
          }
          
          //ensures that the tp url is set before changing
          if (typeof tp_url !== 'undefined') {
            if (offset.top + offset_pad < viewport.top) {
              url = tp_url;
              
              //only change the title if it's not undefined
              if (typeof tp_url_title !== 'undefined') {
                title = tp_url_title;
              }
              
              return;
            }
          }
          
          //changes back to original page if needed
          if (index === 0) {
            //ensures that if user scrolls back to the top that we have the original
            if (offset.top + offset_pad > viewport.top) {
              url = tp_url_orig;
              title = tp_url_title_orig;
            }
          }
        });
        
        //updates the last scroll var
        lastScrollTop = viewport.top;
        
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
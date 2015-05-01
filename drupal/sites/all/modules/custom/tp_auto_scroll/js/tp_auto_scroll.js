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
          var window_bottom = $window.scrollTop() + $window.height();
          var last_article = $('.article-wrapper:last').height() / 2;

          /* when the page scrolls to within 480px of #next-article */
          if (window_bottom + last_article + $('#footer').height() > elTop && page < page_limit) {
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
          if (offset_pad > $(this).height() / 2) {
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
      
      update_tp_social_media(title, window.location.href);
      update_fb_comments();
    }
  }
  
  /**
   *  @function:
   *    window function that is used to update the social links
   */
  window.update_tp_social_media = function(title, url) {
    //changes to update the social links
    $("meta[property='og:title']").attr("content", title);
    $("meta[property='og:url']").attr("content", url);
    $("meta[name='twitter:title']").attr("content", title);
    $("meta[name='twitter:url']").attr("content", url);
    
    //updates the social config
    tp_social_config.services.mailto.title = title;
    tp_social_config.services.twitter.text = document.title;
    tp_social_config.services.twitter.url = url;
    tp_social_config.services.facebook.title = title;
    tp_social_config.services.facebook.url = url;
    tp_social_config.services.googleplus.title = title;
    tp_social_config.services.googleplus.url = url;
    
    //refires to update
    $('body').find('.tp-social:not(.tp-social-skip)').tpsocial(tp_social_config);
  }
  
	// You need to re-parse the FBXML that contains all FB metadata (e.g. comment count)
	// And then attach existing JS Drupal.behaviors to new elements
	// that didn't exist when the initial behaviors were attached at page load
	update_fb_comments = function () {
		FB.XFBML.parse();
		Drupal.attachBehaviors(".fb_comments");
  }

})(jQuery, Drupal, this, this.document);
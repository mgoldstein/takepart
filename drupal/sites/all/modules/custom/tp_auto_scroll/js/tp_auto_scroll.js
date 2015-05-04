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

        /* Make a copy of the page data in the DDL for use when the user scrolls to the top */
        digitalData.pageInititial = digitalData.page;

        $(window).scroll(function() {
          var $window = $(window),
            elTop = $('#next-article').offset().top;
          var window_bottom = $window.scrollTop() + $window.height();
          var last_article = $('.article-wrapper:last').height() / 2;

          /* when the page scrolls to within 480px of #next-article */
          if (window_bottom + last_article + $('#footer').height() > elTop && page < page_limit) {
            if (alreadyloading == false) {



              /* Add a pageload event with the the details within attributes */
              /* Add a DDL pageload-id (nid) as a data element to the article tag */
              /* In a different location, update update DDL page info with info from the page load event with the nid in the data attribute of the article tag */


              /* Set the URL */
              var url = settings.articles[page + 1];
              alreadyloading = true;
              $.post(url, function(data) {

                /* Not returning a json object (Drupal is slow at that) so let's convert it here */
                data = jQuery.parseJSON(data);

                /* Create a new event in the DDL to be used when the user scolls to the article */
                digitalData.event.push(data.ddl);

                /* Return Article */
                $('#next-article').before(data.output);
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

        
        //For each article
        $('article').each(function(index, value) {

          /** Update active Article **/
          var articleTop = $(this).offset().top;
          var articleBottom = articleTop + $(this).height();
          var offset = (viewport.bottom - viewport.top)/2;

          if((viewport.top <= articleBottom - offset) && (viewport.top >= articleTop - offset)){
            $(this).addClass('active');

            /** Update the URL **/
            /* if article is active and data-tp-url != url, update it */
            var tp_url = $(this).data('tpUrl');
            var tp_url_title = $(this).data('tp-url-title'); //maps to data-tp-url-title
            if(tp_url){
              //ensures that the tp url is set before changing
              if (typeof tp_url !== 'undefined') {
                url = tp_url;
                //only change the title if it's not undefined
                if (typeof tp_url_title !== 'undefined') {
                  title = tp_url_title;
                }
              }
              // Upate the URL, social links and DDL based on URL logic
              if (url != window.location.pathname && url != '') {
                /* Update the DDL */
                tp_url_changer(url, title);

                /** Update the sharing **/
                if(title){
                  update_tp_social_media(title, window.location.href);
                }

                /** Update the DDL **/
                var page_id = $(this).data('ddl-page-id');
                if(page_id){
                  update_tp_ddl(page_id);
                }

		            // Update the TAP widget
		            new TP.Bootstrapper().start();

              }
            }


          }else{
            $(this).removeClass('active');
          }

        });
        
        //updates the last scroll var
        lastScrollTop = viewport.top;
      });
    }
  }
  
  /**
   * @function:
   *  window function that is used to update the URL and is binded to the scroll.
   */
  window.tp_url_changer = function(url, title) {
    //change url with pushstate so that the page doesnt reload
    window.history.pushState({}, url, url);
    document.title = title;
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

  /**
   *  @function:
   *  Update PageInfo in DDL with the correct Page Load event data
   */
  window.update_tp_ddl = function(id) {
    /* get the event with the page id */
    for (var i=0; i < digitalData.event.length; i++) {
      if(typeof(digitalData.event[i].eventInstanceID) != 'undefined' && digitalData.event[i].eventInstanceID == id){
        digitalData.page = digitalData.event[i].eventInfo.page;
        _satellite.track('autoload');
        return;
      }
      digitalData.page = digitalData.pageInitial;
      _satellite.track('autoload');
    }
  }

})(jQuery, Drupal, this, this.document);




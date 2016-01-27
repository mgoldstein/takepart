/**
 * @file
 * A JavaScript file for autoscroll.
 *
 */

(function ($, Drupal, window, document, undefined) {

  $( document ).ready(function() {
    window.newTapWidgets = true;
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
        var last_article = $('article').last().parent().height() / 2;

        /* when the page scrolls to within 480px of #next-article */
        if (window_bottom + last_article + $('#footer').height() > elTop && page < page_limit) {

          if (alreadyloading == false) {
            alreadyloading = true;

            /* Set the URL */
            var url = settings.articles[page + 1];
            $.get(url, function(data) {

              /* Not returning a json object (Drupal is slow at that) so let's convert it here */
              data = jQuery.parseJSON(data);

              /* Append ajax settings */
              jQuery.extend(Drupal.settings, data.settings);

              /* Create a new event in the DDL to be used when the user scolls to the article */
              digitalData.event.push(data.ddl);

              /* Return Article */
              $('#next-article').before(data.output);

              /* Append Ajax behaviors */
              if('function' === typeof Drupal.behaviors.AJAX.attach) {
                Drupal.behaviors.AJAX.attach(document, Drupal.settings);
              }

              // init video players for auto-loaded content
              if ('function' === typeof Drupal.behaviors.tp_video_player.attach) {
                Drupal.behaviors.tp_video_player.attach();
              }

              // Load comments box on button click for mobile display
              $('a.comments-count').once('FBComments', function () {
                $('a.comments-count').on('click', function(e){
                  $(this).siblings('.fb-comments').attr('href', window.location.href).show();
                  $(this).hide();
                  e.preventDefault();
                  return false;
                });
              });

              /* There are new Tap Widgets available on the page.  Delay these calls until page is active */
              window.newTapWidgets = true;

              alreadyloading = false;
              page++;
            });
          }
        }
      });
    }
  });


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
      var timer;
      $(window).bind('scroll', function() {

        /* Only process the code below every 100ms on scroll */
        if(timer) {
          window.clearTimeout(timer);
        }
        timer = window.setTimeout(function() {
          //default variables for this scope
          var url = window.location.href;
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
              var tp_og_url = $(this).data('tp-og-url');
              var tp_og_title = $(this).data('tp-og-title');
              var tp_og_image = $(this).data('tp-og-image');
              var tp_og_description = $(this).data('tp-og-description');
              var current_path = location.protocol + '//' + location.host + location.pathname;
              // Upate the URL, social links and DDL based on URL logic
              if (typeof tp_og_url != 'undefined' && tp_og_url != current_path) {
                /** Update the URL **/
                tp_url_changer(tp_og_url, tp_og_title);

                /**
                 *  check to ensure that the reach.js is fully ready
                 */
                if (typeof Drupal.settings.tpAutoScroll[0].auto_updates[tp_og_url] !== 'undefined') {
                  var data = Drupal.settings.tpAutoScroll[0].auto_updates[tp_og_url].data;
                  tp_reach_call(data);
                }

                /** Update the sharing **/
                update_tp_social_media(tp_og_title, tp_og_url, tp_og_image, tp_og_description);

                /** Update the DDL **/
                var page_id = $(this).data('ddl-page-id');
                if(page_id){
                  update_tp_ddl(page_id);
                }

                /** Check for additional TAP widgets */
                // needs to happen after page info updates for DTM
                if ( window.newTapWidgets == true ) {
                  TP.scope = $(value).data('ddlPageId');
                  TP.Bootstrapper && new TP.Bootstrapper().start();
                  TAP.Widget      && TAP.Widget.addWidgets();
                  window.newTapWidgets = false;
                }

                //Check if Chartbeat is installed and run the auto update on it
                if(Drupal.settings.hasOwnProperty('chartbeat')) {
                  //Reusing sailthru tags and authors
                  _sf_async_config.sections=Drupal.settings.tpAutoScroll[0]['auto_updates'][tp_og_url].data.channels.join(",");;
                  _sf_async_config.authors=Drupal.settings.tpAutoScroll[0]['auto_updates'][tp_og_url].data.authors.join(",");;
                  pSUPERFLY.virtualPage(tp_og_url, tp_og_title);
                }

              }

            }else{
              $(this).removeClass('active');
            }
          });
          //updates the last scroll var
          lastScrollTop = viewport.top;

        }, 100);
      });
    }
  };

  /**
   * @function:
   *  window function that is used to update the URL and is binded to the scroll.
   */
  window.tp_url_changer = function(url, title) {
    //change url with pushstate so that the page doesnt reload
    if ( window.history.pushState )
      window.history.pushState({}, url, url);
    document.title = title;
  };

  /**
   *  @function:
   *    window function that is used to update the social links
   */
  window.update_tp_social_media = function(title, url, image, description) {
    //changes to update the social links
    if (typeof title !== 'undefined') {
      $("meta[property='og:title']").attr("content", title);
      $("meta[name='twitter:title']").attr("content", title);
    }
    if (typeof url !== 'undefined') {
      $("meta[property='og:url']").attr("content", url);
      $("meta[name='twitter:url']").attr("content", url);
	 $("link[rel='canonical']").attr("href", url);
    }
    if (typeof image !== 'undefined') {
      $("meta[property='og:image']").attr("content", image);
    }
    if (typeof description !== 'undefined') {
      $("meta[property='og:description']").attr("content", description);
    }

    //updates the social config
    tp_social_config.services.mailto.title = title;
    tp_social_config.services.twitter.text = document.title;
    tp_social_config.services.twitter.url = url;
    tp_social_config.services.facebook.title = title;
    tp_social_config.services.facebook.url = url;
    tp_social_config.services.googleplus.title = title;
    tp_social_config.services.googleplus.url = url;
    tp_social_config.services.tumblr.title = title;
    tp_social_config.services.tumblr.url = url;

    //only update the og metatag data if the url is set
    if (Drupal.settings.tpAutoScroll[0]['auto_updates'][url] != undefined) {
      var width = Drupal.settings.tpAutoScroll[0]['auto_updates'][url]['width'];
      var height = Drupal.settings.tpAutoScroll[0]['auto_updates'][url]['height'];
      var sttags = Drupal.settings.tpAutoScroll[0]['auto_updates'][url]['sailthru_tags'];
      var stauthors = Drupal.settings.tpAutoScroll[0]['auto_updates'][url]['sailthru_authors'];
      var stdate = Drupal.settings.tpAutoScroll[0]['auto_updates'][url]['sailthru_date'];

      //ensures we only update if if the metatag exists before
      if ($("meta[property='og:image:width']").length == 1) {
        $("meta[property='og:image:width']").attr("content", width);
      }

      //ensures we only update if if the metatag exists before
      if ($("meta[property='og:image:height']").length == 1) {
        $("meta[property='og:image:height']").attr("content", height);
      }

      if($("meta[name='sailthru.tags']").length == 1) {
        $("meta[name='sailthru.tags']").attr("content", sttags);
      }
      if($("meta[name='sailthru.author']").length == 1) {
        $("meta[name='sailthru.author']").attr("content", stauthors);
      }
      if($("meta[name='sailthru.date']").length == 1) {
        $("meta[name='sailthru.date']").attr("content", stdate);
      }
    }

    //refires to update
    $('body').find('.tp-social:not(.tp-social-skip)').tpsocial(tp_social_config);
  };

  /**
   *  @function:
   *  Update PageInfo in DDL with the correct Page Load event data
   */
  window.update_tp_ddl = function(id) {

    /* get the event with the page id */
    for (var i=0; i < digitalData.event.length; i++) {
      if(typeof(digitalData.event[i].eventInstanceID) != 'undefined' && digitalData.event[i].eventInstanceID == id){
        digitalData.page.pageInfo = digitalData.event[i].eventInfo.page.pageInfo;
        digitalData.page.pageNumber = digitalData.event[i].eventInfo.autoloadCount;
        digitalData.category = digitalData.event[i].eventInfo.category;
        _satellite.track('clear_vars');
	    setTimeout(function(){ _satellite.track('autoload'); }, 1000);
        return;
      }
    }

    /* If no event exists then it is the initial page load */
    if ( digitalData.pageInitial )
      digitalData.page.pageInfo = digitalData.pageInitial.pageInfo;
    digitalData.page.pageNumber = 1;
    _satellite.track('clear_vars');
   setTimeout(function(){ _satellite.track('autoload'); }, 1000);

  };

})(jQuery, Drupal, this, this.document);

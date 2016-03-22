//defines function
(function ($) {
  //does on document ready since variables from drupal setting not available til then
  $(document).ready(function() {
    window.tpScrollTop = 0;
    //on init
    init_tp_ads('down');
    window.tp_ad_debug_mode = $.getUrlParam('debug-mode');

    //attaches a handler to the scroll functionality
    $(window).bind('scroll', function(event) {
      //calls the init
      init_tp_ads();

      //does for each main wrapper
      $('.tp-main-ad-wrapper > div').each(function() {
        var id = this.id;

        //ensures we have an id to call the google tag display on
        if (id != '') {
          //ensures we only fire the display if its empty
          if ($('div', this).length == 0) {
            googletag.display(id);
          }
        }
      })
    });
  });

  /**
   *  @function:
   *    this function is called on the init and on scroll bind
   */
  window.init_tp_ads = function() {
    //variables
    window.mobile_ads = Drupal.settings.tp_ad_settings;
    window.mobile_leader_ads = Drupal.settings.tp_leader_ad_settings;

    //this is for the leaderboard insert.
    tp_add_article_ads(window.mobile_leader_ads, 300, 'article_leader_ads', 1);

    //this is for the mobile article insert. ad will come when within 300 px of the viewport
    tp_add_article_ads(window.mobile_ads, 300, 'article_ads', 1);

    //only fire code if setting exists
    if (typeof Drupal.settings.tp_ad_more_on_takepart != 'undefined') {
      window.more_on_takepart_ads = Drupal.settings.tp_ad_more_on_takepart;
      tp_add_article_ads(window.more_on_takepart_ads, 300, 'more_on_takepart', 1);
    }
  }

  /**
   *  @function:
   *    jquery function extend to have get url parem
   */
  $.getUrlParam = function(name) {
    var results = new RegExp('[\?&]' + name + '=([^&#]*)').exec(window.location.href);
    if (results == null) {
      return 0;
    }
    else {
      return results[1] || 0;
    }
  }

   /**
   *  @function:
   *    Escape all quotes in a string (for PageTitle)
   */
    window.addslashes = function(str) {
    return (str + '').replace(/[\\"']/g, '\\$&').replace(/\u0000/g, '\\0');
}

  /**
   *  @function:
   *    function is used to add the ads when in viewport
   *
   *  @param:
   *    ads_object - object containing the ads
   *         ads_object[{Content Number}]['selector] = jquery selector
   *         ads_object.ads[{Content Number}][0]['javascript'] = markup
   *    viewport_offset - the viewport offset to fire
   *    id - used to differiated the selectors
   *    show_ads - shows the ads starting from
   */
  window.tp_add_article_ads = function(ads_object, viewport_offset, id, show_ads) {
    //variable
    var view_offset = viewport_offset;

    //conditional checks to ensure that
    var auto_scroll_status = !(Drupal.settings.tpAutoScroll == undefined);

    //does for each article thats on the page
    $('article').each(function(k, value) {

      //variable
      var win = $(window);
      var viewport = {
        top : win.scrollTop(),
        left : win.scrollLeft(),
      };
      viewport.bottom = viewport.top + win.height();
      var article_offset = $(this).offset();
      article_offset.bottom = article_offset.top + $(this).height();
      var article_wrapper = $(this).parent();
      //adds class based if article is active in view
      if (article_offset.top < viewport.bottom && article_offset.bottom > viewport.bottom) {
        //add the class if it's not there
        if (!$(article_wrapper).hasClass('ad-active')) {
          //adds correct classes
          //Only 1 Ad Active at a time
          $('.ad-active').each(function(){
            $(this).removeClass('ad-active').addClass('not-ad-active');
          });
          //This will make sure ours keep the ad active class
          $(article_wrapper).removeClass('not-ad-active').addClass('ad-active');
        }
      }
      //removes the class if the article is not active within the viewport
      else {
        //marks this article as not active and remove ads to reuse
        $(article_wrapper).removeClass('ad-active').addClass('not-ad-active');
      }

      //area for updating
      if (article_offset.bottom > viewport.bottom) {
        $(this).once('tp_ad_targetting', function() {
          var page_url = $(this).data('tpOgUrl');
          targets = '';

          //break if the page url doesnt exist
          if (typeof Drupal.settings.tpAutoScroll[0]['auto_updates'][page_url] == 'undefined') {
            return;
          }

          //does for each target set from the backend
          $.each(Drupal.settings.tpAutoScroll[0]['auto_updates'][page_url]['targets'], function(i, v) {
            targets += ' googletag.pubads().clearTargeting(\'' + i + '\');';
            if (v !== '""') {
      		    if (i === 'PageTitle') {
      			    targets += 'googletag.pubads().setTargeting(\'' + i + '\', "'+ addslashes(v) + '");';
      		    }
              else if (v.indexOf('[') >= 0) {
                targets += 'googletag.pubads().setTargeting(\'' + i + '\', '+ v + ');';
              }
              else {
                targets += 'googletag.pubads().setTargeting(\'' + i + '\', \'' + addslashes(v) + '\');';
              }
            }
          });

          //if article is first then set target to true otherwise false
          var top_article = Drupal.settings.tpAutoScroll[0]['auto_updates'][page_url]['TopArticle'];
          targets += 'googletag.pubads().setTargeting(\'TopArticle\', \'' + top_article + '\');';

          //adding a article position targetting even if its not being used now its built
          targets += 'googletag.pubads().setTargeting(\'articlePosition\', \'' + (k + 1) + '\');';

          //append script into cmd stack to be called.
          $('<script>googletag.cmd.push(function() {' + targets + '});</' + 'script>').appendTo(document.body);
        });
      }

      $(article_wrapper).each(function(){
        if($(this).hasClass('ad-active')
          && (!$(this).hasClass('feature_article-wrapper')
            || id == 'more_on_takepart')) {
          window.tp_insert_ads(this, ads_object[k]['selector'], ads_object[k], id, show_ads);
        }
      });
    });

  }

  /**
   *  @function:
   *    Global function for inserting ads
   */
  window.tp_insert_ads = function(article, selector, ads_object, id, show_ads) {
    //does for each ad within the object
    $(ads_object.ads).each(function(ad_key, ad_value) {
      //default variables
      var ad_placement = this.placement;
      var javascript = this.javascript;
      var current_ad = this;
      view_offset = 500;
      ad_class = '';

      var win = $(window);
      var viewport = {
        top : win.scrollTop(),
        left : win.scrollLeft(),
      };
      viewport.bottom = viewport.top + win.height();

      var selector_item = $(article).find(selector).eq(parseInt(ad_placement) - 1);
      //conditional check to ensure that the there are 2 more selectors after the placement
      var conditional_check = $(article).find(selector).eq(parseInt(ad_placement) + 1);

      //ensures that we have an item that is defined
      if (selector_item.length) {
        var selector_item_offset = $(selector_item).offset();

        //first condition allows a specific number ads to be shown.
        //second condition ensure that the ad is within the the viewport and offset by 500 px so that the ad is in place before its in view.
        //OVERRIDE Made more on takepart ads load early to ensure loaded before some gets there
        if ((show_ads < ad_key
          || selector_item_offset.top > viewport.top
          && selector_item_offset.top < viewport.bottom + view_offset)
          || id == 'more_on_takepart') {

          var adSlot = current_ad.ad_slot;

          //overrides for desktop
          if (window.innerWidth > 480) {
            //break this if conditional if the conditional check comes back as 0
            if (id != 'article_leader_ads' && id != 'more_on_takepart' && !conditional_check.length) {
              return;
            }

            //override for non-leaderboard
            if (id != 'article_leader_ads') {
              ad_class = ' ad-right';
            }
            //override for leaderboard
            else {
              //only override the first of it's type so that we can update it's selector
              if ($(article).is(':first-of-type')) {
                selector_item = '.fresh-first-ad';
              }
            }
          }

          //only replace call with refresh
          var page_url = $('.ad-active article').data('tpOgUrl');
          var targets = '';

          //break if the page url doesnt exist
          if (typeof Drupal.settings.tpAutoScroll[0]['auto_updates'][page_url] == 'undefined') {
            return;
          }

          //does for each target set from the backend
          $.each(Drupal.settings.tpAutoScroll[0]['auto_updates'][page_url]['targets'], function(i, v) {
            targets += ' googletag.pubads().clearTargeting(\'' + i + '\');';
            if (v !== '""') {
      		    if (i === 'PageTitle') {
      			    targets += 'googletag.pubads().setTargeting(\'' + i + '\', "'+ addslashes(v) + '");';
      		    }
              else if (v.indexOf('[') >= 0) {
                targets += 'googletag.pubads().setTargeting(\'' + i + '\', '+ v + ');';
              }
              else {
                targets += 'googletag.pubads().setTargeting(\'' + i + '\', \'' + addslashes(v) + '\');';
              }
            }
          });

          //if article is first then set target to true otherwise false
          var top_article = Drupal.settings.tpAutoScroll[0]['auto_updates'][page_url]['TopArticle'];
          targets += 'googletag.pubads().setTargeting(\'TopArticle\', \'' + top_article + '\');';

          targets += 'googletag.pubads().refresh([' +  adSlot.replace('-', '-') + ']);'
          javascript = javascript.replace('[targets]', targets);

          //ensures we only process the selector once
          $(selector_item).once('tp-ad', function() {
            var $this = this;

            //allows debug mode
            if (window.tp_ad_debug_mode == "true") {
              javascript = '<h5 class="ad-label text-center">Advertisement - ' + current_ad.ad_slot + '</h5>' + javascript;
            }

            //creates the wrapper and append. wrapper is used later for removal so that there's no jump on the screen.
            if ($('.tp-ad-wrapper', this).length == 0) {
              javascript = '<div id="' + adSlot.replace('-', '-') + '" class="tp-ad-wrapper row' + ad_class + '">' + javascript + '</div>';
              $($this).append(javascript);
            }
            //otherwise append back to the same wrapper
            else {
              $('.tp-ad-wrapper', this).append(javascript);
            }
          });
        }
      }
    });
  }

}(jQuery));

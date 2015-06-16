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
   *    function is used to add the ads when in viewport
   *
   *  @param:
   *    ads_object - object containing the ads
   *         ads_object['selector] = jquery selector
   *         ads_object.ads[0]['javascript'] = markup
   *    viewport_offset - the viewport offset to fire
   *    id - used to differiated the selectors
   *    show_ads - shows the ads starting from
   */
  window.tp_add_article_ads = function(ads_object, viewport_offset, id, show_ads) {
    //variable
    var view_offset = viewport_offset;
    var selector = ads_object['selector'];
    var tp_count = 'tp_ad_' + id;
    var tp_count_insert = tp_count + '_insert';
    
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
      if ((article_offset.top < viewport.bottom + viewport_offset && article_offset.bottom > viewport.bottom)) {
        //add the class if it's not there
        if (!$(article_wrapper).hasClass('ad-active')) {
          //adds correct classes
          $(article_wrapper).removeClass('not-ad-active').addClass('ad-active');
        }
      }
      //removes the class if the article is not active within the viewport
      else {
        //marks this article as not active and remove ads to reuse
        $(article_wrapper).removeClass('ad-active').addClass('not-ad-active').each(function() {});
      }
    });
    
    //removes the old ads from not active articles first so that we can reuse them
    $('.article-wrapper.not-ad-active').each(function() {
      window.tp_remove_ads(this);
    });
    
    //now process and add the ads back into the active article
    $('.article-wrapper.ad-active').each(function() {
      window.tp_insert_ads(this, selector, ads_object, id, show_ads);
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
      
      var selector_item = $(article).find(selector).eq(ad_placement - 1);
      
      //ensures that we have an item that is defined
      if (selector_item.length) {
        var selector_item_offset = $(selector_item).offset();
        
        //first condition allows a specific number ads to be shown.
        //second condition ensure that the ad is within the the viewport and offset by 500 px so that the ad is in place before its in view.
        if (show_ads < ad_key || selector_item_offset.top > viewport.top && selector_item_offset.top < viewport.bottom + view_offset) {
            
          //overrides for desktop
          if ($(window).width() > 480) {
            javascript = current_ad.javascript_desktop;
            
            //override for non-leaderboard
            if (id != 'article_leader_ads') {
              ad_class = ' ad-right';
            }
            //override for leaderboard
            else {
              //only override the first of it's type so that we can update it's selector
              if ($(article).is(':first-of-type')) {
                selector_item = $(current_ad.desktop.selector);
              }
              //otherwise we remove the old one to reuse
              else {
                $('.tp-ad', current_ad.desktop.selector).remove();
                $(current_ad.desktop.selector).removeClass('tp-ad-processed');
              }
            }
          }          
          
          //ensures we only process the selector once
          $(selector_item).once('tp-ad', function() {
            var $this = this;
            
            //allows debug mode
            if (window.tp_ad_debug_mode == "true") {
              javascript = '<h5 class="ad-label text-center">Advertisement - ' + ad_slot + '</h5>' + javascript;
            }
            
            //creates the wrapper and append. wrapper is used later for removal so that there's no jump on the screen.
            if ($('.tp-ad-wrapper', this).length == 0) {
              javascript = '<div class="tp-ad-wrapper row' + ad_class + '">' + javascript + '</div>';
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
  
  /**
   *  @function:
   *    Global function that removes ads based on selector passed
   *    Additional logic to keep height and width based on what comes in so that it doesnt jump
   */
  window.tp_remove_ads = function(parent_selector) {
    //does for each tp-ad-processed in the selector
    $('.tp-ad-processed', parent_selector).each(function() {
      //defines variable to set width and height
      var height = $('.tp-ad', this).height();
      var width = $('.tp-ad', this).width();
      
      //removes the ad
      $('.tp-ad', this).remove();
      
      //removes the processed so that it can refire on scrolling
      $(this).removeClass('tp-ad-processed');
      
      //appends height and width
      $('.tp-ad-wrapper', this).css('height', height).css('width', width);
    });
  }
  
}(jQuery));
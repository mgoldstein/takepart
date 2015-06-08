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
      var viewport_top = $(window).scrollTop();
      
      //sets which direction user is scrolling
      if (viewport_top < tpScrollTop) {
        direction = 'up';
      }
      else {
        direction = 'down';
      }
      
      //updates the viewport_top for calculation for which direction the scroll is occurring on.
      window.tpScrollTop = viewport_top;
      
      //calls the init based on direction so that we dont have a double call
      init_tp_ads(direction);
    });
    
    //based on window size remove the desktop leaderboard
    $(window).smartresize(function() {
      var window_width = $(window).width();
    });
  });
  
  /**
   *  @function:
   *    this function is called on the init and on scroll bind
   */
  window.init_tp_ads = function(direction) {
    //variables
    window.mobile_ads = Drupal.settings.tp_ad_settings;
    window.mobile_leader_ads = Drupal.settings.tp_leader_ad_settings;
  
    //this is for the leaderboard insert.
    tp_add_article_ads(window.mobile_leader_ads, 300, 'article_leader_ads', 1, direction);
  
    //this is for the mobile article insert. ad will come when within 300 px of the viewport
    tp_add_article_ads(window.mobile_ads, 300, 'article_ads', 5, direction);
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
  window.tp_add_article_ads = function(ads_object, viewport_offset, id, show_ads, direction) {
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
      var article_footer = $('footer', this).offset();
      var article_wrapper = $(this).parent();
      tp_count = tp_count + '_' + k;
      tp_count = tp_count_insert + '_' + k;
      
      //adds class based if article is active in view
      if ((article_offset.top < viewport.bottom + viewport_offset && article_offset.bottom > viewport.bottom)) {
        //add the class if it's not there
        if (!$(this).parent().hasClass('ad-active')) {
          //adds correct classes
          $(article_wrapper).addClass('ad-active');
          $(article_wrapper).removeClass('not-ad-active');
        }
      }
      //removes the class if the article is not active within the viewport
      else {
        //checks to see if auto scroll is enabled
        if (auto_scroll_status) {
          //adds a extra class so that we know it has already been processed
          if ($(article_wrapper).hasClass('ad-active')) {
            $(article_wrapper).addClass('ad-processed');
          }
          
          $(article_wrapper).removeClass('ad-active');
          $(article_wrapper).addClass('not-ad-active');
        }
        
        //ensures that we remove the old ad so that we can reuse it
        $('.not-ad-active .mobile-ad-processed .tp-ad').each(function() {
          //calculate the height of each tp-ad to add to parent wrapper
          var ad_height = $(this).height();
          var item_offset = $(this).offset();
          
          //ensures that we dont add the height if it's less then 50 in order to address issue with empty divs
          if (ad_height > 50) {
            $(this).parent().height(ad_height);
          }
          
          //removes the tp-ad from all other articles so that the code can be reused
          if (item_offset.top > viewport.bottom + viewport_offset || item_offset.top < viewport.top - viewport_offset) {
            $(this).remove();
          }
        });
      }
      
      //checks to see if there is already an ad present. if so do not add another one back in.
      if ($('.ad-active .mobile-article-ad .tp-ad').length < 1) {
        $('.ad-active .mobile-ad-processed').removeClass('mobile-ad-processed');
      }
      
      //reset the counter for non ad active articles
      if (!$(this).hasClass('ad-active')) {
        window[tp_count] = 0;
        window[tp_count_insert] = 0;
      }
      
      //does for each of the selector item
      $(selector).each(function(i, v) {
        //ensures that the article count is set to 0 and no more then the length of the array
        if (typeof window[tp_count] === 'undefined') {
          window[tp_count] = 0;
          window[tp_count_insert] = 0;
          var end = false;
        }
        //ensures that if the length is larger then the amt to reset it back to zero before continuing
        else if (window[tp_count] + 1 > Object.keys(ads_object.ads).length) {
          var end = true;
          window[tp_count] = 0;
        }
        
        //grabs the item
        var item = $(selector + ":nth-of-type(" + (i + 1) + ")")
        var offset = item.offset();
        
        //ensures that the offset is defined
        if (offset != null) {
          //only when in viewport
          if (window[tp_count] < show_ads || (offset.top > viewport.bottom + view_offset || offset.bottom < viewport.top - viewport_offset) || direction == 'up') {
            //process item once
            $(item).once('mobile-ad', function() {
              if (!end) {
                //ensures that the placement is defined before we continue
                if (typeof ads_object.ads[window[tp_count]]['placement'] !== undefined) {
                  var insert_key = (window[tp_count_insert] + parseInt(ads_object.ads[window[tp_count]]['placement']));
                  
                  //only add after the the correct key            
                  if ((insert_key - 1) == i) {
                    //switch javascript based on window size on init
                    if ($(window).width() > 480) {
                      var ad_class = '';
                      var js_markup = ads_object.ads[window[tp_count]]['javascript_desktop'];
                      if (id != 'article_leader_ads') {
                        ad_class = 'ad-right';
                      }
                    }
                    else {
                      var js_markup = ads_object.ads[window[tp_count]]['javascript'];
                      if (id != 'article_leader_ads') {
                        ad_class = 'ad-right';
                      }
                    }
                    
                    var ad_gpd_id = ads_object.ads[window[tp_count]]['ad_gpd_id'];
                    var ad_slot = ads_object.ads[window[tp_count]]['ad_slot'];
                    var dynamic_js_markup = '';

                    //checks to see if the wrapper is in place before appending
                    if ($('.tp-ad-wrapper', this).length == 0) {
                      if (window.tp_ad_debug_mode == "true") {
                        js_markup = '<h5 class="ad-label text-center">Advertisement - ' + ad_slot + '</h5>' + js_markup;
                      }
                      dynamic_js_markup = '<div class="tp-ad-wrapper row' + ad_class + '">' + js_markup + '</div>';
                      $(this).append(dynamic_js_markup);
                    }
                    else {
                      dynamic_js_markup = js_markup;
                      $('.tp-ad-wrapper', this).append(dynamic_js_markup);
                    }
                    //appends the markup after the selector
                    $(item).addClass('ad-inserted-append');
                    
                    //increment counts
                    window[tp_count]++; //increment the ads for rotation
                    window[tp_count_insert] = insert_key; //update key once its been added
                  }
                }
              }
            });
          }
        }
      });
    });
  }
}(jQuery));
//defines function
(function ($) {
  //does on document ready since variables from drupal setting not available til then
  $(document).ready(function() {
    window.tpScrollTop = 0;
    //on init
    init_tp_ads('down');
    
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
  });
  
  /**
   *  @function:
   *    this function is called on the init and on scroll bind
   */
  window.init_tp_ads = function(direction) {
    //variables
    window.mobile_ads = Drupal.settings.tp_ad_settings;
    window.mobile_leader_ads = Drupal.settings.tp_leader_ad_settings;
  
    tp_add_article_ads(window.mobile_leader_ads, 500, 'article_leader_ads', 'default', 1, direction);
  
    //this is for the mobile article insert. ad will come when within 300 px of the viewport
    tp_add_article_ads(window.mobile_ads, 500, 'article_ads', 'default', 1, direction);
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
  window.tp_add_article_ads = function(ads_object, viewport_offset, id, insert_pos, show_ads, direction) {
    //variable
    var view_offset = viewport_offset;
    var selector = ads_object['selector'];
    
    var tp_count = 'tp_ad_' + id;
    var tp_count_insert = tp_count + '_insert';
    
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
      tp_count = tp_count + '_' + k;
      tp_count = tp_count_insert + '_' + k;
      
      //adds class based if article is active in view
      if ((article_offset.top < viewport.bottom + viewport_offset && article_offset.bottom > viewport.bottom + viewport_offset)) {
        //add the class if it's not there
        if (!$(this).parent().hasClass('ad-active')) {
          
          //adds correct classes
          $(this).parent().addClass('ad-active');
          $(this).parent().removeClass('not-ad-active');
        }
      }
      //removes the class if the article is not active within the viewport
      else {
        $(this).parent().removeClass('ad-active');
        $(this).parent().addClass('not-ad-active');
        //ensures that we remove the old ad so that we can reuse it
        //$('.not-ad-active .mobile-ad-processed .tp-ad').remove(); //@dev: disabled for now for single articles
      }
      
      //if the direction is going back up this will remove the process class so that the js can add the ads back in
      if (direction == 'up') {
        //checks to see if there is already an ad present. if so do not add another one back in.
        if ($('.ad-active .mobile-article-ad .tp-ad').length < 1) {
          $('.ad-active .mobile-ad-processed').removeClass('mobile-ad-processed');
        }
        
        if (!$(this).hasClass('ad-active')) {
          window[tp_count] = 0;
          window[tp_count_insert] = 0;
        }
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
          //var end = true;
          window[tp_count] = 0;
          window.article_ad = 0; //this is disabled as ads do not rotate back to the top of the stack
        }
        
        //grabs the item
        var item = $(selector + ":nth-of-type(" + (i + 1) + ")")
        var offset = item.offset();
        
        //ensures that the offset is defined
        if (offset != null) {
          //only when in viewport
          if (window[tp_count] < show_ads || (viewport.top < offset.top + view_offset && offset.top < viewport.bottom + view_offset) || direction == 'up') {
            //ensures to only add the ad once to address issue with scrolling backwards
            $(item).once('mobile-ad', function() {
              if (!end) {
                var insert_key = (window[tp_count_insert] + parseInt(ads_object.ads[window[tp_count]]['placement']));
                
                //only add after the the correct key            
                if ((insert_key - 1) == i) {
                  var js_markup = ads_object.ads[window[tp_count]]['javascript'];
                  var ad_gpd_id = ads_object.ads[window[tp_count]]['ad_gpd_id'];
                  var ad_slot = ads_object.ads[window[tp_count]]['ad_slot'];
                  var dynamic_js_markup = js_markup;
                  //var dynamic_js_markup = js_markup.replace(ad_gpd_id, ad_gpd_id + '_' + k);
                  //dynamic_js_markup = dynamic_js_markup.replace(ad_slot, ad_slot + '_' + k);
                  
                  if (insert_pos == 'after') {
                    //appends the markup after the selector
                    $(this).after(dynamic_js_markup);
                    $(item).addClass('ad-inserted-after');
                  }
                  else {
                    //appends the markup after the selector
                    $(this).append(dynamic_js_markup);
                    $(item).addClass('ad-inserted-append');
                  }
    
                  
                  //increment counts
                  window[tp_count]++; //increment the ads for rotation
                  window[tp_count_insert] = insert_key; //update key once its been added
                }
              }
            });
          }
        }
      });
    });
  }
}(jQuery));
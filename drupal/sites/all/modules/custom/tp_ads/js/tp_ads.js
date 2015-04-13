//defines function
(function ($) {
  //does on document ready since variables from drupal setting not available til then
  $(document).ready(function() {    
    //on init
    init_tp_ads();
    
    //attaches a handler to the scroll functionality
    $(window).bind('scroll', function(event) {
      init_tp_ads();
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
  
    tp_add_article_ads(window.mobile_leader_ads, 300, 'article_leader_ads', 'default', 1);
  
    //this is for the mobile article insert. ad will come when within 300 px of the viewport
    tp_add_article_ads(window.mobile_ads, 300, 'article_ads', 'after', 1);
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
  window.tp_add_article_ads = function(ads_object, viewport_offset, id, insert_pos, show_ads) {
    //variable
    var view_offset = viewport_offset;
    var selector = ads_object['selector'];
    
    var tp_count = 'tp_ad_' + id;
    var tp_count_insert = tp_count + '_insert';
    
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
        //window.article_ad = 0; //this is disabled as ads do not rotate back to the top of the stack
      }
      
      //variable
      var win = $(window);
      var viewport = {
        top : win.scrollTop(),
        left : win.scrollLeft(),
      };
      viewport.bottom = viewport.top + win.height();
      
      //grabs the item
      var item = $(selector + ":nth-of-type(" + (i + 1) + ")")
      var offset = item.offset();
      
      //ensures that the offset is defined
      if (typeof offset.top !== 'undefined') {
        //only when in viewport
        if (window[tp_count] < show_ads || (viewport.top < offset.top + view_offset && offset.top < viewport.bottom + view_offset)) {
          //ensures to only add the ad once to address issue with scrolling backwards
          $(item).once('mobile-ad', function() {
            if (!end) {
              var insert_key = (window[tp_count_insert] + parseInt(ads_object.ads[window[tp_count]]['placement']));
              
              //only add after the the correct key            
              if ((insert_key - 1) == i) {
                if (insert_pos == 'after') {
                  //appends the markup after the selector
                  $(this).after(ads_object.ads[window[tp_count]]['javascript']);
                  $(item).addClass('ad-inserted-after');
                }
                else {
                  //appends the markup after the selector
                  $(this).append(ads_object.ads[window[tp_count]]['javascript']);
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
  }
}(jQuery));
//defines function
(function ($) {
  //does on document ready since variables from drupal setting not available til then
  $(document).ready(function() {
    //variables
    window.mobile_ads = Drupal.settings.tp_ad_settings;
    var selector = mobile_ads['selector']; //formula to add
    
    //on init
    tp_add_article_ads(selector);
    
    //attaches a handler to the scroll functionality
    $(window).bind('scroll', function(event) {
      tp_add_article_ads(selector);
    });
  });
  
  /**
   *  @function:
   *    function is used to add the ads when in viewport
   */
  window.tp_add_article_ads = function(selector) {
    //variable
    var view_offset = 300;
    
    //does for each of the selector item
    $(selector).each(function(i, v) {
      //ensures that the article count is set to 0 and no more then the length of the array
      if (typeof article_ad === 'undefined') {
        window.article_ad = 0;
        window.article_ad_insert = 0;
      }
      //ensures that if the length is larger then the amt to reset it back to zero before continuing
      else if (article_ad + 1 > Object.keys(mobile_ads.ads).length) {
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
      
      //only when in viewport
      if (viewport.top < offset.top + view_offset && offset.top < viewport.bottom + view_offset) {
        //ensures to only add the ad once to address issue with scrolling backwards
        $(item).once('mobile-ad', function() {
          var insert_key = (article_ad_insert + parseInt(mobile_ads.ads[article_ad]['placement']));

          //only add after the the correct key
          if (insert_key == i) {
            //appends the markup after the selector
            $(this).after(mobile_ads.ads[article_ad]['mobile_javascript']);
            article_ad++; //increment the ads for rotation
            article_ad_insert = insert_key; //update key once its been added
          }
        });
      }
    });
  }
}(jQuery));
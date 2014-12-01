(function ($, Drupal, window, document, undefined) {

  Drupal.behaviors.tp_custom_collab = {
    attach: function (context, settings) {
      $(document).ready(function() {
        window.init_custom_collab_block();
        
        $(window).smartresize(function() {
          window.init_custom_collab_block();
        });
      });
      
      $('.tp-slim-nav-wrapper #megamenu li').hover(
        function(){
          $(this).addClass('tp-hover');
        },
        function(){
          $(this).removeClass('tp-hover');
        }
      );
    }
  };
  
  /**
   *  @function:
   *    This is a window function to init the custom block
   */
  window.init_custom_collab_block = function() {
    var small = 401;
    var large = 701;
    
    //does for each collab block
    $('.tp-custom-collab-block').each(function(i, v) {
      $(this).unbind('mouseenter mouseleave');
      
      //anything smaller than desktop
      if ($(window).width() < large) {
        //binds click to the div
        $(this).bind('click', function() {
          $('.normal-state', this).hide();
          $('.focus-state', this).show();
        });
        
        //additional code to handle the mousedown and touch for mobile
        $("body").bind('touchstart mousedown', function(event) {
          if (!$(event.target).hasClass('focus-state-link')) {
            $('.normal-state', this).show();
            $('.focus-state', this).hide();
          }
        });
      }
      else {
        //desktop
        $(this).hover(function() {
          $('.normal-state', this).hide();
          $('.focus-state', this).show();
        }, function() {
          $('.normal-state', this).show();
          $('.focus-state', this).hide();
        });
      }
    });
  }

})(jQuery, Drupal, this, this.document);
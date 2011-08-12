
(function ($) {
  Drupal.behaviors.ss_controls = { 
    attach : function(context) {
    $(".views-slideshow-controls-top").appendTo($("#ss_controls"));
    $(".views-slideshow-controls-bottom").appendTo($("#ss_controls"));
    }
  };
})(jQuery);


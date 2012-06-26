// file: javascript support for takepart_vidpop


(function ($) {
  Drupal.behaviors.takepart_vidpop = {
    attach: function (context, settings) {
      $(".vidpop-trigger").click(function(){
        alert(2);
      });
    }
  };
})(jQuery);

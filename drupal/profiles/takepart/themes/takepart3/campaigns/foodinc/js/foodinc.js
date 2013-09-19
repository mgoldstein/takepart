(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.expandJudges = {
    attach: function (context) {
      $(".show-more").click(function () {
          if($(this).prev().hasClass("show-more-height")) {
              $(this).text("See Less");
          } else {
              $(this).text("See More");
          }

          $(this).prev().toggleClass("show-more-height");
      });
    }
  }
  Drupal.behaviors.tpSocial={
    attach: function(context) {
      var tp_social_config = {
        url_append: '?cmpid=organic-share-{{name}}',
        services: [
          {name: 'facebook'},
          {
            name: 'twitter',
            text: '{{title}}',
            via: 'TakePart'
          },
          {name: 'googleplus'},
          {name: 'email'}
        ]
      };
      $('.tp-social:not(.tp-social-skip)').tpsocial(tp_social_config);
    }
  }
  Drupal.behaviors.FBook={
    attach: function(context) {
      FB.Canvas.setSize({ width: 640, height: 1000 });
    }
  }
  }

})(jQuery, Drupal, this, this.document);





















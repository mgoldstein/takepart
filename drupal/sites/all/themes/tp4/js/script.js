/**
 * @file
 * Scripts for thetheme.
 */

(function ($, Drupal, window, document, undefined) {

/**
 * Megamenu Behaviors
 */
Drupal.behaviors.megaMenuBehaviors = {
  attach: function(context, settings) {
    //prevent parent links on megamenu from linking on touch (link on double touch)
    $('#megamenu li.mega-item:has(.mega-content)').doubleTapToGo();

    //Toggle search on mobile
    $('html').click(function() {
      $('.search-toggle').parent().removeClass('active');
    });

    $('.search-toggle').parent().click(function(event){
        event.stopPropagation();
        $(this).addClass('active');
    });
  }
};

/**
 * Settings for the snap.js library
 */
Drupal.behaviors.snapperSettings = {
  attach: function(context, settings) {
    var snapper = new Snap({
      element: document.getElementById('page-wrap')
    });

    snapper.settings({
      dragger: null,
      disable: 'none',
      addBodyClasses: true,
      hyperextensible: true,
      resistance: 0.5,
      flickThreshold: 50,
      transitionSpeed: 0.3,
      easing: 'ease',
      maxPosition: 280,
      minPosition: 0,
      tapToClose: true,
      touchToDrag: true,
      clickToDrag: false,
      slideIntent: 40,
      minDragDistance: 5
    });

    $('.menu-toggle').on('click', function(){
        if( snapper.state().state=="left" ){
            snapper.close();
        } else {
            snapper.open('left');
        }
    });
  }
};

Drupal.behaviors.articleBehaviors = {
  attach: function() {
    var $body = $('body');

    if ($body.is('.page-node.node-type-openpublish-article')) {
      $('#article-social').tpsticky({offsetNode: '#article-content'});        

      // Social share buttons
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
          {name: 'reddit'},
          {name: 'email'}
        ]
      };

      $('.tp-social:not(.tp-social-skip)').tpsocial(tp_social_config);

      var main_image = $('#article-image img').attr('src');
      var more_services = {
        pinterest: {
          name: 'pinterest',
          media: main_image
        },
        tumblr_link: {name: 'tumblr_link'},
        gmail: {name: 'gmail'},
        hotmail: {name: 'hotmail'},
        yahoomail: {name: 'yahoomail'},
        aolmail: {name: 'aolmail'},

        //{name: 'myspace'},
        //{name: 'delicious'},
        linkedin: {name: 'linkedin'},
        //{name: 'myaol'},
        //{name: 'live'},
        digg: {name: 'digg'},
        stumbleupon: {name: 'stumbleupon'},
        //{name: 'hyves'}
      };

      if ( !main_image ) delete more_services.pinterest;

      $('#article-more-shares p').tpsocial({
        services: more_services
      });
    }
  }
};

})(jQuery, Drupal, this, this.document);

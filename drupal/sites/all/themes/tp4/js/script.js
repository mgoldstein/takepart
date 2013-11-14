/**
 * @file
 * Scripts for the theme.
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

/**
 * Behaviors for Article Nodes
 */
Drupal.behaviors.articleBehaviors = {
  attach: function() {
    var $body = $('body');

    if ($body.is('.page-node.node-type-openpublish-article')) {
      // sticky elements
      $('#article-social').tpsticky({ offsetNode: '#article-content' });

      var $stickyAd = $('.block-boxes-ga_ad-bottom'),
          stickyAdOffset = $stickyAd.offset().top,
          stickyAdHeight = $stickyAd.height(),
          $footer = $('.footer-wrapper'),
          $doc = $(document);

      $(window).on('scroll', function(e) {
        var isSticky = $stickyAd.hasClass('sticky'),
            documentHeight = $doc.height(),
            stickyAdLowestPoint = documentHeight - stickyAdHeight - $footer.outerHeight();

        // add/remove the sticky class
        if (window.scrollY > stickyAdOffset) {
          isSticky || $stickyAd.addClass('sticky');
        } else {
          !isSticky || $stickyAd.removeClass('sticky');
        }

        if (isSticky && window.scrollY > stickyAdLowestPoint) {
          $stickyAd.css('top', stickyAdLowestPoint - window.scrollY);
        } else {
          $stickyAd.css('top', '');
        }

      });
      

      // Setup Social Share Buttons
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

      // Set up secondary social share buttons
      var main_image = $('figure.article-main-image img').attr('src');
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

      // set up behavior of "more" social links
      // this is untouched code from gerald burns and chunkpart
      var social_more_close = function() {
        $article_social_more.removeClass('focusin');
        $body.unbind('click', social_more_close);
      };

      var $article_social_more = $('#article-social-more')
        .bind('focusin', function() {
          $article_social_more.addClass('focusin');
        })
        .bind('focusout', function() {
          $article_social_more.removeClass('focusin');
        })
        .bind('click', function(e) {
          if ( !$article_social_more.is('.focusin') ) {
            $article_social_more.addClass('focusin');
            setTimeout(function() {
              $body.bind('click', social_more_close);
            }, 100);
          }
          e.preventDefault();
        })
        ;
    }
  }
};

// Omniture position tracking
// Parent/ancestor vars to track in reverse order of importance
$.tpregions.add({
  'Header logo' : '.logo',
  'Header social' : '.follow-us',
  'Header user menu' : '.user-menu',
  //'Header search' : '.search',
  'Slim Header' : '.slimnav',
  'Mega Menu' : '#megamenu',
  'Footer' : '#footer',
  'Graveyard' : '#block-tp4-support-tp4-graveyard',
  'Daily Featured Content': '.of_the_day_section',
  'Partner Link': 'aside.on-our-radar',
  'Embedded Content' : '#article-content aside.inline-content',
  'Related Stories' : '#article-footer .field-name-field-related-stories',
  'Series Navigation' : '#series-navigation',
  'Keyword Link' : '.topic-links',
  'Author Full Bio Link' : '.author-bio',
  //'Badge' : '.badge',
  //'Topic Box': '#topic_box',
  'Outbrain Widget': '.OUTBRAIN'
});
        
})(jQuery, Drupal, this, this.document);

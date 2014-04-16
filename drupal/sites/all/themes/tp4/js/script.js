/**
 * @file
 * Scripts for the theme.
 */
(function ($, Drupal, window, document, undefined) {
  $.extend(true, this, {Drupal: {
    behaviors: {
      /**
      * Megamenu Behaviors
      */
      megaMenuBehaviors: {
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

          function makeTall(){$(this).find('.mega-content').fadeIn(100);}
          function makeShort(){$(this).find('.mega-content').fadeOut(100);}

          $("#megamenu").hoverIntent({
            over: makeTall,
            out: makeShort,
            selector: 'li.mega-item'
          });
        }
      },
      /**
        Settings for the snap.js library
      */
      snapperSettings: {
        attach: function(context, settings) {
          Drupal.behaviors.snapper = new Snap({
            element: document.getElementById('page-wrap')
          });

          Drupal.behaviors.snapper.settings({
            dragger: null,
            disable: 'none',
            addBodyClasses: true,
            hyperextensible: false,
            resistance: 0.5,
            flickThreshold: 50,
            transitionSpeed: 0.3,
            easing: 'ease',
            maxPosition: 280,
            minPosition: -1,
            tapToClose: true,
            touchToDrag: false,
            clickToDrag: false,
            slideIntent: 40,
            minDragDistance: 5
          });

          Drupal.behaviors.snapper.on('animated', Drupal.behaviors.closeTpSidebar);

          $('.menu-toggle').on('click', function(e){
            e.preventDefault();
            if ( Drupal.behaviors.snapper.state().state == "closed" ) {
              $('#campaign-drawers').hide();
              $('#tp-drawers').show();
              Drupal.behaviors.snapper.open('left');
            }
            else {
              Drupal.behaviors.snapper.close();
              jQuery('.snap-drawers').hide();
            }
          });
        }
      },

      closeTpSidebar: function() {
        if ( Drupal.behaviors.snapper.state().state == "closed" ) {
          Drupal.behaviors.snapper.close();
          jQuery('.snap-drawers').hide();
        }
      },

      // Campaign Page 
      campaignsnapperSettings: {
        attach: function(context, settings) {
          Drupal.behaviors.campaignsnapper = new Snap({
            element: document.getElementById('page-wrap')
          });

          Drupal.behaviors.campaignsnapper.settings({
            dragger: null,
            disable: 'none',
            addBodyClasses: true,
            hyperextensible: false,
            resistance: 0.5,
            flickThreshold: 50,
            transitionSpeed: 0.3,
            easing: 'ease',
            maxPosition: -280,
            minPosition: 50,
            tapToClose: true,
            touchToDrag: false,
            clickToDrag: false,
            slideIntent: 40,
            minDragDistance: 5
          });


          var db = Drupal.behaviors;

          $('.snap-drawer a').click( db.closeCampaignsSidebar );
          $('.campaign-menu-toggle').on('click', db.toggleCampaignSidebar );
          $('#campaign-drawers a[href*=#]').on('click', db.captureInboundClicks );
          db.campaignsnapper.on('animated', db.scrollToAnchor );
          db.campaignsnapper.on('drag', db.preventHorizontalScrolling );

          setTimeout( db.offsetAnchorsForStickyHeader, 1000 );
        }
      },

      offsetAnchorsForStickyHeader: function() {
        var $header       = $('.header-wrapper'),
            headerHeight  = $header.height() - 30;

        if (  $(window).width() > 768 )
          $('a.card-anchor').css({ top: -headerHeight + 'px' });
      },

      preventHorizontalScrolling: function() {
      },

      toggleCampaignSidebar: function(e) {
        e.preventDefault();
        var db = Drupal.behaviors;
        if ( db.campaignsnapper.state().state == "closed" ) {
          $('#tp-drawers').hide();
          $('#campaign-drawers').show();
          db.campaignsnapper.open('right');
        }
        else  {
          db.closeCampaignsSidebar();
        }
      },

      closeCampaignsSidebar: function() {
        Drupal.behaviors.campaignsnapper.close();
        $('.snap-drawers').hide();
      },

      captureInboundClicks: function(e) {
        e.preventDefault();
        var path = $(e.target)[0].href;
        Drupal.settings.anchorTarget = '#' + path.split('#')[1];
      },

      scrollToAnchor: function() {
        if (Drupal.settings.anchorTarget) {
          $.scrollTo( Drupal.settings.anchorTarget, 250 );
          Drupal.settings.anchorTarget = null;
        }
      },

      /**
       * Behaviors for tpsocial shares
       */
      tpsocialShares: {
          attach: function() {
              var $body = $('body'),
                  isOpenpublishArticle = $body.is('.page-node.node-type-openpublish-article'),
                  isFeatureArticle = $body.is('.page-node.node-type-feature-article');
                  isVideoArticle = $body.is('.page-node.node-type-video');

              if (
                  isOpenpublishArticle
                  || isFeatureArticle
                  || isVideoArticle
              ) {
                  // Setup Social Share Buttons
                  var tp_social_config = {
                      url_append: '?cmpid=organic-share-{{name}}',
                      services: [
                      {
                          name: 'facebook',
                          description: isFeatureArticle ? $('.field-name-field-article-subhead .field-item').text() : null
                      },

                      {
                          name: 'twitter',
                          text: '{{title}}' + (isFeatureArticle ? ' #longform' : ''),
                          via: 'TakePart'
                      },
                      {
                          name: 'googleplus'
                      },

                      {
                          name: 'reddit'
                      },

                      {
                          name: 'email'
                      }
                      ]
                  };

                  // initialize tpsocial and make it sticky.
                  $.when($('.tp-social:not(.tp-social-skip)').tpsocial(tp_social_config))
                  .then($('#article-social').tp4Sticky({offset: 7}));

                  // Set up secondary social share buttons
                  var main_image;
                  if (isOpenpublishArticle) {
                      main_image = $('figure.article-main-image').find('img').attr('src');
                  } else if (isFeatureArticle) {
                      main_image = $('.field-name-field-article-main-image').find('img').attr('src');
                  }
                  var more_services = {
                      pinterest: {
                          name: 'pinterest',
                          media: main_image
                      },
                      tumblr_link: {
                          name: 'tumblr_link'
                      },
                      gmail: {
                          name: 'gmail'
                      },
                      hotmail: {
                          name: 'hotmail'
                      },
                      yahoomail: {
                          name: 'yahoomail'
                      },
                      aolmail: {
                          name: 'aolmail'
                      },

                      //{name: 'myspace'},
                      //{name: 'delicious'},
                      linkedin: {
                          name: 'linkedin'
                      },
                      //{name: 'myaol'},
                      //{name: 'live'},
                      digg: {
                          name: 'digg'
                      },
                      stumbleupon: {
                          name: 'stumbleupon'
                      },
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
      },

      /**
       * Behaviors for Article Nodes
       */
      articleBehaviors: {
          attach: function() {
              var $body = $('body');

              if ($body.is('.page-node.node-type-openpublish-article')
                || $body.is('.page-node.node-type-video')) {

                  // make second ad sticky
                  // (sticky social buttons are done below)
                  $('.block-boxes-ga_ad-bottom').tp4Sticky();

              }
          }
      },

          /**
       * Social Events tracking
       */
      socialEventsTracking: {
          attach: function() {

              $(window).bind('tp-social-share', function(e, args) {
                  takepart.analytics.track('tp-social-share', args);
              });

              $(window).bind('tp-social-click', function(e, args) {
                  takepart.analytics.track('tp-social-click', args);
              });

          }
      },

      /**
       * Handle TP Infographics
       */
      infographics: {
          attach: function() {
              $('.tpinfographic').tpInfographic();
          }
      }
    }
  }});

    // Omniture position tracking
    // Parent/ancestor vars to track in reverse order of importance
  $.tpregions.add({
      'Header logo' : '.logo',
      'Header social' : '.follow-us',
      'Header user menu' : '.user-menu',
      'Slim Header' : '.slim-nav',
      'Mega Menu' : '#megamenu',
      'Footer' : '#footer',
      'Daily Featured Content': '#block-bean-of-the-day',

      // Gallery Properties
      'Gallery - author name': '#block-takepart-gallery-support-takepart-gallery-content .author',
      'Gallery - cover - share icons': '#gallery-cover-social',
      'Gallery - share icons': '#galllery-content-social',
      'Gallery - cover slide - enter gallery': '#gallery-cover',
      'Gallery - gallery description - enter gallery': '#gallery-description .enter-link',
      'Gallery - next slide >': '#block-takepart-gallery-support-takepart-gallery-content #next-slide',
      'Gallery - previous slide <': '#block-takepart-gallery-support-takepart-gallery-content #previous-slide',
      'Gallery - next gallery >': '#block-takepart-gallery-support-takepart-gallery-content #previous-slide',
      'Gallery - related stories': '#gallery-footer .field-name-field-related-stories',

      'Partner Link': '#block-bean-on-our-radar-block',
      'Embedded Content' : '#article-content aside.inline-content',
      'Article - Related Stories' : '#article-footer .field-name-field-related-stories',
      'Series Navigation' : '#series-navigation',
      'Keyword Link' : '.topic-links',
      'Author Full Bio Link' : '.author-bio',
      'Taboola - TPs Most Popular' : '#taboola-bottom-main-column-mix',
      'Taboola - From the Web' : '#taboola-below-main-column',
      'Topic Box' : '.topic-box',
      'TakePart Features': '.node-feature-article .title-block',
      'Home - featured columns' : '#block-views-homepage-columns-block',
      'Home - featured actions' : '#block-views-takeaction-homepage-block',
      'Home - latest headlines' : 'body.page-tp4-homepage #block-views-latest-headlines-block',
      'Home - lead story action' : 'body.page-tp4-homepage .field-name-field-tab-action-override',
      'Home - lead story' : 'body.page-tp4-homepage .panel-main-featured',
      'Home - right rail galleries' : 'body.page-tp4-homepage #block-views-photo-galleries-promo-block',
      'Home - graveyard' : '#block-tp4-support-tp4-graveyard',
      'Home - stories under lead' : 'body.page-tp4-homepage .panel-secondary-featured',
      'Home - top horizontal promo' : '#block-tp4-support-tp4-dont-miss'
  });

})(jQuery, Drupal, this, this.document);

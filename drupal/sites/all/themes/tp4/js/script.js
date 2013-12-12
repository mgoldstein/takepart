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

            function makeTall(){$(this).find('.mega-content').fadeIn(100);}
            function makeShort(){$(this).find('.mega-content').fadeOut(100);}

            $("#megamenu").hoverIntent({
                over: makeTall,
                out: makeShort,
                selector: 'li.mega-item'
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
                touchToDrag: false,
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

                // make second ad sticky
                // (sticky social buttons are done below)
                $('.block-boxes-ga_ad-bottom').tp4Sticky();

                // Setup Social Share Buttons
                var tp_social_config = {
                    url_append: '?cmpid=organic-share-{{name}}',
                    services: [
                    {
                        name: 'facebook'
                    },

                    {
                        name: 'twitter',
                        text: '{{title}}',
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
                .then($('#article-social').tp4Sticky());

                // Set up secondary social share buttons
                var main_image = $('figure.article-main-image img').attr('src');
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
                    }
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

    /**
 * Social Events tracking
 */
    Drupal.behaviors.socialEventsTracking = {
        attach: function() {

            $(window).bind('tp-social-share', function(e, args) {
                takepart.analytics.track('tp-social-share', args);
            });

            $(window).bind('tp-social-click', function(e, args) {
                takepart.analytics.track('tp-social-click', args);
            });

        }
    };


    // Omniture position tracking
    // Parent/ancestor vars to track in reverse order of importance
    $.tpregions.add({
        'Header logo' : '.logo',
        'Header social' : '.follow-us',
        'Header user menu' : '.user-menu',
        'Slim Header' : '.slimnav',
        'Mega Menu' : '#megamenu',
        'Footer' : '#footer',
        'Daily Featured Content': '.of_the_day_section',
        'Partner Link': 'aside.on-our-radar',
        'Embedded Content' : '#article-content aside.inline-content',
        'Related Stories' : '#article-footer .field-name-field-related-stories',
        'Series Navigation' : '#series-navigation',
        'Keyword Link' : '.topic-links',
        'Author Full Bio Link' : '.author-bio',
        "Taboola Article Widget: TP\'s Most Popular" : '#taboola-bottom-main-column-mix',
        "Taboola Article Widget: From the Web" : '#taboola-below-main-column',
        // 'Taboola Widget - Article Page' : '#taboola-bottom-main-column-mix',
        // TODO Going to have to add wrapping divs to distinguish
        // between article and gallery Taboola widgets
        // 'Taboola Widget - Gallery Page' : '',
        'Topic Box' : '.topic-box',
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

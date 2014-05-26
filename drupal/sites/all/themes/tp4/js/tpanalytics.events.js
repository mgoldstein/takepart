(function($, window, undefined) {

    takepart.analytics.skip_addthis = false;

    takepart.analytics.addThis_shareEventHandler = function (evt) {
        if ( takepart.analytics.skip_addthis ) return;
        if (evt.type === 'addthis.menu.share') {
        //takepart.analytics.track('generic_addthis', {name: evt.data.service, url: this.href});
        }
    };

    takepart.analytics.addThis_ready = function (evt) {
        if ( takepart.analytics.skip_addthis ) return;
        addthis.addEventListener('addthis.menu.share', takepart.analytics.addThis_shareEventHandler);
    };

    var normalize_share_title = function(title) {
        switch (title) {
            case ("Like this content on Facebook."):
            case ("facebook_like"):
            case ("facebook"):
                title = "Facebook";
                break;
            case ("Twitter Tweet Button"):
            case ("tweet"):
            case ("twitter"):
                title = "Twitter";
                break;
            case ("+1"):
            case ("googleplus"):
            case ("google_plusone"):
                title = "GooglePlus";
                break;
            case ("linkedin"):
                title = "LinkedIn";
                break;
            case ("stumbleupon"):
                title = "Stumbleupon";
                break;
            case ("pinterest"):
                title = "Pinterest";
                break;
            case ("email"):
                title = "Email";
                break;
            case ("reddit"):
                title = "Reddit";
                break;
        }

        return title;
    };

    // c = prop
    // v = evar

    var special_share_event = "event74";
    var _gaq = window._gaq || [];
    var ga_category = 'Social';
    var ga_action = 'Share';

    var social_click = function(options) {
        var title = normalize_share_title(options.name);
        var evar1, evar4, evar17, evar19, evar20, evar21, evar43, list2, linkTrackVars;
        var $body = $('body');
        if (
            $body.is('.node-type-article')
            || $body.is('.node-type-openpublish-photo-gallery')
            || $body.is('.node-type-feature-article')
            || $body.is('.node-type-video')
            || $body.is('.node-type-flashcard')
        ) {

            evar4 = s.prop4;
            var authors = [];
            $('.byline-author').each(function() {
                authors.push($(this).text());
            });
            evar17 = authors.join(',');
    	    evar19 = $('.node.view-mode-full').data('series');
            evar20 = s.eVar20;
            evar21 = s.eVar21;
        }
        else if (
            $body.is('.node-type-campaign-page')
        ) {
            takepart.analytics.parameters.social_share_platform = title;
            _satellite.track('social_share');
            return;
        }

        if ( title ) {
            var s2=s_gi(Drupal.settings.omniture.s_account);
            s2.events = 'event25';
            linkTrackVars = [];

            // these were set on page load
            linkTrackVars.push('eVar1');
            linkTrackVars.push('eVar12');

            if ( evar4 ) {
                s2.eVar4 = evar4;
                linkTrackVars.push('eVar4');
                s2.prop4 = evar4;
                linkTrackVars.push('prop4');
            }
            if ( evar17 ) {
                s2.eVar17 = evar17;
                linkTrackVars.push('eVar17');
                s2.prop16 = evar17;
                linkTrackVars.push('prop16');
            }
            if ( evar19 ) {
                s2.eVar19 = evar19;
                linkTrackVars.push('eVar19');
                s2.prop18 = evar19;
                linkTrackVars.push('prop18');
            }
            if ( evar20 ) {
                s2.eVar20 = evar20;
                linkTrackVars.push('eVar20');
                s2.prop19 = evar20;
                linkTrackVars.push('prop19');
            }
            if ( evar21 ) {
                s2.eVar21 = evar21;
                linkTrackVars.push('eVar21');
            }
            if ( evar43 ) {
                s2.eVar43 = evar43;
                linkTrackVars.push('eVar43');
            }
            if ( list2 ) {
                s2.list2 = list2;
                linkTrackVars.push('list2');
            }
            linkTrackVars.push('eVar30,eVar27,prop26,events');

            s2.prop26 = title;
            s2.eVar27 = title;
            s2.eVar30 = s2.pageName;
            s2.linkTrackVars = linkTrackVars.join(',');
            s2.linkTrackEvents = 'event25';
            s2.tl(options.url, 'o', 'Content Share');
            s2.linkTrackVars = null;
            s2.linkTrackEvents = null;
            s2.events = null;
            _gaq.push(['_trackEvent', ga_category, ga_action, title]);
        }
    };

    takepart.analytics.add({
        // Putting off til we can get exit tracking figured out
        'on-our-radar-click': function(options) {
            var domain = options.element.hostname.replace('www.', '');

            // Google
            _gaq.push(['_trackEvent', 'Click', 'On Our Radar', domain]);

            // Omniture
            var linkTrackVars = s.linkTrackVars;
            var linkTrackEvents = s.linkTrackEvents;

            var s2 = s_gi(Drupal.settings.omniture.s_account);
            s2.linkTrackVars = 'eVar4,prop4,eVar30,eVar35,eVar36,events';
            s2.linkTrackEvents = 'event44';
            s2.events = 'event44';
            s2.eVar4 = s.prop4;
            s2.prop4 = s.prop4;
            s2.eVar30 = s.pageName;
            s2.eVar35 = domain;
            s2.eVar36 = options.element.href;
            s2.tl(options.element, 'o', 'On Our Radar Click');

            s.linkTrackVars = linkTrackVars;
            s.linkTrackEvents = linkTrackEvents;
        },
        'tp-social-share': function(options) {
            var title = normalize_share_title(options.name);

            var s=s_gi(Drupal.settings.omniture.s_account);
            s.events = 'event22';
            s.prop26 = title;
            s.eVar27 = title;
            s.eVar30 = s.pageName;
            s.linkTrackVars = 'eVar30,eVar27,prop26,events';
            s.linkTrackEvents = 'event22';
            s.tl(options.url, 'o', 'Share Completion');

            _gaq.push(['_trackEvent', ga_category, 'Confirmed Share', title]);
        },
        'tp-social-click': social_click,
        'generic_tpsocial': social_click,
        'generic_addthis': social_click,
        // -------------------------------
        // TP Gallery --------------------
        // -------------------------------
        'gallery-next-gallery-click': function(options) {
            var s2=s_gi(Drupal.settings.omniture.s_account);
            s2.linkTrackVars='prop16,prop20,eVar21,eVar30,eVar17,eVar14,prop12,eVar34,eVar33,events';
            s2.linkTrackEvents='event17';
            s2.events='event17';
            s2.eVar33=options.headline;
            s2.eVar34=options.topic.toLowerCase();
            s2.eVar14=s.eVar14;
            s2.eVar30=s.pageName;
            s2.eVar21=s.eVar21;
            s2.prop20=s2.eVar21;
            var authors = [];
            $('.article-header .authors a').each(function() {
                authors.push($(this).text());
            });
            s2.eVar17=authors.join(',');
            s2.prop16=s2.eVar17;
            s2.tl(options.a, 'o', 'Click on Up Next Promo Gallery');
        },
        'gallery-track-slide': function(options) {
            var token = options.token;
            s.events = ( options.skip_pageview ) ? '' : 'event2';
            s.linkTrackEvents = ( options.skip_pageview ) ? '' : 'event2';

            // Next gallery
            if ( token === 'next-gallery' ) {
                if ( s.events ) s.events += ',';
                s.events += 'event16';
                if ( s.linkTrackEvents ) s.linkTrackEvents += ',';
                s.linkTrackEvents += 'event16';
                s.eVar16 = 'Up Next Gallery Cover';
                s.eVar33 = options.next_gallery_headline;
            // Photo view
            } else if ( token ) {
                if ( s.events ) s.events += ',';
                s.events += 'event15';
                if ( s.linkTrackEvents ) s.linkTrackEvents += ',';
                s.linkTrackEvents += 'event15';
                s.eVar16 = 'Photo';
            // Gallery cover
            } else {
                s.eVar16 = 'Gallery Cover';
            }

            s.t();
        },
        // -------------------------------
        // TP Interstitial----------------
        // -------------------------------
        'tpinterstitial_twitter': function(options) {
            var s=s_gi(Drupal.settings.omniture.s_account);
            s.linkTrackVars='prop46';
            s.linkTrackEvents=null;
            s.events=null;
            s.prop46="Social Interstitial: Twitter Click";
            s.tl(true, 'o', 'Social Interstitial Click');
        },
        'tpinterstitial_facebook': function(options) {
            var s=s_gi(Drupal.settings.omniture.s_account);
            s.linkTrackVars='prop46';
            s.linkTrackEvents=null;
            s.events=null;
            s.prop46="Social Interstitial: Facebook Click";
            s.tl(true, 'o', 'Social Interstitial Click');
        },
        'tpinterstitial_dontshow': function(options) {
            var s=s_gi(Drupal.settings.omniture.s_account);
            s.linkTrackVars='prop46';
            s.linkTrackEvents=null;
            s.events=null;
            s.prop46=options.interstitial_type + " Interstitial: Don't Show Me This Again";
            s.tl(true, 'o', options.interstitial_type + ' Interstitial Click');
        },
        'tpinterstitial_dismiss': function(options) {
            var s=s_gi(Drupal.settings.omniture.s_account);
            s.linkTrackVars='prop46';
            s.linkTrackEvents=null;
            s.events=null;
            s.prop46=options.interstitial_type + " Interstitial: Click on X to Dismiss";
            s.tl(true, 'o', options.interstitial_type + ' Interstitial Click');
        },
        'tpinterstitial_newsletter_signup': function(options) {
            var s=s_gi(Drupal.settings.omniture.s_account);
            s.linkTrackVars = "prop46,eVar22,eVar23,eVar30,events";
            s.linkTrackEvents = "event39";
            s.prop46="Newsletter Interstitial: Email Signup";
            s.eVar22 = "Marketing Interstitial";
            s.eVar23 = options.title;
            s.eVar30 = s.pageName;
            s.events = 'event39';
            s.tl(true, 'o', 'Newsletter Interstitial Signup');
        },
        'tpinterstitial_show_modal': function(options) {
            var s=s_gi(Drupal.settings.omniture.s_account);
            s.linkTrackVars='prop46';
            s.linkTrackEvents=null;
            s.events=null;
            s.prop46=options.interstitial_type + " Interstitial: Popup View";
            s.tl(true, 'o', options.interstitial_type + ' Interstitial Popup View');
        },
        // -------------------------------
        // TP Infographic ----------------
        // -------------------------------
        'tpinfographic_show': function(options) {
            var s=s_gi(Drupal.settings.omniture.s_account);
            s.linkTrackVars='eVar45,eVar30,events';
            s.linkTrackEvents='event45';
            s.events='event45';
            s.eVar45=options.name;
            s.eVar30=s.pageName;
            s.tl(true, 'o', 'Click on Infographic');
        },
        'tpinfographic_embed_show': function(options) {
            var s=s_gi(Drupal.settings.omniture.s_account);
            s.linkTrackVars='eVar45,eVar30,events';
            s.linkTrackEvents='event46';
            s.events='event46';
            s.eVar45=options.name;
            s.eVar30=s.pageName;
            s.tl(true, 'o', 'Click on Embed Infographic Link');
        },
        // -----------------------------------
        // Newsletter Signups ----------------
        // -----------------------------------
        'newsletter_signup': function(options) {
            var $body = $('body');
            if ($body.is('.node-type-campaign-page')) {
                takepart.analytics.parameters.newsletter_name = options.name;
                takepart.analytics.parameters.newsletter_signup_method = 'Campaign Email Signup + Social Card';
                _satellite.track('newsletter_signup');
            }
            else {
                var s=s_gi(Drupal.settings.omniture.s_account);
                s.linkTrackVars='eVar23,eVar30,events';
                s.linkTrackEvents='event39';
                s.events = 'event39';
                s.eVar23 = options.name;
                if ('source' in options && options.source && options.source !== '') {
                    s.eVar22 = options.source;
                    s.linkTrackVars = 'eVar22,' + s.linkTrackVars;
                }
                s.eVar30 = s.pageName;
                s.tl(true, 'o', 'Newsletter Signup');
            }
        },
        // -----------------------------------
        // Place at the Table ----------------
        // -----------------------------------
        'patt_show_modal': function(options) {
            var s=s_gi(Drupal.settings.omniture.s_account);
            s.linkTrackVars='eVar73,prop73,eVar30,events';
            s.linkTrackEvents='event73';
            s.events='event73';
            s.eVar30="takepart:place-at-the-table:APATT Gallery";
            s.eVar73=options.name;
            s.prop73=options.name;
            s.tl(true, 'o', 'APATT - SNAP Gallery Modal View');
        },
        'patt_email_modal': function(options) {
            var s=s_gi(Drupal.settings.omniture.s_account);
            s.linkTrackVars='eVar27,prop27,eVar30,eVar73,prop73,events';
            s.linkTrackEvents=special_share_event;
            s.events=special_share_event;
            s.eVar27="Email";
            s.prop27="Email";
            s.eVar30=s.pageName;
            s.eVar73=options.name;
            s.prop73=options.name;
            s.tl(true, 'o', 'SNAP Gallery share');
        },
        'patt_twitter_modal': function(options) {
            var s=s_gi(Drupal.settings.omniture.s_account);
            s.events=special_share_event;
            s.eVar27="Twitter";
            s.prop27="Twitter";
            s.eVar30=s.pageName;
            s.eVar73=options.name;
            s.prop73=options.name;
            s.linkTrackVars='eVar27,prop27,eVar30,eVar73,prop73,events';
            s.linkTrackEvents=special_share_event;
            s.tl(true, 'o', 'SNAP Gallery share');
        },
        'patt_facebook_modal': function(options) {
            var s=s_gi(Drupal.settings.omniture.s_account);
            s.linkTrackVars='eVar27,prop27,eVar30,eVar73,prop73,events';
            s.linkTrackEvents=special_share_event;
            s.events=special_share_event;
            s.eVar27="Facebook";
            s.prop27="Facebook";
            s.eVar30=s.pageName;
            s.eVar73=options.name;
            s.prop73=options.name;
            s.tl(true, 'o', 'SNAP Gallery share');
        },
        'patt_email_gallery': function(options) {
            var s=s_gi(Drupal.settings.omniture.s_account);
            s.linkTrackVars='eVar27,prop27,eVar30,eVar73,prop73,events';
            s.linkTrackEvents=special_share_event;
            s.events=special_share_event;
            s.eVar27="Email";
            s.prop27="Email";
            s.eVar30=s.pageName;
            s.eVar73="SNAP Alumni Gallery";
            s.prop73="SNAP Alumni Gallery";
            s.tl(true, 'o', 'SNAP Gallery share');
        },
        'patt_twitter_gallery': function(options) {
            var s=s_gi(Drupal.settings.omniture.s_account);
            s.linkTrackVars='eVar27,prop27,eVar30,eVar73,prop73,events';
            s.linkTrackEvents=special_share_event;
            s.events=special_share_event;
            s.eVar27="Twitter";
            s.prop27="Twitter";
            s.eVar30=s.pageName;
            s.eVar73="SNAP Alumni Gallery";
            s.prop73="SNAP Alumni Gallery";
            s.tl(true, 'o', 'SNAP Gallery share');
        },
        'patt_facebook_gallery': function(options) {
            var s=s_gi(Drupal.settings.omniture.s_account);
            s.linkTrackVars='eVar27,prop27,eVar30,eVar73,prop73,events';
            s.linkTrackEvents=special_share_event;
            s.events=special_share_event;
            s.eVar27="Facebook";
            s.prop27="Facebook";
            s.eVar30=s.pageName;
            s.eVar73="SNAP Alumni Gallery";
            s.prop73="SNAP Alumni Gallery";
            s.tl(true, 'o', 'SNAP Gallery share');
        },
        // -----------------------------------
        // Homepage --------------------------
        // -----------------------------------
        'homepage_secondary_featured': function(options) {
            var s=s_gi(Drupal.settings.omniture.s_account);
            s.linkTrackVars = 'prop36';
            s.linkTrackEvents = 'None';
            s.events = null;
            s.prop36 = options.name;
            s.tl(options.target, 'o', options.name, null, 'navigate');
        },
        // -----------------------------------
        // Article ---------------------------
        // -----------------------------------

        'article_more_on_takepart': function(options) {
            var s=s_gi(Drupal.settings.omniture.s_account);
            s.linkTrackVars = 'prop36';
            s.linkTrackEvents = 'None';
            s.events = null;
            s.prop36 = options.name;
            s.tl(options.target, 'o', options.name, null, 'navigate');
        },
        // -----------------------------------
        // Flashcards ------------------------
        // -----------------------------------
        
        'flashcard-tooltip': function(options) {
            var s=s_gi(Drupal.settings.omniture.s_account);
            s.linkTrackVars='eVar26,eVar30,events';
            s.linkTrackEvents='event89';
            s.events='event89';
            s.eVar26=options.term;
            s.eVar30=s.pageName;
            s.tl(true, 'o', 'Flashcard Tooltip Popup');
            delete s.linkTrackVars;
            delete s.linkTrackEvents;
            delete s.events;
            delete s.eVar26;
            delete s.eVar30;            
        },
        'flashcard-click': function(options) {
            var s=s_gi(Drupal.settings.omniture.s_account);
            s.linkTrackVars='eVar26,eVar30,events';
            s.linkTrackEvents='event90';
            s.events='event90';
            s.eVar26=options.term;
            s.eVar30=s.pageName;
            s.tl(true, 'o', 'Flashcard Tooltip Popup');
            delete s.linkTrackVars;
            delete s.linkTrackEvents;
            delete s.events;
            delete s.eVar26;
            delete s.eVar30;            
        }

    });

    // Document Ready
    $(function() {
        if (typeof addthis !== "undefined" && addthis) {
            addthis.addEventListener('addthis.ready', takepart.analytics.addThis_ready);
        }

        // Pinterest doesn't work when it's just a link
        $('body')
        .delegate('a.addthis_button_pinterest_pinit', 'click', function() {
            takepart.analytics.track('generic_addthis', 'pinterest');
        })

        .delegate('.node-type-openpublish-article #block-bean-of-the-day a[href]', 'click', function(event) {
            takepart.analytics.track('article_more_on_takepart', {name: 'Article - right rail - more on tp', target: this});
            // return false;
        })
        .delegate('.panel-takepart-homepage .panel-tpl-secondary-featured a[href]', 'click', function(event) {
            takepart.analytics.track('homepage_secondary_featured', {name: 'Home - tpl featured stories', target: this});
            // return false;
        });

    /* // Track clicks to addthis iframes
    var hoverframe = null;
    var tracked = [];
    window.optimizely = window.optimizely || [];

    var trackshare = function(target) {
        var $target = $(target);
        var title;
        if ( target.tagName != 'A' ) {
            $target = $target.closest('a');
        }

        title = $target.attr('title');

        if ( typeof tracked[title] != 'undefined' ) return true;

        tracked[title] = true;

        takepart.analytics.track('generic_addthis', title);
    };

    $('body')
        .delegate('.addthis_toolbox iframe, .addThis iframe', 'mouseover', function() {
            hoverframe = this;
        })
        .delegate('.addthis_toolbox iframe, .addThis iframe', 'mouseout', function() {
            hoverframe = null;
        })
        //.delegate('.takepart_addthis_leftpanel a', 'click', function() {
        //    trackshare(this);
        //})
        ;

    $(window).bind('blur', function() {
        if ( hoverframe ) trackshare(hoverframe);
    });*/

    });

})(jQuery, window);

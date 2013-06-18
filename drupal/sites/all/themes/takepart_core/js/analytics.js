(function($, window, undefined) {

// Setup ----------------

if ( typeof takepart == 'undefined' ) {
    window.takepart = {};
    takepart = window.takepart;
}

//Analytics functions:
takepart.analytics = takepart.analytics || {};

takepart.analytics.skip_addthis = false;

takepart.analytics.addThis_shareEventHandler = function (evt) {
    if ( takepart.analytics.skip_addthis ) return;
    if (evt.type == 'addthis.menu.share') {
        takepart.analytics.track('generic_addthis', evt.data.service, this.href);
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

// Named tracking
takepart.analytics.track = function(name) {
    var args = arguments || [];
    var special_share_event = "event74";
    var s = window.s || {};
    var _gaq = window._gaq || [];
    var ga_category = 'Social';
    var ga_action = 'Share';

    switch (name) {
        case 'tp-social-share':
            var title = normalize_share_title(args[1].name);

            var s=s_gi(Drupal.settings.omniture.s_account);
            s.events = 'event22';
            s.prop26 = title;
            s.eVar27 = title;
            s.eVar30 = s.pageName;
            s.linkTrackVars = 'eVar30,eVar27,prop26,events';
            s.linkTrackEvents = 'event22';
            s.tl(args[2], 'o', 'Share Completion');
            _gaq.push(['_trackEvent', ga_category, 'Confirmed Share', title]);
            break;
        case 'tp-social-click':
            var tpsargs = args[1];
            args[1] = tpsargs.name;
            // PASS THROUGH
        case 'generic_tpsocial':
        case 'generic_addthis':
            var title = normalize_share_title(args[1]);
            var evar4, evar17, evar19, evar21, linkTrackVars;

            // Series stuff for article, add photo gallery later
            if ( $('body').is('.node-type-article') ) {
                evar4 = s.prop4;
                var authors = [];
                $('.article-header .authors a').each(function() {
                    authors.push($(this).text());
                })
                evar17 = authors.join(',');
                evar19 = $('.article').data('series');
                evar21 = s.eVar21;
            }

            if ( title ) {
                var s=s_gi(Drupal.settings.omniture.s_account);
                s.events = 'event25';
                linkTrackVars = [];

                if ( evar4 ) {
                    s.eVar4 = evar4;
                    linkTrackVars.push('eVar4');
                    s.prop4 = evar4;
                    linkTrackVars.push('prop4');
                }
                if ( evar17 ) {
                    s.eVar17 = evar17;
                    linkTrackVars.push('eVar17');
                    s.prop16 = evar17;
                    linkTrackVars.push('prop16');
                }
                if ( evar19 ) {
                    s.eVar19 = evar19;
                    linkTrackVars.push('eVar19');
                    s.sProp18 = evar19;
                    linkTrackVars.push('prop18');
                }
                if ( evar21 ) {
                    s.eVar21 = evar21;
                    linkTrackVars.push('eVar21');
                }
                linkTrackVars.push('eVar30,eVar27,prop26,events')

                s.prop26 = title;
                s.eVar27 = title;
                s.eVar30 = s.pageName;
                s.linkTrackVars = linkTrackVars.join(',');
                s.linkTrackEvents = 'event25';
                s.tl(args[2], 'o', 'Content Share');
                _gaq.push(['_trackEvent', ga_category, ga_action, title]);
            }
            break;
        // -------------------------------
        // TP Infographic ----------------
        // -------------------------------
        case 'tpinfographic_show':
            var s=s_gi(Drupal.settings.omniture.s_account);
            s.linkTrackVars='eVar45,eVar30,events';
            s.linkTrackEvents='event45';
            s.events='event45';
            s.eVar45=args[1];
            s.eVar30=s.pageName;
            s.tl(true, 'o', 'Click on Infographic');
            break;
        case 'tpinfographic_embed_show':
            var s=s_gi(Drupal.settings.omniture.s_account);
            s.linkTrackVars='eVar45,eVar30,events';
            s.linkTrackEvents='event46';
            s.events='event46';
            s.eVar45=args[1];
            s.eVar30=s.pageName;
            s.tl(true, 'o', 'Click on Embed Infographic Link');
            break;
        // -----------------------------------
        // Place at the Table ----------------
        // -----------------------------------
        case 'patt_show_modal':
            var s=s_gi(Drupal.settings.omniture.s_account);
            s.linkTrackVars='eVar73,prop73,eVar30,events';
            s.linkTrackEvents='event73';
            s.events='event73';
            s.eVar30="takepart:place-at-the-table:APATT Gallery";
            s.eVar73=args[1];
            s.prop73=args[1]; 
            s.tl(true, 'o', 'APATT - SNAP Gallery Modal View');
            break;
        case 'patt_email_modal':
            var s=s_gi(Drupal.settings.omniture.s_account);
            s.linkTrackVars='eVar27,prop27,eVar30,eVar73,prop73,events';
            s.linkTrackEvents=special_share_event;
            s.events=special_share_event;
            s.eVar27="Email";
            s.prop27="Email";
            s.eVar30=s.pageName;
            s.eVar73=args[1];
            s.prop73=args[1]; 
            s.tl(true, 'o', 'SNAP Gallery share');
            break;
        case 'patt_twitter_modal':
            var s=s_gi(Drupal.settings.omniture.s_account);
            s.events=special_share_event;
            s.eVar27="Twitter";
            s.prop27="Twitter";
            s.eVar30=s.pageName;
            s.eVar73=args[1];
            s.prop73=args[1]; 
            s.linkTrackVars='eVar27,prop27,eVar30,eVar73,prop73,events';
            s.linkTrackEvents=special_share_event;
            s.tl(true, 'o', 'SNAP Gallery share');
            break;
        case 'patt_facebook_modal':
            var s=s_gi(Drupal.settings.omniture.s_account);
            s.linkTrackVars='eVar27,prop27,eVar30,eVar73,prop73,events';
            s.linkTrackEvents=special_share_event;
            s.events=special_share_event;
            s.eVar27="Facebook";
            s.prop27="Facebook";
            s.eVar30=s.pageName;
            s.eVar73=args[1];
            s.prop73=args[1]; 
            s.tl(true, 'o', 'SNAP Gallery share');
            break;
        case 'patt_email_gallery':
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
            break;
        case 'patt_twitter_gallery':
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
            break;
        case 'patt_facebook_gallery':
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
            break;
    }
};

// Document Ready
$(function() {
    if (typeof addthis != "undefined" && addthis) {
        addthis.addEventListener('addthis.ready', takepart.analytics.addThis_ready);
    }

    // Pinterest doesn't work when it's just a link
    $('body')
        .delegate('a.addthis_button_pinterest_pinit', 'click', function() {
            takepart.analytics.track('generic_addthis', 'pinterest');
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

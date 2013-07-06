(function($, window, undefined) {

takepart.analytics.skip_addthis = false;

takepart.analytics.addThis_shareEventHandler = function (evt) {
    if ( takepart.analytics.skip_addthis ) return;
    if (evt.type == 'addthis.menu.share') {
        takepart.analytics.track('generic_addthis', {name: evt.data.service, url: this.href});
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
            s.prop18 = evar19;
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
        s.tl(options.url, 'o', 'Content Share');
        _gaq.push(['_trackEvent', ga_category, ga_action, title]);
    }
};

takepart.analytics.add({
    // Putting off til we can get exit tracking figured out
    'on-our-radar-click': function(options) {
        var domain = options.element.hostname.replace('www.', '');
        _gaq.push(['_trackEvent', 'Click', 'On Our Radar', domain]);

        // Omniture will handle the click
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
        var s=s_gi(Drupal.settings.omniture.s_account);
        s.linkTrackVars='events';
        s.linkTrackEvents='event17';
        s.events='event17';
        s.eVar14=options.headline;
        s.tl(true, 'o', 'Click on Up Next Promo Gallery');
    },
    'gallery-track-slide': function(options) {
        var token = options.token;
        omniture = s.prop15.split(':');
        s.prop15 = omniture[0] + ':' + omniture[1] + ((token) ? ':' + token : '');
        s.eVar15 = s.prop15;
        s.events = ( options.skip_pageview ) ? '' : 'event2';
        s.linkTrackEvents = ( options.skip_pageview ) ? '' : 'event2';

        // Next gallery
        if ( token == 'next-gallery' ) {
            if ( s.events ) s.events += ',';
            s.events += 'event16';
            if ( s.linkTrackEvents ) s.linkTrackEvents += ',';
            s.linkTrackEvents += 'event16';
            s.eVar16 = 'Up Next Gallery Cover';
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
    }
});

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

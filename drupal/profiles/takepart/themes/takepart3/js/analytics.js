(function($, window, undefined) {

// Setup ----------------

if ( typeof takepart == "undefined" || !takepart ) {
    window.takepart = {};
}

//Analytics functions:
takepart.analytics = takepart.analytics || {};

takepart.analytics.addThis_shareEventHandler = function (evt) {
    if (evt.type == 'addthis.menu.share') {
        takepart.analytics.track('generic_addthis', evt.data.service, this.href);
    }
};

takepart.analytics.omn_clickTrack = function (target) {
    jQuery(target).click(function() {
        var link_title = jQuery(this).attr('title');
        var title = convert_title(link_title);
        s.events='event25';
        s.prop26=title;
        s.eVar27=title;
        s.linkTrackVars='eVar27,prop26,events';
        s.linkTrackEvents='event25';
        s.tl(this.href, 'o', 'Content Share');
    });
};

takepart.analytics.addThis_ready = function (evt) {
    addthis.addEventListener('addthis.menu.share', takepart.analytics.addThis_shareEventHandler);
};

// Named tracking
takepart.analytics.track = function(name) {
    var args = arguments || [];
    var special_share_event = "event74";
    var s = window.s || {};

    switch (name) {
        case 'generic_addthis':
            var title = null;
            switch (args[1]) {
                case ("Like this content on Facebook."):
                case ("facebook_like"):
                    title = "Facebook Recommend";
                    break;
                case ("Twitter Tweet Button"):
                case ("tweet"):
                    title = "Twitter Tweet";
                    break;
                case ("+1"):
                case ("google_plusone"):
                    title = "Google Plus One";
                    break;
                case ("linkedin"):
                    title = "LinkedIn";
                    break;
                case ("email"):
                    title = "Email";
                    break;
            }

            if ( title ) {
                s.events = 'event25';
                s.prop26 = title;
                s.eVar27 = title;
                s.linkTrackVars = 'eVar27,prop26,events';
                s.linkTrackEvents = 'event25';
                s.tl(args[2], 'o', 'Content Share');
            }
            break;
        case 'patt_show_modal':
            var s=s_gi(Drupal.settings.omniture.s_account);
            s.linkTrackVars='eVar73,prop73,eVar30,eVar28,events';
            s.linkTrackEvents='event73';
            s.events='event73';
            s.eVar28="APATT - SNAP Gallery Modal View";
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
            s.linkTrackVars='eVar27,prop27,eVar30,eVar73,prop73,events';
            s.linkTrackEvents=special_share_event;
            s.events=special_share_event;
            s.eVar27="Twitter";
            s.prop27="Twitter";
            s.eVar30=s.pageName;
            s.eVar73=args[1];
            s.prop73=args[1]; 
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
    if (typeof addthis != "undefined") {
        if(addthis) {
            addthis.addEventListener('addthis.ready', takepart.analytics.addThis_ready);
        }
    }
    /* Incorrectly attaches social sharing event to Take Action button
     * takepart.analytics.omn_clickTrack('.take_action_button');
     */

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

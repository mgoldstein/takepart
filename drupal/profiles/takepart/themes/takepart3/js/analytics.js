if ( typeof takepart == "undefined" || !takepart ) {
    var takepart = {};
}

//Analytics functions:
takepart.analytics = takepart.analytics || {};

takepart.analytics.addThis_shareEventHandler = function (evt) {

    if (evt.type == 'addthis.menu.share') {

        var title;

        switch (evt.data.service) {
            case ("facebook_like"):
                title = "Facebook Recommend";
                break;
            case ("tweet"):
                title = "Twitter Tweet";
                break;
            case ("google_plusone"):
                title = "Google Plus One";
                break;
            case ("linkedin"):
                title = "LinkedIn";
                break;
        }

        if (title) {
            s.events = 'event25';
            s.prop26 = title;
            s.eVar27 = title;
            s.linkTrackVars = 'eVar27,prop26,events';
            s.linkTrackEvents = 'event25';
            s.tl(this.href, 'o', 'Content Share');
        }
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
console.log(args[1]);
    switch (name) {
        case 'patt_show_modal':
            var s=s_gi(Drupal.settings.omniture.s_account);
            s.linkTrackVars='eVar73,eVar30,events';
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
            s.linkTrackEvents='event25';
            s.events="event25";
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
            s.linkTrackEvents='event25';
            s.events="event25";
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
            s.linkTrackEvents='event25';
            s.events="event25";
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
            s.linkTrackEvents='event25';
            s.events="event25";
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
            s.linkTrackEvents='event25';
            s.events="event25";
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
            s.linkTrackEvents='event25';
            s.events="event25";
            s.eVar27="Facebook";
            s.prop27="Facebook";
            s.eVar30=s.pageName;
            s.eVar73="SNAP Alumni Gallery";
            s.prop73="SNAP Alumni Gallery"; 
            s.tl(true, 'o', 'SNAP Gallery share');
            break;
    }
};
if (typeof marigold_hotel_contest == "undefined" || !marigold_hotel_contest) {
    var marigold_hotel_contest = {};
}

marigold_hotel_contest.widgets = {
    addthis_email: function (elem) {
        jQuery(elem).attr("addthis:ui_email_note", "Marigold Campaign Email Text HERE.");
    },
    analytics: function (elem) {
        jQuery(elem).click(function () {
            var link_title = jQuery(this).attr('title');
            if(convert_title) {
            	var title = convert_title(link_title);
            } else {
            	var title = link_title;
            }
            s.events = 'event25,event19';
            s.prop26 = title;
            s.eVar27 = title;
            s.eVar28 = 'Content Share';
            s.linkTrackVars = 'eVar27,prop26,events';
            s.linkTrackEvents = 'event25';
            s.tl(this.href, 'o', 'Content Share');
        });
    },
}


jQuery(document).ready(function () {
    marigold_hotel_contest.widgets.addthis_email(jQuery('#mg-email-share-block .addthis_button_email'));
    marigold_hotel_contest.widgets.analytics(jQuery('#mg-email-share-block .addthis_button_email'));
});
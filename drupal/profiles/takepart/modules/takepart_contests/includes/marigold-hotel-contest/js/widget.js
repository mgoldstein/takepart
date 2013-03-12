if (typeof marigold_hotel_contest == "undefined" || !marigold_hotel_contest) {
    var marigold_hotel_contest = {};
}

marigold_hotel_contest.widgets = {
    addthis_email: function (elem) {
    	//I don't know what they want here:
        //jQuery(elem).attr("addthis:ui_email_note", "Marigold Campaign Email Text HERE.");
    },
    analytics: function (elem) {
        jQuery(elem).click(function () {
            var link_title = jQuery(this).attr('title');
            if(convert_title) {
            	var title = convert_title(link_title);
            } else {
            	var title = link_title;
            }
            
            s.events = 'event19';
            s.eVar28 = 'Content Share';
            s.linkTrackVars = 'eVar28,events';
            s.linkTrackEvents = 'event19';
            s.tl(this.href, 'o', 'Action Click');
    
            // clear the event tracking so that clicks from
            // anchor tags do not repeat the event
            s.events = '';
            s.linkTrackVars = 'events';
        });
    },
    addthis_email_submitted: function (elem) {
      addthis.addEventListener('addthis.menu.share', addthisMenuShareEventHandler);
    },
    contest_entered: function () {

      if (jQuery.cookie("contest_entered") != null) {
        var name = jQuery.cookie("contest_entered");
        if (name.length > 0) {
          while (name.indexOf("+") != -1) {
            name = name.replace("+"," ");
          }
          s.events = 'event29';
          s.prop24 = name;
          s.eVar24 = name;
          s.linkTrackVars = 'eVar24,prop24,events';
          s.linkTrackEvents = 'event29';
          s.tl(this.href, 'o', 'Content Share');

          s.events = 'event19';
          s.eVar28 = 'Contest Entry';
          s.linkTrackVars = 'eVar28,events';
          s.linkTrackEvents = 'event19';
          s.tl(this.href, 'o', 'Action Click');
        }
      
        // delete the cookie
        jQuery.cookie("contest_entered", null);
      }
    }
}

function addthisMenuShareEventHandler(evt) {
  // one of these two works, (I think email)
  if (evt.data.service == 'toemail' || evt.data.service == 'email') {
    s.events = 'event19';
    s.eVar28 = 'Content Share';
    s.linkTrackVars = 'eVar28,events';
    s.linkTrackEvents = 'event19';
    s.tl(this.href, 'o', 'Action Click');
    
    // clear the event tracking so that clicking the
    // 'X' on the share window does repeat the event
    s.events = '';
    s.linkTrackVars = 'events';
  }
}

jQuery(document).ready(function () {
    marigold_hotel_contest.widgets.addthis_email(jQuery('#mg-email-share-block .addthis_button_email'));
    marigold_hotel_contest.widgets.analytics(jQuery('#mg-email-share-block .addthis_button_email'));
    marigold_hotel_contest.widgets.analytics(jQuery('#mg-email-share-block-2 .addthis_button_email'));
    marigold_hotel_contest.widgets.analytics(jQuery('#mg-contest-addthis-block .addthis_button_facebook'));
    marigold_hotel_contest.widgets.analytics(jQuery('#mg-contest-addthis-block .addthis_button_twitter'));
    marigold_hotel_contest.widgets.addthis_email_submitted(jQuery('#mg-contest-addthis-block .addthis_button_twitter'));
    marigold_hotel_contest.widgets.contest_entered();
});
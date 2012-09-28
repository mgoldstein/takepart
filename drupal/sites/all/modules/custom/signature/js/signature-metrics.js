(function ($) {
  $(document).ready(function() {
    // Signature form view
    $(".node.signature-list").bind(
      'signature_form_view', function(e, title, type) {
        if (type === 'petition_action') {
          s.linkTrackVars = "eVar25,eVar30,events";
          s.linkTrackEvents = "event26";
          s.eVar25 = title;
          s.events = 'event26';
          s.eVar30 = s.pageName;
          s.tl(true, 'o', 'petition view');
        }
        else if (type === 'pledge_action') {
          s.linkTrackVars = "eVar32,eVar30,events";
          s.linkTrackEvents = "event31";
          s.eVar32 = title;
          s.events = 'event31';
          s.eVar30 = s.pageName;
          s.tl(true, 'o', 'pledge view');
        }
      }
    );
    // Signature form submit
    $(".node.signature-list").bind(
      'signature_form_submit', function(e, title, type) {
        if (type === 'petition_action') {
          s.linkTrackVars = "eVar25,eVar30,events";
          s.linkTrackEvents = "event27";
          s.eVar25 = title;
          s.events = 'event27';
          s.eVar30 = s.pageName;
          s.tl(true, 'o', 'petition submit');
        }
        else if (type === 'pledge_action') {
          s.linkTrackVars = "eVar32,eVar30,events";
          s.linkTrackEvents = "event32";
          s.eVar32 = title;
          s.events = 'event32';
          s.eVar30 = s.pageName;
          s.tl(true, 'o', 'pledge submit');
        }
      }
    );
    // Newsletter Signup
    $(".node.signature-list").bind(
      'newsletter_signup', function(e, title) {
        s.linkTrackVars = "eVar23,eVar30,events";
        s.linkTrackEvents = "event39";
        s.eVar23 = title;
        s.eVar30 = s.pageName;
        s.events = 'event39';
        s.tl(true, 'o', 'Newsletter Signup');
      }
    );
  });
})(jQuery);

(function ($) {
  $(document).ready(function() {
    // Signature form view
    console.log($(".node.signature-list"));
    $(".node.signature-list").bind(
      'signature_form_view', function(e, title) {
        s.linkTrackVars = "eVar25,eVar30,events";
        s.linkTrackEvents = "event26";
        s.eVar25 = title;
        s.eVar30 = s.pageName;
        s.events = 'event26';
        s.tl(true, 'o', 'petition view');
      }
    );
    // Signature form submit
    $(".node.signature-list").bind(
      'signature_form_submit', function(e, title) {
        s.linkTrackVars = "eVar23,eVar30,events";
        s.linkTrackEvents = "event27";
        s.eVar23 = title;
        s.eVar30 = s.pageName;
        s.events = 'event27';
        s.tl(true, 'o', 'petition submit');
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

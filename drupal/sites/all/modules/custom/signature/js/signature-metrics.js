(function ($) {

  var fireSignatureFormViewed = function (name) {
    s.events = 'event26';
    s.eVar25 = name;
    s.eVar30 = s.pageName;
    s.linkTrackVars='eVar25,eVar30,events';
    s.linkTrackEvents='event26';
    s.tl(true, 'o', 'petition view');
  };

  var fireSignatureFormSubmitted = function (name) {
    s.events = 'event27';
    s.eVar25 = name;
    s.eVar30 = s.pageName;
    s.linkTrackVars='eVar25,eVar30,events';
    s.linkTrackEvents='event27';
    s.tl(true, 'o', 'petition submit');
  };

  var fireSignatureNewsletterSignup = function (name) {
    s.events = 'event39';
    s.eVar23 = name;
    s.eVar30 = s.pageName;
    s.linkTrackVars = "eVar23,eVar30,events";
    s.linkTrackEvents = "event39";
    s.tl(true, 'o', 'Newsletter Signup');
  };

  Drupal.behaviors.signatureMetrics = {
    attach: function (context, settings) {
      if ('signature' in settings && 'metrics' in settings.signature) {
        var latch = settings.signature.metrics.viewedLatch; 
        if (jQuery.cookie(latch) == null) {
          fireSignatureFormViewed(settings.signature.metrics.nodeTitle);
          jQuery.cookie(latch, 1, {path:'/'});
        }
        if ('newsletterSignup' in settings.signature.metrics) {
          if (settings.signature.metrics.newsletterSignup) {
            fireSignatureNewsletterSignup(
              settings.signature.metrics.newsletterGroup);
          }
        }
        if ('signatureAdded' in settings.signature.metrics) {
          if (settings.signature.metrics.signatureAdded) {
            fireSignatureFormSubmitted(settings.signature.metrics.nodeTitle);
          } 
        } 
      }
    }
  };
})(jQuery);

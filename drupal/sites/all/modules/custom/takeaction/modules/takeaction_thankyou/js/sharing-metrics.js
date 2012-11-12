(function ($) {
  var takeactionThankYouShareListener = function (evt) {
    var share_method = 'Unknown';
    var services = {
      'email': 'Email',
      'facebook': 'Facebook',
      'twitter': 'Twitter',
      'linkedin': 'LinkedIn',
      'pinterest': 'Pinterest',
      'stumbleupon': 'StumbleUpon',
      'digg': 'Digg',
      'google_plusone_badge': 'Google +1'
    }
    if (evt.data.service in services) {
      share_method = services[evt.data.service];
    }

    var tracked = [
      'eVar27', 'prop27',
      'eVar30',
      //'eVar50', 'prop50',
      //'eVar51', 'prop51',
      //'eVar52', 'prop52',
      'eVar53', 'prop53',
      'eVar54', 'prop54',
      'eVar55', 'prop55',
      'eVar56', 'prop56',
      'eVar58', 'prop58',
      'prop66'
    ];
    
    s.linkTrackVars = tracked.join();
    s.linkTrackEvents = 'event60';
    s.events = 'event60';

    s.eVar27 = s.prop27 = share_method;
    s.eVar30 = s.pageName; 
    //s.eVar50 = s.prop50 = null;
    //s.eVar51 = s.prop51 = null;
    //s.eVar52 = s.prop52 = null;
    if (Drupal.settings.takeaction.thankyou) {
      s.eVar53 = s.prop53 = Drupal.settings.takeaction.thankyou.action_title;
      s.eVar54 = s.prop54 = Drupal.settings.takeaction.thankyou.action_url;
      s.eVar55 = s.prop55 = Drupal.settings.takeaction.thankyou.action_type;
      s.eVar56 = s.prop56 = Drupal.settings.takeaction.thankyou.action_topic;
    }
    s.eVar58 = s.prop58 = Drupal.settings.takeaction.guid;
    s.prop66 = "Social Share";

    s.tl(true, 'o', 'Content Share');
  };
  Drupal.behaviors.addthisField = {
    attach: function (context, settings) {
      // Setup the share event listener.
      if (window.addthis) {
        $('body').once('addthis-init', function () {
          window.addthis.addEventListener('addthis.menu.share',
            takeactionThankYouShareListener);
        });
      }
    }
  };
})(jQuery);

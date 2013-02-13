// Add analytics to the TakePart JavaScript name space
if (typeof tp === 'undefined' || !tp) { var tp = {}; }
if (!tp.analytics) { tp.analytics = {'events': {}}; }

(function ($) {

  var view_modes = {
    'full': 'Full Page',
    'embedaction': 'Embedded',
    'embedaction_expanded': 'Embedded',
    'thank_you': 'Thank You Page'
  };

  $(document).ready(function () {
    $('.more-actions .button').click(function (event) {
      $('body').analyticstracking('fireInstance', 'see_more_actions_click');
    });
  });

  tp.analytics.events['action_view'] = function (args) {
    var tracked = [
      'eVar4', 'prop4',
      'eVar39',
      'eVar53', 'prop53',
      'eVar55', 'prop55',
      'eVar56', 'prop56',
      'prop66',
      'prop67',
      'events'
    ];
    s.linkTrackVars = tracked.join(',');
    s.events = s.linkTrackEvents = 'event55';
    s.eVar4 = s.prop4 = args.type_name;
    s.eVar39 = view_modes[args.view_mode];
    s.eVar53 = s.prop53 = args.action_name;
    s.eVar55 = s.prop55 = args.action_type;
    s.eVar56 = s.prop56 = args.topic;
    s.prop66 = 'Action Page View';
    s.prop67 = s.pageName;
    s.tl(true, 'o', 'action view');
  };

  tp.analytics.events['action_taken'] = function (args) {
    var tracked = [
      'eVar4', 'prop4',
      'eVar30',
      'eVar39',
      'eVar53', 'prop53',
      'eVar55', 'prop55',
      'eVar56', 'prop56',
      'prop66',
      'prop67',
      'events'
    ];
    s.linkTrackVars = tracked.join(',');
    s.events = s.linkTrackEvents = 'event56,' + args.extra_event;
    s.eVar4 = s.prop4 = args.type_name;
    s.eVar30 = s.pageName;
    s.eVar39 = view_modes[args.view_mode];
    s.eVar53 = s.prop53 = args.action_name;
    s.eVar55 = s.prop55 = args.action_type;
    s.eVar56 = s.prop56 = args.topic;
    s.eVar60 = s.prop60 = args.empowered_by;
    s.prop66 = 'Action Plage Completion';
    s.prop67 = 'Action Plage Completion';
    s.tl(true, 'o', 'action taken');
    s.events = s.linkTrackEvents = s.linkTrackVars = null;
  };

  tp.analytics.events['see_more_actions_click'] = function () {
    var tracked = [
      'eVar50', 'prop50',
      'eVar51', 'prop51',
      'eVar52', 'prop52',
      'prop66',
      'prop67',
      'events'
    ];
    s.linkTrackVars = tracked.join(',');
    s.events = s.linkTrackEvents = 'event52';
    s.eVar50 = s.prop50 = s.pageName;
    s.eVar51 = s.prop51 = '' + window.location;
    s.eVar52 = s.prop52 = window.location.hostname;
    s.prop66 = 'See More Actions Click';
    s.prop67 = 'See More Actions Click';
    s.tl(true, 'o', 'see more actions click');
  };

  tp.analytics.events['newsletter_action_opt_in'] = function (args) {
    s.linkTrackVars = 'eVar23,eVar25,eVar30,eVar39,eVar53,prop53,events';
    s.events = s.linkTrackEvents = 'event39';
    s.eVar23 = args.group;
    s.eVar25 = args.title;
    s.eVar30 = args.view_mode === 'full' ? args.page_name : s.pageName;
    s.eVar38 = args.type_short_name;
    s.eVar39 = view_modes[args.view_mode];
    s.eVar53 = s.prop53 = args.action_name;
    s.tl(true, 'o', 'newsletter signup');
  };

  tp.analytics.events['action_share'] = function (args) {
    var tracked = [
      'eVar4', 'prop4,',
      'eVar27', 'prop26', // the mismatch is intentional
      'eVar30',
      'eVar39', 'prop39',
      'eVar53', 'prop53',
      'eVar55', 'prop55',
      'eVar56', 'prop56',
      'eVar60', 'prop60',
      'prop66',
      'prop67',
      'events'
    ];
    s.linkTrackVars = tracked.join(',');
    s.events = s.linkTrackEvents = 'event60';
    s.eVar4 = s.prop4 = args.type_name;
    s.eVar27 = s.prop26 = args.share_method;
    s.eVar30 = s.pageName;
    s.eVar39 = s.prop39 = view_modes[args.view_mode];
    s.eVar53 = s.prop53 = args.action_name;
    s.eVar55 = s.prop55 = args.action_type;
    s.eVar56 = s.prop56 = args.topic;
    s.eVar60 = s.prop60 = args.empowered_by;
    s.prop66 = 'Share';
    s.prop67 = 'Share';
    s.tl(true, 'o', 'action thank you share');
  };

  var takeactionShareListener = function (evt) {
    var share_method = 'Unknown';
    var services = {
      'email': 'Email',
      'facebook': 'Facebook',
      'twitter': 'Twitter',
      'linkedin': 'LinkedIn',
      'pinterest': 'Pinterest',
      'stumbleupon': 'StumbleUpon',
      'digg': 'Digg',
      'google_plusone': 'Google +1'
    };
    if (evt.data.service in services) {
      share_method = services[evt.data.service];
    }
    var toolbox = $(evt.data.element).closest('.addthis_toolbox');
    var nid = toolbox.attr('nid');
    if (typeof nid != 'undefined') {
      var name = 'action_share-' + nid;
      $('body').analyticstracking('fireShareInstance', name, share_method);
    }
  };

  $(document).ready(function () {
    // Setup the share event listener.
    if (window.addthis) {
      // Add a share listener to all share bar fields.
      if ($('.share-bar-field').length !== 0) {
        $('body').once('addthis-init', function () {
          window.addthis.addEventListener('addthis.menu.share',
            takeactionShareListener);
        });
      }
    }
  });

})(jQuery);

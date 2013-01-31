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

  tp.analytics.events['petition_action_view'] = function (args) {
    s.linkTrackVars = 'eVar25,eVar30,eVar39,events';
    s.events = s.linkTrackEvents = 'event26';
    s.eVar25 = args.title;
    s.eVar30 = s.pageName;
    s.eVar39 = view_modes[args.view_mode];
    s.tl(true, 'o', 'petition view');
  };

  tp.analytics.events['pledge_action_view'] = function (args) {
    s.linkTrackVars = 'eVar30,eVar32,eVar39,events';
    s.events = s.linkTrackEvents = 'event31';
    s.eVar30 = s.pageName;
    s.eVar32 = args.title;
    s.eVar39 = view_modes[args.view_mode];
    s.tl(true, 'o', 'pledge view');
  };

  tp.analytics.events['petition_action_submit'] = function (args) {
    s.linkTrackVars = 'eVar25,eVar30,eVar39,events';
    s.events = s.linkTrackEvents = 'event27';
    s.eVar25 = args.title;
    s.eVar30 = args.view_mode === 'full' ? args.page_name : s.pageName;
    s.eVar39 = view_modes[args.view_mode];
    s.tl(true, 'o', 'petition submit');
  };

  tp.analytics.events['pledge_action_submit'] = function (args) {
    s.linkTrackVars = 'eVar30,eVar32,eVar39,events';
    s.events = s.linkTrackEvents = 'event32';
    s.eVar30 = args.view_mode === 'full' ? args.page_name : s.pageName;
    s.eVar32 = args.title;
    s.eVar39 = view_modes[args.view_mode];
    s.tl(true, 'o', 'pledge submit');
  };

  tp.analytics.events['petition_action_opt_in'] = function (args) {
    s.linkTrackVars = 'eVar23,eVar25,eVar30,eVar39,events';
    s.events = s.linkTrackEvents = 'event39';
    s.eVar23 = args.group;
    s.eVar25 = args.title;
    s.eVar30 = args.view_mode === 'full' ? args.page_name : s.pageName;
    s.eVar38 = 'Petition';
    s.eVar39 = view_modes[args.view_mode];
    s.tl(true, 'o', 'newsletter signup');
  };

  tp.analytics.events['pledge_action_opt_in'] = function (args) {
    s.linkTrackVars = 'eVar23,eVar30,eVar32,eVar39,events';
    s.events = s.linkTrackEvents = 'event39';
    s.eVar23 = args.group;
    s.eVar30 = args.view_mode === 'full' ? args.page_name : s.pageName;
    s.eVar32 = args.title;
    s.eVar38 = 'Pledge';
    s.eVar39 = view_modes[args.view_mode];
    s.tl(true, 'o', 'newsletter signup');
  };

  tp.analytics.events['action_share'] = function (args) {
    var tracked = [
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
    s.eVar27 = s.prop26 = args.share_method;
    s.eVar30 = s.pageName;
    s.eVar39 = s.prop39 = view_modes[args.view_mode];
    s.eVar53 = s.prop53 = args.title;
    s.eVar55 = s.prop55 = args.action_type;
    s.eVar56 = s.prop56 = args.topic;
    s.eVar60 = s.prop60 = args.empowered_by;
    s.prop66 = 'Share';
    s.prop67 = 'Share';
    s.tl(true, 'o', 'action thank you share');
  };

})(jQuery);

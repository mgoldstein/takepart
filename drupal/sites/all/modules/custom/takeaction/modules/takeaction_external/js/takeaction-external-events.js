// Add analytics to the TakePart JavaScript name space
if (typeof tp == 'undefined' || !tp) {
    var tp = {};
}
if (!tp.analytics) {
    tp.analytics = {
        'events': {}
    };
}

(function ($) {

    $(document).ready(function () {
        $('.external-action-link').click(function (event) {
            event.preventDefault();

            $('body').analyticstracking('fireInstance',
                'external_action_click-' + $(this).attr('nid'));

            $('body').analyticstracking('fireInstance',
                'action_taken-' + $(this).attr('nid'));

            var action_href = $(this).attr('action-href');
            if (typeof action_href == 'undefined') {
                $('span', this).text('Action Taken');
            }
            else {
                if ($(this).attr('target') == '_blank') {
                    window.open(action_href);
                }
                else {
                    window.location = action_href;
                }
            }
        });
    });

    tp.analytics.events['external_action_click'] = function (args) {
        var view_modes = {
            'full': 'Full Page',
            'embed': 'Embedded'
        }
        if (view_modes[args.view_mode] == 'Full Page') {
            s.linkTrackVars = 'eVar25,eVar30,eVar39,events';
            s.events = s.linkTrackEvents = 'event34';
            s.eVar25 = args.title;
            s.eVar30 = s.pageName;
            s.eVar39 = view_modes[args.view_mode];
            s.tl(true, 'o', 'external action click');
        }
    };

})(jQuery);

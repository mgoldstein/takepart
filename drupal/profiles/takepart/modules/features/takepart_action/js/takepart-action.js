(function ($) {
    // handle the click funciton on the take action button.
    Drupal.behaviors.TPactionClick = {
        attach: function (context, settings) {
            $('.node-action .field-name-field-action-url a, .take_action_button', context).click(
                function(e) {
                    //if it is marked as local we are just recording the hit
                    var href = $(this).attr('href');
                    var suffix = '/local';
                    var test = href.indexOf(suffix, href.length - suffix.length) !== -1;
                    if (test) {
                        e.preventDefault();
                    } else {
                        if ($(this).attr('target') == '_blank') {
                            window.open(jQuery(this).attr('href'), '_blank');
                        } else {
                            window.location = jQuery(this).attr('href');
                        }
                    }
                    s.linkTrackVars="eVar28,eVar30,events";
                    s.linkTrackEvents="event37, event19";
                    s.eVar28='tpaction';
                    s.eVar30='takepart:actions:' + $('h1.title').text();
                    s.events='event37, event19';
                    s.tl(this.href, 'o', 'Take Action Button Click');
                    $(this).addClass('action-taken');
                    $(this).children(":first").text('Action Taken');
                }
                );
        }
    };
}(jQuery));

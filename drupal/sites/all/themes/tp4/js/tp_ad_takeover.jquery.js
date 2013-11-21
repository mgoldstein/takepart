(function (window, $, undefined) {

window.tp_ad_takeover = function(bgcolor, bgimage, link) {
        var $body = jQuery('body');
        var $a = jQuery('<a id="tp_ad_takeover" href="' + link + '" target="_blank"></a>');

        $body
                .css({
                        background: bgcolor + ' url("' + bgimage + '") center top no-repeat',
                        backgroundAttachment: 'fixed'
                })
                .addClass('tp_ad_takeover');

        $a
                .css({
                        position: 'fixed',
                        height: '100%',
                        width: '100%',
                        left: 0,
                        top: 0,
                        zIndex: 0
                });

        jQuery('body #page-wrap').append($a);
};

})(window, jQuery);
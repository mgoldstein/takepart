(function(window, $, undefined) {

    var regions = {};
    // Only place it on internal urls
    // var relative_test = new RegExp("//" + location.host + "($|/)");

    $.tpregions = {
        add: function(name, selector) {
            if ( typeof name == 'object' ) {
                for ( var key in name ) {
                    if ( name.hasOwnProperty(key) ) {
                        $.tpregions.add(key, name[key]);
                    }
                }
            } else {
                regions[name] = selector;
            }
        }
    };

    // Onload
    $(function() {

        // Add omniture region on mouseover/focus
        $('body').delegate('a:not(.tplinkpos)', 'focus mouseover', function() {
            var a = this;
            var $a = $(this);
            $a.addClass('tplinkpos');
            // var is_local = (a.href.substring(0,4) === "http") ? relative_test.test(a.href) : true;
            // if ( !is_local ) return;

            for ( var pos in regions ) {
                var sel = regions[pos];
                if ( $a.is(sel + ' a') ) {
                    a.name += '&lpos=' + pos;
                }
            }
        });
        $('body').delegate('iframe#twitter-widget-0:not(.tplinkpos)', 'focus mouseover', function() {
            var a = this;
            var $a = $(this);
            $a.addClass('tplinkpos');
            // var is_local = (a.href.substring(0,4) === "http") ? relative_test.test(a.href) : true;
            // if ( !is_local ) return;

            for ( var pos in regions ) {
                var sel = regions[pos];
                if ( $a.is(sel + ' a') ) {
                    a.name += '&lpos=' + pos;
                }
            }
        });
        $('body').delegate('.fb_iframe_widget iframe:not(.tplinkpos)', 'focus mouseover', function() {
            var a = this;
            var $a = $(this);
            $a.addClass('tplinkpos');
            // var is_local = (a.href.substring(0,4) === "http") ? relative_test.test(a.href) : true;
            // if ( !is_local ) return;

            for ( var pos in regions ) {
                var sel = regions[pos];
                if ( $a.is(sel + ' a') ) {
                    a.name += '&lpos=' + pos;
                }
            }
        });
    });
})(window, jQuery);
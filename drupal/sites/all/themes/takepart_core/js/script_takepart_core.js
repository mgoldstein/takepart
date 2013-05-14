(function (window, $, undefined) {
// Query string manipulation
// jacked from http://stackoverflow.com/questions/5999118/add-or-update-query-string-parameter
function UpdateQueryString(key, value, url) {
    if (!url) url = window.location.href;
    var re = new RegExp("([?|&])" + key + "=.*?(&|#|$)(.*)", "gi");

    if (re.test(url)) {
        if (typeof value !== 'undefined' && value !== null)
            return url.replace(re, '$1' + key + "=" + value + '$2$3');
        else {
            return url.replace(re, '$1$3').replace(/(&|\?)$/, '');
        }
    }
    else {
        if (typeof value !== 'undefined' && value !== null) {
            var separator = url.indexOf('?') !== -1 ? '&' : '?',
                hash = url.split('#');
            url = hash[0] + separator + key + '=' + value;
            if (hash[1]) url += '#' + hash[1];
            return url;
        }
        else
            return url;
    }
}

// Document Ready
$(function() {
	// Omniture position tracking
	// Parent/ancestor vars to track in reverse order of importance
	var positions = {
		'Header': '#site-header',
		'Footer': '#site-footer',
		'Daily Featured Content': '.of_the_day_section',
		'Partner Link': '.on_our_radar_section',
		'Embedded Content': '#article-body .drupal-embed',
		'Related Stories': '#article-related',
		'Next Article': '#next-article',
		'Keyword Link': '#article-tags'
	};

	// Only place it on internal urls
	var relative_test = new RegExp("//" + location.host + "($|/)");

	for ( var pos in positions ) {
		var sel = positions[pos];

		var $as = $(sel + ' a');

		for ( var i = 0; i < $as.length; i++ ) {
			var a = $as[i];
			var is_local = (a.href.substring(0,4) === "http") ? relative_test.test(a.href) : true;

			if ( is_local  ) {
				var url = UpdateQueryString('lpos', 'pos', a.href);
				a.href = url;
			}
		}
	}
});

})(window, jQuery);
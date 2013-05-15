(function (window, $, undefined) {

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
				a.name = '&lpos=' + pos;
			}
		}
	}
});

})(window, jQuery);
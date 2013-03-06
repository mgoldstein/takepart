(function(window, $, undefined) {

// Setup

// Document load
$(function() {
	$('body')
		.delegate('.tpsocial-facebook a, a.tpsocial-facebook', 'click', function(e) {
			var $this = $(this);
			var href = this.href;
			if ( this.pathname == '#' ) href = window.document.location.href;
			if ( $this.data('tpsocial-href') ) href = $this.data('tpsocial-href');
			if ( $this.data('tpsocial-facebook-href') ) href = $this.data('tpsocial-facebook-href');
			$this.data('tpsocial-facebook-href', href);
			this.href = 'http://www.facebook.com/sharer/sharer.php?u=' + encodeURIComponent(href);
			this.target = '_blank';
			takepart.analytics.track('generic_tpsocial', 'facebook');
		});
});

})(window, jQuery);
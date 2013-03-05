(function(window, $, undefined) {

// Setup

// Document load
$(function() {
	$('body')
		.delegate('.tpsocial-facebook a, a.tpsocial-facebook', 'click', function(e) {
			var $this = $(this);
			var href this.href;
			if ( href = '#' ) href = window.document.location.href;
			if ( $this.data('tpsocial-href') ) href = $this.data('tpsocial-href');
			if ( $this.data('tpsocial-facebook-href') ) href = $this.data('tpsocial-facebook-href');
			this.href = href;
			this.target = '_blank';
		});
});

})(window, jQuery);
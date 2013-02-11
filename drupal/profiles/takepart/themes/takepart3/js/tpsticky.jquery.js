(function(window, $, undefined) {

var $window = $(window);

$.fn.tpsticky = function(parameters) {
	var settings = $.extend({
		prepend: 'tpsticky_',
		offsetNode: undefined
	}, parameters);

	return this.each(function() {
		var $this = $(this);
		var $offset = settings.offsetNode || $this.parent();
		$offset = $($offset);

		$this.width($this.width());

		var left = $this.offset().left;

		var check_scroll = function() {
			if ( $window.scrollTop() + $this.outerHeight() > $offset.offset().top + $offset.height() ) {
				$this
					.removeClass('above').removeClass('inside').addClass('below')
					.css({
						position: 'static',
						marginTop: $offset.height() - $this.outerHeight()
					})
					;
			} else if ( $window.scrollTop() > $offset.offset().top ) {
				$this
					.removeClass('above').removeClass('below').addClass('inside')
					.css({
						position: 'fixed',
						left: left,
						top: 0,
						marginTop: 0
					})
					;
				//$this.css({marginTop: $window.scrollTop() - $offset.offset().top, left: left});
			} else {
				$this
					.removeClass('below').removeClass('inside').addClass('above')
					.css({
						position: 'static',
						marginTop: 0
					})
					;
				//$this.css({marginTop: 0});
			}
		};

		$window
			.bind('scroll', check_scroll)
			.bind('resize', function() {
				$this
					.removeClass('below').removeClass('inside').removeClass('above')
					.css({
						position: 'static',
						marginTop: 0,
						width: ''
					})
					.width($this.width())
					;
				left = $this.offset().left;
				check_scroll();
			})
			;

		check_scroll();
	});
};

})(window, jQuery);
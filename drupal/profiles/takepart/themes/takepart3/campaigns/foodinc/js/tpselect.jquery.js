(function(window, $, undefined) {

var has_placeholder = ("placeholder" in document.createElement("input"));

$.fn.tpselect = function(options) {
	var settings = $.extend({
		prepend: 'tpselect_'
	}, options || {});

	var $elems = this.filter('select');

	$elems.each(function() {
		var $this = $(this);

		if ( $this.is('.' + settings.prepend + '_ed') || this.type != 'select-one' ) {
			return;
		} else {
			$this.addClass(settings.prepend + '_ed');
		}

		var $wrapper = $('<span/>');
		var $value = $('<span/>');
		var $input = $this;
		var element = this;
		var prepend = settings.prepend;

		$value
			.addClass(prepend + 'value');

		$wrapper
			.addClass(prepend + 'input')
			.addClass(prepend + 'select')
			.addClass(prepend + 'wrapper')
			.css({
				position: 'relative'
			});

		var val = element.options[element.selectedIndex].innerHTML;
		if ( val == '' ) val = '&nbsp;';

		$wrapper.insertAfter($input);

		$value.html(val);
		$wrapper.append($value);
		$wrapper.append($input);

		var input_outer_width = $input.outerWidth();
		var input_inner_width = $input.width();
		var wrapper_inner_width = $wrapper.innerWidth();

		$input
			.css({
				opacity: 0,
				position: 'absolute',
				left: 0,
				bottom: 0
			})
			.bind('change keyup', function() {
				var option = this.options[this.selectedIndex];
				$value.html(option.innerHTML);
			})
			.bind('focus', function() {
				$wrapper.addClass(prepend + 'focus');
			})
			.bind('blur', function() {
				$wrapper.removeClass(prepend + 'focus');
			});

		var input_outer_height = $input.outerHeight();
		var input_inner_height = $input.height();
		var wrapper_inner_height = $wrapper.innerHeight();
	});

	return this;
};

})(window, jQuery);


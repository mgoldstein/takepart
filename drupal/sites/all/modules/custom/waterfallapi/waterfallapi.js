(function(window, $, undefined) {
// Setup

// Auto tab plugin
// TODO try to automagically sniff the next input
$.fn.autoTab = function(params) {
    var defaults = {
        maxlength: null,
        mask: /^[0-9]+$/,
        next: 'input'
    };
    var options = $.extend({}, defaults, params);
    var maxlength = options.maxlength;
    var mask = options.mask;
    var next = options.next;

    this.each(function() {
        var $this = $(this);
        var limit = ( maxlength == null ) ? $this.attr('maxlength') : maxlength;
        
        $this
            .bind('keypress', function(e) {
			    /**
			     * Do not auto tab when the following keys are pressed
			     * 8:    Backspace
			     * 9:    Tab
			     * 16:    Shift
			     * 17:    Ctrl
			     * 18:    Alt
			     * 19:    Pause Break
			     * 20:    Caps Lock
			     * 27:    Esc
			     * 33:    Page Up
			     * 34:    Page Down
			     * 35:    End
			     * 36:    Home
			     * 37:    Left Arrow
			     * 38:    Up Arrow
			     * 39:    Right Arrow
			     * 40:    Down Arrow
			     * 45:    Insert
			     * 46:    Delete
			     * 144:    Num Lock
			     * 145:    Scroll Lock
			     */
                var keys = [8, 9, 16, 17, 18, 19, 20, 27, 33, 34, 35, 36, 37, 38, 39, 40, 45, 46, 144, 145];
                if ( $.inArray(e.which, keys) != -1 ) return true;
                var s = String.fromCharCode(e.which);
                if ( !mask.exec(s) ) return false;
                var val = $(this).val();
                if ( val.length >= limit ) {
                    $this.val(val.substring(0, limit));
                    console.log(1);
                    $(next).focus();
                    return false;
                }

                if ( val.length >= limit - 1 ) {
					setTimeout(function(){$(next).focus();},0);
                }
            })
            ;
    });
};

// Document Ready
$(function() {
	// TODO this should probably be in the Drupal behaviors thing
    $('#edit-areacode').autoTab({next: '#edit-phone1'});
    $('#edit-phone1').autoTab({next: '#edit-phone2'});
    $('#edit-phone2').autoTab({next: '#edit-zipcode'});
    $('#edit-zipcode').autoTab({next: '#edit-submit'});
});
})(window, jQuery);
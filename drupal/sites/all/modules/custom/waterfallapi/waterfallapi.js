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

                if ( $.inArray(e.keyCode, keys) != -1 ) return true;
                var s = String.fromCharCode(e.charCode);
                if ( !mask.exec(s) ) {
                    e.preventDefault();
                    return true;
                }
                var val = $(this).val();
                var input = this;

                if ( val.length >= limit ) {
                    $this.val(val.substring(0, limit));
                    setTimeout(function(){
                        val = $(input).val();
                        if ( val.length >= limit ) {
                            $(input).val(val.substring(0,limit));
                            $(next).focus();
                        }
                    }, 0);
                }

                if ( val.length >= limit - 1 ) {
					setTimeout(function(){
                        val = $(input).val();
                        if ( val.length >= limit ) {
                            $(input).val(val.substring(0,limit));
                            $(next).focus();
                        }
                    }, 0);
                }
            })
            ;
    });
};

Drupal.behaviors.waterfall_autoTab = {
    attach: function (context, settings) {
        $('#waterfallapi-form').once('autoTab', function () {
            $('.form-item-areacode input').autoTab({next: '.form-item-phone1 input'});
            $('.form-item-phone1 input').autoTab({next: '.form-item-phone2 input'});
            $('.form-item-phone2 input').autoTab({next: '.form-item-zipcode input'});
            $('.form-item-zipcode input').autoTab({next: '#block-waterfallapi-waterfallsubscription .form-submit'});
        });
    }
}

// Document Ready
// $(function() {

// });
})(window, jQuery);
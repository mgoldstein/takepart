/* 
	Auto tab to next input.

	Usage:
    $('body')
        .delegate('#edit-mobile input', 'keypress', function(e) {
            $.tpautoTab(e, this, {
                mask: /^[0-9]+$/
            })
        })

	Params:
		e: event object. Required
		el: element. Required
		params: object with optional params
			mask: regex for allowed characters
			maxlength: maximum length for input

	TODO:
		Make it more like a plugin, or have more of a plugin interface like $('#edit-mobile input').tpautoTab().
		Maybe clean up the params.
*/

(function(window, $, undefined) {
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

var next = function($this) {
	var el = $this[0];
	var $inputs = $this.closest('form').find('input:not([type="hidden"]), select, textarea');
	var found = false;
	var fel = null;

	for ( var i=0, eli; (eli = $inputs[i]); i++ ) {
		if ( found == true ) {
			fel = eli;
			break;
		} else if ( eli == el ) {
			found = true;
		}
	}

	if ( fel ) {
        $(fel).focus();
	}
};

var defaults = {
    maxlength: null,
    mask: /^.+$/
};

$.tpautoTab = function(e, el, parameters) {
    var options = $.extend({}, defaults, parameters);
    var maxlength = options.maxlength;
    var mask = options.mask;

    if ( $.inArray(e.keyCode, keys) != -1 ) return true;
    var s = String.fromCharCode(e.charCode);
    if ( !mask.exec(s) ) {
        e.preventDefault();
        return true;
    }

    var $this = $(el);
    var val = $this.val();
    var nmaxlength = $this.attr('maxlength');
    var limit = maxlength || nmaxlength;

    if ( val.length >= limit ) {
        if ( limit != nmaxlength ) $this.val(val.substring(0, limit));
        setTimeout(function(){
            val = $this.val();
            if ( val.length >= limit ) {
                $this.val(val.substring(0,limit));
                next($this);
            }
        }, 0);
    }

    if ( val.length >= limit - 1 ) {
		setTimeout(function(){
			val = $this.val();
            if ( val.length >= limit ) {
                $this.val(val.substring(0,limit));
                next($this);
            }
        }, 0);
    }
};

})(window, jQuery);
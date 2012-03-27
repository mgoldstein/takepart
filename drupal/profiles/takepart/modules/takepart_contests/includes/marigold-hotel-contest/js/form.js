if (typeof marigold_hotel_contest == "undefined" || !marigold_hotel_contest) {
    var marigold_hotel_contest = {};
}

marigold_hotel_contest.forms = {
    remaining_chars: function (elem) {
        if (elem) {
            jQuery(elem).each(function () {
                var max = jQuery(this).attr('maxlength');
                var val = jQuery(this).attr('value');
                var cur = 0;
                if (val) cur = val.length;
                var left = max - cur;
                jQuery(this).after("<div class='counter'>" + left.toString() + "</div>");
                var c = jQuery(this).next(".counter");
                jQuery(elem).keyup(function (i) {
                    var max = jQuery(elem).attr('maxlength');
                    var val = jQuery(elem).attr('value');
                    var cur = 0;
                    if (val) cur = val.length;
                    var left = max - cur;
                    jQuery(elem).next(".counter").text(left.toString());
                });
            });
        }
    },
    checkboxes: function (elem) {            
        if (elem) {
        	jQuery(elem).checkBox();
        }
    },
    selectboxes: function (elem) {            
        if (elem) {
        	jQuery(elem).selectbox();
        }
    },
    selectboxes_alt: function (elem) {            
        if (elem) {
        	jQuery(elem).takepartStyle();
        }
    },
    textfield_edit: function (elem) {            
        if (elem) {
            jQuery(elem).each(function () {
            	if(elem.is("textarea")) {
            		text = elem.val();
            	}      	
                jQuery(this).parent().parent().after("<div class='textarea_edit'>Edit</div>");
                jQuery(this).after("<div class='textarea_dispal'>" + text + "</div>");
            });
            jQuery('.textarea_edit').click(function() {
            	alert('test');
            });
        }
    },
    onformrender: function () {
        marigold_hotel_contest.forms.remaining_chars(jQuery("#takepart_contests_form_wrapper_1 #edit-field-custom-265 textarea"));
        marigold_hotel_contest.forms.remaining_chars(jQuery("#takepart_contests_form_wrapper_1 #edit-field-custom-266 textarea"));
        marigold_hotel_contest.forms.remaining_chars(jQuery("#takepart_contests_form_wrapper_1 #edit-field-custom-267 textarea"));
        marigold_hotel_contest.forms.remaining_chars(jQuery("#takepart_contests_form_wrapper_1 #edit-field-custom-270 textarea"));
        marigold_hotel_contest.forms.remaining_chars(jQuery("#takepart_contests_form_wrapper_1 #edit-field-custom-271 textarea"));

        marigold_hotel_contest.forms.checkboxes(jQuery("#takepart_contests_form_wrapper_1 .form-type-checkbox input"));
        //marigold_hotel_contest.forms.selectboxes(jQuery("#takepart_contests_form_wrapper_1 form .form-type-select select"));
        marigold_hotel_contest.forms.selectboxes_alt(jQuery("#takepart_contests_form_wrapper_1 .form-type-select select"));
        if(jQuery('#takepart_contests_form_wrapper_1 .group-step1 legend').length != 0) {
        	jQuery('.field-type-text-with-summary').show();
        } else {
        	jQuery('.field-type-text-with-summary').hide();
        }
        
        if(jQuery('#takepart_contests_form_wrapper_1 #step4legend').length != 0) {
            marigold_hotel_contest.forms.textfield_edit(jQuery("#takepart_contests_form_wrapper_1 textarea"));
        }
        
    }
}

jQuery(document).ajaxComplete(function(e, xhr, settings) {
	marigold_hotel_contest.forms.onformrender();
});


jQuery(document).ready(function () {	
	marigold_hotel_contest.forms.onformrender();
});
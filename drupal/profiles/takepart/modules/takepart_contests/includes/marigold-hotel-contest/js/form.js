if (typeof marigold_hotel_contest == "undefined" || !marigold_hotel_contest) {
    var marigold_hotel_contest = {};
}

marigold_hotel_contest.forms = {
    remaining_chars: function (elem, attach) {
        if (elem) {
            jQuery(elem).each(function () {
                var max = jQuery(this).attr('maxlength');
                var val = jQuery(this).attr('value');
                var cur = 0;
                if (val) cur = val.length;
                var left = max - cur;
                if (attach) {
                    jQuery(this).after("<div class='counter'>&nbsp;" + left.toString() + "</div>");
                }
                jQuery(elem).keyup(function (i) {
                    var max = jQuery(elem).attr('maxlength');
                    var val = jQuery(elem).attr('value');
                    var cur = 0;
                    if (val) cur = val.length;
                    var left = max - cur;
                    //jQuery(elem).next(".counter").text(left.toString());
                    jQuery(elem).parent().children(".counter").text(' ' + (left.toString()));
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
                if (jQuery(this).is("textarea")) {
                    text = jQuery(this).val();
                    jQuery(this).toggle();
                    jQuery(this).parent().parent().after("<div class='textarea_edit' id='" + jQuery(this).attr('id') + "_editlink'>Edit</div>");
                    jQuery(this).after("<div class='textarea_display' id='" + jQuery(this).attr('id') + "_editdisplay'>" + text + "</div>");
                    jQuery(this).parent().children(".counter").toggle();
                }
            });
            jQuery('.textarea_edit').click(function () {
                textareaid = jQuery(this).attr('id').replace("_editlink", "");
                jQuery("#" + textareaid).toggle();
                jQuery("#" + textareaid + '_editdisplay').toggle();
                jQuery("#" + textareaid + '_editdisplay').html(jQuery("#" + textareaid).val().replace(/\n/g, '<br />\n'));
                jQuery("#" + textareaid).parent().children(".counter").toggle();
                //marigold_hotel_contest.forms.attachremainingchar(false);
            });
        }
    },
    onformrender: function () {

        marigold_hotel_contest.forms.attachremainingchar(true);

        marigold_hotel_contest.forms.checkboxes(jQuery("#takepart_contests_form_wrapper_1 .form-type-checkbox input"));
        //marigold_hotel_contest.forms.selectboxes(jQuery("#takepart_contests_form_wrapper_1 form .form-type-select select"));
        marigold_hotel_contest.forms.selectboxes_alt(jQuery("#takepart_contests_form_wrapper_1 .form-type-select select"));
        if (jQuery('#takepart_contests_form_wrapper_1 .group-step1 legend').length != 0) {
            jQuery('.field-type-text-with-summary').show();
        } else {
            jQuery('.field-type-text-with-summary').hide();
        }

        if (jQuery('#takepart_contests_form_wrapper_1 #step4legend').length != 0) {
            marigold_hotel_contest.forms.textfield_edit(jQuery("#takepart_contests_form_wrapper_1 textarea"));
        }

        jQuery.preloadCssImages();

    },
    attachremainingchar: function (rebuild) {

        marigold_hotel_contest.forms.remaining_chars(jQuery("#takepart_contests_form_wrapper_1 #edit-field-custom-265 textarea"), rebuild);
        marigold_hotel_contest.forms.remaining_chars(jQuery("#takepart_contests_form_wrapper_1 #edit-field-custom-266 textarea"), rebuild);
        marigold_hotel_contest.forms.remaining_chars(jQuery("#takepart_contests_form_wrapper_1 #edit-field-custom-267 textarea"), rebuild);
        marigold_hotel_contest.forms.remaining_chars(jQuery("#takepart_contests_form_wrapper_1 #edit-field-custom-270 textarea"), rebuild);
        marigold_hotel_contest.forms.remaining_chars(jQuery("#takepart_contests_form_wrapper_1 #edit-field-custom-271 textarea"), rebuild);

    },
    track: function () {
        var marigolduser = marigold_hotel_contest.forms.getMGCookie("marigolduser");
        if (marigolduser == null || marigolduser == "") {
            //alert(Math.round(+new Date()/1000).toString());
            s.eVar28 = 'Contest Begin';
            s.eVar24 = 'Best Exotic Marigold Hotel';
            s.prop24 = 'Best Exotic Marigold Hotel';
            s.events = 'event19';
            marigold_hotel_contest.forms.setMGCookie("marigolduser", Math.round(+new Date() / 1000).toString(), 0);
        }
    },
    getMGCookie: function (c_name) {
        var i, x, y, ARRcookies = document.cookie.split(";");
        for (i = 0; i < ARRcookies.length; i++) {
            x = ARRcookies[i].substr(0, ARRcookies[i].indexOf("="));
            y = ARRcookies[i].substr(ARRcookies[i].indexOf("=") + 1);
            x = x.replace(/^\s+|\s+$/g, "");
            if (x == c_name) {
                return unescape(y);
            }
        }
    },
    setMGCookie: function (c_name, value, exdays) {
        if (exdays > 0) {
            var exdate = new Date();
            exdate.setDate(exdate.getDate() + exdays);
            var c_value = escape(value) + ((exdays == null) ? "" : "; expires=" + exdate.toUTCString());
        } else {
            var c_value = escape(value) + ((exdays == null) ? "" : "; expires=0");
        }
        document.cookie = c_name + "=" + c_value;
    }
}


jQuery(document).ajaxComplete(function (e, xhr, settings) {
    marigold_hotel_contest.forms.onformrender();
});


jQuery(document).ready(function () {
    marigold_hotel_contest.forms.onformrender();
    marigold_hotel_contest.forms.track();
});
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
    onformrender: function () {
        marigold_hotel_contest.forms.remaining_chars(jQuery("#marigold-hotel-contest-form-wrapper form textarea#edit-step1-custom-265"));
        marigold_hotel_contest.forms.remaining_chars(jQuery("#marigold-hotel-contest-form-wrapper form textarea#edit-step1-custom-266"));
        marigold_hotel_contest.forms.remaining_chars(jQuery("#marigold-hotel-contest-form-wrapper form textarea#edit-step1-custom-267"));
        marigold_hotel_contest.forms.remaining_chars(jQuery("#marigold-hotel-contest-form-wrapper form textarea#edit-step1-custom-270"));
        marigold_hotel_contest.forms.remaining_chars(jQuery("#marigold-hotel-contest-form-wrapper form textarea#edit-step1-custom-271"));

        marigold_hotel_contest.forms.checkboxes(jQuery("#marigold-hotel-contest-form-wrapper form .form-checkboxes input"));
        //marigold_hotel_contest.forms.selectboxes(jQuery("#marigold-hotel-contest-form-wrapper form .form-type-select select"));
        marigold_hotel_contest.forms.selectboxes_alt(jQuery("#marigold-hotel-contest-form-wrapper form .form-type-select select"));
    }
}

/*
jQuery(document).ajaxComplete(function(){       
    //alert('oksdsakdsa');          
    
    for (var i = 0; i < arguments.length;  i++) {
        //alert(i + ":" + dump(arguments[i]));
    }
    
});
*/

jQuery(document).ajaxComplete(function(e, xhr, settings) {
	
	marigold_hotel_contest.forms.onformrender();
	/*
	if(settings) {
		alert('---------SETTINGS---------');
		for(x in settings) {
			alert(x + " : " + settings[x]);
		}
	}
	if(e) {
		alert('---------EVENTS---------');
		for(x in e) {
			alert(x + " : " + e[x]);
		}
	}
	if(e) {
		alert('---------XHR---------');
		for(x in xhr) {
			alert(x + " : " + xhr[x]);
		}
	}
	*/
});

/*
jQuery(function () {
	  if (!Drupal.Ajax) return;
	  Drupal.Ajax.plugins.test = function (hook, args) {
	    if (hook == 'message' && args.data.form_id == 'marigold-hotel-contest-form' && args.data.status == true) {
	      alert('valid!');
	    }
	  };
	});
*/
/*
Drupal.ajax.plugins.anypluginname = function(hook, args){
	
	alert(hook);
	
    switch (hook) {
        case 'submit': // after submit was pressed
            $('#edit-submitted--product-link').val(window.location); // I know ID of my field :)
            /*
                Anything you want here
           
        break;
    }

    return true;
}
*/

//http://stackoverflow.com/questions/8728291/how-do-i-make-a-drupal-ajax-call-manually

/*
Drupal.ajax.prototype.beforeSubmit = function (form_values, element, options) {
	//alert('test2');
	//alert("caller is 10" + arguments.callee.caller.toString());
	//jQuery('body').prepend('<br /><pre>' + "caller is 10" + arguments.callee.caller.toString() + '</pre>'); 

}
*/



jQuery(document).ready(function () {
	
	marigold_hotel_contest.forms.onformrender();
	
    //jQuery("#marigold-hotel-contest-form").bind("submit", function() { alert('ya'); })
    //jQuery('#edit-next--2').listHandlers('*', console.info);
    //jQuery('#edit-next').listHandlers('*', function (element, data) {
    //    jQuery('body').prepend('<br />Event: ' + element.nodeName + ': <br /><pre>' + dump(data) + '<\/pre>');
    //});
    //jQuery('#marigold-hotel-contest-form').listHandlers('*', console.info);
	//jQuery('body').prepend('<br /><pre>' + (dump(jQuery('form#marigold-hotel-contest-form').submit)) + '</pre>'); 

	//jQuery('body').prepend('<br /><pre>' + (dump(jQuery('form#marigold-hotel-contest-form #edit-next').data("events"))) + '</pre>'); 
	
	//jQuery('body').prepend('<br /><pre>' + (dump(Drupal.ajax.prototype.beforeSubmit)) + '</pre>'); 
	
		
});






function dump(arr, level) {
    var dumped_text = "";
    if (!level) level = 0;

    //The padding given at the beginning of the line.
    var level_padding = "";
    for (var j = 0; j < level + 1; j++) level_padding += "    ";

    if (typeof (arr) == 'object') { //Array/Hashes/Objects
        for (var item in arr) {
            var value = arr[item];

            if (typeof (value) == 'object') { //If it is an array,
                dumped_text += level_padding + "'" + item + "' ...\n";
                dumped_text += dump(value, level + 1);
            } else {
                dumped_text += level_padding + "'" + item + "' => \"" + value + "\"\n";
            }
        }
    } else { //Stings/Chars/Numbers etc.
        dumped_text = "===>" + arr + "<===(" + typeof (arr) + ")";
    }
    return dumped_text;
}

jQuery.fn.listHandlers = function (events, outputFunction) {
    return this.each(function (i) {
        var elem = this,
            dEvents = jQuery(this).data('events');
        if (!dEvents) {
            return;
        }
        jQuery.each(dEvents, function (name, handler) {
            if ((new RegExp('^(' + (events === '*' ? '.+' : events.replace(',', '|').replace(/^on/i, '')) + ')$', 'i')).test(name)) {
                jQuery.each(handler, function (i, handler) {
                    outputFunction(elem, '\n' + i + ': [' + name + '] : ' + handler);
                });
            }
        });
    });
};

/*
(function ($) {
	Drupal.behaviors.marigold-hotel-contest-form = {
	  attach: function (context) {
	    $('#edit-next', context).click(function(){
	      alert('test');
	    });
	  }
	};
})(jQuery);


/*
Drupal.behaviors.ajaxComment = function (context) {
	//Drupal.settings.ajaxComment is the javascript version of the contents of $settings['ajaxComment'] in our implementation of hook_form_alter
	Drupal.ajaxComment = new Drupal.ajaxComment($('#comment-form'), Drupal.settings.ajaxComment);
}

/*
Drupal.ajax.plugins.takepart_contests = function (hook, args) {
    alert(hook)
    if (hook === 'message') {
        //alert(args.data.options.some_data);
    }
}
*/
/*
jQuery(document).ready(function () {
	jQuery("marigold-hotel-contest-form").bind("submit", function() { alert('ya'); })
});



Drupal.behaviors.AJAX

for(i in Drupal.behaviors.formUpdated ) { alert(i); }

(function ($) {
	
	for(i in Drupal.behaviors.takepart_contests) { alert(i); }
	
	
/*
	  Drupal.behaviors.takepart_contests = {
	    attach: function (context, settings) {
	      $('.example', context).click(function () {
	        $(this).next('ul').toggle('show');
	      });
	    }
	  };

	})(jQuery);

*/
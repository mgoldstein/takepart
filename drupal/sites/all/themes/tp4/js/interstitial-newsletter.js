(function (window, $, undefined) {

$(function() {

	initInput($('.form-type-textfield input'));

	Drupal.behaviors.newsletterSocialSignupSubmitted = {
        attach: function (context) {

        	if (context.is('#newsletter-campaign-email-only-signup-form')){
        		console.log(context.find('.form-type-textfield input'));
        		initInput(context.find('.form-type-textfield input'));
        	}

            if (context.is('.thank-you-message') && window.parent && window.parent.interstitial_newsletter_signup){
            	window.parent.interstitial_newsletter_signup(context.attr('data-newsletter-name'));
            }
        }
    }

	$('#dont a').bind('click', function(e) {
		e.preventDefault();
		if ( window.parent && window.parent.dont_show_interstitial ) window.parent.dont_show_interstitial();
	})
});


function initInput(input){
	checkInputCss(input);
	input.bind('blur', function(){
		checkInputCss($(this));
	});
}
function checkInputCss(input){
	var newCss = {'z-index': ''};
	if(input.val()){
		newCss['z-index'] = 3;
	}
	input.css(newCss);
}

})(window, jQuery);
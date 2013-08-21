(function (window, $, undefined) {

$(function() {
	$('.form-item-email input').bind('blur', function(){
		var newCss = {'z-index': ''};
		if($(this).val()){
			newCss['z-index'] = 3;
		}
		$(this).css(newCss);
	});

	Drupal.behaviors.newsletterSocialSignupSubmitted = {
        attach: function (context) {
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

})(window, jQuery);
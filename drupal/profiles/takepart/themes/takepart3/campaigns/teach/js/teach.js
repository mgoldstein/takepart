(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.punishInternetExplorerUsers = {
    attach: function (context) {
      var message = 'This web page is not optimized for use with Intenret Explorer 8 or earlier versions of this browser. You may experience display issues while viewing.',
	  contentSelector = ($('body').is('.page-wordlet-teach')) ? '.page-body-content' : '#page > .content';
      if ($.browser.msie && parseInt($.browser.version, 10) === 8 ) {
	$('<div />')
	  .addClass('messages error')
	  .html(message)
	  .prependTo(contentSelector)
	;
      }
    }
  };
  Drupal.behaviors.newsletterSocialSignupSubmitted = {
    attach: function (context) {
      if ($(context).is('.newsletter-signup.thank-you-message')){
	 var name = context.attr('data-newsletter-name');
	 takepart.analytics.track('newsletter_signup', {name: name});
      }
    }
  };
  Drupal.behaviors.teachAllianceLogoResize = {
    attach: function () {
      if ($('body').is('.page-wordlet-teach-alliances')) {
	var $alliance = $('.alliances').find('.alliance'),
	    resizeAlliances = function() {
	      $alliance.each(function(i, el) {
		var $el = $(el),
		    height = Math.round(($el.width() * 3) / 4);
		$el.height(height).css('line-height', (height - 20) + 'px');
	      });
	    };
	resizeAlliances();
	$(window).resize(function() {
	  resizeAlliances();
	});
      }
    }
  }
  Drupal.behaviors.campaignShare = {
    attach: function() {
      $('.campaign-social-share').on('click', 'a', function(e) {
        e.preventDefault();
        alert($(this).text() + " Share"); // TODO Implement Social Shares
      });
    }
  };
  Drupal.behaviors.teachTextLightbox = {
    attach: function() {
      var modalOptions = {
	id: 'teach_text_lightbox_'
      };

      $('body').on('click', '.teach-text-lightbox', function(e) {
	e.preventDefault();

	$.tpmodal.show(modalOptions);

	$node = $('<div />')
	  .css({maxWidth: "800px"})
	  .load($(this).attr('href') + ' .view-mode-full', function() {
	    $.tpmodal.show($.extend(modalOptions, {node: this}));
	  })
	;
      });
    }
  };
})(jQuery, Drupal, this, this.document);

(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.punishInternetExplorerUsers = {
    attach: function (context) {
      var message = '<p>The TEACH website is a richly interactive web experience and full functionality requires a <a href="http://browsehappy.com/" target="_blank">recent web browser</a>.</p>',
	  contentSelector = ($('body').is('.page-wordlet-teach')) ? '.page-body-content' : '#page > .content';
      if ($.browser.msie && parseInt($.browser.version, 10) < 10 ) {
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
      $('.campaign-social-share:not(.tp-social-skip)').each(function() {

        var $this = $(this);
        var url = $this.data('shareurl') || 'http://www.takepart.com/teach';
        var title = $this.data('sharetitle') || 'TEACH | Join the “Teacher Stories” initiative and help us support great teachers.';
	var description = $this.data('sharedescription').replace(/<[^>]+>/ig, '') || 'Share a teacher story and you’ll help us give away more than $10,000 to public schools.';

        var opts = {
          url_append: '?cmpid=organic-share-{{name}}',
          services: [
            {
                name: 'facebook',
                url: url,
                title: title,
                description: description
            },
            {
                name: 'twitter',
                url: url,
                text: description,
                via: 'TeachMovie'
            },
            {
                name: 'googleplus',
                url: url
            }
          ]
        };

        $this.tpsocial(opts);

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

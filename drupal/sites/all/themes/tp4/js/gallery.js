/**
 * @file
 * Scripts for Takepart Galleries in TP4.
 */

(function ($, Drupal, window, document, undefined) {

  //
  // Set up gallery-wide variables
  // and functions
  // 

  // social config
  var tp_social_config = {
    url_append: '?cmpid=organic-share-{{name}}',
    services: {
      facebook: {
        name: 'facebook',
        url: '{current}'
      },
      twitter: {
        name: 'twitter',
        text: '{{title}}',
        via: 'TakePart',
        url: '{current}'
      },
      googleplus: {
        name: 'googleplus',
        url: '{current}'
      },
      pinterest: {
        name: 'pinterest',
        url: '{current}'
      },
      tumblr: {
        name: 'tumblr',
        url: '{current}'
      },
      email: {
        name: 'email',
        url: '{current}'
      }
    }
  };

  // utility functionto update social share variables 
  var updateTpSocialMedia = function(imageSrc, shareDescription) {
    tp_social_config.services.pinterest.media = imageSrc;
    tp_social_config.services.tumblr.source = imageSrc;
    tp_social_config.services.pinterest.description = shareDescription;
    tp_social_config.services.tumblr.caption = shareDescription;
  };

  // prevent 2 email calls from firing
  // (Legacy TP code)
  window.takepart.analytics.skip_addthis = true;

  var isTouch = 'ontouchstart' in window || 'msmaxtouchpoints' in window.navigator;
  var isTouchmove = false;
  var click = isTouch ? "touchend" : "click";

  // establish base values for URL/token functions
  var base_url = document.location.href.split(/\/|#/).slice(0,5).join('/');
  var query = '';
  if(base_url.indexOf('?') > 0) {
      query = base_url.substring(base_url.indexOf('?'), base_url.length);
      base_url = base_url.substring(0,base_url.indexOf('?'));
  }

  // utility function to get current token
  var getCurrentToken = function() {
    var token = document.location.href.split(/\/|#/).slice(5,6) + '';
    if (token.indexOf('?') > -1) {
      token =  token.substring(0, token.indexOf('?'));
    }
    return token;
  };

  // Update html5 history if token is new,
  // with option to replace state instead of updating
  var hpush = function(token, title, replace) {

    if (typeof window.history == 'undefined') return;

    var replace = replace || false;
    var curtoken = getCurrentToken();
    if ( curtoken == token ) return;

    updatePage(token);

    if ( replace ) {
      history.replaceState(null, title, base_url + '/' + token + query);
    } else {
      history.pushState(null, title, base_url + '/' + token + query);
    }
  };

  var skipNextPageview = false;
  var updateTo = null;
  var updatePage = function(token) {
    clearTimeout(updateTo);

    // allow calls to this function to prevent
    // the analytics call from being fired
    if ( !skipNextPageview ) {
      setTimeout((function(token, skipNextPageview) {
        return function() {
          takepart.analytics.track('gallery-track-slide', {
            token: token,
            skip_pageview: skipNextPageview,
            next_gallery_headline: gallery.nextGalleryHeadline,
            next_gallery_topic: gallery.nextGalleryTopic
          });
        }
      })(token, skipNextPageview), 500);
    } else {
      skipNextPageview = false;
    }

    updateTo = setTimeout(function() {
      showFacebookComments(token);
      refreshDfpAds();
    }, 500);
  };

  // utility function to refresh ads
  var refreshDfpAds = function() {
    if(typeof googletag != 'undefined') {
      googletag.pubads().refresh();
    }
  };

  // utility funcitions to show/hide and replace facebook comments
  var $facebookComments = null;
  var facebookCommentsTemplate = null;
  var showFacebookComments = function(token) {

    $facebookComments = $facebookComments || $('#gallery-comments');

    if ( token == 'next-gallery' ) {
      $facebookComments.hide();
    } else {
      $facebookComments.show();
    }

      updateFacebookComments(base_url + '/' + token);
  };

  var updateFacebookComments = function(url) {
    facebookCommentsTemplate = facebookCommentsTemplate || $('#facebook-comments-template').text();

    if ( url ) {
      $facebookComments.html(facebookCommentsTemplate.replace(/href="[^"]+"/g, 'href="' + url + '"'));
    }

    FB.XFBML.parse($facebookComments[0]);
  };


  // keep track of gallery variables
  // this is a global for debugging
  gallery = {
    // gallery-wide properties
    slideshow: null,
    $slides: null,

    // Cover Slide properties
    hasCover: false,
    $galleryCoverSlide: null,
    $galleryDescription: null,
    $galleryContent: null,

    // gallery nav properties
    $nav: null,
    $previousSlide: null,
    $nextSlide: null,
    $paginationTotal: null,
    $paginationCurrent: null,

    // next gallery properties
    $nextGallery: null,
    nextGalleryHeadline: null,
    nextGalleryTopic: null,

    // state
    isShowing: false,
    currentSlideIndex: null,
    $currentSlide: null,

    showCover: function() {
      // upate tpsocial values if we ahven't done them already
      if (!this.$galleryCoverSlide.find('.tp-social:not(.tp-social-skip)').is('tp-social-processed')) {
        updateTpSocialMedia(this.$galleryCoverSlide.find('img').attr('src'), this.$galleryCoverSlide.find('.gallery-cover-title').text());
        this.$galleryCoverSlide.find('.tp-social:not(.tp-social-skip)').tpsocial(tp_social_config);
      }
      // show the cover
      this.$galleryCoverSlide.removeClass('hidden');
      this.$galleryDescription.removeClass('hidden');
      this.$galleryContent.addClass('hidden');
      this.isShowing = false;
      $('body').removeClass('gallery-showing');

    },

    showGallery: function(replace) {
      if ( this.isShowing ) return;

      this.slideCallback();

      // show the gallery
      this.$galleryCoverSlide.addClass('hidden');
      this.$galleryDescription.addClass('hidden');
      this.$galleryContent.removeClass('hidden');
      this.isShowing = true;
      $('body').addClass('gallery-showing');

      // store the token to catch a corner case where page updates
      // fail to fire when the first slide is loaded.
      var token = getCurrentToken();
      this.hpushCurrentSlide(replace);

      if (token == getCurrentToken()) {
	showFacebookComments(token);
      }
    },

    adjustSlideshowHeight: function() {
      this.$slides.height(this.$currentSlide.height());
    },

    getIndex: function(token) {
      return this.$slides.find("[data-token='" + token + "']").data('index');
    },

    next: function() {
      // if we're on the last slide (currentSlideIndex is zero-indexed)
      // go to the next gallery if there is one; in any case, return
      if (this.currentSlideIndex == (this.slideshow.getNumSlides() - 1)) {
	if (this.$nextGallery.length) {
	  var $anchor = this.$nextGallery.find('a:first');
	  $anchor.trigger(click);
	  window.location.href = $anchor.attr('href');
	}
        return;
      }

      this.slideTo(this.currentSlideIndex + 1);
    },
    previous: function() {
      // if we're on the first slide go back to the cover
      // if there is one; in any case, return
      if (this.currentSlideIndex == 0) {
        if(this.hasCover) {
          this.showCover();
          hpush('', this.$galleryCoverSlide.find('.gallery-cover-title').text);
        }
        return;
      }

      this.slideTo(this.currentSlideIndex - 1);
    },

    // wrapper function for sliding for interface consistency
    // and for dealing with instances where we're already on the requested slide
    slideTo: function(slideIndex) {
      // if we're on the requested slide already, just run the callback
      if (slideIndex == this.currentSlideIndex) {
	this.slideCallback();
      } else {
	this.slideshow.slide(slideIndex);
      }
    },

    slideCallback: function() {
      this.currentSlideIndex = this.slideshow.getPos();
      this.$currentSlide = this.$slides.find('[data-index=' + this.currentSlideIndex + ']');

      this.adjustSlideshowHeight();

      // update tpsocial values
      updateTpSocialMedia(this.$currentSlide.find('img').attr('src'), this.$currentSlide.find('.slide-caption').text().replace(/^\s+|\s+$/g, '').replace(/[\ |\t]+/g, ' ').replace(/[\n]+/g, "\n"));
      this.$galleryContent.find('.tp-social:not(.tp-social-skip)').tpsocial(tp_social_config);

      console.log([
        this.$currentSlide.find('img').attr('src'),
        this.$currentSlide.find('.slide-caption').text().replace(/^\s+|\s+$/g, '').replace(/[\ |\t]+/g, ' ').replace(/[\n]+/g, "\n")
      ]);

      // hide social buttons on the "next gallery slide"
      if (this.$currentSlide[0] === this.$nextGallery[0]) {
	this.$galleryContent.find('#gallery-content-social').css('visibility', 'hidden');
      } else {
	this.$galleryContent.find('#gallery-content-social').css('visibility', 'visible');
      }

      // update pagination
      this.$paginationCurrent.html(this.currentSlideIndex + 1);
      this.$previousSlide.toggleClass('hidden', this.currentSlideIndex == 0 && !this.hasCover);
      this.$nextSlide.toggleClass('hidden', this.currentSlideIndex == (this.slideshow.getNumSlides() - 1) && !this.$nextGallery.length);

      // only update the history and state of the page
      // if the gallery is showing.
      if (this.isShowing) {
	this.hpushCurrentSlide();
      }
    },

    hpushCurrentSlide: function(replaceState) {
      hpush(this.$currentSlide.data('token'), this.$currentSlide.find('.slide-caption-headline').text(), replaceState);
    }
  };

  Drupal.behaviors.sideshowInit = {
    attach: function() {
      if (!$('body').is('.node-type-openpublish-photo-gallery')) return;

      // first, create the slideshow
      gallery.slideshow = new Swipe(document.getElementById('slides'), {
        continuous: false,
        callback: $.proxy(gallery.slideCallback, gallery)
      });

      // populate gallery properties
      gallery.$slides = $('#slides');

      // gallery nav
      gallery.$nav = $('#gallery-nav');
      gallery.$previousSlide = $('#previous-slide');
      gallery.$nextSlide = $('#next-slide');
      gallery.$paginationTotal = $('#total-slides').html(gallery.slideshow.getNumSlides());
      gallery.$paginationCurrent = $('#current-slide').html('1');

      // next gallery slide
      gallery.$nextGallery = gallery.$slides.find('.gallery-slide-next-gallery');

      // cover properties
      gallery.$galleryCoverSlide = $('#block-takepart-gallery-support-takepart-gallery-cover-slide');
      gallery.$galleryDescription = $('#gallery-description');
      gallery.$galleryContent = $('#block-takepart-gallery-support-takepart-gallery-content');
      gallery.hasCover = gallery.$galleryCoverSlide.length;

      // fire the callback to populate all the relevant data
      gallery.slideTo(0);
    }
  };

  Drupal.behaviors.slideshowBehavior = {
    attach: function() {
      if (!$('body').is('.node-type-openpublish-photo-gallery')) return;

      // hovering on all slides lights lights up "next" nav
      // clicking images (on all slides by the last) advances slideshow
      // (or touchend, on touch-enabled devices)
      gallery.$slides.find('.gallery-slide')
        .on('mouseover', 'img', function() { gallery.$nextSlide.addClass('hover'); })
        .on('mouseout', 'img', function () { gallery.$nextSlide.removeClass('hover'); })
      .not(gallery.$nextGallery)
        .on(click, 'img', function() { gallery.$nextSlide.trigger(click); })
      ;

      // deal with touch events
      $('body').on('touchmove', function() {
        isTouchmove = true;
      });

      // previous/next behavior
      gallery.$previousSlide.on(click, function (e) {
        if (isTouchmove) return isTouchmove = false;
        e.preventDefault();
        gallery.previous.call(gallery);
      });

      gallery.$nextSlide.on(click, function (e) {
        if (isTouchmove) return isTouchmove = false;
        e.preventDefault();
        gallery.next.call(gallery);
      });

      var resizeTimeout = null;
      $(window).on('resize', function(){
        clearTimeout(resizeTimeout);
        resizeTimeout = setTimeout($.proxy(gallery.adjustSlideshowHeight, gallery), 250);
      });

    }
  };

  Drupal.behaviors.nextGalleryBehavior = {
    attach: function() {
      if (!$('body').is('.node-type-openpublish-photo-gallery')) return;

      gallery.nextGalleryHeadline = gallery.$nextGallery.find('.slide-caption-headline').text();
      gallery.nextGalleryTopic = $('<div />').html(gallery.$nextGallery.data('topic')).text(); // hack to decode entities

      gallery.$nextGallery.find('a:first').on(click, function(e) {
        if (isTouchmove) return isTouchmove = false;
        takepart.analytics.track('gallery-next-gallery-click', {
          headline: nextGalleryHeadline,
          topic: nextGalleryTopic,
          a: this
        });
      });
    }
  };

  Drupal.behaviors.coverBehavior = {
    attach: function() {
      if (!$('body').is('.node-type-openpublish-photo-gallery')) return;

      $('.gallery-cover-slide, .enter-link').find('> a').on(click, function(e){
        if (isTouchmove) return isTouchmove = false;
        e.preventDefault();
        gallery.showGallery();
      });

      // Initialize page based on URL
      var token = getCurrentToken();

      if ( token && token != 'first-slide' ) {
        var slideIndex = gallery.getIndex(token);
        gallery.showGallery();
	gallery.slideTo(slideIndex);
      } else if ( token == 'first-slide' ) {
        skipNextPageview = true;
        gallery.showGallery(true);
      } else if ( gallery.hasCover ) {
        gallery.showCover();
      } else {
        skipNextPageview = true;
        gallery.showGallery(true);
      }
    }
  };

  Drupal.behaviors.galleryPopstateBehavior = {
    attach: function() {
      if (!$('body').is('.node-type-openpublish-photo-gallery')) return;

      // Listen for html5 history updates/back button
      var firstPop = true;
      window.addEventListener('popstate', function(e) {
        // don't track the first popstate event
        if (firstPop) return firstPop = false;

        var token = getCurrentToken();
        if (token) {
          var slideIndex = gallery.getIndex(token);
          gallery.slideTo(slideIndex);
          gallery.showGallery();
        } else if ( gallery.hasCover ) {
          gallery.showCover();
        }

        updatePage(token);
      });
    }
  };

})(jQuery, Drupal, this, this.document);
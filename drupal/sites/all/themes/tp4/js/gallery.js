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

  // utility function to refresh ads
  var refreshDfpAds = function() {
    if(typeof googletag != 'undefined') {
      googletag.pubads().refresh();
    }
  };

  // Update html5 history if token is new,
  // with option to replace state instead of updating
  var hpush = function(token, title, replace) {

    if (typeof window.history == 'undefined') return;

    var replace = replace || false;
    var curtoken = getCurrentToken();
    if ( curtoken == token ) return;

    // TODO
    // update_page(token);

    if ( replace ) {
      history.replaceState(null, title, base_url + '/' + token + query);
    } else {
      history.pushState(null, title, base_url + '/' + token + query);
    }
  };

  var skip_next_pageview = false;
  var updateTo = null;
  var updatePage = function(token) {
    clearTimeout(updateTo);

    // skip the 
    if ( !skip_next_pageview ) {
      setTimeout((function(token, skip_next_pageview) {
        return function() {
          takepart.analytics.track('gallery-track-slide', {
            token: token,
            skip_pageview: skip_next_pageview,
            next_gallery_headline: next_gallery_headline,
            next_gallery_topic: next_gallery_topic
          });
        }
      })(token, skip_next_pageview), 500);
    } else {
      skip_next_pageview = false;
    }

    updateTo = setTimeout(function() {
      var token = get_curtoken();

      if ( token == 'next-gallery' ) {
        $fb_comment.hide();
      } else {
        $fb_comment.show();
      }

      show_fb_comments(fb_comment_el, base_url + '/' + token);

      if ( googletag != undefined ) {
        googletag.pubads().refresh();
      }
    }, 500);
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
    currentSlideIndex: 0,
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

    },

    showGallery: function(replace) {
      if ( this.isShowing ) return;

      // update social values
      updateTpSocialMedia(this.$currentSlide.find('img').attr('src'), this.$currentSlide.find('.slide-caption').text().replace(/^\s+|\s+$/g, '').replace(/[\ |\t]+/g, ' ').replace(/[\n]+/g, "\n"));
      this.$galleryContent.find('.tp-social:not(.tp-social-skip)').tpsocial(tp_social_config);

      // show the gallery
      this.$galleryCoverSlide.addClass('hidden');
      this.$galleryDescription.addClass('hidden');
      this.$galleryContent.removeClass('hidden');
      this.isShowing = true;

      this.hpushCurrentSlide(replace);

    },

    next: function() {
      // if we're on the last slide (currentSlideIndex is zero-indexed)
      // go to the next gallery if there is one; in any case, return
      if (this.currentSlideIndex == (this.slideshow.getNumSlides() - 1)) {
	if (this.$nextGallery.length) {
	  var $anchor = this.$nextGallery.find('a:first');
	  $anchor.trigger('click');
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

    // wrapper function for sliding for consistency
    // in the gallery object's interface
    slideTo: function(slideIndex) {
      this.currentSlideIndex = slideIndex;
      this.$currentSlide = this.$slides.find('[data-index=' + this.currentSlideIndex + ']');

      // update pagination
      this.$paginationCurrent.html(this.currentSlideIndex + 1);

      // TODO
      // set variables/classes for "on first" or "on last" slides?

      // and finally, we slide
      this.slideshow.slide(slideIndex);
    },

    slideCallback: function() {
      // update tpsocial values and hide if we're on the "next gallery" slide
      updateTpSocialMedia(this.$currentSlide.find('img').attr('src'), this.$currentSlide.find('.slide-caption').text().replace(/^\s+|\s+$/g, '').replace(/[\ |\t]+/g, ' ').replace(/[\n]+/g, "\n"));
      this.$galleryContent.find('.tp-social:not(.tp-social-skip)').tpsocial(tp_social_config);
      if (this.$currentSlide[0] === this.$nextGallery[0]) {
        //  TODO
        //  hide social buttons
      } else {
        // TODO
        // show social buttons
      }

      // TODO re-size slideshow based on height of the current slide?

      // if the gallery is showing, update the state of the page
      if (!this.isShowing) return;
      this.hpushCurrentSlide();
      // TODO do this in the page update?
      refreshDfpAds();
    },

    hpushCurrentSlide: function(replaceState) {
      hpush(this.$currentSlide.data('token'), this.$currentSlide.find('.slide-caption-headline').text(), replaceState);
    }
  };

  Drupal.behaviors.slideshowBehavior = {
    attach: function() {
      // first, create the slideshow
      gallery.slideshow = new Swipe(document.getElementById('slides'), {
        continuous: false,
        callback: $.proxy(gallery.slideCallback, gallery)
      });
      // store the top gallery div jquery object
      gallery.$slides = $('#slides');
      gallery.$currentSlide = gallery.$slides.find('[data-index=' + this.currentSlideIndex + ']');

      // populate gallery nav properties
      gallery.$nav = $('#gallery-nav');
      gallery.$previousSlide = $('#previous-slide');
      gallery.$nextSlide = $('#next-slide');
      gallery.$paginationTotal = $('#total-slides').html(gallery.slideshow.getNumSlides());
      gallery.$paginationCurrent = $('#current-slide').html('1');

      // hovering on all slides lights lights up "next" nav
      // clicking images (on all slides by the last) advances slideshow
      gallery.$slides.find('.gallery-slide')
        .on('mouseover', 'img', function() { gallery.$nextSlide.addClass('hover'); })
        .on('mouseout', 'img', function () { gallery.$nextSlide.removeClass('hover'); })
      .not(gallery.$nextGallery)
        .on('click', 'img', function() { gallery.$nextSlide.trigger('click'); })
      ;

      // previous/next behavior
      gallery.$previousSlide.on('click', function (e) {
        e.preventDefault();
        gallery.previous.call(gallery);
      });

      gallery.$nextSlide.on('click', function (e) {
        e.preventDefault();
        gallery.next.call(gallery);
      });

      // TODO: resize all slides on window resize?
    }
  };

  Drupal.behaviors.nextGalleryBehavior = {
    attach: function() {
      // if there is a next gallery slide, set it up
      gallery.$nextGallery = gallery.$slides.find('.gallery-slide-next-gallery');
      gallery.nextGalleryHeadline = gallery.$nextGallery.find('.slide-caption-headline').text();
      gallery.nextGalleryTopic = $('<div />').html(gallery.$nextGallery.data('topic')).text(); // hack to decode entities

      gallery.$nextGallery.find('a:first').on('click', function(e) {
        takepart.analytics.track('gallery-next-gallery-click', {
          headline: gallery.nextGalleryHeadline,
          topic: gallery.nextGalleryTopic,
          a: this
        });
      });
    }
  };

  Drupal.behaviors.coverBehavior = {
    attach: function() {
      // populate gallery properties with cover, slideshow, and description
      gallery.$galleryCoverSlide = $('#block-takepart-gallery-support-takepart-gallery-cover-slide');
      gallery.$galleryDescription = $('#gallery-description');
      gallery.$galleryContent = $('#block-takepart-gallery-support-takepart-gallery-content');
      gallery.hasCover = gallery.$galleryCoverSlide.length;

      $('.gallery-cover-slide, .enter-link').find('> a').on('click', function(e){
        e.preventDefault();
        // gallery.slideTo(0); // shouldn't need this (index should already be at zero)
        gallery.showGallery();
      });

      // Initialize page based on URL
      var token = getCurrentToken();

      if ( token && token != 'first-slide' ) {
        var slideIndex = gallery.$slides.find("[data-token='" + token + "']").data('index');
        gallery.slideTo(slideIndex);
        gallery.showGallery();
      } else if ( token == 'first-slide' ) {
        skip_next_pageview = true;
        gallery.showGallery(true);
      } else if ( gallery.hasCover ) {
        gallery.showCover();
      } else {
        skip_next_pageview = true;
        gallery.showGallery(true);
      }
    }
  };

  Drupal.behaviors.galleryPopstateBehavior = {
    attach: function() {

      // Listen for html5 history updates/back button
      var firstPop = true;
      window.addEventListener('popstate', function(e) {
        // don't track the first popstate event
        if (firstPop) return firstPop = false;

        var token = getCurrentToken();
        alert(token);
        if (token) {
          var slideIndex = gallery.$slides.find("[data-token='" + token + "']").data('index');
          gallery.slideTo(slideIndex);
          gallery.showGallery();
        } else if ( gallery.hasCover ) {
          gallery.showCover();
        }

        // TODO ??
        // update_page(token);
      });
    }
  };

})(jQuery, Drupal, this, this.document);

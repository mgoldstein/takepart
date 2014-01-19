/**
 * @file
 * Scripts for Takepart Galleries in TP4.
 */

(function ($, Drupal, window, document, undefined) {

  //
  // Set up gallery-wide variables
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
  window.takepart.analytics.skip_addthis = true;

  // analytics
  var skip_next_pageview = false;

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

  // Update html5 history if token is new
  var hpush = function(token, title, replace) {
    var curtoken = getCurrentToken();
    var replace = replace || false;
    if ( curtoken == token ) return;

    // TODO
    // update_page(token);

    if ( typeof window.history != 'undefined' ) {
      return;
    }

    if ( replace ) {
      history.replaceState(null, title, base_url + '/' + token + query);
    } else {
      history.pushState(null, title, base_url + '/' + token + query);
    }
  };

  // keep track of gallery variables
  // this is a global for debugging
  gallery = {
    // top-level properties
    slideshow: null,
    isShowing: false,
    $slides: null,

    // specific slides
    hasCover: false,
    $galleryCoverSlide: null,
    $galleryDescription: null,
    $galleryContent: null,

    // next gallery stuff
    $nextGallery: null,
    nextGalleryHeadline: null,
    nextGalleryTopic: null,

    // current properties
    currentSlideIndex: 0,
    $currentSlide: null,

    // gallery nav
    $nav: null,
    $previousSlide: null,
    $nextSlide: null,
    $paginationTotal: null,
    $paginationCurrent: null,

    showCover: function() {
      // upate tpsocial values
      updateTpSocialMedia(this.$galleryCoverSlide.find('img').attr('src'), this.$galleryCoverSlide.find('.gallery-cover-title').text());
      this.$galleryCoverSlide.find('.tp-social:not(.tp-social-skip)').tpsocial(tp_social_config);

      // show the cover
      this.$galleryCoverSlide.removeClass('hidden');
      this.$galleryDescription.removeClass('hidden');
      this.$galleryContent.addClass('hidden');
      this.isShowing = false;

      $('.gallery-cover-slide, .enter-link').find('> a').on('click.enterGallery', function(e){
        e.preventDefault();
        gallery.showGallery();
      });
    },

    showGallery: function(replace) {
      if ( this.isShowing ) return;

      // update tpsocial values
      updateTpSocialMedia(this.$galleryContent.find('img').attr('src'), this.$galleryContent.find('.slide-caption-headline').text());
      this.$galleryContent.find('.tp-social:not(.tp-social-skip)').tpsocial(tp_social_config);

      // show the gallery
      this.$galleryCoverSlide.addClass('hidden');
      this.$galleryDescription.addClass('hidden');
      this.$galleryContent.removeClass('hidden');
      this.isShowing = true;

      // update the state of the page
      // hpush($current_slide.data('token'), $current_slide.find('.headline').text(), replace);
      refreshDfpAds();
    },

    next: function() {
      // if we're on the last slide (currentSlideIndex is zero-indexed)
      // go to the next gallery if there is one; in any case, return
      if (this.currentSlideIndex == (this.slideshow.getNumSlides() - 1)) {
        this.$nextGallery.length && alert('next gallery!'); // TODO
        return;
      }

      this.slideTo(this.currentSlideIndex + 1);
    },
    previous: function() {
      // if we're on the first slide go back to the cover
      // if there is one; in any case, return
      if (this.currentSlideIndex == 0) {
        this.hasCover && this.showCover();
        return;
      }

      this.slideTo(this.currentSlideIndex - 1);
    },

    slideTo: function(slideIndex) {
      this.slideshow.slide(slideIndex);
      this.currentSlideIndex = slideIndex;
      this.$currentSlide = this.$slides.find('[data-index=' + slideIndex + ']');

      this.$paginationCurrent.html(slideIndex + 1);
    },

    slideCallback: function() {
      var previousSlideIndex = this.currentSlideIndex;
      var newSlideIndex = this.slideshow.getPos();
    }
  };

  Drupal.behaviors.slideshowBehavior = {
    attach: function() {
      gallery.$slides = $('#slides');

      gallery.$nextGallery = gallery.$slides.find('.gallery-slide-next-gallery');
      gallery.nextGalleryHeadline = gallery.$nextGallery.find('slide-caption-headline').text();
      // TODO add topics to template
      // gallery.nextGalleryTopic - gallery.$nextGallery.find('.topic').text();

      gallery.$nav = $('#gallery-nav');
      gallery.$previousSlide = $('#previous-slide');
      gallery.$nextSlide = $('#next-slide');

      gallery.slideshow = new Swipe(document.getElementById('slides'), {
        continuous: false,
        callback: $.proxy(gallery.slideCallback, gallery)
      });

      // populate slide nav with current and total numbers
      gallery.$paginationTotal = $('#total-slides').html(gallery.slideshow.getNumSlides());
      gallery.$paginationCurrent = $('#current-slide').html('1');

      // clicking images (on all slides by the last) advances slideshow
      gallery.$slides.find('.gallery-slide').not(gallery.$nextGallery)
        .on('click', 'img', function() { gallery.$nextSlide.trigger('click'); })
        .on('mouseover', 'img', function() { gallery.$nextSlide.addClass('hover'); })
        .on('mouseout', 'img', function () { gallery.$nextSlide.removeClass('hover'); })
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

  Drupal.behaviors.coverBehavior = {
    attach: function() {
      gallery.$galleryCoverSlide = $('#block-takepart-gallery-support-takepart-gallery-cover-slide');
      gallery.$galleryDescription = $('#gallery-description');
      gallery.$galleryContent = $('#block-takepart-gallery-support-takepart-gallery-content');
      gallery.hasCover = gallery.$galleryCoverSlide.length;

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

  Drupal.behaviors.galleryAnalytics = {
    attach: function() {
      // TODO
    }
  };
})(jQuery, Drupal, this, this.document);

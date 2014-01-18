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

  // prevent 2 email calls from firing
  window.takepart.analytics.skip_addthis = true;

  // analytics
  var skip_next_pageview = false;

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

  var base_url = document.location.href.split(/\/|#/).slice(0,5).join('/');
  var query = '';
  if(base_url.indexOf('?') > 0) {
      query = base_url.substring(base_url.indexOf('?'), base_url.length);
      base_url = base_url.substring(0,base_url.indexOf('?'));
  }

  // keep track of whetehr the gallery is showing
  var galleryShowing = false;

  Drupal.behaviors.coverBehavior = {
    attach: function() {
      var $galleryCoverSlide = $('#block-takepart-gallery-support-takepart-gallery-cover-slide');
      var $galleryContent = $('#block-takepart-gallery-support-takepart-gallery-content');

      var showGallery = function(replace) {
        if ( galleryShowing ) return;

        var currentImage = $galleryContent.find('img').attr('src');
        tp_social_config.services.pinterest.media = currentImage;
        tp_social_config.services.tumblr.source = currentImage;

        var currentDescription = $galleryContent.find('.slide-caption-headline').text();
        tp_social_config.services.pinterest.description = currentDescription;
        tp_social_config.services.tumblr.caption = currentDescription;

        $galleryContent.find('.tp-social:not(.tp-social-skip)').tpsocial(tp_social_config);


        $galleryCoverSlide.addClass('hidden');
        $('#gallery-description').addClass('hidden');
        $galleryContent.removeClass('hidden');
        galleryShowing = true;

        // TODO $current_slide
        hpush($current_slide.data('token'), $current_slide.find('.headline').text(), replace);

        refreshDfpAds();
      };

      var showCover = function() {
        $galleryCoverSlide.removeClass('hidden');
        $('#gallery-description').removeClass('hidden');
        $galleryContent.addClass('hidden');
        galleryShowing = false;

        var currentImage = $galleryCoverSlide.find('img').attr('src');
        tp_social_config.services.pinterest.media = currentImage;
        tp_social_config.services.tumblr.source = currentImage;

        var currentDescription = $galleryCoverSlide.find('.gallery-cover-title').text();
        tp_social_config.services.pinterest.description = currentDescription;
        tp_social_config.services.tumblr.caption = currentDescription;

        $galleryCoverSlide.find('.tp-social:not(.tp-social-skip)').tpsocial(tp_social_config);

        $('.gallery-cover-slide, .enter-link').find('> a').on('click.enterGallery', function(e){
          e.preventDefault();
          showGallery();
        });
      };

      // Initialize page based on URL
      if ( getCurrentToken() && getCurrentToken() != 'first-slide' ) {
        var token = get_curtoken();
        var $slide = $galleryContent.find('[data-token="' + token + '"]');
        $slides.tpslide_to($slide);
        showGallery();
      } else if ( getCurrentToken() == 'first-slide' ) {
        skip_next_pageview = true;
        showGallery(true);
      } else if ( $galleryCoverSlide.length ) {
        showCover();
      } else {
        skip_next_pageview = true;
        showGallery(true);
      }

    }
  };

  Drupal.behaviors.slideshowBehavior = {
    attach: function() {
      // TODO: Initialize Slideshow

      // TODO: highlight "next" arrow on slide hover
      // TODO: Setup click on slide = advance behavior

      // TODO: resize all slides on window resize      
    }
  };

  Drupal.behaviors.galleryAnalytics = {
    attach: function() {
      // TODO
    }
  };
})(jQuery, Drupal, this, this.document);

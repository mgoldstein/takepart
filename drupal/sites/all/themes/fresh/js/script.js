/**
 * @file
 * A JavaScript file for the theme.
 *
 */

(function ($, Drupal, window, document, undefined) {

  window.initialVid = true;
var Environment = {
  isAndroid: function() {
    return navigator.userAgent.match(/Android/i);
  },
  isBlackBerry: function() {
    return navigator.userAgent.match(/BlackBerry/i);
  },
  isIOS: function() {
    return navigator.userAgent.match(/iPhone|iPad|iPod/i);
  },
  isOpera: function() {
    return navigator.userAgent.match(/Opera Mini/i);
  },
  isWindows: function() {
    return navigator.userAgent.match(/IEMobile/i);
  },
  isMobile: function() {
    return (Environment.isAndroid() || Environment.isBlackBerry() || Environment.isIOS() || Environment.isOpera() || Environment.isWindows());
  }
};
  window.isMobile = Environment.isMobile();

  Drupal.behaviors.mobileMenuToggle = {
    attach: function (context, settings) {

  var $body = $('body');
  $('.toggle-menu.toggle-left, .i-close-x').click(function () {
    //In campaign experience menu
    if ($('.campaign-experience').length != 0) {
      if ($body.hasClass('cic-menu-show')) {
        $body.removeClass('cic-menu-show');
        $('#cic-menu').fadeOut();
      }
      else {
        //Display the menu item that matches the current node
        expandCicMenu();
        $body.addClass('cic-menu-show');
        $('#cic-menu').fadeIn();
      }
    }
    else {
      if ($body.hasClass('mobile-menu-show')) {
        $body.removeClass("mobile-menu-show");
        //enable scroll on tablet
        document.ontouchmove = function (e) {
        return true;
        }
     } else {
    $body.addClass("mobile-menu-show");
    //disable scroll on tablet
    //document.ontouchmove = function(e){ e.preventDefault(); }
    $(document).on('touchstart touchmove', function (e) {
      if (!$(e.target).parents('nav#mobile-menu')) {
        e.preventDefault();
      }
    });
    //append a modal on feature articles
    if ($('body.node-type-feature-article').length != 0) {
      if ($('.feature-modal').length == 0) {
        $('body').append('<div class = "feature-modal"></div>');
      }
      $('.feature-modal').click(function () {
        if ($body.hasClass('mobile-menu-show')) {
       $body.removeClass("mobile-menu-show");
        }
      });
    }
     }
   }
   });
    }
  };

  Drupal.behaviors.mobileSearchToggleStyleTwo = {
    attach: function (context, settings) {


   /* Show search field */
   var $body = $('body');
   $('.navbar-transparent .toggle-search').click(function () {
     $(this).parents('.navbar-transparent').addClass('search-open');
   });

   /* Hide search if clicked away from */
   $(document).on('click', function (event) {
     if (!$(event.target).closest('.navbar-transparent').length) {
    $('.navbar-transparent').removeClass("search-open");
     }
   });

   // Close search
   /*$('#search-api-page-search-form-site-search--2 input#edit-keys-2--2').click(function(e){
    var offset = $(this).offset();
    var width = $(this).outerWidth();
    var pos_x = e.pageX - offset.left;

    if(width - pos_x < 15) {
    $('.navbar-transparent').removeClass("search-open");
    }
    });*/
   //Close search
   $('.navbar-transparent .search-close').click(function () {
     if ($('.navbar-transparent').hasClass('search-open')) {
    $('.navbar-transparent').removeClass("search-open");
     }
   });

    }
  };


  Drupal.behaviors.mobileSearchToggle = {
    attach: function (context, settings) {

   /* Search for mobile and Desktop */
   tp_mobile_header_init();
   if (typeof smartresize == 'function') {
     $(window).smartresize(function () {
    tp_mobile_header_init();
     });
   }

   function tp_mobile_header_init() {
     if ($(window).width() < 768) {
    /* Show search field */
    var $body = $('body');
    $('#header .toggle-search').click(function () {
      if ($body.hasClass('mobile-search-show')) {
        $body.removeClass("mobile-search-show");
      } else {
        $body.addClass("mobile-search-show");
      }
    });

    /* Hide search if clicked away from */
    $(document).on('click', function (event) {
      if (!$(event.target).closest('.search').length) {
        $body.removeClass("mobile-search-show");
      }
    });

    //makes the search go away on focus
    $('.search input').focus(function () {
      $(this).val('');
    });
     }
   }
    }
  };

  Drupal.behaviors.mobileMenuBehaviors = {
    attach: function (context, settings) {
      /* TODO: TP4 is unexpectedly dependent on the menu being 'exposed'.  Remove this dependency and use classes
      that come with Drupal */

      /* Prevent parent item from clicking through on initial click - mobile menu */
      var curItem = false;
      $('.mobile-menu > ul > li > a').on('click', function (e) {
        var item = $(this);
        if (item[ 0 ] != curItem[ 0 ]) {
          e.preventDefault();
          curItem = item;
        }
      });

      /* Show child menu. See _mobile-menu.scss */
      $('.mobile-menu > ul > li').click(function () {
        if (!$(this).hasClass('show')) {
          $(this).addClass("show");
        }
      });

      /* Show/hide child menu and prevent parent link from clicking - CIC menu */
      $('#cic-menu .content-menu ul > li.expanded > a').on('click', function (e) {
        if (!$(this).parent().hasClass('show')) {
          //Collapse any open/active items.
          $('#cic-menu .content-menu li.expanded').each(function(){
            $(this).removeClass('show');
            $(this).children('ul.menu').slideUp();
          });
          $(this).parent().addClass('show');
          $(this).next().slideDown();
          e.preventDefault();
        }
        else {
          $(this).parent().removeClass('show');
          $(this).next().slideUp();
          e.preventDefault();
        }
      });

    }
  }

  /* Position stick share Done here to not bother tp4 */
  $('document').ready(function () {
    window.featureFirst = false;
    window.tp_shareTopOffset();
    window.tp_shareLeftAlign();
    $(window).resize(function () {
   window.tp_shareTopOffset();
   window.tp_shareLeftAlign();
    });

    //Give the sticky share a fighting chance to load
    setTimeout(function () {
   $('.social').show();
   window.tp_shareTopOffset();
   window.tp_shareLeftAlign();
    }, 200);

    var lastScrollPos = 0;
    var scrollUp = false;
    //Content inside campaign Nav ONLY exists on campaign experience - first node is tagged with a campaign
    if ($('.campaign-experience').length != 0) {
      $(window).scroll(function() {
        //Determine the scroll direction
        var newScrollPos = window.scrollY;
        scrollUp = (newScrollPos < lastScrollPos) ? true : false;
        enableCicStickyNav(scrollUp);
        lastScrollPos = newScrollPos;
      });
    }

    //Add the class to position absolute the header if a node is tagged with a campaign on mobile
    //TODO: Uncomment once we review how it behaves with Ad
    //$('#page-wrapper.campaign-experience #header').addClass('mobile-ad-loaded');

  });

  /**
   *  @function:
   *    Function copied from tp_ad_takeover.jquery.js
   */
  window.tp_ad_takeover = function (bgcolor, bgimage, link) {
    //do not do on Feature Articles
    if (typeof $('.fresh-content-wrapper') != 'undefined' && $('.fresh-content-wrapper').hasClass('feature_article-wrapper') == false) {
   var $body = jQuery('body');
   var $a = jQuery('<a id="tp_ad_takeover" href="' + link + '" target="_blank"></a>');

   $body.css({
     background: bgcolor + ' url("' + bgimage + '") center top no-repeat',
     backgroundAttachment: 'fixed'
   }).addClass('tp_ad_takeover');

   $a.css({
     position: 'fixed',
     height: '100%',
     width: '100%',
     left: 0,
     top: 0,
     zIndex: 0
   });

   jQuery('body #footer-wrapper').after($a);

   //only do on fresh theme
   if ($('.fresh-content-wrapper').length != 0) {

     jQuery('body #footer-wrapper').after($a);
     //variables
     var background_image = new Image();
     background_image.src = bgimage;

     //checks to see if the image is loaded
     if (background_image.complete) {
    var background_image_height = background_image.height;
    takeover_ad(background_image_height);
     }
     //otherwise load image and then call function
     else {
    $(background_image).load(function () {
      var background_image_height = background_image.height;
      takeover_ad(background_image_height);
    });
     }

     //triggers a scroll so the background takeover will go in place
     $(window).scroll();
   }
    }
  };

  /**
   *  @function:
   *    Function is used to update the article only if on fresh
   */
  window.takeover_ad = function (background_image_height) {
    //ensures that the height is defined
    if (background_image_height != undefined) {
   //binds a window scroll
   $(window).bind('scroll', function () {
     //variables
     var first_article = $('article:first').offset();
     var window_top = $(window).scrollTop();
     var window_bottom = $(window).height() + window_top;
     first_article.bottom = first_article.top + $('article:first').height();
     var background_pos = first_article.bottom - background_image_height;
     $takeover_ad = $('#tp_ad_takeover');

     //updates the background position
     if (window_bottom > first_article.bottom) {
    $('body').css('background-attachment', 'scroll');
    $('body').css('background-position', 'center ' + background_pos + 'px');
    $takeover_ad.css('position', 'absolute');
    $takeover_ad.css('top', background_pos);
     }
     else {
    $('body').css('background-attachment', 'fixed');
    $('body').css('background-position', 'center top');
    $takeover_ad.css('position', 'fixed');
    $takeover_ad.css('top', 0);
     }

   });
    }
  };


  Drupal.behaviors.scrollUp = {
    attach: function (context, settings) {
   var lastScrollTop = 0;
   window.scrollUp = false;
   $(window).scroll(function (event) {
     var st = $(this).scrollTop();
     if (st > lastScrollTop) {
    window.scrollUp = false;
     } else {
    window.scrollUp = true;
     }
     lastScrollTop = st;
   });
    }
  };


  /**
   * Handle TP Infographics
   */
  Drupal.behaviors.infographics = {
    attach: function () {
   $('.tpinfographic').tpInfographic();
    }
  };
  /*
   * Set a Cookie/Message for the updated Terms of Use
   */
  /*
  Drupal.behaviors.TouCookie = {
    attach: function () {
   if (document.cookie.search('ppu') == -1) {
     //Set the cookie - 30 days
     exdays = 30;
     var d = new Date();
     d.setTime(d.getTime() + (exdays * 24 * 60 * 60 * 1000));
     var expires = d.toGMTString();
     document.cookie = "ppu=1; expires=" + expires + "; path=/";
     var markup = '\
         <div class="tou-alert">\
           <p>We have updated our <a href = "http://www.takepart.com/privacy-policy">Privacy Policy</a>.</p>\
           <span class="tou-close">close</span>\
         </div>';
     $('#page-wrapper').prepend(markup);
     $('.tou-close').click(function () {
    $('.tou-alert').slideUp('slow');
     });
   }
    }
  };
  */
 
  /*
   * Create ambient video on feature article
   */
   Drupal.behaviors.featureVideoBG = {
    attach: window.createVideoBG = function($vid_wrapper) {

      //The $vid_wrapper param is not set on initial load
      //It gets set on autoloaded nodes
      if (window.initialVid) {
        $vid_wrapper = $('.feature-image.has-videoBG');
        window.initialVid = false;
      }

      var src = $vid_wrapper.data('video-bg');
      if(!Environment.isMobile()){
        $('.feature-image.has-videoBG').each(function(){
          if(!$(this).hasClass('video-created')) {
            var videoWrapper = document.createElement("div");
            var video = document.createElement("video");
            var videoSource = document.createElement("source");
            videoWrapper.className = 'videoBG-wrapper';
            videoSource.type = "video/mp4";
            videoSource.src = src;
            video.className = 'background-video';
            video.setAttribute('autoplay', '');
            video.setAttribute('muted', '');
            video.setAttribute('loop', '');
            video.appendChild(videoSource);
            videoWrapper.appendChild(video);
            $vid_wrapper.prepend(videoWrapper);
            $vid_wrapper.addClass('video-created');
          }
        });
      }
      $('.feature-ambient-image.has-videoBG').each(function(){
        if(!$(this).hasClass('processed')) {
          $vid_wrapper = $(this);
          var src = $vid_wrapper.data('video-bg');
          if(!Environment.isMobile()){
            var videoWrapper = document.createElement("div");
            var video = document.createElement("video");
            var videoSource = document.createElement("source");
            videoWrapper.className = 'videoBG-wrapper';
            videoSource.type = "video/mp4";
            videoSource.src = src;
            video.className = 'background-video';
            video.setAttribute('autoplay', '');
            video.setAttribute('muted', '');
            video.setAttribute('loop', '');
            video.appendChild(videoSource);
            videoWrapper.appendChild(video);
            $vid_wrapper.prepend(videoWrapper);
            $vid_wrapper.addClass('video-created');
          }
          $(this).addClass('processed');
        }
      });
    }
  };

})(jQuery, Drupal, this, this.document);

/*
 * Enables the sticky Nav & sticky share for content inside campaign
 */
function enableCicStickyNav(scrollUp) {
  var $camp_banner = $('.campaign-ref-wrapper');
  //DESKTOP - Display the sticky Nav once the banner is not in viewport
  if(!window.isMobile) {
    if(!$camp_banner.isInViewport(null,0.0)) {
      $('body').addClass('sticky-cic-nav');
      $('.sticky-cic-header').slideDown('fast');
      //Social share becomes sticky once cic header is sticky (non-feature)
      if ($('.node-type-feature-article').length == 0) {
        $('.sticky-wrapper .social').addClass('cic-sticky');
      }
      else if (!($('.feature_article-wrapper:not(.autoloaded) .feature-image').isInViewport(null,0.1))) {
        //Social share becomes sticky when cic header is sticky and the main image is not visible (feature article)
          $('.sticky-wrapper .social').addClass('cic-sticky');
      }
    }
    else if ($('.sticky-cic-nav').length != 0) {
      $('body').removeClass('sticky-cic-nav');
      $('.sticky-cic-header').hide();
      $('.sticky-wrapper .social').removeClass('cic-sticky');
    }
  }
  else {
    //MOBILE - Display the sticky Nav once the banner is not in viewport and ONLY when the user is scrolling up
    if(!$camp_banner.isInViewport(null,0.0) && scrollUp) {
        $('body').addClass('sticky-cic-nav');
        $('.sticky-cic-header').slideDown('fast');
    }
    else {
      $('body').removeClass('sticky-cic-nav');
      $('.sticky-cic-header').hide();
    }
  }
}
/* expand the CIC menu to display the current article */
function expandCicMenu() {
  //Collapse any open menu items
  $('#cic-menu .content-menu li.expanded').each(function() {
    $(this).removeClass('show');
    $(this).children('ul.menu').slideUp();
  });
  //remove any previous link that has current-node class
  $('#cic-menu .content-menu li.is-leaf a').removeClass('current-node');

  active_url = window.location.href;
  //Loop through the content menu link and match the url
  $('#cic-menu .content-menu li.is-leaf a').each(function() {
    $this = $(this);
    var href = $this.attr('href');
    //Convert relative links to absulute
    if (href.substr(0,7) != 'http://' && href.substr(0,8) != 'https://' && href.substr(0,2) != '//') {
      //Append the host file
      href = 'http://' + window.location.host + href;
    }
    if (active_url == href) {
      $(this).addClass('current-node');
      //Does the link have a parent?
      if ($this.parents('li.expanded').length != 0) {
        parent_link = $this.parents('li.expanded');
        //Expand the parent menu item
        parent_link.addClass('show');
        parent_link.children('ul.menu').slideDown();
      }
      return false;
    }
  });
}


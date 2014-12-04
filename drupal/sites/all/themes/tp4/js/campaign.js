/**
 * @file
 * Scripts for Takepart Campaigns.
 */
(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.campaignSlideShows = {
    attach: function() {
      if (!$('body').is('.node-type-campaign-page')) {
        return;
      }

      //TODO: There is an error when testing videos with only 2 slides
      //swipejs duplicates slides if only two exist throwing an error with videos

      var $sliders = $('.slider');
      var $swipes = $('.swipe');

      // setup slideshows
      $sliders.each(function() {
        // set up the slider
        var $this = $(this).Swipe({
          continuous: false,
          speed: 800,
          callback: function(index, slide) {
            $navLinks
              .filter('[data-slide=' + index % $navLinks.length + ']').addClass('active')
              .siblings('.active').removeClass('active')
            ;
            var maxCards = $this.data('Swipe').getNumSlides() - 1;

            if(index  === 0){
              $this.addClass('on-first-slide');
              $this.removeClass('on-last-slide');
            }
            else if(index == maxCards){
              $this.addClass('on-last-slide');
              $this.removeClass('on-first-slide');
            }
            else{
              $this.removeClass('on-last-slide');
              $this.removeClass('on-first-slide');
            }
          }
        });
        var slider = $this.data('Swipe');
        var $navLinks = $this.find('.slider-pagination a');

        // setup forward/back nav
        $this.find('.left-arrow').on('click', function() { slider.prev(); });
        $this.find('.right-arrow').on('click', function() { slider.next();  });

        // set up pagination -- active class and click event
        $navLinks.filter(':first').addClass('active')
          .parent().on('click', 'a', function(e) {
            e.preventDefault();
            slider.slide($(this).data('slide'));
          })
        ;
      }); // end $sliders.each()

      // deal with card padding
      var adjustCardHeightsAndPadding = function() {
        $swipes.each(function() {
          var $this = $(this);
          var titleHeight = $this.find('.tray-header').outerHeight();
          var multipleCards = $this.is('.has-multiple-cards');

          // if there is a tray title, set card padding
          // and contextual link position
          if (titleHeight > 0) {
            $this.find('.card .card-inner')
              .css("padding-top", titleHeight)
              .find('.contextual-links-wrapper')
                .css({
                  top: titleHeight + 2,
                  right: multipleCards ? 80 : 5
                })
            ;
          }
        });
      };

      // bind the previous function to window load and resize
      // debouncing for 300ms
      var resizeTimeout = null;
      $(window).on('load resize', function() {
        clearTimeout(resizeTimeout);
        resizeTimeout = setTimeout($.proxy(adjustCardHeightsAndPadding, this), 250);
      });
      
      //addresses issue with hover state - removed touchstart
      $('.mobile-arrow.right-arrow, .mobile-arrow.left-arrow').bind('mouseover', function() {
        $(this).addClass('hover-class'); 
      });
      
      //addresses issue with hover state remove touchend
      $('.mobile-arrow.right-arrow, .mobile-arrow.left-arrow').bind('mouseout touchend', function() {
        $(this).removeClass('hover-class');
      });
    }
  };

  Drupal.behaviors.campaignHeaderMenu = {
    attach: function() {
      if ($('body').is('.node-type-campaign-page')) {
        $('ul.sf-menu').superfish();

        // minimum mobile height 
        var HeaderMobileMinHeight = $('.header-inner').attr("data-mheight");
        if(HeaderMobileMinHeight != '-20px'){
          if($(window).width() < 768){
            $('.header-inner').css( "min-height", HeaderMobileMinHeight);
            $('.branding-header').css( "min-height", HeaderMobileMinHeight);
          }
        }

      }
    }
  };

  Drupal.behaviors.campaignResponsiveMenu = {
    attach: function() {
      function bindStickupToMenus() {
        //initiating jQuery  
        //enabling stickUp on the '.navbar-wrapper' class
        var desktopWidth = ( $(window).width() > 768),
            campaignHasNoMenus = $('#campaign-drawers li').length == 0,
            stickUpSettings = {
              parts:     Drupal.settings.tp_campaigns.stickupParts,
              itemClass: 'anchored',
              itemHover: 'active'
            }; 

        if ( desktopWidth ) {
          $('#block-tp-campaigns-tp-campaigns-hero').stickUp( stickUpSettings );
        }
        if ( campaignHasNoMenus ) {
          $('.campaign-menu-toggle').hide();
        }
      }
      
      //only bind when document is ready to bind
      $(document).ready(function() {
        //addresses issue with race condition
        if ( Drupal.settings.tp_campaigns )
          setTimeout( bindStickupToMenus, 2000 );
          
        //ensures that this only runs on campaign displays
        if ($('body').hasClass('campaign-display')) {
          $(window).scroll(function() {
            if ($('#block-tp-campaigns-tp-campaigns-hero').hasClass('isStuck')) {
              $('#main-wrap').css('margin-top', parseInt($('#block-tp-campaigns-tp-campaigns-hero').height()) + 'px');
            }
            else {
              $('#main-wrap').css('margin-top', '');
            }
          });
        }
      });
    }
  };

  //needed to override TakePart3 theming of the Newsletter block.
  Drupal.behaviors.newsletterSubmit = {
    attach: function() {
      $('.takepart-newsletter-form input.rollover-image-off').hover(
        function() {
          $(this).attr('old-src', $(this).attr('src'));
          $(this).attr('src', $(this).parent().find('img.rollover-image-on').attr('src'));
        },
        function() {
          // $(this).attr('src', $(this).attr('old-src'));
          $(this).attr('src','/sites/all/themes/tp4/images/newsletter_submit.png');
        }
      );
    }
  };

  Drupal.behaviors.campaignPageSocialShare = {
    attach: function() {
      var $body = $('body');

      if (!$body.is('.node-type-campaign-page')) {
        return;
      }

      var $social = $('#campaign-page-social');
      var title = $social.data('title');
      var description = $social.data('description');
      var imageSrc = $social.data('imagesrc');

      var mainShares = {
          url_append: '?cmpid=organic-share-{{name}}',
          services: [
            {
              name: 'facebook',
              title: title,
              image: imageSrc,
              description: description
            },
            {
              name: 'twitter',
              text: title
            },
            {
              name: 'googleplus'
            }
          ]
      };
      var moreShares = {
          url_append: '?cmpid=organic-share-{{name}}',
          services: [
            {
              name: 'pinterest',
              media: imageSrc,
              description: title
            },
            {
              name: 'tumblr',
              source: imageSrc,
              caption: title + " - " + description
            },
            {
              name: 'mailto',
              title: title,
              note: description
            }
          ]
      };

      $('#campaign-page-share').tpsocial(mainShares);
      $('#campaign-page-more-shares').find('p').tpsocial(moreShares);
      $moreShares = $('#campaign-page-social-more');

      var moreSharesClose = function() {
        $moreShares.removeClass('focus');
        $body.off('click.campaignSocial');
      };

      $moreShares
        .on('click', '.trigger a', function(e) {
          e.preventDefault();
          if (!$moreShares.is('.focus')) {
            $moreShares.addClass('focus');
            setTimeout(function() {
              $body.on('click.campaignSocial', moreSharesClose);
            }, 100);
          }
        })
        .on('focusin', function() {
          $moreShares.addClass('focus');
        })
        .on('focusout', function() {
          $moreShares.removeClass('focus');
        })
      ;
    }
  };
})(jQuery, Drupal, this, this.document);

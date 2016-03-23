/**
 * @file
 * A JavaScript file for autoscroll.
 *
 */

(function ($, Drupal, window, document, undefined) {

  /**
    * Add an extra function to the Drupal ajax object
    * which allows us to trigger an ajax response without
    * an element that triggers it.
    */
   Drupal.ajax.prototype.autoCampaign = function() {
     var ajax = this;

     // Do not perform another ajax command if one is already in progress.
     if (ajax.ajaxing) {
       return false;
     }
     var traynumb = window.campaignTray + Number(Drupal.settings.traysLoaded);
     ajax.url = ajax.element_settings.url = ajax.options.url = '/autocampaign/'+Drupal.settings.autoloadCampaigns+'/'+traynumb;
     window.campaignTray++;
     window.newTapWidgets = true;
     try {
       $.ajax(ajax.options);
     }
     catch (err) {
       alert('An error occurred while attempting to process ' + ajax.options.url);
       return false;
     }

     return false;
   };

   /**
    * Define a custom ajax action to load my autocampaign ids.
    */
   var custom_settings = {};
   custom_settings.url = '/autocampaign/'+Drupal.settings.autoloadCampaigns+'/0';
   custom_settings.event = 'onload';
   custom_settings.keypress = false;
   custom_settings.prevent = false;
   custom_settings.callback = 'tp_autoload_campaign_handler';
   custom_settings.selector = 'article.node-campaign-page.view-mode-full';
   Drupal.ajax['autocampaign_ajax'] = new Drupal.ajax(null, $(document.body), custom_settings);

   /**
    * On the load of the page I init my custom ajax call
    */
   $(document).ready(function() {
     campaignPreload();
     window.muted = false;
     //pause the video when less than 70% is in viewport
     $(window).bind('scroll', function() {
      jQuery('.videoBG_wrapper video').each(function(index){
        //Get the card height since the video itself could be a different height
        var vid = jQuery('.videoBG_wrapper video').get(index);
        if(typeof vid !== 'undefined') {
          var vid_parent = jQuery(this).parent().parent();
          var is_paused = vid.paused;
          if (vid_parent.isInViewport(null,0.7)) {
            if (is_paused) {
              vid.play();
            }
          }
          else {
            if (!is_paused) {
              vid.pause();
            }
          }
        }
     });
     //Fade in the multi-col cards
     $('.node-campaign-card-multi-column').not('.animated').each(function() {
       multiColumnAnimation($(this));
     });

    });
    if ($('.has-mute-button').length != 0) {
      $('.field-name-field-mute').click(function(){
        muteAmbientVideo();
      });
     }

   });

   //This is called through the ajax commands sent from the server.
   Drupal.behaviors.tp_auto_changer = {
     attach: function (context, settings) {
       $('body').once('InvokeOthersCampaign', function(){
         $(document).delegate('article.node-campaign-page.view-mode-full', 'InvokeOthers', function(ev, data) {
           if ( window.newTapWidgets == true ) {
             TP.Bootstrapper && new TP.Bootstrapper().start();
             TAP.Widget      && TAP.Widget.addWidgets();
             window.newTapWidgets = false;
           }
           //INIT Facebook again
           //Targeting the slide that was just loaded
           if(typeof FB != 'undefined') {
             FB.XFBML.parse(document.getElementById('slider_'+(window.campaignTray+1)));
           }
           //Check for ads and try to display the
           $('.node-campaign-page .block-boxes-ga_ad').each(function(){
             //check if the ad has loaded
             if( !$.trim( $(this).find('.boxes-box-content div').html() ).length ) {
               //try to display it
               googletag.display($(this).find('.boxes-box-content div').attr('id'));
             }
           });
           //Trigger a resize for styling to take effect on media cards
           $(window).trigger('resize');

           //Check if the card that was just loaded has jumpto links
           jumptocheck(window.campaignTray + 1);
         });
       });
     }
   };

  /**
  * Preloading the background images
  */
  var campaignPreload = function() {
    var imgs = Drupal.settings.campaignPreload;
    window.preloaded = 0;

    //If there are no images to preload just load campaignOnload
    if(window.preloaded >= Drupal.settings.campaignPreload.length) {
      campaignOnload();
    } else {
      //Loop through image urls loading them into the browser cache
      for(var i = 0; i < imgs.length; i++) {
        window['campaignImage'+i] = new Image();
        window['campaignImage'+i].src = imgs[i];
        window['campaignImage'+i].onload = campaignOnload;
      }
    }
    //Show the multi-col card if its part of the initial load
    $('.node-campaign-card-multi-column').not('animated').find('.item').css('opacity' , 1);

    //Play the video if its part of initial load and in viewport
    if (jQuery('.videoBG_wrapper video').length != 0) {
        jQuery('.videoBG_wrapper video')[0].play();
    }


  };

  var campaignOnload = function() {
    window.preloaded++;

    //Check if all the images have been preloaded then let the trays load
    if(window.preloaded >= Drupal.settings.campaignPreload.length &&
      Drupal.settings.campaignItemCount > 0) {
      window.campaignTray = 0;
      $(window).bind('scroll.campaignScroll', function(e) {

        var wrap = $('article.node-campaign-page.view-mode-full'),
          $win = $(window);
        var wrapBot = wrap.offset().top + wrap.height();
        var viewport = {
          top : $win.scrollTop(),
          left : $win.scrollLeft(),
          bottom : $win.scrollTop() + $win.height()
        };

        //garbage collection
        if(Drupal.settings.campaignItemCount <= window.campaignTray || isNaN(window.campaignTray) ) {
          $(window).unbind('scroll.campaignScroll');
          delete(window.campaignTray);
        } else {
          if(viewport.bottom + 1000 >= wrapBot){
            Drupal.ajax['autocampaign_ajax'].autoCampaign();
          }
        }

      });

      jumptocheck(0);
      jumptocheck(1);
      //check if page has room to scroll
      //Need to check for terms of use cookie
      //If it is set it will show and hide causing the page to give a increased
      //body height
      //770 is the height of featured campagign and footer
      var extraheight = 770;
      if(document.cookie.search('tou') != -1){
        extraheight += 85;
      }
      if (($("body").height() - extraheight) <= $(window).height()) {
        window.campaignInterval = setInterval("campaignBodyCheck()",500);
      }

      delete(window.preloaded);

    }
  };

  //if a slide has internal links load all the slides so that they
  //can link to the correct card
  var jumptocheck = function(number) {
    $('#slider_'+number).find('a').each(function(){
      var tmphref = $(this).attr('href');
      if (typeof tmphref == 'undefined') {
        return false;
      }
      var tmpjump = tmphref.indexOf("#");
      if(tmpjump != -1 && tmpjump != tmphref.length && typeof window.jumptoIntervalid == "undefined") {
        //Kill the scroll
        $(window).unbind('scroll.campaignScroll');
        //Start an interval
        window.jumptoIntervalid = setInterval("jumptoInterval()",250);
      }
    });
  };

  /**
   * Override the ajax error message on campaign pages to console log.
   */
  Drupal.ajax.prototype.error = function (xmlhttprequest, uri, customMessage) {
    console.log(Drupal.ajaxError(xmlhttprequest, uri, customMessage));
    // Remove the progress element.
    if (this.progress.element) {
      $(this.progress.element).remove();
    }
    if (this.progress.object) {
      this.progress.object.stopMonitoring();
    }
    // Undo hide.
    $(this.wrapper).show();
    // Re-enable the element.
    $(this.element).removeClass('progress-disabled').removeAttr('disabled');
    // Reattach behaviors, if they were detached in beforeSerialize().
    if (this.form) {
      var settings = this.settings || Drupal.settings;
      Drupal.attachBehaviors(this.form, settings);
    }
  };
})(jQuery, Drupal, this, this.document);


/**
 * Needs to be a separate function so the set interval can find it.
 */
function campaignBodyCheck() {
  //Check if the body height is still not up to window height
  //AND if there are no more trays to load
  if ((jQuery("body").height() - 770 <= jQuery(window).height()) &&
    (Drupal.settings.campaignItemCount > window.campaignTray)) {
    Drupal.ajax['autocampaign_ajax'].autoCampaign();
  } else {
    clearInterval(window.campaignInterval);
  }
}

/**
 * Start loading the campaigns until there are no more.
 * Happening when a jumpto link is loaded.
 */
function jumptoInterval() {
  Drupal.ajax['autocampaign_ajax'].autoCampaign();
  if(Drupal.settings.campaignItemCount <= window.campaignTray) {
    delete(window.campaignTray);
    clearInterval(window.jumptoIntervalid);
  }
}

/**
 * Checks to see whether a certain portion of the element is in viewport
 * x-> width, y-> height, 0.5 -> 50% of the height or width is visible
 */

jQuery.fn.isInViewport = function(x, y) {
  if(x == null || typeof x == 'undefined') x = 1;
    if(y == null || typeof y == 'undefined') y = 1;

    var win = jQuery(window);

    var viewport = {
        top : win.scrollTop(),
        left : win.scrollLeft()
    };
    viewport.right = viewport.left + win.width();
    viewport.bottom = viewport.top + win.height();

    var height = this.outerHeight();
    var width = this.outerWidth();

    if(!width || !height){
        return false;
    }

    var bounds = this.offset();
    bounds.right = bounds.left + width;
    bounds.bottom = bounds.top + height;

    var visible = (!(viewport.right < bounds.left || viewport.left > bounds.right || viewport.bottom < bounds.top || viewport.top > bounds.bottom));

    if(!visible){
        return false;
    }

    var deltas = {
        top : Math.min( 1, ( bounds.bottom - viewport.top ) / height),
        bottom : Math.min(1, ( viewport.bottom - bounds.top ) / height),
        left : Math.min(1, ( bounds.right - viewport.left ) / width),
        right : Math.min(1, ( viewport.right - bounds.left ) / width)
    };

    return (deltas.left * deltas.right) >= x && (deltas.top * deltas.bottom) >= y;
}

/*
 * Fade in the multicolumn cards once in viewport
 */

function multiColumnAnimation($container) {
  var i = 0;
  var item_number = $container.find('.item').length;
  $container.find('.item').each(function(index) {
    if (jQuery(this).isInViewport(null,0.9)) {
      jQuery(this).animate({opacity: 1},500, function() {
        if (++i == item_number) {
          $container.addClass('animated');
        }
      });
    }
  });
}

/*
 * Mute/Unmute all ambient videos on the page
 */

function muteAmbientVideo() {
  jQuery('.videoBG_wrapper video').each(function() {
    if(!jQuery(this).hasClass('muted')) {
      //Mute
      jQuery(this).prop('muted', true).addClass('muted');
      window.muted = true;
    }
    else if(window.muted) {
      //Unmute
      jQuery(this).prop('muted', false).removeClass('muted');
    }
  });
}

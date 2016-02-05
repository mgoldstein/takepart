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
     var traynumb = window.campaignTray + 2;
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
     //pause the video when less than 70% is in viewport
     $(window).bind('scroll', function() {
      jQuery('.videoBG_wrapper video').each(function(index){
        //Get the card height since the video itself could be a different height
        var vid = jQuery(this).get(index);
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
      });
    });

   });

   //This is called through the ajax commands sent from the server.
   Drupal.behaviors.tp_auto_changer = {
     attach: function (context, settings) {
       $(document).delegate('article.node-campaign-page.view-mode-full', 'InvokeOthers', function(ev, data) {
         if ( window.newTapWidgets == true ) {
           TP.Bootstrapper && new TP.Bootstrapper().start();
           TAP.Widget      && TAP.Widget.addWidgets();
           window.newTapWidgets = false;
         }
         //INIT Facebook again
         window.fbAsyncInit();

         //Trigger a resize for styling to take effect on media cards
         $(window).trigger('resize');
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

        if(viewport.bottom + 1000 >= wrapBot){
          Drupal.ajax['autocampaign_ajax'].autoCampaign();
        }
        //garbage collection
        if(Drupal.settings.campaignItemCount <= window.campaignTray) {
          $(window).unbind('scroll.campaignScroll');
          delete(window.campaignTray);
        }
      });

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

})(jQuery, Drupal, this, this.document);


//Needs to be a separate function so the set interval can find it.
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

//Checks to see whether a certain portion of the element is in viewport
//x -> width, y -> height, 0.5 -> 50% of the height or width is visible
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

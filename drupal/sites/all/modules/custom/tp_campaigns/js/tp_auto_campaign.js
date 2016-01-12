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
     var traynumb = window.campaignTray + 2;
     ajax.url = ajax.element_settings.url = ajax.options.url = '/autocampaign/'+Drupal.settings.autoloadCampaigns+'/'+traynumb;

     // Do not perform another ajax command if one is already in progress.
     if (ajax.ajaxing) {
       return false;
     }

     try {
       window.newTapWidgets = true;
       $.ajax(ajax.options);
       window.campaignTray++;
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
   });

   //This is called through the ajax commands sent from the server.
   Drupal.behaviors.tp_auto_changer = {
     attach: function (context, settings) {
       $(document).delegate('article.node-campaign-page.view-mode-full', 'TAPInvoke', function(ev, data) {
         if ( window.newTapWidgets == true ) {
           TP.Bootstrapper && new TP.Bootstrapper().start();
           TAP.Widget      && TAP.Widget.addWidgets();
           window.newTapWidgets = false;
         }
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
      delete(window.preloaded);
    }
  }

})(jQuery, Drupal, this, this.document);

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

     try {
       window.newTapWidgets = true;
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
   custom_settings.url = '/autocampaign/'+Drupal.settings.autoloadCampaigns;
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
     for(var i = 0; i < imgs.length; i++) {
       window['campaignImage'+i] = new Image();
       window['campaignImage'+i].src = imgs[i];
       window['campaignImage'+i].onload = function(){
         window.preloaded++;
         //Check if all the images have been preloaded then let the trays load
         if(window.preloaded == Drupal.settings.campaignPreload.length) {
           Drupal.ajax['autocampaign_ajax'].autoCampaign();
           delete(window.preloaded);
         }
       };
     }
   };

})(jQuery, Drupal, this, this.document);

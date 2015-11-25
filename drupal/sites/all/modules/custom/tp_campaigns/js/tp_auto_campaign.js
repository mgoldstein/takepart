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
     Drupal.ajax['autocampaign_ajax'].autoCampaign();
   });

   Drupal.behaviors.tp_auto_changer = {
     attach: function (context, settings) {
       $(document).delegate('article.node-campaign-page.view-mode-full', 'TAPInvoke', function(ev, data) {
         console.log('TAPPING');
         if ( window.newTapWidgets == true ) {
           TP.Bootstrapper && new TP.Bootstrapper().start();
           TAP.Widget      && TAP.Widget.addWidgets();
           window.newTapWidgets = false;
         }
       });
     }
   }
  // Drupal.behaviors.tp_auto_changer = {
  //   attach: function(context, settings) {
  //     var ele = $('article.node-campaign-page.view-mode-full', context);
  //     if(!ele.hasClass('autoloadCampaigns-processed')) {
  //       var camps = JSON.stringify(Drupal.settings.autoloadCampaigns.targets);
  //       var node = Drupal.settings.autoloadCampaigns;
  //       $.get( "/autocampaign/"+node)
  //         .done(function( data ) {console.log(data);
  //           $.map(data,function(val,i){console.log(val);
  //             //Add the ajax form settingss
  //             if(val.command == "insert") {
  //               //Append the other slides
  //               ele.once('autoloadCampaigns').append(val.data);
  //               //Reset behaviors
  //               Drupal.attachBehaviors();
  //             } else if(val.command == "alert") {
  //               ele.once('autoloadCampaigns');
  //               alert(val.text);
  //             } else if(val.command == 'settings'){
  //               jQuery.extend(Drupal.settings, val.settings);
  //             }
  //           });
  //         });
  //     }
  //   }
  // };
})(jQuery, Drupal, this, this.document);

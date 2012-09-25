(function ($) {

  Drupal.behaviors.signaturesBlock = {
    attach: function(context) {
      // There must be AJAX enabled views on the page.
      if (!Drupal.settings || !Drupal.settings.views || !Drupal.settings.views.ajaxViews) {
        return;
      }
      
      // onLoad and onAjax
      var container = $('.field-name-field-signatures, .block-boxes-view-name-pledge_signature_block');
      
      container.once('signature-block-init', _init);
      
      // onLoad only
      function _init(){
        // variables
        var element = $(this);
        
        // onLoad
        $.each(Drupal.settings.views.ajaxViews, function(i, settings) {
          if (settings.view_name !== 'petition_signature_list' && settings.view_name !== 'pledge_signature_block') {
            return;
          }
          var view = '.view-dom-id-' + settings.view_dom_id;
          
          // if a sub-view, exit
          if ($(view).parents('.view').size()){
            return;
          }
          
          // Retrieve the path to use for views' ajax. (is this needed?)
          var ajax_path = Drupal.settings.views.ajax_path;

          // If there are multiple views this might've ended up showing up multiple times. (is this needed?)
          if (ajax_path.constructor.toString().indexOf("Array") != -1) {
            ajax_path = ajax_path[0];
          }
          var element_settings = {
            url: ajax_path,
            submit: settings,
            event: 'refresh_signature_list',
            selector: view,
            progress: { type: 'throbber' }
          };
          var ajax = new Drupal.ajax(false, container, element_settings);
        });
      }
    }
  };
  
  var updateSignatureState = function (response) {
    var all_classes = [
      'signature-node-unsigned',
      'signature-node-thank-you',
      'signature-node-signed',
      'signature-node-closed',
      'signature-node-inactive'
    ].join(' ');
    for (var nid in response) {
      var node = response[nid];

      // Adjust the visibility state of the node.
      var div_id = '#node-' + nid;
      var state_class = 'signature-node-' + node.state;
      $(div_id).removeClass(all_classes).addClass(state_class);
    
      // Trigger the viewed event
      if (jQuery.cookie(node.view_latch) == null) {
        $(div_id).trigger('signature_form_view', [node.title]);
        jQuery.cookie(node.view_latch, 1, {path:'/'});
      }
      
      // Refresh any signature lists
      $('.field-name-field-signatures, .block-boxes-view-name-pledge_signature_block').trigger('refresh_signature_list');

      // Adjust the selected tab state of the petition
      var tab = '.signature-tab-' + node.state;
      $(tab, $(div_id)).each(function () {
        $(this).data('horizontalTab').tabShow();
      });

      var summary = '#' + node.summary_id;
      $(summary).each(function () {
        $('.signature-progress-percent', this).text(node.percent + '%');
        $('.signature-progress-bar', this).attr('src', node.bar).attr('alt',
          node.percent + '% Complete');
        $('.signature-progress-count', this).html(node.progress);
      });
    }
  };

  Drupal.behaviors.signatureStates = {
    attach: function (context, settings) {
      if ('signature' in settings && 'submitted_by' in settings.signature) {
        if (addthis) {
          addthis.update('config', 'ui_email_from',
            settings.signature.submitted_by);
        }
      }
      if ('signature' in settings && 'progress' in settings.signature) {
        updateSignatureState(settings.signature.progress);
      }
      else {
        // Update all the progress blocks on the page
        var nodes = Array();
        $('.node.signature-list').once('signature-init', function (index) {
          nodes[index] = $(this).attr('nid');
        });
        if (nodes.length > 0) {
          $.get('/ajax/signature/node/' + nodes.join(','), null, updateSignatureState);
        }
      }
    }
  };
})(jQuery);

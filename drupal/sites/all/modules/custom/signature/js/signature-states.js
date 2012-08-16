(function ($) {

  Drupal.behaviors.signatureRefreshList = {};
  Drupal.behaviors.signatureRefreshList.attach = function() {
    if (Drupal.settings && Drupal.settings.views && Drupal.settings.views.ajaxViews) {
      // Retrieve the path to use for views' ajax.
      var ajax_path = Drupal.settings.views.ajax_path;

      // If there are multiple views this might've ended up showing up multiple times.
      if (ajax_path.constructor.toString().indexOf("Array") != -1) {
        ajax_path = ajax_path[0];
      }
      
      $.each(Drupal.settings.views.ajaxViews, function(i, settings) {
        if (settings.view_name == 'petition_signature_list') {
          var view = '.view-dom-id-' + settings.view_dom_id;

          var element_settings = {
            url: ajax_path,
            submit: settings,
            event: 'refresh_signature_list',
            selector: view,
            progress: { type: 'throbber' }
          };

          $(view).filter(':not(.signature-list-refresh-processed)')
            // Don't attach to nested views. Doing so would attach multiple behaviors
            // to a given element.
            .filter(function() {
              // If there is at least one parent with a view class, this view
              // is nested (e.g., an attachment). Bail.
              return !$(this).parents('.view').size();
            })
            .each(function() {
              // Set a reference that will work in subsequent calls.
              var target = this;
              $(this)
                .addClass('signature-list-refresh-processed')
                // Process pager, tablesort, and attachment summary links.
                .closest('.field-name-field-signatures')
                .each(function () {
                  var viewData = {};
                  // Construct an object using the settings defaults and then overriding
                  // with data specific to the link.
                  $.extend(
                    viewData,
                    settings
                  );
                  element_settings.submit = viewData;
                  var ajax = new Drupal.ajax(false, this, element_settings);
                }); // .each function () {
          }); // $view.filter().each
        } // if view_name == 'petition_signature_list'
      }); // .each Drupal.settings.views.ajaxViews
    } // if
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

      // Reload any signature lists
      $('.field-name-field-signatures.initial-signature-refresh-processed', $(div_id))
        .once('submit-signature-refresh')
        .trigger('refresh_signature_list');
      $('.field-name-field-signatures', $(div_id))
        .once('initial-signature-refresh')
        .trigger('refresh_signature_list');

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
          $.get('/ajax/signature/node/' + nodes.join(','), null,
            updateSignatureState);
        }
      }
    }
  };
})(jQuery);

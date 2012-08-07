(function ($) {

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

      // Adjust the visibility state of the petition
      var div_id = '#node-' + nid;
      var state_class = 'signature-node-' + node.state;
      $(div_id).removeClass(all_classes).addClass(state_class);
    
      // Trigger the viewed event
      if (jQuery.cookie(node.view_latch) == null) {
        $(div_id).trigger('signature_form_view', [node.title]);
        jQuery.cookie(node.view_latch, 1, {path:'/'});
      }

      // Adjust the selected tab state of the petition
      var tab = '.signature-tab-' + node.state;
      $(tab).each(function () {
        $(this).data('horizontalTab').tabShow();
      });

      var summary = '#' + node.summary_id;
      $(summary).each(function () {
        $('.signature-progress-percent', this).text(node.percent + '%');
        $('.signature-progress-bar', this).attr('src', node.bar).attr('alt',
          node.percent + '% Complete');
        $('.signature-progress-count', this).text(node.progress);
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

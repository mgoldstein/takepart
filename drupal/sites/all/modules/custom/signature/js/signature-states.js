(function ($) {

  var extractClassValue = function (classes, startsWith) {
    for (var i=0; i<classes.length; i++) {
      var value = classes[i]
      if (value.length > startsWith.length) {
        if (value.substr(0, startsWith.length) == startsWith) {
          return value.substring(startsWith.length);
        }
      }
    }
    return '';
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

      // Adjust the visibility state of the petition
      var div_id = '#node-' + nid;
      var state_class = 'signature-node-' + node.state;
      $(div_id).removeClass(all_classes).addClass(state_class);
    
      // Trigger the viewed event
      if (jQuery.cookie(node.view_latch) == null) {
        $(div_id).trigger('signature_form_view', [node.title]);
        jQuery.cookie(node.view_latch, 1, {path:'/'});
      }

      // Reload any signature lists
      var lists = Array();
      $('.view.view-petition-signature-list').each(function (index) {
        var classes = $(this).attr('class').split(/\s+/);
        var dom_id = extractClassValue(classes, 'view-dom-id-');
        var display_id = extractClassValue(classes, 'view-display-id-');
        $.ajax({
          type: "POST",
          url: "/views/ajax",
          data: {
            page: 1,
            pager_element: 0,
            view_args: nid,
            view_base_path: "node/" + nid,
            view_display_id: display_id,
            view_dom_id: dom_id,
            view_name: "petition_signature_list",
            view_path: "node/" + nid, 
          }
        }).done(function (response) {
          for (var i=0; i<response.length; i++) {
            var chunk = response[i];
            console.log(chunk);
            if (chunk.command == 'insert' && chunk.method == 'replaceWith') {
              $(chunk.selector).replaceWith(chunk.data);
            }
          }
        });
      });

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

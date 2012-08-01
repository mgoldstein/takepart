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
      var div_id = '#node-' + nid;
      var node = response[nid];
      var state_class = 'signature-node-' + node.state;
      $(div_id).removeClass(all_classes).addClass(state_class);
    
      var tab = '.signature-tab-' + node.state;
      $(tab).each(function () {
        $(this).data('horizontalTab').tabShow();
      });

      var summary = '#' + node.summary_id;
      $(summary).each(function () {
        $(this).find('span.signature-progress-percent').text(node.percent + '%');
        $(this).find('img.signature-progress-bar').attr('src', node.bar).attr(
          'alt', node.percent + '% Complete');
        $(this).find('p.signature-progress-count').text(node.progress);
      });
    }
  };

  Drupal.behaviors.signatureStates = {
    attach: function (context, settings) {
      if ('signature' in settings && 'progress' in settings.signature) {
        updateSignatureState(settings.signature.progress);
      }
      else {
        var nodes = Array();
        $('div.node.signature-list').once('signature-init', function (index) {
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

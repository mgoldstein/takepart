// Tabs on petitions should all be the same height.
(function ($) {
  Drupal.behaviors.sameheight = {
    attach: function (context, settings) {
      $('.node-petition-action .horizontal-tabs').once('sameheight', function () {
        $(this).sameheight({
          source_selector: 'fieldset.same-height-source > .fieldset-wrapper',
          adjust_selector: 'fieldset.same-height-adjust > .fieldset-wrapper'
        });
      });
    }
  }
})(jQuery);

// Separate the recipients of a petiion with commas.
(function ($) {
  Drupal.behaviors.recipientlist = {
    attach: function (context, settings) {
      $('.field-name-field-petition-recipient').once('recipientlist', function () {
        $('.field-item', this).not(':last').append(', ');
      });
    }
  }
})(jQuery);

// Widgetize the read more / read less link.
(function ($) {
  Drupal.behaviors.moreorless = {
    attach: function(context, settings) {
      $('.more-or-less-container').once('moreorless', function () {
        $(this).moreorless();
      });
    }
  };
})(jQuery);

// The signature list block on petition and pledges should be refreshed when the
// page is loaded.
(function ($) {
  Drupal.behaviors.signaturelist = {
    attach: function (context, settings) {
      var container = '.block-boxes-view-name-petition_signature_block';
      $(container).once('signaturelist', function () {
        $(this).signaturelist({
          'view_name': 'petition_signature_block', 
        });
        if (Drupal.settings && Drupal.settings.views
        && Drupal.settings.views.ajaxViews) {
          $(this).signaturelist('connect', Drupal.settings.views);
        }
      });
      container = '.block-boxes-view-name-pledge_signature_block';
      $(container).once('signaturelist', function () {
        $(this).signaturelist({
          'view_name': 'pledge_signature_block', 
        });
        if (Drupal.settings && Drupal.settings.views
        && Drupal.settings.views.ajaxViews) {
          $(this).signaturelist('connect', Drupal.settings.views);
        }
      });
    }
  }
})(jQuery);

// Widgetize the signature form for easier control of the display disclaimer,
// in-field labels and selectable address.
(function ($) {
  Drupal.behaviors.signatureform = {
    attach: function (context, settings) {
      $('.signature-form').once('signatureform', function () {
        $(this).displaydisclaimer();
        $(this).infieldlabels();
        $(this).selectableaddress();
      });
    }
  }
})(jQuery);

// Widgetize the content node to manage updating signature collection progress
// and state.
(function ($) {
  Drupal.behaviors.signatureprogress = {
    attach: function (context, settings) {
      $('.signature-list').once('signatureprogress', function () {
        $(this).signatureprogress({ nid: $(this).attr('nid') });
      });
      if (settings.signature && settings.signature.submission) {
        console.log(settings.signature.submission.result);
        $('.signature-list').signatureprogress('update',
          settings.signature.submission.result);
      }
    }
  }
})(jQuery);

// Bind metrics event handlers to node that collection signatures.
(function ($) {
  Drupal.behaviors.signaturemetrics = {
    attach: function (context, settings) {
      $('.signature-list').once('signaturemetrics', function () {
        $(this).signaturemetrics();
        // Fire off a viewed event for each action on the page.
        if (settings.signature && settings.signature.nodes.full) {
          for (node in settings.signature.nodes.full) {
            var latch = 'viewed-signature-action-' + node;
            if ($.cookie(latch) == null) {
              $.cookie(latch, 1, {path:'/'});
              $('.' + node + '.view-mode-full').trigger('track_view');
            }
          }
        }
      });
    }
  };
})(jQuery);

// Bind a click event handler to the Take Action button to report external
// actions to TAB
(function ($) {
  Drupal.behaviors.externalaction = {
    attach: function (context, settings) {
      $('.node-action.view-mode-full').once('externalaction', function () {
        $(this).externalaction({ nid: $(this).attr('nid') });
      });
    }
  };
})(jQuery);

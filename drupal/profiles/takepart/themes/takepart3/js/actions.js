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
        //$(this).infieldlabels();
        // $(this).selectableaddress();
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

// Not sure about all those redundant self-executing anonymous functions up there
(function(window, $, undefined) {

// inside/outside US switch
var address_check = function(form) {
  var $form;
  if ( form != undefined ) {
    $form = $(form);
  } else {
    $form = $('form');
  }

  $form.each(function() {
    var val = $('input[name="field_sig_address_toggle[und]"]:checked', this).val();
    $('.group_address_tabs .field-group-format:not(.group_' + val + '_us)', this).hide();
    $('.group_address_tabs .field-group-format.group_' + val + '_us', this).show();
  });
};

Drupal.behaviors.addresscheck = {
  attach: function (context, settings) {
    $('.signature-form').once('addresscheck', function() {
      var form = this;
      // Hook for observing inside/outside changes
      $('input[name="field_sig_address_toggle[und]"]', this)
        .bind('change', function() {
          address_check(form)
        });

        address_check(form)
    });
  }
};

// Document ready
$(function() {

  // give pledge actions the same class as petition actions for styling
  // TODO: fix in the html and remove this
  $('.pledge_action, .petition_action, .embedaction-wrapper').addClass('petition_pledge_action');

  // Uses css3 to rotate stuff.
  // TODO: put this in its own plugin file
  $.fn.protate = function(deg) {
    var rotate = 'rotate(' + deg + 'deg)';
    /*var deg2radians = Math.PI * 2 / 360;
    var rad = deg * deg2radians ;
    var costheta = Math.cos(rad);
    var sintheta = Math.sin(rad);

    var m11 = costheta;
    var m12 = -sintheta;
    var m21 = sintheta;
    var m22 = costheta;
    var matrixValues = 'M11=' + m11 + ', M12='+ m12 +', M21='+ m21 +', M22='+ m22;*/

    return this
      .css({
        '-webkit-transform': rotate,
        '-moz-transform': rotate,
        '-ms-transform': rotate,
        'transform': rotate
      });
      //.css('filter', 'progid:DXImageTransform.Microsoft.Matrix(sizingMethod=\'auto expand\','+matrixValues+')')
      //.css('-ms-filter', 'progid:DXImageTransform.Microsoft.Matrix(SizingMethod=\'auto expand\','+matrixValues+')');
  };

  // Add two elements to make a pie chart. ie9+
  // TODO: put this in its own plugin file
  $.fn.pie = function(params) {
    if ( $.browser.msie && $.browser.version < 9 ) return this;

    var settings = $.extend({
      prepend: 'pie_'
    }, params || {});

    var prepend = settings.prepend;

    return this.each(function() {
      var $this = $(this)
        .addClass(prepend + 'container')

      if ($this.css('position') != 'relative' && $this.css('position') != 'absolute'){
        $this.css({
          position: 'relative'
        });
      }
      var startp = settings.start || $this.data('pie-start') || 0;

      var endp = 100;
      if ( settings.end != undefined ) {
        endp = settings.end;
      } else if ( $this.data('pie-end') != undefined ) {
        endp = $this.data('pie-end');
      }
      endp = parseInt(endp);
      if ( endp > 100 ) endp = 100;

      var $pie = $('<div/>').addClass(prepend + 'slice_container').appendTo($this);
      var $slice = $('<div/>');
      var $slice_fill = $('<div/>');
      var w = $pie.width();
      var slice_css = {
        clip: 'rect(0,' + w/2 + 'px,' + w + 'px,0)',
        position: 'absolute',
        height: '100%',
        width: '100%'
      };

      startp = startp - (endp/2);

      $pie
        .css({
          clip: 'rect(0,' + w + 'px,' + w + 'px,' + w/2 + 'px)',
          position: 'absolute'
        })
        .protate(startp / 100 * 360)
        ;


      $slice
        .addClass(prepend + 'slice ')
        .protate(180)
        .css(slice_css)
        .hide()
        ;

      $slice_fill
        .addClass(prepend + 'slice ' + prepend + 'fill')
        .protate(endp / 100 * 360)
        .css(slice_css)
        ;

      $this
        .prepend(
          $pie
            .append($slice)
            .append($slice_fill)
        );

      if ( endp > 50 ) {
        $slice.show();
        $pie
          .css({
            clip: 'rect(auto,auto,auto,auto)'
          })
          ;
      }
    });
  };

  // run the pie plugin with special params
  $('.signature-progress-percent').each(function() {
    var $this = $(this);
    var end = parseInt($this.find('.percentage').html());
    if (end > 100) {
      end = 100;
    } else if ( end > 0 && end < 5 ) {
      end = 5;
    }
    $this.pie({start: 25, end: 100 - end});
  });
});
})(window, jQuery);

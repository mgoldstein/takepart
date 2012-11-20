// Add analytics to the TakePart JavaScript name space
if (typeof tp === 'undefined' || !tp) { var tp = {}; }
if (!tp.analytics) { tp.analytics = {'events': {}}; } 

(function ($) {

  /**
   * Analytics tracking widget.
   */
  var methods = {
    _create: function (options) {
      this.options = $.extend({
      }, options);
    },
    fireEvent: function (event) {
      if (event.name in tp.analytics.events) {
        if (event.scope === 'session') {
          if ($.cookie(event.latch) == null) {
            $.cookie(event.latch, 1, {path:'/'});
            tp.analytics.events[event.name].apply(this, Array(event.args));
          }
        }
        else if (event.scope === 'page') {
          if (!$('body').hasClass(event.latch)) {
            $('body').addClass(event.latch);
            tp.analytics.events[event.name].apply(this, Array(event.args));
          }
        }
        else {
          tp.analytics.events[event.name].apply(this, Array(event.args));
        }
      }
    },
    fireInstance: function (name) {
      if (Drupal.settings.analytics && Drupal.settings.analytics.instances) {
        if (name in Drupal.settings.analytics.instances) {
          var event = Drupal.settings.analytics.instances[name];
          methods['fireEvent'].apply(this, Array(event));
        }
      }
    },
    fireShareInstance: function (name, method) {
      if (Drupal.settings.analytics && Drupal.settings.analytics.instances) {
        if (name in Drupal.settings.analytics.instances) {
          var event = Drupal.settings.analytics.instances[name];
          event.args.share_method = method;
          methods['fireEvent'].apply(this, Array(event));
        }
      }
    }
  };

  $.fn.analyticstracking = function (method) {
    if (methods[method]) {
      var args = Array.prototype.slice.call(arguments, 1);
      $(this).each(function () {
        var obj = $.data(this, 'analyticstracking');
        methods[method].apply(obj, args);
      });
    }
    else if (typeof method === 'object' || !method) {
      var args = arguments;
      $(this).each(function () {
        var obj = $(this)
        obj.element = this;
        $.data(this, 'analyticstracking', obj);
        methods._create.apply(obj, args);
      });
    }
    else {
      $.error('Method ' + method + ' does not exist on analytics tracking objects.');
    }
    return this;
  };

  $(document).ready(function () {
    // Initialize analytics tracking for the page
    $('body').once('analyticstracking', function () {
      $('body').analyticstracking();
    });
    // Fire off any passed in events.
    if (Drupal.settings.analytics && Drupal.settings.analytics.events) {
      for (var index in Drupal.settings.analytics.events) {
        var e = Drupal.settings.analytics.events[index];
        $('body').analyticstracking('fireEvent', e);
      }
    }
  });

})(jQuery);

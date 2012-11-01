(function ($) {
  var methods = {
    // Set the default options and initialize the wrapper.
    _create: function (options) {
      this.options = $.extend({
        'expanded': false
      }, options);
      if (methods.init) {
        methods.init.apply(this);
      }
    },
    // Bind the event handlers and set the initial state of the wrapper.
    init: function () {
      this.header = $('.header', this.element);
      this.header.bind('click.embedaction', {
        container: this,
      }, methods._click);
      this.header.bind('mouseenter.embedaction', {
        container: this,
      }, methods._hover);
      this.header.bind('mouseleave.embedaction', {
        container: this,
      }, methods._hover);
      this.toggle = $('.switch', this.element);
      this.toggle.bind('click.embedaction', {
        container: this,
      }, methods._click);
      if (this.options['expanded']) {
        methods.expand.apply(this);
      }
      else {
        methods.collapse.apply(this);
      }
    },
    // Click handler (for expanding and collapsing the action).
    _click: function(event) {
      var container = event.data.container;
      var target = $(event.target);
      event.preventDefault();
      if (container.hasClass('collapsed')) {
        methods.expand.apply(container);
      }
      else if (target.hasClass('switch')) {
        methods.collapse.apply(container);
      }
    },
    // Hover handler for the action header.
    _hover: function(event) {
      var container = event.data.container;
      var action = (event.type == "mouseenter" ? "add": "remove") + "Class";
      container.header[action]("highlight");
    },
    // Expand and show the action.
    expand: function () {
      this.removeClass('collapsed').addClass('expanded');
    },
    // Collapse and hide the action.
    collapse: function () {
      this.removeClass('expanded').addClass('collapsed');
    },
    // Destroy the wrapper and return the element back to its original state.
    destroy: function() {
      this.header.unbind('.embedaction');
      this.toggle.unbind('.embedaction');
    }
  };

  $.fn.embedaction = function (method) {
    if (methods[method]) {
      // Cut off method name.
      var args = Array.prototype.slice.call(arguments, 1);
      // Call the method for each wrapper.
      $(this).each(function () {
        obj = $.data(this, 'embedaction');
        methods[method].apply(obj, args);
      });
    }
    else if (typeof method === 'object' || !method) {
      // Create each wrapper.
      var args = arguments;
      $(this).each(function () {
        obj = $(this);
        obj.element = this;
        $.data(this, 'embedaction', obj);
        methods._create.apply(obj, args);
      });
    }
    else {
      $.error('Method ' + method + ' does not exist on embedaction objects.');
    }
    return this;
  };
})(jQuery);

(function ($) {
  Drupal.behaviors.embedaction = {
    attach: function (context, settings) {
      $('.embedaction-wrapper').once('embedaction', function () {
        $(this).embedaction({expanded: !$(this).hasClass('collapsed')});
      });
    }
  }
})(jQuery);

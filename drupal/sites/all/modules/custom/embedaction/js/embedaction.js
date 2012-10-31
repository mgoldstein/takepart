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
      this.header = $('.embedaction-header', this.element);
      this.header.bind('click.embedaction', {
        container: this,
        open: true
      }, methods._click);
      this.header.bind('mouseenter.embedaction', {
        container: this,
      }, methods._hover);
      this.header.bind('mouseleave.embedaction', {
        container: this,
      }, methods._hover);
      this.content = $('.embedaction-content', this.element);
      $('.embedaction-divider > a', this.content).bind('click.embedaction', {
        container: this,
        open: false
      }, methods._click);
      this.options['expanded'] ? methods.expand.apply(this)
        : methods.collapse.apply(this);
    },
    // Click handler (for expanding and collapsing the action).
    _click: function(event) {
      var container = event.data.container;
      event.preventDefault();
      event.data.open ?  methods.expand.apply(container)
        : methods.collapse.apply(container);
    },
    // Hover handler for the action header.
    _hover: function(event) {
      var container = event.data.container;
      var action = (event.type == "mouseenter" ? "add": "remove") + "Class";
      container.header[action]("highlight");
    },
    // Expand and show the action.
    expand: function () {
      var self = this;
      this.content.slideDown('fast', function() {
        $('.embedaction-divider > a', self.content).show();
      });
    },
    // Collapse and hide the action.
    collapse: function () {
      var self = this;
      this.content.slideUp('fast', function() {
        $('.embedaction-divider > a', self.content).hide();
      });
    },
    // Destroy the wrapper and return the element back to its original state.
    destroy: function() {
      this.header.unbind('.embedaction');
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
      $('.embedaction-wrapper.expanded').once('embedaction', function () {
        $(this).embedaction({expanded: true});
      });
      $('.embedaction-wrapper.collapsed').once('embedaction', function () {
        $(this).embedaction({expanded: false});
      });
    }
  }
})(jQuery);

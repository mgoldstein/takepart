/**
 * Make content elements all the same height.
 */
(function ($) {
  var methods = {
    _create: function (options) {
      this.options = $.extend({
        'source_selector': '.same-height-source',
        'adjust_selector': '.same-height-adjust',
        'minimum-height': 250
      }, options);
      methods.adjust.apply(this);
    },
    adjust: function () {
      var source = $(this.options['source_selector'], this.element);
      if (source.length > 0) {
        var height = source.height();
        if (height < this.options['minimum_height']) {
          height = this.options['minimum_height'];
        }
        $(this.options['adjust_selector'], this.element).each(function (index) {
          if ($(this).height() > height) {
            $(this).height(height).css('overflow-y', 'scroll');
          }
        });
      }
    }
  };
  $.fn.sameheight = function (method) {
    if (methods[method]) {
      // Cut off method name.
      var args = Array.prototype.slice.call(arguments, 1);
      // Call the method for each wrapper.
      $(this).each(function () {
        obj = $.data(this, 'sameheight');
        methods[method].apply(obj, args);
      });
    }
    else if (typeof method === 'object' || !method) {
      // Create each wrapper.
      var args = arguments;
      $(this).each(function () {
        obj = $(this);
        obj.element = this;
        $.data(this, 'sameheight', obj);
        methods._create.apply(obj, args);
      });
    }
    else {
      $.error('Method ' + method + ' does not exist on sameheight objects.');
    }
    return this;
  };
})(jQuery);


/**
 * Toggle showing more or less content.
 */
(function ($) {
  var methods = {
    _create: function (options) {
      this.options = $.extend({
        'less_selector': '.more-or-less-less-view',
        'less_label': 'Read less.',
        'more_selector': '.more-or-less-more-view',
        'more_label': 'Read more.'
      }, options);
      methods.init.apply(this);
    },
    _click: function (event) {
      var container = event.data.container;
      event.preventDefault();
      methods.toggle.apply(container);
    },
    init: function () {

      this.lessView = $(this.options['less_selector'], this.element);
      this.lessView.addClass('more-or-less-view');

      this.moreView = $(this.options['more_selector'], this.element);
      this.moreView.addClass('more-or-less-view');
      
      this.toggleLink = $('<a href="javascript:void(0)">'
        + this.options['more_label'] + '</a>')
        .addClass('more-or-less-link').insertAfter(this);
      this.toggleLink.bind('click.moreorless', { container: this },
        methods._click);

      methods.less.apply(this);
    },
    more: function (event) {
      // Show the more view
      this.lessView.removeClass('active').addClass('inactive');
      this.moreView.removeClass('inactive').addClass('active');
      // Show the less label
      this.toggleLink.removeClass('more').addClass('less');
      this.toggleLink.text(this.options['less_label']);
    },
    less: function () {
      // Show the less view
      this.lessView.removeClass('inactive').addClass('active');
      this.moreView.removeClass('active').addClass('inactive');
      // Show the more label
      this.toggleLink.removeClass('less').addClass('more');
      this.toggleLink.text(this.options['more_label']);
    },
    toggle: function () {
      // Toggle the state of the views and link
      this.lessView.toggleClass('active inactive');
      this.moreView.toggleClass('active inactive');
      this.toggleLink.toggleClass('less more');
      // Adjust the link label to match the link state 
      var label = this.toggleLink.hasClass('more')
        ? this.options['more_label'] : this.options['less_label'];
      this.toggleLink.text(label);
    },
    destroy: function () {
      this.toggleLink.unbind('.moreorless');
      this.toggleLink.remove();
      this.lessView.removeClass('more-or-less-view active inactive');
      this.moreView.removeClass('more-or-less-view active inactive');
    }
  };
  $.fn.moreorless = function (method) {
    if (methods[method]) {
      var args = Array.prototype.slice.call(arguments, 1);
      $(this).each(function () {
        var obj = $.data(this, 'moreorless');
        methods[method].apply(obj, args);
      });
    }
    else if (typeof method === 'object' || !method) {
      var args = arguments;
      $(this).each(function () {
        var obj = $(this)
        obj.element = this;
        $.data(this, 'moreorless', obj);
        methods._create.apply(obj, args);
      });
    }
    else {
      $.error('Method ' + method + ' does not exist on moreorless objects.');
    }
    return this;
  };
})(jQuery);

/**
 * Display disclaimer widget.
 */
(function ($) {
  var methods = {
    _create: function (options) {
      this.options = $.extend({
        'display_disclaimer': '.signature-display-disclaimer',
        'display_opt_in': '.signature-display-opt-in-field'
      }, options);
      methods.init.apply(this);
    },
    _click: function (event) {
      var form = event.data.form;
      if (form.opt_in.is(':checked')) {
        form.disclaimer.slideUp('fast');
      }
      else {
        form.disclaimer.slideDown('fast');
      }
    },
    init: function () {
      this.disclaimer = $(this.options['display_disclaimer'], this.element);
      this.opt_in = $(this.options['display_opt_in'], this.element);
      this.opt_in.bind('click.displaydisclaimer', { form: this },
        methods._click);
      if (this.opt_in.is(':checked')) {
        this.disclaimer.hide();
      }
      else {
        this.disclaimer.show();
      }
    },
    destroy: function () {
      this.opt_in.unbind('.displaydisclaimer');
    }
  };

  $.fn.displaydisclaimer = function (method) {
    if (methods[method]) {
      var args = Array.prototype.slice.call(arguments, 1);
      $(this).each(function () {
        var obj = $.data(this, 'displaydisclaimer');
        methods[method].apply(obj, args);
      });
    }
    else if (typeof method === 'object' || !method) {
      var args = arguments;
      $(this).each(function () {
        var obj = $(this)
        obj.element = this;
        $.data(this, 'displaydisclaimer', obj);
        methods._create.apply(obj, args);
      });
    }
    else {
      $.error('Method ' + method + ' does not exist on display disclaimer objects.');
    }
    return this;
  };
})(jQuery);

/**
 * In Field labels widget.
 */
(function ($) {
  var methods = {
    _create: function (options) {
      this.options = $.extend({
      }, options);
      methods.init.apply(this);
    },
    _focus: function (event) {
      var input = $(this);
      if (!Modernizr || !Modernizr.input || !Modernizr.input.placeholder) {
        if (input.val() == input.attr('placeholder')) {
          input.val('');
          input.removeClass('placeholder');
        }
      }
      else {
        input.attr('placeholder', '');
      }
    },
    _blur: function (event) {
      var input = $(this);
      if (!Modernizr || !Modernizr.input || !Modernizr.input.placeholder) {
        if (input.val() == '' || input.val() == input.attr('placeholder')) {
          input.addClass('placeholder');
          input.val(input.attr('placeholder'));
        }
      }
      else {
        input.attr('placeholder', input.attr('infieldlabel'));
      }
    },
    _submit: function (event) {
      $(this).find('[placeholder]').each(function () {
        var input = $(this);
        if (input.val() == input.attr('placeholder')) {
          input.val('');
        }
      });
    },
    init: function () {
      var self = this;
      // Initialize the in field labels on text fields.
      this.fields = $('.form-type-textfield', this.element);
      this.fields.each(function (index) {
        var label = $('label', this);
        $('input[type=text]', this).attr('placeholder', label.text());
        $('input[type=text]', this).attr('infieldlabel', label.text());
        label.hide(); 
      });
      // Replace the "- None -" option the lists with the field label.
      this.lists = $('.form-type-select', this.element);
      this.lists.each(function (index) {
        var label = $('label', this);
        $("select option[value='_none']", this).text(label.text());
        label.hide();
      });
      $('[placeholder]', this)
        .bind('focus.infieldlabels', methods._focus)
        .bind('blur.infieldlabels', methods._blur)
        .blur();
      if (!Modernizr || !Modernizr.input || !Modernizr.input.placeholder) {
        this.bind('submit.infieldlabels', methods._submit);
      }
    },
    destroy: function () {
      if (!Modernizr || !Modernizr.input || !Modernizr.input.placeholder) {
        $('[placeholder]', this).unbind('.infieldlabels');
        this.unbind('.infieldlabels');
      }
    }
  };

  $.fn.infieldlabels = function (method) {
    if (methods[method]) {
      var args = Array.prototype.slice.call(arguments, 1);
      $(this).each(function () {
        var obj = $.data(this, 'infieldlabels');
        methods[method].apply(obj, args);
      });
    }
    else if (typeof method === 'object' || !method) {
      var args = arguments;
      $(this).each(function () {
        var obj = $(this)
        obj.element = this;
        $.data(this, 'infieldlabels', obj);
        methods._create.apply(obj, args);
      });
    }
    else {
      $.error('Method ' + method + ' does not exist on in-field labels objects.');
    }
    return this;
  };
})(jQuery);


/**
 * Selectable address widget.
 */
(function ($) {
  var methods = {
    _create: function (options) {
      this.options = $.extend({
        'address_group': '.selectable-address-group',
        'inside_us': '.selectable-address-inside-us',
        'inside_us_header': 'h3',
        'state_field': '.field-name-field-sig-state .form-item',
        'outside_us': '.selectable-address-outside-us',
        'outside_us_header': 'h3',
        'country_field': '.field-name-field-sig-country .form-item'
      }, options);
      methods.init.apply(this);
    },
    _click: function (event) {
      var form = event.data.form;
      form.inside_us.toggle();
      form.outside_us.toggle();
    },
    init: function () {
      var self = this;

      // Get the selectable address.
      this.inside_us = $(this.options['inside_us'], this.element);
      this.outside_us = $(this.options['outside_us'], this.element);

      // Add an outside US link to the inside US address
      this.inside_us.each(function () {
        var label = $('h3 > span:first-of-type', self.outside_us).text();
        this.outside_link = $('<span class="selectable-address-link">'
          + ' (<a href="javascript:void(0)">' + label + '?</a>)</span>');
        $(self.options['inside_us_header'], this).append(this.outside_link);
        this.outside_link.bind('click.selectableaddress', {
          form: self 
        }, methods._click);
      });

      // Add an inside US link to the outside US address
      this.outside_us.each(function () {
        var label = $('h3 > span:first-of-type', self.inside_us).text();
        this.inside_link = $('<span class="selectable-address-link">'
          + ' (<a href="javascript:void(0)">' + label + '?</a>)</span>');
        $(self.options['outside_us_header'], this).append(this.inside_link);
        this.inside_link.bind('click.selectableaddress', {
          form: self 
        }, methods._click);
      });

      // Start off with the inside US address
      this.outside_us.hide();
    },
    destroy: function () {
      this.inside_link.remove();
      this.outside_link.remove();
    }
  };

  $.fn.selectableaddress = function (method) {
    if (methods[method]) {
      var args = Array.prototype.slice.call(arguments, 1);
      $(this).each(function () {
        var obj = $.data(this, 'selectableaddress');
        methods[method].apply(obj, args);
      });
    }
    else if (typeof method === 'object' || !method) {
      var args = arguments;
      $(this).each(function () {
        var obj = $(this)
        obj.element = this;
        $.data(this, 'selectableaddress', obj);
        methods._create.apply(obj, args);
      });
    }
    else {
      $.error('Method ' + method + ' does not exist on selectable address objects.');
    }
    return this;
  };
})(jQuery);


/**
 * Signature list widget.
 */
(function($) {
  var methods = {
    _create: function (options) {
      this.options = $.extend({
        'view_name': ''
      }, options);
      methods.init.apply(this);
    },
    init: function () {
      this._connected = false;
      this._locked = true;
    },
    connect: function (views) {
      var self = this;

      // Only connect the signature lists once.
      if (this._connected) { return; }
      this._connected = true;

      $.each(views.ajaxViews, function (i, settings) {
        if (settings.view_name == self.options['view_name']) {
          var view = '.view-dom-id-' + settings.view_dom_id;
          // Skip sub-views.
          if (!$(view).parents('.view').size()){
            // Retrieve the path to use for views' ajax. (is this needed?)
            var ajax_path = views.ajax_path;
            // If there are multiple views this might've ended up showing up
            // multiple times. (is this needed?)
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
            var ajax = new Drupal.ajax(false, self, element_settings);
          }
        }
      });
      this._locked = false;
      methods.refresh.apply(this);
    },
    refresh: function () {
      if (this._connected && !this._locked) {
        this._locked = true;
        this.trigger('refresh_signature_list');
      }
    }
  };

  $.fn.signaturelist = function (method) {
    if (methods[method]) {
      var args = Array.prototype.slice.call(arguments, 1);
      $(this).each(function () {
        var obj = $.data(this, 'signaturelist');
        methods[method].apply(obj, args);
      });
    }
    else if (typeof method === 'object' || !method) {
      var args = arguments;
      $(this).each(function () {
        var obj = $(this)
        obj.element = this;
        $.data(this, 'signaturelist', obj);
        methods._create.apply(obj, args);
      });
    }
    else {
      $.error('Method ' + method + ' does not exist on signature list objects.');
    }
    return this;
  };
})(jQuery);

/**
 * Signature progress/state widget.
 */
(function($) {
  var methods = {
    _create: function (options) {
      this.options = $.extend({
        'nid': '',
        'ajax_path': '/ajax/signature/node/'
      }, options);
      methods.init.apply(this);
    },
    init: function () {
      this._locked = false;
      this.groups = $('.signature-state-fields', this.element);
      methods.refresh.apply(this);
    },
    refresh: function () {
      if (!this._locked) {
        this._locked = true;
        var self = this;
        var callback = function() { methods.update.apply(self, arguments); };
        $.get(this.options['ajax_path'] + this.options['nid'], null, callback);
      }
    },
    update: function (response) {
      if (response[this.options['nid']]) {
        var data = response[this.options['nid']];
        var progress = data['progress'];
        this.groups.each(function (index) {
          var group = $(this);
          if (group.hasClass(progress['state'])) {
            // Field(s) active for current signature collection state, check
            // action completion state
            if (group.hasClass('complete')) {
              // Field(s) only shown when ation complete.
              if (progress['count'] >= progress['goal']) {
                group.removeClass('inactive').addClass('active');
              }
              else {
                group.removeClass('active').addClass('inactive');
              }
            }
            else if (group.hasClass('incomplete')) {
              // Field(s) only shown when action not complete
              if (progress['count'] >= progress['goal']) {
                group.removeClass('active').addClass('inactive');
              }
              else {
                group.removeClass('inactive').addClass('active');
              }
            }
            else {
              // Field(s) not marked with complete/incomplete class so only
              // depend on colleciton state.
              group.removeClass('inactive').addClass('active');
            }
          }
          else {
            // Field(s) not shown for current signature collection state. 
            group.removeClass('active').addClass('inactive');
          }
        });
        // Update the progress text and meters.
        for (selector in progress['updates']) {
          $(selector, this.element).replaceWith(progress['updates'][selector]);
        }
      }
    }
  };

  $.fn.signatureprogress = function (method) {
    if (methods[method]) {
      var args = Array.prototype.slice.call(arguments, 1);
      $(this).each(function () {
        var obj = $.data(this, 'signatureprogress');
        methods[method].apply(obj, args);
      });
    }
    else if (typeof method === 'object' || !method) {
      var args = arguments;
      $(this).each(function () {
        var obj = $(this)
        obj.element = this;
        $.data(this, 'signatureprogress', obj);
        methods._create.apply(obj, args);
      });
    }
    else {
      $.error('Method ' + method + ' does not exist on signature progress objects.');
    }
    return this;
  };
})(jQuery);


/**
 * External action tracking widget.
 */
(function ($) {
  var methods = {
    _create: function (options) {
      this.options = $.extend({
        'nid': '',
        'ajax_path': '/ajax/takeaction/action/external/'
      }, options);
      methods.init.apply(this);
    },
    _click: function (event) {
      var self = event.data.self;
      $.get(self.options['ajax_path'] + self.options['nid']);
    },
    init: function () {
      this.button = $('.take_action_button', this.element);
      this.button.bind('click.externalaction', {self:this}, methods._click);
    },
    destroy: function () {
      this.button.unbind('.externalaction');
    }
  };

  $.fn.externalaction = function (method) {
    if (methods[method]) {
      var args = Array.prototype.slice.call(arguments, 1);
      $(this).each(function () {
        var obj = $.data(this, 'externalaction');
        methods[method].apply(obj, args);
      });
    }
    else if (typeof method === 'object' || !method) {
      var args = arguments;
      $(this).each(function () {
        var obj = $(this)
        obj.element = this;
        $.data(this, 'externalaction', obj);
        methods._create.apply(obj, args);
      });
    }
    else {
      $.error('Method ' + method + ' does not exist on external action objects.');
    }
    return this;
  };
})(jQuery);

/**
 * Signature action metrics widget.
 */
(function ($) {
  var methods = {
    _create: function (options) {
      this.options = $.extend({
      }, options);
      methods.init.apply(this);
    },
    _track_view: function (event, type, title) {
      if (type === 'petition_action') {
        s.linkTrackVars = "eVar25,eVar30,events";
        s.linkTrackEvents = "event26";
        s.eVar25 = title;
        s.events = 'event26';
        s.eVar30 = s.pageName;
        s.tl(true, 'o', 'petition view');
      }
      else if (type === 'pledge_action') {
        s.linkTrackVars = "eVar32,eVar30,events";
        s.linkTrackEvents = "event31";
        s.eVar32 = title;
        s.events = 'event31';
        s.eVar30 = s.pageName;
        s.tl(true, 'o', 'pledge view');
      }
    },
    _track_submit: function (event, type, title) {
      if (type === 'petition_action') {
        s.linkTrackVars="eVar25,eVar30,events";
        s.linkTrackEvents="event27,event56";
        s.eVar25=title;
        s.events='event27,event56';
        s.eVar30=s.pageName;
        s.prop53=title;
        s.eVar53=title;
        s.prop55="Petition";
        s.eVar55="Petition";
        s.prop66="Click to Complete Action";
        s.prop67=s.pageName;
        s.tl(true, 'o', 'petition submit');
      }
      else if (type === 'pledge_action') {
        s.linkTrackVars="eVar32,eVar30,events";
        s.linkTrackEvents="event32,event56";
        s.eVar32=title;
        s.events='event32,event56';
        s.eVar30=s.pageName;
        s.prop53=title;
        s.eVar53=title;
        s.prop55="Pledge";
        s.eVar55="Pledge";
        s.prop66="Click to Complete Action";
        s.prop67=s.pageName;
        s.tl(true, 'o', 'pledge submit');
      }
    },
    _track_newsletter_signup: function (event, title) {
      s.linkTrackVars = "eVar23,eVar30,events";
      s.linkTrackEvents = "event39";
      s.eVar23 = title;
      s.eVar30 = s.pageName;
      s.events = 'event39';
      s.tl(true, 'o', 'Newsletter Signup');
    },
    init: function () {
      // Bind the events that should be fired when the action is loaded/viewed.
      this.bind('track_view.signaturemetrics', methods._track_view);
      // Bind the events that can be fired by submitting the signature form.
      this.bind('track_submit.signaturemetrics', methods._track_submit);
      this.bind('track_newsletter_signup.signaturemetrics',
        methods._track_newsletter_signup);
    }
  };

  $.fn.signaturemetrics = function (method) {
    if (methods[method]) {
      var args = Array.prototype.slice.call(arguments, 1);
      $(this).each(function () {
        var obj = $.data(this, 'signaturemetrics');
        methods[method].apply(obj, args);
      });
    }
    else if (typeof method === 'object' || !method) {
      var args = arguments;
      $(this).each(function () {
        var obj = $(this)
        obj.element = this;
        $.data(this, 'signaturemetrics', obj);
        methods._create.apply(obj, args);
      });
    }
    else {
      $.error('Method ' + method + ' does not exist on signature metrics objects.');
    }
    return this;
  };
})(jQuery);

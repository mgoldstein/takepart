(function($, window, document, undefined) {

  var TEACH = window.TEACH || {};

  TEACH.AppRouter = Backbone.Router.extend({
    routes: {
      '(/)': 'featured',      
      'featured(/)': 'featured',
      'popular(/)': 'popular',
      'recent(/)': 'recent',
      'school(/)': 'school',
      'school/:school': 'schoolView',
      'tag/:tag': 'tagView',
      'story/:id': 'storyView'
    }
  });

  TEACH.StoryView = Backbone.View.extend({
    className: "story"
  });

  TEACH.StoriesView = Backbone.View.extend({
    className: "teach-app-pane stories-view",
    initialize: function() {
      this.$el.html(this.id + ' view');
    },
    render: function() {
      return this;
    }

  });

  TEACH.FindSchoolView = Backbone.View.extend({
    id: 'pane-find-school',

    className: 'teach-app-pane school-view',

    events: {
      'submit form': 'formSubmitHandler'
    },

    initialize: function() {
      this.$el.html(_.template($('#school_view').html(), {}));

      if ($.fn.schoolBrowser) {
        this.$('form').schoolBrowser();
      }

      // this function needs to be proxied to "this"
      this.on('show', this.updateCustomSelect, this);
    },

    updateCustomSelect: function() {
      this.$('.hasCustomSelect').trigger('update');
    },

    formSubmitHandler: function(e) {
      e.preventDefault();
      this.trigger('browseschool', this.$('#school_id').val(), this.$('#school_state').val());
    }
  });

  TEACH.AppView = Backbone.View.extend({

    el: 'section#app',

    views: {},

    initialize: function(router) {
      this.$el.html(_.template($('#app_view').html(), {}));

      this.$nav = this.$('.app-nav');

      this.views.featured = new TEACH.StoriesView({id: 'pane-featured'});
      this.views.popular = new TEACH.StoriesView({id: 'pane-popular'});
      this.views.recent = new TEACH.StoriesView({id: 'pane-recent'});
      this.views.school = new TEACH.FindSchoolView();
      _.each(this.views, function(view) { view.$el.appendTo(this.$el).hide(); }, this);

      // the router sets up the state of the application
      this.listenTo(router, 'route', this.route);
      this.listenTo(this.views.school, 'browseschool', function(id, state){
        router.navigate('school/' + (id != 0 ? id : state), {trigger: true});
      });
    },

    route: function(route, params) {
      this.$nav.find('a').removeClass('active');
      this.$el.find('.teach-app-pane').hide();
      this.views.extra && this.views.extra.remove();

      switch (route) {        
        case "featured":
        case "popular":
        case "recent":
        case "school":
          this.$nav.find('#nav-' + route).addClass('active');
          this.views[route].render().$el.show();
          this.views[route].trigger('show');
          break;
        case "schoolView":
        case "tagView":
        case "storyView":
          this.views.extra = new TEACH.StoriesView({id: route + '-' + params[0]});
          this.views.extra.render().$el.appendTo(this.$el).show();
          break;
      }
    }

  });

  $(document).ready(function() {
    var router = new TEACH.AppRouter();
    var app = new TEACH.AppView(router);
    Backbone.history.start();
  });
})(jQuery, this, this.document)

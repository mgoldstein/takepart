(function($, TEACH, window, document, undefined) {

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

  TEACH.Models.Story = Backbone.Model.extend({
    defaults: {
        id: null,
        first_name: '',
        last_name: '',
        image_uid: null,
        image_link: '',
        story: {},
        school: {},
        teacher: {}
    },

    parse: function(data) {
      if (!data.image_uid) {
        data.image_uid = 'sys-defaults/avatar';
        data.image_link = $.cloudinary.url(data.image_uid + '.jpg');
      }
      if (!data.teacher.image_uid) {
        data.teacher.image_uid = 'sys-defaults/sys-default-' + Math.ceil(Math.random() * 17);
        data.teacher.image_link = $.cloudinary.url(data.teacher.image_uid + '.jpg');
      }
      return data;
    },

    initialize: function() {
      // fill in image values if necessary
      this.set(this.parse(this.attributes));
    }
  });

  TEACH.Views.StoryView = Backbone.View.extend({
    tagName: "article",
    className: "story",
    initialize: function() {
      this.template = _.template($('#story_view').html());
      this.listenTo(this.model, "change", this.render);
    },

    render: function() {
      this.$el
        .html(this.template(this.model.toJSON()))
        .find('img').cloudinary()
      ;
      return this;
    }
  });

  TEACH.Collections.Stories = Backbone.Collection.extend({
    model: TEACH.Models.Story,

    parse: function(response) {
      return response.signatures;
    }
  });

  TEACH.Views.StoriesView = Backbone.View.extend({
    className: "teach-app-pane stories-view",

    initialize: function() {
      this.listenTo(this.collection, 'change', this.render);
    },

    render: function() {
      var that = this; // ugh

      this.collection.each(function(model) {
        var view = new TEACH.Views.StoryView({
          model: model,
          id: 'story-' + model.get('id')
        });
        view.render().$el.appendTo(that.$el);
      });

      return this;
    }
  });

  TEACH.Views.FindSchoolView = Backbone.View.extend({
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

  TEACH.Views.AppView = Backbone.View.extend({

    el: 'section#app',

    views: {},

    initialize: function(router) {
      this.$el.html(_.template($('#app_view').html(), {}));

      this.$nav = this.$('.app-nav');

      this.views.featured = new TEACH.Views.StoriesView({id: 'pane-featured', collection: new TEACH.Collections.Stories() });
      this.views.featured.collection.url = 'http://qa-web1.tab.takepart.com/user_teach_stories?action_id=9035092&publisher_key=38ec3cd1db216fd6964277e5969f4cb2';
      this.views.popular = new TEACH.Views.StoriesView({id: 'pane-popular', collection: new TEACH.Collections.Stories() });
      this.views.popular.collection.url = 'http://qa-web1.tab.takepart.com/user_teach_stories?action_id=9035092&publisher_key=38ec3cd1db216fd6964277e5969f4cb2';
      this.views.recent = new TEACH.Views.StoriesView({ id: 'pane-recent', collection: new TEACH.Collections.Stories() });
      this.views.recent.collection.url = 'http://qa-web1.tab.takepart.com/user_teach_stories?action_id=9035092&publisher_key=38ec3cd1db216fd6964277e5969f4cb2';

      this.views.school = new TEACH.Views.FindSchoolView();
      _.each(this.views, function(view) {
        view.$el.appendTo(this.$el).hide();
        if (view.collection) {
          view.collection.fetch({
            success: function() { view.render(); }
          });
        }
      }, this);

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
          this.views.extra = new TEACH.Views.StoriesView({id: route + '-' + params[0]});
          this.views.extra.render().$el.appendTo(this.$el).show();
          break;
        case "storyView":
          $.tpmodal.show({id: 'sys_modal_', node: $('<div>').html('story')[0]});
      }
    }

  });

  $(document).ready(function() {
    var router = new TEACH.AppRouter();
    var app = new TEACH.Views.AppView(router);
    Backbone.history.start();
    window.app = app; // @todo delete me
  });
})(jQuery, TEACH, this, this.document)

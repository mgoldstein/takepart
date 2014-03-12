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

  TEACH.Collections.Stories = Backbone.PageableCollection.extend({
    model: TEACH.Models.Story,

    mode: 'infinite',

    url: TEACH.TAP.postURL,

    state: {
        pageSize: 6
    },

    queryParams: {
        pageSize: 'per',
        totalPages: null,
        totalRecords: null,
        sortKey: null,
        order: null,
        action_id: TEACH.TAP.action_id,
        publisher_key: TEACH.TAP.partner_code
    },

    parseRecords: function(response) {
      // @todo set total stories if it's not set yet
      return response.signatures;
    },

    parseLinks: function() {
      var response = {
        first: TEACH.TAP.postURL,
      };

      if (this.state.currentPage != 1) {
        response.prev = TEACH.TAP.postURL;
      }

      // @todo alter the conditional to fail if we're on the last page
      if (true) {
        response.next = TEACH.TAP.postURL;        
      }

      return response;
    },

    parseState: function (response) {
      // @todo update the pagination state based on response from the server
      // @see http://backbone-paginator.github.io/backbone-pageable/api/#!/api/Backbone.PageableCollection
      return {};
    }
  });

  TEACH.Views.StoriesView = Backbone.View.extend({
    className: "teach-app-pane stories-view",

    events:  {
        'click .story': "showStoriesModal",
        'click .load-more-stories-button': "loadMoreStories"
    },

    initialize: function() {
      this.listenTo(this.collection.fullCollection, 'add', this.render);
    },

    render: function() {
      var that = this; // ugh

      this.$el.empty(); // @todo inefficient

      this.collection.fullCollection.each(function(model) {
        var view = new TEACH.Views.StoryView({
          model: model,
          id: 'story-' + model.get('id')
        });
        view.render().$el.appendTo(that.$el);
      });

      // @todo masonry

      // @todo render the total number of stories
      $('<div>').addClass('story-count').text(this.collection.fullCollection.length + ' Stories').prependTo(this.$el);
      // @todo add conditional to only add this button if there are more stories
      $(_.template($('#load_more_stories_view').html(), {button_text: "Load More Stories"})).appendTo(this.$el);

      return this;
    },

    showStoriesModal: function(e) {
      e.preventDefault();
      $.tpmodal.show();
    },

    loadMoreStories: function(e) {
      e.preventDefault();
      this.$el.find('.load-more-stories-button').addClass('in-progress');
      this.collection.getNextPage();
    }
  });

  TEACH.Views.FindSchoolView = Backbone.View.extend({
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

      // cache jQuery objects for convenience
      this.$nav = this.$('.app-nav');

      this.views.featured = new TEACH.Views.StoriesView({
        id: 'pane-featured',
        collection: new TEACH.Collections.Stories([], {
          queryParams: {
            filter: 'feature'
          }
        })
      });
      this.views.popular = new TEACH.Views.StoriesView({
        id: 'pane-popular',
        collection: new TEACH.Collections.Stories([], {
          queryParams: {
            sort: 'popular'
          }
        })
      });
      this.views.recent = new TEACH.Views.StoriesView({
        id: 'pane-recent',
        collection: new TEACH.Collections.Stories()
      });
      this.views.school = new TEACH.Views.FindSchoolView({ id: 'pane-find-school' });

      // add the views to the app.
      _.each(this.views, function(view) {
        view.$el.appendTo(this.$el).hide();
        if (view.collection) {
          view.collection.fetch();
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
          break;
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

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

  TEACH.Views.StoryFullView = Backbone.View.extend({
    tagName: "article",
    className: "sys-story-modal",

    initialize: function() {
      this.template = _.template($('#story_full_view').html());

      this.listenTo(this.model, "change", this.render);
    },

    render: function() {
      // set up social options
      var title = "Teacher Stories: " + [this.model.get('teacher').first_name, this.model.get('teacher').last_name].join(' ');
      var description = "Here’s an inspiring teacher story that is helping TEACH to donate up to $50,000 to public schools.";
      var socialOptions = $.extend({}, TEACH.social.options, {
        services: [
          {
            name: 'facebook',
            title: title,
            description: description,
            image: this.model.get('teacher').image_link
          },
          {
            name: 'twitter',
            text: description,
            via: 'TeachMovie'
          },
          {
            name: 'googleplus'
          }
        ]
      });

      // render the element
      this.$el.html(this.template(this.model.toJSON()));
      this.$el.find('img').cloudinary();
      this.$el.find('#story-social-share').tpsocial(socialOptions);
      window.FB && FB.XFBML.parse(this.el);

      // bind social share event to contact TAP
      this.$el.find('#story-social-share a').on('click', _.bind(function(){
        $.ajax(TEACH.TAP.postURL + '/' + this.model.get('id') + '/share?publisher_key=' + TEACH.TAP.partner_code, {
          success: function(data) {
            console.log(data);
          }
        });
      }, this));

      // When we click on a tag, close the tpmodal
      // (otherwise, this )
      this.$el.find('#story-tags').on('click', 'a', _.bind(function(e){
        this.trigger('tpmodalclose');
        $.tpmodal.hide({id: 'sys_modal_'});
        this.remove();
      }, this));

      // phone home and say we have a successful view
      $.ajax(TEACH.TAP.postURL + '/' + this.model.get('id') + '/view?publisher_key=' + TEACH.TAP.partner_code, {
        success: function(data) {
          console.log(data);
        }
      });

      return this;
    },
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
      'click .story': 'showStoriesModal',
      'click .load-more-stories-button': "loadMoreStories"
    },

    modal: null,

    initialize: function() {
      this.template = _.template($('#stories_view').html());
      this.listenTo(this.collection.fullCollection, 'add', this.render);
    },

    render: function() {
      this.$el.empty().html(this.template({})); // @todo inefficient

      this.collection.fullCollection.each(_.bind(function(model, i, collection) {
        var view = new TEACH.Views.StoryView({
          model: model,
          id: 'story-' + model.get('id')
        });
        view.render().$el
          .data('index', collection.indexOf(model))
          .appendTo(this.$('.stories'))
        ;
      },this));

      // @todo masonry

      // @todo render the total number of stories
      $('<div>').addClass('story-count').text(this.collection.fullCollection.length + ' Stories').prependTo(this.$el);
      // @todo add conditional to only add this button if there are more stories
      $(_.template($('#load_more_stories_view').html(), {button_text: "Load More Stories"})).appendTo(this.$el);

      return this;
    },

    loadMoreStories: function(e) {
      e.preventDefault();
      this.$el.find('.load-more-stories-button').addClass('in-progress');
      this.collection.getNextPage();
    },

    showStoriesModal: function(e) {
      e.preventDefault();
      this.modal && this.modal.remove();
      this.modal = new TEACH.Views.StoriesModalView({
        collection: new TEACH.Collections.Stories(this.collection.fullCollection.clone().models, {
          mode: 'client',
          parentView: this,
          state: {
            firstPage: 0,
            pageSize: 1,
            currentPage: $(e.currentTarget).data('index')
          }
        })
      });
      this.modal.render();
    }
  });

  TEACH.Views.StoriesModalView = Backbone.View.extend({

    currentStory: null,

    events: {
      'click #previous-story': 'showPreviousStory',
      'click #next-story': 'showNextStory'
    },

    initialize: function() {
      this.listenTo(this.collection, 'reset', this.render);

      this.$el.html([
        '<a id="previous-story" class="story-nav previous-story"></a>',
        '<a id="next-story" class="story-nav next-story"></a>'
      ].join(''));
    },
    render: function() {
      // clean up
      this.$('.sys-story-modal').remove();
      if (this.currentStory) {
        this.currentStory.remove();
      }
      // put the story in
      this.currentStory = new TEACH.Views.StoryFullView({
        model: this.collection.models[0] // there's only one model
      });
      this.currentStory.render().$el.appendTo(this.$el);

      // show the links we want
      this.$('.story-nav').hide();
      if (this.collection.state.currentPage != 0) {
        this.$('#previous-story').show();
      }
      if (this.collection.state.currentPage != this.collection.state.lastPage) {
        this.$('#next-story').show();
      }
      $.tpmodal.show({
        id: 'sys_modal_',
        node: this.el,
        afterClose: _.bind(function() {
          this.remove();
        },this)
      });
      window.teachRouter.navigate('story/' + this.collection.models[0].get('id'), {
        replace: true
      });
      this.delegateEvents();
    },

    showPreviousStory: function(e) {
      e.preventDefault();
      this.collection.getPreviousPage();
    },

    showNextStory: function(e) {
      e.preventDefault();
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

    initialize: function() {
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
      this.listenTo(window.teachRouter, 'route', this.route);
      this.listenTo(this.views.school, 'browseschool', function(id, state){
        window.teachRouter.navigate('school/' + (id != 0 ? id : state), {trigger: true});
      });
    },

    route: function(route, params) {
      var queryParams = {};

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
          if (route == "tagView") {
            queryParams.tag = params[0];
          } else {
            if (isNaN(parseInt(params[0], 10))) {
              queryParams.school_state = params[0];
              queryParams.school_external_id = 0;
            } else {
              queryParams.school_external_id = params[0];
            }
          }
          this.views.extra = new TEACH.Views.StoriesView({
            id: 'pane-' + route,
            collection: new TEACH.Collections.Stories([], {
              queryParams: queryParams
            })
          });
          this.views.extra.collection.fetch();
          this.views.extra.render().$el.appendTo(this.$el);
          break;
        case "storyView":
          this.views.extra = new TEACH.Views.StoryFullView({
            model: new TEACH.Models.Story()
          });
          this.views.extra.model.url = '/proxy?request=' + TEACH.TAP.postURL + '/' + params[0] + encodeURIComponent('?action_id = ' + TEACH.TAP.action_id + '&publisher_key=' + TEACH.TAP.partner_code);
          this.views.extra.model.fetch({
            success: _.bind(function() {
              $.tpmodal.show({
                id: 'sys_modal_',
                node: this.views.extra.el,
                afterClose: _.bind(function() {
                  this.views.extra.remove();
                }, this)
              });
            }, this)
          });
          this.$nav.find('#nav-featured').addClass('active');
          this.views.featured.render().$el.show();
          break;
      }
    }
  });

  $(document).ready(function() {
    window.teachRouter = new TEACH.AppRouter(); // @todo remove global?
    var app = new TEACH.Views.AppView();
    Backbone.history.start();
    window.app = app; // @todo delete me
  });
})(jQuery, TEACH, this, this.document)

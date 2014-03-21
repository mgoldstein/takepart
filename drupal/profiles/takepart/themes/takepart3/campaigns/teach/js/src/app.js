(function($, TEACH, window, document, undefined) {

  TEACH.AppRouter = Backbone.Router.extend({
    routes: {
      '(/)': 'featured',      
      'featured(/)': 'featured',
      'popular(/)': 'popular',
      'recent(/)': 'recent',
      'school(/)': 'school',
      'school/:state(/:id)': 'schoolView',
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
        $.post(TEACH.TAP.postURL + '/' + this.model.get('id') + '/share?publisher_key=' + TEACH.TAP.partner_code);
      }, this));

      // When we click on a tag, remove the view
      this.$el.find('#story-tags').on('click', 'a', _.bind(function(e){
        this.remove();
      }, this));

      // phone home and say we have a successful view
      // and trigger the analytics event
      $.post(TEACH.TAP.postURL + '/' + this.model.get('id') + '/view?publisher_key=' + TEACH.TAP.partner_code);
      $(window).trigger('teach-story-view');

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

    parseLinks: function(response) {
      var data = {
        first: TEACH.TAP.postURL,
      };

      if (this.state.currentPage != 1) {
        data.prev = TEACH.TAP.postURL;
      }

      if (this.state.currentPage < response.total_pages) {
        data.next = TEACH.TAP.postURL;
      }

      return data;
    },

    parseState: function (response) {
      return {
        // the new signatures are added AFTERWARDS to the calculation
        totalRecords: response.total_signature_count - response.signatures.length
      };
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
      this.$el.empty().html(_.template($('#stories_view').html(), {}));
      this.$wrapper = this.$('.stories-wrapper').masonry({
        gutter: 20,
        transitionDuration: 0
      });

      this.listenTo(this.collection, 'reset', this.render);
      this.on('show', _.bind(function() {
        this.$wrapper.masonry('layout');
      }, this));
      this.collection.fetch();
    },

    render: function() {
      var $newElements;

      // drop in the new stories
      this.collection.each(_.bind(function(model, i, collection) {
        var view = new TEACH.Views.StoryView({
          model: model,
          id: 'story-' + model.get('id')
        });
        view.render().$el
          .data('index', collection.indexOf(model))
        ;
        $newElements = $newElements ? $newElements.add(view.$el) : view.$el;
      },this));

      // handle an empty result set
      if (!$newElements) return this;

      $newElements.appendTo(this.$wrapper);

      $newElements.imagesLoaded(_.bind(function() {      
        this.$wrapper.masonry('appended', $newElements).masonry('layout');
      }, this));

      this.$('.story-count').text((this.collection.state.totalRecords ? this.collection.state.totalRecords : '0') + ' Stories').prependTo(this.$el);

      this.$('.load-more-stories')
        .toggleClass('hidden', this.collection.fullCollection.length == this.collection.state.totalRecords)
        .find('a')
          .removeClass('in-progress')
      ;

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

  TEACH.Views.StoriesSchoolSearchView = TEACH.Views.StoriesView.extend({
    getSchoolName: function() {
      $.ajax({
        url: '/proxy?request=' + encodeURIComponent('http://api.greatschools.org/schools/' + this.attributes['data-state'] + '/' + this.attributes['data-gsid'] + '?key=zzlcyx4aijxe1nmnagoziqxx'),
        success: _.bind(function(response) {
          this.schoolName = $(response).find('school name').text()
          this.$('#school_search_results_name').text(this.schoolName);
        }, this)
      });
    },

    render: function() {
      TEACH.Views.StoriesView.prototype.render.apply(this);
      this.$('.story-count').hide();

      var viewMessages = [];

      var templateVars = {
        count: this.collection.length > 0 ? this.collection.state.totalRecords : 'no',
        state: TEACH.stateNames[this.attributes['data-state']],
        verb: this.collection.state.totalRecords == 1 ? 'is' : 'are',
        plural: this.collection.state.totalRecords == 1 ? 'story' : 'stories'
      };

      var messagesTemplate = this.attributes['data-gsid'] ? '#school_count_results_view' : '#school_no_gsid_results_view';

      viewMessages.push(_.template($(messagesTemplate).html(), templateVars));

      if (this.collection.length == 0) {
        viewMessages.push(_.template($('#school_no_results_view').html(), {}));
      }

      this.$('.view-messages').html(viewMessages.join(''));
      if (parseInt(this.attributes['data-gsid']) > 0 && typeof this.schoolName === 'undefined') {
        this.getSchoolName();
      }

      return this;
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
      this.$('.hasCustomSelect').trigger('update').trigger('change');
    },

    formSubmitHandler: function(e) {
      e.preventDefault();
      this.$('.school-name').removeClass('in-progress');
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
      }, this);

      // the router sets up the state of the application
      this.listenTo(window.teachRouter, 'route', this.route);
      this.listenTo(this.views.school, 'browseschool', function(id, state) {
        window.teachRouter.navigate('school/' + state + (id != 0 ? '/' + id : ''), {trigger: true});
      });
    },

    route: function(route, params) {
      var queryParams = {};

      this.$nav.find('a').removeClass('active');
      this.$el.find('.teach-app-pane').hide();
      this.views.extra && this.views.extra.remove();
      $.tpmodal.hide({id: 'sys_modal_'});

      switch (route) {
        case "featured":
        case "popular":
        case "recent":
        case "school":
          this.$nav.find('#nav-' + route).addClass('active');
          this.views[route].$el.show();
          this.views[route].trigger('show');
          break;
        case "schoolView":
          queryParams.school_state = params[0];
          queryParams.school_external_id = params[1] ? params[1] : 0;

          this.views.extra = new TEACH.Views.StoriesSchoolSearchView({
            id: 'pane-schoolView',
            collection: new TEACH.Collections.Stories([], {
              queryParams: queryParams
            }),
            attributes: {
              "data-state": queryParams.school_state,
              "data-gsid": queryParams.school_external_id
            }
          });

          // show the search box
          this.$nav.find('#nav-school').addClass('active');
          this.views.school.$el.show();
          this.views.school.trigger('show');

          this.views.extra.$el.appendTo(this.$el);

          window.scroll(0,this.$nav.offset().top);
          break;
        case "tagView":
          queryParams.tag = params[0];
          this.views.extra = new TEACH.Views.StoriesView({
            id: 'pane-tagView',
            collection: new TEACH.Collections.Stories([], {
              queryParams: queryParams
            })
          });
          this.views.extra.$el.appendTo(this.$el);
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
          this.views.featured.$el.show();
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

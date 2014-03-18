(function($, TEACH, window, document, undefined) {

  // not using Drupal.behaviors because
  // this code has nothing to do with Drupal
  $(document).ready(function(){
    var $body = $('body');

    // delegate clicks on stories/schools
    $body
      .on('click', '[data-storyid]', function() {
        window.location = "/teach/stories#story/" + $(this).data('storyid');
      })
      .on('click', '[data-schoolid]', function() {
        window.location = "/teach/stories#school/" + $(this).data('schoolid');
      })
    ;

    // setup form browse behavior
    $('#browse-by-school')
      .schoolBrowser()
      .on('submit', function(e) {
        e.preventDefault();
        var $this = $(this),
            id = $this.find('#school_id').val();

        window.location = "/teach/stories#school/" + (id != 0 ? id : $this.find('#school_state').val());
      });

    // set up most stories lists 
    var $mostStoriesNav = $('#most-stories-nav');
    var $mostStoriesLists = $('.most-stories-list');
    var $mostStoriesLatest = $mostStoriesLists.filter('#most-stories-latest');
    var $mostStoriesOverall = $mostStoriesLists.filter('#most-stories-overall');

    $mostStoriesLists.hide().filter(':first').show();
    $mostStoriesNav.find('a:first').addClass('active');

    $mostStoriesNav.on('click', 'a', function(e){
      e.preventDefault();
      $mostStoriesNav.find('a').removeClass('active').filter(this).addClass('active');
      $mostStoriesLists.hide().filter(e.target.hash).show();
    });

    // populate the story stats and latest school list
    var $storyStats = $('.teacher-story-stat');
    var listItem = TEACH.tmpl('most_stories_list_template');
    $.ajax('/proxy?request=' + TEACH.TAP.postURL + '/stats' + encodeURIComponent('?interval=overall&action_id=' + TEACH.TAP.action_id), {
      success: function(data) {
        // this could be templated.
        $storyStats.filter('.stats-stories').find('.campaign-stat').text(data.stories_count);
        $storyStats.filter('.stats-states').find('.campaign-stat').text(data.uniq_states_count);
        $storyStats.filter('.stats-schools').find('.campaign-stat').text(data.uniq_school_count);

        $.each(data.school_list.slice(0,5), function() {
          $(listItem(this)).appendTo($mostStoriesOverall);
        })
      }
    });

    $.ajax('/proxy?request=' + TEACH.TAP.postURL + '/stats' + encodeURIComponent('?interval=latest&action_id=' + TEACH.TAP.action_id), {
      success: function(data) {
        $.each(data.school_list.slice(0,5), function() {
          $(listItem(this)).appendTo($mostStoriesLatest);
        })
      }
    });

    // populate the featured stories in polaroids
    $('.featured-stories').find('.featured-story').each(function() {
      var $this = $(this);
      var storyId = $this.data('storyid');
      $.ajax('/proxy?request=' + encodeURIComponent(TEACH.TAP.postURL + '/' + storyId + '?action_id=' + TEACH.TAP.action_id + '&publisher_key=' + TEACH.TAP.partner_code), {
        success: function(data) {

          // replace empty teacher image with defaults
          if (data.teacher.image_uid == "") {
            data.teacher.image_uid = 'sys-defaults/sys-default-' + Math.ceil(Math.random() * 17);
          }

          $this
            .html(TEACH.tmpl('featured_story_template', data))
            .on('click', 'a', function(e) { e.stopPropagation(); })
            .find('img').cloudinary()
          ;
        }
      });
    });
  });
})(jQuery, TEACH, this, this.document)

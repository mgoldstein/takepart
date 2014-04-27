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
        var id = $(this).data('schoolid');
        window.location = '/teach/stories#school/' + $(this).data('state') + (id != 0 ? '/' + id : '');
      })
    ;

    // setup form browse behavior
    $('#browse-by-school')
      .schoolBrowser()
      .on('submit', function(e) {
        e.preventDefault();
        var $this = $(this),
            id = $this.find('#school_id').val();

        window.location = "/teach/stories#school/" + $this.find('#school_state').val() + (id != 0 ? '/' + id : '');
      });

    // populate the story stats and latest school list
    var $mostStoriesOverall = $('#most-stories-overall');
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
  });
})(jQuery, TEACH, this, this.document)

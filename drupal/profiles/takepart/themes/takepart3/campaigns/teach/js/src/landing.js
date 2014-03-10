(function($, TEACH, window, document, undefined) {

  // not using Drupal.behaviors because
  // this code has nothing to do with Drupal
  $(document).ready(function(){
    var $body = $('body');

    // delegate clicks on stories/schools
    $body
      .on('click', '[data-storyid]', function() {
        alert('@todo - navigate to story ID ' + $(this).data('storyid'));
      })
      .on('click', '[data-schoolid]', function() {
        alert('@todo - navigate to school ID ' + $(this).data('schoolid'));
      })
    ;

    // setup form browse behavior
    $('#browse-by-school')
      .schoolBrowser()
      .on('submit', function(e) {
        e.preventDefault();
        var $this = $(this),
            id = $this.find('#school_id').val();

        if (id != 0) {
          alert('@todo - navigate to school ID ' + id);
        } else {
          alert('@todo - navigate to "other" schools in ' + $this.find('#school_state').val());
        }
      });

    // set up most stories lists 
    var $mostStoriesNav = $('#most-stories-nav');
    var $mostStoriesLists = $('.most-stories-list');
    var $mostStoriesLatest = $mostStoriesLists.filter('#most-stories-latest');
    var $mostStoriesOverall = $mostStoriesLists.filter('#most-stories-overall');

    $mostStoriesLists.hide().filter(':first').show();
    $mostStoriesNav.find('a:first').addClass('active');

    var listItem = TEACH.tmpl('most_stories_list_template');
    // @todo ajax call
    var data = [{id: 1}, {id: 2}, {id: 3}, {id: 4}, {id: 5}];    
    $.each(data, function() {
      $(listItem(this)).appendTo($mostStoriesLatest);
      $(listItem(this)).appendTo($mostStoriesOverall);
    });

    $mostStoriesNav.on('click', 'a', function(e){
      e.preventDefault();
      $mostStoriesNav.find('a').removeClass('active').filter(this).addClass('active');
      $mostStoriesLists.hide().filter(e.target.hash).show();
    });

    // populate the story stats
    var $storyStats = $('.teacher-story-stat');
    // @todo ajax call
    $storyStats.find('.campaign-stat').html("54,321");

    // populate the featured stories in polaroids
    $('.featured-stories').find('.featured-story').each(function() {
      var $this = $(this);
      // @todo ajax call
      $this.html(TEACH.tmpl('featured_story_template', {}));
    });
  });
})(jQuery, TEACH, this, this.document)

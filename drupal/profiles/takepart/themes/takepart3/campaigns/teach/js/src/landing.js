(function($, window, document, undefined) {
  // Simple JavaScript Templating
  // John Resig - http://ejohn.org/ - MIT Licensed
  var templateCache = {};

  var tmpl = function tmpl(str, data) {
    // Figure out if we're getting a template, or if we need to
    // load the template - and be sure to cache the result.
    var fn = !/\W/.test(str) ?
            templateCache[str] = templateCache[str] ||
            tmpl(document.getElementById(str).innerHTML) :
            // Generate a reusable function that will serve as a template
            // generator (and which will be cached).
            new Function("obj",
                    "var p=[],print=function(){p.push.apply(p,arguments);};" +
                    // Introduce the data as local variables using with(){}
                    "with(obj){p.push('" +
                    // Convert the template into pure JavaScript
                    str
                    .replace(/[\r\t\n]/g, " ")
                    .split("<%").join("\t")
                    .replace(/((^|%>)[^\t]*)'/g, "$1\r")
                    .replace(/\t=(.*?)%>/g, "',$1,'")
                    .split("\t").join("');")
                    .split("%>").join("p.push('")
                    .split("\r").join("\\'")
                    + "');}return p.join('');");

    // Provide some basic currying to the user
    return data ? fn(data) : fn;
  };

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

    // set up most stories lists 
    var $mostStoriesNav = $('#most-stories-nav');
    var $mostStoriesLists = $('.most-stories-list');
    var $mostStoriesLatest = $mostStoriesLists.filter('#most-stories-latest');
    var $mostStoriesOverall = $mostStoriesLists.filter('#most-stories-overall');

    $mostStoriesLists.hide().filter(':first').show();
    $mostStoriesNav.find('a:first').addClass('active');

    var listItem = tmpl('most_stories_list_template');
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
      $this.html(tmpl('featured_story_template', {}));
    });
  });
})(jQuery, this, this.document)

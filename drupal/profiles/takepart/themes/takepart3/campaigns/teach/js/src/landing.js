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
    $('.featured-stories').find('.featured-story').each(function() {
      var $this = $(this);
      $this.html(tmpl('featured_story_template', {}));
    });
  });
})(jQuery, this, this.document)

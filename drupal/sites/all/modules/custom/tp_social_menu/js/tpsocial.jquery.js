(function (window, $, undefined) {
  // Plugin

  var dpre = 'tps';
  var cpre = 'tp-social-';
  var $window = $(window);
  /*
  * Scan for sponsored meta tag and pull value if present
  */
  var sponsoredmetatag = $("meta[property='sponsored']").attr("content");
  var default_title = (sponsoredmetatag) ? document.title + ' (' + sponsoredmetatag + ')' : document.title;
  /*
  *
  * Use open graph title if present
  */
  var ogtitle = $("meta[property='og:title']").attr("content");
  var twittertitle = $("meta[name='twitter:title']").attr("content");
  if (ogtitle) {
    // If sponsored meta tag present and promoted copy is not in the og:title, then add it
    if (sponsoredmetatag && ogtitle.toLowerCase().indexOf("(" + sponsoredmetatag.toLowerCase() + ")") < 0) {
      default_title = ogtitle + " (" + sponsoredmetatag + ")";
    }
    else {
      default_title = ogtitle;
    }
  }
  else if (twittertitle) {
    // If sponsored meta tag present and promoted copy is not in the twitter:title, then add it
    if (sponsoredmetatag && twittertitle.toLowerCase().indexOf("(" + sponsoredmetatag.toLowerCase() + ")") < 0) {
      default_title = twittertitle + " (" + sponsoredmetatag + ")";
    }
    else {
      default_title = twittertitle;
    }
  }

  // Find subhead
  var default_subhead = "";
  // Try open graph data first
  if ($("meta[property='og:description']").attr("content")) {
    default_subhead = ': ' + $("meta[property='og:description']").attr("content");
  }
  // next try the Twitter meta data
  else if (default_subhead === "" && $("meta[name='twitter:description']").attr("content")) {
    default_subhead = ': ' + $("meta[name='twitter:description']").attr("content");
  }

  // Default values
  var default_url = document.location.href;
  var $rel_canonical = $('link[rel="canonical"]');
  if ($rel_canonical.length) {
    default_url = $rel_canonical.attr('href');
  }
  var defaults = {
    url: default_url,
    title: default_title,
    subhead: default_subhead
  };


  /*
  * function for tracking shares of UPS sponsored content
  */
  var upsShare = function (service) {
    // Check for simplereach tags. If they don't exist, this isn't UPS sponsored
    if (typeof __reach_config !== 'undefined' ||
    typeof __reach_config.tags !== 'undefined') {
      // If free tags are present for sponsored content
      if (__reach_config.tags.indexOf('Business') !== -1 ||
      __reach_config.tags.indexOf('UPS') !== -1) {

        var appID = '';
        var ebRand = Math.random() + '';
        ebRand = ebRand * 1000000;
        switch (service) {
          case 'facebook':
          appID = '617974';
          break;

          case 'twitter':
          appID = '617975';
          break;

          case 'mailto':
          appID = '617978';
          break;

          default:
          appID = '';
        }
        // Only fire UPS tracking for Facebook, Twitter, and email shares
        if (appID !== '') {
          var s = document.createElement('script');
          s.type = 'text/javascript';
          s.src = document.location.protocol + '//bs.serving-sys.com/Serving/ActivityServer.bs?cn=as&amp;ActivityID=' + appID + '&amp;rnd=' + ebRand;
          (document.getElementsByTagName('head')[0] || document.getElementsByTagName('body')[0]).appendChild(s);
        }
      }
    }
  };

  // function to make social share link
  var makeLink = function (args) {
    var $link = $('<a href="#"/>')
    .addClass(cpre + args.name)
    .addClass(cpre + 'link')
    .attr('target', '_blank')
    .attr('data-share-type', args.shareType)
    .html(args.display);
    return $link;
  };

  //Share Type
  var share_type = function($this) {
    //Set the type of share that is being processed
    if($this.hasClass('inlineSharingButtons')) {
      return {'shareType': 'inlineShare'};
    }
    if($this.hasClass('highlight_share')) {
      return {'shareType': 'highlightShare'};
    }
    return {'shareType': 'tpSocial'};
  };

  // Make an object based on data- attributes from the given jQuery object
  var get_data = function ($el, prefix_main, prefix_secondary) {
    var data = $el.data();
    var ret = {};
    var prop, i;
    for (i in data) {
      if (i.indexOf(prefix_main) === 0) {
        prop = i.substring(prefix_main.length);
        ret[prop] = data[i];
      } else if (i.indexOf(prefix_secondary) === 0) {
        prop = i.substring(prefix_secondary.length);
        ret[prop] = data[i];
      }
    }
    return ret;
  };

  $.fn.tpsocial = function (args) {
    var services = args.services;

    return this.each(function () {
      var $this = $(this);
      var shareType = share_type($this);

      // Loop through the requested services
      for (var s in services) {
        var service = services[s];
        var name = service.name;

        // See if the requested service has been added
        if (!(name in valid_services)) {
          continue;
        }
        var srvc = $.extend({}, valid_services[name], service, shareType);

        // Find the link for the requested service in the node
        var $link = $this.find('a.' + cpre + name + ', .' + cpre + name + ' a');

        // If none exists, create and append it
        if (!$link.length) {
          $link = makeLink(srvc);
          var $container = $this.find('.' + cpre + name);
          if ($container.length) {
            $container.append($link);
          } else {
            $this.append($link);
          }
        }

        // Add service specific arguments to the links'd data object
        for (var i in service) {
          if (typeof service[i] === 'function')
          continue;
          $link.data(dpre + name + i, service[i]);
        }

        // If you are simply updating the services, bail out
        if ($this.data(dpre + 'processed'))
        continue;

        // Set up link
        var data = $.extend({}, defaults, srvc, get_data($this, dpre + srvc.name, dpre), get_data($link, dpre + srvc.name, dpre));
        if (typeof data.prepare === 'function') {
          data.prepare($link[0], data);
        }

        // Bind an event to the link
        $link
        .on('click', (function (srvc, $parent, $lnk) {

          return function (e) {
            //Disabled links are added during scroll
            //This should prevent phantom clicks
            if($lnk.hasClass('disabled')) {
              return false;
            }

            // TODO: reduce the code duplication
            var data = $.extend({}, defaults, args, srvc, get_data($parent, dpre + srvc.name, dpre), get_data($lnk, dpre + srvc.name, dpre));
            data.element = this;

            if (data.url == '{current}')
            data.url = document.location.href;
            if (data.url_append != undefined) {
              // TODO: more than just {{name}} replacement
              data.url_append = data.url_append.replace('{{name}}', data.name);

              if (data.url.indexOf('?') !== -1 && data.url_append.indexOf('?') !== -1) {
                data.url_append = data.url_append.replace('?', '&');
              }
              data.url += data.url_append;
            }
            if(typeof data.anchor !== 'undefined' && data.anchor != '') {
              data.url = data.url+'#'+data.anchor;
            }
            //Call the share, Generate the link and open the share
            var ret = srvc.share(data);

            //Facebook tracking for keywee use
            if(typeof fbq !== 'undefined') {
              fbq('track', 'Lead');
            }

            //Delay for tracking
            setTimeout(function(e) {
              $window.trigger(cpre + 'click', data);
              upsShare(data.name);
            }, 200);

            //if in Desktop view just do popup/But in mobile do a link click
            if($('.social-wrapper').hasClass('desktop') || !ret || $('body').hasClass('node-type-campaign-page')) {
              e.preventDefault();
              return false;
            }

            return ret;
          }

        })(srvc, $this, $link)
      );

      if (typeof data.hoverfocus === 'function') {
        $link
        .on('mouseover focus', (function (srvc, $parent, $lnk) {
          return function (e) {
            var data = $.extend({}, defaults, args, srvc, get_data($parent, dpre + srvc.name, dpre), get_data($lnk, dpre + srvc.name, dpre));

            if (data.url == '{current}')
            data.url = document.location.href;
            if (data.url_append != undefined) {
              // TODO: more than just {{name}} replacement
              data.url_append = data.url_append.replace('{{name}}', data.name);

              if (data.url.indexOf('?') !== -1 && data.url_append.indexOf('?') !== -1) {
                data.url_append = data.url_append.replace('?', '&');
              }
              data.url += data.url_append;
            }

            data.element = this;

            srvc.hoverfocus(data);
          }
        })(srvc, $this, $link)
      );
    }
  }

  $this.data(dpre + 'processed', true);
  $this.addClass(cpre + 'processed');
});
};

var valid_services = {};

$.tpsocial = {
  add_service: function (args) {
    valid_services[args.name] = args;
  },
  // Load script and run callback
  queues: {},
  onces: {},
  load_script: function (test, url, context, callback, once) {
    if (test !== undefined) {
      callback.call(context);
      return true;
    }

    if ($.tpsocial.queues[url] !== undefined) {
      $.tpsocial.queues[url].push(callback);
      return;
    }

    $.tpsocial.queues[url] = [];
    $.tpsocial.onces[url] = once;

    var ready = function (s) {
      // Use this in IE if we want to track throughout the load.
      if (s.readyState === 'loaded' || s.readyState === 'complete')
      done();
    };

    var done = function () {
      for (var i in $.tpsocial.queues[url]) {
        var cb = $.tpsocial.queues[url][i];
        if (typeof cb === 'function')
        cb.call(context);
      }

      if (typeof $.tpsocial.onces[url] === 'function')
      $.tpsocial.onces[url].call(context);
    };

    var s = document.createElement('script');
    s.type = "text/javascript";
    s.onreadystatechange = function (s) {
      return function () {
        ready(s);
      };
    }(s);
    s.onerror = s.onload = done;
    s.src = url;
    document.getElementsByTagName('head')[0].appendChild(s);
  }
};
})(window, jQuery);

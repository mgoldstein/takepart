# TakePart.com Digital Data

```JavaScript
window.digitalData = {

  version: "1.0",               // Version of the spec being used.

  pageInstanceID: "",           // Unique identifier of page across all environments, for TakePart this is the
                                // environment name plus the internal Drupal path.

  page: {

    pageInfo: {

      pageID: "",               // Unique identifier of the page with an environment, for TakePart this is the
                                // internal Drupal path.

      pageName: "",             // The title of the page, this value should remain the same for the life of the page.
                                // Values that are adjusted for marketing or SEO reasons should NOT be used. One
                                // possible value is the title of the first revision of the page.

      destinationURL: "",       // The absolute URL of the page. This can be be set client side using document.location.

      referringURL: "",         // The absolute URL of the referring page. This can be set client side using
                                // document.referrer.

      author: "",               // The primary author of the page.

      authors: [""],            // All authors of the page, including the primary author.

      issueDate: "",            // The published date of the page. This can be a string or a Date() object.
    },

    category: {

      primaryCategory: "",      // The primary category of the page, for TakePart this is the content type.

      primaryTopic: "",         // The primary topic of the page.

      topics: [""],             // All topics of the page in order of relevance.

      series: "",               // The content series of the page.

      campaign: "",             // The film or digital campaign to which the page belongs.

      freeTags: [""]            // The free tags of the page.

    }

  }

  event: [{                     // List of events that have been tracked for the page. This key is used for passing
                                // event parameters to the Dynamic Tag Manager. This list is initially empty.

    eventName: "",              // The human readable name of the event.

    eventAction: "",            // The name of the event as a lower case string with no spaces. This value is used by
                                // the Dynamic Tag Manager when reading event parameter data elements.

    timeStamp: "",              // The time at which the event occurred. This value will be automatically added to
                                // events add through the Digital Data wrapper library.

    effect: "",                 // The effect the event had.

    parameters: {               // The parameters of the event. If the event has no parameters, this key can left out.

      someParameter:  ""        // An example parameter. The individual parameters should be limited to scalar values.

    }

  }
  /* ... */
  ]

};
```

# Digital Data Wrapper Library

```JavaScript
(function(window, digitalData, undefined) {

  // Need something to wrap even if it is as empty as the hole you so desprately
  // wish you could fill.
  digitalData = typeof(digitalData) !== 'undefined' ? digitalData : {};

  // Namespace the libary.
  window.TPAnalyticsData = window.TPAnalyticsData || {};

  // Wrapper constructor.
  function DigitalDataWrapper(digitalData) {
    this.data = digitalData;
  };

  // Convience method for retrieving nested values.
  DigitalDataWrapper.prototype.get = function(path) {
    path = typeof(path) !== 'undefined' ? path : '';
    var keys = path.split('.');
    var value = this.data;
    for (var i=0; i<keys.length; i++) {
      if (value.hasOwnProperty(keys[i])) {
        value = value[keys[i]];
      }
      else {
        return null;
      }
    }
    return value;
  };

  // Get the page's pathname based on the destinationURL.
  DigitalDataWrapper.prototype.pathname = function() {
    var url = this.get('page.pageInfo.destinationURL');
    return '/' + url.split('//', 2)[1].split('/', 2)[1];
  };

  // The page's pageName as used in SiteCatalyst.
  DigitalDataWrapper.prototype.pageName = function() {
    return ['takepart', this.siteSection(), this.get('page.pageInfo.pageName')].join(':');
  };

  // The page's site section (channel) as used in SiteCatalyst.
  DigitalDataWrapper.prototype.siteSection = function() {
    var path = this.pathname();
    var pieces = path.split('/');
    return pieces.length > 1 ? pieces[1].toLowerCase() : 'home';
  };

  // The page's site subsection as used in SiteCatalyst.
  DigitalDataWrapper.prototype.siteSubsection = function() {
    var path = this.pathname();
    var pieces = path.split('/');
    if (pieces.length > 2) {
      return pieces[1].toLowerCase() + ':' + pieces[2].toLowerCase();
    }
  };

  // Add an event to digital data event list
  DigitalDataWrapper.prototype.addEvent = function(evt) {
    this.data.event = this.data.event || [];
    evt.timeStamp = evt.timeStamp || new Date();
    this.data.event.push(evt);
  };

  // Get an event parameter value. The event list is search from the end for
  // the last event with the requested action.
  DigitalDataWrapper.prototype.eventParameter = function(action, name) {
    var last = this.data.event.length - 1;
    while (last >= 0) {
      var evt = this.data.event[last];
      if (evt.eventAction == action && evt.hasOwnProperty('parameters')) {
        if (evt.parameters.hasOwnProperty(name)) { return evt[name]; }
        break; // stop looking
      }
    }
  };

  // Get the parent page data that needs to be passed to the login modal.
  DigitalDataWrapper.prototype.getLoginData = function() {
    return JSON.stringify({
      url: this.get('page.pageInfo.destinationURL'),
      title: this.get('page.pageInfo.pageName'),
      contentType: this.get('page.category.primaryCategory'),
      campaign: this.get('page.category.campaign')
    });
  }

  // Create a wrapper around the page's digital data.
  window.TPAnalyticsData.page = new DigitalDataWrapper(digitalData);

  // Loads the parent page's digital data (if available).
  function loadParentData() {
    var json = jQuery.cookie('parent_dtm');
    if (json) {
      json = decodeURIComponent(json);
      var data = null;
      try { data = JSON.parse(json); } catch (e) { return {}; }
      return {
        version: "1.0",
        page: {
          pageInfo: {
            pageName: data['title'],
            destinationURL: data['url']
          },
          category: {
            primaryCategory: data['contentType'],
            campaign: data['campaign']
          }
        }
      };
    }
  }

  // Create a wrapper around the parent page's digital data (if available).
  parentData = loadParentData();
  if (typeof(parentData) !== 'undefined') {
    digitalData.parentData = parentData;
    window.TPAnalyticsData.parentPage = new DigitalDataWrapper(digitalData.parentData);
  }

})(window, window.digitalData);
```

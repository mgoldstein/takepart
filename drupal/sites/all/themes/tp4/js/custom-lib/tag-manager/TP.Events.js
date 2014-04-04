(function(window, undefined) {

  TP = TP || {};
  TP.Events = {

    'AdobeTagManagerConnector': function(libName) {
      this.libName = libName;
      this.track = function(eventName, data) {
        if (TPSC) { TPSC.track(this.libName, eventName, data); }
      };
    },

    'LogToConsoleConnector': function(libName) {
      this.libName = libName;
      console.log('Using Event Library: ' + libName);
      this.track = function(name, data) {
        console.log('Event [' + name + '] fired.')
        var event = {
          'active library': this.libName,
          'event name': name,
          'event data': data,
        }
        console.log(event);
      }
    }
  };

  TP.Events.connector = new TP.Events.AdobeTagManagerConnector('takepart');

})(window);

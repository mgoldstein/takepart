(function ($, Drupal, window, document, undefined) {

  /**
   *  @function:
   *    Function is used to call the reach
   */
  window.tp_reach_call = function(data) {
    //assigns the data to the reach config
    window['__reach_config'] = data;
    
    //break the function if it contains Business
    if (typeof __reach_config !== 'undefined' || typeof __reach_config.tags !== 'undefined') {
      if (__reach_config.tags.indexOf('Business') == -1) {
        return;
      }
    }
    
    //only make the call if the SPR has been defined on the page
    if (typeof SPR !== 'undefined') {
      //call the collect and pass values
      SPR.Reach.collect(__reach_config);
    }
    //otherwise we add the script to the page and then call
    else {
      //code taken from implementation documentation
      var s = document.createElement('script');
      s.async = true;
      s.type = 'text/javascript';
      s.src = document.location.protocol + '//d8rk54i4mohrb.cloudfront.net/js/reach.js';
      (document.getElementsByTagName('head')[0] || document.getElementsByTagName('body')[0]).appendChild(s);

    }
  }

})(jQuery, Drupal, this, this.document);
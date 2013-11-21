(function (window, $, undefined) {

$(function() {
  
  // INTERSTITIALS
  interstitial_init();
  function interstitial_init(){

    // DISABLE INTERSTITIALS ON FIREFOX
    if(navigator.userAgent.toLowerCase().indexOf('firefox') > -1) {
      return;
    }

    // // FOR TESTING
    // var interstitial_links = $('#block-pm-interstitial-interstitials .content a');
    // if(interstitial_links.length > 0){
    //  show_interstitial(interstitial_links.filter('[data-interstitial-type="email"]'));
    // }
    // return;

    var interstitial_cookie = $.cookie('pm_igloo');
    var referer_cookie = $.cookie('pm_referers') || '';
    var referers = $('body').attr('data-interstitial-referer');
    if (typeof referers === 'undefined'){ // opt out
      return;
    }

    if (interstitial_cookie === null){ // first page view

      // create ignore interstitial cookie and set to off
      $.cookie('pm_igloo', 0, { path:'/' });

      // create referer list cookie
      $.cookie('pm_referers', referers, { path:'/' });

    } else if(interstitial_cookie === '0') { // second page view (or subsequent page view without closing the interstitial)
      var excluded_links = referer_cookie.split(',');
      var $interstitial_links = $('#block-pm-interstitial-interstitials .content a');
      if($interstitial_links.length <= 0){
        return;
      }

      // exclude referrer classes and map the remaining hrefs
      var interstitial_links = $.map($interstitial_links, function(link, i){
        if ($.inArray($(link).attr('data-interstitial-type'), excluded_links) === -1){
          return $(link);
        }
      });
      // show random href from list of available interstitials
      show_interstitial(interstitial_links[Math.floor(Math.random() * interstitial_links.length)]);
    }
  }

});

})(window, jQuery);
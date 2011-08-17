//console.log('loaded takepart_omniture.js');

(function ($) {
  Drupal.behaviors.scSearchClick = {
    attach: function (context, settings) {
      $('#top-search #search-api-page-search-form-2 .tpform-submit', context).click(function(){
        //console.log('search click');
        var search_terms = $('#search-block-form #edit-search-block-form--2').val();
        s.eVar7 = search_terms.toLowerCase();
        s.prop7 = search_terms.toLowerCase();
        
        s.events='event1';
        s.tl(true, 'o', 'Searches');
      });
    }
  }

}(jQuery));
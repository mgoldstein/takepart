//console.log('loaded takepart_omniture.js');
(function ($) {

  Drupal.behaviors.scSearchClick = {
    attach: function (context, settings) {
      $('#top-search #search-api-page-search-form-2 .tpform-submit', context).click(function(){
        //console.log('search click');
        var search_terms = $('#search-block-form #edit-search-block-form--2').val();
        //s.eVar7 = search_terms.toLowerCase();
        //s.prop7 = search_terms.toLowerCase();
        
        s.events='event1';
        s.tl(true, 'o', 'Searches');
      });
    }
  }

  Drupal.behaviors.scCommentClick = {
    attach: function (context, settings) {
      $('form.comment-form input.form-submit', context).click(function(){
        s.events='event24';
        s.eVar22=s.pageName;
        s.prop21=s.eVar5;
      });
    }
  }

  Drupal.behaviors.scBlogCommentClick = {
    attach: function (context, settings) {
      $('.node-type-openpublish-blog-post form.comment-form input.form-submit').click(function(){
        s.eVar31="Action";
      });
    }
  }

}(jQuery));


/*
  Drupal.behaviors.scCommentClick = {
    attach: function (context, settings) {
      $()
    }
  }

*/
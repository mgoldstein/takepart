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

  Drupal.behaviors.scSocialClick = {
    attach: function (context, settings) {
      //console.log('socialclick');

    
      $('.takepart_addthis_leftpanel .addthis_toolbox a, .takepart_addthis_footer .addthis_toolbox a').click(function(){
        var title = $(this).attr('title');
        //console.log(title);
        s.events="event25";
        s.prop26=title;
        s.eVar27=title;
        //console.log(s);
        //return false;
      });
    }
  }

// takepart_addthis_leftpanel a
// takepart_addthis_footer

}(jQuery));





/*
  Drupal.behaviors.scCommentClick = {
    attach: function (context, settings) {
      $()
    }
  }

*/
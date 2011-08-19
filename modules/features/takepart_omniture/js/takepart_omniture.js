//console.log('loaded takepart_omniture.js');
(function ($) {

  Drupal.behaviors.scSearchClick = {
    attach: function (context, settings) {
      $('#top-search #search-api-page-search-form-2 .tpform-submit', context).click(function(){
        var search_terms = $('#search-block-form #edit-search-block-form--2').val();
        s.linkTrackVars="eVar7,prop7,events";
        s.linkTrackEvents="event1";        
        s.events='event1';
        s.tl(true, 'o', 'Searches');
      });
    }
  }

  Drupal.behaviors.scCommentClick = {
    attach: function (context, settings) {
      $('form.comment-form input.form-submit', context).click(function(){
        s.linkTrackVars="eVar22,prop21,events";
        s.linkTrackEvents="event24";
        s.events='event24';
        s.eVar22=s.pageName;
        s.prop21=s.eVar5;
        s.tl(true, 'o', 'Searches');
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
      $('.takepart_addthis_leftpanel .addthis_toolbox a, .takepart_addthis_footer .addthis_toolbox a').click(function(){
        var title = $(this).attr('title');
        //console.log(title);
        s.events="event25";
        s.prop26=title;
        s.eVar27=title;
        s.linkTrackVars="eVar27,prop26,events";
        s.linkTrackEvents="event25";
        s.tl(true, 'o', 'Content Share');
        //console.log(s);
        //return false;
      });
    }
  }

  Drupal.behaviors.scEmbeddedActionClick = {
    attach: function (context, settings) {
      $('.embed-action a').click(function(){
        s.linkTrackVars="eVar28,events";
        s.linkTrackEvents="event34";
        s.eVar28="editorial";
        s.events="event34";
        s.tl(true, 'o', 'Embedded Action Click');
      });
    }
  }

  Drupal.behaviors.scFiveThingsClick = {
    attach: function (context, settings) {
      $('.field-name-field-tp-campaign-4-things-link a').click(function(){
        s.linkTrackVars="eVar28,events";
        s.linkTrackEvents="event38";
        s.eVar28="fivethings";
        s.events="event38";
        s.tl(true, 'o', 'Five Things Click');
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
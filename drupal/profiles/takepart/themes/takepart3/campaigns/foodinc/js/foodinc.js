(function ($, Drupal, window, document, undefined) {
  $(document).ready(function() {
    $('#foodinc-entryform select').each(function() {
      $(this).tpselect();
    });
  });

  $.extend(true, Drupal, {behaviors: {
      // expandJudges:
      // {
      //   attach: function (context) {
      //     $(".show-more").click(function () {
      //         if($(this).prev().hasClass("show-more-height")) {
      //             $(this).text("See Less");
      //         } else {
      //             $(this).text("See More");
      //         }

      //         $(this).prev().toggleClass("show-more-height");
      //     });
      //   }
      // },

      tpSocial:
      {
        attach: function(context) {
          var tp_social_config = {
            url_append: '?cmpid=organic-share-{{name}}',
            services: [
              {name: 'facebook'},
              {
                name: 'twitter',
                text: '{{title}}',
                via: 'TakePart'
              },
              {name: 'googleplus'},
              {name: 'email'}
            ]
          };
          $('.tp-social:not(.tp-social-skip)').tpsocial(tp_social_config);
        }
      }
    }
  })
})(jQuery, Drupal, this, this.document);


(function ($) {
  $('a.tp-social-facebook').click(
      function(e) {
          var s=s_gi('takepartprod');
          s.linkTrackVars='eVar27,eVar30,events';
          s.linkTrackEvents='event25';
          s.events='event25';
          s.eVar27="Facebook share";
          s.eVar30=s.pageName;
          s.tl(true, 'o', 'Food Inc Awards Social Sharing');
      }
      );

          $('a.tp-social-twitter').click(
      function(e) {
          var s=s_gi('takepartprod');
          s.linkTrackVars='eVar27,eVar30,events';
          s.linkTrackEvents='event25';
          s.events='event25';
          s.eVar27="Twitter Tweet";
          s.eVar30=s.pageName;
          s.tl(true, 'o', 'Food Inc Awards Social Sharing');
      }
      );

          $('a.tp-social-googleplus').click(
      function(e) {
          var s=s_gi('takepartprod');
          s.linkTrackVars='eVar27,eVar30,events';
          s.linkTrackEvents='event25';
          s.events='event25';
          s.eVar27="GooglePlus share";
          s.eVar30=s.pageName;
          s.tl(true, 'o', 'Food Inc Awards Social Sharing');
      }
      );
  });


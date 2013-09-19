(function ($, Drupal, window, document, undefined) {
  $(document).ready(function() {
    $('#foodinc-entryform select').each(function() {
      $(this).tpselect();
    });
  });

  $.extend(true, Drupal, {behaviors: {
      responsiveNav:
      {
        attach: function (context) {
          // Responsive nav
          var nav = '#site-header';
          var $nav = $('#site-header');

          var click = 'click';
          var is_touchmove = false;
          if ( 'ontouchend' in document.documentElement ) click = 'touchend';

          var $body = $('body');
          $body
            .delegate(nav, 'touchmove', function () {
              is_touchmove = true;
            })
            .delegate(nav, click, function () {
              if ( click == 'touchend' && is_touchmove ) {
                is_touchmove = false;
                return true;
              }

              if ( $body.is('.clickedon') ) {
                $body.removeClass('clickedon');
              } else {
                $body.addClass('clickedon');
              }
            })
            .delegate(nav + ' a', click, function (e) {
              e.stopPropagation();
            })
            .delegate(nav, 'focusin', function (e) {
              $body.addClass('clickedon');
            })
            .delegate(nav, 'focusout', function (e) {
              $body.removeClass('clickedon');
            });
        }
      },

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
          s.linkTrackVars='eVar27,events';
          s.linkTrackEvents='event25';
          s.events='event25';
          s.eVar27="Facebook share";
          s.tl(true, 'o', 'Food Inc Awards Social Sharing');
      }
      );

          $('a.tp-social-twitter').click(
      function(e) {
          var s=s_gi('takepartprod');
          s.linkTrackVars='eVar27,events';
          s.linkTrackEvents='event25';
          s.events='event25';
          s.eVar27="Twitter Tweet";
          s.tl(true, 'o', 'Food Inc Awards Social Sharing');
      }
      );

          $('a.tp-social-googleplus').click(
      function(e) {
          var s=s_gi('takepartprod');
          s.linkTrackVars='eVar27,events';
          s.linkTrackEvents='event25';
          s.events='event25';
          s.eVar27="GooglePlus share";
          s.tl(true, 'o', 'Food Inc Awards Social Sharing');
      }
      );
  });


(function ($, Drupal, window, document, undefined) {
  $(document).ready(function() {
    $('#foodinc-entryform select').each(function() {
      $(this).tpselect();
    });
  });

  // The window level TP Social click event needs to be attached to the
  // TP Analytics social click handler.
  $(window).bind('tp-social-click', function(e, args) {
    takepart.analytics.track('tp-social-click', args);
  });

  Drupal.behaviors.newsletterSocialSignupSubmitted = {
    attach: function (context) {
      if ($(context).is('.newsletter-signup.thank-you-message')){
        var name = context.attr('data-newsletter-name');
        var source = context.attr('data-signup-source');
        takepart.analytics.track('newsletter_signup',
          {name: name, source: source});
      }
    }
  };

  // TODO: Move to TP Analytics by adding ability to alter page view call variables.
  $.extend(true, takepart, {analytics: {
    foodinc_awards_entry: function (s) {
      var status = $.cookie('foodinc_awards');
      if (status == 'true') {
        s.events = 'event29';
        s.eVar24 = 'Food, Inc. Awards';
      }
      $.cookie('foodinc_awards', null, {path:'/'});
    }
  }});

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

          var $body = $('body');
          if ( $body.is('.page-wordlet-foodinc-entryreceived') ) {
            var social_title = $('#foodinc-social-received').attr('social-title');
            var social_image = $('#foodinc-social-received').attr('social-image');
            var social_text = $('#foodinc-social-received').attr('social-text');
            var social_caption = $('#foodinc-social-received').attr('social-caption');
            var social_twitter_via = $('#foodinc-social-received').attr('social-twitter-via');
            var social_url = $('#foodinc-social-received').attr('social-url');
            var tp_social_config = {
              url_append: '?cmpid=organic-share-{{name}}',
              services: [
                {
                  name: 'facebook',
                  image: social_image,
                  description: social_text,
                  title: social_title,
                  url: social_url,
                  caption: social_caption
                },
                {
                  name: 'twitter',
                  text: social_title,
                  via: social_twitter_via,
                  url: social_url
                },
                {
                  name: 'googleplus',
                  title: social_title,
                  media: social_image,
                  url: social_url
                },
                {
                  name: 'email',
                  url: social_url,
                  title: social_title,
                  text: social_text
                }
              ]
            };
            $('.tp-social:not(.tp-social-skip)').tpsocial(tp_social_config);
          }
          else{
            // Social share buttons
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
    }
  })
})(jQuery, Drupal, this, this.document);

/*
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

*/

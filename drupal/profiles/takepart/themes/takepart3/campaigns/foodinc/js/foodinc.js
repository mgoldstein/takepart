(function ($, Drupal, window, document, undefined) {
  $(document).ready(function() {
    $('#foodinc-entryform select').each(function() {
      $(this).tpselect();
    });

    fbAsyncInit();
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
            var facebook_title = $('#foodinc-social-received').attr('data-facebook-title');
            var facebook_image = $('#foodinc-social-received').attr('data-facebook-image');
            var facebook_url = $('#foodinc-social-received').attr('data-facebook-url');
            var facebook_caption = $('#foodinc-social-received').attr('data-facebook-caption');

            var twitter_text = $('#foodinc-social-received').attr('data-twitter-text');
            var twitter_url = $('#foodinc-social-received').attr('data-twitter-url');
            var twitter_via = $('#foodinc-social-received').attr('data-twitter-via');

            var googleplus_title = $('#foodinc-social-received').attr('data-google-title');
            var googleplus_text = $('#foodinc-social-received').attr('data-googleplus-text');

            var email_title = $('#foodinc-social-received').attr('data-email-title');
            var email_url = $('#foodinc-social-received').attr('data-email-url');
            var email_text = $('#foodinc-social-received').attr('data-email-text');

            var tp_social_config = {
              url_append: '?cmpid=organic-share-{{name}}',
              services: [
                {
                  name: 'facebook',
                  image: facebook_image,
                  title: facebook_title,
                  url: facebook_url,
                  caption: facebook_caption
                },
                {
                  name: 'twitter',
                  text: twitter_text,
                  via: twitter_via,
                  url: twitter_url
                },
                {
                  name: 'googleplus',
                  title: googleplus_title,
                  text: googleplus_text
                },
                {
                  name: 'email',
                  url: email_url,
                  title: email_title,
                  text: email_text
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

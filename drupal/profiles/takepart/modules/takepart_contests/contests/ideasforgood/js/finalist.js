(function ($) {

  // initialize the addthis buttons when they are loaded
  Drupal.behaviors.ideasforgood = {
    attach: function (context, settings) {
      $('#ideasforgood-share-facebook').once('ideasforgood', function() {
        window.addthis.toolbox('#ideasforgood-share-facebook');
      });
      $('#ideasforgood-share-twitter').once('ideasforgood', function() {
        window.addthis.toolbox('#ideasforgood-share-twitter');
        var template = Drupal.settings.ideasforgood['twitter_template'];
        addthis.update('share', 'templates', {twitter:template});
      });
      $('#ideasforgood-share-email').once('ideasforgood', function() {
        window.addthis.toolbox('#ideasforgood-share-email');
        var email_from = Drupal.settings.ideasforgood['email_from'];
        addthis.update('config', 'ui_email_from', email_from);
        var email_note = Drupal.settings.ideasforgood['email_note'];
        addthis.update('config', 'ui_email_note', email_note);

        addthis.addEventListener('addthis.menu.share', addthisMenuShareEventHandler);
      });
      if (Drupal.settings.ideasforgood) {
        if ('vote_accepted' in Drupal.settings.ideasforgood) {
          var finalist_id = Drupal.settings.ideasforgood['finalist_id'];
          var item_dialog = '#ideasforgood-finalist-' + finalist_id + '-dialog';
          if (Drupal.settings.ideasforgood['vote_accepted']) {
            $(item_dialog).dialog("option", "title", "Thank You for Voting!");
            $(item_dialog).once('events-tracked', function() {
              // Action (event 19)
              s.events='event19';
              s.eVar28='Contest Vote';
              s.linkTrackVars='eVar28,events';
              s.linkTrackEvents='event19';
              s.tl(true, 'o', 'action');

              // Contest Vote (event 30)
              s.events='event30';
              s.eVar24=Drupal.settings.ideasforgood['contest_name'];
              s.linkTrackVars='eVar24,events';
              s.linkTrackEvents='event30';
              s.tl(true, 'o', 'contest vote');
            });
          }
          else {
            $(item_dialog).dialog("option", "title", "Oops!");
          }
          $(item_dialog).bind("dialogclose", function(event, ui) {
            var destination = Drupal.settings.ideasforgood['destination'];
            if (destination.length > 0) {
              window.location = destination;
            }
          });
        }
      }
    }
  };

  $(document).ready(function() {
    $('.ideasforgood-finalist-item').each(function() {

      var tooltip_width = 376;
      var target_corner = 'bottomLeft';
      var tooltip_corner = 'topLeft';

      if (($(document).width() - $(this).offset().left) < tooltip_width) {
        target_corner = 'bottomRight';
        tooltip_corner = 'topRight';
      }

      // create the idea tooltip
      var item_idea = '#' + $(this).attr('id') + '-idea';
      var tip = $(this).qtip({
        content: $(item_idea),
        position: {
          corner: {
            target: target_corner,
            tooltip: tooltip_corner
          }
        },
        hide: {
          fixed: true,
          delay: 200
        },
        style: {
          width: tooltip_width,
          padding: 10,
          background: '#ffffff',
          color: '#000000',
          textAlign: 'left',
          border: {
            width: 2,
            radius: 0,
            color: '#f58d34'
          },
          name: 'light',
          classes: {
            tooltip: 'ideasforgood-shadow'
          }
        }
      });

      // create the vote dialog
      var item_dialog = '#' + $(this).attr('id') + '-dialog';
      var dlg = $(item_dialog).dialog({
        autoOpen: false,
        resizable: false,
        modal: false,
        title: $(this).attr('title'),
        width: 520,
        open: function() {
          $('body').append(
            '<div' +
            ' class="ui-widget-overlay"' +
            ' style="' +
            '  width:' + $(document).width() + 'px;' +
            '  height:' + $(document).height() + 'px;' +
            '  z-index:500;"' +
            '></div>');
        },
        close: function() {
          $('body .ui-widget-overlay').remove();
        }
      });

      // clicking a finalist should bring up the vote dialog
      $(this).click(function() {
        tip.qtip('hide');
        dlg.dialog('open');
      });

      // connect the vote for me button
      $(item_idea).find('.ideasforgood-vote-button').click(function() {
        tip.qtip('hide');
        dlg.dialog('open');
      });

      // connect the cancel button
      $(item_dialog).find('.ideasforgood-cancel-button').click(function() {
        dlg.dialog('close');
      });
    });
  });
})(jQuery);

function addthisMenuShareEventHandler(evt) {

  // Action (event 19)
  s.linkTrackVars = 'eVar28,events';
  s.linkTrackEvents = 'event19';
  s.events = 'event19';
  s.eVar28 = 'Share';
  s.tl(true, 'o', 'action');

  // Share (event 25)
  var share_type = evt.data.service;
  if (evt.data.service == 'email') { share_type = 'Email'; }
  else if (evt.data.service == 'twitter') { share_type = 'Twitter'; }
  else if (evt.data.service == 'facebook') { share_type = 'Facebook'; }
  s.events = 'event25';
  s.eVar26 = document.title;
  s.eVar27 = share_type;
  s.prop26 = share_type;
  s.linkTrackVars = 'eVar26,eVar27,events';
  s.linkTrackEvents = 'event25';
  s.tl(true, 'o', 'share');
}

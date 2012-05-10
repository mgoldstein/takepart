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
      });
    }
  };

  $(document).ready(function() {
    $('.ideasforgood-finalist-item').each(function() {

      // create the idea tooltip
      var item_idea = '#' + $(this).attr('id') + '-idea';
      var tip = $(this).qtip({
        content: $(item_idea),
        position: {
          corner: {
            target: 'bottomLeft',
            tooltip: 'topLeft'
          }
        },
        hide: {
          fixed: true,
          delay: 200
        },
        style: {
          width: 480,
          padding: 10,
          background: '#ffffff',
          color: '#000000',
          textAlign: 'left',
          border: {
            width: 1,
            radius: 0,
            color: '#ff9900'
          },
          name: 'light'
        }
      });

      // create the vote dialog
      var item_dialog = '#' + $(this).attr('id') + '-dialog';
      var dlg = $(item_dialog).dialog({
        autoOpen: false,
        resizable: false,
        modal: true,
        title: $(this).attr('title'),
        width: 400,
        height: 300
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

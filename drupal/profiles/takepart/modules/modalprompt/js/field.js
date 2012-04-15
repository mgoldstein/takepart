jQuery(document).ready(function () {

  if (Drupal.settings.modalprompt['shown'] == 'never') {
    return;
  }

  var prompt = jQuery('div.modal-prompt-field').dialog({
    autoOpen: false,
    resizable: false,
    modal: true,
    title: Drupal.settings.modalprompt['title'],
    width: Drupal.settings.modalprompt['width'],
    height: Drupal.settings.modalprompt['height'],
    buttons: [{
      text: Drupal.settings.modalprompt['button'],
      click: function() { jQuery(this).dialog('close'); }
    }]
  });

  if (Drupal.settings.modalprompt['shown'] == 'always') {
    prompt.dialog('open');
  }
  else if (jQuery.cookie(Drupal.settings.modalprompt['cookie']) == null) {
    prompt.dialog('open');
    if (Drupal.settings.modalprompt['shown'] == 'once') {
      jQuery.cookie(Drupal.settings.modalprompt['cookie'], 1, {expires: 365*5});
    }
    else {
      jQuery.cookie(Drupal.settings.modalprompt['cookie'], 1);
    }
  }
});

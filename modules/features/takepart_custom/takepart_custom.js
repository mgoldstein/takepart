
(function($) {
/*
 * Currently the wysiwyg editor brakes fields in the vmedia_views_wdiget meta data edit
 * popup. so we are starting those fields witht he wysiwyg editor turned off
 * TODO: See why this is happening
 */
Drupal.behaviors.takepart = { attach: function(context) {
  $.each(Drupal.settings.wysiwyg.triggers, function(k,v) {
  if (k == 'edit-field-media-caption-und-0-format--2') {
    v.formatfull_html.status = 0;
  }
  });
}};
})(jQuery);

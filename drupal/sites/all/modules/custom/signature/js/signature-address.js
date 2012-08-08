(function ($) {
  $(document).ready(function () {
    $('.selectable-address-group').once('address-init', function () {
      var inside = $('.selectable-address-inside-us', this);
      var outside = $('.selectable-address-outside-us', this);
      $('#edit-field-sig-state > div.form-item', this).each(function () {
        var label = $('h3 > span', outside).text()
        var link = $('<span class="selectable-address-link">'
          + '<a href="#">' + label + '</a></span>');
        $(this).append(link);
        $('a', link).click({ i: inside, o: outside }, function (event) {
          event.preventDefault();
          event.data['i'].hide();
          event.data['o'].show();
        });
      });
      $('#edit-field-sig-country > div.form-item', this).each(function () {
        var label = $('h3 > span', inside).text()
        var link = $('<span class="selectable-address-link">'
          + '<a href="#">' + label + '</a></span>');
        $(this).append(link);
        $('a', link).click({ i: inside, o: outside }, function (event) {
          event.preventDefault();
          event.data['o'].hide();
          event.data['i'].show();
        });
      });
      outside.hide();
    });
  });
})(jQuery);

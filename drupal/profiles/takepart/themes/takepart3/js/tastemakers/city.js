(function($) {
  Drupal.behaviors.tastemakersCity = {
    attach: function(context) {
      var containerSelector = '.tastemakers.city';
      
      // $(document).ready and after every ajax call
      var container = $(containerSelector);
      container.once('tastemakers-city-js', _init);
      
      // $(document).ready only
      function _init(){
        // variables
        var container = $(this);
        var cities = [];
        $.each($('.region-highlighted .menu .dhtml-menu ul a', container), function(i, anchor){
          var city = {
            url: $(anchor).attr('href'),
            label: $(anchor).text()
          };
          cities.push(city)
        });

        // on load
        var cityMenuClass = 'city-menu';
        var cityMenu = $('.' + cityMenuClass, container);
        if (cityMenu.length <= 0){
          cityMenu = $('<div></div>').addClass(cityMenuClass);
          $('.city-content', container).append(cityMenu);
        }
        cityMenu.append('<span class="label">All Cities</span>');
        $.each(cities, function(i, city){
          var cityAnchor = $('<a href="' + city.url + '">' + city.label + '</a>');
          cityMenu.append(cityAnchor);
        });
      }
    }
  };
})(jQuery);
(function($, Drupal, window, document, undefined){

  Drupal.behaviors.setupFlashcards = {
    attach: function() {
      // bail early on touch devices
      if ('ontouchstart' in window || 'msmaxtouchpoints' in window.navigator) {
        return;
      }

      var $window = $(window);

      $('a.flashcard').each(function(){
        var $this = $(this);
        var data = Drupal.settings.flashcards[$this.data('flashcard')];

        var $popup = $('<aside />').addClass('flashcard-popup');
        var $headline = $('<h2>').text(data.title).appendTo($popup);
        if (data.pronunciation !== "") {
          $('<small>').text('[' + data.pronunciation + ']').appendTo($headline);
        }
        $(data.definition).appendTo($popup);
        $('<a>').addClass('flashcard-article-link')
          .attr('href', $this.attr('href'))
          .text('read more on “' + data.page_title + '”')
          .on('click', function() {
            $window.trigger('flashcard-click', {term: $this.text().toLowerCase()});
          })
          .wrap('<p>').parent().appendTo($popup)
        ;

        $('<div class="flashcard-close">')
          .html('&times;')
          .on('click', function() {
            $this.tooltipster('hide');
          })
          .prependTo($popup)
        ;

        $this.tooltipster({
          content: $popup,
          theme: 'tooltipster-flashcard',
          position: $this.position().left < $this.parent().width() / 2 ? 'bottom-left' : 'bottom-right',
          positionTracker: true,
          arrow: false,
          touchDevices: false,
          interactive: true,
          maxWidth: 350,
          functionBefore: function(origin, continueTooltip) {
            origin.addClass('hover');
            $window.trigger('flashcard-tooltip', {term: $this.text().toLowerCase()});
            continueTooltip();
          },
          functionAfter: function(origin) {
            origin.removeClass('hover');
          }
        });
      });

    }
  };

})(jQuery, Drupal, this, this.document)

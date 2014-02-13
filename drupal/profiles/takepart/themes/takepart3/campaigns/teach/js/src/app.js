(function($, window, document, undefined){


  // not using Drupal.behaviors because this JS has nothing to do with drupal
  $(document).ready(function() {
    // populate character count divs from maxlength
    $('input[maxlength], textarea[maxlength]').not('.story-year').each(function() {
      var $this = $(this),
          maxlength = $this.attr('maxlength');

      // build up character count elements:
      // <p class="character-count character-count-story-body"><span></span> Characters Left</p>
      // @todo This should be templated
      var $characterCountWrapper = $('<p class="character-count" />')
            .addClass('character-count-' + $this.attr('id').split('_').join('-'))
            .html(' Characters Left')
            .insertAfter($this)
          ,
          $characterCount = $('<span />').html(maxlength).prependTo($characterCountWrapper)
      ;

      // set initial value
      $characterCount.html(maxlength);

      // when the value of the input changes, adjust the character count
      // and add classes for alert/warning to the characer count wrapper
      $this.on('keyup', function() {
        var count = maxlength - $this.val().length;
        $characterCount.html(count);
        $characterCountWrapper.toggleClass('count-alert', count < maxlength / 4);
        $characterCountWrapper.toggleClass('count-warning', count < maxlength / 10);
      });
    });

    // Preview
    $('#sys-preview').on('click', function(e) {
      e.preventDefault();
      var $modal = $('<div />');
      $('<h1>').html('Preview Coming Soon').appendTo($modal);
      $('<p>').html('Stay tuned for preview functionality&hellip;').appendTo($modal);
      $.tpmodal.show({node: $modal[0]});
    });

    $('#sys-submit').on('click', function(e) {
      e.preventDefault();

      if ($('#sys-form').valid()) {
        alert('yes!');
      }

    });

  }); // $(document).ready() callback

})(jQuery, this, this.document)

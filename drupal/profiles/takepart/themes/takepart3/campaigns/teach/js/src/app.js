(function($, window, document, undefined){


  // not using Drupal.behaviors because this JS has nothing to do with drupal
  $(document).ready(function() {
    // populate character count divs from maxlength
    $('input[maxlength], textarea[maxlength]').not('.story-year').each(function() {
      var $this = $(this),
          maxlength = $this.attr('maxlength');

      // build up character count elements <p class="character-count character-count-story-body"><span></span> Characters Left</p>
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
      alert('preview coming soon!');
    });

    $('#sys-submit').on('click', function(e) {
      e.preventDefault();

      var $form = $('#sys-form');

      if ($form.valid()) {
        alert('form submission coming soon!');
      } else {
        $form.validate();
      }

    });

  }); // $(document).ready() callback

})(jQuery, this, this.document)

(function($, window, document, undefined){
  // not using Drupal.behaviors because this JS has nothing to do with drupal
  $(document).ready(function() {
    // populate character count divs from maxlength
    $('input[maxlength], textarea[maxlength]').each(function() {
      var $this = $(this),
          maxlength = $this.attr('maxlength'),
          $characterCountWrapper = $this.parent().find('.character-count'),
          $characterCount = $characterCountWrapper.find('span');

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
  }); // $(document).ready() callback
})(jQuery, this, this.document)

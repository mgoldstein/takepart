(function($, window, document, undefined){

  var touchEnabled = 'ontouchstart' in window || window.DocumentTouch && document instanceof DocumentTouch;

  var coppaCookieName = "pm_sys_user_birthdate",
      coppaCookieExpires = 1, // days to keep the cookie
      msDay = 24 * 60 * 60 * 1000, // one day in milliseconds
      ageRequirement = Date.now() - 13 * 365 * msDay; // 13 years in milliseconds

  // show coppa error message and delete form from page
  var showCoppaErrorMessage = function() {
      $('#sys-form-content').slideUp().remove();
      $('#sys-coppa-content').slideDown();
  };

  var sysFormSubmit = function(form) {
    var $form = $(form),
        formData = {};

    // let's get all the data
    $form.find("input, textarea, select").not('[type="checkbox"]').each(function() {
      formData[this.id] = $(this).val();
    });
    formData.email_subscribe = $form.find('#email_subscribe').is(':checked');
    formData.terms_agree = $form.find('#terms_agree').is(':checked');
    console.log(formData); // TODO remove after debugging

    var userBirthdate = formData.user_year + '-' + formData.user_month + '-' + formData.user_day;

    if (Date.parse(userBirthdate) > ageRequirement) {

      // set coppa cookie
      var expires = new Date();
      expires.setTime(expires.getTime() + coppaCookieExpires * msDay);
      document.cookie = escape(coppaCookieName) + "=" + escape(userBirthdate) + "; expires=" +  expires.toGMTString() + '; path=/';

      showCoppaErrorMessage();

      return false;
    }

    // we've passed the age check. Lets have a beer.

    alert('TODO: successful form submit goes here.');
    $('#sys-form-content').slideUp().remove();
    $('#sys-thanks-content').slideDown();
  };

  // not using Drupal.behaviors because this JS has nothing to do with drupal
  $(document).ready(function() {

    // coppa check
    var birthDate = null;
    $.each(document.cookie.split(";"), function() {
      if (this.trim().indexOf(escape(coppaCookieName)) === 0) {
        birthDate = unescape(this.substring(escape(coppaCookieName).length + 1, this.length));
      }
    });
    if (birthDate && (Date.parse(birthDate) > ageRequirement)) {
      showCoppaErrorMessage();
      return false;
    }

    // we've passed the age test. have a beer.
    var $form = $('#sys-form');

    // populate character count divs from maxlength properties
    $form.find('input[maxlength], textarea[maxlength]').each(function() {
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

    // style select boxes on non-touch-enabled devices
    if (!touchEnabled) {
        $form.find('select').customSelect();
    }

    // Preview
    $('#sys-preview').on('click', function(e) {
      e.preventDefault();
      var $modal = $('<div />');
      $('<h1>').html('Preview Coming Soon').appendTo($modal);
      $('<p>').html('Stay tuned for preview functionality&hellip;').appendTo($modal);
      $.tpmodal.show({node: $modal[0]});
    });

    $form.validate({
      submitHandler: sysFormSubmit,
      messages: {
        terms_agree: {
          required: "You must agree to to submit your story."
        }
      }
    });

  }); // $(document).ready() callback

})(jQuery, this, this.document)

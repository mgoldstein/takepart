
function takepart_newsletter_isValidEmailAddress(emailAddress, formId) {
    var pattern = new RegExp(/^(("[\w-\s]+")|([\w-]+(?:\.[\w-]+)*)|("[\w-\s]+")([\w-]+(?:\.[\w-]+)*))(@((?:[\w-]+\.)*\w[\w-]{0,66})\.([a-z]{2,6}(?:\.[a-z]{2})?)$)|(@\[?((25[0-5]\.|2[0-4][0-9]\.|1[0-9]{2}\.|[0-9]{1,2}\.))((25[0-5]|2[0-4][0-9]|1[0-9]{2}|[0-9]{1,2})\.){2}(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[0-9]{1,2})\]?$)/i);
    var isValid = pattern.test(emailAddress);
    
    if (!isValid) {
        jQuery("#takepart-newsletter-"+formId+"-body .form-messages").text("Email address is invalid.");

    }
    
    return isValid;
}

jQuery(document).ready(function() {
  jQuery("input#edit-email").val("Your Email").addClass('takepart-newsletter-empty');
  jQuery("input#edit-email").focus(function() {
    if (jQuery(this).val() == 'Your Email') {
      jQuery(this).val('').removeClass('takepart-newsletter-empty');
    }
  })
  jQuery("input#edit-email").blur(function() {
    if (jQuery(this).val() == '') {
      jQuery(this).val('Your Email').addClass('takepart-newsletter-empty');
    }
  })     
});

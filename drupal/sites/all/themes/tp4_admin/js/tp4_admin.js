jQuery(function ($) {
  $(document).ready(function () {
    var location = "" + window.top.location;
    if (location.search(/#back/) !== -1) {
	 window.top.location.replace('#');
	 alert("Do not use the back button to open the content editing interface. Reload the page to see the most recent changes.");
	 window.top.location.reload(true);
    }

    $('input#edit-submit').click(function (event) {
	 window.top.location.replace('#back');
    });

    $('input#edit-submit-1').click(function (event) {
	 window.top.location.replace('#back');
    });

    //Set the exclude from newsletter checkbox for sponsored content.
    if($('#edit-field-sponsored-und').length && $('#edit-field-newsletter-feed-exclude-und-1').length) {
      $('#edit-field-sponsored-und').on('change',function(){
        if($(this).val() != "_none") {
          $('#edit-field-newsletter-feed-exclude-und-1').prop('checked', true);
          alert("The \"Exclude from Newsletters\" checkbox was checked automatically because you chose a sponsor.");
        } else {
          $('#edit-field-newsletter-feed-exclude-und-1').prop('checked', false);
        }
      });
    }

    $('.node-form').on('click', '#edit-submit, #edit-addanother',function(){
      return confirm("Are you sure you want to save?");
    });

  });
});

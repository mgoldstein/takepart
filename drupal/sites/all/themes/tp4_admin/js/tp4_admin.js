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

    //Special warning for publishing content so that this is not done prematurely.
    $('.node-form').on('click', '#edit-submit, #edit-submit-1, #edit-addanother, #edit-addanother-1',function(){
      if($('#edit-workbench-moderation-state-new').length) {
        if($('#edit-workbench-moderation-state-new').val() == 'published') {
          return confirm("**WARNING** Clicking OK will PUBLISH this content.");
        }
      }
    });

  });
});

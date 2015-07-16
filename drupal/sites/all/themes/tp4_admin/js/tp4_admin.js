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

  });
});
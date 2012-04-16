jQuery(document).ready(function () {
  jQuery("input.rollover-button").hover(
    function () { this.src = this.src.replace("_off","_on");
    },
    function () { this.src = this.src.replace("_on","_off");
    }
  );

  jQuery("#edit-signature-public-display-und").click(
    function () {
      var note = jQuery('#petition-signature-display-disclaimer');
      if (this.checked) {
        note.hide();
      }
      else {
        note.slideDown('fast', function () {});
      }
    }
  );
});

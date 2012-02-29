jQuery(document).ready(function(){
var jqxhr = jQuery.getJSON('/lastcall/ajax/signature-count/'+tp_petition_signatures_deferred_id, function(response) {
  if (response.status == 0) {
    var count = parseInt(response.data);
    if (! isNaN(count)) {
      var percent = Math.floor((count / tp_petition_signatures_goal) * 100.0);
      jQuery('#tp_signatures_to_date').text("Signatures to Date: " + count);
      jQuery('#tp_signatures_percent').text("PROGRESS: " + percent + "%");
    }
  } else if (response.status == -1) {
  }
})
.error(function() {})
});

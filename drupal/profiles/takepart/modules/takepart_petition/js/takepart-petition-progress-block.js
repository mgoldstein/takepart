jQuery(document).ready(function(){
var jqxhr = jQuery.getJSON('/lastcall/ajax/signature-count/'+tp_petition_signatures_deferred_id, function(response) {
  if (response.status == 0) {
    jQuery('#tp_signatures_to_date').text("Signatures to Date: " + response.data);
  } else if (response.status == -1) {
  }
})
.error(function() {})
});

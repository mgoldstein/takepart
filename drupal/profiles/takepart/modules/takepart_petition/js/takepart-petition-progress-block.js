var update_progress_retries = 5;

function update_progress() {

  var jqxhr = jQuery.getJSON('/lastcall/ajax/signature-count/'+tp_petition_signatures_deferred_id, function(response) {
    if (response.status == 0) {
      var count = parseInt(response.data);
      if (! isNaN(count)) {
        var percent = Math.floor((count / tp_petition_signatures_goal) * 100.0);
        var bar_num = percent - (percent % 10);
        var bar_url = "/profiles/takepart/modules/takepart_petition/images/petition-status-bar-" + bar_num + ".png";
        jQuery('#tp_signatures_to_date').text("Signatures to Date: " + count);
        jQuery('#tp_signatures_percent').text("PROGRESS: " + percent + "%");
        jQuery('#tp_signatures_bar').attr('src', bar_url);
      }
    } else if (response.status == -1) {
      if (update_progress_retries) {
        update_progress_retries -= 1;
        setTimeout(update_progress, 500);
      }
    }
  }).error(function() {
    if (update_progress_retries) {
      update_progress_retries -= 1;
      setTimeout(update_progress, 500);
    }
  })
}

jQuery(document).ready(function(){
  setTimeout(update_progress, 500);
});

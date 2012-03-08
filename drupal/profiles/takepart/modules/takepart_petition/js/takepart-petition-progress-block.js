var update_progress_retries = 5;

function update_progress() {
  var countURL  = '/lastcall/ajax/signature-count/' + tp_petition_signatures_form_name;
  var d = new Date();
  countURL += '?t=' + d.getTime();
  var jqxhr = jQuery.getJSON(countURL, function(response) {
    if (response.status == 0) {
      var goal = parseInt(tp_petition_signatures_goal);
      var count = parseInt(response.data);
      if ( (!isNaN(count)) && (!isNaN(goal)) && (goal>0) ) {
        var percent = (count / goal) * 100.0;
        var percent_string = String(percent);
        var index = percent_string.indexOf('.');
        if (index == 0) {
          percent_string = '0' + percent_string;
        } else if (index >= 1) {
          percent_string = percent_string.substr(0,index+2);
        }
        percent_string += "%";
        var bar_num = String(Math.floor(percent) - (Math.floor(percent) % 10));
        var bar_url = "/profiles/takepart/modules/takepart_petition/images/petition-status-bar-" + bar_num + ".png";
        jQuery('#tp_signatures_to_date').text(count);
        jQuery('#tp_signatures_percent').text(percent_string);
        jQuery('#tp_signatures_bar').attr('src', bar_url);
      }
    } else if (response.status == -1) {
      if (update_progress_retries > 0) {
        update_progress_retries -= 1;
        setTimeout(update_progress, 1000+(500*(6-update_progress_retries)));
      }
    }
  }).error(function() {
    if (update_progress_retries > 0) {
      update_progress_retries -= 1;
      setTimeout(update_progress, 1000+(500*(6-update_progress_retries)));
    }
  })
}

jQuery(document).ready(function(){
  setTimeout(update_progress, 1000);
});

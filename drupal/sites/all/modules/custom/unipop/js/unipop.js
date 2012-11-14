// file: javascript support for Takepart Universal Popups Support

  // return youtube id from video node id
  function unipop_video_id_from_node(nid) {
    var output = '?';

    jQuery.ajax({
      url: "/unipop/video_id_from_node/" + nid,
      type: 'get',
      async: false,
      dataType: 'html',
      error: function(XMLHttpRequest, textStatus, errorThrown) {
        alert('unipop_video_id_from_node: cannot fetch node ' + nid);
        console.log(JSON.stringify(XMLHttpRequest));
        console.log(JSON.stringify(textStatus));
        console.log(JSON.stringify(errorThrown));
      },
      success: function (data) {
        //alert('data: ' + data);
        output = data;
      }
    });

    return output;
  }


(function ($) {
})(jQuery);



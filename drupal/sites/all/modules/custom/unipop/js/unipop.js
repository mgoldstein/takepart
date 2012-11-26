// file: javascript support for Takepart Universal Popups Support


// these are lookups for information about embdedded video nodes or youtube popups
// arrays are indexed by nid or youtube id, and are set in unipop_set_metric_page_load()
//   Drupal.settings.unipop.unipop_titles
//   Drupal.settings.unipop.unipop_types


var unipop_titles = new Array();   // list of titles
var unipop_types  = new Array();   // list of node types

function unipop_get_unipop_types() {
  alert(unipop_types.length);
  return unipop_types;
}

function unipop_showme(s) {
  //var unipop_types  = new Array();   // list of node types
  //unipop_types[0] = 33;
  alert('('+s+') unipop_showme: ' + unipop_types.length)
;}
//unipop_showme('unipop.js');

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

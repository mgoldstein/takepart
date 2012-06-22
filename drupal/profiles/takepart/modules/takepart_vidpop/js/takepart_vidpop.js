// file: javascript support for takepart_vidpop

//Vars
var videoOverlay = 'http://www.youtube.com/embed/WZIGFPCSoII';


$(document).ready(function(){
  // Overlay
  $('a.vidpopOverlayTrigger').overlay({
    mask: '#000',
    opacity: .8
  });


  // Overlay Video
  $('.vidpopOverlayTriggerHome').click(function(){
    $('#vidpopOverlayVideoContent').attr('src', videoOverlay);
  });
});

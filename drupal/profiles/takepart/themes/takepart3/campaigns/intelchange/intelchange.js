(function(window, $, undefined) {
// Setup

// Document load
$(function() {

var intelChange = $('.smartgirls');
var vidEmbed = intelChange.find('.vid-embed').css('position', 'relative');
var vid = vidEmbed.find('iframe')
    .css({
        position: 'absolute',
        opacity: '0'
    });
var vidPreview = $('<img id="intel_change_play_video" />').addClass('vid-preview').css('cursor', 'pointer');
vidPreview.attr('src', vidEmbed.data('previewSrc'));
vidEmbed.append(vidPreview);

// youtube tab show
$(window).bind('keydown', function() {
    setTimeout(function() {
        if ( document.activeElement == vid[0] ) {
            showIntelGirlsVideo();
        }
    }, 100);
});

// youtube video hover / click show
var hoverframe = null;
$('body')
    .delegate('.vid-embed iframe', 'mouseover', function() {
        hoverframe = this;
    })
    .delegate('.vid-embed iframe', 'mouseout', function() {
        hoverframe = null;  
    });

$(window).bind('blur', function() {
    if ( hoverframe ) {
        showIntelGirlsVideo();
    };
});

function showIntelGirlsVideo(){
    vid.css('opacity', "");
}

});
})(window, jQuery);
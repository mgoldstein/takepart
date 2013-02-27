(function(window, $, undefined) {
// Setup ----------------

// Document Ready ----------------
$(function() {

var speed = 'slow';
$body = $('body');

// Page Specific -----------------

// Home
if ( $body.is('.page-wordlet-intelchange-home') ) {
    var $video_template;
    var $first_block = $('.first-block');
    var $intro_block = $('.intro-block');

    $body
        // Show video
        .delegate('.video-play a', 'click', function(e) {
            $intro_block
                .animate({opacity: 0}, speed, function() {
                    var h = $first_block.height();
                    $video_template = $($('#video-template').html());
                    $video_template.css({opacity: 0}).insertAfter($intro_block);
                    $intro_block.css({display: 'none'});
                    $first_block.css({height: 'auto'});
                    var h2 = $first_block.height();
                    $first_block.height(h);
                    $first_block.animate({height: h2}, speed, function() {
                        $video_template.animate({opacity: 1});
                    });
                });

            e.preventDefault();
        })
        // Hide video
        .delegate('.video-block .close a', 'click', function(e) {
            $video_template.animate({opacity: 0}, speed, function() {
                var h = $first_block.height();
                $video_template.remove();
                $video_template.html('');
                $intro_block.css({display: 'block'});
                $first_block.css({height: 'auto'});
                var h2 = $first_block.height();
                $first_block.height(h);
                $first_block.animate({height: h2}, speed, function() {
                    $intro_block.animate({opacity: 1});
                });
            });
            e.preventDefault();
        })
        .delegate('.stay-contected a', 'click', function(e) {
            $('.default-state').hide();
            $(this.hash).show();
            e.preventDefault();
        })
        .delegate('#edit-mobile input', 'keypress', $.tpautoTab)
        ;

    $('.form-state').hide();

}

// Contest
if ( $body.is('.page-wordlet-intelchange-contest') ) {
    var contentNav = $('.countries-nav');
    var content = $('.countries');
    var contentSections = content.children();
    $body
        // Nav click
        .delegate('.countries-nav li a', 'click', function(e) {
            e.preventDefault();
            contentNav.find('li a').removeClass('active');
            contentSections.hide().filter('#' + $(this).attr('href')).show();
            $(this).addClass('active');
        });

    contentNav.find('li a').first().trigger('click');
}

// About
if ( $body.is('.page-wordlet-intelchange-about') ) {
    var contentNav = $('.content-nav');
    var contentInfo = $('.content-info');
    var contentSections = contentInfo.children();
    $body
        // Nav click
        .delegate('.content-nav li a', 'click', function(e) {
            e.preventDefault();
            contentNav.find('li a').removeClass('active');
            contentSections.hide().filter('#' + $(this).attr('href')).show();
            $(this).addClass('active');
        });

    contentNav.find('li a').first().trigger('click');
}

});
})(window, jQuery);
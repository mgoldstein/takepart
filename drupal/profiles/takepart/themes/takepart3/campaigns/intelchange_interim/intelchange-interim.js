(function(window, $, undefined) {
// Setup ----------------

var speed = 'slow';

var swap = function($from, $to, $parent, callback) {
    $from
        .animate({opacity: 0}, speed, function() {
            var h = $parent.height();
            callback = callback || null;

            $from.css({display: 'none'});
            $to.css({opacity: 0, display: 'block'});
            $parent.css({height: 'auto'});
            var h2 = $parent.height();
            $parent.height(h);

            $parent.animate({height: h2}, speed, function() {
                $to.animate({opacity: 1}, function() {
                    if ( callback ) callback();
                });
            });
        });
};

// Document Ready ----------------
$(function() {

$body = $('body');

// Page Specific -----------------

// Home
if ( $body.is('.page-wordlet-intelchange-interim-home') ) {
    var $video_template;
    var $first_block = $('.first-block');
    var $intro_block = $('.intro-block');

    var $form_wrapper = $('.form_wrapper');
    var $default_state = $('.default-state');
    var $form_state = $('.form-state');

    $body
        // Show video
        .delegate('.video-play a', 'click', function(e) {
            $intro_block
                .stop()
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
            swap($default_state, $form_state, $form_wrapper, function(){
                $form_wrapper.height('');
            });
            e.preventDefault();
        })
        .delegate('.form-state .close a', 'click', function(e) {
            swap($form_state, $default_state, $form_wrapper);
            e.preventDefault();
        })
        .delegate('#edit-mobile input', 'keypress', function(e) {
            $.tpautoTab(e, this, {
                mask: /^[0-9]+$/
            })
        })
        ;

    $('#stay-connected').not('.interim')
        .hide()
        .append('<p class="close"><a href="#">Close</a></p>');

    // Show random fact
    var $facts = $('.facts-block .fact');
    var fact_length = $facts.length;
    var rfact = Math.floor(Math.random()*fact_length);
    $facts.hide();
    $($facts.get(rfact)).show();
}
// Contest
else if ( $body.is('.page-wordlet-intelchange-interim-contest') ) {
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

else if ( $body.is('.page-wordlet-intelchange-interim-contest-enter')) {
    Drupal.behaviors.contestEntryFormThankYou = {
        attach: function (context) {
            if (context.is('.thank-you-message')){

                // scroll to top of thank you after loaded
                $('html, body').animate({
                     scrollTop: context.offset().top
                });

                // thank you add this block
                var $thankyouMessage = $('.form-block').data('thankyouMessage');
                var $thankyouUrl = $('.form-block').data('thankyouUrl');
                addthis.toolbox('.addThis', {
                    ui_email_note: $thankyouMessage + '  ' + $thankyouUrl
                },
                {
                    url: $thankyouUrl,
                    title: $thankyouMessage
                });
            }
        }
    }
}


// About
else if ( $body.is('.page-wordlet-intelchange-interim-about') ) {
    var contentNav = $('.content-nav');
    var contentInfo = $('.content-info');
    var contentSections = contentInfo.children();
    var $content_navs = contentNav.find('li a');
    var $current_nav = $content_navs.first();
    if ( location.hash ) {
        var $target_nav = $('a[href="' + location.hash + '"]');
        if ( $target_nav.is('.content-nav a') ) {
            $current_nav = $target_nav;
        }
    }
    var $current_content = contentSections.filter('#' + $current_nav.attr('href'));

    $body
        // Nav click
        .delegate('.content-nav li a', 'click', function(e) {
            e.preventDefault();
            if ( this == $current_nav[0] ) return;
            $content_navs.removeClass('active');
            var $this = $(this).addClass('active');
            var $from = $current_content;
            var $to = contentSections.filter('#' + $this.attr('href'));
            swap($from, $to, contentInfo);
            $current_content = $to;
            $current_nav = $this;
        });

    $current_nav.addClass('active');
    contentSections.not('#' + $current_nav.attr('href')).hide();
}

});
})(window, jQuery);
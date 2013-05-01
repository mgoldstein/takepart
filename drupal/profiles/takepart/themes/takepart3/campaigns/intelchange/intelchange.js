// FB login redirect for voting page
function takepart_facebookapi_check_login_session0() {
    path = '/tpfboauth/connect?destination=' + encodeURI(window.location);
    window.location = path;
}

(function(window, $, undefined) {
// Setup ----------------

var speed = 'fast';

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
if ( $body.is('.page-wordlet-intelchange-home') ) {
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

    // Slider
    $('.finalists-menu').tpslide();
}
// Contest
else if ( $body.is('.page-wordlet-intelchange-contest') ) {
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

else if ( $body.is('.page-wordlet-intelchange-contest-enter')) {
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
else if ( $body.is('.page-wordlet-intelchange-about') ) {
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

// Vote
else if ( $body.is('.page-wordlet-intelchange-vote') ) {

    // variables
    var $voteWrap = $('.second-block .vote');
    var $contentNav = $('.finalists-menu');
    var $contentInfo = $('.finalist-content');
    var $contentNavs = $contentNav.find('.finalist a');
    var $contentSections = $contentInfo.find('.finalist');
    var $currentNav;
    var $currentContent;
    var modalHash = 'vote_';
    var justVoted = false;
    var $hashFinalist = $contentNavs.filter('[href="' + window.location.href.replace(modalHash, '') + '"]');
    var confirmFormOptInHandler = function(e){
        var $container = $(this).parents('.vote-confirm');
        if ($(this).find('input').is(':checked')){
            $container.find('.form-item-agree-to-rules').show();
            $container.find('.footnote').show();
        } else {
            $container.find('.form-item-agree-to-rules').hide();
            $container.find('.footnote').hide();
        }
        
    }
    var setCurFinalist = function(navItem){
        if ($currentNav === navItem) return;

        // Stop Current Video (Hide it)
        if ($currentContent){
            $loadedVidWrapper = $currentContent.find('.video');
            $loadedVid = $('.video-player', $loadedVidWrapper);
            $loadedVidWrapper.height($loadedVid.height());
            $loadedVid.animate({opacity: 0}, speed, function() {
                $(this).remove();
            });
        }

        $currentNav = navItem;
        $currentContent = $($currentNav[0].hash);
        $contentSections.removeClass('active');
        $currentContent.addClass('active');
        $contentNavs.removeClass('active');
        $currentNav.addClass('active');

        // Show Video
        var $videotpl = $currentContent.find('.video-template');
        if ( $videotpl.length ) {
            var $video = $($videotpl.html());
            $videotpl.parent().append($video);
            //$videotpl.remove();
        }
    };
    var scrollTopFinalists = function(){
        $('body').scrollTo('.second-block', 0);
    };
    var finalistMenuClickHandler = function(e) {
        e.preventDefault();
        if ( this === $currentNav[0] ) return;
        var $from = $currentContent;
        setCurFinalist($(this));
        swap($from, $currentContent, $contentInfo);
        window.location.hash = $currentContent.data('finalisttoken');
        scrollTopFinalists();
    };
    var showVoteModal = function(contentToShow){
        var $voteModalWrapper = $currentContent.find('.modal-wrapper');
        $.tpmodal.show({id: 'intelforchange_',node: contentToShow, afterClose: function(){
            $voteModalWrapper.append(contentToShow);
            if (justVoted){
                location.reload();
            }
        }});
    };
    var voteBtnHandler = function(e){
        var $voteModalWrapper = $currentContent.find('.modal-wrapper');
        var $fbModalContent = $('.vote-register', $voteModalWrapper);
        var $confirmModalContent = $('.vote-confirm', $voteModalWrapper);
        var notLoggedIn = $fbModalContent.length > 0;
        var $contentToShow = notLoggedIn ? $fbModalContent : $confirmModalContent;
        if (!notLoggedIn){
            e.preventDefault();
        }
        showVoteModal($contentToShow);
    };
    var modalCancelHandler = function(e){
        e.preventDefault();
        var $parent = $(this).parents('.tpmodal_modal');
        var $modalClose = $parent.find('.tpmodal_close');
        $modalClose.trigger('click');
    };
    var voteConfirmSubmit = function(context, settings){
        if (settings && settings.contest_intel && settings.contest_intel.vote_result){
            var $voteModalWrapper = $currentContent.find('.modal-wrapper');
            var vote_result = settings.contest_intel.vote_result;
            var $contentToShow = $('.vote-error', $voteModalWrapper);
            if (vote_result === 'accepted'){
                // show thank you modal
                $contentToShow = $('.vote-thanks', $voteModalWrapper);
                justVoted = true;
                window.location.hash = "";
            } else if(vote_result === 'rejected'){
                // show rejected modal
                $contentToShow = $('.vote-rejected', $voteModalWrapper);
            }
            showVoteModal($contentToShow);
        }
    };

    // body delegates
    $body
        // Nav click
        .delegate('.finalists-menu .finalist a', 'click', finalistMenuClickHandler)
        // Vote Button click
        .delegate('.finalist .vote-btn a', 'click', voteBtnHandler)
        // Modal Cancel click
        .delegate('.modal .cancel', 'click', modalCancelHandler)
        // Confirm vote form opt in handler
        .delegate('.vote-confirm .form-item-entry-opt-in', 'click', confirmFormOptInHandler);

    /* drupal behavior binding for vote confirm */
    Drupal.behaviors.confirmFormSubmit = {
        attach: voteConfirmSubmit
    }

    // hide finalist modals
    $('.finalist .modal-wrapper').hide();

    // adjust finalist wrapper height based on menu size
    $voteWrap.css({
        'min-height': $contentNav.children().outerHeight(),
        '_height': $contentNav.children().outerHeight()
    });

    // initialize finalist on load
    if ($hashFinalist.length > 0){
        // if #finalistToken or #modalToken_finalistToken
        setCurFinalist($hashFinalist);
        if (window.location.href.indexOf(modalHash) !== -1){
            // if #modalToken_finalistToken (exapmle: #vote_one)
            $currentContent.find('.vote-btn a').trigger('click');
        } else {
            scrollTopFinalists();
        }
    } else {
        // else use first finalist in menu
        setCurFinalist($contentNavs.first());
    }

    // fix for swap function jumpiness
    $contentSections.not('.active').hide();

}

});
})(window, jQuery);
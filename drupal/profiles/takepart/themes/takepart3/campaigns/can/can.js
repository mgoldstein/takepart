(function(window, $, undefined) {

// Document Ready ----------------
$(function() {
    var $body = $('body');
    var animationSpeed = 'fast';

    // Page Specific -----------------

    // Home
    if ( $body.is('.page-wordlet-can-home') ) {

        /* variables */
        var $chapterNav = $('.chapter-menu');
        var $chaptersWrapper = $('.chapters').hide();
        var $chapters = $chaptersWrapper.children().hide();
        var $sectionNavs = $('.chapter .section-menu');
        var currentChapter;
        var voteComplete = false;
        var $currentModals = [];
        var modalHash = 'vote_';
        var $hashChapter = $chapterNav.find('.chapter').filter('[href="' + window.location.href.replace(modalHash, '') + '"]');
        var loadVideo = function($vidWrapper){
			var $videotpl = $vidWrapper.find('.video-template');
        	if ( $videotpl.length ) {
	            var $video = $($videotpl.html());
	            $videotpl.parent().append($video);
	        }
        }
        var chapterMenuHandler = function(e){
            if ($(this).is('.active')){
                return;
            }
            currentChapter = $(this).attr('data-chapter');
            $chapterNav.find('a').removeClass('active');
            $(this).addClass('active');
            var $chapterToShow = $chapters.filter('#' + this.hash.substr(1));
            var $curSectionMenu = $chapterToShow.find('.section-menu');
            var $curSections = $chapterToShow.find('.sections');
            var $curSectionMenuItem = $('.section.active', $curSectionMenu);
            var $curSection = $curSections.find('#' + $curSectionMenuItem[0].hash.substr(1))

            // show video if need to
            if ($curSection.find('.video-wrapper').length > 0 && $chapterToShow.find('.video-player').length < 1) {
            	loadVideo($curSection.find('.video-wrapper'));
            }

            swap($chapters.filter(':visible'), $chapterToShow, $chaptersWrapper, function(){
            	// hide video in prev section if need to
            	$('.sections .section', $chapters).filter(':not(:visible)').find('.video-player').remove();
            });
            $('html, body').animate({
                 scrollTop: $chaptersWrapper.offset().top
            });
        }

        var chapterSectionMenuHandler = function(e){
            var $thisSectionsWrapper = $(this).parents('.chapter').find('.sections');
            var $thisSections = $thisSectionsWrapper.children();
            e.preventDefault();
            if ($(this).is('.active')){
                return;
            }
            var $section = $thisSections.filter('#' + this.hash.substr(1));
            var $prevSection = $thisSections.filter(':visible');

            // update menu styling
            $(this).siblings().removeClass('active');
            $(this).addClass('active');

            // show video in new section if there
            loadVideo($section.find('.video-wrapper'));

            // animate hide/show sections
            swap($thisSections.filter(':visible'), $section, $thisSectionsWrapper, function(){
            	// hide video in prev section if need to
            	$('.sections .section', $chapters).filter(':not(:visible)').find('.video-player').remove();
            });
        }

        var voteBtnHandler = function(e){
            e.preventDefault();
            var $voteModalWrapper = $(' .modal-wrapper', '.chapter.' + currentChapter);
            var $fbModalContent = $('.facebook-signup', $voteModalWrapper);
            var $confirmModalContent = $('.vote-form', $voteModalWrapper);
            var $contentToShow = $fbModalContent.length > 0 ? $fbModalContent : $confirmModalContent;
            if (voteComplete) {
            	$contentToShow = $('.voting-rejected', $voteModalWrapper);
            }
            showVoteModal($contentToShow);
        }

        var modalCancelHandler = function(e){
            e.preventDefault();
            var $parent = $(this).parents('.tpmodal_modal');
            var $modalClose = $parent.find('.tpmodal_close');
            $modalClose.trigger('click');
        }

        var voteConfirmSubmit = function(context, settings){
            if (settings && settings.can_campaign && settings.can_campaign.vote_result){
                var $voteModalWrapper = $(' .modal-wrapper', '.chapter.' + currentChapter);
                var vote_result = settings.can_campaign.vote_result;
                var $contentToShow = $('.voting-error', $voteModalWrapper);
                if (vote_result === 'accepted'){
                    // show thank you modal
                    $contentToShow = $('.thank-you', $voteModalWrapper);
                    voteComplete = true;
                } else if(vote_result === 'rejected'){
                    // show rejected modal
                    $contentToShow = $('.voting-rejected', $voteModalWrapper);
                    voteComplete = true;
                }
                showVoteModal($contentToShow);
            }
        }

        var showVoteModal = function(contentToShow){
            var $voteModalWrapper = $(' .modal-wrapper', '.chapter.' + currentChapter);

            $.tpmodal.show({node: contentToShow, afterClose: function() {
                $.each($currentModals, function(i, e){
					$voteModalWrapper.append($(e));
	        	});
	        	$currentModals = [];
            }});
            $currentModals.push(contentToShow);
        }

        /* hide modal containers */
        $('.modal-wrapper').hide();

        /* show first section in each chapter */
        $.each($sectionNavs, function(i, e){
            var $firstSectionMenuItem = $(e).find('a').first().addClass('active');
            var $firstSection = $('.chapter .sections').children().hide().filter('#' + $firstSectionMenuItem[0].hash.substr(1)).show();
        });
        $chaptersWrapper.show();

        /* set thank you add_this block messages/urls */
        $.each($chapterNav.find('.chapter'), function(i,e){
            var chapter = $(e).data('chapter');
            var addThisBlockSelector = '.' + chapter + ' .thank-you .addThis';
            var $thankyouMessage = $(addThisBlockSelector).data('thankyouMessage');
            var $thankyouUrl = $(addThisBlockSelector).data('thankyouUrl');
            addthis.toolbox(addThisBlockSelector, {
                ui_email_note: $thankyouMessage + '  ' + $thankyouUrl
            },
            {
                url: $thankyouUrl,
                title: $thankyouMessage
            });
        });

        /* event binds */
        $body
            // Chapter Menu click
            .delegate('.chapter-menu .chapter', 'click', chapterMenuHandler)
            // Section Menu click
            .delegate('.chapter .section-menu .section', 'click', chapterSectionMenuHandler)
            // Vote Button click
            .delegate('.chapter .vote', 'click', voteBtnHandler)
            // Modal Cancel click
            .delegate('.modal .cancel', 'click', modalCancelHandler);

        /* show chapter and modal if hashed */
        if ($hashChapter.length > 0){
            $hashChapter.trigger('click');
            if (window.location.href.indexOf(modalHash) !== -1){
                $('.vote-wrapper .vote', '#' + currentChapter).trigger('click');
            }
        }

        /* drupal behavior binding for vote confirm */
        Drupal.behaviors.confirmFormSubmit = {
            attach: voteConfirmSubmit
        }

    }
    // About
    else if ( $body.is('.page-wordlet-can-about') ) {

    }

    // Global Page Functions -----------------

    function swapIn(toShow, parent, callback){
    	toShow.css({opacity: 0, display: 'block'});
        parent.animate({height: toShow.outerHeight(true)}, animationSpeed, function() {
            toShow.animate({opacity: 1}, animationSpeed, function() {
                parent.css({height: ''});
                if ( callback ) callback();
            });
        });
    }

    function swap(toHide, toShow, parent, callback) {
        if (toHide.length > 0){
            toHide.animate({opacity: 0}, animationSpeed, function() {
                parent.css({height: toHide.outerHeight(true)});
                toHide.css({display: 'none'});
                swapIn(toShow, parent, callback);
            });
        }else{
            swapIn(toShow, parent, callback);
        }
    }
});

})(window, jQuery);
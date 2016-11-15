/**
 * @file
 * A JavaScript file for autoscroll.
 *
 */

(function ($, Drupal, window, document, undefined) {

  $(document).ready(function () {
    window.newTapWidgets = true;
    /* Settings need to be set */
    if (Drupal.settings.tpAutoScroll.length == 1) {
	 var settings = Drupal.settings.tpAutoScroll[0];
	 var alreadyloading = false;
	 var page = -1;
	 var page_limit = settings.limit - 1;
   window.forceAutoload = false;
   window.reached_second_article = false;

   //Set the first loaded article percentage complete
   digitalData.page.pageInfo['percentageMarks'] = window.setContentPercentageMarks(digitalData.page.pageInfo.pageId);

	 /* Make a copy of the page data in the DDL for use when the user scrolls to the top */
	 digitalData.pageInititial = digitalData.page;

	 $(window).scroll(function () {
	   var $window = $(window),
		elTop = $('#next-article').offset().top;
	   var window_bottom = $window.scrollTop() + $window.height();
	   var last_article = $('article').last().parent().height() / 2;

    //Promote the next article after 1 minute unless the user scrolls to the next article faster
    //Adding this snippet inside the scroll to prevent race condition with Optimizely
    //recirculation-test class is set via Optimizely
    if ($('body').hasClass('recirculation-test')) {
      //Run the timer only once
      if (!$('body').hasClass('recirculation-timer')) {
        setTimeout(function() {
          if (!$('body').hasClass('next-node-promoted')) {
            window.forceAutoload = true;
          }
        },60000);
      }
      $('body').addClass('recirculation-timer');
    }

	   /* when the page scrolls to within 480px of #next-article */
	   if ((window_bottom + last_article + $('#footer').height() > elTop && page < page_limit) || window.forceAutoload) {

		if (alreadyloading == false) {
		  alreadyloading = true;
		  /* Set the URL */
		  var url = settings.articles[page + 1];
		  $.get(url, function (data) {

		    /* Not returning a json object (Drupal is slow at that) so let's convert it here */
		    data = jQuery.parseJSON(data);

        /* Return Article */
		    $('#next-article').before(data.output);

        //Set the article autoload page number
		    var pageNumber = page + 3;
		    data.ddl.eventInfo['autoloadCount'] = 'page ' + pageNumber;

        //Set the % pixel placements
        data.ddl.eventInfo.page.pageInfo['percentageMarks'] = window.setContentPercentageMarks(data.ddl.eventInfo.page.pageInfo.pageId);

		    /* Append ajax settings */
		    jQuery.extend(Drupal.settings, data.settings);

		    /* Create a new event in the DDL to be used when the user scolls to the article */
		    digitalData.event.push(data.ddl);

		    /* Append Ajax behaviors */
		    if ('function' === typeof Drupal.behaviors.AJAX.attach) {
			 Drupal.behaviors.AJAX.attach(document, Drupal.settings);
		    }

		    // init video players for auto-loaded content
		    if ('function' === typeof Drupal.behaviors.tp_video_player.attach) {
			 Drupal.behaviors.tp_video_player.attach();
		    }

        //process inline social share
        if ('function' === typeof Drupal.behaviors.InlineSocialShare.attach) {
          Drupal.behaviors.InlineSocialShare.attach();
        }

        if(typeof Drupal.behaviors.lazyloader !== 'undefined' && typeof Drupal.behaviors.lazyloader.attach !== 'undefined') {
          Drupal.behaviors.lazyloader.attach(document, Drupal.settings);
        }

        if(typeof Drupal.behaviors.extlink !== 'undefined' && typeof Drupal.behaviors.extlink.attach !== 'undefined') {
          Drupal.behaviors.extlink.attach(document, Drupal.settings);
        }

              // Load comments box on button click for mobile display
		    $('a.comments-count').once('FBComments', function () {
			 $('a.comments-count').on('click', function (e) {
			   $(this).siblings('.fb-comments').attr('href', window.location.href).show();
			   $(this).hide();
			   e.preventDefault();
			   return false;
			 });
		    });

		    /* There are new Tap Widgets available on the page.  Delay these calls until page is active */
		    window.newTapWidgets = true;

		    alreadyloading = false;
		    page++;

        //Promote next article
        //recirculation-test set via optimizely
        if ($('body').hasClass('recirculation-test') && !$('body').hasClass('next-node-promoted')) {
          promptNextNode();
        }
		  });
		}
	   }
	 });
    }
  });


  /**
   *
   *  @function:
   *    This drupal behavior is used to change the URL and Title on the page.
   *    Note that some specific browser does not respect title changes
   *
   *  @example:
   *    This can be implemented via adding the following to any html tag
   *      data-tp-url="/example"
   *      data-tp-url-title="Test" *Note that some browsers does not respect this
   *
   */
  Drupal.behaviors.tp_auto_changer = {
    attach: function (context, settings) {
	 //variables
	 window.lastScrollTop = 0;
	 window.tp_url_orig = window.location.href;
	 window.tp_url_title_orig = document.title;

	 //binds to the scroll
	 var timer;
	 $(window).bind('scroll', function () {

	   /* Only process the code below every 100ms on scroll */
	   if (timer) {
		window.clearTimeout(timer);
	   }
	   timer = window.setTimeout(function () {
		//default variables for this scope
		var url = window.location.href;
		var title = document.title;
		var win = $(window);
		var viewport = {
		  top: win.scrollTop(),
		  left: win.scrollLeft(),
		  bottom: win.scrollTop() + win.height()
		};

		//For each article
		$('article').each(function (index, value) {
      //Fresh gallery autoloaded
      if($(this).hasClass('node-fresh-gallery') && !$(this).hasClass("gallery-processed")) {
        var page_url = $(this).data('tpOgUrl');
        if (typeof Drupal.settings.tpAutoScroll[0]['auto_updates'][page_url] == 'undefined') {
          var adMeta = null;
        }
        else {
          var adMeta = Drupal.settings.tpAutoScroll[0]['auto_updates'][page_url]['targets'];
          //Don't pass an array if there is only one element in the ad targeting
          if (Array.isArray(adMeta.FreeTag)) {
            adMeta.FreeTag = adMeta.FreeTag[0];
          }
          else {
            adMeta.FreeTag = JSON.parse(adMeta.FreeTag);
          }
          if (Array.isArray(adMeta.Topic)) {
            adMeta.Topic = adMeta.Topic[0];
          }
          else {
            adMeta.Topic = JSON.parse(adMeta.Topic);
          }
          if (Array.isArray(adMeta.Series)) {
            adMeta.Series = adMeta.Series[0];
          }
          else {
            adMeta.Series = JSON.parse(adMeta.Series);
          }
          if (Array.isArray(adMeta.Sponsor)) {
            adMeta.Sponsor = adMeta.Sponsor[0];
          }
          else {
            adMeta.Sponsor = JSON.parse(adMeta.Sponsor);
          }
        }

        // Build the object we need.
        var galleryData = {
          "title": $(this).attr('data-tp-og-title'),
          "subhead": $(this).attr('data-tp-og-description'),
          "adTag": Drupal.settings.tp_ads_fresh_gallery.tp_ad_single_tag,
          "adFrequency": Drupal.settings.tp_ads_fresh_gallery.tp_ad_single_freq,
          "adMeta": adMeta
        };

        var jsonId = $(this).attr('data-ddl-page-id');
        galleryData.images = eval('gallery_' + jsonId + '_json.images');
        var galleryElement = $(this).find('.gallery-wrapper')[0];
        var current_gallery = $(this);
        //First Fresh gallery on the page - ajax load all the required js
        if (typeof showImageGallery === 'undefined') {
          $.getScript( "/sites/all/libraries/fresh-gallery/gallery.js" )
          .done(function( script, textStatus ) {
            current_gallery.addClass("gallery-processed");
            showImageGallery(galleryData, galleryElement);
          })
          .fail(function( jqxhr, settings, exception ) {
            console.error('failed to grab the gallery script');
          });

          //Load photoswipe css
          $('<link/>', {
            rel: 'stylesheet',
            type: 'text/css',
            href: '/sites/all/libraries/photoswipe/photoswipe.css'
          }).appendTo('head');
        }
        else {
          //Node 1 is a fresh gallery
          showImageGallery(galleryData, galleryElement);
          current_gallery.addClass("gallery-processed");
        }
      }

		  /** Update active Article **/
		  var articleTop = $(this).offset().top;
		  var articleBottom = articleTop + $(this).height();
		  var offset = (viewport.bottom - viewport.top) / 2;

		  if ((viewport.top <= articleBottom - offset) && (viewport.top >= articleTop - offset)) {
		    $(this).addClass('active');

		    //Remove page-wrapper constraints if a feature article is close by
		    var f_article = $('.tp_ad_takeover article.node-feature-article');
		    if (f_article.length != 0) {
			 var f_article_diff = $('article.node-feature-article').offset().top - $(window).scrollTop();
			 if ((f_article_diff - $(window).innerHeight()) <= 450) {
			   $('body').addClass('feature-active');
			 }
			 else if ($('article.node-feature-article.active').length == 0 && $('body').hasClass('feature-active')) {
			   $('body').removeClass('feature-active');
			 }
		    }

		    //Create ambient video on feature articles
		    if (!window.isMobile && $('.feature-image.has-videoBG').length != 0) {
			 $('.feature-image.has-videoBG').each(function () {
			   if (!$(this).hasClass('video-created')) {
				createVideoBG($(this));
			   }
			 });
		    }

		    //Pause & play the ambient video if its in viewport
		    if ($('.feature-image.has-videoBG.video-created').length != 0) {
			 pauseAmbientVid();
		    }

        //Reached Article 2
        if (index == 1) {
          //Optimizley tracking - if reached article 2 - can be removed once A/B test is stopped.
          if (!window.reached_second_article) {
            window['optimizely'] = window['optimizely'] || [];
            window.optimizely.push(["trackEvent", "reached_second_article"]);
            window.reached_second_article = true;
          }

          //Remove next node promo if still visible when we get to second node.
          if ($('#prompt-next-article.show').length != 0) {
            if (window.isMobile) {
              jQuery('#prompt-next-article').removeClass('show').slideUp();
            }
            else {
              jQuery('#prompt-next-article').removeClass('show').animate({
                'right' : '-320'
              });
            }
          }
        }

		    /** Update the URL **/
		    /* if article is active and data-tp-url != url, update it */
		    var tp_og_url = $(this).data('tp-og-url');
		    var tp_og_title = $(this).data('tp-og-title');
		    var tp_og_image = $(this).data('tp-og-image');
		    var tp_og_description = $(this).data('tp-og-description');
		    var current_path = location.protocol + '//' + location.host + location.pathname;
		    // Upate the URL, social links and DDL based on URL logic
		    if (typeof tp_og_url != 'undefined' && tp_og_url != current_path) {
			 /** Update the URL **/
			 tp_url_changer(tp_og_url, tp_og_title);

			 /**
			  *  check to ensure that the reach.js is fully ready
			  */
			 if (typeof Drupal.settings.tpAutoScroll[0].auto_updates[tp_og_url] !== 'undefined') {
			   var data = Drupal.settings.tpAutoScroll[0].auto_updates[tp_og_url].data;
			   tp_reach_call(data);
			 }

			 /** Update the sharing **/
			 update_tp_social_media(tp_og_title, tp_og_url, tp_og_image, tp_og_description);

			 /** Update the DDL **/
			 var page_id = $(this).data('ddl-page-id');
			 if (page_id) {
			   update_tp_ddl(page_id);
			 }

			 /** Check for additional TAP widgets */
			 // needs to happen after page info updates for DTM
			 if (window.newTapWidgets == true) {
			   TP.scope = $(value).data('ddlPageId');
			   if ($('.takepart-modal-container').length) {
				$('.takepart-modal-container').remove();
			   }
			   TP.Bootstrapper && new TP.Bootstrapper().start();
			   TAP.Widget && TAP.Widget.addWidgets();
			   window.newTapWidgets = false;
			 }

			 //Keywee pixel tracking
			 if (typeof fbq !== 'undefined') {
			   fbq("track", "PageView");
			 }
			 if (typeof window.snowplowKW !== 'undefined') {
			   window.snowplowKW("trackPageView", tp_og_title);
			 }
		    }

		  } else {
		    $(this).removeClass('active');
		  }
		});

    //Add check if past percentage complete mark
    window.trackContentPercentageComplete();

		//updates the last scroll var
		lastScrollTop = viewport.top;

	   }, 100);
	 });
    }
  };

  /**
   * @function:
   *  window function that is used to update the URL and is binded to the scroll.
   */
  window.tp_url_changer = function (url, title) {
    //change url with pushstate so that the page doesnt reload
    if (window.history.pushState)
	 window.history.pushState({}, url, url);
    document.title = title;
  };

  /**
   *  @function:
   *    window function that is used to update the social links
   */
  window.update_tp_social_media = function (title, url, image, description) {
    //changes to update the social links
    if (typeof title !== 'undefined') {
	 $("meta[property='og:title']").attr("content", title);
	 $("meta[name='twitter:title']").attr("content", title);
    }
    if (typeof url !== 'undefined') {
	 $("meta[property='og:url']").attr("content", url);
	 $("meta[name='twitter:url']").attr("content", url);
	 $("link[rel='canonical']").attr("href", url);
    }
    if (typeof image !== 'undefined') {
	 $("meta[property='og:image']").attr("content", image);
    }
    if (typeof description !== 'undefined') {
      $("meta[property='og:description']").attr("content", description);
      $("meta[name='description']").attr("content", description);
      $("meta[name='abstract']").attr("content", description);
      $("meta[name='twitter:description']").attr("content", description);
    } else {
      $("meta[property='og:description']").attr("content", title);
      $("meta[name='description']").attr("content", title);
      $("meta[name='abstract']").attr("content", title);
      $("meta[name='twitter:description']").attr("content", title);
    }

    //updates the social config
    tp_social_config.services.mailto.title = title;
    tp_social_config.services.twitter.text = document.title;
    tp_social_config.services.twitter.url = url;
    tp_social_config.services.facebook.title = title;
    tp_social_config.services.facebook.url = url;
    tp_social_config.services.googleplus.title = title;
    tp_social_config.services.googleplus.url = url;
    tp_social_config.services.tumblr.title = title;
    tp_social_config.services.tumblr.url = url;

    //only update the og metatag data if the url is set
    if (Drupal.settings.tpAutoScroll[0]['auto_updates'][url] != undefined) {
	 var width = Drupal.settings.tpAutoScroll[0]['auto_updates'][url]['width'];
	 var height = Drupal.settings.tpAutoScroll[0]['auto_updates'][url]['height'];
	 var sttags = Drupal.settings.tpAutoScroll[0]['auto_updates'][url]['sailthru_tags'];
	 var stauthors = Drupal.settings.tpAutoScroll[0]['auto_updates'][url]['sailthru_authors'];
	 var stdate = Drupal.settings.tpAutoScroll[0]['auto_updates'][url]['sailthru_date'];

	 //ensures we only update if if the metatag exists before
	 if ($("meta[property='og:image:width']").length == 1) {
	   $("meta[property='og:image:width']").attr("content", width);
	 }

	 //ensures we only update if if the metatag exists before
	 if ($("meta[property='og:image:height']").length == 1) {
	   $("meta[property='og:image:height']").attr("content", height);
	 }

	 if ($("meta[name='sailthru.tags']").length == 1) {
	   $("meta[name='sailthru.tags']").attr("content", sttags);
	 }
	 if ($("meta[name='sailthru.author']").length == 1) {
	   $("meta[name='sailthru.author']").attr("content", stauthors);
	 }
	 if ($("meta[name='sailthru.date']").length == 1) {
	   $("meta[name='sailthru.date']").attr("content", stdate);
	 }
    }

    //refires to update
    $('body').find('.tp-social:not(.tp-social-skip)').tpsocial(tp_social_config);
  };

  /**
   *  @function:
   *  Update PageInfo in DDL with the correct Page Load event data
   */
  window.update_tp_ddl = function (id) {

    /* get the event with the page id */
    for (var i = 0; i < digitalData.event.length; i++) {
	 if (typeof (digitalData.event[i].eventInstanceID) != 'undefined' && digitalData.event[i].eventInstanceID == id) {
	   digitalData.page.pageInfo = digitalData.event[i].eventInfo.page.pageInfo;
	   digitalData.page.pageNumber = digitalData.event[i].eventInfo.autoloadCount;
	   digitalData.category = digitalData.event[i].eventInfo.category;
	   _satellite.track('clear_vars');
	   setTimeout(function () {
		_satellite.track('autoload');
	   }, 1000);
	   return;
	 }
    }

    /* If no event exists then it is the initial page load */
    if (digitalData.pageInitial)
	 digitalData.page.pageInfo = digitalData.pageInitial.pageInfo;
    digitalData.page.pageNumber = 'page 1';
    _satellite.track('clear_vars');
    setTimeout(function () {
	 _satellite.track('autoload');
    }, 1000);

  };

  //For analytics to set the percentage that the user got down the content
  window.setContentPercentageMarks = function(pageId) {
    //adding the percentage down the page variable to the DDL should start at 0
    var percentageMarks = new Array();
    if($('article[data-ddl-page-id="'+pageId+'"]').length) {
      var hght = $('article[data-ddl-page-id="'+pageId+'"]').height();
      var disttop = $('article[data-ddl-page-id="'+pageId+'"]').offset().top;
      var div = (hght/4).toFixed(0);
      percentageMarks[0] = [(disttop+(div*0)).toFixed(0),0];
      percentageMarks[1] = [(disttop+(div*1)).toFixed(0),25];
      percentageMarks[2] = [(disttop+(div*2)).toFixed(0),50];
      percentageMarks[3] = [(disttop+(div*3)).toFixed(0),75];
      percentageMarks[4] = [(disttop+(div*4)).toFixed(0),100];
    }
    return percentageMarks;
  };

  window.trackContentPercentageComplete = function() {
    var win = $(window);
    var bottom = win.scrollTop() + win.height();
    var marks = window.digitalData.page.pageInfo['percentageMarks'];
    var delMarks = new Array();
    //new custom event for percentageComplete tracking
    $.each(marks, function(i,v){
      if(typeof v !== 'undefined') {
        if(v[0] <= bottom) {
          window.percentageCompleteEvent = new CustomEvent('percentageComplete', { detail: '' });
          //track the percentage complete if it is not 0 just make it 25
          window.digitalData.page.pageInfo['percentageComplete'] = (v[1] == 0?0:25);
          document.body.dispatchEvent( percentageCompleteEvent );
          //delete the mark from the event info and page
          delMarks.push(i);
        }
      }
      //Remove the marks that got tracked
      if(i == (marks.length - 1) && delMarks.length > 0) {
        //I reverse so the that it deletes from top to bottom if you start with 0
        //They the array will reset and you will delete the wrong one
        $.each(delMarks.reverse(), function(ind, val){
          //This should propagate to the event info and pageInitial
          window.digitalData.page.pageInfo['percentageMarks'].splice(val, 1);
        });
      }
    });
  };


})(jQuery, Drupal, this, this.document);

/*
 * Pause the ambient video if less than 70% of it is in viewport.
 */
function pauseAmbientVid() {
  jQuery('.has-videoBG.video-created video').each(function (index) {
    var vid = jQuery('.has-videoBG.video-created video').get(index);
    if (typeof vid !== 'undefined') {
	 var vid_parent = jQuery(this).parent().parent();
	 var is_paused = vid.paused;
	 if (vid_parent.isInViewport(null, 0.7)) {
	   if (is_paused || jQuery(this).hasClass('paused')) {
		vid.play();
		jQuery(this).removeClass('paused');
	   }
	 }
	 else {
	   if (!is_paused && !jQuery(this).hasClass('paused')) {
		vid.pause();
		jQuery(this).addClass('paused');
	   }
	 }
    }
  });
}

/**
 * Checks to see whether a certain portion of the element is in viewport
 * x-> width, y-> height, 0.5 -> 50% of the height or width is visible
 */

jQuery.fn.isInViewport = function(x, y) {
  if(x == null || typeof x == 'undefined') x = 1;
    if(y == null || typeof y == 'undefined') y = 1;
    var win = jQuery(window);
    var viewport = {
        top : win.scrollTop(),
        left : win.scrollLeft()
    };
    viewport.right = viewport.left + win.width();
    viewport.bottom = viewport.top + win.height();

    //Need to pass true/false(if you want margin) for outerHeight/outerWidth to get a value back
    //This is due to the current version of jquery on fresh and jquery UI when logged in
    var height = this.outerHeight(false);
    var width = this.outerWidth(false);
    window.height = height;
    window.width = width;
    if(!width || !height){
        return false;
    }
    var bounds = this.offset();
    bounds.right = bounds.left + width;
    bounds.bottom = bounds.top + height;
    window.bounds = bounds;
    var visible = (!(viewport.right < bounds.left || viewport.left > bounds.right || viewport.bottom < bounds.top || viewport.top > bounds.bottom));
    if(!visible){
        return false;
    }
    var deltas = {
        top : Math.min( 1, ( bounds.bottom - viewport.top ) / height),
        bottom : Math.min(1, ( viewport.bottom - bounds.top ) / height),
        left : Math.min(1, ( bounds.right - viewport.left ) / width),
        right : Math.min(1, ( viewport.right - bounds.left ) / width)
    };

    return (deltas.left * deltas.right) >= x && (deltas.top * deltas.bottom) >= y;
}

/*
 * Displays a prompt that link to the next autoloaded node for an A/B test
 */
function promptNextNode() {
  jQuery('article').each(function (index) {
    if (index == 1) {
      $this = jQuery(this);
      //Next node's info
      var promo_title = $this.data('tp-og-title');
      var promo_img = $this.data('tp-og-image');
      var promo_nid = $this.data('ddl-page-id');

      //Create markup
      //TODO: if this A/B test is succuessful, we should move this to a template
      var markup = '';
      markup += '<div id= "prompt-next-article">';
      markup +=   '<div class = "prompt-next-article-inner">';
      markup +=     '<div class="i-close-x"></div>';
      markup +=     '<img src="' + promo_img + '">';
      markup +=     '<div class="prompt-content">';
      markup +=       '<p>Next story</p>';
      markup +=       '<h1 class= "title">' + promo_title + '</h1>';
      markup +=       '<a href="javascript:gotoNextdNode(' + promo_nid + ')" class="jump desktop">Jump to next story</a>';
      markup +=       '<a href="javascript:gotoNextdNode(' + promo_nid + ')" class="jump mobile">JUMP</a>';

      markup +=     '</div>'
      markup +=    '</div>';
      markup += '</div>';

      //Add the markup to the page
      jQuery('.main-content .container').before(markup);
      jQuery('#prompt-next-article').addClass('show').animate({
        'right' : '0'
      }, 400);
      jQuery('body').addClass('next-node-promoted');
      return;
    }
  });

  //close next article promo
  jQuery('#prompt-next-article .i-close-x').click(function() {
    if (window.isMobile) {
      jQuery('#prompt-next-article').removeClass('show').slideUp();
    }
    else {
      jQuery('#prompt-next-article').removeClass('show').animate({
        'right' : '-320'
      });
    }
  });
  //Optimizley tracking - next article promo is displayed
  window['optimizely'] = window['optimizely'] || [];
  window.optimizely.push(["trackEvent", "next_article_promo"]);

  window.forceAutoload = false;
}

/*
 * Slide to the next node in autoload. Remove the promo banner
 */
function gotoNextdNode(nid) {
  if (window.isMobile) {
    jQuery('#prompt-next-article').removeClass('show').slideUp();
  }
  else {
    jQuery('#prompt-next-article').removeClass('show').animate({
      'right' : '-320'
    });
  }

  jQuery('html, body').animate({
    scrollTop: jQuery('article[data-ddl-page-id="' + nid + '"]').offset().top
  }, 1000);
}

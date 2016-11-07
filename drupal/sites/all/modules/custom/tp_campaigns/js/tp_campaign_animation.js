/**
 * @file
 * A JavaScript file for TakePart Campaign Page Animation.
 *
 */

(function ($, Drupal, window, document, undefined) {

  //Disable the browser scroll
  if ($('.campaign-page-animation').length != 0) {
    $('body').addClass('campaign-full-page-scrollng');

  }
  Drupal.behaviors.campaignTrayAnimation = {
    attach: function () {
      var $anim_tray = $('.tray.animate');
      //Quit if no tray qualifies for animation
      if ($anim_tray.length == 0) return false;

      var tray_length =  $anim_tray.length;
      var tray_id_arr = [];
      $anim_tray.each(function(index){
        //Add active class to the first tray
        if (index ==0) $(this).addClass('active first');
        //Add last class
        if (index == (tray_length -1)) $(this).addClass('last');

        $(this).attr('data-anim-slide' , index);
        //Array of the tray IDs
        tray_id_arr.push('#' + $(this).attr('id'));
      });

      //Create a Pager
      tpc_create_pager(tray_id_arr);

      var body = document.body;
      //Determines the scroll direction on desktop
      var MouseWheelHandler = function(e) {
        //Quit if animating/Scrolling to another tray is in progress
        if ($('body').hasClass('animating')) return false;
        //delta return 1 for up and -1 for down.
        var e = window.event || e;
        var delta = Math.max(-1, Math.min(1, (e.wheelDelta || -e.detail)));

        //e.preventDefault();
        $slide = $('.tray.animate.active');
        if(delta === -1) {
         tpc_next_tray($slide , false);
        }
        if(delta === 1) {
          tpc_prev_tray($slide);
        }
      }

      if (body.addEventListener) {
        // IE9, Chrome, Safari, Opera
        body.addEventListener("mousewheel", MouseWheelHandler, false);
        // Firefox
        body.addEventListener("DOMMouseScroll", MouseWheelHandler, false);
      }

      $(document).bind('touchstart', function(e) {
        ts = e.originalEvent.touches[0].clientY;
      });

      //Determine the touch direction on touch devices.
      $(document).bind('touchmove', function(e) {
        if ($('body').hasClass('animating')) return false;
        var te = e.originalEvent.changedTouches[0].clientY;
        $slide = $('.tray.animate.active');
        if (ts > te) {
          e.preventDefault();
          tpc_next_tray($slide , false);
        } else {
          e.preventDefault();
          tpc_prev_tray($slide);
        }
      });

      //Capture up/down keys
      $(document).keydown(function(e) {
        switch(e.which) {
          case 38: // up
            if ($('body').hasClass('animating')) return false;
            $slide = $('.tray.animate.active');
            tpc_prev_tray($slide);
          break;

          case 40: // down
            if ($('body').hasClass('animating')) return false;
            $slide = $('.tray.animate.active');
            tpc_next_tray($slide, false);
          break;

          default: return;
        }
        e.preventDefault(); // prevent the default action
      });

      $('.campaign-animation-pager ul li a').click(function(e) {
        //Quit if clicking the active class
        if ($(this).hasClass('active-tray')) return false;
        $slide = $('.tray.animate.active');
        e.preventDefault();
        var dest = $(this).attr('href');
        tpc_next_tray($slide,$(dest));

      });

    }
  };

  /*
   * Next Tray function
   * @param {selector} $current_slide - the selector for the active tray
   * @param {selector} $next_tray_id - the selector for the next tray
   */

  tpc_next_tray = function($current_slide, $next_tray_id) {
    //Quit if we've reached the last slide
    if (!$next_tray_id && $current_slide.hasClass('last')) return false;

    //Determine the next tray if not set
    if (!$next_tray_id) {
      next_index = parseInt($current_slide.attr('data-anim-slide')) + 1;
      next_tray_id = $('.animate[data-anim-slide="' + next_index + '"]').attr('id');
      $next_tray = $('#' + next_tray_id);
    }
    else {
      $next_tray = $next_tray_id;
    }

    //Remove active class from current_slide & pager
    $current_slide.removeClass('active');
    $('.campaign-animation-pager a.active-tray').removeClass('active-tray');

    //Scroll to the appropriate item
    tpc_scroll_to($next_tray);
   }

 /*
  * Prev Tray function
  * @param {selector} $current_slide - the current active tray
  */

   tpc_prev_tray = function($current_slide) {
      //Quit if its the first slide
      if ($current_slide.hasClass('first')) return false;

      next_index = parseInt($current_slide.attr('data-anim-slide')) - 1;
      next_tray_id = $('.animate[data-anim-slide="' + next_index + '"]').attr('id');
      $current_slide.removeClass('active');
      //Remove active class from current_slide & pager
      $('.campaign-animation-pager a.active-tray').removeClass('active-tray');
      $next_tray = $('#' + next_tray_id);
      //Scroll to the appropriate item
      tpc_scroll_to($next_tray);
   }

    /*
    * Scroll To fucntion
    * @param {selector} $current_slide - the current active tray
    */

    tpc_scroll_to = function($next_tray) {
      var target_top = $next_tray.offset().top;
      $body = $('body');
      var index = $next_tray.attr('data-anim-slide');
      //Animating class prevents scrolling to other trays while animating in process
      $body.addClass('animating');
      $('body,html').animate({
        scrollTop: target_top
      }, 800 , function(){
        $next_tray.addClass('active');
        //Add active class to the pager
        $('.campaign-animation-pager a').eq(index).addClass('active-tray');
        //This is a helper callback function that could be used inside each campaign's custom js
        if (typeof tpc_animation_callback !== 'undefined') tpc_animation_callback(index);

        //Adding this timeout to resolve scrolling on track pads.
        setTimeout(function(){
          $body.removeClass('animating')} , 500);
      });
    }

    /*
    * Create animation tray
    * Going to create this markup on the font-end till we fully productize this functionality
    * @param {array of strings} tray id - IDs of the trays that will be animated
    */

    tpc_create_pager = function(tray_ids) {
      var markup = '';
      markup += '<div class = "campaign-animation-pager">';
      markup +=   '<ul>';
      for (i in tray_ids) {
        active_link = (i == 0) ?  " class=active-tray" : "";
        markup += '<li><a href="' + tray_ids[i] + '"' + active_link + '></a></li>';
      }
      markup +=   '</ul>';
      markup += '</div>';
      $('article.campaign-page-animation').prepend(markup);
    }

})(jQuery, Drupal, this, this.document);

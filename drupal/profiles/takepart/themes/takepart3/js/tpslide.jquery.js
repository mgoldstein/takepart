(function ($, undefined) {
    var $body = $(document.body);
    var $window = $(window);
    var return_false = function () {
        return false;
    };
    $.fn.slide_set = function (key, val) {
        return this.each(function () {
            var accessor = $(this).data('accessor');
            accessor.set(key, val);
        });
    };
    $.fn.tpslide = function (options) {
        var settings = $.extend({
            prepend: 'tpslide_',
            slides: '> *',
            rewind: true,
            threshold: 50,
            autoslide: false,
            cycle: true,
            do_hash: false
        }, options || {});
        return this.each(function () {
            var $this = $(this);
            var $wrapper = $('<span/>').addClass(settings.prepend + 'wrapper');
            var $prev = $('<span/>').attr('title', 'Previous slide').addClass(settings.prepend + 'prev').html('&larr;');
            var $next = $('<span/>').attr('title', 'Next slide').addClass(settings.prepend + 'next').html('&rarr;');
            var $nav = $('<span/>').addClass(settings.prepend + 'nav');
            var $nav_slides = $('<span/>').addClass(settings.prepend + 'nav_slides');
            var $slides = $this.find(settings.slides).addClass(settings.prepend + 'slide');
            var current = 0;
            var $current = $slides.eq(0);
            var hash = location.hash;
            var links = '';
            var autoslide_timeout = null;
            var accessor = {};
            $this.data('accessor', accessor);
            accessor.set = function (key, val) {
                if (typeof (key) == 'object') {
                    settings = $.extend(settings, key);
                } else {
                    settings[key] = val;
                }
                if (settings.autoslide) {
                    clearTimeout(autoslide_timeout);
                    autoslide_timeout = setTimeout(auto_next, settings.autoslide);
                }
            };
            $slides.each(function (i) {
                var $slide = $(this).data(settings.prepend + 'index', i);
                links += '<a href="#' + $slide.attr('id') + '" class="' + settings.prepend + 'link"><span>' + (i + 1) + ' / ' + $slides.length + '</span></a>';
                if (hash && $slide.is(hash)) {
                    current = i;
                    $current = $slide
                }
            });
            $nav_slides.html(links);
            var $links = $nav_slides.find('a').each(function (i) {
                var $a = $(this).data('slide', i);
                if (i == current) $a.addClass(settings.prepend + 'active');
            });
            $nav.prepend($prev).append($nav_slides).append($next);
            $wrapper.insertAfter($this).append($this).prepend($nav);
            $slides.css({
                width: $wrapper.outerWidth()
            });
            $window.bind('resize', function () {
                $slides.css({
                    width: $wrapper.outerWidth()
                });
                slide(false);
            });
            var auto_next = function () {
                next(false);
            };
            var slide = function (do_hash) {
                if (settings.autoslide) {
                    clearTimeout(autoslide_timeout);
                    autoslide_timeout = setTimeout(auto_next, settings.autoslide);
                }
                do_hash = do_hash || settings.do_hash;
                $this.scrollTo($current, 'slow');
                $links.removeClass(settings.prepend + 'active');
                $links.eq(current).addClass(settings.prepend + 'active');
                var hash = $current.attr('id');
                $current.attr({
                    id: ''
                });
                if (do_hash) location.hash = hash;
                $current.attr({
                    id: hash
                });
                if (current == $slides.length - 1) {
                    $next.addClass(settings.prepend + 'disabled');
                } else {
                    $next.removeClass(settings.prepend + 'disabled');
                }
                if (current == 0) {
                    $prev.addClass(settings.prepend + 'disabled');
                } else {
                    $prev.removeClass(settings.prepend + 'disabled');
                }
            };
            var next = function (do_hash) {
                if (!settings.cycle && $next.is('.' + settings.prepend + 'disabled')) return;
                current++;
                if (current >= $slides.length) {
                    if (settings.rewind) {
                        current = 0;
                    } else {
                        current = $slides.length - 1;
                    }
                }
                $current = $slides.eq(current);
                slide(do_hash);
            };
            $next.bind('click', function () {
                next();
            });
            if (settings.autoslide) {
                clearTimeout(autoslide_timeout);
                autoslide_timeout = setTimeout(auto_next, settings.autoslide);
            }
            var prev = function (do_hash) {
                if (!settings.cycle && $prev.is('.' + settings.prepend + 'disabled')) return;
                current--;
                if (current < 0) {
                    if (settings.rewind) {
                        current = $slides.length - 1;
                    } else {
                        current = 0;
                    }
                }
                $current = $slides.eq(current);
                slide(do_hash);
            };
            $prev.bind('click', function () {
                prev();
            });
            $nav.delegate('a', 'click', function () {
                current = $.data(this, 'slide');
                $current = $slides.eq(current);
                slide();
                return false;
            });
            $wrapper.delegate('a', 'click', function () {
                var href = this.href;
                if (href.indexOf('#') !== -1) {
                    var hash = href.split('#')[1];
                    if (hash && $slides.is('#' + hash)) {
                        var $el = $wrapper.find('#' + hash);
                        $current = $el;
                        current = $current.data(settings.prepend + 'index');
                        slide();
                        return false;
                    } else {
                        return true;
                    }
                }
                return true;
            });
            var total_moved = 0;
            var mouse_start_x;
            var delta_x;
            var last_x;
            var old_moz_user_select;
            var moving = false;
            var drag = function (event) {
                if (event.originalEvent.touches) {
                    event.pageX = event.originalEvent.touches[0].clientX;
                    event.pageY = event.originalEvent.touches[0].clientY;
                }
                delta_x = event.pageX - last_x;
                total_moved = event.pageX - mouse_start_x;
                last_x = event.pageX;
            };
            var stop = function (event) {
                $body.unbind('touchmove', drag).unbind('touchend touchcancel touchup touchleave', stop);
                $wrapper.removeClass(settings.prepend + 'mousedown');
                $body.css({
                    MozUserSelect: old_moz_user_select
                });
                if ($.browser.msie) {
                    $body.unbind('dragstart', return_false).unbind('selectstart', return_false);
                }
                if (total_moved > settings.threshold) {
                    prev();
                } else if (total_moved < settings.threshold * -1) {
                    next();
                }
                moving = false;
                total_moved = 0;
            };
            if ((navigator.userAgent.indexOf('Android') == -1)) {
                $wrapper.bind('touchstart', function (event) {
                    if (moving) return true;
                    moving = true;
                    if (event.originalEvent.touches) {
                        event.pageX = event.originalEvent.touches[0].clientX;
                        event.pageY = event.originalEvent.touches[0].clientY;
                    }
                    last_x = event.pageX;
                    mouse_start_x = event.pageX;
                    old_moz_user_select = $body.css('MozUserSelect');
                    $body.css({
                        MozUserSelect: 'none'
                    });
                    $wrapper.addClass(settings.prepend + 'mousedown');
                    $body.bind('touchmove', drag).bind('touchend touchcancel touchup touchleave', stop);
                    if ($.browser.msie) {
                        $body.bind('dragstart', return_false).bind('selectstart', return_false);
                    }
                }).bind('click', function () {
                    if (total_moved > settings.threshold || total_moved < settings.threshold * -1) {
                        total_moved = 0;
                        return false;
                    }
                    total_moved = 0;
                });
            }
            slide(false);
        });
    };
})(jQuery);
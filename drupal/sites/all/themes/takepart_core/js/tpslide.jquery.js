(function ($, undefined) {
    var $body = $(document.body);
    var $window = $(window);
    var return_false = function () {
        return false;
    };
    $.fn.tpslide_set = function (key, val) {
        return this.each(function () {
            var accessor = $(this).data('accessor');
            accessor.set(key, val);
        });
    };
    $.fn.tpslide_to = function (val) {
        return this.each(function () {
            var accessor = $(this).data('accessor');
            accessor.slide_to(val);
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
            do_hash: false,
            onslide: null
        }, options || {});
        return this.each(function () {
            var $this = $(this);
            var $wrapper = $('<span/>').addClass(settings.prepend + 'wrapper');
            var $prev = $('<a href="#"/>').attr('title', 'Previous slide').addClass(settings.prepend + 'prev').html('&larr;');
            var $next = $('<a href="#"/>').attr('title', 'Next slide').addClass(settings.prepend + 'next').html('&rarr;');
            var $nav = $('<span/>').addClass(settings.prepend + 'nav');
            var $nav_slides = $('<span/>').addClass(settings.prepend + 'nav_slides');
            var $slides = $this.find(settings.slides).addClass(settings.prepend + 'slide');
            var slides = {};
            var current = 0;
            var $current = $slides.eq(0);
            var hash = location.hash;
            var links = '';
            var autoslide_timeout = null;
            var accessor = {};
            $this.data('accessor', accessor);
            var block_slide_to = false;

            for ( var i = 0; i <= $slides.length; i++ ) {
                var slide = $slides.get(i);
                $(slide).data('tpslide-key', i);
            };

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

                if ( settings.onslide ) settings.onslide($current);
            };

            accessor.slide_to = function (val) {
                if ( block_slide_to ) return;
                var $el;
                if ( typeof val == 'string' ) {
                    $el = $(val);
                } else if ( val.jquery ) {
                    $el = val;
                } else {
                    $el = $(val);
                }

                // TODO: figure out the dohash stuff
                if ( $current[0] != $el[0] ) {
                    $current = $el;
                    current = $current.data('tpslide-key');
                    slide(false);
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
            $next.bind('click', function (e) {
                block_slide_to = true;
                e.preventDefault();
                next();
                block_slide_to = false;
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
            $prev.bind('click', function (e) {
                block_slide_to = true;
                e.preventDefault();
                prev();
                block_slide_to = false;
            });
            $nav_slides.delegate('a', 'click', function (e) {
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


            // Swipe - requires jquery.touchSwipe.js
            $wrapper.swipe({
                swipeLeft: function(event, direction, distance, duration, fingerCount) {
                    next();
                },
                swipeRight: function(event, direction, distance, duration, fingerCount) {
                    prev();
                },
                threshold: settings.threshold
            });

            slide(false);
        });
    };
})(jQuery);
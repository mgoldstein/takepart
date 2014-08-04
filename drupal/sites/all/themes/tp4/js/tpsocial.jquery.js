(function(window, $, undefined) {
    // Plugin

    var dpre = 'tps';
    var cpre = 'tp-social-';
    var $window = $(window);

    var default_title = document.title;
    if ($("meta[property='og:title']").attr("content")) {
        default_title = $("meta[property='og:title']").attr("content");
    }
    else if ($("meta[name='twitter:title']").attr("content")) {
        default_title = $("meta[name='twitter:title']").attr("content");
    }

    // Default values

    var default_url = document.location.href;
    var $rel_canonical = $('link[rel="canonical"]');
    if ($rel_canonical.length)
        default_url = $rel_canonical.attr('href');

    var defaults = {
        url: default_url,
        title: default_title
    };

    // function to make social share link
    var makeLink = function(args) {
        var $link = $('<a href="#"/>')
                .addClass(cpre + args.name)
                .addClass(cpre + 'link')
                .html(args.display);
        return $link;
    };

    // Make an object based on data- attributes from the given jQuery object
    var get_data = function($el, prefix_main, prefix_secondary) {
        var data = $el.data();
        var ret = {};
        var prop, i;
        for (i in data) {
            if (i.indexOf(prefix_main) === 0) {
                prop = i.substring(prefix_main.length);
                ret[prop] = data[i];
            } else if (i.indexOf(prefix_secondary) === 0) {
                prop = i.substring(prefix_secondary.length);
                ret[prop] = data[i];
            }
        }

        return ret;
    };

    $.fn.tpsocial = function(args) {
        //var settings = $.extend(defaults, args);
        //var services = settings.services;
        var services = args.services;

        return this.each(function() {
            var $this = $(this);

            // Loop through the requested services
            for (var s in services) {
                var service = services[s];
                var name = service.name;

                // See if the requested service has been added
                if (!(name in valid_services)) {
                    continue;
                }
                var srvc = $.extend({}, valid_services[name], service);

                // Find the link for the requested service in the node
                var $link = $this.find('a.' + cpre + name + ', .' + cpre + name + ' a');
                // If none exists, create and append it
                if (!$link.length) {
                    $link = makeLink(srvc);

                    var $container = $this.find('.' + cpre + name);
                    if ($container.length) {
                        $container.append($link);
                    } else {
                        $this.append($link);
                    }
                }
                // Add service specific arguments to the links'd data object
                for (var i in service) {
                    if (typeof service[i] == 'function')
                        continue;
                    $link.data(dpre + name + i, service[i]);
                }

                // If you are simply updating the services, bail out
                if ($this.data(dpre + 'processed'))
                    continue;

                // Set up link
                var data = $.extend({}, defaults, srvc, get_data($this, dpre + srvc.name, dpre), get_data($link, dpre + srvc.name, dpre));
                if (typeof data.prepare == 'function') {
                    data.prepare($link[0], data);

                    // Bind an event to the link 
                    if (name != "mailto") {
                        $link.bind('click', (function(srvc, $parent, $lnk) {
                            return function(e) {
                                // TODO: reduce the code duplication
                                var data = $.extend({}, defaults, args, srvc, get_data($parent, dpre + srvc.name, dpre), get_data($lnk, dpre + srvc.name, dpre));
                                data.element = this;
                                if (data.url == '{current}')
                                    data.url = document.location.href;
                                if (data.url_append != undefined) {
                                    // TODO: more than just {{name}} replacement
                                    data.url_append = data.url_append.replace('{{name}}', data.name);

                                    if (data.url.indexOf('?') !== -1 && data.url_append.indexOf('?') !== -1) {
                                        data.url_append = data.url_append.replace('?', '&');
                                    }
                                    data.url += data.url_append;
                                }

                                srvc.share(data);
                                $window.trigger(cpre + 'click', data);
                                e.preventDefault();
                                return true;
                            }
                        })(srvc, $this, $link)
                                );
                    }
                }
                if (typeof data.hoverfocus == 'function') {
                    $link.bind('mouseover focus', (function(srvc, $parent, $lnk) {
                        return function(e) {
                            var data = $.extend({}, defaults, args, srvc, get_data($parent, dpre + srvc.name, dpre), get_data($lnk, dpre + srvc.name, dpre));

                            if (data.url == '{current}')
                                data.url = document.location.href;
                            if (data.url_append != undefined) {
                                // TODO: more than just {{name}} replacement
                                data.url_append = data.url_append.replace('{{name}}', data.name);

                                if (data.url.indexOf('?') !== -1 && data.url_append.indexOf('?') !== -1) {
                                    data.url_append = data.url_append.replace('?', '&');
                                }
                                data.url += data.url_append;
                            }

                            data.element = this;

                            srvc.hoverfocus(data);
                            //e.preventDefault();
                        }
                    })(srvc, $this, $link)
                            );
                }
            }

            $this.data(dpre + 'processed', true);
            $this.addClass(cpre + 'processed');
        });
    };

    var valid_services = {};

    $.tpsocial = {
        add_service: function(args) {
            valid_services[args.name] = args;
        },
        // Load script and run callback
        queues: {},
        onces: {},
        load_script: function(test, url, context, callback, once) {
            if (test != undefined) {
                callback.call(context);
                return true;
            }

            if ($.tpsocial.queues[url] != undefined) {
                $.tpsocial.queues[url].push(callback);
                return;
            }

            $.tpsocial.queues[url] = [];
            $.tpsocial.onces[url] = once;

            var ready = function(s) {
                // Use this in IE if we want to track throughout the load.
                if (s.readyState == 'loaded' || s.readyState == 'complete')
                    done();
            }

            var done = function() {
                for (var i in $.tpsocial.queues[url]) {
                    var cb = $.tpsocial.queues[url][i];
                    if (typeof cb == 'function')
                        cb.call(context);
                }

                if (typeof $.tpsocial.onces[url] == 'function')
                    $.tpsocial.onces[url].call(context);
            }

            var s = document.createElement('script');
            s.type = "text/javascript";
            s.onreadystatechange = function(s) {
                return function() {
                    ready(s)
                }
            }(s);
            s.onerror = s.onload = done;
            s.src = url;
            document.getElementsByTagName('head')[0].appendChild(s);
        }
    };
})(window, jQuery);

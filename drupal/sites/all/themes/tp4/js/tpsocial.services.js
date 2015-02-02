(function(window, $, undefined) {

    // Return string from template
    var twitter_tpl_reg = /{{([a-zA-Z\-_]+)}}/g;
    var template_tplvar_clean_reg = /({{)|(}})/g;

    var template_value = function(tpl_name, args) {
        // Replace variables in twitter template
        var text = args[tpl_name] || '';
        var matches = text.match(twitter_tpl_reg);

        for (var i in matches) {
            var match = matches[i];
            var prop = match.replace(template_tplvar_clean_reg, '');

            if (match != tpl_name && args[prop] != undefined && args[prop]) {
                text = text.replace(match, args[prop]);
            } else {
                text = text.replace(match, '');
            }
        }

        return text;
    };

    var logged_in = function() {
        if ( document.cookie.match(/takepart=/gi) )
            return true;
        else
            return false;
    };

    var get_login_cookie = function() {
        return decodeURIComponent(document.cookie.replace(new RegExp("(?:(?:^|.*;)\\s*" + encodeURIComponent('takepart').replace(/[\-\.\+\*]/g, "\\$&") + "\\s*\\=\\s*([^;]*).*$)|^.*$"), "$1")) || '';
    };

    var get_share_url = function(url, title, callback, _shorten) {
        var shorten = (typeof _shorten != 'undefined') ? _shorten : false;
        if (window.TP.tabHost) {
            $.ajax({
                url: window.TP.tabHost + "/share.json",
                dataType: 'json',
                data: {url: url, title: title, shorten: shorten, login_info: get_login_cookie()},
                type: 'POST',
                async: false,
                success: function(data) {
                    callback(data.share_url);
                },
                error: function() {
                    callback(url);
                }
            });
        } else {
            callback(url);
        }
    }

    // Add services

    $.tpsocial.add_service({
        name: 'facebook',
        display: 'Facebook',
        image: null,
        caption: null,
        description: null,
        share: function(args) {
            get_share_url(args.url, args.title, function(url) {
                var parser = document.createElement("a");
                parser.href = args.url;
                FB.ui({
                    method: 'feed',
                    name: args.title,
                    link: url + '',
                    picture: args.image,
                    caption: args.caption || parser.hostname,
                    description: args.description //,
                            // message: 'Facebook Dialogs are easy!' ???
                },
                function(response) {
                    if (response && response.post_id) {
                        // Post was published
                        $window.trigger('tp-social-share', args);
                    } else {
                        //Post was not published
                    }
                });
            });
        }
    });

    $.tpsocial.add_service({
        name: 'twitter',
        display: 'Twitter',
        width: 550,
        height: 420,
        share: function(args) {
            // Replace variables in twitter template
            var twitter_tpl_reg = /{{([a-zA-Z\-_]+)}}/g;
            var template_tplvar_clean_reg = /({{)|(}})/g;

            var text = args.text || '{{title}}';
            var matches = text.match(twitter_tpl_reg);
            var url_obj = {
                url: args.url,
                via: args.via,
                in_reply_to: args.in_reply_to,
                hashtags: args.hashtags,
                related: args.related
            };

            for (var i in matches) {
                var match = matches[i];
                var prop = match.replace(template_tplvar_clean_reg, '');

                if (match != 'text' && args[prop] != undefined && args[prop]) {
                    text = text.replace(match, args[prop]);
                } else {
                    text = text.replace(match, '');
                }
            }

            if (text)
                url_obj.text = text;

            get_share_url(args.url, args.title, function(new_url) {
                var url_parts = [];
                url_obj.url = new_url;
                for (var i in url_obj) {
                    var val = url_obj[i];
                    if (val != undefined && val)
                        url_parts.push(i + '=' + encodeURIComponent(val));
                }
                var url = 'https://twitter.com/intent/tweet?' + url_parts.join('&');

                // Open twitter share
                var windowOptions = 'scrollbars=yes,resizable=yes,toolbar=no,location=yes';
                var left = 0;
                var tops = Number((screen.height / 2) - (args.height / 2));
                window.open(url, undefined, [windowOptions, "width=" + args.width, "height=" + args.height, "left=" + left, "top=" + tops].join(", "));
            }, true)

            //$window.trigger('tp-social-share', args);
        }
    });

    $.tpsocial.add_service({
        name: 'aolmail',
        display: 'AOL Mail',
        width: 1000,
        height: 650,
        share: function(args) {
            var url = 'http://mail.aol.com/compose-message.aspx?subject=' + encodeURIComponent(args.title) + '&body=' + encodeURIComponent(args.url);
            var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
            window.open(url, undefined, [windowOptions, "width=" + args.width, "height=" + args.height].join(", "));
        }
    });

    $.tpsocial.add_service({
        name: 'yahoomail',
        display: 'Y! Mail',
        width: 660,
        height: 650,
        share: function(args) {
            var url = 'http://compose.mail.yahoo.com/?subject=' + encodeURIComponent(args.title) + '&body=' + encodeURIComponent(args.url);
            var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
            window.open(url, undefined, [windowOptions, "width=" + args.width, "height=" + args.height].join(", "));
        }
    });

    $.tpsocial.add_service({
        name: 'hotmail',
        display: 'Hotmail',
        width: 490,
        height: 600,
        share: function(args) {
            var url = 'https://mail.live.com/default.aspx?rru=compose&subject=' + encodeURIComponent(args.title) + '&body=' + encodeURIComponent(args.url);
            var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
            window.open(url, undefined, [windowOptions, "width=" + args.width, "height=" + args.height].join(", "));
        }
    });

    $.tpsocial.add_service({
        name: 'gmail',
        display: 'Gmail',
        width: 460,
        height: 500,
        share: function(args) {
            var url = 'https://mail.google.com/mail/?view=cm&ui=1&tf=0&fs=1&su=' + encodeURIComponent(args.title) + '&body=' + encodeURIComponent(args.url);
            var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
            window.open(url, undefined, [windowOptions, "width=" + args.width, "height=" + args.height].join(", "));
        }
    });

    $.tpsocial.add_service({
        name: 'tumblr_link',
        display: 'Tumblr',
        width: 460,
        height: 500,
        description: '',
        share: function(args) {
            var url = 'http://www.tumblr.com/share/link?name=' + encodeURIComponent(args.title) + '&description=' + encodeURIComponent(args.description) + '&url=' + encodeURIComponent(args.url);
            var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
            window.open(url, undefined, [windowOptions, "width=" + args.width, "height=" + args.height].join(", "));
        }
    });

    $.tpsocial.add_service({
        name: 'tumblr',
        display: 'Tumblr',
        width: 460,
        height: 500,
        media: null,
        caption: null,
        source: null,
        share: function(args) {
            var url = 'http://www.tumblr.com/share/photo?source=' + encodeURIComponent(args.source) + '&caption=' + encodeURIComponent(args.caption) + '&click_thru=' + encodeURIComponent(args.url);
            var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
            window.open(url, undefined, [windowOptions, "width=" + args.width, "height=" + args.height].join(", "));
        }
    });

    $.tpsocial.add_service({
        name: 'pinterest',
        display: 'Pinterest',
        width: 760,
        height: 316,
        media: '',
        description: '',
        share: function(args) {
            get_share_url(args.url, args.title, function(_new_url){ 
                if ( !args.description ) args.description = args.title;
                args.description = args.description + '';
                if ( args.description.length > 499 ) {
                    args.description = args.description.substring(0, 496) + '...';
                }
                var url = '//pinterest.com/pin/create/button/?url=' + encodeURIComponent(_new_url) + '&media=' + encodeURIComponent(args.media) + '&description=' + encodeURIComponent(args.description);

                var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
                window.open(url, undefined, [windowOptions,"width="+args.width,"height="+args.height].join(", "));
            });
        }
    });

    $.tpsocial.add_service({
        name: 'googleplus',
        display: 'Google +1',
        width: 600,
        height: 600,
        share: function(args) {
            get_share_url(args.url, args.title, function(_new_url){ 
                var url = 'https://plus.google.com/share?url=' + encodeURIComponent(_new_url);
                var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
                window.open(url, undefined, [windowOptions,"width="+args.width,"height="+args.height].join(", "));
            });
        }
    });

    $.tpsocial.add_service({
        name: 'reddit',
        display: 'Reddit',
        width: 850,
        height: 600,
        share: function(args) {
            get_share_url(args.url, args.title, function(_new_url) {
                var url = 'http://www.reddit.com/submit?url=' + encodeURIComponent(_new_url) + '&title=' + encodeURIComponent(args.title);
                var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
                window.open(url, undefined, [windowOptions, "width=" + args.width, "height=" + args.height].join(", "));
            });
        }
    });

    $.tpsocial.add_service({
        name: 'myspace',
        display: 'Myspace',
        width: 550,
        height: 450,
        share: function(args) {
            var url = 'http://www.myspace.com/Modules/PostTo/Pages/?u=' + encodeURIComponent(args.url) + '&t=' + encodeURIComponent(args.title);
            var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
            window.open(url, undefined, [windowOptions, "width=" + args.width, "height=" + args.height].join(", "));
        }
    });

    $.tpsocial.add_service({
        name: 'delicious',
        display: 'Delicious',
        width: 550,
        height: 420,
        share: function(args) {
            var url = 'https://delicious.com/post?url=' + encodeURIComponent(args.url) + '&title=' + encodeURIComponent(args.title) + '&notes=';
            var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
            window.open(url, undefined, [windowOptions, "width=" + args.width, "height=" + args.height].join(", "));
        }
    });

    $.tpsocial.add_service({
        name: 'linkedin',
        display: 'Linked In',
        width: 600,
        height: 390,
        share: function(args) {
            var url = 'http://www.linkedin.com/shareArticle?mini=true&url=' + encodeURIComponent(args.url) + '&title=' + encodeURIComponent(args.title) + '&ro=false&summary=&source=';
            var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
            window.open(url, undefined, [windowOptions, "width=" + args.width, "height=" + args.height].join(", "));
        }
    });

    $.tpsocial.add_service({
        name: 'myaol',
        display: 'My AOL',
        width: 600,
        height: 370,
        share: function(args) {
            var url = 'http://favorites.my.aol.com/ffclient/AddBookmark?url=' + encodeURIComponent(args.url) + '&title=' + encodeURIComponent(args.title) + '&description=';
            var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
            window.open(url, undefined, [windowOptions, "width=" + args.width, "height=" + args.height].join(", "));
        }
    });

    $.tpsocial.add_service({
        name: 'live',
        display: 'Messenger',
        width: 1020,
        height: 570,
        share: function(args) {
            var url = 'https://profile.live.com/P.mvc#!/badge?url=' + encodeURIComponent(args.url) + '&title=' + encodeURIComponent(args.title);
            var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
            window.open(url, undefined, [windowOptions, "width=" + args.width, "height=" + args.height].join(", "));
        }
    });

    $.tpsocial.add_service({
        name: 'digg',
        display: 'Digg',
        width: 1070,
        height: 670,
        share: function(args) {
            var url = 'http://digg.com/submit?url=' + encodeURIComponent(args.url) + '&title=' + encodeURIComponent(args.title) + '&bodytext=';
            var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
            window.open(url, undefined, [windowOptions, "width=" + args.width, "height=" + args.height].join(", "));
        }
    });

    $.tpsocial.add_service({
        name: 'stumbleupon',
        display: 'Stumbleupon',
        width: 790,
        height: 560,
        share: function(args) {
            var url = 'http://www.stumbleupon.com/submit?url=' + encodeURIComponent(args.url) + '&title=' + encodeURIComponent(args.title);
            var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
            window.open(url, undefined, [windowOptions, "width=" + args.width, "height=" + args.height].join(", "));
        }
    });

    $.tpsocial.add_service({
        name: 'hyves',
        display: 'Hyves',
        width: 1030,
        height: 700,
        share: function(args) {
            var url = 'http://www.hyves.nl/profilemanage/add/tips/?name=' + encodeURIComponent(args.title) + '&text=' + encodeURIComponent(args.url) + '&type=12#';
            var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
            window.open(url, undefined, [windowOptions, "width=" + args.width, "height=" + args.height].join(", "));
        }
    });

    $.tpsocial.add_service({
        name: 'mailto',
        display: 'Email App',
        share: function(args) {
            var url = 'mailto:?body=' + encodeURIComponent(window.location) + '?cmpid=organic-share-mailto' + '&subject=' + encodeURIComponent(args.title);
            location.href = url;
      }
    });
})(window, jQuery);
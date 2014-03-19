TEACH = window.TEACH || { support: {}, social: {}, Models: {}, Collections: {}, Views: {} };

// Magic Numbers
TEACH.TAP = {
    postURL: "http://qa-web1.tab.takepart.com/user_teach_stories",
    action_id: "9035092",
    partner_code: "38ec3cd1db216fd6964277e5969f4cb2"
};

//
// Our own little modernizr
//

// detect touch support
TEACH.support.touchEnabled = 'ontouchstart' in window || window.DocumentTouch && document instanceof DocumentTouch;

// detect localstorage
TEACH.support.hasStorage = (function() {
    try {
        localStorage.setItem('foo', 'test');
        localStorage.removeItem('test');
        return true;
    } catch (e) {
        return false;
    }
})();

// detect whether we're in an iframe
TEACH.support.loadedInIframe = (function() {
    try {
        return window.self !== window.top;
    } catch (e) {
        return true;
    }
})();

// social share options
TEACH.social.options = {
    url_append: '?cmpid=organic-share-{{name}}',
    services: [
        {
            name: 'facebook'
        },
        {
            name: 'twitter',
            text: '{{title}}'
        },
        {
            name: 'googleplus'
        }
    ]
};


// Simple JavaScript Templating
// John Resig - http://ejohn.org/ - MIT Licensed
TEACH.templateCache = {};

TEACH.tmpl = function tmpl(str, data) {
    // Figure out if we're getting a template, or if we need to
    // load the template - and be sure to cache the result.
    var fn = !/\W/.test(str) ?
            TEACH.templateCache[str] = TEACH.templateCache[str] ||
            tmpl(document.getElementById(str).innerHTML) :
            // Generate a reusable function that will serve as a template
            // generator (and which will be cached).
            new Function("obj",
                    "var p=[],print=function(){p.push.apply(p,arguments);};" +
                    // Introduce the data as local variables using with(){}
                    "with(obj){p.push('" +
                    // Convert the template into pure JavaScript
                    str
                    .replace(/[\r\t\n]/g, " ")
                    .split("<%").join("\t")
                    .replace(/((^|%>)[^\t]*)'/g, "$1\r")
                    .replace(/\t=(.*?)%>/g, "',$1,'")
                    .split("\t").join("');")
                    .split("%>").join("p.push('")
                    .split("\r").join("\\'")
                    + "');}return p.join('');");

    // Provide some basic currying to the user
    return data ? fn(data) : fn;
};

TEACH.stateNames = {AL:"Alabama",AK:"Alaska",AS:"America Samoa",AZ:"Arizona",AR:"Arkansas",CA:"California",CO:"Colorado",CT:"Connecticut",DE:"Delaware",DC:"District of Columbia",FL:"Florida",GA:"Georgia",GU:"Guam",HI:"Hawaii",ID:"Idaho",IL:"Illinois",IN:"Indiana",IA:"Iowa",KS:"Kansas",KY:"Kentucky",LA:"Louisiana",ME:"Maine",MD:"Maryland",MA:"Massachusetts",MI:"Michigan",MN:"Minnesota",MS:"Mississippi",MO:"Missouri",MT:"Montana",NE:"Nebraska",NV:"Nevada",NH:"New Hampshire",NJ:"New Jersey",NM:"New Mexico",NY:"New York",NC:"North Carolina",ND:"North Dakota",OH:"Ohio",OK:"Oklahoma",OR:"Oregon",PW:"Palau",PA:"Pennsylvania",PR:"Puerto Rico",RI:"Rhode Island",SC:"South Carolina",SD:"South Dakota",TN:"Tennessee",TX:"Texas",UT:"Utah",VT:"Vermont",VI:"Virgin Island",VA:"Virginia",WA:"Washington",WV:"West Virginia",WI:"Wisconsin",WY:"Wyoming"};

// augment String.prototype with some things
String.prototype.htmlEntities = function() {
    return this.replace(/&/g, '&amp;').replace(/</g, '&lt;').replace(/>/g, '&gt;').replace(/"/g, '&quot;');
};

// polyfill for String.trim()
if (!String.prototype.trim) {
    String.prototype.trim = function() {
        return this.replace(/^\s+|\s+$/g, '');
    };
}

(function($, Drupal, window, document, undefined) {

    Drupal.behaviors.iFrameBuster = {
        attach: function() {
            // hide some things when we're on facebook
            // (i.e., when the site is loaded in an iframe)
            if (TEACH.support.loadedInIframe) {
                $('.footer-wrapper, .slimnav').remove();
                $('body').css('border', 'none');
                $('.page-wrap').css('padding', '0');
                // $('#page').css('padding', '0'); // in case we want to go even wider
            }
        }
    };

    Drupal.behaviors.punishInternetExplorerUsers = {
        attach: function(context) {
            var message = '<p>The TEACH website is a richly interactive web experience and full functionality requires a <a href="http://browsehappy.com/" target="_blank">recent web browser</a>.</p>',
                    contentSelector = ($('body').is('.page-wordlet-teach')) ? '.page-body-content' : '#page > .content';
            if ($.browser.msie && parseInt($.browser.version, 10) < 10) {
                $('<div />')
                        .addClass('messages error')
                        .html(message)
                        .prependTo(contentSelector)
                        ;
            }
        }
    };
    Drupal.behaviors.newsletterSocialSignupSubmitted = {
        attach: function(context) {
            if ($(context).is('.newsletter-signup.thank-you-message')) {
                var name = context.attr('data-newsletter-name');
                takepart.analytics.track('newsletter_signup', {name: name});
            }
        }
    };
    Drupal.behaviors.teachAllianceLogoResize = {
        attach: function() {
            if ($('body').is('.page-wordlet-teach-alliances')) {
                var $alliance = $('.alliances').find('.alliance'),
                        resizeAlliances = function() {
                            $alliance.each(function(i, el) {
                                var $el = $(el),
                                        height = Math.round(($el.width() * 3) / 4);
                                $el.height(height).css('line-height', (height - 20) + 'px');
                            });
                        };
                resizeAlliances();
                $(window).resize(function() {
                    resizeAlliances();
                });
            }
        }
    }
    Drupal.behaviors.campaignShare = {
        attach: function() {
            $('.campaign-social-share:not(.tp-social-skip)').each(function() {

                var $this = $(this);
                var url = $this.data('shareurl') || 'http://www.takepart.com/teach';
                var title = $this.data('sharetitle') || 'TEACH | Join the “Teacher Stories” initiative and help us support great teachers.';
                var description = $this.data('sharedescription').replace(/<[^>]+>/ig, '') || 'Share a teacher story and you’ll help us give away more than $10,000 to public schools.';

                var opts = $.extend({}, TEACH.social.options, {
                    services: [
                        {
                            name: 'facebook',
                            url: url,
                            title: title,
                            description: description
                        },
                        {
                            name: 'twitter',
                            url: url,
                            text: description,
                            via: 'TeachMovie'
                        },
                        {
                            name: 'googleplus',
                            url: url
                        }
                    ]
                });

                $this.tpsocial(opts);

            });
        }
    };
    Drupal.behaviors.teachTextLightbox = {
        attach: function() {
            var modalOptions = {
                id: 'teach_text_lightbox_'
            };

            $('body').on('click', '.teach-text-lightbox', function(e) {
                e.preventDefault();

                $.tpmodal.show(modalOptions);

                $node = $('<div />')
                        .css({maxWidth: "800px"})
                        .load($(this).attr('href') + ' .view-mode-full', function() {
                            $.tpmodal.show($.extend(modalOptions, {node: this}));
                        })
                        ;
            });
        }
    };

    // The window level TP Social click event needs to be attached to the
    // TP Analytics social click handler.
    Drupal.behaviors.trackSocialClicks = {
        attach: function() {
            $(window).on('tp-social-click', function(e, args) {
                takepart.analytics.track('tp-social-click', args);
            });
        }
    };
})(jQuery, Drupal, this, this.document);

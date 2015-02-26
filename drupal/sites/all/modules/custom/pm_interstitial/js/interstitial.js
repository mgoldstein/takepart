(function($, Drupal, window, document, undefined) {
    Drupal.behaviors.interstitialsBehaviors = {
        attach: function(context, settings) {
            // INTERSTITIALS
            $('body').once('interstitial_init', function() {
              //check if mobile
              var isMobile = {
                Android: function() {
                  return navigator.userAgent.match(/Android/i);
                },
                BlackBerry: function() {
                  return navigator.userAgent.match(/BlackBerry/i);
                },
                iOS: function() {
                  return navigator.userAgent.match(/iPhone|iPad|iPod/i);
                },
                Opera: function() {
                  return navigator.userAgent.match(/Opera Mini/i);
                },
                Windows: function() {
                  return navigator.userAgent.match(/IEMobile/i);
                },
                any: function() {
                  return (isMobile.Android() || isMobile.BlackBerry() || isMobile.iOS() || isMobile.Opera() || isMobile.Windows());
                }
              };
              if(isMobile.any()) {
                interstitial_init();
              }else{
                interstitial_init();
              }

            });

            function GetQueryStringParams(sParam) {
                var sPageURL = window.location.search.substring(1);
                var sURLVariables = sPageURL.split('&');

                for (var i = 0; i < sURLVariables.length; i++) {
                    var sParameterName = sURLVariables[i].split('=');
                    if (sParameterName[0] === sParam) {
                        return sParameterName[1];
                    }
                }
            }
            function interstitial_init() {

                // FOR TESTING
                /*
                 var interstitial_links = $('#block-pm-interstitial-interstitials .content a');
                 if(interstitial_links.length > 0){
                 show_interstitial(interstitial_links.filter('[data-interstitial-type="email"]'));
                 }
                 return;
                 */
                // alert(GetQueryStringParams('cmpid'));
                var interstitial_cookie = $.cookie('pm_igloo');
                var referer_cookie = $.cookie('pm_referers') || '';
                var referers = $('body').attr('data-interstitial-referer');
                if (typeof referers === 'undefined') { // opt out
                    return;
                }
                if (interstitial_cookie === null) { // first page view
                    // create ignore interstitial cookie and set to off
                    $.cookie('pm_igloo', 0, {path: '/'});

                    // create referer list cookie
                    $.cookie('pm_referers', referers, {path: '/'});

                } else if (interstitial_cookie === '0' && GetQueryStringParams('cmpid') !== 'eml') { // second page view (or subsequent page view without closing the interstitial)
                    var excluded_links = referer_cookie.split(',');
                    var $interstitial_links = $('#block-pm-interstitial-interstitials a.interstitial');
                    if ($interstitial_links.length <= 0) {
                        return;
                    }
                    // exclude referrer classes and map the remaining hrefs
                    var interstitial_links = $.map($interstitial_links, function(link, i) {
                        if ($.inArray($(link).attr('data-interstitial-type'), excluded_links) === -1) {
                            return $(link);
                        }
                    });
                    // show random href from list of available interstitials
                    show_interstitial(interstitial_links[Math.floor(Math.random() * interstitial_links.length)]);
                }
            }

            function show_interstitial(interstitial_link) {
                var interstitial_modal_id = 'interstitial_modal_';
                var address = interstitial_link.attr('href');
                var $iframe = $('<iframe src="' + address + '"></iframe>').css({border: '0'});
                var interstitial_type = interstitial_link.attr('data-interstitial-type');
                var analytics_types = {
                    'email': 'Newsletter',
                    'social': 'Social',
                };
                $iframe.bind('load', function() {
					// prevent scrolling, you sick bastard
					$('body').css('overflow','hidden');

                    var $modal = $('#' + interstitial_modal_id + 'modal');
                    $modal.show();
                    if(window.innerWidth <= 480) {
                      var w = 300;
                    }else{
                      var w = 400;
                    }
                    var h = $iframe.contents().find('html').height();
                    $modal.hide();
                    $iframe.css({width: w, height: h});
                    $modal.css({overflow: 'hidden'});
                    $.tpmodal.showModal({id: interstitial_modal_id});
                    return takepart.analytics.track('tpinterstitial_show_modal', {interstitial_type: analytics_types[interstitial_type]});
                });

                var extend_pm_interstitial_cookie = function(days) {
                    var date = new Date();
                    date.setTime(date.getTime() + (days * 24 * 60 * 60 * 1000));
                    $.cookie('pm_igloo', null);
                    $.cookie('pm_igloo', 1, {expires: date, path: '/'});
                };

                window.dont_show_interstitial = function() {
                    $.tpmodal.set({
                        id: interstitial_modal_id,
                        values: {
                            afterClose: function() {
                                extend_pm_interstitial_cookie(365 * 5);
                                takepart.analytics.track('tpinterstitial_dontshow', {interstitial_type: analytics_types[interstitial_type]});
                            }
                        }
                    });
                    $.tpmodal.hide({id: interstitial_modal_id});
                };

                window.interstitial_social_click = function(service) {
                    if (service === "twitter") {
                        takepart.analytics.track('tpinterstitial_twitter');
                    } else if (service === "facebook") {
                        takepart.analytics.track('tpinterstitial_facebook');
                    }
                }

                window.interstitial_newsletter_signup = function(title) {
                    takepart.analytics.track('tpinterstitial_newsletter_signup', {title: title});
                }
                $.tpmodal.load({
                    id: interstitial_modal_id,
                    node: $iframe,
                    afterClose: function() {
						// return scrolling to the body
						$('body').css('overflow','scroll');
                        extend_pm_interstitial_cookie(7);
                        takepart.analytics.track('tpinterstitial_dismiss', {interstitial_type: analytics_types[interstitial_type]});
                    }
                });
            }
        }
    };
})(jQuery, Drupal, this, this.document);

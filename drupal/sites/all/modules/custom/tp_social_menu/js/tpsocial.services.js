(function (window, $, undefined) {

  // Return string from template
  var twitter_tpl_reg = /{{([a-zA-Z\-_]+)}}/g;
  var template_tplvar_clean_reg = /({{)|(}})/g;

  var template_value = function (tpl_name, args) {
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

  var logged_in = function () {
    if (document.cookie.match(/takepart=/gi))
	 return true;
    else
	 return false;
  };

  var get_login_cookie = function () {
    return decodeURIComponent(document.cookie.replace(new RegExp("(?:(?:^|.*;)\\s*" + encodeURIComponent('takepart').replace(/[\-\.\+\*]/g, "\\$&") + "\\s*\\=\\s*([^;]*).*$)|^.*$"), "$1")) || '';
  };

  var get_share_url = function (url, title, callback, _shorten) {
    var shorten = (typeof _shorten != 'undefined') ? _shorten : false;
    if (window.TP.tabHost) {
      $.ajax({
        url: window.TP.tabHost + "/share.json",
        dataType: 'json',
        data: {
          url: url,
          title: title,
          shorten: shorten,
          login_info: get_login_cookie()
        },
        type: 'POST',
        async: false,
        success: function (data) {
          callback(data.share_url);
        },
        error: function () {
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
    share: function (args) {
    	 get_share_url(args.url, args.title, function (url) {
    	   var parser = document.createElement("a");
    	   parser.href = args.url;

         //Set the url to the link
         $('.tp-social .tp-social-facebook').attr('href',"http://facebook.com/share.php?u="+url);
         //Desktop view will do a window.open, but Mobile view will do a new tab
         if($('.social-wrapper').hasClass('desktop') || $('body').hasClass('node-type-campaign-page')) {
           FB.ui(
             {
               method: 'share',
               href: url
             },
             function (response) {
               if (response && response.post_id) {
                 // Post was published
                 $window.trigger('tp-social-share', args);
               }
               else {
                 //Post was not published
               }
             });
          }

    	   function openFBLoginDialogManually() {
           if ($('body').hasClass('tploggedin')) {
             var logged_class = '-influence';
           }
           else {
             var logged_class = '';
           }

           // Open your auth window containing FB auth page
           // with forward URL to your Opened Window handler page (below)
           var redirect_uri = "&redirect_uri=" + url + "fbjscomplete";
           var scope = "&scope=public_profile,email,user_friends";
           var url = "https://www.facebook.com/dialog/oauth?client_id=" + "247137505296280" + redirect_uri + scope + '&cmpid=organic-share-facebook' + logged_class;
           // notice the lack of other param in window.open
           // for some reason the opener is set to null
           // and the opened window can NOT reference it
           // if params are passed. #Chrome iOS Bug
           window.open(url);
    	   }

    	   function fbCompleteLogin() {
           FB.getLoginStatus(function (response) {
             // Calling this with the extra setting "true" forces
             // a non-cached request and updates the FB cache.
             // Since the auth login elsewhere validated the user
             // this update will now asyncronously mark the user as authed
           }, true);
    	   }

    	   function requireLogin(callback) {
      		FB.getLoginStatus(function (response) {
      		  if (response.status !== "connected") {
      		    showLogin();
      		  } else {
      		    checkAuth(response.authResponse.accessToken, response.authResponse.userID, function (success) {
      		    // Check FB tokens against your API to make sure user is valid
      		    });
      		  }
      		});
    	   }

    	   //only do for crios
    	   if (navigator.userAgent.match('CriOS')) {
    	     fbCompleteLogin();
    	   }
    	 });
       return true;
      }
  });

  $.tpsocial.add_service({
    name: 'facebookfeed',
    display: 'Facebook',
    share: function (args) {
    	 get_share_url(args.url, args.title, function (url) {
    	   var parser = document.createElement("a");
    	   parser.href = args.url;
         var text_width = args.description.length + 450;
           FB.ui({
             method: 'feed',
             display: 'popup',
             link: url,
             description: args.caption,
             name: args.share_title,
             picture: 'http://res.cloudinary.com/'+Drupal.settings.cloudinary_bucket+'/image/upload/g_north,x_0,y_120,w_'+text_width+',c_fit,l_text:Libre%20Baskerville_36_left_line_spacing_8:'+encodeURI(args.description).replace(/,/g, "%E2%80%9A").replace(/\?/g,"%253F")+'/l_text:arial_20:%20,g_south,x_0,y_-20/ar_1.91,c_fill/g_north,y_30,l_logo_ol/blank_quote_canvas.jpg'
           },
             function (response) {
               if (response && response.post_id) {
                 // Post was published
                 $window.trigger('tp-social-share', args);
               }
               else {
                 //Post was not published
               }
             });

    	   function openFBLoginDialogManually() {
           if ($('body').hasClass('tploggedin')) {
             var logged_class = '-influence';
           }
           else {
             var logged_class = '';
           }

           // Open your auth window containing FB auth page
           // with forward URL to your Opened Window handler page (below)
           var redirect_uri = "&redirect_uri=" + url + "fbjscomplete";
           var scope = "&scope=public_profile,email,user_friends";
           var url = "https://www.facebook.com/dialog/oauth?client_id=" + "247137505296280" + redirect_uri + scope + '&cmpid=organic-share-facebook' + logged_class;
           // notice the lack of other param in window.open
           // for some reason the opener is set to null
           // and the opened window can NOT reference it
           // if params are passed. #Chrome iOS Bug
           window.open(url);
    	   }

    	   function fbCompleteLogin() {
           FB.getLoginStatus(function (response) {
             // Calling this with the extra setting "true" forces
             // a non-cached request and updates the FB cache.
             // Since the auth login elsewhere validated the user
             // this update will now asyncronously mark the user as authed
           }, true);
    	   }

    	   function requireLogin(callback) {
      		FB.getLoginStatus(function (response) {
      		  if (response.status !== "connected") {
      		    showLogin();
      		  } else {
      		    checkAuth(response.authResponse.accessToken, response.authResponse.userID, function (success) {
      		    // Check FB tokens against your API to make sure user is valid
      		    });
      		  }
      		});
    	   }

    	   //only do for crios
    	   if (navigator.userAgent.match('CriOS')) {
    	     fbCompleteLogin();
    	   }
    	 });
       return false;
      }
  });

  $.tpsocial.add_service({
    name: 'twitter',
    display: 'Twitter',
    width: 550,
    height: 420,
    share: function (args) {
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
        related: args.related,
        anchor: args.anchor
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

      if (text) {
        url_obj.text = text;
      }

      get_share_url(args.url, args.title, function (new_url) {
        //For the quote we need to truncate
        if(typeof args.quote !== 'undefined' && args.quote) {
          //140 is the limit but need to remove the taken space the 13 for via
          //Minus 3 the quotes and spaces that get added
          var count = 140 - 3 - (args.author_name.length) - new_url.length - 13;
          if(url_obj.text.length > count) {
            url_obj.text = "\""+url_obj.text.substr(0, (count-4))+"...\""+args.author_name;
          } else {
            url_obj.text = "\""+url_obj.text+"\""+args.author_name;
          }
        }
        var url_parts = [];
        url_obj.url = new_url;
        for (var i in url_obj) {
          var val = url_obj[i];
          if (val !== undefined && val)
          url_parts.push(i + '=' + encodeURIComponent(val));
        }
        var url = 'https://twitter.com/intent/tweet?' + url_parts.join('&');

        // Open twitter share
        var windowOptions = 'scrollbars=yes,resizable=yes,toolbar=no,location=yes';
        var left = 0;
        var tops = Number((screen.height / 2) - (args.height / 2));

        //Set the url to the link
        if(typeof args.class_target !== 'undefined') {
          $('.'+args.class_target+' .tp-social-twitter').attr('href',url);
        } else {
          //Assume it is the main social share.
          $('.tp-social .tp-social-twitter').attr('href',url);
        }

        //Desktop view will do a window.open, but Mobile view will do a new tab
        if($('.social-wrapper').hasClass('desktop') || $('body').hasClass('node-type-campaign-page')) {
          window.open(url, undefined, [windowOptions, "width=" + args.width, "height=" + args.height, "left=" + left, "top=" + tops].join(", "));
        }

      }, true);

      return true;
    }
  });

  $.tpsocial.add_service({
    name: 'aolmail',
    display: 'AOL Mail',
    width: 1000,
    height: 650,
    share: function (args) {
      var url = 'http://mail.aol.com/compose-message.aspx?subject=' + encodeURIComponent(args.title) + '&body=' + encodeURIComponent(args.url);
      var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
      //Set the url to the link
      $('.tp-social .tp-social-aolmail').attr('href',url);
      //Desktop view will do a window.open, but Mobile view will do a new tab
      if($('.social-wrapper').hasClass('desktop') || $('body').hasClass('node-type-campaign-page')) {
        window.open(url, undefined, [windowOptions, "width=" + args.width, "height=" + args.height].join(", "));
      }
      return true;
    }
  });

  $.tpsocial.add_service({
    name: 'yahoomail',
    display: 'Y! Mail',
    width: 660,
    height: 650,
    share: function (args) {
      var url = 'http://compose.mail.yahoo.com/?subject=' + encodeURIComponent(args.title) + '&body=' + encodeURIComponent(args.url);
      var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
      $('.tp-social .tp-social-yahoomail').attr('href',url);
      //Desktop view will do a window.open, but Mobile view will do a new tab
      if($('.social-wrapper').hasClass('desktop') || $('body').hasClass('node-type-campaign-page')) {
        window.open(url, undefined, [windowOptions, "width=" + args.width, "height=" + args.height].join(", "));
      }
      return true;
    }
  });

  $.tpsocial.add_service({
    name: 'hotmail',
    display: 'Hotmail',
    width: 490,
    height: 600,
    share: function (args) {
      var url = 'https://mail.live.com/default.aspx?rru=compose&subject=' + encodeURIComponent(args.title) + '&body=' + encodeURIComponent(args.url);
      var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
      $('.tp-social .tp-social-hotmail').attr('href',url);
      //Desktop view will do a window.open, but Mobile view will do a new tab
      if($('.social-wrapper').hasClass('desktop') || $('body').hasClass('node-type-campaign-page')) {
        window.open(url, undefined, [windowOptions, "width=" + args.width, "height=" + args.height].join(", "));
      }
      return true;
    }
  });

  $.tpsocial.add_service({
    name: 'gmail',
    display: 'Gmail',
    width: 460,
    height: 500,
    share: function (args) {
      var url = 'https://mail.google.com/mail/?view=cm&ui=1&tf=0&fs=1&su=' + encodeURIComponent(args.title) + '&body=' + encodeURIComponent(args.url);
      var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
      $('.tp-social .tp-social-gmail').attr('href',url);
      //Desktop view will do a window.open, but Mobile view will do a new tab
      if($('.social-wrapper').hasClass('desktop') || $('body').hasClass('node-type-campaign-page')) {
        window.open(url, undefined, [windowOptions, "width=" + args.width, "height=" + args.height].join(", "));
      }
      return true;
    }
  });

  $.tpsocial.add_service({
    name: 'pinterest',
    display: 'Pinterest',
    width: 760,
    height: 316,
    media: '',
    description: '',
    share: function (args) {
      get_share_url(args.url, args.title, function (_new_url) {
        if (!args.description)
        args.description = args.title;
        args.description = args.description + '';
        if (args.description.length > 499) {
          args.description = args.description.substring(0, 496) + '...';
        }
        var url = '//pinterest.com/pin/create/button/?url=' + encodeURIComponent(_new_url) + '&media=' + encodeURIComponent(args.media) + '&description=' + encodeURIComponent(args.description);

        var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
        $('.tp-social .tp-social-pinterest').attr('href',url);
        //Desktop view will do a window.open, but Mobile view will do a new tab
        if($('.social-wrapper').hasClass('desktop') || $('body').hasClass('node-type-campaign-page')) {
          window.open(url, undefined, [windowOptions, "width=" + args.width, "height=" + args.height].join(", "));
        }
      });
      return true;
    }
  });

  $.tpsocial.add_service({
    name: 'tumblr',
    display: 'Tumblr',
    width: 460,
    height: 500,
    share: function (args) {
      if ($('body').hasClass('tploggedin')) {
        var logged_class = '-influence';
      }
      else {
        var logged_class = '';
      }
      var url = 'http://www.tumblr.com/share/link?name=' + encodeURIComponent(args.title) + '&description=' + encodeURIComponent($("meta[property='og:description']").attr("content")) + '&url=' + args.url + '&cmpid=organic-share-tumblr' + logged_class;
      var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
      $('.tp-social .tp-social-tumblr').attr('href',url);
      //Desktop view will do a window.open, but Mobile view will do a new tab
      if($('.social-wrapper').hasClass('desktop') || $('body').hasClass('node-type-campaign-page')) {
        window.open(url, undefined, [windowOptions, "width=" + args.width, "height=" + args.height].join(", "));
      }
      return true;
    }
  });

  $.tpsocial.add_service({
    name: 'whatsapp',
    display: 'WhatsApp',
    share: function (args) {
      var url = 'whatsapp://send?text=' + encodeURIComponent("Take a look at this awesome website: " + args.url);
      var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
      $('.tp-social .tp-social-whatsapp').attr('href',url);
      //Desktop view will do a window.open, but Mobile view will do a new tab
      if($('.social-wrapper').hasClass('desktop') || $('body').hasClass('node-type-campaign-page')) {
        window.open(url, undefined, [windowOptions, "width=" + args.width, "height=" + args.height].join(", "));
      }
      return true;
    }
  });

  $.tpsocial.add_service({
    name: 'googleplus',
    display: 'Google +1',
    width: 600,
    height: 600,
    share: function (args) {
      get_share_url(args.url, args.title, function (_new_url) {
        var url = 'https://plus.google.com/share?url=' + encodeURIComponent(_new_url);
        var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
        $('.tp-social .tp-social-googleplus').attr('href',url);
        //Desktop view will do a window.open, but Mobile view will do a new tab
        if($('.social-wrapper').hasClass('desktop') || $('body').hasClass('node-type-campaign-page')) {
          window.open(url, undefined, [windowOptions, "width=" + args.width, "height=" + args.height].join(", "));
        }
      });
      return true;
    }
  });

  $.tpsocial.add_service({
    name: 'reddit',
    display: 'Reddit',
    width: 850,
    height: 600,
    share: function (args) {
      get_share_url(args.url, args.title, function (_new_url) {
        var url = 'http://www.reddit.com/submit?url=' + encodeURIComponent(_new_url) + '&title=' + encodeURIComponent(args.title);
        var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
        $('.tp-social .tp-social-reddit').attr('href',url);
        //Desktop view will do a window.open, but Mobile view will do a new tab
        if($('.social-wrapper').hasClass('desktop') || $('body').hasClass('node-type-campaign-page')) {
          window.open(url, undefined, [windowOptions, "width=" + args.width, "height=" + args.height].join(", "));
        }
      });
      return true;
    }
  });

  $.tpsocial.add_service({
    name: 'myspace',
    display: 'Myspace',
    width: 550,
    height: 450,
    share: function (args) {
      var url = 'http://www.myspace.com/Modules/PostTo/Pages/?u=' + encodeURIComponent(args.url) + '&t=' + encodeURIComponent(args.title);
      var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
      $('.tp-social .tp-social-myspace').attr('href',url);
      //Desktop view will do a window.open, but Mobile view will do a new tab
      if($('.social-wrapper').hasClass('desktop') || $('body').hasClass('node-type-campaign-page')) {
        window.open(url, undefined, [windowOptions, "width=" + args.width, "height=" + args.height].join(", "));
      }
      return true;
    }
  });

  $.tpsocial.add_service({
    name: 'delicious',
    display: 'Delicious',
    width: 550,
    height: 420,
    share: function (args) {
      var url = 'https://delicious.com/post?url=' + encodeURIComponent(args.url) + '&title=' + encodeURIComponent(args.title) + '&notes=';
      var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
      $('.tp-social .tp-social-delicious').attr('href',url);
      //Desktop view will do a window.open, but Mobile view will do a new tab
      if($('.social-wrapper').hasClass('desktop') || $('body').hasClass('node-type-campaign-page')) {
        window.open(url, undefined, [windowOptions, "width=" + args.width, "height=" + args.height].join(", "));
      }
      return true;
    }
  });

  $.tpsocial.add_service({
    name: 'linkedin',
    display: 'Linked In',
    width: 600,
    height: 390,
    share: function (args) {
      var url = 'http://www.linkedin.com/shareArticle?mini=true&url=' + encodeURIComponent(args.url) + '&title=' + encodeURIComponent(args.title) + '&ro=false&summary=&source=';
      var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
      $('.tp-social .tp-social-linkedin').attr('href',url);
      //Desktop view will do a window.open, but Mobile view will do a new tab
      if($('.social-wrapper').hasClass('desktop') || $('body').hasClass('node-type-campaign-page')) {
        window.open(url, undefined, [windowOptions, "width=" + args.width, "height=" + args.height].join(", "));
      }
      return true;
    }
  });

  $.tpsocial.add_service({
    name: 'myaol',
    display: 'My AOL',
    width: 600,
    height: 370,
    share: function (args) {
      var url = 'http://favorites.my.aol.com/ffclient/AddBookmark?url=' + encodeURIComponent(args.url) + '&title=' + encodeURIComponent(args.title) + '&description=';
      var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
      $('.tp-social .tp-social-myaol').attr('href',url);
      //Desktop view will do a window.open, but Mobile view will do a new tab
      if($('.social-wrapper').hasClass('desktop') || $('body').hasClass('node-type-campaign-page')) {
        window.open(url, undefined, [windowOptions, "width=" + args.width, "height=" + args.height].join(", "));
      }
      return true;
    }
  });

  $.tpsocial.add_service({
    name: 'live',
    display: 'Messenger',
    width: 1020,
    height: 570,
    share: function (args) {
      var url = 'https://profile.live.com/P.mvc#!/badge?url=' + encodeURIComponent(args.url) + '&title=' + encodeURIComponent(args.title);
      var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
      $('.tp-social .tp-social-myaol').attr('href',url);
      //Desktop view will do a window.open, but Mobile view will do a new tab
      if($('.social-wrapper').hasClass('desktop') || $('body').hasClass('node-type-campaign-page')) {
        window.open(url, undefined, [windowOptions, "width=" + args.width, "height=" + args.height].join(", "));
      }
      return true;
    }
  });

  $.tpsocial.add_service({
    name: 'digg',
    display: 'Digg',
    width: 1070,
    height: 670,
    share: function (args) {
      var url = 'http://digg.com/submit?url=' + encodeURIComponent(args.url) + '&title=' + encodeURIComponent(args.title) + '&bodytext=';
      var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
      $('.tp-social .tp-social-digg').attr('href',url);
      //Desktop view will do a window.open, but Mobile view will do a new tab
      if($('.social-wrapper').hasClass('desktop') || $('body').hasClass('node-type-campaign-page')) {
        window.open(url, undefined, [windowOptions, "width=" + args.width, "height=" + args.height].join(", "));
      }
      return true;
    }
  });

  $.tpsocial.add_service({
    name: 'stumbleupon',
    display: 'Stumbleupon',
    width: 790,
    height: 560,
    share: function (args) {
      var url = 'http://www.stumbleupon.com/submit?url=' + encodeURIComponent(args.url) + '&title=' + encodeURIComponent(args.title);
      var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
      $('.tp-social .tp-social-stumbleupon').attr('href',url);
      //Desktop view will do a window.open, but Mobile view will do a new tab
      if($('.social-wrapper').hasClass('desktop') || $('body').hasClass('node-type-campaign-page')) {
        window.open(url, undefined, [windowOptions, "width=" + args.width, "height=" + args.height].join(", "));
      }
      return true;
    }
  });

  $.tpsocial.add_service({
    name: 'hyves',
    display: 'Hyves',
    width: 1030,
    height: 700,
    share: function (args) {
      var url = 'http://www.hyves.nl/profilemanage/add/tips/?name=' + encodeURIComponent(args.title) + '&text=' + encodeURIComponent(args.url) + '&type=12#';
      var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
      $('.tp-social .tp-social-hyves').attr('href',url);
      //Desktop view will do a window.open, but Mobile view will do a new tab
      if($('.social-wrapper').hasClass('desktop') || $('body').hasClass('node-type-campaign-page')) {
        window.open(url, undefined, [windowOptions, "width=" + args.width, "height=" + args.height].join(", "));
      }
      return true;
    }
  });

  $.tpsocial.add_service({
    name: 'mailto',
    display: 'Email App',
    share: function (args) {
      var longURL = window.location.href + '?cmpid=organic-share-mailto';
       get_share_url( longURL, args.title, function (shortenedUrl) {
         var url = 'mailto:?body=I%20thought%20you\'d%20like%20this%20story%20on%20TakePart.com%0D%0A%0D%0A' +
            encodeURIComponent(args.title) +
            encodeURIComponent(args.subhead) +
            '%0D%0A%0D%0A' +
             encodeURIComponent( shortenedUrl ) +
            '&subject=TakePart:%20' +
            encodeURIComponent(args.title);
         location.href = url;
       }, true);
    }
  });
})(window, jQuery);

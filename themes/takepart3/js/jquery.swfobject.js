(function($){
	var UNDEF = 'undefined',
		OBJECT = 'object',
		SHOCKWAVE_FLASH = 'Shockwave Flash',
		SHOCKWAVE_FLASH_AX = 'ShockwaveFlash.ShockwaveFlash',
		FLASH_MIME_TYPE = 'application/x-shockwave-flash';

	var scriptBase = $("script[src$='jquery.js']")[0];
	var flashObjects = [];

	var ua = (function() {
		var w3cdom = typeof document.getElementById !== UNDEF && typeof document.getElementsByTagName !== UNDEF && typeof document.createElement !== UNDEF,
			playerVersion = [0, 0, 0],
			d = null;

		if (typeof navigator.plugins !== UNDEF && typeof navigator.plugins[SHOCKWAVE_FLASH] === OBJECT) {
			d = navigator.plugins[SHOCKWAVE_FLASH].description;
			if (d && !(typeof navigator.mimeTypes !== UNDEF && navigator.mimeTypes[FLASH_MIME_TYPE] && !navigator.mimeTypes[FLASH_MIME_TYPE].enabledPlugin)) {
				d = d.replace(/^[\S|\s]*\s+(\S+\s+\S+$)/, '$1');
				playerVersion[0] = parseInt(d.replace(/^([\S|\s]*)\.[\S|\s]*$/, '$1'), 10);
				playerVersion[1] = parseInt(d.replace(/^[\S|\s]*\.([\S|\s]*)\s[\S|\s]*$/, '$1'), 10);
				playerVersion[2] = /r/.test(d) ? parseInt(d.replace(/^[\S|\s]*r([\S|\s]*)$/, '$1'), 10) : 0;
			}
		} else if (typeof window.ActiveXObject !== UNDEF) {
			var a = null, fp6Crash = false;
			try {
				a = new ActiveXObject(SHOCKWAVE_FLASH_AX + '.7');
			} catch (e) {
				try {
					a = new ActiveXObject(SHOCKWAVE_FLASH_AX + '.6');
					playerVersion = [6, 0, 21];
					a.AllowScriptAccess = 'always';	
				} catch (ee) {
					if (playerVersion[0] === 6) {
						fp6Crash = true;
					}
				}
				if (!fp6Crash) {
					try {
						a = new ActiveXObject(SHOCKWAVE_FLASH_AX);
					} catch (eee) {}
				}
			}
			if (!fp6Crash && a) {
				try {
					d = a.GetVariable('$version');
					if (d) {
						d = d.split(' ')[1].split(',');
						playerVersion = [parseInt(d[0], 10), parseInt(d[1], 10), parseInt(d[2], 10)];
					}
				} catch (eeee) {}
			}
		}

		var u = navigator.userAgent.toLowerCase(), p = navigator.platform.toLowerCase();
		return {
			w3cdom: w3cdom,
			pv: playerVersion,
			webkit: jQuery.browser.safari ? jQuery.browser.version : false,
			ie: jQuery.browser.msie,
			win: p ? /win/.test(p) : /win/.test(u),
			mac: p ? /mac/.test(p) : /mac/.test(u)
		};
	})();

	var hasPlayerVersion = function(rv) {
		var pv = ua.pv, v = rv.split(".");
		v[0] = parseInt(v[0], 10);
		v[1] = parseInt(v[1], 10) || 0;
		v[2] = parseInt(v[2], 10) || 0;
		return (pv[0] > v[0] || (pv[0] === v[0] && pv[1] > v[1]) || (pv[0] === v[0] && pv[1] === v[1] && pv[2] >= v[2])) ? true : false;
	};

	var createSWF = function(attObj, parObj) {
		if (ua.ie && ua.win) {
			var att = '';
			$.each(attObj, function(key, val) {
				var key = key.toLowerCase();
				if(typeof val !== UNDEF) {
					if (key === 'data') {
						parObj.movie = val;
					} else if (key === 'styleclass') {
						att += ' class="' + val + '"';
					} else if (key !== 'classid') {
						att += ' ' + key + '="' + val + '"';
					}
				}
			});

			var par = '';
			$.each(parObj, function(key, val) {
				if(typeof val !== UNDEF) {
					par += '<param name="' + key + '" value="' + val + '" />';
				}
			});

			var tag = $('<object classid="clsid:D27CDB6E-AE6D-11cf-96B8-444553540000"' + att + '>' + par + '</object>');
			flashObjects.push(tag[0]);
			return tag;
		} else if (ua.webkit && ua.webkit < 312) {
			var tag = $('<embed type="' + FLASH_MIME_TYPE + '" />');
			$.each(attObj, function(key, val) {
				if(typeof val !== UNDEF) {
					var key = key.toLowerCase();
					if (key === 'data') {
						tag.attr('src', val);
					} else if (key === 'styleclass') {
						tag.attr('class', val);
					} else if (key !== 'classid') {
						tag.attr(key, val);
					}
				}
			});
			$.each(parObj, function(key, val) {
				if(typeof val !== UNDEF && key.toLowerCase() !== 'movie') {
					tag.attr(key, val);
				}
			});
			return tag;
		} else {
			var tag = $('<object type="' + FLASH_MIME_TYPE + '" />');
			$.each(attObj, function(key, val) {
				if(typeof val !== UNDEF) {
					var key = key.toLowerCase();
					if (key === 'styleclass') {
						tag.attr('class', val);
					} else if (key !== 'classid') {
						tag.attr(key, val);
					}
				}
			});
			$.each(parObj, function(key, val) {
				if(typeof val !== UNDEF && key.toLowerCase() !== 'movie') {
					tag.append($('<param name="' + key + '" value="' + val + '" />'));
				}
			});
			return tag;
		}
	};

	var createExpressInstall = function(options) {
		var alt = options.alternative, tag;
		if($.expressInstallCallback) {
			return alt;
		}
		$.expressInstallCallback = function() {
			if(alt) {
				tag.replaceWith(alt);
			} else {
				tag.remove();
			}
			$.expressInstallCallback = null;
		};
		tag = createSWF({
			data: (typeof options.expressInstall == 'string') ? options.expressInstall : (scriptBase ? scriptBase.src.replace(/jquery.js/, "../images/") : "images") + "/expressInstall.swf",
			width: Math.max(parseInt(options.width), 214) || 214,
			height: Math.max(parseInt(options.height), 137) || 137
		}, {
			flashvars: "MMredirectURL=" + window.location + "&MMplayerType=" + (ua.ie && ua.win ? 'ActiveX' : 'PlugIn') + "&MMdoctitle=" + document.title
		});
		return tag;
	};

	$.flash = function(options) {
		var options = $.extend({
			version: "9.0.115",
			attributes: {},
			params: {allowfullscreen: 'true', allowscriptaccess: 'always', bgcolor: '#202020' , 'wmode': 'transparent'},
			flashvars: {},
			expressInstall: true,
			alternative: $("<div>Please update your Flash Player.</div>")
		}, options);

		if(hasPlayerVersion(options.version)) {
			var att = $.extend({
				width: options.width,
				height: options.height,
				data: options.swf
			}, options.attributes);

			var flashvars = "";
			if(options.flashvars) {
				// flashvars are no longer returned as key/value pairs,
				// they are now encoded via encodeURIComponent
				if(typeof options.flashvars == "string") {
					flashvars = decodeURIComponent(options.flashvars)
				} else {
					var fv = [];
					$.each(options.flashvars, function(key, val) {
						if(typeof val !== UNDEF) {
							fv.push(key + "=" + val);
						}
					});
					flashvars = fv.join("&");
				}
			}

			var par = $.extend({
				flashvars: flashvars
			}, options.params);

			return createSWF(att, par);
		} else if(options.expressInstall && hasPlayerVersion('6.0.65') && (ua.win || ua.mac)) {
			return createExpressInstall(options);
		} else {
			return options.alternative;
		}
	};

	$.fn.flash = function(options) {
		$(this).each(function() {
			var target = $(this);
			var tag_options = {};
			try {
				tag_options = eval("false||(function(){return " + target.attr("title") + ";})()") || {};
			} catch(e) {
			};
			var tag = $.flash($.extend({
				width: target.width(),
				height: target.height(),
				alternative: target
			}, tag_options, options));
			if(tag != target) {
				target.replaceWith(tag);
			}
		});
		return $(this);
	};

	// NOTE somehow, the original swfobject remove function object inside the HTMLElement
	// I didin't make sure it isn't meaninsless or not.
	if(ua.ie && ua.win) {
		var remove = $.fn.remove;
		$.fn.remove = function() {
			$(this).each(function() {
				var target = $(this);
				$.each(flashObjects, function(i, val) {
					var element = target[0];
					if(val == element) {
						for(var i in element) {
							if(typeof element[i] == "function") {
								element[i] = null;
							}
						}
						flashObjects[i] = null;
					}
				});
			});
			return remove.apply(this, arguments);
		};
		$(window).bind("unload", function() {
			$(flashObjects).each(function(i, val) {
				$(val).remove();
			});
		});
	}
})(jQuery);

(function(window, undefined) {

// Setup ----------------

if ( typeof takepart == 'undefined' ) {
    window.takepart = {};
    takepart = window.takepart;
}

//Analytics functions:
takepart.analytics = takepart.analytics || {};

// c = prop
// v = evar

// Named tracking

var events = {};

takepart.analytics.add = function(name, fn) {
	if ( typeof name == 'object' ) {
		for ( var key in name ) {
			if ( name.hasOwnProperty(key) ) {
				takepart.analytics.add(key, name[key]);
			}
		}
	} else {
		events[name] = fn;
	}
};

takepart.analytics.track = function(name, options) {
	if ( events[name] == undefined ) return;
	var e = events[name];
	e(options);
};

})(window);

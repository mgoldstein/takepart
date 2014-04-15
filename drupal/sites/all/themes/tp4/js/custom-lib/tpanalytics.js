// define the takepart global object
var takepart = takepart || {};

(function(window, takepart, undefined) {

//Analytics functions:
takepart.analytics = takepart.analytics || {};

//Analytics DTM direct call parameter:
takepart.analytics.parameters = takepart.analytics.parameters || {};


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
	return e(options);
};

})(this, this.takepart);

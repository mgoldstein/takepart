/**
 *  TP Intercept in namespace tp. Requires jQuery and jQuery.cookie
 */
tp = {}; 
 
/**
 *  Class Declared
 */
tp.tp_intercept = function(script, freq) {
  this.script = script;
  
  //ensures that the freq is not empty if so set to 1 day
  if (freq == '') {
    freq = 1;
  }
  
  this.freq = freq;
};

/**
 *  Class method for appending into the header
 */
tp.tp_intercept.prototype.insert = function(pos) {
  jQuery(pos).append(this.script);
};

/**
 *  Class method for setting the cookie
 */
tp.tp_intercept.prototype.set_cookie = function() {
  jQuery.cookie('tp_intercept_cookie', 'true', { expires: this.freq });
};

//anonymous function declared
(function() {
  //functions
  window.init_intercept = function() {
    //creates the variables
    var <?php print $variables['vars']; ?>;  
  
    //reads the cookie
    var tp_intercept_cookie = jQuery.cookie('tp_intercept_cookie');
    
    //if no cookie is set then go ahead and set a cookie
    if (tp_intercept_cookie == undefined) {
      var intercept = new tp.tp_intercept(tp_inter_script, tp_inter_freq);
      intercept.set_cookie();
      
      //insert into the head
      intercept.insert('head');
    }
  }
  
  init_intercept();
}());
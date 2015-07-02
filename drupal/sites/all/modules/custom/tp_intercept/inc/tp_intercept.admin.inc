<?php

/**
 *  Custom Admin form for controlling the intercept code
 */
function tp_intercept_admin_form() {
  $form = array();
  
  $form['tp_intercept_js_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Intercept Javascript Path'),
    '#description' => t('Enter a path such as api/intercept/intercept.js. If empty, it will be turned off.'),
    '#default_value' => variable_get('tp_intercept_js_path', 'api/intercept/intercept.js')
  );
  
  $form['tp_intercept_js'] = array(
    '#type' => 'textarea',
    '#title' => t('Intercept Javascript'),
    '#default_value' => variable_get('tp_intercept_js', '<script type="text/javascript">
(function(){var g=function(e,h,f,g){
this.get=function(a){for(var a=a+"=",c=document.cookie.split(";"),b=0,e=c.length;b<e;b++){for(var d=c[b];" "==d.charAt(0);)d=d.substring(1,d.length);if(0==d.indexOf(a))return d.substring(a.length,d.length)}return null};
this.set=function(a,c){var b="",b=new Date;b.setTime(b.getTime()+6048E5);b="; expires="+b.toGMTString();document.cookie=a+"="+c+b+"; path=/; "};
this.check=function(){var a=this.get(f);if(a)a=a.split(":");else if(100!=e)"v"==h&&(e=Math.random()>=e/100?0:100),a=[h,e,0],this.set(f,a.join(":"));else return!0;var c=a[1];if(100==c)return!0;switch(a[0]){case "v":return!1;case "r":return c=a[2]%Math.floor(100/c),a[2]++,this.set(f,a.join(":")),!c}return!0};
this.go=function(){if(this.check()){var a=document.createElement("script");a.type="text/javascript";a.src=g+ "&t=" + (new Date()).getTime();document.body&&document.body.appendChild(a)}};
this.start=function(){var a=this;window.addEventListener?window.addEventListener("load",function(){a.go()},!1):window.attachEvent&&window.attachEvent("onload",function(){a.go()})}};
try{(new g(100,"r","QSI_S_ZN_3TQACyOSd1g2V5H","//zn3tqacyosd1g2v5h-participantmedia.siteintercept.qualtrics.com/WRSiteInterceptEngine/?Q_ZID=ZN_3TQACyOSd1g2V5H&Q_LOC="+encodeURIComponent(window.location.href))).start()}catch(i){}})();
</script><div id="ZN_3TQACyOSd1g2V5H"><!--DO NOT REMOVE-CONTENTS PLACED HERE--></div>
<!--END SITE INTERCEPTÑ>')
  );
  
  $form['tp_intercept_freq'] = array(
    '#type' => 'select',
    '#title' => t('Frequency'),
    '#description' => t('Frequency for when the intercept javascript will be fired'),
    '#options' => array(
      1 => '1 Day',
      7 => '1 Week',
      30 => '1 Month (30 days)'
    ),
    '#default_value' => variable_get('tp_intercept_freq', 7)
  );
  
  $form['tp_intercept_cache_time'] = array(
    '#type' => 'select',
    '#title' => t('Cache Time'),
    '#description' => t('Cache the javascript for set period of time'),
    '#options' => array(
      60 => '1 Hour',
      120 => '2 Hour',
      360 => '6 Hour',
      1440 => '1 Day',
      10080 => '1 Week'
    ),
    '#default_value' => variable_get('tp_intercept_cache_time', 60)
  );
  
  return system_settings_form($form);
}
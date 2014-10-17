<?php

/**
 *  @function:
 *    This function is built for future use.
 */
function theme_tp_slim_nav_wrapper($elements) {

}

/**
 *  @function:
 *    This theme function is used to create the dynamic colors
 *
 *    @uses:
 *      This is used on the tp_custom_nav
 */
function theme_tp_slim_nav_colors($vars) {
  //dynamically create the keys
  foreach ($vars as $key => $value) {
    ${$key} = $value;
  }
  
  //dynamic css based on custom tax
  drupal_add_css(
    '
    body #tp-drawers .snap-drawer {
      background-color: #' . $mobile_bg_color . ';
    }
    
    body #tp-drawers .snap-drawer a {
      border-color: #' . $font_color . ';
    }
    
    .header-wrapper .tp-slim-nav .menu-toggle {
      border-color: #' . $font_color . ';
    }
    
    body #page-wrap .header-wrapper {
      background-color: #' . $bg_color . ';
    }
    
    #header,
    .header-wrapper,
    .header-wrapper .tp-slim-nav,
    .header-wrapper .tp-slim-nav a {
      background-color: #' . $bg_color . ';
      color: #' . $font_color . ';
    }
    
    .header-wrapper .mega-item.tp-hover,
    .header-wrapper .mega-item.tp-hover a,
    .header-wrapper .tpsLogin .tp_login.open {
      background-color: #' . $font_color .';
      color: #' . $bg_color . '
    }
    
    .header-wrapper .tp-slim-nav .mega-content,
    .header-wrapper .tp-slim-nav .mega-content a {
      background-color: #' . $font_color .';
      color: #' . $bg_color . '
    }
    ',
    array(
      'weight' => 20,
      'type' => 'inline'
    )
  );
}
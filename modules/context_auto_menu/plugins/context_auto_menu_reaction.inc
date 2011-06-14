<?php

/**
 * Expose menu items as context reactions.
 */
class context_auto_menu_reaction extends context_reaction {
  /**
   * Provide a form element that allow the admin to chose a menu item.
   */
  function options_form($context) {
    if (module_exists('menu')) {

      $menus = menu_get_menus();
      dpm($menus);
      $menus['context_auto_menu'] = "*Context Specific*";
      dpm($context);
      dpm($this);
      $form = array();
      $form['context_menu'] = array(
        '#title' => 'Context Menu',
        '#type' => 'select',
        '#options' => $menus,
        '#default_value' => $context->reactions['auto_menu']['context_menu'],
      );
      return $form;
    }
  }

  /**
   * Override of options_form_submit().
   * Trim any identifier padding for non-unique path menu items.
   */
  function options_form_submit($values) {
//    return trim($values, "'");
    dpm($values);
    return $values;
  }

  /**
   * If primary + secondary links are pointed at the same menu, provide
   * contextual trailing by default.
   */
  function execute(&$vars = NULL) {
  }

  function get_menu($context) {
    
  }

  /**
   * Iterates through a provided links array for use with theme_links()
   * (e.g. from menu_primary_links()) and provides an active class for
   * any items that have a path that matches an active context.
   *
   * @param $links
   *   An array of links.
   * @param $reset
   *   A boolean flag for resetting the static cache.
   *
   * @return
   *   A modified links array.
   */
  function menu_set_active($links = array(), $reset = FALSE) {
  /*
    $new_links = array();
    if (!empty($links)) {
      $active_paths = $this->get_active_paths();

      // Iterate through the provided links and build a new set of links
      // that includes active classes
      foreach ($links as $key => $link) {
        if (!empty($link['href']) && in_array($link['href'], $active_paths)) {
          $link['attributes']['class'][] = 'active';

          if (strpos(' active', $key) === FALSE) {
            $new_links[$key . ' active'] = $link;
          }
        }
        else {
          $new_links[$key] = $link;
        }
      }
    }
    return $new_links;
    */
  }

  /**
   * Wrapper around menu_navigation_links() that gives themers the option of
   * building navigation links based on an active context trail.
   */
  function menu_navigation_links($menu_name, $level = 0) {
  /*
    // Retrieve original path so we can repair it after our hack.
    $original_path = $_GET['q'];

    // Retrieve the first active menu path found.
    if ($active_paths = $this->get_active_paths()) {
      $path = current($active_paths);
      if (menu_get_item($path)) {
        menu_set_active_item($path);
      }
    }

    // Build the links requested
    $links = menu_navigation_links($menu_name, $level);

    // Repair and get out
    menu_set_active_item($original_path);
    return $links;
    */
  }
}

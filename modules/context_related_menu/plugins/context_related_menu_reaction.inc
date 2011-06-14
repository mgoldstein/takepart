<?php

/**
 * Expose menu items as context reactions.
 */
class context_related_menu_reaction extends context_reaction {
  /**
   * Provide a form element that allow the admin to chose a menu item.
   */
  function options_form($context) {
    if (module_exists('menu')) {

      $menus = menu_get_menus();
      $menus['context_related_menu'] = "*Context Specific*";
      $form = array();
      $form['context_menu'] = array(
        '#title' => 'Context Menu',
        '#type' => 'select',
        '#options' => $menus,
        '#default_value' => $context->reactions['related_menu']['context_menu'],
      );
      return $form;
    }
  }

  /**
   * Override of options_form_submit().
   */
  function options_form_submit($values) {
    return $values;
  }

  /**
   * Override of execute()
   *
   * we return the menu that is currently active
   * NOTE: this looks at all contexts that are active
   */
  function execute(&$vars = NULL) {
    $active_contexts = context_active_contexts();
    foreach($active_contexts as $context) {
      if(isset($context->reactions['related_menu']['context_menu'])) {
        $menu = $context->reactions['related_menu']['context_menu'];
        $menu = $menu == 'context_related_menu' ? $context->name : $menu;
        if (!menu_load($menu)) {
          $title = $context->description ? $context->description : $menu;
          $menu_object = array("menu_name" => $menu, "title"=> $title, "description" => "");
          menu_save($menu_object);
        }
        return $menu;
      }
    }
  }
}

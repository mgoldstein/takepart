<?php
/**
 * Define theme templates.
 */
function theme_on_our_radar_link(&$variables) {
  return "<li><h4>" . $variables['topic'] . "</h4>" .  l($variables['title'], $variables['link'], array('attributes' => array('class' => array('radar-links')))) . "</li>";
}

<?php
/**
 * @file
 * tpf_display_menus.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function tpf_display_menus_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-corporate-footer_participant-media:http://www.participantmedia.com.
  $menu_links['menu-corporate-footer_participant-media:http://www.participantmedia.com'] = array(
    'menu_name' => 'menu-corporate-footer',
    'link_path' => 'http://www.participantmedia.com',
    'router_path' => '',
    'link_title' => 'Participant Media',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'logos-participantmedia',
        ),
        'target' => '_blank',
      ),
      'identifier' => 'menu-corporate-footer_participant-media:http://www.participantmedia.com',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-corporate-footer_pivot:http://www.pivot.tv.
  $menu_links['menu-corporate-footer_pivot:http://www.pivot.tv'] = array(
    'menu_name' => 'menu-corporate-footer',
    'link_path' => 'http://www.pivot.tv',
    'router_path' => '',
    'link_title' => 'Pivot',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'logos-pivot',
        ),
        'target' => '_blank',
      ),
      'identifier' => 'menu-corporate-footer_pivot:http://www.pivot.tv',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-corporate-footer_takepart:http://www.takepart.com.
  $menu_links['menu-corporate-footer_takepart:http://www.takepart.com'] = array(
    'menu_name' => 'menu-corporate-footer',
    'link_path' => 'http://www.takepart.com',
    'router_path' => '',
    'link_title' => 'TakePart',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'logos-takepart',
        ),
        'target' => '_blank',
      ),
      'identifier' => 'menu-corporate-footer_takepart:http://www.takepart.com',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-megamenu_aid--development:taxonomy/term/115553.
  $menu_links['menu-megamenu_aid--development:taxonomy/term/115553'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/115553',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Aid & Development',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_aid--development:taxonomy/term/115553',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_social-justice:taxonomy/term/99103',
  );
  // Exported menu link: menu-megamenu_animals:taxonomy/term/496.
  $menu_links['menu-megamenu_animals:taxonomy/term/496'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/496',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Animals',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_animals:taxonomy/term/496',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_food:taxonomy/term/11',
  );
  // Exported menu link: menu-megamenu_big-issues:node/64607.
  $menu_links['menu-megamenu_big-issues:node/64607'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'node/64607',
    'router_path' => 'node/%',
    'link_title' => 'Big Issues',
    'options' => array(
      'identifier' => 'menu-megamenu_big-issues:node/64607',
      'attributes' => array(
        'name' => 'See all News',
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-megamenu_business:taxonomy/term/117590.
  $menu_links['menu-megamenu_business:taxonomy/term/117590'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/117590',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Business',
    'options' => array(
      'identifier' => 'menu-megamenu_business:taxonomy/term/117590',
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: menu-megamenu_climate-change:taxonomy/term/198.
  $menu_links['menu-megamenu_climate-change:taxonomy/term/198'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/198',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Climate Change',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_climate-change:taxonomy/term/198',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_environment:taxonomy/term/8',
  );
  // Exported menu link: menu-megamenu_cooking:taxonomy/term/4568.
  $menu_links['menu-megamenu_cooking:taxonomy/term/4568'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/4568',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Cooking',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_cooking:taxonomy/term/4568',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_food:taxonomy/term/11',
  );
  // Exported menu link: menu-megamenu_culture:taxonomy/term/108747.
  $menu_links['menu-megamenu_culture:taxonomy/term/108747'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/108747',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Culture',
    'options' => array(
      'identifier' => 'menu-megamenu_culture:taxonomy/term/108747',
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: menu-megamenu_entertainment:taxonomy/term/5838.
  $menu_links['menu-megamenu_entertainment:taxonomy/term/5838'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/5838',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Entertainment',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_entertainment:taxonomy/term/5838',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_culture:taxonomy/term/108747',
  );
  // Exported menu link: menu-megamenu_entrepreneurs:taxonomy/term/116620.
  $menu_links['menu-megamenu_entrepreneurs:taxonomy/term/116620'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/116620',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Entrepreneurs',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-megamenu_entrepreneurs:taxonomy/term/116620',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_business:taxonomy/term/117590',
  );
  // Exported menu link: menu-megamenu_environment:taxonomy/term/8.
  $menu_links['menu-megamenu_environment:taxonomy/term/8'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/8',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Environment',
    'options' => array(
      'identifier' => 'menu-megamenu_environment:taxonomy/term/8',
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-megamenu_farming:taxonomy/term/386.
  $menu_links['menu-megamenu_farming:taxonomy/term/386'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/386',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Farming',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_farming:taxonomy/term/386',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_food:taxonomy/term/11',
  );
  // Exported menu link: menu-megamenu_featured-actions:http://takeaction.takepart.com/?browse=featured&filtered=true&sort=recent.
  $menu_links['menu-megamenu_featured-actions:http://takeaction.takepart.com/?browse=featured&filtered=true&sort=recent'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'http://takeaction.takepart.com/?browse=featured&filtered=true&sort=recent',
    'router_path' => '',
    'link_title' => 'Featured Actions',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_featured-actions:http://takeaction.takepart.com/?browse=featured&filtered=true&sort=recent',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_take-action:node/41544',
  );
  // Exported menu link: menu-megamenu_film--tv-actions:http://takeaction.takepart.com/?browse=pivot&filtered=true&tags=&sort=recent.
  $menu_links['menu-megamenu_film--tv-actions:http://takeaction.takepart.com/?browse=pivot&filtered=true&tags=&sort=recent'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'http://takeaction.takepart.com/?browse=pivot&filtered=true&tags=&sort=recent',
    'router_path' => '',
    'link_title' => 'Film & TV Actions',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_film--tv-actions:http://takeaction.takepart.com/?browse=pivot&filtered=true&tags=&sort=recent',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_take-action:node/41544',
  );
  // Exported menu link: menu-megamenu_food:taxonomy/term/11.
  $menu_links['menu-megamenu_food:taxonomy/term/11'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/11',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Food',
    'options' => array(
      'identifier' => 'menu-megamenu_food:taxonomy/term/11',
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-megamenu_global-health:taxonomy/term/116036.
  $menu_links['menu-megamenu_global-health:taxonomy/term/116036'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/116036',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Global Health',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_global-health:taxonomy/term/116036',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_social-justice:taxonomy/term/99103',
  );
  // Exported menu link: menu-megamenu_green:taxonomy/term/14.
  $menu_links['menu-megamenu_green:taxonomy/term/14'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/14',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Green',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_green:taxonomy/term/14',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_business:taxonomy/term/117590',
  );
  // Exported menu link: menu-megamenu_health:taxonomy/term/15.
  $menu_links['menu-megamenu_health:taxonomy/term/15'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/15',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Health',
    'options' => array(
      'identifier' => 'menu-megamenu_health:taxonomy/term/15',
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_culture:taxonomy/term/108747',
  );
  // Exported menu link: menu-megamenu_innovation--tech:taxonomy/term/6.
  $menu_links['menu-megamenu_innovation--tech:taxonomy/term/6'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/6',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Innovation & Tech',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_innovation--tech:taxonomy/term/6',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_business:taxonomy/term/117590',
  );
  // Exported menu link: menu-megamenu_innovation:taxonomy/term/115730.
  $menu_links['menu-megamenu_innovation:taxonomy/term/115730'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/115730',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Innovation',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_innovation:taxonomy/term/115730',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_social-justice:taxonomy/term/99103',
  );
  // Exported menu link: menu-megamenu_insights:node/57281.
  $menu_links['menu-megamenu_insights:node/57281'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'node/57281',
    'router_path' => 'node/%',
    'link_title' => 'Insights',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-megamenu_insights:node/57281',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_business:taxonomy/term/117590',
  );
  // Exported menu link: menu-megamenu_jane-says:http://www.takepart.com/series/jane-says.
  $menu_links['menu-megamenu_jane-says:http://www.takepart.com/series/jane-says'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'http://www.takepart.com/series/jane-says',
    'router_path' => '',
    'link_title' => 'Jane Says',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_jane-says:http://www.takepart.com/series/jane-says',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_food:taxonomy/term/11',
  );
  // Exported menu link: menu-megamenu_lifestyle:taxonomy/term/18.
  $menu_links['menu-megamenu_lifestyle:taxonomy/term/18'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/18',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Lifestyle',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-megamenu_lifestyle:taxonomy/term/18',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_culture:taxonomy/term/108747',
  );
  // Exported menu link: menu-megamenu_oceans:taxonomy/term/312.
  $menu_links['menu-megamenu_oceans:taxonomy/term/312'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/312',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Oceans',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_oceans:taxonomy/term/312',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_environment:taxonomy/term/8',
  );
  // Exported menu link: menu-megamenu_petitions:http://takeaction.takepart.com/?filtered=true&sort=recent&types=Petition.
  $menu_links['menu-megamenu_petitions:http://takeaction.takepart.com/?filtered=true&sort=recent&types=Petition'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'http://takeaction.takepart.com/?filtered=true&sort=recent&types=Petition',
    'router_path' => '',
    'link_title' => 'Petitions',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_petitions:http://takeaction.takepart.com/?filtered=true&sort=recent&types=Petition',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_take-action:node/41544',
  );
  // Exported menu link: menu-megamenu_pledges:http://takeaction.takepart.com/?types=Pledge&filtered=true&sort=recent.
  $menu_links['menu-megamenu_pledges:http://takeaction.takepart.com/?types=Pledge&filtered=true&sort=recent'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'http://takeaction.takepart.com/?types=Pledge&filtered=true&sort=recent',
    'router_path' => '',
    'link_title' => 'Pledges',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_pledges:http://takeaction.takepart.com/?types=Pledge&filtered=true&sort=recent',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_take-action:node/41544',
  );
  // Exported menu link: menu-megamenu_restaurants:taxonomy/term/3887.
  $menu_links['menu-megamenu_restaurants:taxonomy/term/3887'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/3887',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Restaurants',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-megamenu_restaurants:taxonomy/term/3887',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_business:taxonomy/term/117590',
  );
  // Exported menu link: menu-megamenu_restaurants:taxonomy/term/43.
  $menu_links['menu-megamenu_restaurants:taxonomy/term/43'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/43',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Restaurants',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_restaurants:taxonomy/term/43',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_food:taxonomy/term/11',
  );
  // Exported menu link: menu-megamenu_social-justice:taxonomy/term/99103.
  $menu_links['menu-megamenu_social-justice:taxonomy/term/99103'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/99103',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Social Justice',
    'options' => array(
      'identifier' => 'menu-megamenu_social-justice:taxonomy/term/99103',
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-megamenu_take-action:node/41544.
  $menu_links['menu-megamenu_take-action:node/41544'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'node/41544',
    'router_path' => 'node/%',
    'link_title' => 'Take Action',
    'options' => array(
      'attributes' => array(
        'id' => 'action',
        'name' => 'See all Actions',
        'class' => array(
          0 => 'takeaction-logo',
          1 => 'menu-node-unpublished',
        ),
      ),
      'identifier' => 'menu-megamenu_take-action:node/41544',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -44,
    'customized' => 1,
  );
  // Exported menu link: menu-megamenu_track-your-impact:http://takeaction.takepart.com/dashboard.
  $menu_links['menu-megamenu_track-your-impact:http://takeaction.takepart.com/dashboard'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'http://takeaction.takepart.com/dashboard',
    'router_path' => '',
    'link_title' => 'Track Your Impact',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_track-your-impact:http://takeaction.takepart.com/dashboard',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_take-action:node/41544',
  );
  // Exported menu link: menu-megamenu_wildlife:taxonomy/term/4.
  $menu_links['menu-megamenu_wildlife:taxonomy/term/4'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/4',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Wildlife',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_wildlife:taxonomy/term/4',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_environment:taxonomy/term/8',
  );
  // Exported menu link: menu-social-footer-follow_email:http://www.takepart.com/follow-us-email.
  $menu_links['menu-social-footer-follow_email:http://www.takepart.com/follow-us-email'] = array(
    'menu_name' => 'menu-social-footer-follow',
    'link_path' => 'http://www.takepart.com/follow-us-email',
    'router_path' => '',
    'link_title' => 'Email',
    'options' => array(
      'identifier' => 'menu-social-footer-follow_email:http://www.takepart.com/follow-us-email',
      'attributes' => array(
        'class' => array(
          0 => 'social-email-black',
        ),
        'target' => '_blank',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-social-footer-follow_facebook:https://www.facebook.com/takepart.
  $menu_links['menu-social-footer-follow_facebook:https://www.facebook.com/takepart'] = array(
    'menu_name' => 'menu-social-footer-follow',
    'link_path' => 'https://www.facebook.com/takepart',
    'router_path' => '',
    'link_title' => 'Facebook',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'social-facebook-black',
        ),
        'target' => '_blank',
      ),
      'identifier' => 'menu-social-footer-follow_facebook:https://www.facebook.com/takepart',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-social-footer-follow_google-plus:https://plus.google.com/+TakePart.
  $menu_links['menu-social-footer-follow_google-plus:https://plus.google.com/+TakePart'] = array(
    'menu_name' => 'menu-social-footer-follow',
    'link_path' => 'https://plus.google.com/+TakePart',
    'router_path' => '',
    'link_title' => 'Google Plus',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'social-googleplus-black',
        ),
        'target' => '_blank',
      ),
      'identifier' => 'menu-social-footer-follow_google-plus:https://plus.google.com/+TakePart',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-social-footer-follow_pinterest:http://pinterest.com/takepart.
  $menu_links['menu-social-footer-follow_pinterest:http://pinterest.com/takepart'] = array(
    'menu_name' => 'menu-social-footer-follow',
    'link_path' => 'http://pinterest.com/takepart',
    'router_path' => '',
    'link_title' => 'Pinterest',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'social-pinterest-black',
        ),
        'target' => '_blank',
      ),
      'identifier' => 'menu-social-footer-follow_pinterest:http://pinterest.com/takepart',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: menu-social-footer-follow_tumblr:http://takepart.tumblr.com.
  $menu_links['menu-social-footer-follow_tumblr:http://takepart.tumblr.com'] = array(
    'menu_name' => 'menu-social-footer-follow',
    'link_path' => 'http://takepart.tumblr.com',
    'router_path' => '',
    'link_title' => 'Tumblr',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'social-tumblr-black',
        ),
        'target' => '_blank',
      ),
      'identifier' => 'menu-social-footer-follow_tumblr:http://takepart.tumblr.com',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: menu-social-footer-follow_twitter:https://twitter.com/takepart.
  $menu_links['menu-social-footer-follow_twitter:https://twitter.com/takepart'] = array(
    'menu_name' => 'menu-social-footer-follow',
    'link_path' => 'https://twitter.com/takepart',
    'router_path' => '',
    'link_title' => 'Twitter',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'social-twitter-black',
        ),
        'target' => '_blank',
      ),
      'identifier' => 'menu-social-footer-follow_twitter:https://twitter.com/takepart',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-social-footer-follow_youtube:http://youtube.com/takepart.
  $menu_links['menu-social-footer-follow_youtube:http://youtube.com/takepart'] = array(
    'menu_name' => 'menu-social-footer-follow',
    'link_path' => 'http://youtube.com/takepart',
    'router_path' => '',
    'link_title' => 'YouTube',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'social-youtube-black',
        ),
        'target' => '_blank',
      ),
      'identifier' => 'menu-social-footer-follow_youtube:http://youtube.com/takepart',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
  );
  // Exported menu link: menu-social-header-follow_email:http://www.takepart.com/follow-us-email.
  $menu_links['menu-social-header-follow_email:http://www.takepart.com/follow-us-email'] = array(
    'menu_name' => 'menu-social-header-follow',
    'link_path' => 'http://www.takepart.com/follow-us-email',
    'router_path' => '',
    'link_title' => 'Email',
    'options' => array(
      'identifier' => 'menu-social-header-follow_email:http://www.takepart.com/follow-us-email',
      'attributes' => array(
        'class' => array(
          0 => 'social-email-gray',
        ),
        'target' => '_blank',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-social-header-follow_facebook:https://www.facebook.com/takepart.
  $menu_links['menu-social-header-follow_facebook:https://www.facebook.com/takepart'] = array(
    'menu_name' => 'menu-social-header-follow',
    'link_path' => 'https://www.facebook.com/takepart',
    'router_path' => '',
    'link_title' => 'Facebook',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'social-facebook-gray',
        ),
        'target' => '_blank',
      ),
      'identifier' => 'menu-social-header-follow_facebook:https://www.facebook.com/takepart',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-social-header-follow_google-plus:https://plus.google.com/+TakePart.
  $menu_links['menu-social-header-follow_google-plus:https://plus.google.com/+TakePart'] = array(
    'menu_name' => 'menu-social-header-follow',
    'link_path' => 'https://plus.google.com/+TakePart',
    'router_path' => '',
    'link_title' => 'Google Plus',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'social-googleplus-gray',
        ),
        'target' => '_blank',
      ),
      'identifier' => 'menu-social-header-follow_google-plus:https://plus.google.com/+TakePart',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-social-header-follow_twitter:https://twitter.com/takepart.
  $menu_links['menu-social-header-follow_twitter:https://twitter.com/takepart'] = array(
    'menu_name' => 'menu-social-header-follow',
    'link_path' => 'https://twitter.com/takepart',
    'router_path' => '',
    'link_title' => 'Twitter',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'social-twitter-gray',
        ),
        'target' => '_blank',
      ),
      'identifier' => 'menu-social-header-follow_twitter:https://twitter.com/takepart',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-takepart-links_about-us:node/246.
  $menu_links['menu-takepart-links_about-us:node/246'] = array(
    'menu_name' => 'menu-takepart-links',
    'link_path' => 'node/246',
    'router_path' => 'node/%',
    'link_title' => 'About Us',
    'options' => array(
      'attributes' => array(
        'target' => '_top',
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-takepart-links_about-us:node/246',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-takepart-links_contact-us:node/41550.
  $menu_links['menu-takepart-links_contact-us:node/41550'] = array(
    'menu_name' => 'menu-takepart-links',
    'link_path' => 'node/41550',
    'router_path' => 'node/%',
    'link_title' => 'Contact Us',
    'options' => array(
      'attributes' => array(
        'target' => '_top',
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-takepart-links_contact-us:node/41550',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-takepart-links_faq:node/238.
  $menu_links['menu-takepart-links_faq:node/238'] = array(
    'menu_name' => 'menu-takepart-links',
    'link_path' => 'node/238',
    'router_path' => 'node/%',
    'link_title' => 'FAQ',
    'options' => array(
      'attributes' => array(
        'target' => '_top',
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-takepart-links_faq:node/238',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-takepart-links_interest-based-ads:node/36861.
  $menu_links['menu-takepart-links_interest-based-ads:node/36861'] = array(
    'menu_name' => 'menu-takepart-links',
    'link_path' => 'node/36861',
    'router_path' => 'node/%',
    'link_title' => 'Interest-Based Ads',
    'options' => array(
      'fragment' => 'ads',
      'attributes' => array(
        'target' => '_top',
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-takepart-links_interest-based-ads:node/36861',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
  );
  // Exported menu link: menu-takepart-links_privacy-policy:node/36861.
  $menu_links['menu-takepart-links_privacy-policy:node/36861'] = array(
    'menu_name' => 'menu-takepart-links',
    'link_path' => 'node/36861',
    'router_path' => 'node/%',
    'link_title' => 'Privacy Policy',
    'options' => array(
      'attributes' => array(
        'target' => '_top',
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-takepart-links_privacy-policy:node/36861',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
  );
  // Exported menu link: menu-takepart-links_rss:node/19814.
  $menu_links['menu-takepart-links_rss:node/19814'] = array(
    'menu_name' => 'menu-takepart-links',
    'link_path' => 'node/19814',
    'router_path' => 'node/%',
    'link_title' => 'RSS',
    'options' => array(
      'attributes' => array(
        'title' => 'RSS',
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-takepart-links_rss:node/19814',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: menu-takepart-links_social-action-network:node/45749.
  $menu_links['menu-takepart-links_social-action-network:node/45749'] = array(
    'menu_name' => 'menu-takepart-links',
    'link_path' => 'node/45749',
    'router_path' => 'node/%',
    'link_title' => 'Social Action Network',
    'options' => array(
      'attributes' => array(
        'target' => '_top',
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-takepart-links_social-action-network:node/45749',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: menu-takepart-links_terms-of-service:node/36965.
  $menu_links['menu-takepart-links_terms-of-service:node/36965'] = array(
    'menu_name' => 'menu-takepart-links',
    'link_path' => 'node/36965',
    'router_path' => 'node/%',
    'link_title' => 'Terms of Service',
    'options' => array(
      'attributes' => array(
        'target' => '_top',
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-takepart-links_terms-of-service:node/36965',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('About Us');
  t('Aid & Development');
  t('Animals');
  t('Big Issues');
  t('Business');
  t('Climate Change');
  t('Contact Us');
  t('Cooking');
  t('Culture');
  t('Email');
  t('Entertainment');
  t('Entrepreneurs');
  t('Environment');
  t('FAQ');
  t('Facebook');
  t('Farming');
  t('Featured Actions');
  t('Film & TV Actions');
  t('Food');
  t('Global Health');
  t('Google Plus');
  t('Green');
  t('Health');
  t('Innovation');
  t('Innovation & Tech');
  t('Insights');
  t('Interest-Based Ads');
  t('Jane Says');
  t('Lifestyle');
  t('Oceans');
  t('Participant Media');
  t('Petitions');
  t('Pinterest');
  t('Pivot');
  t('Pledges');
  t('Privacy Policy');
  t('RSS');
  t('Restaurants');
  t('Social Action Network');
  t('Social Justice');
  t('Take Action');
  t('TakePart');
  t('Terms of Service');
  t('Track Your Impact');
  t('Tumblr');
  t('Twitter');
  t('Wildlife');
  t('YouTube');

  return $menu_links;
}

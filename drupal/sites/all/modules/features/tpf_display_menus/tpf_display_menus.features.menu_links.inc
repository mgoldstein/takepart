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

  // Exported menu link: menu-corporate-footer_participant-media:http://www.participantmedia.com
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
  // Exported menu link: menu-corporate-footer_pivot:http://www.pivot.tv
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
  // Exported menu link: menu-corporate-footer_takepart:http://www.takepart.com
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
  // Exported menu link: menu-megamenu_aid--development:taxonomy/term/115553
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
    'parent_identifier' => 'menu-megamenu_world:taxonomy/term/24',
  );
  // Exported menu link: menu-megamenu_animals:taxonomy/term/496
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
  // Exported menu link: menu-megamenu_as-green-as-i-get:http://www.takepart.com/series/as-green-as-i-get
  $menu_links['menu-megamenu_as-green-as-i-get:http://www.takepart.com/series/as-green-as-i-get'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'http://www.takepart.com/series/as-green-as-i-get',
    'router_path' => '',
    'link_title' => 'As Green as I Get',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_as-green-as-i-get:http://www.takepart.com/series/as-green-as-i-get',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_environment:taxonomy/term/8',
  );
  // Exported menu link: menu-megamenu_business:taxonomy/term/117590
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
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: menu-megamenu_climate-change:taxonomy/term/198
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
  // Exported menu link: menu-megamenu_cooking:taxonomy/term/4568
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
  // Exported menu link: menu-megamenu_culture:taxonomy/term/108747
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
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-megamenu_daily-fix:taxonomy/term/115274
  $menu_links['menu-megamenu_daily-fix:taxonomy/term/115274'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/115274',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Daily Fix',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_daily-fix:taxonomy/term/115274',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_news:taxonomy/term/19',
  );
  // Exported menu link: menu-megamenu_education:taxonomy/term/7
  $menu_links['menu-megamenu_education:taxonomy/term/7'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/7',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Education',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_education:taxonomy/term/7',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_news:taxonomy/term/19',
  );
  // Exported menu link: menu-megamenu_entertainment:taxonomy/term/5838
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
  // Exported menu link: menu-megamenu_environment:taxonomy/term/8
  $menu_links['menu-megamenu_environment:taxonomy/term/8'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/8',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Environment',
    'options' => array(
      'identifier' => 'menu-megamenu_environment:taxonomy/term/8',
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-megamenu_farming:taxonomy/term/386
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
  // Exported menu link: menu-megamenu_fashion:taxonomy/term/9
  $menu_links['menu-megamenu_fashion:taxonomy/term/9'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/9',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Fashion',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_fashion:taxonomy/term/9',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_culture:taxonomy/term/108747',
  );
  // Exported menu link: menu-megamenu_featured-actions:http://takeaction.takepart.com/?browse=featured&filtered=true&sort=recent
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
  // Exported menu link: menu-megamenu_film--tv-actions:http://takeaction.takepart.com/?browse=pivot&filtered=true&tags=&sort=recent
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
  // Exported menu link: menu-megamenu_food-policy:taxonomy/term/32711
  $menu_links['menu-megamenu_food-policy:taxonomy/term/32711'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/32711',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Food Policy',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_food-policy:taxonomy/term/32711',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_food:taxonomy/term/11',
  );
  // Exported menu link: menu-megamenu_food:taxonomy/term/11
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
  // Exported menu link: menu-megamenu_green:taxonomy/term/14
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
  // Exported menu link: menu-megamenu_home:taxonomy/term/114840
  $menu_links['menu-megamenu_home:taxonomy/term/114840'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/114840',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Home',
    'options' => array(
      'identifier' => 'menu-megamenu_home:taxonomy/term/114840',
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_culture:taxonomy/term/108747',
  );
  // Exported menu link: menu-megamenu_human-rights:taxonomy/term/16
  $menu_links['menu-megamenu_human-rights:taxonomy/term/16'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/16',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Human Rights',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_human-rights:taxonomy/term/16',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_news:taxonomy/term/19',
  );
  // Exported menu link: menu-megamenu_innovation--tech:taxonomy/term/6
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
  // Exported menu link: menu-megamenu_innovation:taxonomy/term/115730
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
    'parent_identifier' => 'menu-megamenu_world:taxonomy/term/24',
  );
  // Exported menu link: menu-megamenu_jane-says:http://www.takepart.com/series/jane-says
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
  // Exported menu link: menu-megamenu_lgbt-rights:taxonomy/term/12
  $menu_links['menu-megamenu_lgbt-rights:taxonomy/term/12'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/12',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'LGBT Rights',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_lgbt-rights:taxonomy/term/12',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_news:taxonomy/term/19',
  );
  // Exported menu link: menu-megamenu_lifestyle:taxonomy/term/18
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
  // Exported menu link: menu-megamenu_meatless-mondays:http://www.takepart.com/series/meatless-mondays
  $menu_links['menu-megamenu_meatless-mondays:http://www.takepart.com/series/meatless-mondays'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'http://www.takepart.com/series/meatless-mondays',
    'router_path' => '',
    'link_title' => 'Meatless Mondays',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_meatless-mondays:http://www.takepart.com/series/meatless-mondays',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_food:taxonomy/term/11',
  );
  // Exported menu link: menu-megamenu_news:taxonomy/term/19
  $menu_links['menu-megamenu_news:taxonomy/term/19'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/19',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'News',
    'options' => array(
      'attributes' => array(
        'name' => 'See all News',
      ),
      'identifier' => 'menu-megamenu_news:taxonomy/term/19',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-megamenu_oceans:taxonomy/term/312
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
  // Exported menu link: menu-megamenu_petitions:http://takeaction.takepart.com/?filtered=true&sort=recent&types=Petition
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
  // Exported menu link: menu-megamenu_pledges:http://takeaction.takepart.com/?types=Pledge&filtered=true&sort=recent
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
  // Exported menu link: menu-megamenu_poaching:taxonomy/term/31331
  $menu_links['menu-megamenu_poaching:taxonomy/term/31331'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/31331',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Poaching',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_poaching:taxonomy/term/31331',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_environment:taxonomy/term/8',
  );
  // Exported menu link: menu-megamenu_politics:taxonomy/term/20
  $menu_links['menu-megamenu_politics:taxonomy/term/20'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/20',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Politics',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_politics:taxonomy/term/20',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_news:taxonomy/term/19',
  );
  // Exported menu link: menu-megamenu_restaurants:taxonomy/term/43
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
  // Exported menu link: menu-megamenu_social-justice:taxonomy/term/99103
  $menu_links['menu-megamenu_social-justice:taxonomy/term/99103'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/99103',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Social Justice',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_social-justice:taxonomy/term/99103',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_news:taxonomy/term/19',
  );
  // Exported menu link: menu-megamenu_strange-behaviors:http://www.takepart.com/series/strange-behaviors
  $menu_links['menu-megamenu_strange-behaviors:http://www.takepart.com/series/strange-behaviors'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'http://www.takepart.com/series/strange-behaviors',
    'router_path' => '',
    'link_title' => 'Strange Behaviors',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_strange-behaviors:http://www.takepart.com/series/strange-behaviors',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_environment:taxonomy/term/8',
  );
  // Exported menu link: menu-megamenu_take-action:node/41544
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
  // Exported menu link: menu-megamenu_track-your-impact:http://takeaction.takepart.com/dashboard
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
  // Exported menu link: menu-megamenu_wildlife:taxonomy/term/4
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
  // Exported menu link: menu-megamenu_world:taxonomy/term/24
  $menu_links['menu-megamenu_world:taxonomy/term/24'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/24',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'World',
    'options' => array(
      'identifier' => 'menu-megamenu_world:taxonomy/term/24',
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
  // Exported menu link: menu-social-footer-follow_email:http://go.takepart.com/clients/takepart/survey.htm
  $menu_links['menu-social-footer-follow_email:http://go.takepart.com/clients/takepart/survey.htm'] = array(
    'menu_name' => 'menu-social-footer-follow',
    'link_path' => 'http://go.takepart.com/clients/takepart/survey.htm',
    'router_path' => '',
    'link_title' => 'Email',
    'options' => array(
      'identifier' => 'menu-social-footer-follow_email:http://go.takepart.com/clients/takepart/survey.htm',
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
  // Exported menu link: menu-social-footer-follow_facebook:https://www.facebook.com/takepart
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
  // Exported menu link: menu-social-footer-follow_google-plus:https://plus.google.com/+TakePart
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
  // Exported menu link: menu-social-footer-follow_pinterest:http://pinterest.com/takepart
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
  // Exported menu link: menu-social-footer-follow_tumblr:http://takepart.tumblr.com
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
  // Exported menu link: menu-social-footer-follow_twitter:https://twitter.com/takepart
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
  // Exported menu link: menu-social-footer-follow_youtube:http://youtube.com/takepart
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
  // Exported menu link: menu-social-header-follow_email:http://go.takepart.com/clients/takepart/survey.htm
  $menu_links['menu-social-header-follow_email:http://go.takepart.com/clients/takepart/survey.htm'] = array(
    'menu_name' => 'menu-social-header-follow',
    'link_path' => 'http://go.takepart.com/clients/takepart/survey.htm',
    'router_path' => '',
    'link_title' => 'Email',
    'options' => array(
      'identifier' => 'menu-social-header-follow_email:http://go.takepart.com/clients/takepart/survey.htm',
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
  // Exported menu link: menu-social-header-follow_facebook:https://www.facebook.com/takepart
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
  // Exported menu link: menu-social-header-follow_google-plus:https://plus.google.com/+TakePart
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
  // Exported menu link: menu-social-header-follow_twitter:https://twitter.com/takepart
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
  // Translatables
  // Included for use with string extractors like potx.
  t('Aid & Development');
  t('Animals');
  t('As Green as I Get');
  t('Business');
  t('Climate Change');
  t('Cooking');
  t('Culture');
  t('Daily Fix');
  t('Education');
  t('Email');
  t('Entertainment');
  t('Environment');
  t('Facebook');
  t('Farming');
  t('Fashion');
  t('Featured Actions');
  t('Film & TV Actions');
  t('Food');
  t('Food Policy');
  t('Google Plus');
  t('Green');
  t('Home');
  t('Human Rights');
  t('Innovation');
  t('Innovation & Tech');
  t('Jane Says');
  t('LGBT Rights');
  t('Lifestyle');
  t('Meatless Mondays');
  t('News');
  t('Oceans');
  t('Participant Media');
  t('Petitions');
  t('Pinterest');
  t('Pivot');
  t('Pledges');
  t('Poaching');
  t('Politics');
  t('Restaurants');
  t('Social Justice');
  t('Strange Behaviors');
  t('Take Action');
  t('TakePart');
  t('Track Your Impact');
  t('Tumblr');
  t('Twitter');
  t('Wildlife');
  t('World');
  t('YouTube');


  return $menu_links;
}

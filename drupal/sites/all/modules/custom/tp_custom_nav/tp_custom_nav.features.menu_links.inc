<?php
/**
 * @file
 * tp_custom_nav.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function tp_custom_nav_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-megamenu_a-place-at-the-table:wordlet/patt_home
  $menu_links['menu-megamenu_a-place-at-the-table:wordlet/patt_home'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'wordlet/patt_home',
    'router_path' => 'wordlet/%',
    'link_title' => 'A Place at the Table',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_a-place-at-the-table:wordlet/patt_home',
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
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_environment:taxonomy/term/8',
  );
  // Exported menu link: menu-megamenu_culture:taxonomy/term/108747
  $menu_links['menu-megamenu_culture:taxonomy/term/108747'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/108747',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Culture',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_culture:taxonomy/term/108747',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
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
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_news:taxonomy/term/19',
  );
  // Exported menu link: menu-megamenu_environment:taxonomy/term/8
  $menu_links['menu-megamenu_environment:taxonomy/term/8'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/8',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Environment',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_environment:taxonomy/term/8',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-megamenu_fair-trade:taxonomy/term/258
  $menu_links['menu-megamenu_fair-trade:taxonomy/term/258'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/258',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Fair Trade',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_fair-trade:taxonomy/term/258',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_world:taxonomy/term/24',
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
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
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
  // Exported menu link: menu-megamenu_food-inc-campaign:node/21246
  $menu_links['menu-megamenu_food-inc-campaign:node/21246'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'node/21246',
    'router_path' => 'node/%',
    'link_title' => 'Food, Inc. campaign',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_food-inc-campaign:node/21246',
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
  // Exported menu link: menu-megamenu_food:taxonomy/term/11
  $menu_links['menu-megamenu_food:taxonomy/term/11'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/11',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Food',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_food:taxonomy/term/11',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-megamenu_global-development:taxonomy/term/99767
  $menu_links['menu-megamenu_global-development:taxonomy/term/99767'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/99767',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Global Development',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_global-development:taxonomy/term/99767',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_world:taxonomy/term/24',
  );
  // Exported menu link: menu-megamenu_health--beauty:taxonomy/term/15
  $menu_links['menu-megamenu_health--beauty:taxonomy/term/15'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/15',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Health & Beauty',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_health--beauty:taxonomy/term/15',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_culture:taxonomy/term/108747',
  );
  // Exported menu link: menu-megamenu_home--garden:taxonomy/term/114840
  $menu_links['menu-megamenu_home--garden:taxonomy/term/114840'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/114840',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Home & Garden',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_home--garden:taxonomy/term/114840',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_culture:taxonomy/term/108747',
  );
  // Exported menu link: menu-megamenu_hunger:taxonomy/term/3253
  $menu_links['menu-megamenu_hunger:taxonomy/term/3253'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/3253',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Hunger',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-megamenu_hunger:taxonomy/term/3253',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_food:taxonomy/term/11',
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
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_news:taxonomy/term/19',
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
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_food:taxonomy/term/11',
  );
  // Exported menu link: menu-megamenu_lifestyle:taxonomy/term/18
  $menu_links['menu-megamenu_lifestyle:taxonomy/term/18'] = array(
    'menu_name' => 'menu-megamenu',
    'link_path' => 'taxonomy/term/18',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Lifestyle',
    'options' => array(
      'attributes' => array(
        'name' => 'See all Lifestyle',
      ),
      'identifier' => 'menu-megamenu_lifestyle:taxonomy/term/18',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -47,
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
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
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
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'menu-megamenu_news:taxonomy/term/19',
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
    'weight' => -45,
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
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
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
      'attributes' => array(),
      'identifier' => 'menu-megamenu_world:taxonomy/term/24',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('A Place at the Table');
  t('As Green as I Get');
  t('Culture');
  t('Education');
  t('Environment');
  t('Fair Trade');
  t('Fashion');
  t('Featured Actions');
  t('Film & TV Actions');
  t('Food');
  t('Food, Inc. campaign');
  t('Global Development');
  t('Health & Beauty');
  t('Home & Garden');
  t('Hunger');
  t('Innovation & Tech');
  t('Jane Says');
  t('Lifestyle');
  t('Meatless Mondays');
  t('News');
  t('Petitions');
  t('Pledges');
  t('Politics');
  t('Social Justice');
  t('Strange Behaviors');
  t('Take Action');
  t('Track Your Impact');
  t('Wildlife');
  t('World');


  return $menu_links;
}

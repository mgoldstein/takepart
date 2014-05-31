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
    'weight' => 0,
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
    'weight' => 0,
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
    'weight' => 0,
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
  t('Email');
  t('Facebook');
  t('Google Plus');
  t('Participant Media');
  t('Pinterest');
  t('Pivot');
  t('TakePart');
  t('Tumblr');
  t('Twitter');
  t('YouTube');


  return $menu_links;
}

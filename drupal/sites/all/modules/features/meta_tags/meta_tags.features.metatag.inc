<?php
/**
 * @file
 * meta_tags.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function meta_tags_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: global.
  $config['global'] = array(
    'instance' => 'global',
    'config' => array(
      'title' => array(
        'value' => '[current-page:title] | [site:name]',
      ),
      'description' => array(
        'value' => '',
      ),
      'abstract' => array(
        'value' => '',
      ),
      'keywords' => array(
        'value' => '',
      ),
      'robots' => array(
        'value' => array(
          'index' => 0,
          'follow' => 0,
          'noindex' => 0,
          'nofollow' => 0,
          'noarchive' => 0,
          'nosnippet' => 0,
          'noodp' => 0,
          'noydir' => 0,
        ),
      ),
      'news_keywords' => array(
        'value' => '',
      ),
      'generator' => array(
        'value' => '',
      ),
      'copyright' => array(
        'value' => 'TakePart is the Social Action Network™ of Participant Media. © 2008-2012 TakePart, LLC',
      ),
      'image_src' => array(
        'value' => '',
      ),
      'canonical' => array(
        'value' => '[current-page:url]',
      ),
      'shortlink' => array(
        'value' => '',
      ),
      'publisher' => array(
        'value' => 'https://plus.google.com/102129351800746591723',
      ),
      'author' => array(
        'value' => '',
      ),
      'original-source' => array(
        'value' => '',
      ),
      'fb:admins' => array(
        'value' => '',
      ),
      'fb:app_id' => array(
        'value' => '',
      ),
      'og:site_name' => array(
        'value' => '[site:name]',
      ),
      'og:title' => array(
        'value' => '[current-page:title]',
      ),
      'og:description' => array(
        'value' => '',
      ),
      'og:type' => array(
        'value' => 'website',
      ),
      'og:image' => array(
        'value' => '',
      ),
      'og:url' => array(
        'value' => '[current-page:url]',
      ),
      'og:latitude' => array(
        'value' => '',
      ),
      'og:longitude' => array(
        'value' => '',
      ),
      'og:street-address' => array(
        'value' => '',
      ),
      'og:locality' => array(
        'value' => '',
      ),
      'og:region' => array(
        'value' => '',
      ),
      'og:postal-code' => array(
        'value' => '',
      ),
      'og:country-name' => array(
        'value' => '',
      ),
      'og:email' => array(
        'value' => '',
      ),
      'og:phone_number' => array(
        'value' => '',
      ),
      'og:fax_number' => array(
        'value' => '',
      ),
      'og:video' => array(
        'value' => '',
      ),
      'og:video:secure_url' => array(
        'value' => '',
      ),
      'og:video:width' => array(
        'value' => '',
      ),
      'og:video:height' => array(
        'value' => '',
      ),
      'og:video:type' => array(
        'value' => '',
      ),
    ),
  );

  // Exported Metatag config instance: global:frontpage.
  $config['global:frontpage'] = array(
    'instance' => 'global:frontpage',
    'config' => array(
      'title' => array(
        'value' => '[site:name]',
      ),
      'canonical' => array(
        'value' => '[site:url]',
      ),
      'og:title' => array(
        'value' => '[site:name]',
      ),
      'og:url' => array(
        'value' => 'http://www.takepart.com',
      ),
    ),
  );

  // Exported Metatag config instance: node.
  $config['node'] = array(
    'instance' => 'node',
    'config' => array(
      'title' => array(
        'value' => '[node:title] | [site:name]',
      ),
      'description' => array(
        'value' => '[node:summary]',
      ),
      'copyright' => array(
        'value' => 'TakePart is the Social Action Network™ of Participant Media. © 2008-2013 TakePart, LLC',
      ),
      'og:title' => array(
        'value' => '[node:title]',
      ),
      'og:description' => array(
        'value' => '[node:summary]',
      ),
      'og:type' => array(
        'value' => 'article',
      ),
      'og:image' => array(
        'value' => '[tp_og_image:thumbnail:{node:nid}]',
      ),
    ),
  );

  // Exported Metatag config instance: node:action.
  $config['node:action'] = array(
    'instance' => 'node:action',
    'config' => array(
      'robots' => array(
        'value' => array(
          'noindex' => 'noindex',
          'nofollow' => 0,
          'noarchive' => 0,
          'nosnippet' => 0,
          'noodp' => 0,
        ),
      ),
    ),
  );

  // Exported Metatag config instance: node:article.
  $config['node:article'] = array(
    'instance' => 'node:article',
    'config' => array(
      'og:image' => array(
        'value' => '[tp_og_image:article_main_image:{node:nid}]',
      ),
    ),
  );

  // Exported Metatag config instance: node:takepart_list.
  $config['node:takepart_list'] = array(
    'instance' => 'node:takepart_list',
    'config' => array(
      'robots' => array(
        'value' => array(
          'noindex' => 'noindex',
          'nofollow' => 0,
          'noarchive' => 0,
          'nosnippet' => 0,
          'noodp' => 0,
        ),
      ),
    ),
  );

  // Exported Metatag config instance: node:takepart_slide.
  $config['node:takepart_slide'] = array(
    'instance' => 'node:takepart_slide',
    'config' => array(
      'robots' => array(
        'value' => array(
          'noindex' => 'noindex',
          'nofollow' => 0,
          'noarchive' => 0,
          'nosnippet' => 0,
          'noodp' => 0,
        ),
      ),
    ),
  );

  // Exported Metatag config instance: taxonomy_term.
  $config['taxonomy_term'] = array(
    'instance' => 'taxonomy_term',
    'config' => array(
      'description' => array(
        'value' => '[term:description]',
      ),
      'title' => array(
        'value' => '[term:name] | [site:name]',
      ),
      'og:title' => array(
        'value' => '[term:name]',
      ),
      'og:description' => array(
        'value' => '[term:description]',
      ),
    ),
  );

  // Exported Metatag config instance: taxonomy_term:free_tags.
  $config['taxonomy_term:free_tags'] = array(
    'instance' => 'taxonomy_term:free_tags',
    'config' => array(
      'robots' => array(
        'value' => array(
          'noindex' => 'noindex',
          'nofollow' => 0,
          'noarchive' => 0,
          'nosnippet' => 0,
          'noodp' => 0,
        ),
      ),
    ),
  );

  // Exported Metatag config instance: user.
  $config['user'] = array(
    'instance' => 'user',
    'config' => array(
      'title' => array(
        'value' => '[user:name] | [site:name]',
      ),
      'og:type' => array(
        'value' => 'profile',
      ),
      'og:title' => array(
        'value' => '[user:name]',
      ),
      'og:image' => array(
        'value' => '[user:picture:url]',
      ),
    ),
  );

  return $config;
}

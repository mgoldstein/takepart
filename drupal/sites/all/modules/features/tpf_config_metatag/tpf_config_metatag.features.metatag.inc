<?php
/**
 * @file
 * tpf_config_metatag.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function tpf_config_metatag_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: global.
  $config['global'] = array(
    'instance' => 'global',
    'config' => array(
      'title' => array(
        'value' => '[current-page:title]',
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
          'noimageindex' => 0,
          'notranslate' => 0,
        ),
      ),
      'news_keywords' => array(
        'value' => '',
      ),
      'standout' => array(
        'value' => '',
      ),
      'generator' => array(
        'value' => '',
      ),
      'rights' => array(
        'value' => 'TakePart is the Social Action Network™ of Participant Media. © 2008-2013 TakePart, LLC',
      ),
      'image_src' => array(
        'value' => '',
      ),
      'canonical' => array(
        'value' => '',
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
      'revisit-after' => array(
        'value' => '',
        'period' => '',
      ),
      'content-language' => array(
        'value' => '',
      ),
      'fb:admins' => array(
        'value' => 1327833247,
      ),
      'fb:app_id' => array(
        'value' => '247137505296280',
      ),
      'og:site_name' => array(
        'value' => '[site:name]',
      ),
      'og:type' => array(
        'value' => 'website',
      ),
      'og:url' => array(
        'value' => '[current-page:url]',
      ),
      'og:title' => array(
        'value' => '[current-page:title]',
      ),
      'og:determiner' => array(
        'value' => '',
      ),
      'og:description' => array(
        'value' => '',
      ),
      'og:updated_time' => array(
        'value' => '',
      ),
      'og:see_also' => array(
        'value' => '',
      ),
      'og:image' => array(
        'value' => '',
      ),
      'og:image:secure_url' => array(
        'value' => '',
      ),
      'og:image:type' => array(
        'value' => '',
      ),
      'og:image:width' => array(
        'value' => '',
      ),
      'og:image:height' => array(
        'value' => '',
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
      'og:locale' => array(
        'value' => '',
      ),
      'og:locale:alternate' => array(
        'value' => '',
      ),
      'article:author' => array(
        'value' => '',
      ),
      'article:publisher' => array(
        'value' => '',
      ),
      'article:section' => array(
        'value' => '',
      ),
      'article:tag' => array(
        'value' => '',
      ),
      'article:published_time' => array(
        'value' => '',
      ),
      'article:modified_time' => array(
        'value' => '',
      ),
      'article:expiration_time' => array(
        'value' => '',
      ),
      'profile:first_name' => array(
        'value' => '',
      ),
      'profile:last_name' => array(
        'value' => '',
      ),
      'profile:username' => array(
        'value' => '',
      ),
      'profile:gender' => array(
        'value' => '',
      ),
      'og:audio' => array(
        'value' => '',
      ),
      'og:audio:secure_url' => array(
        'value' => '',
      ),
      'og:audio:type' => array(
        'value' => '',
      ),
      'book:author' => array(
        'value' => '',
      ),
      'book:isbn' => array(
        'value' => '',
      ),
      'book:release_date' => array(
        'value' => '',
      ),
      'book:tag' => array(
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
      'video:actor' => array(
        'value' => '',
      ),
      'video:actor:role' => array(
        'value' => '',
      ),
      'video:director' => array(
        'value' => '',
      ),
      'video:writer' => array(
        'value' => '',
      ),
      'video:duration' => array(
        'value' => '',
      ),
      'video:release_date' => array(
        'value' => '',
      ),
      'video:tag' => array(
        'value' => '',
      ),
      'video:series' => array(
        'value' => '',
      ),
      'twitter:card' => array(
        'value' => 'summary',
      ),
      'twitter:site' => array(
        'value' => '@TakePart',
      ),
      'twitter:site:id' => array(
        'value' => '',
      ),
      'twitter:creator' => array(
        'value' => '',
      ),
      'twitter:creator:id' => array(
        'value' => '',
      ),
      'twitter:url' => array(
        'value' => '[current-page:url]',
      ),
      'twitter:title' => array(
        'value' => '[current-page:title]',
      ),
      'twitter:description' => array(
        'value' => '',
      ),
      'twitter:image:src' => array(
        'value' => '',
      ),
      'twitter:image:width' => array(
        'value' => '',
      ),
      'twitter:image:height' => array(
        'value' => '',
      ),
      'twitter:image0' => array(
        'value' => '',
      ),
      'twitter:image1' => array(
        'value' => '',
      ),
      'twitter:image2' => array(
        'value' => '',
      ),
      'twitter:image3' => array(
        'value' => '',
      ),
      'twitter:player' => array(
        'value' => '',
      ),
      'twitter:player:width' => array(
        'value' => '',
      ),
      'twitter:player:height' => array(
        'value' => '',
      ),
      'twitter:player:stream' => array(
        'value' => '',
      ),
      'twitter:player:stream:content_type' => array(
        'value' => '',
      ),
      'twitter:app:country' => array(
        'value' => '',
      ),
      'twitter:app:name:iphone' => array(
        'value' => '',
      ),
      'twitter:app:id:iphone' => array(
        'value' => '',
      ),
      'twitter:app:url:iphone' => array(
        'value' => '',
      ),
      'twitter:app:name:ipad' => array(
        'value' => '',
      ),
      'twitter:app:id:ipad' => array(
        'value' => '',
      ),
      'twitter:app:url:ipad' => array(
        'value' => '',
      ),
      'twitter:app:name:googleplay' => array(
        'value' => '',
      ),
      'twitter:app:id:googleplay' => array(
        'value' => '',
      ),
      'twitter:app:url:googleplay' => array(
        'value' => '',
      ),
      'twitter:label1' => array(
        'value' => '',
      ),
      'twitter:data1' => array(
        'value' => '',
      ),
      'twitter:label2' => array(
        'value' => '',
      ),
      'twitter:data2' => array(
        'value' => '',
      ),
      'tab-keywords' => array(
        'value' => '',
      ),
      'tp:node_id' => array(
        'value' => '',
      ),
      'tp:content_title' => array(
        'value' => '',
      ),
      'tp:content_type' => array(
        'value' => '',
      ),
      'tp:content_authors' => array(
        'value' => '',
      ),
      'tp:published_date' => array(
        'value' => '',
      ),
      'tp:campaign' => array(
        'value' => '',
      ),
      'tp:series' => array(
        'value' => '',
      ),
      'tp:topic' => array(
        'value' => '',
      ),
    ),
  );

  // Exported Metatag config instance: global:403.
  $config['global:403'] = array(
    'instance' => 'global:403',
    'config' => array(
      'canonical' => array(
        'value' => '[site:url]',
      ),
      'shortlink' => array(
        'value' => '[site:url]',
      ),
      'og:title' => array(
        'value' => '[site:name]',
      ),
      'og:type' => array(
        'value' => 'website',
      ),
      'og:url' => array(
        'value' => '[site:url]',
      ),
      'twitter:title' => array(
        'value' => '[site:name]',
      ),
      'twitter:url' => array(
        'value' => '[site:url]',
      ),
    ),
  );

  // Exported Metatag config instance: global:404.
  $config['global:404'] = array(
    'instance' => 'global:404',
    'config' => array(
      'canonical' => array(
        'value' => '[site:url]',
      ),
      'shortlink' => array(
        'value' => '[site:url]',
      ),
      'og:title' => array(
        'value' => '[site:name]',
      ),
      'og:type' => array(
        'value' => 'website',
      ),
      'og:url' => array(
        'value' => '[site:url]',
      ),
      'twitter:title' => array(
        'value' => '[site:name]',
      ),
      'twitter:url' => array(
        'value' => '[site:url]',
      ),
    ),
  );

  // Exported Metatag config instance: global:frontpage.
  $config['global:frontpage'] = array(
    'instance' => 'global:frontpage',
    'config' => array(
      'title' => array(
        'value' => '[site:name] | [site:slogan]',
      ),
      'description' => array(
        'value' => 'Stories That Matter, Actions That Count.',
      ),
      'rights' => array(
        'value' => 'TakePart is the Social Action Network™ of Participant Media. © 2008-2014 TakePart, LLC',
      ),
      'canonical' => array(
        'value' => '[site:url]',
      ),
      'publisher' => array(
        'value' => 'https://plus.google.com/113369936500827860065/',
      ),
      'og:url' => array(
        'value' => 'http://www.takepart.com',
      ),
      'og:title' => array(
        'value' => '[site:name]',
      ),
      'og:description' => array(
        'value' => 'Stories That Matter, Actions That Count.',
      ),
      'og:image' => array(
        'value' => 'http://www.takepart.com/sites/default/files/takepart_logo_color.jpg',
      ),
      'og:image:secure_url' => array(
        'value' => 'https://www.takepart.com/sites/default/files/takepart_logo_color.jpg',
      ),
      'twitter:site:id' => array(
        'value' => 13451802,
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
        'value' => '[node:field_page_subhead]',
      ),
      'abstract' => array(
        'value' => '[node:field_page_subhead]',
      ),
      'keywords' => array(
        'value' => '[node:field_topic]',
      ),
      'rights' => array(
        'value' => 'TakePart is the Social Action Network™ of Participant Media. © 2008-[current-date:custom:Y] TakePart, LLC',
      ),
      'canonical' => array(
        'value' => '[current-page:url]',
      ),
      'og:type' => array(
        'value' => 'article',
      ),
      'og:title' => array(
        'value' => '[node:title][f:bool:{node:field_sponsored}: (Promoted):] ',
      ),
      'og:description' => array(
        'value' => '[node:field_page_subhead]',
      ),
      'og:image' => array(
        'value' => '[tp_og_image:thumbnail:{node:nid}]',
      ),
      'twitter:creator' => array(
        'value' => '@TakePart',
      ),
      'twitter:title' => array(
        'value' => '[current-page:title][f:bool:{node:field_sponsored}: (Promoted):] ',
      ),
      'tab-keywords' => array(
        'value' => '[tab_metatags:topic_freetags:{node:field_topic}, {node:field_free_tag}]',
      ),
    ),
  );

  // Exported Metatag config instance: node:feature_article.
  $config['node:feature_article'] = array(
    'instance' => 'node:feature_article',
    'config' => array(
      'og:title' => array(
        'value' => '[node:title][f:bool:{node:field_sponsored}: (Promoted):] ',
      ),
      'og:description' => array(
        'value' => '[node:field_article_subhead]',
      ),
      'twitter:title' => array(
        'value' => '[current-page:title][f:bool:{node:field_sponsored}: (Promoted):] ',
      ),
      'twitter:description' => array(
        'value' => '[node:field_article_subhead]',
      ),
      'twitter:image:src' => array(
        'value' => '[tp_og_image:thumbnail:{node:nid}]',
      ),
    ),
  );

  // Exported Metatag config instance: node:openpublish_article.
  $config['node:openpublish_article'] = array(
    'instance' => 'node:openpublish_article',
    'config' => array(
      'description' => array(
        'value' => '[f:bool:{node:field_article_subhead}:{node:field_article_subhead}:{node:body}]',
      ),
      'abstract' => array(
        'value' => '[f:bool:{node:field_article_subhead}:{node:field_article_subhead}:{node:body}]',
      ),
      'canonical' => array(
        'value' => '[tp_auto_scroll:clean_url:{node:nid}]',
      ),
      'og:url' => array(
        'value' => '[tp_auto_scroll:clean_url:{node:nid}]',
      ),
      'og:description' => array(
        'value' => '[node:field_article_subhead]',
      ),
      'og:image:width' => array(
        'value' => '[tp_og_image:thumbnail_width:{node:nid}] ',
      ),
      'og:image:height' => array(
        'value' => '[tp_og_image:thumbnail_height:{node:nid}]',
      ),
      'twitter:url' => array(
        'value' => '[tp_auto_scroll:clean_url:{node:nid}]',
      ),
      'twitter:title' => array(
        'value' => '[node:title][f:bool:{node:field_sponsored}: (Promoted):] ',
      ),
      'twitter:description' => array(
        'value' => '[node:field_article_subhead]',
      ),
      'twitter:image:src' => array(
        'value' => '[tp_og_image:thumbnail:{node:nid}]',
      ),
    ),
  );

  // Exported Metatag config instance: node:openpublish_photo_gallery.
  $config['node:openpublish_photo_gallery'] = array(
    'instance' => 'node:openpublish_photo_gallery',
    'config' => array(
      'description' => array(
        'value' => '[node:field_subhead]',
      ),
      'abstract' => array(
        'value' => '[node:field_subhead]',
      ),
      'fb:admins' => array(
        'value' => 1327833247,
      ),
      'og:title' => array(
        'value' => '[node:title][f:bool:{node:field_sponsored}: (Promoted):]',
      ),
      'og:description' => array(
        'value' => '[node:field_subhead]',
      ),
      'twitter:title' => array(
        'value' => '[current-page:title][f:bool:{node:field_sponsored}: (Promoted):]',
      ),
    ),
  );

  // Exported Metatag config instance: taxonomy_term.
  $config['taxonomy_term'] = array(
    'instance' => 'taxonomy_term',
    'config' => array(
      'title' => array(
        'value' => '[term:name] | [site:name]',
      ),
      'description' => array(
        'value' => '[term:description]',
      ),
      'og:title' => array(
        'value' => '[term:name]',
      ),
      'og:description' => array(
        'value' => '[term:description]',
      ),
      'og:url' => array(
        'value' => '[current-page:url]',
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
      'og:title' => array(
        'value' => '[user:name]',
      ),
      'og:type' => array(
        'value' => 'profile',
      ),
      'profile:username' => array(
        'value' => '[user:name]',
      ),
      'og:image' => array(
        'value' => '[user:picture:url]',
      ),
      'twitter:title' => array(
        'value' => '[user:name]',
      ),
      'twitter:image:src' => array(
        'value' => '[user:picture:url]',
      ),
      'tab-keywords' => array(),
    ),
  );

  return $config;
}

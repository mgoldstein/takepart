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
        ),
      ),
      'news_keywords' => array(
        'value' => '',
      ),
      'generator' => array(
        'value' => '',
      ),
      'copyright' => array(
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
      'fb:admins' => array(
        'value' => '792568495, 1327833247, 13304443, 658568746, 100003533144273',
      ),
      'fb:app_id' => array(
        'value' => '247137505296280',
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
      'twitter:image' => array(
        'value' => '',
      ),
      'twitter:image:width' => array(
        'value' => '',
      ),
      'twitter:image:height' => array(
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
      'tab-keywords' => array(
        'value' => '',
      ),
    ),
  );

  // Exported Metatag config instance: global:403.
  $config['global:403'] = array(
    'instance' => 'global:403',
    'disabled' => FALSE,
    'config' => array(
      'canonical' => array(
        'value' => '[site:url]',
      ),
      'shortlink' => array(
        'value' => '[site:url]',
      ),
      'og:type' => array(
        'value' => 'website',
      ),
      'og:title' => array(
        'value' => '[site:name]',
      ),
      'og:url' => array(
        'value' => '[site:url]',
      ),
      'twitter:description' => array(
        'value' => '',
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
    'disabled' => FALSE,
    'config' => array(
      'canonical' => array(
        'value' => '[site:url]',
      ),
      'shortlink' => array(
        'value' => '[site:url]',
      ),
      'og:type' => array(
        'value' => 'website',
      ),
      'og:title' => array(
        'value' => '[site:name]',
      ),
      'og:url' => array(
        'value' => '[site:url]',
      ),
      'twitter:description' => array(
        'value' => '',
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
      'canonical' => array(
        'value' => '[site:url]',
      ),
      'publisher' => array(
        'value' => 'https://plus.google.com/113369936500827860065/',
      ),
      'og:title' => array(
        'value' => '[site:name]',
      ),
      'og:image' => array(
        'value' => 'http://takepart.com/sites/all/themes/tp4/images/takepart_logo.png',
      ),
      'og:url' => array(
        'value' => 'http://www.takepart.com',
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
      'copyright' => array(
        'value' => 'TakePart is the Social Action Network™ of Participant Media. © 2008-[current-date:custom:Y] TakePart, LLC',
      ),
      'canonical' => array(
        'value' => '[current-page:url]',
      ),
      'og:title' => array(
        'value' => '[node:title]',
      ),
      'og:description' => array(
        'value' => '[node:field_page_subhead]',
      ),
      'og:type' => array(
        'value' => 'article',
      ),
      'og:image' => array(
        'value' => '[tp_og_image:thumbnail:{node:nid}]',
      ),
      'tab-keywords' => array(
        'value' => '[tab_metatags:topic_freetags:{node:field_topic}, {node:field_free_tag}]',
      ),
    ),
  );

  // Exported Metatag config instance: node:campaign_card_ad.
  $config['node:campaign_card_ad'] = array(
    'instance' => 'node:campaign_card_ad',
    'config' => array(
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
      'dtm:page-title' => array(
        'value' => 'This is a dtm page title',
      ),
      'dtm:section' => array(
        'value' => 'This is a dtm section',
      ),
      'dtm:subsection' => array(
        'value' => 'This is a dtm subsection',
      ),
      'dtm:content-type' => array(
        'value' => 'This is a dtm content type',
      ),
      'dtm:node-id' => array(
        'value' => 'This is a dtm node id',
      ),
      'dtm:url' => array(
        'value' => 'This is a dtm node id',
      ),
      'dtm:publish-date' => array(
        'value' => 'This is a dtm node id',
      ),
      'dtm:topic' => array(
        'value' => 'This is a dtm node id',
      ),
      'dtm:campaign-name' => array(
        'value' => 'This is a dtm node id',
      ),
    ),
  );

  // Exported Metatag config instance: node:feature_article.
  $config['node:feature_article'] = array(
    'instance' => 'node:feature_article',
    'config' => array(
      'og:url' => array(
        'value' => '[current-page:url]',
      ),
      'twitter:description' => array(
        'value' => '[node:field_article_subhead]',
      ),
      'twitter:image' => array(
        'value' => '[tp_og_image:thumbnail:{node:nid}]',
      ),
    ),
  );

  // Exported Metatag config instance: node:openpublish_article.
  $config['node:openpublish_article'] = array(
    'instance' => 'node:openpublish_article',
    'config' => array(
      'description' => array(
        'value' => '[node:field_article_subhead]',
      ),
      'abstract' => array(
        'value' => '[node:field_article_subhead]',
      ),
      'og:description' => array(
        'value' => '[node:field_article_subhead]',
      ),
      'og:url' => array(
        'value' => '[current-page:url]',
      ),
      'twitter:title' => array(
        'value' => '[node:title]',
      ),
      'twitter:description' => array(
        'value' => '[node:field_article_subhead]',
      ),
      'twitter:image' => array(
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
      'og:description' => array(
        'value' => '[node:field_subhead]',
      ),
      'og:url' => array(
        'value' => '[current-page:url]',
      ),
    ),
  );

  // Exported Metatag config instance: node:takepart_campaign.
  $config['node:takepart_campaign'] = array(
    'instance' => 'node:takepart_campaign',
    'config' => array(
      'description' => array(
        'value' => '[node:field_tp_campaign_subheadline]',
      ),
      'abstract' => array(
        'value' => '[node:field_tp_campaign_subheadline]',
      ),
      'og:description' => array(
        'value' => '[node:field_tp_campaign_subheadline]',
      ),
      'og:url' => array(
        'value' => '[current-page:url]',
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

  // Exported Metatag config instance: user.
  $config['user'] = array(
    'instance' => 'user',
    'disabled' => FALSE,
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
      'tab-keywords' => array(),
    ),
  );

  return $config;
}

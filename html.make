api = 2
core = 7.0
projects[drupal][type] = core
projects[drupal][patch][] = http://drupal.org/files/issues/object_conversion_menu_router_build-972536-1.patch
projects[drupal][patch][] = http://drupal.org/files/issues/fix_autocompletion_with_slashes-93854-99-make.patch
projects[drupal][patch][] = https://raw.github.com/phase2/taxonomy_field_autocomplete_multi_voc_widget/master/use_double_colon_to_show_voc_on_term_fields.patch
projects[drupal][version] = 7.7

projects[field_group][subdir] = contrib
projects[field_group][type] = module
projects[field_group][download][type] = git
projects[field_group][download][url] = http://git.drupal.org/project/field_group.git
projects[field_group][download][revision] = 45f20b653535c9fc32bdf3899ab953b4ae195f4f

projects[references][subdir] = contrib
projects[references][type] = module
projects[references][download][type] = git
projects[references][download][url] = http://git.drupal.org/project/references.git
projects[references][download][revision] = 8e1e57bea4f6c7915e5b8be8690a3e28590cca2d

projects[context][subdir] = contrib
projects[context][type] = module
projects[context][version] = 3.0-beta1

projects[ctools][subdir] = contrib
projects[ctools][type] = module
projects[ctools][version] = 1.0-rc1

projects[date][subdir] = contrib
projects[date][type] = module
projects[date][version] = 2.0-alpha3

projects[diff][subdir] = contrib
projects[diff][version] = 2.0

projects[entity][subdir] = contrib
projects[entity][version] = 1.0-beta10

projects[features][subdir] = contrib
projects[features][version] = 1.0-beta4

projects[pathauto][subdir] = contrib
projects[pathauto][version] = 1.0-rc2

projects[strongarm][subdir] = contrib
projects[strongarm][version] = 2.0-beta3

projects[token][subdir] = contrib
projects[token][version] = 1.0-beta2
projects[token][patch][] = http://drupal.org/files/issues/691078-token-field-tokens-v2.patch

projects[views][subdir] = contrib
projects[views][version] = 3.0-rc1

projects[entitycache][subdir] = contrib
projects[entitycache][type] = module
projects[entitycache][version] = 1.x-dev

projects[conditional_styles][subdir] = contrib
projects[conditional_styles][version] = 2.0

projects[tao][version] = 3.0-beta4

projects[rubik][version] = 4.0-beta6

projects[nodeconnect][type] = module
projects[nodeconnect][subdir] = contrib
projects[nodeconnect][download][type] = git
projects[nodeconnect][download][revision] = 1d35e1c7087057a4a8616383a1ecb33bc119ee0b
projects[nodeconnect][download][url] = http://git.drupal.org/project/nodeconnect.git

projects[pangea][type] = theme
projects[pangea][download][type] = git
projects[pangea][download][url] = git@github.com:phase2/pangea.git
projects[pangea][download][revision] = aab0bbdb0ddb968659a17c95382dc297fc018531

projects[apps][type] = module
projects[apps][subdir] = custom
projects[apps][download][type] = git
projects[apps][download][url] = git@phase2.beanstalkapp.com:/apps.git
projects[apps][download][revision] = 4722dd4c76b06f0912d1770bdcd420b5c04dcde4

projects[imce][subdir] = contrib
projects[imce][version] = 1.4
projects[imce][type] = module

projects[imce_wysiwyg][subdir] = contrib
projects[imce_wysiwyg][version] = 1.x-dev
projects[imce_wysiwyg][revision] = 3a5a5acad386aae2ca47bd2cd02b9c3c68f6d306

projects[xmlsitemap][subdir] = contrib
projects[xmlsitemap][type] = module
projects[xmlsitemap][version] = 2.0-beta3

projects[wysiwyg][subdir] = contrib
projects[wysiwyg][type] = module
projects[wysiwyg][version] = 2.1
projects[wysiwyg][download][type] = git
projects[wysiwyg][download][url] = http://git.drupal.org/project/wysiwyg.git
projects[wysiwyg][download][revision] = cd2142614c3d17ec7b0111712226aa51b5ffba6e
projects[wysiwyg][patch][] = http://drupal.org/files/issues/746524-91Drupal7-v3_drush_make.patch

projects[google_analytics][subdir] = contrib
projects[google_analytics][module] = module
projects[google_analytics][version] = 1.2

projects[comment_notify][subdir] = contrib
projects[comment_notify][version] = 1.0-beta1

projects[webform][subdir] = contrib
projects[webform][type] = module
projects[webform][version] = 3.11

projects[recaptcha][subdir] = contrib
projects[recaptcha][type] = module
projects[recaptcha][version] = 1.7

projects[link][subdir] = contrib
projects[link][type] = module
projects[link][version] = 1.0-alpha3

projects[phase2_profile][type] = module
projects[phase2_profile][subdir] = contrib
projects[phase2_profile][download][type] = svn
projects[phase2_profile][download][url] = https://phase2.svn.beanstalkapp.com/phase2_d7/trunk/phase2_profile
projects[phase2_profile][download][revision] = 825

projects[media][subdir] = contrib
projects[media][type] = module
projects[media][download][type] = git
projects[media][download][url] = http://git.drupal.org/project/media.git
projects[media][download][revision] = 58fc0858e777869eabe4e9ba66e74bc841df0918
projects[media][patch][] = http://drupal.org/files/issues/views-integration-file-entity-type-1192326-6-D7-drush.patch
projects[media][patch][] = http://drupal.org/files/issues/1199482-add_views_relationship_to_media_field-drush_make_0_0.patch

projects[boxes][subdir] = contrib
projects[boxes][type] = module
projects[boxes][download][type] = git
projects[boxes][download][revision] = 5fc88dba179c00907ce86ccefeef1b9e9d362a9d
projects[boxes][download][url] = http://git.drupal.org/project/boxes.git
projects[boxes][patch][] = http://drupal.org/files/issues/boxes-modified-simple-box.make_.patch

projects[styles][subdir] = contrib
projects[styles][type] = module
projects[styles][version] = 2.0-alpha8

projects[views_arguments_extras][subdir] = contrib
projects[views_arguments_extras][download][type] = git
projects[views_arguments_extras][download][url] = http://git.drupal.org/project/views_arguments_extras.git
projects[views_arguments_extras][download][revision] = 5b5003c7cebc2815a9bd3a1aa8a3919dc1913e57

projects[embbedable][subdir] = contrib
projects[embbedable][type] = module
projects[embbedable][download][type] = git
projects[embbedable][download][url] = git://github.com/phase2/embbedable.git
projects[embbedable][download][revision] = 0bb7a44696bc6ba8db9d0af4774efac6efde449e

projects[openpublish][type] = profile
projects[openpublish][download][type] = git
projects[openpublish][download][url] = git@phase2.beanstalkapp.com:/openpublish3.git
projects[openpublish][download][revision] = 9f95fce4758dae9e92dbc1af2f6724a27efc0b74

projects[openpublish_features][type] = module
projects[openpublish_features][download][type] = git
projects[openpublish_features][download][url] = git@phase2.beanstalkapp.com:/openpublish_features.git
projects[openpublish_features][download][revision] = 829432e1565cf1fd535ca47cd4686dd16164f8a9

projects[media_views_widget][type] = module
projects[media_views_widget][subdir] = contrib
projects[media_views_widget][download][type] = git
projects[media_views_widget][download][url] = git@github.com:phase2/media_views_widget.git
projects[media_views_widget][download][revision] = 520ec324fb7932ef916450d673010d87b3499da8

projects[taxonomy_view][type] = module
projects[taxonomy_view][subdir] = contrib
projects[taxonomy_view][download][type] = git
projects[taxonomy_view][download][url] = git@github.com:phase2/taxonomy_view.git
projects[taxonomy_view][download][revision] = e6a0256ac24e3107e3a2d1df9f6755b3b2a2f72a

projects[media_image_formatter][type] = module
projects[media_image_formatter][subdir] = contrib
projects[media_image_formatter][download][type] = git
projects[media_image_formatter][download][url] = git@github.com:phase2/media_image_formatter.git
projects[media_image_formatter][download][revision] = 097faa8b5752222ec640bf7df78575bd16ce53a7

projects[context_breadcrumb_current_page][type] = module
projects[context_breadcrumb_current_page][subdir] = contrib
projects[context_breadcrumb_current_page][download][type] = git
projects[context_breadcrumb_current_page][download][url] = git@github.com:phase2/context_breadcrumb_current_page.git
projects[context_breadcrumb_current_page][download][revision] = b419eaf9a033a92dec339aa7835010ecf5884769

projects[views_file_row][type] = module
projects[views_file_row][subdir] = contrib
projects[views_file_row][download][type] = git
projects[views_file_row][download][url] = git@github.com:phase2/views_file_row.git
projects[views_file_row][download][revision] = 2fc030bdf6a43816f44384e7921e9a5274ef70fb

projects[context_title][type] = module
projects[context_title][subdir] = contrib
projects[context_title][download][type] = git
projects[context_title][download][url] = git@github.com:phase2/context_title.git
projects[context_title][download][revision] = 8083030cd5cf9b48b1b0f8739cc9bf7d3e3e5c90

projects[static_404][type] = module
projects[static_404][subdir] = contrib
projects[static_404][download][type] = git
projects[static_404][download][url] = http://git.drupal.org/project/static_404.git
projects[static_404][download][revision] = 41af087d004704d9cd55130bc51b2944f1e42300

projects[location][type] = module
projects[location][subdir] = contrib
projects[location][download][type] = git
projects[location][download][url] = http://git.drupal.org/project/location.git
projects[location][download][revision] = 99ce4bc42d19fd6ae243ebebc356cd0bbb7edbcc

projects[context_bool_field][type] = module
projects[context_bool_field][subdir] = contrib
projects[context_bool_field][download][type] = git
projects[context_bool_field][download][url] = http://git.drupal.org/project/context_bool_field.git
projects[context_bool_field][download][revision] = 18f6c6bf7e1cce492418d9f05344969be4fdb118

projects[content_taxonomy][type] = module
projects[content_taxonomy][subdir] = contrib
projects[content_taxonomy][download][type] = git
projects[content_taxonomy][download][url] = http://git.drupal.org/project/content_taxonomy.git
projects[content_taxonomy][download][revision] = f62521bccbb5097e015c123edd06a1341583fdb8

projects[views_php][type] = module
projects[views_php][subdir] = contrib
projects[views_php][download][type] = git
projects[views_php][download][url] = http://git.drupal.org/project/views_php.git
projects[views_php][download][revision] = 989aa6e5e19b8996d84b26437d191cfa7255f960

projects[views_slideshow][type] = module
projects[views_slideshow][subdir] = contrib
projects[views_slideshow][download][type] = git
projects[views_slideshow][download][url] = http://git.drupal.org/project/views_slideshow.git
projects[views_slideshow][download][revision] = 9a91a5f6459c324568b0146531b8303d02c4b651

projects[fb][type] = module
projects[fb][subdir] = contrib
projects[fb][download][type] = git
projects[fb][download][url] = http://git.drupal.org/project/fb.git
projects[fb][download][revision] = b3adf0894a1a3a76f23e5a3cd599c34610aaa28a
projects[fb][patch][] = http://drupal.org/files/issues/1197924_fb_url_rewrite_0.patch
projects[fb][patch][] = http://drupal.org/files/issues/fb-register-formid-1032636-2.patch

projects[brightcove][type] = module
projects[brightcove][subdir] = contrib
projects[brightcove][version] = 2.0-alpha4

projects[media_vimeo][type] = module
projects[media_vimeo][subdir] = contrib
projects[media_vimeo][download][type] = git
projects[media_vimeo][download][url] = http://git.drupal.org/project/media_vimeo.git
projects[media_vimeo][download][revision] = 74c055e137f717d39430e3b45537ca0031e0f3c3

projects[token_function][type] = module
projects[token_function][subdir] = contrib
projects[token_function][download][type] = git
projects[token_function][download][url] = http://git.drupal.org/project/token_function.git
projects[token_function][download][revision] = 53c714fc1420a982c5c6c7f2293bd3a499cf9b94

projects[webform_conditional][type] =  module
projects[webform_conditional][subdir] = contrib
projects[webform_conditional][download][type] = git
projects[webform_conditional][download][url] = http://git.drupal.org/project/webform_conditional.git
projects[webform_conditional][download][revision] = 58c1b10c9fb221c4a1147f1967ce5ed511968762

projects[omniture][type] = module
projects[omniture][subdir] = contrib
projects[omniture][download][type] = git
projects[omniture][download][url] = http://git.drupal.org/project/omniture.git
projects[omniture][download][revision] = e5fa6af829e93206b9ab2cc9f6291c9d6ffe6673
projects[omniture][patch][] = http://drupal.org/files/issues/omniture_context_1223462-make_3.patch

projects[username_check][type] = module
projects[username_check][subdir] = contrib
projects[username_check][download][type] = git
projects[username_check][download][url] = http://git.drupal.org/project/username_check.git
projects[username_check][download][revision] = 299f05438af20211dda6c15e0c832b9af70e4138

projects[job_scheduler][type] = module
projects[job_scheduler][subdir] = contrib
projects[job_scheduler][version] = 2.0-alpha2

projects[scheduler][type] = module
projects[scheduler][subdir] = contrib
projects[scheduler][version] = 1.0

projects[feeds][type] = module
projects[feeds][subdir] = contrib
projects[feeds][version] = 2.0-alpha4

projects[memcache][type] = module
projects[memcache][subdir] = contrib
projects[memcache][version] = 1.0-beta4

projects[taxonomy_manager][type] = module
projects[taxonomy_manager][subdir] = contrib
projects[taxonomy_manager][version] = 1.0-beta1

projects[field_redirection][type] = module
projects[field_redirection][subdir] = contrib
projects[field_redirection][version] = 1.0
projects[field_redirection][patch][] = http://drupal.org/files/issues/1215538-drush.patch

projects[ga_stats][type] = module
projects[ga_stats][subdir] = contrib
projects[ga_stats][version] = 1.0-alpha2

projects[jcarousel][type] = module
projects[jcarousel][subdir] = contrib
projects[jcarousel][version] = 2.4-alpha3
projects[jcarousel][patch][] = http://drupal.org/files/issues/jcarousel_update-1196558-8-make.patch

projects[libraries][type] = module
projects[libraries][subdir] = contrib
projects[libraries][version] = 1.0

projects[terms_of_use][type] = module
projects[terms_of_use][subdir] = contrib
projects[terms_of_use][version] = 1.1

projects[devel][type] =  module
projects[devel][subdir] = contrib
projects[devel][version] = 1.2

projects[options_element][type] =  module
projects[options_element][subdir] = contrib
projects[options_element][version] = 1.4

projects[twitter_pull][type] =  module
projects[twitter_pull][subdir] = contrib
projects[twitter_pull][version] = 1.0-rc1

projects[googlenews][type] =  module
projects[googlenews][subdir] = contrib
projects[googlenews][version] = 1.4

projects[akamai][type] = module
projects[akamai][subdir] = contrib
projects[akamai][version] = 1.1

projects[media_youtube][type] = module
projects[media_youtube][subdir] = contrib
projects[media_youtube][verison] = 1.0-alpha5

projects[apachesolr][type] = module
projects[apachesolr][subdir] = contrib
projects[apachesolr][version] = 1.0-beta8

projects[content_lock][type] = module
projects[content_lock][subdir] = contrib
projects[content_lock][version] = 1.1

projects[search_api][type] = module
projects[search_api][subdir] = contrib
projects[search_api][version] = 1.0-beta10

projects[search_api_solr][type] = module
projects[search_api_solr][subdir] = contrib
projects[search_api_solr][version] = 1.0-beta3

projects[search_api_sorts][type] = module
projects[search_api_sorts][subdir] = contrib
projects[search_api_sorts][version] = 1.1

projects[jquery_update][type] = module
projects[jquery_update][subdir] = contrib
projects[jquery_update][version] = 2.2

projects[captcha][type] =  module
projects[captcha][subdir] = contrib
projects[captcha][version] = 1.0-alpha3

projects[nodequeue][type] = module
projects[nodequeue][subdir] = contrib
projects[nodequeue][version] = 2.0-alpha2

projects[field_boxes][type] = module
projects[field_boxes][subdir] = contrib
projects[field_boxes][download][type] = git
projects[field_boxes][download][url] = http://git.drupal.org/project/field_boxes.git
projects[field_boxes][download][revision] = 54918ad944e516c62c27b1116c1adac38d4d4507
// allow simpletest to look into profiles for modules
projects[drupal][patch][] = http://drupal.org/files/issues/911354.46.patch
// projects[views][patch][] = http://drupal.org/files/issues/views_relatedterms.patch
project[devel][subdir] = contrib
project[devel][version] = 1.2

project[coder][subdir] = contrib
project[coder][version] = 1.0

libraries[ckeditor][download][type] = get
libraries[ckeditor][download][url] = http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.6/ckeditor_3.6.tar.gz
libraries[ckeditor][directory_name] = ckeditor

libraries[brightcove-php][download][type] = git
libraries[brightcove-php][download][branch] = master
libraries[brightcove-php][download][tag] = 2.0.4
libraries[brightcove-php][download][url] = git://github.com/BrightcoveOS/PHP-MAPI-Wrapper.git
libraries[brightcove-php][directory_name] = BrightcoveOS-PHP-MAPI-Wrapper

libraries[facebook-php-sdk][download][type] = git
libraries[facebook-php-sdk][download][branch] = master
libraries[facebook-php-sdk][download][tag] = v2.1.2
libraries[facebook-php-sdk][download][url] = git://github.com/facebook/php-sdk.git
libraries[facebook-php-sdk][directory_name] = facebook-php-sdk

libraries[jquery.cycle][download][type] = get
libraries[jquery.cycle][download][url] = http://jquery.malsup.com/cycle/release/jquery.cycle.zip?v2.99
libraries[jquery.cycle][directory_name] = jquery.cycle

libraries[SolrPhpClient][download][type] = get
libraries[SolrPhpClient][download][url] = http://solr-php-client.googlecode.com/files/SolrPhpClient.r22.2009-11-09.tgz
libraries[SolrPhpClient][destination] = modules/contrib/search_api_solr
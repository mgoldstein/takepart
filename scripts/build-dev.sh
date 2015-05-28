#!/usr/bin/env sh

# Set the alias
alias drush="drush -r ../drupal"

# Update the Prod database with latest code updates
drush updb

# Disable caches and then clear them
drush vset preprocess_css 0
drush vset preprocess_js 0
drush vset cache 0
drush cc all

# Enable Development tools
drush en stage_file_proxy -y
drush variable-set stage_file_proxy_origin "http://www.takepart.com"
drush en devel -y
drush en diff -y

# Enable UI modules (these should be disabled on prod)
drush en views_ui -y
drush en themekey_ui -y
drush en styles_ui -y
drush en field_validation_ui -y
drush en feeds_ui -y
drush en bean_admin_ui -y
drush en context_ui -y

# Revert features
drush fra -y

# Rebuild registry and clear cache
drush eval "registry_rebuild();"
drush cc all

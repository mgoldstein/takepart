#!/usr/bin/env sh

# Set the alias
alias drush="drush -r ../drupal"


# Disable UI modules
drush dis views_ui -y
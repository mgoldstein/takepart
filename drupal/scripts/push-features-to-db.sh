#!/bin/bash

# Get the of the script file. This works by first getting the directory of the
# script as invoked, then resolving any symlinks using pwd.
SCRIPT_DIR=$(dirname "$0")
SCRIPT_DIR=$(cd "${SCRIPT_DIR}" && pwd -P)

# This file is located in the scripts directory directly under the Drupal root
# directory. The relative portion of the path is removed with a call to pwd.
DRUPAL_ROOT="${SCRIPT_DIR}/../"
DRUPAL_ROOT=$(cd "${DRUPAL_ROOT}" && pwd -P)

# List feature identifiers of a specified type
function list_features() {
  local NAME=$1
  # Search through the site code base
  find "${DRUPAL_ROOT}" -type f |
    # Exclude contributed modules
    grep -v "modules/contrib" |
    # Examine only info files
    grep '\.info$' |
    # Extract feature identifiers from each file found
    while read FILENAME ; do
      # Look for feature declaration lines
      grep '^features\['"${NAME}"'\]\[\]' "${FILENAME}" |
      # Print everything after the first equal sign
      awk '{
        pos=index($0, "=")
        print substr($0, pos+1)
      }' |
      # Trim surrounding whitespace
      sed -e 's/^ *//g' -e 's/ *$//g' |
      # Trim double quotes
      sed -e 's/^\"//g' -e 's/\"$//g'
    done |
    # Sort the feature identifiers to make
    # before and after comparisons easier
    sort
}

# Remove feature indentifiers of a specified type from info files
function remove_features_from_info_files() {
  local NAME=$1
  # Search through the site code base
  find "${DRUPAL_ROOT}" -type f |
    # Exclude contributed modules
    grep -v "modules/contrib" |
    # Examine only info files
    grep '\.info$' |
    # Remove feature identifiers from each file found
    while read FILENAME ; do
      TEMPFILE="${FILENAME}.features-removed"
      # Dump the info file into a temporary file without the feature identifiers
      grep -v '^features\['"${NAME}"'\]\[\]' "${FILENAME}" > "${TEMPFILE}"
      # Copy the temporary file over the original
      cp "${TEMPFILE}" "${FILENAME}"
      # Remove the temporary file
      rm "${TEMPFILE}"
    done
}

# Remove ctools versions of a specified type from info files
function remove_ctools_versions_from_info_files() {
  local NAME=$1
  # Search through the site code base
  find "${DRUPAL_ROOT}" -type f |
    # Exclude contributed modules
    grep -v "modules/contrib" |
    # Examine only info files
    grep '\.info$' |
    # Remove the appropriate ctools version from each file found
    while read FILENAME ; do
      TEMPFILE="${FILENAME}.version-removed"
      # Dump the info file into a temporary file without the version
      grep -v '^features\[ctools\]\[\] = '"${NAME}" "${FILENAME}" > "${TEMPFILE}"
      # Copy the temporary file over the original
      cp "${TEMPFILE}" "${FILENAME}"
      # Remove the temporary file
      rm "${TEMPFILE}"
    done
}

# Remove feature files of a specified type
function remove_feature_include_files() {
  local SUFFIX=$(echo "$1" | sed 's/\./\\\./g')
  # Search through the site code base
  find "${DRUPAL_ROOT}" -type f |
    # Exclude contributed modules
    grep -v "modules/contrib" |
    # Examine only info files
    grep "${SUFFIX}"'$' |
    # Remove each file
    while read FILENAME ; do
      echo rm "${FILENAME}"
    done
}

function export_variables() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  drush php-eval '
    $values = array();
    while ($line = fgets(STDIN)) {
      $name = trim($line);
      $values[$name] = variable_get($name, NULL);
      echo $line . "\n";
    }
    print json_encode($values, JSON_PRETTY_PRINT) . "\n";
  '
}




#remove_features_from_info_files "variable"
#remove_ctools_versions_from_info_files "strongarm"
#remove_feature_include_files ".strongarm.inc"
#list_features "variable" > "variables.txt"
#export_variables "variables.txt"

# list_features "ctools"
# list_features "features_api"

# list_features "bean_type"
# list_features "box"
# list_features "ccl"
# list_features "context"
# list_features "facetapi"
# list_features "fe_block_boxes"
# list_features "fe_block_settings"
# list_features "fe_nodequeue"
# list_features "feeds_importer"
# list_features "field"
# list_features "field_group"
# list_features "filter"
# list_features "image"
# list_features "menu_custom"
# list_features "node"
# list_features "panels_mini"
# list_features "pm_signup_endpoint"
# list_features "search_api_index"
# list_features "search_api_server"
# list_features "taxonomy"
# list_features "user_permission"
# list_features "views_view"






# function remove_features_from_info_file() {
#   local NAME=$1
#   find "${DRUPAL_ROOT}" -type f | grep "\.info$" | while read FILENAME ; do
#     grep -v '^features\['"${NAME}"'\]\[\]' "${FILENAME}" > "/tmp/no-${NAME}-info"
#     cp "/tmp/no-${NAME}-info" "${FILENAME}"
#   done
# }

# function remove_versions_from_info_file() {
#   local NAME=$1
#   find "${DRUPAL_ROOT}" -type f | grep "\.info$" | while read FILENAME ; do
#     grep -v '^features\[ctools\]\[\] = '"${NAME}" "${FILENAME}" > "/tmp/no-${NAME}-version-info"
#     cp "/tmp/no-${NAME}-version-info" "${FILENAME}"
#   done
# }

# # Remove variables from features
# list_features "variable"
# drush scr "export-variables.php" > "variables-before.json"
# drush scr "push-variables-to-db.php"
# remove_features_from_info_file "variable"
# remove_versions_from_info_file "strongarm"
# drush scr "export-variables.php" > "variables-after.json"

# # Remove field groups from features
# list_features "field_group" > "field-group-features.txt"
# drush scr "export-field-groups.php" > "field-groups-before.json"
# drush scr "push-field-groups-to-db.php"
# remove_features_from_info_file "field_group"
# remove_versions_from_info_file "field_group"
# drush scr "export-field-groups.php" > "field-groups-after.json"



# # List strongarm feature files
# find . -type f | grep "strongarm\.inc$"

# # Remove variable features from info files
# find . -type f | grep "\.info$" | while read FILENAME; do grep -v "features\[variable\]\[\]" "$FILENAME" > /tmp/no-vars-info; cp /tmp/no-vars-info "$FILENAME"; done

# # List remaining features
# find . -type f | grep info$ | while read filename; do grep 'features\[' "$filename"; done | sort


# # Remove variable features from info files
# find . -type f | grep "\.info$" | while read FILENAME; do grep -v "features\[field_group\]\[\]" "$FILENAME" > /tmp/no-field-group-info; cp /tmp/no-field-group-info "$FILENAME"; done



# find . -type f | grep "\.info$" | while read FILENAME; do grep -v "features\[ctools\]\[\] = field_group:" "$FILENAME" > /tmp/no-fg-version-info; cp /tmp/no-fg-version-info "$FILENAME"; done



# find . -type f | grep "\.info$" | while read FILENAME ; do
#   grep -v "features\[field\]\[\]" "$FILENAME" > /tmp/no-field-info;
#   cp /tmp/no-field-info "$FILENAME";
# done

# find . -type f | grep "\.info$" | while read FILENAME ; do
#   grep -v "features\[ctools\]\[\] = strongarm:" "$FILENAME" > /tmp/no-strongarm-info;
#   cp /tmp/no-strongarm-info "$FILENAME";
# done


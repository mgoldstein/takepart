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

# Remove feature identifiers of a specified type from info files
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
      rm "${FILENAME}"
    done
}

# Complete remove features of a specified type
function remove_features_of_type() {
  local TYPE=$1
  local VERSION_NAME=$2
  local INCLUDE_SUFFIX=$3

  local IDENTIFIER_LIST="${TYPE}-identifiers.txt"
  local BEFORE_EXPORT="${TYPE}-values-before.json"
  local AFTER_EXPORT="${TYPE}-values-after.json"
  local EXPORT_DIFF="${TYPE}-values.diff"

  # Get a list of the identifiers for the specified type of feature
  list_features "${TYPE}" > "${IDENTIFIER_LIST}"

  # Export their values before making any changes
  #export_${TYPE}_values "${IDENTIFIER_LIST}" > "${BEFORE_EXPORT}"

  # Push the feature values to the database
  push_${TYPE}_values_to_db "${IDENTIFIER_LIST}"

  # Remove all variables from features
  # remove_features_from_info_files "${TYPE}"
  # remove_ctools_versions_from_info_files "${VERSION_NAME}"
  # if [[ ! -z "${INCLUDE_SUFFIX}" ]] ; then
  #   remove_feature_include_files "${INCLUDE_SUFFIX}"
  # fi

  # Export the values again for the purpose of
  # verifying that no values were changed.
  #drush cc all
  #export_${TYPE}_values "${IDENTIFIER_LIST}" > "${AFTER_EXPORT}"

  # Get the difference between before and after
  #diff "${BEFORE_EXPORT}" "${AFTER_EXPORT}" > "${EXPORT_DIFF}"
}

function export_bean_type_values() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
    $values = ctools_export_load_object("bean_type");
    ksort($values);
    print json_encode($values, JSON_PRETTY_PRINT) . "\n";
  '
}

function export_box_values() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
    $values = boxes_box_load();
    ksort($values);
    print json_encode($values, JSON_PRETTY_PRINT) . "\n";
  '
}

function export_ccl_values() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
    $values = ccl_get_presets();
    ksort($values);
    print json_encode($values, JSON_PRETTY_PRINT) . "\n";
  '
}

function export_context_values() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
    $values = array();
    while ($line = fgets(STDIN)) {
      $identifier = trim($line);
      $values[$identifier] = context_load($identifier, TRUE);
    }
    print json_encode($values, JSON_PRETTY_PRINT) . "\n";
  '
}

function export_facetapi_values() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
    $values = ctools_export_load_object("facetapi");
    ksort($values);
    print json_encode($values, JSON_PRETTY_PRINT) . "\n";
  '
}

function export_fe_block_boxes_values() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
  '
}

function export_fe_block_settings_values() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
  '
}

function export_fe_nodequeue_values() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
  '
}

function export_feeds_importer_values() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
  '
}

function export_field_values() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
    $values = array(
      "bases" => array(),
      "instances" => array(),
    );
    while ($line = fgets(STDIN)) {
      $identifier = trim($line);
      list($entity_type, $bundle, $name) = explode("-", $identifier);
      if (!array_key_exists($name, $values["bases"])) {
        $values["bases"][$name] = field_info_field($name);
      }
      $values["instances"][$identifier] = field_info_instance(
        $entity_type, $name, $bundle);
    }
    print json_encode($values, JSON_PRETTY_PRINT) . "\n";
  '
}

function export_field_group_values() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
    $values = array();
    while ($line = fgets(STDIN)) {
      $identifier = trim($line);
      list($name, $entity_type, $bundle, $mode) = explode("|", $identifier);
      $values[$identifier] = field_group_load_field_group(
        $name, $entity_type, $bundle, $mode);
    }
    print json_encode($values, JSON_PRETTY_PRINT) . "\n";
  '
}

function export_filter_values() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
  '
}

function export_image_values() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
    $values = array();
    while ($line = fgets(STDIN)) {
      $identifier = trim($line);
      $values[$identifier] = image_style_load($identifier);
    }
    print json_encode($values, JSON_PRETTY_PRINT) . "\n";
  '
}

function export_menu_custom_values() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
  '
}

function export_node_values() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
    $values = array();
    while ($line = fgets(STDIN)) {
      $identifier = trim($line);
      $values[$identifier] = node_type_get_type($identifier);
    }
    print json_encode($values, JSON_PRETTY_PRINT) . "\n";
  '
}

function export_panels_mini_values() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
  '
}

function export_pm_signup_endpoint_values() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
  '
}

function export_search_api_index_values() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
  '
}

function export_search_api_server_values() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
  '
}

function export_taxonomy_values() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
    $values = array();
    while ($line = fgets(STDIN)) {
      $identifier = trim($line);
      $values[$identifier] = taxonomy_vocabulary_machine_name_load($identifier);
    }
    print json_encode($values, JSON_PRETTY_PRINT) . "\n";
  '
}

function export_user_permission_values() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
    function fptdb_user_features_get_roles() {
      $roles = array();
      foreach (user_roles() as $rid => $name) {
        switch ($rid) {
          case DRUPAL_ANONYMOUS_RID:
              $roles[$rid] = "anonymous user";
            break;
          case DRUPAL_AUTHENTICATED_RID:
              $roles[$rid] = "authenticated user";
            break;
          default:
            $roles[$rid] = $name;
            break;
        }
      }
      return $roles;
    }

    function fptdb_user_features_get_permissions() {
      $map = user_permission_get_modules();
      $roles = fptdb_user_features_get_roles();
      $permissions = array();
      foreach (user_role_permissions($roles) as $rid => $role_permissions) {
        foreach (array_keys(array_filter($role_permissions)) as $permission) {
          if (isset($map[$permission])) {
            $permissions[$permission][] = $roles[$rid];
          }
        }
      }
      return $permissions;
    }

    $perm_modules = user_permission_get_modules();
    $permissions = fptdb_user_features_get_permissions();
    $values = array();
    while ($line = fgets(STDIN)) {
      $identifier = trim($line);
      $values[$identifier] = array(
        "name" => $identifier,
      );
      if (isset($permissions[$identifier])) {
        sort($permissions[$identifier]);
        $values[$identifier]["roles"] = $permissions[$identifier];
      }
      else {
        $values[$identifier]["roles"] = array();
      }
      if (isset($perm_modules[$identifier])) {
        $values[$identifier]["module"] = $perm_modules[$identifier];
      }
    }
    print json_encode($values, JSON_PRETTY_PRINT) . "\n";
  '
}

function export_variable_values() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
    $values = array();
    while ($line = fgets(STDIN)) {
      $identifier = trim($line);
      $values[$identifier] = variable_get($identifier, NULL);
    }
    print json_encode($values, JSON_PRETTY_PRINT) . "\n";
  '
}

function export_views_view_values() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
    $values = array();
    while ($line = fgets(STDIN)) {
      $identifier = trim($line);
      $values[$identifier] = views_get_view($identifier, TRUE);
    }
    print json_encode($values, JSON_PRETTY_PRINT) . "\n";
  '
}









function push_bean_type_values_to_db() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
    $values = ctools_export_load_object("bean_type");
    while ($line = fgets(STDIN)) {
      $identifier = trim($line);
      $bean_type = $values[$identifier];
      drupal_write_record("bean_type", $bean_type, array("name"));
    }
  '
}

function push_box_values_to_db() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
    $values = ctools_export_load_object("box");
    while ($line = fgets(STDIN)) {
      $identifier = trim($line);
      $box = boxes_box::load($identifier);
      $box->save();
    }
  '
}

function push_ccl_values_to_db() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
    $presets = ccl_get_presets();
    foreach($presets as $record) {
      drupal_write_record("ccl", $record, array("clid"));
    }
  '
}

function push_context_values_to_db() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
    while ($line = fgets(STDIN)) {
      $identifier = trim($line);
      $context = context_load($identifier, TRUE);
      context_save($context);
    }
  '
}

function push_facetapi_values_to_db() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
    $values = ctools_export_load_object("facetapi");
    while ($line = fgets(STDIN)) {
      $identifier = trim($line);
      $facetapi = $values[$identifier];
      drupal_write_record("facetapi", $facetapi, array("name"));
    }
  '
}

function push_fe_block_boxes_values_to_db() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
  '
}

function push_fe_block_settings_values_to_db() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
  '
}

function push_fe_nodequeue_values_to_db() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
  '
}

function push_feeds_importer_values_to_db() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
  '
}

function push_field_values_to_db() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
    $bases = array();
    while ($line = fgets(STDIN)) {

      $identifier = trim($line);
      list($entity_type, $bundle, $name) = explode("-", $identifier);

      if (!array_key_exists($name, $bases)) {
        $bases[$name] = field_info_field($name);
        unset($bases[$name]["field_config"]["columns"]);
        if ($bases[$name]["field_config"]["storage"]["type"]
          == variable_get("field_storage_default", "field_sql_storage")) {
          unset($bases[$name]["field_config"]["storage"]);
        }
        if (isset($bases[$name]["field_config"]["storage"]["details"])) {
          unset($bases[$name]["field_config"]["storage"]["details"]);
        }
        if (isset($bases[$name]["id"])) {
          field_update_field($bases[$name]);
        }
        else {
          field_create_field($bases[$name]);
        }
      }

      $instance_config = field_info_instance($entity_type, $name, $bundle);
      if (isset($instance_config["id"])) {
        field_update_instance($instance_config);
      }
      else {
        field_create_instance($instance_config);
      }
    }
  '
}

function push_field_group_values_to_db() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # (Re)save the values while Drupal is boot-strapped
  drush php-eval '
    while ($line = fgets(STDIN)) {
      $identifier = trim($line);
      list($name, $entity_type, $bundle, $mode) = explode("|", $identifier);
      $record = field_group_load_field_group(
        $name, $entity_type, $bundle, $mode);
      field_group_group_save($record);
    }
  '
}

function push_filter_values_to_db() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
  '
}

function push_image_values_to_db() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
    $values = array();
    while ($line = fgets(STDIN)) {
      $identifier = trim($line);
      $style = image_style_load($identifier);
      image_style_save($style);
    }
  '
}

function push_menu_custom_values_to_db() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
  '
}

function push_node_values_to_db() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
    $values = array();
    while ($line = fgets(STDIN)) {
      $identifier = trim($line);
      $type = node_type_get_type($identifier);
      node_type_save($type);
    }
  '
}

function push_panels_mini_values_to_db() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
  '
}

function push_pm_signup_endpoint_values_to_db() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
  '
}

function push_search_api_index_values_to_db() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
  '
}

function push_search_api_server_values_to_db() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
  '
}

function push_taxonomy_values_to_db() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
    $values = array();
    while ($line = fgets(STDIN)) {
      $identifier = trim($line);
      $vocabulary = taxonomy_vocabulary_machine_name_load($identifier);
      taxonomy_vocabulary_save($vocabulary);
    }
  '
}

function push_user_permission_values_to_db() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
  '
}

function push_variable_values_to_db() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # (Re)save the values while Drupal is boot-strapped
  drush php-eval '
    while ($line = fgets(STDIN)) {
      $identifier = trim($line);
      // Using a default value of NULL is not an issue as each variable
      // will have a value either in the database or the feature the
      // variable name was pulled from.
      $value = variable_get($identifier, NULL);
      variable_set($identifier, $value);
    }
  '
}

function push_views_view_values_to_db() {
  local FILENAME=$1
  (cat "${FILENAME}") |
  # Get the values while Drupal is boot-strapped
  drush php-eval '
    $values = array();
    while ($line = fgets(STDIN)) {
      $identifier = trim($line);
      $view = views_get_view($identifier, TRUE);
      views_save_view($view);
    }
  '
}

#  13 features[taxonomy][]
#  17 features[pm_signup_endpoint][]
#  27 features[node][]
#  27 features[views_view][]
#  34 features[context][]
#  34 features[image][]
#  38 features[user_permission][]
#  55 features[box][]
#  56 features[features_api][]
#  95 features[ctools][]
# 139 features[field_group][]
# 317 features[variable][]
# 430 features[field][]

remove_features_of_type "taxonomy" "taxonomy" ".features.taxonomy.inc"
remove_features_of_type "pm_signup_endpoint" "pm_signup_endpoint" ".features.pm_signup_endpoint.inc"
remove_features_of_type "node" "node"
remove_features_of_type "views_view" "views" ".views_default.inc"
remove_features_of_type "context" "context" ".context.inc"
#remove_features_of_type "image" "image"
remove_features_of_type "user_permission" "user_permission" ".features.user_permission.inc"
remove_features_of_type "box" "boxes" ".box.inc"
remove_features_of_type "field_group" "field_group" ".field_group.inc"
remove_features_of_type "variable" "strongarm" ".strongarm.inc"
remove_features_of_type "field" "field" ".features.field.inc"

#remove_features_of_type "bean_type" "bean_type" ".bean.inc"
remove_features_of_type "ccl" "ccl"
remove_features_of_type "facetapi" "facetapi" ".facetapi_defaults.inc"

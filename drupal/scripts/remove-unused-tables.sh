#!/bin/bash

SCRIPT_DIR=$(dirname "$0")
SCRIPT_DIR=$(cd "${SCRIPT_DIR}" && pwd -P)

DB_USER=takepart
DB_PASS=asdfasdf
DB_NAME=code_cleanup

function execute_mysql_command() {
  local COMMAND=$1
  mysql ${DB_NAME} -N -u ${DB_USER} -p${DB_PASS} -e "${COMMAND}"
}

execute_mysql_command "SHOW TABLES;" |
while read TABLE_NAME ; do
  echo "${TABLE_NAME}"
done | sort > "tables-in-database.txt"

drush php-eval '
  $schemas = drupal_get_complete_schema(TRUE);
  foreach ($schemas as $table => $schema) {
    print "{$table}\n";
  }
' | sort > "tables-in-schema.txt"

diff "tables-in-schema.txt" "tables-in-database.txt" |
  grep ^\> |
  awk '{print $2}' | while read TABLE_NAME ; do
    echo "Removing ${TABLE_NAME}"
    execute_mysql_command "DROP TABLE ${TABLE_NAME};"
  done

rm "tables-in-schema.txt"
rm "tables-in-database.txt"

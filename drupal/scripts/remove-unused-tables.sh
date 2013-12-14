#!/bin/bash

SCRIPT_DIR=$(dirname "$0")
SCRIPT_DIR=$(cd "${SCRIPT_DIR}" && pwd -P)

DEFAULT_DB_USER="takepart"
DEFAULT_DB_PASS="asdfasdf"
DEFAULT_DB_NAME="code_cleanup"
DEFAULT_DB_HOST="localhost"

DB_USER=${1:-$DEFAULT_DB_USER}
DB_PASS=${1:-$DEFAULT_DB_PASS}
DB_NAME=${1:-$DEFAULT_DB_NAME}
DB_HOST=${1:-$DEFAULT_DB_HOST}

function execute_mysql_command() {
  local COMMAND=$1
  mysql ${DB_NAME} -N -h ${DB_HOST} -u ${DB_USER} -p${DB_PASS} -e "${COMMAND}"
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

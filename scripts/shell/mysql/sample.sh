#!/bin/bash
# Author : ctoepfer
# Date   : 12/08/2011
# Description : Script for first commit

DB="takepart"
DELIM=","
MYSQL="mysql"


CSV="$1"
TABLE="$2"
USER="$3"

[ "$CSV" = "" -o "$TABLE" = "" ] && echo "Syntax: $0 csvfile tablename user" && exit 1

FIELDS=$(head -1 "$CSV" | sed -e 's/'$DELIM'/` varchar(255),\n`/g' -e 's/\r//g')
FIELDS='`'"$FIELDS"'` varchar(255)'

$MYSQL -u "${USER}" -p"${PASS}" -h localhost -D ${DB} <<EOF
DROP TABLE IF EXISTS  ${TABLE};
CREATE TABLE ${TABLE} ($FIELDS);
 \q
EOF

$MYSQL -u "${USER}" -p"${PASS}" -h localhost -D ${DB} <<EOF
load data local infile '$(pwd)/$CSV'
 into table ${TABLE}
 fields terminated by '$DELIM'
 enclosed by '"'
 escaped by '\\\'
 lines terminated by '\n';
 \q
EOF

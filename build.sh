#!/bin/sh
# Script to build the Ready.gov site.


# Make sure the correct number of args was passed from the command line
if [ $# -eq 0 ]; then
  echo "Usage $0 [--prod] target_build_dir \n  Or: $0 [--rebuild] target_build_dir"
  exit 1
fi

# Initialize variables based on target environment
if [ "$1" = "--prod" ]; then
  DRUSH_OPTS=
  MAKEFILE='html.make'
  TARGET=$2
else
  DRUSH_OPTS='--working-copy'
  MAKEFILE='html.make'
  TARGET=$1
fi

# Make sure we have a target directory
if [ -z "$TARGET" ]; then
  echo "Usage $0 target_build_dir"
  exit 2
fi

# Do the build
CALLPATH=`dirname $0`
drush make $DRUSH_OPTS $CALLPATH/$MAKEFILE $TARGET
BASE=`pwd`
PROFILEPATH=`cd $CALLPATH; pwd`
echo $TARGET
DRUPAL=`cd $TARGET; pwd`
PROFILE_DIR="$DRUPAL/profiles/takepart"
rm -rf $DRUPAL/robots.txt
ln -s $DRUPAL/profiles/takepart/settings/robots.dev.txt robots.txt
ln -s $PROFILEPATH $DRUPAL/profiles/takepart

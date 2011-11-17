#!/bin/sh
# Script to build the Ready.gov site.

function usage()
{
  echo "Usage $0 [--prod] target_build_dir \n  Or: $0 [--rebuild] target_build_dir"
}

#echo "PRvidaded arguments \$1=$1 and \$2=$2"
# Make sure the correct number of args was passed from the command line
if [ $# -eq 0 ]; then
  echo "usage $0 [--prod] target_build_dir \n  Or: $0 [--rebuild] target_build_dir"
  exit 1
fi

echo "dollar1=$1"

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
#if [ -z "$TARGET" ]; then
#  echo "usage $0 target_build_dir"  
#  exit 2
#fi

# Work only with callback 
echo "Target $TARGET"
#CALLPATH should be the repo root
CALLPATH=`dirname $0`
echo "Callpath $CALLPATH"
#BASE should be the shiva container
BASE=`cd $CALLPATH; cd ../; pwd`
echo "BASE $BASE"
#DRupal is drupal inside of the repo container, update if the drupal folder name is updated
DRUPAL=`cd "$CALLPATH/drupal"; pwd` 
echo "Grupal $DRUPAL"
#exit 0

ln -s $DRUPAL html

cd $DRUPAL
if [ -e ./robots.txt ]; then
  rm robots.txt
  ln -s $CALLPATH/settings/robots.dev.txt $DRUPAL/robots.txt
fi
#ln -s /opt/development/files/www.takepart.com-extra/flash $DRUPAL/flash
#ln -s /opt/development/files/www.takepart.com-extra/help_app $DRUPAL/help_app
#ln -s /opt/development/files/www.takepart.com-extra/images $DRUPAL/images
#ln -s /opt/development/files/www.takepart.com-extra/js $DRUPAL/js
#ln -s /opt/development/files/www.takepart.com-extra/tsign_apps $DRUPAL/tsign_apps

echo "$0 successfully finished."

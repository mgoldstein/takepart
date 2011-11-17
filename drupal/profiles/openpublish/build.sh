#!/bin/bash
loc='openpublish'
output='test'
script=`readlink -f $0`;
ap=`dirname $script`;

sudo rm -rf $loc
#drush --debug make $ap/openpublish.make $loc
drush make $ap/openpublish.make $loc

#!/bin/sh


sudo rm html/sites/default/settings.php
sudo cp html/sites/default/default.settings.php html/sites/default/settings.php
sudo chown -R apache:staff html/sites/
sudo chmod -R 775 html/sites/

echo -n "Database password? "
stty -echo
read password
stty echo
echo ""

mysql -u root -p$password -e "DROP DATABASE IF EXISTS d7_openpublishapp_com"
mysql -u root -p$password -e "CREATE DATABASE IF NOT EXISTS d7_openpublishapp_com"


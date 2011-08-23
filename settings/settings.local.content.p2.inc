<?php
$databases = array (
  'default' =>
    array (
      'default' =>
        array (
          'database' => 'takepart_content',
          'username' => 'takepart_conten',
          'password' => '8dadb65a',
          'host' => 'localhost',
          'port' => '',
          'driver' => 'mysql',
          'prefix' => '',
        ),
    ),
  'migrate' =>
    array (
      'default' =>
        array (
          'database' => 'bblake_takepart2',
          'username' => 'root',
          'password' => 'papa16',
          'host' => 'localhost',
          'port' => '',
          'driver' => 'mysql',
          'prefix' => '',
        ),
    ),    
);

  $conf = array(
   'omniture_account_name' => 'takeparttakepartdev2',
);

ini_set('error_reporting', !E_NOTICE & !E_WARNING);
ini_set('memory_limit','512M');
// end of settings.php

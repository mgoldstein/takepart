<?php namespace Participant;

use Illuminate\Database\Capsule\Manager as Capsule;

use Doctrine\ORM\Tools\Setup;
use Doctrine\ORM\EntityManager;

class App {

  private static $_entityManager = NULL;

  public static function init($params) {

    $dbConnection = array(
      'driver'   => 'pdo_mysql',
      'user'     => $params['db_user'],
      'password' => $params['db_pass'],
      'dbname'   => $params['db_name'],
      'host'     => $params['db_host'],
      'charset'  => 'utf8',
    );

    $config = Setup::createAnnotationMetadataConfiguration(
      array($params['entity_path']), $params['development_mode']);

    self::$_entityManager = EntityManager::create($dbConnection, $config);
  }

  public static function db() {
    return self::$_entityManager;
  }

  public static function repo($entity_name) {
    return self::$_entityManager->getRepository($entity_name);
  }
}

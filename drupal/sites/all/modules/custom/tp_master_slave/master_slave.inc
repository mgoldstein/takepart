<?php

/**
 * Class tpSlave
 * Targets the slave database and adds a tag 'tpSlave' to the query
 */
class tpSlave extends SelectQueryExtender {
  public function __construct(SelectQueryInterface $query, DatabaseConnection $connection) {
    if ($connection->getTarget() != 'slave') {
      $connection = Database::getConnection('slave', $connection->getKey());
    }
    parent::__construct($query, $connection);
    $this->addTag('tpSlave');
  }
}
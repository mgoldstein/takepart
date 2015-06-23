<?php

/*
 * This script changes the storage engine of the semaphore table in the takepart
 * database to MEMORY. It sets a multiple column primary key based on the name
 * and value columns using the btree index. It sets the unique constraint on the 
 * name column using btree. Lastly, it creates indexes for the value and expire 
 * columns using btree.
 * 
 * This script can be called using drush:
 * drush scr semaphore_memory_engine
 */

// define static var
define('DRUPAL_ROOT', getcwd());
// include bootstrap
include_once('./includes/bootstrap.inc');
// initialize stuff
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

function _set_semaphore_engine() {
  // Check current engine of semaphore table
  $checkEngine = db_query("SELECT TABLE_NAME, ENGINE FROM information_schema.TABLES where TABLE_SCHEMA = 'takepart' AND TABLE_NAME = 'semaphore'");
  $record = $checkEngine->fetchObject();

  if ($record->ENGINE === 'MEMORY') {
    return print('Semaphore table already set to Memory engine!' . " \r\n");
  } else {
    echo "Set semaphore table engine to memory" . " \r\n";
    $sql = "ALTER TABLE semaphore ENGINE = MEMORY";
    db_query($sql);

    // Check table engine after alter table run
    $sql = "SELECT TABLE_NAME, ENGINE FROM information_schema.TABLES where TABLE_SCHEMA = 'takepart' AND TABLE_NAME = 'semaphore'";
    $results = db_query($sql);
    foreach ($results as $value) {
	 print_r($value);
    }

    sleep(1);
    echo "Drop primary key from semaphore" . " \r\n";
    $sql = "ALTER TABLE semaphore DROP PRIMARY KEY";
    db_query($sql);

    sleep(1);
    echo "Add primary keys name and value (using BTree) to semaphore" . " \r\n";
    $sql = "ALTER TABLE semaphore ADD PRIMARY KEY (name, value) USING BTREE";
    db_query($sql);

    sleep(1);
    echo "Add unique name using BTree" . " \r\n";
    $sql = "ALTER TABLE semaphore ADD UNIQUE name (name) USING BTREE";
    db_query($sql);

    sleep(1);
    echo "Drop index value";
    $sql = "ALTER TABLE semaphore DROP INDEX value" . " \r\n";
    db_query($sql);

    sleep(1);
    echo "Add index value using BTree" . " \r\n";
    $sql = "ALTER TABLE semaphore ADD INDEX value (value) USING BTREE";
    db_query($sql);

    sleep(1);
    echo "Drop index expire" . " \r\n";
    $sql = "ALTER TABLE semaphore DROP INDEX expire";
    db_query($sql);

    sleep(1);
    echo "Add index expire using BTree" . " \r\n";
    $sql = "ALTER TABLE semaphore ADD INDEX expire (expire) USING BTREE";
    db_query($sql);

    sleep(1);
    $sql = "DESCRIBE semaphore";
    $result = db_query($sql);
    foreach ($result as $row) {
	 print_r($row);
    }
  }
}

_set_semaphore_engine();

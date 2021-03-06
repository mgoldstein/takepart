<?php
// Register our shutdown function so that no other shutdown functions run before this one.
// This shutdown function calls exit(), immediately short-circuiting any other shutdown functions,
// such as those registered by the devel.module for statistics.
register_shutdown_function('status_shutdown');
function status_shutdown() {
  exit();
}

// Drupal bootstrap.
define('DRUPAL_ROOT', getcwd());

require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_DATABASE);

// Build up our list of errors.
$errors = array();

// Try reading from the database
$result = db_query('SELECT * FROM {users} WHERE uid = 1 LIMIT 1')->fetch();
if (!$result->uid == 1) {
  $errors[] = 'Database read not responding.';
}

// Check memcache
if ($conf['cache_default_class'] === 'MemCacheDrupal') {
  foreach ($conf['memcache_servers'] as $address => $bin) {
    list($ip, $port) = explode(':', $address);
    if (!memcache_connect($ip, $port)) {
      $errors[] = 'Memcache bin <em>' . $bin . '</em> at address ' . $address . ' is not available.';
    }
  }
}

// Check the files directory
if ($test = tempnam(variable_get('file_directory_path', conf_path() .'/files'), 'status_check_')) {
  if (!strpos($test, '/data/takepart/files') === 0) {
    $errors[] = 'Files are not being saved in the NFS mount under /data/takepart/files';
  }
  if (!unlink($test)) {
    $errors[] = 'Could not delete newly create files in the files directory.';
  }
}
else {
  $errors[] = 'Could not create temporary file in the files directory.';
}

// Print all errors.
if ($errors) {
  $errors[] = 'Errors on this server will cause it to be removed from the load balancer.';
  header('HTTP/1.1 503 Service Unavailable');
  print implode("<br />\n", $errors);
}
else {
  // Split up this message, to prevent the remote chance of monitoring software
  // reading the source code if mod_php fails and then matching the string.
  print 'CONGRATULATIONS' . ' 200' . "\n";
}
// Exit immediately, note the shutdown function registered at the top of the file.
exit();
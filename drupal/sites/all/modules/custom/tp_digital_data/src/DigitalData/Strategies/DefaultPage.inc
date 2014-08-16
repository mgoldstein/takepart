<?php

class ddDefaultPage implements ddBuildStrategy {

  public static function claim($path, $page) {
    // Claim all pages.
    return TRUE;
  }

  public function build($page) {

    // Every page needs at least the event array.
    return array(
      'version' => '1.0',
      'page' => array(
        'pageInfo' => array(
          'destinationURL' => '%document.location.href',
          'referringURL' => '%document.referrer',
        ),
      ),
      'event' => array(),
    );
  }
}

<?php

class TakePart_VideoImportController {

  public static function importers() {
    return array(
      'TakePart_JWPlatformImporter',
      'TakePart_YoutubeImporter',
      'TakePart_VimeoImporter',
    );
  }

  public function createImporter($url) {
    foreach (self::importers() as $klass) {
      $importer = new $klass;
      if ($importer->claim($url)) {
        return $importer;
      }
    }
    return NULL;
  }
}

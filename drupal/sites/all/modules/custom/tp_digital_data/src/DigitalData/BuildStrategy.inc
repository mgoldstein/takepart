<?php

interface ddBuildStrategy {

  public static function claim($path, $page);

  public function build($page);
}

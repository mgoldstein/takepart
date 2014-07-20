<?php
namespace TakePart\DigitalData;

interface BuildStrategy {

  public static function claim($path, $page);

  public function build($page);
}

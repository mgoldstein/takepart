<?php


class ddStrategyFactory {

  protected static $strategies = array();

  public function __construct($strategies) {
    $this->strategies = $strategies;
  }

  protected function determineStrategy($path, $page) {
    foreach ($this->strategies as $class) {
      if (call_user_func(array($class, 'claim'), $path, $page)) {
        return $class;
      }
    }
    return NULL;
  }

  public function createForPage($path, $page) {
    $strategy_class = $this->determineStrategy($path, $page);
    if (!is_null($strategy_class)) {
      return new $strategy_class;
    }
    return new ddDefaultPage($page);
  }
}

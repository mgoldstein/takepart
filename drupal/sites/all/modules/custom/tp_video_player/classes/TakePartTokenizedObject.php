<?php

class TakePartTokenizedObject {

  private $object;
  private $data;
  private $options;

  private $values;

  public function __construct($object, $data, $options) {
    $this->object = $object;
    $this->data = $data;
    $this->options = $options;
    $this->values = array();
  }

  public function __get($name) {
    if (!isset($this->values[$name])) {
      $this->values[$name] = token_replace($this->object->{$name},
        $this->data, $this->options);
    }
    return $this->values[$name];
  }

  public function __set($name, $value) {
    $this->object->{$name} = $value;
    unset($this->values[$name]);
  }

  public function __isset($name) {
    return isset($this->object->{$name});
  }

  public function __unset($name) {
    unset($this->object->{$name});
  }
}

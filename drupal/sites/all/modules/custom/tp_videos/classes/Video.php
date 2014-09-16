<?php

class TakePart_Video {

  public $id = NULL;

  public $type = NULL;

  public $external_key = NULL;
  public $external_type = NULL;

  public $title = NULL;
  public $width = NULL;
  public $height = NULL;
  public $length = NULL;
  public $thumbnail_image = NULL;
  public $allowed_regions = NULL;

  public $embed_code = NULL;

  public $created_at = NULL;
  public $updated_at = NULL;

  public function __construct($values) {
    $this->type = get_class($this);
    foreach ($values as $name => $value) {
      $this->{$name} = $value;
    }
  }

  public function providerLabel() {
    return get_class($this);
  }

  public function refreshPattern() {
    $klass = get_class($this);
    return "{$klass}:{$this->external_key}";
  }

  public function values() {
    // Convert the object to an array.
    $values = (array) $this;
    // Remove the id element if it does not have a real value.
    if (is_null($this->id)) { unset($values['id']); }
    return $values;
  }

  public function update($values) {
    foreach ($values as $name => $value) {
      $this->{$name} = $value;
    }
  }
}

<?php

class WordletItem {

  private $id;
  private $editable;
  private $configurable;

  public $page;
  public $name;
  public $type;
  public $format;

  public function __construct($args = array()) {
    $args += array(
      'id' => '',
      'page' => '',
      'name' => '',
      'type' => '',
      'format' => 0,
      'editable' => FALSE,
      'configurable' => FALSE,
    );
    foreach ($args as $attribute => $value) {
      $this->{$attribute} = $value;
    }
  }

  protected function is_empty() {
    return TRUE;
  }

  protected function inline() {
    return TRUE;
  }

  protected function markup() {
    return '';
  }

  public function __toString() {

    if (!$this->editable) {
      return $this->markup();
    }
    else {

      if (!empty($this->type)) {
        $href = "/admin/wordlet/page/{$this->page}/manage/{$this->id}/edit";
        $edit_link = implode('', array(
          '<span class="wordlet_edit" data-href="' . $href . '">',
          t('Edit @name', array('@name' => $this->name)),
          '</span>'
        ));
      }
      else {
        $edit_link = '';
      }

      if ($this->configurable && empty($this->type) ) {
        $href = "/admin/wordlet/page/{$this->page}/manage/{$this->id}/configure";
        $configure_link = implode('', array(
          '<span class="wordlet_configure" data-href="' . $href . '">',
          t('Configure @name', array('@name' => $this->name)),
          '</span>'
        ));
      }
      else {
        $configure_link = '';
      }

      $classes = $this->is_empty() ? "empty wordlet" : "wordlet";

      if ($this->inline()) {
        return implode('', array(
          '<span class="' . $classes . '">',
          $this->markup(),
          $edit_link,
          $configure_link,
          '</span>'
        ));
      }
      else {
        return implode('', array(
          '<div class="' . $classes . '">',
          $this->markup(),
          $edit_link,
          $configure_link,
          '</div>',
        ));
      }
    }
  }
}

class SingleLineWordlet extends WordletItem {

  public $text;

  public function __construct($values = array()) {
    $values += array(
      'text' => '',
    );
    parent::__construct($values);
  }

  protected function is_empty() {
    return trim($this->text) == FALSE;
  }

  protected function inline() {
    return ($this->format == 0);
  }

  protected function markup() {
    switch ($this->format) {
    case 2: // Full HTML
      return $this->text;
    case 1: // Simple HTML
      return strip_tags($this->text, '<b><i><strong><em><br><br/><img>');
    default: // Plain Text
      return check_plain($this->text);
    }
  }
}

class MultipleLineWordlet extends WordletItem {

  public $text;

  public function __construct($values = array()) {
    $values += array(
      'text' => '',
    );
    parent::__construct($values);
  }

  protected function is_empty() {
    return trim($this->text) == FALSE;
  }

  protected function inline() {
    return FALSE;
  }

  protected function markup() {
    switch ($this->format) {
    case 2: // Full HTML
      return $this->text;
    case 1: // Simple HTML
      $value = strip_tags($this->text, '<b><i><strong><em><br><br/><img>');
      break;
    default: // Plain Text
      $value = check_plain($this->text);
      break;
    }
    $value = str_replace(array("\r\n", "\r"), "\n", $value);
    $value = str_replace("\n\n\n", '</p><p>', $value);
    $value = str_replace("\n\n", '<br/>', $value);
    return '<p>' . $value . '</p>';
  }
}

class NodeReferenceWordlet extends WordletItem {

  public $nid;
  public $view_mode;

  public function __construct($values = array()) {
    $values += array(
      'nid' => 0,
      'view_mode' => '',
    );
    parent::__construct($values);
  }

  protected function is_empty() {
    return empty($this->nid) || empty($this->view_mode);
  }

  protected function inline() {
    return FALSE;
  }

  protected function markup() {
    if (!$this->is_empty()) {
      $node = node_load($this->nid);
      if ($node !== FALSE) {
        return drupal_render(node_view($node, $this->view_mode));
      }
    }
    return '';
  }
}

class SimpleLinkWordlet extends SingleLineWordlet {

  public $href;

  public function __construct($values = array()) {
    $values += array(
      'href' => '',
    );
    parent::__construct($values);
  }

  public function markup() {
    if (empty($this->href)) {
      return parent::markup();
    }
    return '<a href="' . $this->href . '">' . parent::markup() . '</a>';
  }
}

class WordletList implements Iterator {

  private $position;
  private $data;

  public $ordered;

  public function __construct($wordlets, $ordered = FALSE) {
    $this->position = 0;
    $this->data = $wordlets;
    $this->ordered = $ordered;
  }

  public function rewind() {
    $this->position = 0;
  }

  public function current() {
    return $this->data[$this->position];
  }

  public function key() {
    return $this->position;
  }

  public function next() {
    $this->position += 1;
  }

  public function valid() {
    return isset($this->data[$this->position]);
  }

  public function count() {
    return count($this->data);
  }

  public function __toString() {
    $markup = $this->ordered ? '<ol>' : '<ul>';
    foreach ($this->data as $wordlet) {
      $markup .= '<li>' . $wordlet . '</li>';
    }
    $markup .= $this->ordered ? '</ol>' : '</ul>';
    return $markup;
  }
}

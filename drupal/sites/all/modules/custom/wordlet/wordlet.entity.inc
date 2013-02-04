<?php

class WordletItem {

  public $page;
  public $name;
  public $format;

  public $single;
  public $multi;
  public $href;
  public $node;

  public $empty;

  public function __construct($args = array()) {
    $args += array(
      'page' => '',
      'name' => '',
      'format' => 0,
      'single' => '',
      'multi' => '',
      'href' => '',
      'node' => '',
      'empty' => array(
        'single' => TRUE,
        'multi' => TRUE,
        'href' => TRUE,
        'node' => TRUE,
      ),
    );
    foreach ($args as $attribute => $value) {
      $this->{$attribute} = $value;
    }
  }

  public function __toString() {
    $priority = array('multi', 'single', 'href', 'node');
    foreach ($priority as $attribute) {
      if (!$this->empty[$attribute]) {
        return $this->{$attribute};
      }
    }
    foreach ($priority as $attribute) {
      if (!empty($this->{$attribute})) {
        return $this->{$attribute};
      }
    }
    return '';
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


class Wordlet extends Entity {

  public $items;
  public $item_keys;

  public function __construct($values = array(), $entity_type = 'wordlet') {
    $this->items = array();
    parent::__construct($values, $entity_type);
  }

  protected function defaultUri() {
    $path = implode('/', array(
      'admin',
      'wordlet',
      'page',
      $this->page,
      'manage',
      $this->id,
    ));
    return array('path' => $path);
  }

  protected function defaultLabel() {
    return empty($this->title) ? $this->name : $this->title;
  }
}

class WordletController extends EntityAPIControllerExportable {

  public function create(array $values = array()) {
    $values += array(
      'id' => '',
      'page' => '',
      'name' => '',
      'title' => '',
      'description' => '',
      'format' => 0,
      'enabled' => 1,
      'cardinality' => 1,
      'weight' => 0,
      'items_data' => '',
      'keys_data' => '',
      'created' => 0,
      'changed' => 0,
      'status' => ENTITY_CUSTOM,
      'module' => 'wordlet',
    );
    return parent::create($values);
  }

  public function save($entity, DatabaseTransaction $transaction = NULL) {

    // set/update the created and changed timestamps
    $entity->is_new = isset($entity->is_new) ? $entity->is_new : 0;
    if ($entity->is_new) {
      $entity->created = time();
    }
    $entity->changed = time();

    // serialize the field item values
    $entity->items_data = serialize($entity->items);
    $entity->keys_data = implode(',', $entity->item_keys);

    return parent::save($entity, $transaction);
  }

  protected function attachLoad(&$queried_entities, $revision_id = FALSE) {

    // Unserialize the field item values
    foreach ($queried_entities as $key => $entity) {
      $items = unserialize($entity->items_data);
      if (!empty($items) && is_array($items)) {
        $entity->items = $items;
      }
      $entity->item_keys = explode(',', $entity->keys_data);
      $queried_entities[$key] = $entity;
    }

    parent::attachLoad($queried_entities, $revision_id);
  }

  protected function createViewItem($entity, $item) {

    // Default attributes
    $args = array(
      'page' => $entity->page,
      'name' => $entity->name,
      'format' => $entity->format,
      'single' => '',
      'multi' => '',
      'href' => '',
      'node' => '',
      'empty' => array(
        'single' => TRUE,
        'multi' => TRUE,
        'href' => TRUE,
        'node' => TRUE,
      ),
    );

    // Single line text
    if (in_array('single', $entity->item_keys)) {

      // Preprocess the value
      switch ($entity->format) {
      case 2: // Full HTML
        $value = $item['single'];
        break;
      case 1: // Simple HTML
        $value = strip_tags($item['single'],
          '<b><i><strong><em><br><br/><img>');
        break;
      default: // Plain Text
        $value = check_plain($item['single']);
        break;
      }

      $args['single'] = $value;

      $stripped = strip_tags($value);
      $args['empty']['single'] = empty($stripped);
    }

    // Multi line text
    if (in_array('multi', $entity->item_keys)) {

      // Preprocess the value
      switch ($this->format) {
      case 2: // Full HTML
        $value = $item['multi'];
        break;
      case 1: // Simple HTML
        $value = strip_tags($item['multi'], '<b><i><strong><em><br><br/><img>');
        break;
      default: // Plain Text
        $value = check_plain($item['multi']);
        break;
      }
      // Plain text and simple HTML fields need to be converted to paragraphs
      if ($this->format != 2) {
        $value = str_replace(array("\r\n", "\r"), "\n", $value);
        $value = str_replace("\n\n\n", '</p><p>', $value);
        $value = str_replace("\n\n", '<br/>', $value);
        $value = '<p>' . $value . '</p>';
      }

      $args['multi'] = $value;

      $stripped = strip_tags($value);
      $args['empty']['multi'] = empty($stripped);
    }

    // Link href
    if (in_array('href', $entity->item_keys)) {
      $args['href'] = $item['href'];
      $stripped = strip_tags($item['href']);
      $args['empty']['href'] = empty($stripped);
    }

    // Node requires a nid and a view mode
    if (in_array('nid', $entity->item_keys)
      && in_array('view_mode', $entity->item_keys)) {
      $value = '';
      if (!empty($item['nid']) && !empty($item['view_mode'])) {
        $node = node_load($item['nid']);
        if ($node !== FALSE) {
          $value = drupal_render(node_view($node, $item['view_mode']));
          $have_value = TRUE;
        }
      }

      $args['node'] = $value;

      $stripped = strip_tags($value);
      $args['empty']['node'] = empty($stripped);
    }

    // Determine the access level for the wordlet.
    $editable = FALSE;
    $configurable = FALSE;
    if (!empty($_COOKIE['show_wordlets'])) {
      if (wordlet_access('administer', $entity)) {
        $editable = TRUE;
        $configurable = TRUE;
      }
      elseif (wordlet_access('administer', $entity)) {
        $editable = TRUE;
        $configurable = FALSE;
      }
    }

    if ($editable) {

      $displayed_attributes = array('single', 'multi', 'node');

      foreach ($displayed_attributes as $attribute) {

        $classes = $args['empty'][$attribute] ? "empty wordlet" : "wordlet";
        $tag = ($entity->format == 0 && $attribute == 'single') ? 'span' : 'div';

        $edit_link = '';
        if (!$is_empty) {
          $href = "/admin/wordlet/page/{$entity->page}/manage/{$entity->id}/edit";
          $edit_link = implode('', array(
            '<span class="wordlet_edit" data-href="' . $href . '">',
            t('Edit @name', array('@name' => $entity->name)),
            '</span>'
          ));
        }

        $configure_link = '';
        if ($configurable && $is_empty) {
          $href = "/admin/wordlet/page/{$entity->page}/manage/{$entity->id}/configure";
          $configure_link = implode('', array(
            '<span class="wordlet_configure" data-href="' . $href . '">',
            t('Configure @name', array('@name' => $entity->name)),
            '</span>'
          ));
        }

        $args[$attribute] = implode('', array(
          "<{$tag} class=\"{$classes}\">",
          $args[$attribute],
          $edit_link,
          $configure_link,
          "</{$tag}>",
        ));

      }
    }

    return new WordletItem($args);
  }

  public function viewOne($entity) {
    $first = reset($entity->items);
    $item = $first !== FALSE ? $first : array();
    return $this->createViewItem($entity, $item);
  }

  public function viewList($entity) {
    $wordlets = array();
    foreach ($entity->items as $item) {
      $wordlets[] = $this->createViewItem($entity, $item);
    }
    return new WordletList($wordlets);
  }
}

<?php

class Wordlet extends Entity {

  public function __construct($values = array(),
    $entity_type = 'wordlet') {
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
}

class WordletController extends EntityAPIControllerExportable {

  public function create(array $values = array()) {
    $values += array(
      'id' => '',
      'page' => '',
      'title' => '',
      'name' => '',
      'description' => '',
      'type' => '',
      'allow_markup' => 0,
      'enabled' => 1,
      'integer_value' => 0,
      'string_value' => '',
      'text_value' => '',
      'markup' => 0,
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
    return parent::save($entity, $transaction);
  }

  public function viewMarkup($entity) {
    if ($entity->type == 'single-line') {
      switch ($entity->markup) {
      case 2: // Full HTML
        return $entity->string_value;
      case 1: // Simple HTML
        return strip_tags($entity->string_value,
          '<b><i><strong><em><br><br/><img>');
      default: // Plain Text
        return check_plain($entity->string_value);
      }
    }
    elseif ($entity->type == 'multiple-lines') {
      switch ($entity->markup) {
      case 2: // Full HTML
        return $entity->text_value;
      case 1: // Simple HTML
        $value = strip_tags($entity->text_value,
          '<b><i><strong><em><br><br/><img>');
        break;
      default: // Plain Text
        $value = check_plain($entity->text_value);
        break;
      }
      $value = str_replace(array("\r\n", "\r"), "\n", $value);
      $value = str_replace("\n\n\n", '</p><p>', $value);
      $value = str_replace("\n\n", '<br/>', $value);
      return '<p>' . $value . '</p>';
    }
    elseif ($entity->type == 'node-reference') {
      if (!empty($entity->integer_value) && !empty($entity->string_value)) {
        $node = node_load($entity->integer_value);
        if ($node !== FALSE) {
          return drupal_render(node_view($node, $entity->string_value));
        }
      }
    }
    return '';
  }

  public function editMarkup($entity, $configure = FALSE) {

    if (!empty($entity->type)) {
      $edit_link = l(t('Edit @name', array('@name' => $entity->name)),
        "admin/wordlet/page/{$entity->page}/manage/{$entity->id}/edit",
        array('attributes' => array( 'class' => array('wordlet_edit'))));
    }
    else {
      $edit_link = '';
    }

    if ($configure && empty($entity->type) ) {
      $configure_link = l(t('Configure @name', array('@name' => $entity->name)),
      "admin/wordlet/page/{$entity->page}/manage/{$entity->id}/configure",
        array('attributes' => array( 'class' => array('wordlet_configure'))));
    }
    else {
      $configure_link = '';
    }

    $value = $this->viewMarkup($entity);

    if (trim($value) == false) {
      $classes = 'empty wordlet';
    }
    else {
      $classes = 'wordlet';
    }

    if ($entity->type == 'multiple-lines' || $entity->markup) {
      return implode('', array(
        '<div class="' . $classes . '">',
        $value,
        $edit_link,
        $configure_link,
        '</div>',
      ));
    }
    else {
      return implode('', array(
        '<span class="' . $classes . '">',
        $value,
        $edit_link,
        $configure_link,
        '</span>'
      ));
    }
  }
}
